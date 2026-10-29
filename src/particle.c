#include "particle.h"

#include "camera_inline.h"
#include "global.h"
#include "sprite.h"
#include "video.h"

extern OamData gOAMBuffer[128];
extern OamData gStagedOAMBuffer[128];
extern u16 gOAMPrioCounts[4];
extern s32 gOAMCount;
extern s32 gStagedOAMCount;
extern u32 gOamDirty;
extern u8 gObjMosaicEnabled;

s32 Video_AddParticleIntoDrawList(Particle* p, s32 idx);
void Video_RemoveParticleFromDrawList(Particle* p, s32 idx);

// Particle を ParticleGroup の先頭フレームで初期化し、描画リストに繋ぐ
void Particle_Add(Particle* p, ParticleGroup* g, SpriteFlags flags) {
  u32 mask;
  s32 idx;

  if (!p->active) {
    p->flags = flags;
    p->oamAttr01 = 0;
    p->priority = 2;
    p->offsetZ = 0;
    p->rotation = 0;
    p->scaleX = Q6(1), p->scaleY = Q6(1);
    Particle_SetOffset(p, 0, 0);
    Particle_SetPose(p, g, 0);
    p->plttSlot = AllocParticlePlttSlot(g->plttID, &gObjPlttData[g->plttID * 16]);
    mask = SPRFLAG_DRAWLIST;
    idx = (u32)(0 - (flags & mask)) >> 31;
    p->prev = NULL, p->next = NULL;
    Video_AddParticleIntoDrawList(p, idx);
  }
}

// 描画リストに繋がれていなければ、flags の bit7 で選んだリストに Particle を繋ぐ
void Particle_AddToDrawList(Particle* p, SpriteFlags flags) {
  if (!p->active) {
    Video_AddParticleIntoDrawList(p, TEST_FLAGS(flags, SPRFLAG_DRAWLIST) ? 1 : 0);
  }
}

// Particle を ParticleGroup の先頭フレームで初期化する (描画リストには繋がない)
void Particle_Setup(Particle* p, ParticleGroup* g, SpriteFlags flags) {
  if (!p->active) {
    p->flags = flags;
    p->oamAttr01 = 0;
    p->priority = 1;
    p->offsetZ = 0;
    Particle_SetOffset(p, -8, -8);
    Particle_SetPose(p, g, 0);
    p->plttSlot = AllocParticlePlttSlot(g->plttID, &gObjPlttData[g->plttID * 16]);
    p->prev = NULL, p->next = NULL;
  }
}

// 描画リストに繋がれていれば Particle を外す
void Particle_Remove(Particle* p) {
  if (p->active) {
    Video_RemoveParticleFromDrawList(p, p->listIdx);
  }
}

void Particle_SetOffset(Particle* p, s32 offsetX, s32 offsetY) {
  p->offsetX = offsetX;
  p->offsetY = offsetY;
}

// パーティクルに OBJ パレット plttID を割り当て、確保されたパレットスロット番号を記録する
void Particle_SetPltt(Particle* p, s32 plttID) { p->plttSlot = AllocParticlePlttSlot(plttID, &gObjPlttData[plttID * 16]); }

// ParticleGroup の形状からパーティクルのサイズと OAM 属性を作り、 idx 枚目のタイル番号を入れる
// poseIdx は "include/constants/particle.h" の定数
void Particle_SetPose(Particle* p, ParticleGroup* g, u32 poseIdx) {
  p->spriteWidth = gSpriteSizeTable[g->shape];
  p->spriteHeight = gSpriteSizeTable[g->shape] >> 8;
  p->oamAttr01 = ((g->shape & 3) << 14) | ((g->shape & 0xC) << 28);
  if (g->flags & PGFLAG_BPP8) p->oamAttr01 |= OAM0_8BPP;
  p->tileNum = poseIdx * ((p->spriteWidth >> 3) * (p->spriteHeight >> 3)) + g->tile;
}

// 汎用の Particle 描画パス (ほとんどの場面で使われる)
// 残差は p と attr01 のレジスタ (r4/r5) の入れ替わり, スケール比較の bgt が bhi になる点, 原典は u8 の scaleX を ldrb で読んで符号付き比較している
// flags を毎回 p->flags で読む形と offsetX/Y を直接書いて gcse に持ち上げさせる形で命令列はほぼ揃う, 本体を static inline に括ると z の複写まで一致するが一致に至らないので展開してある
NON_MATCH void Particle_DrawList(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  Particle* p;
  Vec3 screen;

  for (p = gParticleLists[gSpriteListIdx]; p != NULL; p = p->next) {
    s32 x, y, z;
    u32 attr01;

    if (p->flags & skipMask) {
      continue;
    }

    if (!(p->flags & SPRFLAG_SCREEN_COORD)) {
      WorldToScreen(&screen, &p->pos);
      x = screen.x;
      y = screen.y;
      z = screen.z;
    } else {
      x = p->pos.x;
      y = p->pos.y;
      z = p->pos.z;
    }

    if (!(p->flags & SPRFLAG_NO_CLIP)) {
      s32 w = p->spriteWidth;
      s32 h = p->spriteHeight;
      s32 left = x + p->offsetX;
      s32 top = y + p->offsetY;

      if (left > 240 || top > 180 || left + w < 0 || top + h < 0) {
        continue;
      }
    }

    x += p->offsetX;
    y += p->offsetY;
    attr01 = p->oamAttr01 | ((x & 0x1FF) << 16) | (y & 0xFF);

    if (p->flags & SPRFLAG_AFFINE) {
      s32 idx;

      if (p->scaleX > 60 || p->scaleY > 60 || p->rotation != 0) {
        attr01 |= 0x300;
      } else {
        attr01 |= 0x100;
      }
      if (gObjAffineCount > 31) {
        idx = 0;
      } else {
        gObjAffineParams[gObjAffineCount].angle = p->rotation;
        gObjAffineParams[gObjAffineCount].scaleX = p->scaleX;
        gObjAffineParams[gObjAffineCount].scaleY = p->scaleY;
        idx = gObjAffineCount++;
      }
      attr01 |= idx << 25;
    }
    if (p->flags & SPRFLAG_XFLIP) {
      attr01 |= 0x10000000;
    }
    if (p->flags & SPRFLAG_YFLIP) {
      attr01 |= 0x20000000;
    }
    if (gObjBlendEnabled && (p->flags & SPRFLAG_UNK_14)) {
      attr01 |= 0x400;
    }
    if (((gObjMosaicEnabled & 1) && p->priority && !(p->flags & SPRFLAG_UNK_16)) || (p->flags & SPRFLAG_UNK_11)) {
      attr01 |= 0x1000;
    }
    z += p->offsetZ;

    if (p->flags & SPRFLAG_OAM_DIRECT) {
      s32 n;
      s32 attr2;

      attr2 = (s16)p->tileNum | (p->priority << 10) | (p->plttSlot << 12);
      n = gOAMCount;
      if (n < 128) {
        OamData* oam = &gOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        gOAMCount = n + 1;
        gOamDirty |= 1;
      }
    } else {
      s32 n;
      s32 attr2;
      u8 priority;

      z = FixToInt(1, z);
      if (z < -128) {
        z = -128;
      } else if (z > 127) {
        z = 127;
      }
      priority = p->priority;
      attr2 = (s16)p->tileNum | (priority << 10) | (p->plttSlot << 12);
      n = gStagedOAMCount;
      if (n < 128) {
        OamData* oam = &gStagedOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        oam->affineParam = ((z + 0x80) & 0xFF) << 8;
        gStagedOAMCount = n + 1;
        gOAMPrioCounts[priority]++;
      }
    }
  }
#else
  INCFUNC("asm/func/Particle_DrawList.inc");
#endif
}

// Video_SetDrawPasses が AuxSprite_DrawListScreen / MainSprite_DrawListScreen と組で差し替える側
// 残差は p と attr01 のレジスタ (r4/r5) の入れ替わり, スケール比較の bgt が bhi になる点, 原典は u8 の scaleX を ldrb で読んで符号付き比較している
// flags を毎回 p->flags で読む形と offsetX/Y を直接書いて gcse に持ち上げさせる形で命令列はほぼ揃う, 本体を static inline に括ると z の複写まで一致するが一致に至らないので展開してある
NON_MATCH void Particle_DrawListScreen(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  Particle* p;

  for (p = gParticleLists[gSpriteListIdx]; p != NULL; p = p->next) {
    s32 x, y, z;
    u32 attr01;

    if (p->flags & skipMask) {
      continue;
    }

    x = FixToInt(3, p->pos.x - gCameraCoords.worldPos.x) + 120;
    y = FixToInt(3, p->pos.y - gCameraCoords.worldPos.y) + 90;
    z = p->pos.z - gCameraCoords.worldPos.z;

    if (!(p->flags & SPRFLAG_NO_CLIP)) {
      s32 w = p->spriteWidth;
      s32 h = p->spriteHeight;
      s32 left = x + p->offsetX;
      s32 top = y + p->offsetY;

      if (left > 240 || top > 180 || left + w < 0 || top + h < 0) {
        continue;
      }
    }

    x += p->offsetX;
    y += p->offsetY;
    attr01 = p->oamAttr01 | ((x & 0x1FF) << 16) | (y & 0xFF);

    if (p->flags & SPRFLAG_AFFINE) {
      s32 idx;

      if (p->scaleX > 60 || p->scaleY > 60 || p->rotation != 0) {
        attr01 |= 0x300;
      } else {
        attr01 |= 0x100;
      }
      if (gObjAffineCount > 31) {
        idx = 0;
      } else {
        gObjAffineParams[gObjAffineCount].angle = p->rotation;
        gObjAffineParams[gObjAffineCount].scaleX = p->scaleX;
        gObjAffineParams[gObjAffineCount].scaleY = p->scaleY;
        idx = gObjAffineCount++;
      }
      attr01 |= idx << 25;
    }
    if (p->flags & SPRFLAG_XFLIP) {
      attr01 |= 0x10000000;
    }
    if (p->flags & SPRFLAG_YFLIP) {
      attr01 |= 0x20000000;
    }
    if (gObjBlendEnabled && (p->flags & SPRFLAG_UNK_14)) {
      attr01 |= 0x400;
    }
    if (((gObjMosaicEnabled & 1) && p->priority && !(p->flags & SPRFLAG_UNK_16)) || (p->flags & SPRFLAG_UNK_11)) {
      attr01 |= 0x1000;
    }
    z += p->offsetZ;

    if (p->flags & SPRFLAG_OAM_DIRECT) {
      s32 n;
      s32 attr2;

      attr2 = (s16)p->tileNum | (p->priority << 10) | (p->plttSlot << 12);
      n = gOAMCount;
      if (n < 128) {
        OamData* oam = &gOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        gOAMCount = n + 1;
        gOamDirty |= 1;
      }
    } else {
      s32 n;
      s32 attr2;
      u8 priority;

      z = FixToInt(1, z);
      if (z < -128) {
        z = -128;
      } else if (z > 127) {
        z = 127;
      }
      priority = p->priority;
      attr2 = (s16)p->tileNum | (priority << 10) | (p->plttSlot << 12);
      n = gStagedOAMCount;
      if (n < 128) {
        OamData* oam = &gStagedOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        oam->affineParam = ((z + 0x80) & 0xFF) << 8;
        gStagedOAMCount = n + 1;
        gOAMPrioCounts[priority]++;
      }
    }
  }
#else
  INCFUNC("asm/func/Particle_DrawListScreen.inc");
#endif
}

// ゲームオーバー時の Particle 描画パス
// 残差は p と attr01 のレジスタ (r4/r5) の入れ替わり, スケール比較の bgt が bhi になる点, 原典は u8 の scaleX を ldrb で読んで符号付き比較している
// flags を毎回 p->flags で読む形と offsetX/Y を直接書いて gcse に持ち上げさせる形で命令列はほぼ揃う, 本体を static inline に括ると z の複写まで一致するが一致に至らないので展開してある
NON_MATCH void Particle_DrawListGameover(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  Particle* p;
  Vec3 screen;

  for (p = gParticleLists[gSpriteListIdx]; p != NULL; p = p->next) {
    s32 x, y, z;
    u32 attr01;

    if (p->flags & skipMask) {
      continue;
    }
    if (!(p->flags & SPRFLAG_GAMEOVER)) {
      continue;
    }

    if (!(p->flags & SPRFLAG_SCREEN_COORD)) {
      WorldToScreen(&screen, &p->pos);
      x = screen.x;
      y = screen.y;
      z = screen.z;
    } else {
      x = p->pos.x;
      y = p->pos.y;
      z = p->pos.z;
    }

    if (!(p->flags & SPRFLAG_NO_CLIP)) {
      s32 w = p->spriteWidth;
      s32 h = p->spriteHeight;
      s32 left = x + p->offsetX;
      s32 top = y + p->offsetY;

      if (left > 240 || top > 180 || left + w < 0 || top + h < 0) {
        continue;
      }
    }

    x += p->offsetX;
    y += p->offsetY;
    attr01 = p->oamAttr01 | ((x & 0x1FF) << 16) | (y & 0xFF);

    if (p->flags & SPRFLAG_AFFINE) {
      s32 idx;

      if (p->scaleX > 60 || p->scaleY > 60 || p->rotation != 0) {
        attr01 |= 0x300;
      } else {
        attr01 |= 0x100;
      }
      if (gObjAffineCount > 31) {
        idx = 0;
      } else {
        gObjAffineParams[gObjAffineCount].angle = p->rotation;
        gObjAffineParams[gObjAffineCount].scaleX = p->scaleX;
        gObjAffineParams[gObjAffineCount].scaleY = p->scaleY;
        idx = gObjAffineCount++;
      }
      attr01 |= idx << 25;
    }
    if (p->flags & SPRFLAG_XFLIP) {
      attr01 |= 0x10000000;
    }
    if (p->flags & SPRFLAG_YFLIP) {
      attr01 |= 0x20000000;
    }
    if (gObjBlendEnabled && (p->flags & SPRFLAG_UNK_14)) {
      attr01 |= 0x400;
    }
    if (((gObjMosaicEnabled & 1) && p->priority && !(p->flags & SPRFLAG_UNK_16)) || (p->flags & SPRFLAG_UNK_11)) {
      attr01 |= 0x1000;
    }
    z += p->offsetZ;

    if (p->flags & SPRFLAG_OAM_DIRECT) {
      s32 n;
      s32 attr2;

      attr2 = (s16)p->tileNum | (p->priority << 10) | (p->plttSlot << 12);
      n = gOAMCount;
      if (n < 128) {
        OamData* oam = &gOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        gOAMCount = n + 1;
        gOamDirty |= 1;
      }
    } else {
      s32 n;
      s32 attr2;
      u8 priority;

      z = FixToInt(1, z);
      if (z < -128) {
        z = -128;
      } else if (z > 127) {
        z = 127;
      }
      priority = p->priority;
      attr2 = (s16)p->tileNum | (priority << 10) | (p->plttSlot << 12);
      n = gStagedOAMCount;
      if (n < 128) {
        OamData* oam = &gStagedOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        oam->affineParam = ((z + 0x80) & 0xFF) << 8;
        gStagedOAMCount = n + 1;
        gOAMPrioCounts[priority]++;
      }
    }
  }
#else
  INCFUNC("asm/func/Particle_DrawListGameover.inc");
#endif
}

// SPRFLAG_UNK_13 の立った Particle だけを描くパス, AuxSprite_DrawListUnk13 と同じ関係
// 残差は p と attr01 のレジスタ (r4/r5) の入れ替わり, スケール比較の bgt が bhi になる点, 原典は u8 の scaleX を ldrb で読んで符号付き比較している
// flags を毎回 p->flags で読む形と offsetX/Y を直接書いて gcse に持ち上げさせる形で命令列はほぼ揃う, 本体を static inline に括ると z の複写まで一致するが一致に至らないので展開してある
NON_MATCH void Particle_DrawListUnk13(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  Particle* p;
  Vec3 screen;

  for (p = gParticleLists[gSpriteListIdx]; p != NULL; p = p->next) {
    s32 x, y, z;
    u32 attr01;

    if (p->flags & skipMask) {
      continue;
    }
    if (!(p->flags & SPRFLAG_UNK_13)) {
      continue;
    }

    if (!(p->flags & SPRFLAG_SCREEN_COORD)) {
      WorldToScreen(&screen, &p->pos);
      x = screen.x;
      y = screen.y;
      z = screen.z;
    } else {
      x = p->pos.x;
      y = p->pos.y;
      z = p->pos.z;
    }

    if (!(p->flags & SPRFLAG_NO_CLIP)) {
      s32 w = p->spriteWidth;
      s32 h = p->spriteHeight;
      s32 left = x + p->offsetX;
      s32 top = y + p->offsetY;

      if (left > 240 || top > 180 || left + w < 0 || top + h < 0) {
        continue;
      }
    }

    x += p->offsetX;
    y += p->offsetY;
    attr01 = p->oamAttr01 | ((x & 0x1FF) << 16) | (y & 0xFF);

    if (p->flags & SPRFLAG_AFFINE) {
      s32 idx;

      if (p->scaleX > 60 || p->scaleY > 60 || p->rotation != 0) {
        attr01 |= 0x300;
      } else {
        attr01 |= 0x100;
      }
      if (gObjAffineCount > 31) {
        idx = 0;
      } else {
        gObjAffineParams[gObjAffineCount].angle = p->rotation;
        gObjAffineParams[gObjAffineCount].scaleX = p->scaleX;
        gObjAffineParams[gObjAffineCount].scaleY = p->scaleY;
        idx = gObjAffineCount++;
      }
      attr01 |= idx << 25;
    }
    if (p->flags & SPRFLAG_XFLIP) {
      attr01 |= 0x10000000;
    }
    if (p->flags & SPRFLAG_YFLIP) {
      attr01 |= 0x20000000;
    }
    if (gObjBlendEnabled && (p->flags & SPRFLAG_UNK_14)) {
      attr01 |= 0x400;
    }
    if (((gObjMosaicEnabled & 1) && p->priority && !(p->flags & SPRFLAG_UNK_16)) || (p->flags & SPRFLAG_UNK_11)) {
      attr01 |= 0x1000;
    }
    z += p->offsetZ;

    if (p->flags & SPRFLAG_OAM_DIRECT) {
      s32 n;
      s32 attr2;

      attr2 = (s16)p->tileNum | (p->priority << 10) | (p->plttSlot << 12);
      n = gOAMCount;
      if (n < 128) {
        OamData* oam = &gOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        gOAMCount = n + 1;
        gOamDirty |= 1;
      }
    } else {
      s32 n;
      s32 attr2;
      u8 priority;

      z = FixToInt(1, z);
      if (z < -128) {
        z = -128;
      } else if (z > 127) {
        z = 127;
      }
      priority = p->priority;
      attr2 = (s16)p->tileNum | (priority << 10) | (p->plttSlot << 12);
      n = gStagedOAMCount;
      if (n < 128) {
        OamData* oam = &gStagedOAMBuffer[n];

        *(u32*)oam = attr01;
        *((u16*)oam + 2) = attr2;
        oam->affineParam = ((z + 0x80) & 0xFF) << 8;
        gStagedOAMCount = n + 1;
        gOAMPrioCounts[priority]++;
      }
    }
  }
#else
  INCFUNC("asm/func/Particle_DrawListUnk13.inc");
#endif
}

void nop_0822e738(void) {}
