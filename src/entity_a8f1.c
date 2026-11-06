#include "coffin.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "msgbus.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

typedef struct {
  Particle ptcl;  // 0x00
  bool8 active;   // 0x28, 立っている枠だけ EntityA8F1_Update が EntityA8F1Ptcl_Update に渡す
  u8 life;        // 0x29, 24 から数え下ろし, 0 で消える
  u8 unk_2a[2];   // 0x2A
  Vec3 vel;       // 0x2C, 毎フレーム 15/16 に減衰する
} EntityA8F1Ptcl;
static_assert(sizeof(EntityA8F1Ptcl) == 52);

typedef struct EntityA8F1 {
  Entity e;                                    // 0x000, ENTITY_UNK_9
  MsgQueue mq;                                 // 0x018, CLS_ETC
  u16 nearState;                               // 0x04C, プレイヤーが近いかを 0/1 で覚え, 変わったフレームだけ効果音を鳴らす
  u16 spriteParam;                             // 0x04E, sprite と sprite2 の +0x10 に入れる値
  AuxSprite sprite;                            // 0x050, flags に 0x200 が立つ
  AuxSpriteGfx gfx;                            // 0x07C, SPRITE_MAGIC_CIRCLE
  Vec3 pos;                                    // 0x098, '.p', y はタイルの attr から計算し直す
  AuxSprite sprite2;                           // 0x0A0
  AuxSpriteGfx gfx2;                           // 0x0CC, SPRITE_MAGIC_CIRCLE
  AuxSprite subSprites[3];                     // 0x0E8
  AuxSpriteGfx subGfx[3];                      // 0x16C, SPRITE_MAGIC_CIRCLE, パレットは plttID + 2
  u16 unk_1c0;                                 // 0x1C0, '.s' があるとき 7
  u8 unk_1c2;                                  // 0x1C2, '.s' の値
  u8 unk_1c3;                                  // 0x1C3, まだ未解析
  u16 plttID;                                  // 0x1C4
  u16 unk_1c6;                                 // 0x1C6, '.s' があるとき 8, 無いとき 0
  EntityA8F1Ptcl ptcls[8];                     // 0x1C8
  u8 unk_368;                                  // 0x368, '.s' があるとき 0x18, 無いとき 0
  u8 unk_369;                                  // 0x369, '.a'
  u16 unk_36a;                                 // 0x36A, '.s' があるとき 10, 無いとき 0
  s32 unk_36c;                                 // 0x36C, '.C'
  s32 unk_370;                                 // 0x370, '.i'
  s32 unk_374;                                 // 0x374
  s32 unk_378;                                 // 0x378, '.n'
  s32 unk_37c;                                 // 0x37C, '.c'
  u16 unk_380;                                 // 0x380, '.s' があるとき 1
  u16 stateTimer;                              // 0x382, updateCallback を差し替えるたびに 0 に戻る
  void (*updateCallback)(struct EntityA8F1*);  // 0x384
} EntityA8F1;
static_assert(sizeof(EntityA8F1) == 904);

void Player_MoveTo(Player* p, Vec3* pos, u32 scriptID, DirS32 dir);
void FUN_080a3004(EntityA8F1* p);
void FUN_080a2a2c(EntityA8F1* p);
void FUN_080a2d18(EntityA8F1* p);
void FUN_080a31dc(EntityA8F1* p);
void EntityA8F1_UpdateSubSprites(EntityA8F1* p);
bool32 FUN_08086af0(void);
void FUN_0807b8dc(Player* p);
void FUN_080a6e88(bool32 stopSound);

void EntityA8F1Ptcl_Update(EntityA8F1Ptcl* ptcl) {
  if (--ptcl->life == 0) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = FALSE;
  } else {
    ptcl->ptcl.pos.x += ptcl->vel.x;
    ptcl->ptcl.pos.y += ptcl->vel.y;
    ptcl->ptcl.pos.z += ptcl->vel.z;
    Particle_SetPose(&ptcl->ptcl, GetParticleGroup(PTCL_GROUP_2), ((ptcl->life >> 2) & 1) + 2);
    ptcl->vel.x = FixToInt(4, ptcl->vel.x * 15);
    ptcl->vel.y = FixToInt(4, ptcl->vel.y * 15);
    ptcl->vel.z = FixToInt(4, ptcl->vel.z * 15);
  }
}

// 88/81命令, EntityA8F1Ptcl_SpawnRise と同じ形の残差, 1回目の下書きで切り上げ
NON_MATCH void EntityA8F1Ptcl_SpawnFall(EntityA8F1Ptcl* ptcl, Vec3* pos) {
#ifdef NONMATCHING_C
  ptcl->ptcl.pos = *pos;
  ptcl->ptcl.pos.x = ptcl->ptcl.pos.x - 15 + (Random() & 0x1F);
  ptcl->ptcl.pos.y = ptcl->ptcl.pos.y + 0x300 + (u8)Random();
  ptcl->ptcl.pos.z = ptcl->ptcl.pos.z - 15 + (Random() & 0x1F);
  ptcl->life = 24;
  ptcl->vel.x = 0;
  ptcl->vel.y = -((Random() & 0x1F) + 32);
  ptcl->vel.z = 0;
  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  ptcl->active = TRUE;
#else
  INCFUNC("asm/func/EntityA8F1Ptcl_SpawnFall.inc");
#endif
}

// 78/76命令, 1回目の下書きで切り上げ, 原典は退避レジスタが1本少なく乱数テーブルの読みを使い回す
NON_MATCH void EntityA8F1Ptcl_SpawnRise(EntityA8F1Ptcl* ptcl, Vec3* pos) {
#ifdef NONMATCHING_C
  ptcl->ptcl.pos = *pos;
  ptcl->ptcl.pos.x = ptcl->ptcl.pos.x - 15 + (Random() & 0x1F);
  ptcl->ptcl.pos.y += (u8)Random();
  ptcl->ptcl.pos.z = ptcl->ptcl.pos.z - 15 + (Random() & 0x1F);
  ptcl->life = 24;
  ptcl->vel.x = 0;
  ptcl->vel.y = (Random() & 0x1F) + 24;
  ptcl->vel.z = 0;
  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  ptcl->active = TRUE;
#else
  INCFUNC("asm/func/EntityA8F1Ptcl_SpawnRise.inc");
#endif
}

s32 EntityA8F1_IsPlayerNear(EntityA8F1* p) {
  s32 dx = gStat->playerX - p->pos.x;
  s32 dz;

  if (dx < 0) {
    dx = -dx;
  }
  dz = gStat->playerZ - p->pos.z;
  if (dz < 0) {
    dz = -dz;
  }
  if (dx <= 96 && dz <= 96 && dx * dx + dz * dz <= 9216) {
    return TRUE;
  }
  return FALSE;
}

s32 EntityA8F1_IsSolarCoffinNear(EntityA8F1* p) {
  WorldPos* pos = Coffin_GetPos();

  if (pos != NULL && gCoffin->coffinID == COFFIN_SOLAR && gCoffin->state < 5) {
    s32 dy = pos->y - p->pos.y;

    if (dy < 0) {
      dy = -dy;
    }
    if (dy < 256) {
      s32 dx = pos->x - p->pos.x;
      s32 dz = pos->z - p->pos.z;

      if (dx <= 380 && dz <= 380 && dx * dx + dz * dz <= 144400) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

// 256/254命令の下書き, (2 - lvl) * 171 + 1026 の掛け算と定数の足し方, 段ごとの sub スプライトのアドレスの作り方が原典と違う
NON_MATCH void EntityA8F1_UpdateSubSprites(EntityA8F1* p) {
#ifdef NONMATCHING_C
  if (p->unk_1c0 != 0) {
    if (p->unk_1c0 <= 2) {
      p->subSprites[0].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[0].pos.y = (2 - p->unk_1c0) * 171 + 1026 + p->pos.y;
      p->subSprites[1].flags |= SPRFLAG_HIDDEN;
      p->subSprites[2].flags |= SPRFLAG_HIDDEN;
      p->sprite.poseIdx = p->spriteParam;
    } else if (p->unk_1c0 <= 4) {
      p->subSprites[0].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[0].pos.y = 1026 + p->pos.y;
      p->subSprites[1].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[1].pos.y = (4 - p->unk_1c0) * 171 + 684 + p->pos.y;
      p->subSprites[2].flags |= SPRFLAG_HIDDEN;
      p->sprite.poseIdx = p->spriteParam;
    } else if (p->unk_1c0 <= 6) {
      p->subSprites[0].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[0].pos.y = 1026 + p->pos.y;
      p->subSprites[1].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[1].pos.y = 684 + p->pos.y;
      p->subSprites[2].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[2].pos.y = (6 - p->unk_1c0) * 171 + 342 + p->pos.y;
      p->sprite.poseIdx = p->spriteParam;
      p->sprite.priority = 3;
    } else {
      p->subSprites[0].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[0].pos.y = 1026 + p->pos.y;
      p->subSprites[1].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[1].pos.y = 684 + p->pos.y;
      p->subSprites[2].flags &= ~SPRFLAG_HIDDEN;
      p->subSprites[2].pos.y = 342 + p->pos.y;
      p->sprite.poseIdx = p->spriteParam + 8;
      p->sprite.flags |= SPRFLAG_BLINK_ODD;
      p->sprite.priority = 1;
    }
  } else {
    p->subSprites[0].flags |= SPRFLAG_HIDDEN;
    p->subSprites[1].flags |= SPRFLAG_HIDDEN;
    p->subSprites[2].flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/EntityA8F1_UpdateSubSprites.inc");
#endif
}

void FUN_080a2c58(EntityA8F1* p);
void FUN_080a3340(EntityA8F1* p);
void FUN_080a2b30(EntityA8F1* p);
void FUN_080a30bc(EntityA8F1* p);
void FUN_0807c200(Player* p, DirS32 dir, u32 scriptID);
bool32 FUN_08086ab8(void);
void FUN_080a6edc(void);
void FUN_080a2a4c(EntityA8F1* p);
void FUN_080a2b78(EntityA8F1* p);
void FUN_080a2bdc(EntityA8F1* p);
void FUN_080a2cb0(EntityA8F1* p);
void EntityA8F1_UpdateIdle(EntityA8F1* p);
void FUN_080a3278(EntityA8F1* p);
void FUN_0807c36c(Player* p, DirS32 dir, u32 scriptID);
void FUN_080a3138(EntityA8F1* p);
void FUN_080a3208(EntityA8F1* p);
void FUN_080a32a4(EntityA8F1* p);
void FUN_080a2c2c(EntityA8F1* p);
void FUN_080a310c(EntityA8F1* p);

// 更新関数を差し替えて経過フレームを0に戻す
void EntityA8F1_SetUpdateCallback(EntityA8F1* p, void* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080a2a2c(EntityA8F1* p) {
  p->sprite.flags |= SPRFLAG_HIDDEN;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
}

void FUN_080a2a4c(EntityA8F1* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_CIRCLE_IN);
    p->stateTimer++;
  }
  if (p->unk_1c6 < 8) {
    p->unk_1c6++;
  }
  if (p->unk_368 < 23) {
    p->unk_368 += 2;
  } else {
    p->unk_368 = 24;
  }
  if (p->unk_368 == 0) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->unk_368;
  }
  if (p->unk_1c6 >= 8) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->unk_1c6 != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
  if (p->unk_368 > 23) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a2b30);
    MsgQueue_EndWait(&p->mq, 1);
  }
}

void FUN_080a2b30(EntityA8F1* p) {
  p->unk_368 = 0x18;
  p->unk_1c6 = 8;
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  p->sprite.pos.y = p->pos.y + p->unk_368;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
}

void FUN_080a2b78(EntityA8F1* p) {
  if (p->unk_368 >= 2) {
    p->unk_368 -= 2;
  } else {
    p->unk_368 = 0;
  }
  p->sprite.pos.y = p->pos.y + p->unk_368;
  if (p->unk_368 == 0) {
    p->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    p->sprite.priority = 3;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    EntityA8F1_SetUpdateCallback(p, FUN_080a2bdc);
  }
}

void FUN_080a2bdc(EntityA8F1* p) {
  if (p->unk_1c0 <= 6) {
    p->unk_1c0++;
    EntityA8F1_UpdateSubSprites(p);
  } else {
    p->stateTimer++;
    if (p->stateTimer > 0x1F) {
      PlaySound_082406e0(SE_WARP_START);
      EntityA8F1_SetUpdateCallback(p, FUN_080a2c2c);
    }
  }
}

void FUN_080a2c2c(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a2c58);
  }
}

void FUN_080a2c58(EntityA8F1* p) {
  if (p->stateTimer < 32 && !(p->stateTimer & 3)) {
    EntityA8F1Ptcl_SpawnRise(&p->ptcls[p->stateTimer >> 2], &p->pos);
  }
  if (++p->stateTimer == 64) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a2cb0);
  }
}

void FUN_080a2cb0(EntityA8F1* p) {
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (p->sprite.pos.y < p->pos.y + 22) {
    p->sprite.pos.y += 2;
  }
  if (p->unk_1c0 != 0) {
    p->unk_1c0--;
    EntityA8F1_UpdateSubSprites(p);
  } else {
    p->sprite2.flags &= ~SPRFLAG_HIDDEN;
    EntityA8F1_SetUpdateCallback(p, EntityA8F1_UpdateIdle);
    MsgQueue_EndWait(&p->mq, 1);
  }
}

// 122/123命令, 原典は &stateTimer を r5 に持ち越して拡大率の書き込みのたびに読み直す, 増やした値を t に受ける形は試済
NON_MATCH void FUN_080a2d18(EntityA8F1* p) {
#ifdef NONMATCHING_C
  u16 t = ++p->stateTimer;

  if (t < 64) {
    p->sprite.flags = (p->sprite.flags & ~SPRFLAG_HIDDEN) | SPRFLAG_AFFINE;
    p->sprite2.flags |= SPRFLAG_AFFINE;
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
    p->sprite.scaleX = t;
    p->sprite.scaleY = t;
    p->sprite.rotation = t << 2;
    p->sprite2.scaleX = p->sprite.scaleX;
    p->sprite2.scaleY = p->sprite.scaleX;
    p->sprite2.rotation = p->sprite.rotation;
    p->sprite.pos.y = p->pos.y + 22;
  } else if (t == 64) {
    p->sprite.flags &= ~SPRFLAG_AFFINE;
    p->sprite2.flags &= ~SPRFLAG_AFFINE;
    p->sprite.scaleX = Q6(1);
    p->sprite.scaleY = Q6(1);
    p->sprite2.scaleX = Q6(1);
    p->sprite2.scaleY = Q6(1);
  } else if (t >= 80) {
    if (--p->sprite.pos.y > p->pos.y) {
      Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
    } else {
      Video_SetAuxSpritePltt(&p->gfx, p->plttID);
      p->sprite.flags |= SPRFLAG_HIDDEN;
      EntityA8F1_SetUpdateCallback(p, EntityA8F1_UpdateIdle);
    }
  }
#else
  INCFUNC("asm/func/FUN_080a2d18.inc");
#endif
}

// プレイヤーが近いと浮き上がって光り, A ボタンでプレイヤーを pos へ飛ばす (Entity7C62_UpdateIdle と同じ形)
void EntityA8F1_UpdateIdle(EntityA8F1* p) {
  s32 near;

  if (!(gGameFlags & GAMEFLAG_EVENT)) {
    if (p->unk_36a < 10) {
      p->unk_36a++;
    }
  }
  near = EntityA8F1_IsPlayerNear(p);
  if (near) {
    if (p->unk_369 == 0) {
      if (TEST_FLAGS(gPlayerModes[0], PMODE_ACTIVE) && gPlayerPtr[0]->action != 0x18 && gPlayerPtr[0]->action != 0x19 && (gInput[0].pressed & A_BUTTON)) {
        PlaySound_082406e0(SE_SOLAR_STAND_DENY);
      }
    } else {
      if (p->nearState != 1) {
        PlaySound_082406e0(SE_CIRCLE_IN);
        p->nearState = 1;
      }
      if (p->unk_1c6 < 8) {
        p->unk_1c6++;
      }
      if (p->unk_368 < 23) {
        p->unk_368 += 2;
      } else {
        p->unk_368 = 24;
      }
      if (TEST_FLAGS(gPlayerModes[0], PMODE_ACTIVE) && (gInput[0].pressed & A_BUTTON) && !gPlayerPtr[0]->formRequest && p->unk_36a > 9) {
        p->unk_1c6 = 8;
        Player_MoveTo(gPlayerPtr[0], &p->pos, 0, 4);
        EntityA8F1_SetUpdateCallback(p, FUN_080a3004);
      }
    }
  } else {
    if (p->nearState != 0) {
      PlaySound_082406e0(SE_CIRCLE_OUT);
      p->nearState = near;
    }
    if (p->unk_1c6 != 0) {
      p->unk_1c6--;
    }
    if (p->unk_368 > 2) {
      p->unk_368 -= 2;
    } else {
      p->unk_368 = near;
    }
  }

  if (p->unk_368 == 0) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->unk_368;
  }

  if (p->unk_1c6 > 7) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->unk_1c6 != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

void FUN_080a3004(EntityA8F1* p) {
  if (p->unk_368 >= 2) {
    p->unk_368 -= 2;
  } else {
    p->unk_368 = 0;
  }
  p->sprite.pos.y = p->pos.y + p->unk_368;
  if (p->unk_368 == 0 && gPlayerPtr[0]->action == 0) {
    FUN_0807c200(gPlayerPtr[0], 4, 0);
    p->unk_1c3 = 0;
    if (EntityA8F1_IsSolarCoffinNear(p) && FUN_08086ab8()) {
      p->unk_1c3 = 1;
    }
    p->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    p->sprite.priority = 3;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    EntityA8F1_SetUpdateCallback(p, FUN_080a30bc);
    if (p->unk_36c != 0) {
      VM_ExecByID(p->unk_36c, NULL);
    }
  }
}

void FUN_080a30bc(EntityA8F1* p) {
  if (p->unk_1c0 <= 6) {
    p->unk_1c0++;
    EntityA8F1_UpdateSubSprites(p);
  } else {
    p->stateTimer++;
    if (p->stateTimer > 0x1F) {
      PlaySound_082406e0(SE_WARP_START);
      EntityA8F1_SetUpdateCallback(p, FUN_080a310c);
    }
  }
}

void FUN_080a310c(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a3138);
  }
}

// 72/72命令, 残差はレジスタの割り当てと ScriptArgs の組み立て順だけ, 1回目の下書きで切り上げ
NON_MATCH void FUN_080a3138(EntityA8F1* p) {
#ifdef NONMATCHING_C
  if (p->stateTimer < 32 && !(p->stateTimer & 3)) {
    EntityA8F1Ptcl_SpawnRise(&p->ptcls[p->stateTimer >> 2], &p->pos);
  }
  if (++p->stateTimer == 64) {
    if (p->unk_374 != 0) {
      u32 argv[1];
      ScriptArgs sa;

      sa.argc = 1;
      argv[0] = p->unk_378;
      sa.argv = argv;
      VM_ExecByID(p->unk_374, &sa);
    }
    if (p->unk_1c3 && p->unk_37c != 0) {
      VM_ExecByID(p->unk_37c, NULL);
    }
  }
#else
  INCFUNC("asm/func/FUN_080a3138.inc");
#endif
}

void FUN_080a31dc(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0x3B) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a3208);
  }
}

void FUN_080a3208(EntityA8F1* p) {
  if (p->stateTimer == 16) {
    FUN_0807c36c(gPlayerPtr[0], 4, 0);
  }
  if (p->stateTimer < 32 && !(p->stateTimer & 3)) {
    EntityA8F1Ptcl_SpawnFall(&p->ptcls[p->stateTimer >> 2], &p->pos);
  }
  if (++p->stateTimer > 32) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a3278);
  }
}

void FUN_080a3278(EntityA8F1* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    EntityA8F1_SetUpdateCallback(p, FUN_080a32a4);
  }
}

void FUN_080a32a4(EntityA8F1* p) {
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (p->sprite.pos.y < p->pos.y + 22) {
    p->sprite.pos.y += 2;
  }
  if (p->unk_1c0 != 0) {
    p->unk_1c0--;
    EntityA8F1_UpdateSubSprites(p);
  } else {
    Player_Unlock(gPlayerPtr[0]);
    FUN_080a6edc();
    p->sprite2.flags &= ~SPRFLAG_HIDDEN;
    if (p->unk_1c2 != 0) {
      EntityA8F1_SetUpdateCallback(p, FUN_080a3340);
    } else {
      EntityA8F1_SetUpdateCallback(p, EntityA8F1_UpdateIdle);
    }
    if (p->unk_370 != 0) {
      VM_ExecByID(p->unk_370, NULL);
    }
  }
}

// 127/125命令, 残差は縮小率 64 - stateTimer を2回書くところ (原典は1回作って使い回す) と分岐の距離
NON_MATCH void FUN_080a3340(EntityA8F1* p) {
#ifdef NONMATCHING_C
  if (p->unk_368 > 2) {
    p->unk_368 -= 2;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->unk_368;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  if (p->unk_1c6 != 0) {
    p->unk_1c6--;
  }
  if (p->unk_1c6 >= 8) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->unk_1c6 != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
  if (++p->stateTimer < 64) {
    p->sprite.flags |= SPRFLAG_AFFINE;
    p->sprite2.flags |= SPRFLAG_AFFINE;
    p->sprite.scaleX = Q6(1) - (u8)p->stateTimer;
    p->sprite.scaleY = Q6(1) - (u8)p->stateTimer;
    p->sprite.rotation = p->stateTimer << 2;
    p->sprite2.scaleX = p->sprite.scaleX;
    p->sprite2.scaleY = p->sprite.scaleX;
    p->sprite2.rotation = p->sprite.rotation;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    KillEntity(&p->e);
  }
#else
  INCFUNC("asm/func/FUN_080a3340.inc");
#endif
}

// 48/59命令, camera.c の Camera_PollMessages と同じメッセージ取り出しのループの残差, 原典は p と mq を別々のレジスタに持って条件式で gMsgBus を毎回読み直す
NON_MATCH void EntityA8F1_HandleMessages(EntityA8F1* p) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    if (msg->cmd == 7) {
      EntityA8F1_SetUpdateCallback(p, FUN_080a2a4c);
    } else if (msg->cmd == 8) {
      EntityA8F1_SetUpdateCallback(p, FUN_080a2b78);
    }
  }
#else
  INCFUNC("asm/func/EntityA8F1_HandleMessages.inc");
#endif
}

s32 EntityA8F1_Update(EntityA8F1* p) {
  s32 i;

  EntityA8F1_HandleMessages(p);
  p->updateCallback(p);
  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active) {
      EntityA8F1Ptcl_Update(&p->ptcls[i]);
    }
  }
  return 0;
}

s32 EntityA8F1_Destroy(EntityA8F1* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  for (i = 0; i < 3; i++) {
    AuxSprite_Remove(&p->subSprites[i]);
  }
  for (i = 0; i < 8; i++) {
    Particle_Remove((Particle*)&p->ptcls[i]);
  }
  MsgQueue_Unregister(&p->mq);
  return 0;
}

void EntityA8F1_InitPtcls(EntityA8F1* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle* pt = &p->ptcls[i].ptcl;

    Particle_Add(pt, GetParticleGroup(PTCL_GROUP_2), SPRFLAG_HIDDEN);
    Particle_SetOffset(pt, -4, -4);
    Particle_SetPltt(pt, 1);
    Particle_SetPose(pt, GetParticleGroup(PTCL_GROUP_2), 2);
    pt->priority = 1;
    pt->offsetZ = 20;
    pt->pos = p->pos;
    p->ptcls[i].active = FALSE;
  }
}

// 518/509命令の下書き, sprite のポインタを r4 に置いて poseIdx を書く形と sub スプライトのループのレジスタが原典と違う, Entity7C62_Init が近い形
NON_MATCH s32 EntityA8F1_Init(EntityA8F1* p, u32 id, u32 param_3) {
#ifdef NONMATCHING_C
  s32 i;

  if (VM_SeekToNamedArg('p')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
    p->pos.y = TileHeightAt(&p->pos);
  } else {
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
  }
  if (VM_SeekToNamedArg('C')) {
    p->unk_36c = VM_GetValue();
  } else {
    p->unk_36c = 0;
  }
  if (VM_SeekToNamedArg('c')) {
    p->unk_37c = VM_GetValue();
  } else {
    p->unk_37c = 0;
  }
  if (VM_SeekToNamedArg('i')) {
    p->unk_370 = VM_GetValue();
  } else {
    p->unk_370 = 0;
  }
  if (VM_SeekToNamedArg('o')) {
    p->unk_374 = VM_GetValue();
  } else {
    p->unk_374 = 0;
  }
  if (VM_SeekToNamedArg('d')) {
    p->spriteParam = VM_GetValue();
  } else {
    p->spriteParam = 6;
  }
  if (VM_SeekToNamedArg('a')) {
    p->unk_369 = VM_GetValue();
  } else {
    p->unk_369 = 0;
  }
  if (VM_SeekToNamedArg('n')) {
    p->unk_378 = VM_GetValue();
  } else {
    p->unk_378 = 0;
  }
  p->plttID = (p->spriteParam >> 1) * 3 + 97;

  Video_GetAuxSprite(&p->gfx, SPRITE_MAGIC_CIRCLE);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  p->sprite.poseIdx = p->spriteParam;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  p->sprite.flags |= SPRFLAG_BLINK_ODD;
  p->sprite.priority = 3;
  p->sprite.pos = p->pos;

  Video_GetAuxSprite(&p->gfx2, SPRITE_MAGIC_CIRCLE);
  AuxSprite_Add(&p->sprite2, &p->gfx2, 0);
  p->sprite2.poseIdx = p->spriteParam;
  Video_SetAuxSpritePltt(&p->gfx2, p->plttID);
  p->sprite2.flags |= SPRFLAG_BLINK_EVEN;
  p->sprite2.priority = 3;
  p->sprite2.pos = p->pos;

  for (i = 0; i < 3; i++) {
    Video_GetAuxSprite(&p->subGfx[i], SPRITE_MAGIC_CIRCLE);
    AuxSprite_Add(&p->subSprites[i], &p->subGfx[i], 0);
    p->subSprites[i].poseIdx = (p->spriteParam & 1) + 16;
    Video_SetAuxSpritePltt(&p->subGfx[i], p->plttID + 2);
    p->subSprites[i].flags |= SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
    p->subSprites[i].priority = 1;
    p->subSprites[i].pos = p->pos;
  }
  EntityA8F1_InitPtcls(p);
  MsgQueue_Register(&p->mq, id, 10);

  if (VM_SeekToNamedArg('D')) {
    p->nearState = 0;
    p->unk_1c6 = 0;
    p->unk_36a = 0;
    p->unk_368 = 0;
    EntityA8F1_SetUpdateCallback(p, FUN_080a2a2c);
  } else {
    s32 flash = 0;
    s32 script = 0;

    if (VM_SeekToNamedArg('f')) {
      flash = VM_GetValue();
    }
    if (VM_SeekToNamedArg('s')) {
      script = VM_GetValue();
    }
    if (flash) {
      s32 warp = 0;

      PlaySound_082406e0(SE_WARP_END);
      p->unk_380 = 1;
      FUN_080a6e88(FALSE);
      FUN_0807a91c(gPlayerPtr[0], &p->pos);
      FUN_0807b8dc(gPlayerPtr[0]);
      p->sprite.flags &= ~SPRFLAG_HIDDEN;
      Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
      p->sprite2.flags |= SPRFLAG_HIDDEN;
      p->unk_1c0 = 7;
      EntityA8F1_UpdateSubSprites(p);
      p->unk_1c6 = 8;
      p->nearState = 1;
      p->unk_36a = 10;
      p->unk_368 = 24;
      p->unk_1c2 = script;
      EntityA8F1_SetUpdateCallback(p, FUN_080a31dc);
      if (VM_SeekToNamedArg('w')) {
        warp = VM_GetValue();
      }
      if (warp && FUN_08086af0()) {
        FUN_08086a4c(&p->pos);
      }
    } else {
      p->nearState = 0;
      p->unk_1c6 = 0;
      p->unk_36a = 0;
      p->unk_368 = 0;
      if (script) {
        PlaySound_082406e0(SONG_350);
        p->sprite.flags |= SPRFLAG_AFFINE;
        p->sprite2.flags |= SPRFLAG_AFFINE;
        p->sprite.scaleX = 1;
        p->sprite.scaleY = 1;
        p->sprite2.scaleX = 1;
        p->sprite2.scaleY = 1;
        EntityA8F1_SetUpdateCallback(p, FUN_080a2d18);
      } else {
        EntityA8F1_SetUpdateCallback(p, EntityA8F1_UpdateIdle);
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/EntityA8F1_Init.inc");
#endif
}

// 0xA8F1
EntityA8F1* EntityA8F1_Create(u32 id, u32 param_2) {
  EntityA8F1* p = CreateEntity(ENTITY_UNK_9, sizeof(EntityA8F1));

  if (p != NULL) {
    SetEntityRoutine(p, EntityA8F1_Update, EntityA8F1_Destroy);
    if (EntityA8F1_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
