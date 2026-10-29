#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "sprite_aux.h"

// 花粉や鱗粉攻撃1つ分の情報
typedef struct {
  u16 delay;          // 0x00, 0 でなければ毎フレーム減る, 0 になるまでアニメが終わっても次へ進まない
  u8 state;           // 0x02, PTR_ARRAY_085ab998 の添字
  u8 angle;           // 0x03, vel の向き
  u8 speed;           // 0x04, vel の大きさ
  u8 power;           // 0x05, プレイヤーに触れたとき DustManager.power に足す
  u16 timer;          // 0x06, 毎フレーム +1
  u8 kind;            // 0x08, 0..3, DustManager.attrKind に写される, 0 のときだけ sprite.pos が範囲内に丸められる
  u8 unk_09[3];       // 0x09
  Vec3 vel;           // 0x0C, 毎フレーム sprite.pos に足される
  AuxSpriteGfx gfx;   // 0x14, SPRITE_DUNEYRR_AUX, パレット行 0x224
  AuxSprite sprite;   // 0x30, pose 0xC, priority 2
  AuxAnimState anim;  // 0x5C, animFile のアニメ3番から始まる
} Dust;
static_assert(sizeof(Dust) == 108);

// 花粉や鱗粉攻撃の管理構造体
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  AuxAnimFile* animFile;  // 0x018, ANIM_31F4
  u32 usedMask;           // 0x01C, elems のどのスロットが使用中かのビットマスク
  u32 frameCount;         // 0x020, 毎フレーム +1, 下位2bitを添字 & 3 と比べる
  u16 hitCount;           // 0x024, 毎フレーム 0 に戻してから, プレイヤーに触れた鱗粉の数を積む
  u16 unk_26;             // 0x026, hitCount * 12 を足して 0x40 に達すると player に power のダメージを与えるカウンタ
  u16 power;              // 0x028, 毎フレーム 0 に戻してから elems が積む, player に与えるダメージ
  u8 attrKind;            // 0x02A, ダメージの属性, 0 と 3 は風, 1 は地, 2 はダーク, 1 のとき player を見る分岐に入る
  u8 unk_2b;              // 0x02B
  Dust dusts[32];         // 0x02C
  Player* player;         // 0xDAC, gPlayerPtr[0]
} DustManager;
static_assert(sizeof(DustManager) == 3504);

static DustManager* gDustManager;  // 0x03000128

void FUN_08055fe4(DustManager*, Dust*, s32);
void FUN_080561b8(DustManager*, Dust*, s32);
void FUN_080563b0(DustManager*, Dust*, s32);

const u16 u16_ARRAY_085ab990[4] = {4, 1, 2, 4};  // 0x085AB990

void (*const PTR_ARRAY_085ab998[3])(DustManager*, Dust*, s32) = {
    FUN_08055fe4,
    FUN_080561b8,
    FUN_080563b0,
};  // 0x085AB998

// 残差は前半の attrKind / playerPos のレジスタ割り当てと, 後半の AuxAnim 手動送り (FUN_080563b0 と同じ壁), Tier A-C は試済
NON_MATCH void FUN_08055fe4(DustManager* p, Dust* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos;
  Vec3* vel;
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  bool32 ended;

  if (elem->timer > 15) {
    u8 power;
    u8 attrKind;
    WorldPos* playerPos;

    power = elem->power;
    attrKind = elem->kind;
    pos = &elem->sprite.pos;
    playerPos = &p->player->mover.pos;
    if (p->hitCount < u16_ARRAY_085ab990[attrKind] && (p->frameCount & 3) == (idx & 3)) {
      s32 dx = abs(playerPos->x - pos->x);
      if (dx < 0x80) {
        s32 dz = abs(playerPos->z - pos->z);
        if (dz < 0x80) {
          p->attrKind = attrKind;
          p->hitCount++;
          p->power += power;
        }
      }
    }
  }
  pos = &sprite->pos;
  vel = &elem->vel;
  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  anim = &elem->anim;
  cmd = &anim->cmds[anim->cmdIdx];
  sprite->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    sprite->flags |= SPRFLAG_YFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        ended = TRUE;
      } else {
        anim->cmdIdx--;
        ended = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx < anim->cmdCount) {
        ended = FALSE;
      } else {
        anim->cmdIdx = 0;
        ended = TRUE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  } else {
    ended = FALSE;
  }
  if (ended) {
    elem->state++;
    elem->timer = 0;
    AuxAnim_SetAnim(anim, p->animFile, elem->state + 3, 0, 0);
  }
#else
  INCFUNC("asm/func/FUN_08055fe4.inc");
#endif
}

// 残差は AuxAnim 手動送りの部分 (FUN_080563b0 と同じ壁), 前半のプレイヤー判定は FUN_08055fe4 と同じ形, 1 回目で打ち切り
NON_MATCH void FUN_080561b8(DustManager* p, Dust* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos = &sprite->pos;
  Vec3* vel = &elem->vel;
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  bool32 ended;
  u8 power;
  u8 attrKind;
  WorldPos* playerPos;

  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  power = elem->power;
  attrKind = elem->kind;
  playerPos = &p->player->mover.pos;
  if (p->hitCount < u16_ARRAY_085ab990[attrKind] && (p->frameCount & 3) == (idx & 3)) {
    s32 dx = abs(playerPos->x - pos->x);
    if (dx < 0x80) {
      s32 dz = abs(playerPos->z - pos->z);
      if (dz < 0x80) {
        p->attrKind = attrKind;
        p->hitCount++;
        p->power += power;
      }
    }
  }

  if (elem->delay != 0) {
    elem->delay--;
  }
  anim = &elem->anim;
  cmd = &anim->cmds[anim->cmdIdx];
  sprite->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    sprite->flags |= SPRFLAG_YFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        ended = TRUE;
      } else {
        anim->cmdIdx--;
        ended = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx < anim->cmdCount) {
        ended = FALSE;
      } else {
        anim->cmdIdx = 0;
        ended = TRUE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  } else {
    ended = FALSE;
  }
  if (ended && elem->delay == 0) {
    if (elem->kind == 0 || elem->kind == 3) {
      elem->state++;
      elem->timer = 0;
      AuxAnim_SetAnim(anim, p->animFile, elem->state + 3, 0, 0);
    } else {
      CLEAR_BIT(p->usedMask, idx);
      AuxSprite_Remove(sprite);
    }
  }
#else
  INCFUNC("asm/func/FUN_080561b8.inc");
#endif
}

// 残差は AuxAnim 手動送りの部分だけ (フリップ判定の定数の使い回し, cmdIdx の & 0xFFFF, ended の分岐の置き方), SpriteHolder_AdvanceAnim と同じ壁, Tier A-C は試済
// フリップ判定を static inline にすると定数は共有されるが eors に畳まれて遠のく
NON_MATCH void FUN_080563b0(DustManager* p, Dust* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos = &sprite->pos;
  Vec3* vel = &elem->vel;
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  bool32 ended;

  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  anim = &elem->anim;
  cmd = &anim->cmds[anim->cmdIdx];
  sprite->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    sprite->flags |= SPRFLAG_YFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        ended = TRUE;
      } else {
        anim->cmdIdx--;
        ended = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx < anim->cmdCount) {
        ended = FALSE;
      } else {
        anim->cmdIdx = 0;
        ended = TRUE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  } else {
    ended = FALSE;
  }
  if (ended) {
    CLEAR_BIT(p->usedMask, idx);
    AuxSprite_Remove(sprite);
  }
#else
  INCFUNC("asm/func/FUN_080563b0.inc");
#endif
}

s32 DustManager_Update(DustManager* p) {
  Dust* dust;
  s32 i;

  p->hitCount = 0;
  p->power = 0;
  dust = p->dusts;
  for (i = 0; i < 32; i++, dust++) {
    if (p->usedMask & (1 << i)) {
      PTR_ARRAY_085ab998[dust->state](p, dust, i);
      if (dust->kind == 0) {
        Vec3* pos = &dust->sprite.pos;

        if (pos->x < 0x120) {
          pos->x = 0x120;
        } else if (pos->x > 0xBE0) {
          pos->x = 0xBE0;
        }
        if (pos->z < 0x220) {
          pos->z = 0x220;
        } else if (pos->z > 0xC80) {
          pos->z = 0xC80;
        }
      }
      dust->timer++;
    }
  }
  if (p->hitCount != 0) {
    p->unk_26 += p->hitCount * 12;
    if (p->unk_26 >= 0x40) {
      p->unk_26 = 0;
      switch (p->attrKind) {
        case 0:
        case 3: {
          Player_TakeInstantHit(p->player, p->power, 0, 0, 8, HBATTR_CLOUD);
          break;
        }
        case 1: {
          Player_TakeInstantHit(p->player, p->power, 0, 0, 8, HBATTR_EARTH);
          break;
        }
        case 2: {
          Player_TakeInstantHit(p->player, p->power, 0, 0, 8, HBATTR_DARK);
          break;
        }
      }
    }
  } else {
    p->unk_26--;
  }
  p->frameCount++;
  return 0;
}

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

s32 DustManager_Destroy(DustManager* p) {
  Dust* dust = p->dusts;
  s32 i;

  for (i = 0; i < 32; i++, dust++) {
    if (p->usedMask & (1 << i)) {
      AuxSprite_Remove(&dust->sprite);
    }
  }
  gDustManager = NULL;
  return 0;
}

s32 DustManager_Init(DustManager* p) {
  Dust* dust;
  s32 i;

  gDustManager = p;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_31F4);
  p->usedMask = 0;
  dust = p->dusts;
  for (i = 0; i < 32; i++, dust++) {
    Vec3* pos;

    dust->speed = 0;
    dust->angle = 0;
    if (!Video_GetAuxSprite(&dust->gfx, SPRITE_DUNEYRR_AUX)) {
      return -1;
    }
    Video_SetAuxSpritePltt(&dust->gfx, 548);
    AuxSprite_Setup(&dust->sprite, &dust->gfx, 0);
    dust->sprite.poseIdx = 12;
    AuxAnim_SetAnim(&dust->anim, p->animFile, 3, 0, 0);
    dust->sprite.priority = 2;
    pos = &dust->sprite.pos;
    CpuFill32(0, pos, sizeof(Vec3));
  }
  p->player = GetPlayer(0);
  return 0;
}

DustManager* DustManager_Create(void) {
  if (gDustManager == NULL) {
    DustManager* p = CreateEntity(ENTITY_UNK_8, sizeof(DustManager));

    if (p != NULL) {
      SetEntityRoutine(p, DustManager_Update, DustManager_Destroy);
      if (DustManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gDustManager;
}

// 残差は switch の case 0/3 と default (同じ中身) が cross jump で1つに畳まれる点と, ループ内の gfx / pos のポインタの持ち方, 原典は2つの塊でレジスタが違うので畳まれない
// 引数はすべて 32bit, 3つのローカルは s32 で書いて byte / halfword で読む形までは合わせた, Tier A-C は試済
NON_MATCH s32 DustManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos) {
#ifdef NONMATCHING_C
  DustManager* p = gDustManager;
  Dust* dust;
  s32 i;
  s32 added;
  s32 halfAngleRange;
  s32 halfSpeedRange;
  s32 animIdx;
  s32 plttID;
  s32 priority;

  if (p == NULL) {
    p = DustManager_Create();
    if (p == NULL) {
      return -1;
    }
  }
  switch (kind) {
    case 0:
    case 3: {
      animIdx = 3;
      plttID = 0x224;
      priority = 2;
      break;
    }
    case 1: {
      animIdx = 6;
      plttID = 0x22C;
      priority = 1;
      break;
    }
    case 2: {
      animIdx = 8;
      plttID = 0x23A;
      priority = 2;
      break;
    }
    default: {
      animIdx = 3;
      plttID = 0x224;
      priority = 2;
      break;
    }
  }
  halfAngleRange = angleRange >> 1;
  halfSpeedRange = speedRange >> 1;
  added = 0;
  dust = p->dusts;
  for (i = 0; i < 32; i++, dust++) {
    if (!(p->usedMask & (1 << i))) {
      AuxSprite* sprite = &dust->sprite;

      dust->kind = kind;
      dust->delay = delay;
      if ((u8)kind == 0 || (u8)kind == 3) {
        dust->state = 0;
      } else {
        dust->state = 1;
      }
      dust->timer = 0;
      dust->power = power;
      if (angleRange == 0) {
        dust->angle = angle;
      } else {
        dust->angle = angle + Mod(Random(), angleRange) - halfAngleRange;
      }
      if (speedRange == 0) {
        dust->speed = speed;
      } else {
        dust->speed = speed + Mod(Random(), speedRange) - halfSpeedRange;
      }
      dust->vel.x = POLAR_X(dust->speed, dust->angle);
      dust->vel.y = 0;
      dust->vel.z = POLAR_Z(dust->speed, dust->angle);
      dust->vel.y = 0;
      sprite->pos = *pos;
      AuxAnim_SetAnim(&dust->anim, p->animFile, animIdx, 0, 0);
      sprite->poseIdx = 18;
      sprite->priority = priority;
      Video_AddAuxSpriteIntoDrawList(sprite, 0);
      Video_SetAuxSpritePltt(&dust->gfx, plttID);
      if (dust->kind == 0) {
        Vec3* spritePos = &dust->sprite.pos;

        if (spritePos->x < 0x120) {
          spritePos->x = 0x120;
        } else if (spritePos->x > 0xBE0) {
          spritePos->x = 0xBE0;
        }
        if (spritePos->z < 0x220) {
          spritePos->z = 0x220;
        } else if (spritePos->z > 0xC80) {
          spritePos->z = 0xC80;
        }
      }
      SET_BIT(p->usedMask, i);
      added++;
      if (added >= count) {
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/DustManager_Emit.inc");
#endif
}
