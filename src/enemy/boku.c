#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u16 scriptID_658;           // 0x658, 0 でなければ unk_65b が unk_65a に届いたときに実行する
  u8 unk_65a;                 // 0x65A, scriptID_658 を実行するまでのフレーム数
  u8 unk_65b;                 // 0x65B, 毎フレーム +1
  u16 unk_65c;                // 0x65C
  u16 unk_65e;                // 0x65E
  WorldPos unk_660;           // 0x660
  Vec3 unk_668;               // 0x668
  u16 timer_670;              // 0x670, FUN_080ffd28 が毎フレーム 1 減らす, 0 になるまで FUN_080ff270 が状態ハンドラを呼ばない
  u16 unk_672;                // 0x672, '.P[2]=120', FUN_080ff470 が timer_670 の初期値として写す
  u8 unk_674;                 // 0x674, '.P[0]=120'
  u8 unk_675[0x67C - 0x675];  // 0x675
  u16 unk_67c;                // 0x67C
  u16 unk_67e;                // 0x67E, '.P[1]=120'
  NavAgent navAgent;          // 0x680, Enemy.navAgent が指す
  Vec3 unk_6a4;               // 0x6A4, Enemy.unk_4a8 が指す
} Boku;
static_assert(sizeof(Boku) == 1708);

void FUN_080e499c(Enemy* p);
void FUN_080e64b4(Enemy* p, s32 kind);
bool32 FUN_080f62b0(Enemy* p);
bool8 FUN_080f0a0c(Enemy* p);
void FUN_080f3cdc(Enemy* p);
void FUN_080e7b6c(Enemy* p);
void Entity081f3324_Spawn(Vec3* pos, Vec3* target, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime, s32 groundTime, s32 speed, s32 unk_9);
bool8 FUN_080e8038(s32 fromIdx, s32 idx, s32 fromHeight, s32 fromStairs);

void FUN_080ff67c(Boku* p);
void FUN_080ffda8(Boku* p);
void FUN_080fc28c(Boku* p);
void FUN_080ffad8(Boku* p);
void FUN_080fc174(Boku* p, s32 param_2);

const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_eneinline_h_08251f90[] = "eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_eneinline_h_08251f9c[] = "eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251fa8[] = "../system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_bokucom_c_08251fc0[] = "bokucom.c";

// 生成時に退避しておいた状態とフラグに戻し, 一時的な値を全部初期化する
static inline void Enemy_RestoreInitialState(Enemy* p) {
  p->flags = p->unk_55c;
  p->flags2 = p->unk_560;
  p->mover.angle = p->unk_564;
  p->subState0 = p->unk_565;
  p->subState1 = p->unk_566;
  p->subState2 = p->unk_567;
  p->handlerState = p->unk_568;
  p->state = p->unk_56c;
  p->flags5 = p->unk_572;
  p->heightAboveFloor = p->unk_570;
  p->hp = p->maxHp;
  p->flags4 = 0;
  p->unk_222 = 0;
  p->flags3 = 0;
  p->subStateDone = FALSE;
  p->subStateBegun = TRUE;
  p->stateBegun = TRUE;
  p->animForceRestart = FALSE;
  p->unk_24e = 0;
  p->unk_192 = 0;
  p->unk_544 = 0;
  p->nodeWait = 0;
  p->hitTargetID = 0;
  p->playerMover = NULL;
  p->angle = 0;
  p->unk_21c = 0;
  p->animSpeedDiv = 1;
  p->weaponExpMask = 0;
  p->flags6 = 0;
  p->unk_4a0 = 0;
  p->unk_48c = 0;
  p->unk_4be = 0;
  p->unk_48d = 0;
  p->unk_48e = 0;
  ClearMemory(p->unk_458, 8);
  p->unk_464 = 0;
  p->unk_460 = 0;
  p->unk_462 = 0;
  Enemy_ClearPendingState(p, gString_08251fa8, 2434);
  p->unk_540 = 0;
  p->unk_541 = 0;
  p->unk_542 = 0xFF;
  p->unk_548 = NULL;
  p->unk_54c = 0;
  p->unk_54d = 0;
  p->unk_54e = 0;
  p->unk_54f = 0;
  FUN_080eeee0(p);
}

static inline void Boku_ClearUnk65c(Boku* p, u16 bit) { p->unk_65c &= ~bit; }

static inline bool8 IsLinkPlay(void) {
  if (gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) return TRUE;
  return FALSE;
}

void Boku_OnHit(HitboxData* a, HitboxData* b, Boku* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// Mimic_OnHurt と同じ食らい判定 (敵共通の処理の inline 展開らしい), Mimic_OnHurt の下書きをそのまま当てただけ
NON_MATCH void Boku_OnHurt(HitboxData* a, HitboxData* b, Boku* p) {
#ifdef NONMATCHING_C
  u32 knockback;
  u8 angle;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if ((p->e).hurtbox.invincibleTime != 0) {
    if ((p->e).unk_48c != 0) {
      b->damage = 0;
      b->hitResult = 0;
    }
    return;
  }
  if ((p->e).hurtbox.flags & HBFLAG_HIDDEN) {
    return;
  }

  if (!(a->flags & HBFLAG_UNK_0)) {
    if (!(a->weakness & 0x4000)) {
      return;
    }
    if ((p->e).flags3 & (ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
      return;
    }
    if ((p->e).unk_488 != 0) {
      return;
    }
    (p->e).unk_488 = 60;
    if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_27) && (b->flags & HBFLAG_ANGLE) && (a->flags & HBFLAG_ANGLE)) {
      s32 d = b->angle - a->angle;

      if (d < 0) {
        d = -d;
      }
      if (d <= 32) {
        (p->e).unk_4be = a->power;
        (p->e).unk_48c = 1;
        (p->e).unk_44e = Div((p->e).unk_4be, 3);
        SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_13);
        return;
      }
    }
    b->damage = 0;
    (p->e).unk_48a = 0;
    {
      bool8 found = FALSE;
      u16 mask = a->ignoreMask;

      if (mask & HIM_0) {
        (p->e).playerMover = &gPlayerPtr[0]->mover;
        found = TRUE;
      } else if (mask & HIM_1) {
        (p->e).playerMover = &gPlayerPtr[1]->mover;
        found = TRUE;
      } else if (mask & HIM_2) {
        (p->e).playerMover = &gPlayerPtr[2]->mover;
        found = TRUE;
      } else if (mask & HIM_3) {
        (p->e).playerMover = &gPlayerPtr[3]->mover;
        found = TRUE;
      } else if (mask & HIM_4) {
        (p->e).playerMover = NULL;
        found = TRUE;
      } else if (mask & HIM_5) {
        found = TRUE;
      }
      (p->e).unk_4a0 = mask;
      (p->e).weaponExpMask = a->weakness;
      (p->e).flags6 = a->attributes;
      if (found) {
        if ((p->e).flags5 & ENEFLAG5_UNK_1) {
          (p->e).playerMover = &gPlayerPtr[0]->mover;
        }
        if ((p->e).playerMover != NULL) {
          s32 dx = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
          s32 dz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

          (p->e).unk_1fc = ArcTan2_8(dx, dz);
          (p->e).unk_1e4 = dx * dx + dz * dz;
        }
      }
    }
    if ((p->e).flags3 & ENEFLAG3_UNK_7) {
      (p->e).unk_24e += 300;
      if ((p->e).unk_24e > (p->e).unk_24c) {
        (p->e).unk_24e = (p->e).unk_24c;
      }
    }
    (p->e).unk_48c = 1;
    return;
  }

  if (!IsLinkPlay()) {
    Hitbox_ApplyDamage(a, b);
  } else {
    Hitbox_ApplyDamageAlt(a, b);
  }
  b->invincibleTime = a->invincibleTime;
  (p->e).unk_48c = b->hitResult;
  if ((p->e).kind == ENEK_BAT || (p->e).kind == ENEK_CROW || (p->e).kind == ENEK_BEE || (p->e).kind == ENEK_GHOST || (a->attributes & HBATTR_18)) {
    knockback = a->knockbackPower;
  } else {
    knockback = a->knockbackPower - (p->e).unk_187;
    if ((s32)knockback < 0) {
      knockback = 0;
    }
  }
  b->knockbackPower = knockback;
  if ((p->e).flags3 & (ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2)) {
    b->damage <<= 1;
    b->knockbackPower >>= 1;
  }
  if (!(a->flags & HBFLAG_ANGLE)) {
    s16 dx = b->pos.x - a->pos.x;
    s16 dz = b->pos.z - a->pos.z;

    if (dx == 0 && dz == 0) {
      angle = Random();
    } else {
      angle = ArcTan2_8(dx, dz);
    }
  } else {
    angle = a->angle;
  }
  (p->e).angle = angle;
  {
    bool8 found = FALSE;
    u16 mask = a->ignoreMask;

    if (mask & HIM_0) {
      (p->e).playerMover = &gPlayerPtr[0]->mover;
      found = TRUE;
    } else if (mask & HIM_1) {
      (p->e).playerMover = &gPlayerPtr[1]->mover;
      found = TRUE;
    } else if (mask & HIM_2) {
      (p->e).playerMover = &gPlayerPtr[2]->mover;
      found = TRUE;
    } else if (mask & HIM_3) {
      (p->e).playerMover = &gPlayerPtr[3]->mover;
      found = TRUE;
    } else if (mask & HIM_4) {
      (p->e).playerMover = NULL;
      found = TRUE;
    } else if (mask & HIM_5) {
      found = TRUE;
    }
    (p->e).unk_4a0 = mask;
    (p->e).weaponExpMask = a->weakness;
    (p->e).flags6 = a->attributes;
    if (found) {
      if ((p->e).flags5 & ENEFLAG5_UNK_1) {
        (p->e).playerMover = &gPlayerPtr[0]->mover;
      }
      if ((p->e).playerMover != NULL) {
        s32 dx = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
        s32 dz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

        (p->e).unk_1fc = ArcTan2_8(dx, dz);
        (p->e).unk_1e4 = dx * dx + dz * dz;
      }
    }
  }
  if ((p->e).unk_48c != 0 && ((p->e).flags3 & ENEFLAG3_UNK_7)) {
    (p->e).unk_24e += 300;
    if ((p->e).unk_24e > (p->e).unk_24c) {
      (p->e).unk_24e = (p->e).unk_24c;
    }
  }
  if (gStat->mapFlags & MPF_UNK_10) {
    b->damage = 0;
    b->knockbackPower = 0;
    (p->e).unk_48a = 0;
    (p->e).unk_48c = 1;
  }
  FUN_080e64e4(&p->e);
  (p->e).unk_48a = b->damage;
  a->damage += (p->e).unk_188;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
#else
  INCFUNC("asm/func/Boku_OnHurt.inc");
#endif
}

// 568/597命令の下書き, Ghidra の出力から起こしたもの, stateBegun を 0/1 に落としてから見る形 (inline らしい) とタイル探索のループの形が未調整
NON_MATCH void FUN_080fb4d0(Boku* p) {
#ifdef NONMATCHING_C
  Boku* self = p->e.unk_1cc;
  EnemySpriteData* spr = p->e.sprite;

  if (p->e.stateBegun) {
    p->e.stateBegun = FALSE;
    p->e.mover.angle = (((p->e.unk_1fc + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 5);
    if (self->unk_65c & 4) {
      spr->s.boxLeft = 2;
      spr->s.rotation = 0;
      self->unk_65c &= ~4;
    }
    if (!(gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14))) {
      self->unk_660 = p->e.playerMover->pos;
    } else if (p->e.playerMover != NULL) {
      s32 idx = p->e.playerMover->unk_4 < 4 ? p->e.playerMover->unk_4 : -1;

      if (idx >= 0) {
        self->unk_660 = gPlayerPtr[idx]->mover.pos;
      }
    }
  }
  if (spr->s.boxLeft == 5 && spr->s.rotation == 0) {
    s32 d = p->e.unk_1fc - (((p->e.mover.angle + 0x20) & 0xFF) >> 6) * 64;
    Vec3 from;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (d < 0) {
      d = -d;
    }
    if (d < 32) {
      if (!(gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14))) {
        self->unk_668 = p->e.playerMover->pos;
      } else if (p->e.playerMover != NULL) {
        s32 idx = p->e.playerMover->unk_4 < 4 ? p->e.playerMover->unk_4 : -1;

        if (idx >= 0) {
          self->unk_668 = gPlayerPtr[idx]->mover.pos;
        }
      }
    } else {
      u32 tileIdx = p->e.unk_256;
      u32 target;
      s32 height;
      s32 fromStairs;
      s32 idx;
      s32 n;

      {
        MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
        CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
        s32 stairs = tile->heightStairs >> 4;

        height = (tile->heightStairs & 0xF) << 8;
        if (stairs == STAIRS_VERTICAL) {
          height -= p->e.mover.pos.z & 0xFF;
        } else if (stairs == STAIRS_HORIZONTAL) {
          height -= p->e.mover.pos.x & 0xFF;
        }
      }
      {
        MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
        CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];

        fromStairs = tile->heightStairs >> 4;
      }
      switch (((p->e.mover.angle + 0x20) >> 6) & 3) {
        case 0: {
          idx = tileIdx + 1;
          for (n = 0; n < 1; n++) {
            if (!FUN_080e8038(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx++;
          }
          target = idx - 1;
          break;
        }
        case 1: {
          idx = tileIdx + gCollisionMap->tiledata->width;
          for (n = 0; n < 1; n++) {
            if (!FUN_080e8038(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx += gCollisionMap->tiledata->width;
          }
          target = idx - gCollisionMap->tiledata->width;
          break;
        }
        case 2: {
          idx = tileIdx - 1;
          for (n = 0; n < 1; n++) {
            if (!FUN_080e8038(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx--;
          }
          target = idx + 1;
          break;
        }
        case 3: {
          idx = tileIdx - gCollisionMap->tiledata->width;
          for (n = 0; n < 1; n++) {
            if (!FUN_080e8038(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx -= gCollisionMap->tiledata->width;
          }
          target = idx + gCollisionMap->tiledata->width;
          break;
        }
        default: {
          target = p->e.unk_256;
          break;
        }
      }
      self->unk_668.x = Mod(target, gCollisionMap->tiledata->width) * 256 + 128;
      {
        MapTileOverride* ov = Map_FindTileOverride(target, 1);
        CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[target];

        self->unk_668.y = (tile->heightStairs & 0xF) << 8;
      }
      self->unk_668.z = Div(target, gCollisionMap->tiledata->width) * 256 + 128;
      switch (((p->e.mover.angle + 0x20) >> 6) & 3) {
        case 0: {
          self->unk_668.x += 0x7F;
          self->unk_668.z = p->e.mover.pos.z;
          break;
        }
        case 1: {
          self->unk_668.x = p->e.mover.pos.x;
          self->unk_668.z += 0x7F;
          break;
        }
        case 2: {
          self->unk_668.x -= 0x7F;
          self->unk_668.z = p->e.mover.pos.z;
          break;
        }
        case 3: {
          self->unk_668.x = p->e.mover.pos.x;
          self->unk_668.z -= 0x7F;
          break;
        }
      }
      self->unk_668.y = TileHeightAt(&self->unk_668);
    }
    from = p->e.mover.pos;
    from.y += 220;
    Entity081f3324_Spawn(&from, &self->unk_668, p->e.atkPower[1], p->e.atkUnk40[1], p->e.atkAttrs[1], p->e.atkInvincibleTime[1], self->unk_674, 30, -20);
    PlaySound_082406e0(SONG_214);
  }
  if (p->e.animForceRestart) {
    p->e.subStateDone = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_080fb4d0.inc");
#endif
}

void FUN_080fba28(Boku* p) {
  if ((p->e).stateBegun != 0) {
    (p->e).stateBegun = 0;
  }
}

void FUN_080fba40(Boku* p) {
  if ((p->e).stateBegun != 0) {
    (p->e).stateBegun = 0;
  }
  Enemy_PlayAnim(&p->e, 0);
}

// 765/688命令の下書き, Ghidra から起こしたもの, 振り向きアニメの再生は向きごとに展開して書いたが原典は末尾を共有して短い, p を r8 と r5 に二重に持つ形も未調整
NON_MATCH void FUN_080fba64(Boku* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 dir;
    u32 target;

    (p->e).mover.angle = ((((((p->e).mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3) * 64 - 64;
    dir = (((((p->e).mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3;
    if ((p->e).subState2 == 6 || (p->e).subState2 == 17 || TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_14)) {
      target = (p->e).unk_1dc;
    } else {
      target = (p->e).pathWalker.node->delay >> 12;
      (p->e).unk_1dc = target;
    }
    if (dir == target >> 1) {
      (p->e).subStateDone = 1;
      Enemy_PlayAnim(&p->e, 0);
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
        Enemy_ResetState(&p->e, 3, 1, 0);
        Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
      }
      return;
    }
    // 今の向きと目標の向きから回る向きを決めて振り向きアニメを流す
    switch (dir) {
      case 0: {
        if (target - 2 < 4) {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 1, 0);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            if ((p->e).playingAnim != 10 || (p->e).animForceRestart != 0 || (s->flags & SPRFLAG_XFLIP)) {
              (p->e).playingAnim = 10;
              MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 10, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
              s->flags &= ~SPRFLAG_XFLIP;
              (p->e).animForceRestart = 0;
            }
          }
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 0, ANIM_PLAY_REVERSE);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            (p->e).playingAnim = 9;
            MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 9, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
            s->flags &= ~SPRFLAG_XFLIP;
            (p->e).animForceRestart = 0;
          }
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 1: {
        if (target - 4 < 4) {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 2, 0);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            if ((p->e).playingAnim != 11 || (p->e).animForceRestart != 0 || (s->flags & SPRFLAG_XFLIP)) {
              (p->e).playingAnim = 11;
              MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 11, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
              s->flags &= ~SPRFLAG_XFLIP;
              (p->e).animForceRestart = 0;
            }
          }
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 1, ANIM_PLAY_REVERSE);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            (p->e).playingAnim = 10;
            MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 10, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
            s->flags &= ~SPRFLAG_XFLIP;
            (p->e).animForceRestart = 0;
          }
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 2: {
        if (target - 1 < 5) {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 2, ANIM_PLAY_REVERSE);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            (p->e).playingAnim = 11;
            MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 11, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
            s->flags &= ~SPRFLAG_XFLIP;
            (p->e).animForceRestart = 0;
          }
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 1, ANIM_PLAY_REVERSE | ANIM_PLAY_XFLIP);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            (p->e).playingAnim = 10;
            MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 10, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
            s->flags |= SPRFLAG_XFLIP;
            (p->e).animForceRestart = 0;
          }
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 3: {
        if (target < 4) {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 0, 0);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            if ((p->e).playingAnim != 9 || (p->e).animForceRestart != 0 || (s->flags & SPRFLAG_XFLIP)) {
              (p->e).playingAnim = 9;
              MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 9, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
              s->flags &= ~SPRFLAG_XFLIP;
              (p->e).animForceRestart = 0;
            }
          }
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

            (p->e).playingAnim = 9;
            AuxAnim_SetAnim(&s->anim, s->animFile, 9, 1, ANIM_PLAY_XFLIP);
            (p->e).animForceRestart = 0;
          } else {
            MainSprite* s = &(p->e).sprite->s;

            if ((p->e).playingAnim != 10 || (p->e).animForceRestart != 0 || !(s->flags & SPRFLAG_XFLIP)) {
              (p->e).playingAnim = 10;
              MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, 10, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
              s->flags |= SPRFLAG_XFLIP;
              (p->e).animForceRestart = 0;
            }
          }
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
    }
    (p->e).animForceRestart = 0;
  }
  anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
  if (anim->tick == 0 && (anim->cmdIdx == 1 || anim->cmdIdx == 3)) {
    u32 targetAngle = (((p->e).unk_1dc + 5) & 7) << 5;
    u8 angle = (p->e).mover.angle;
    s32 d = angle - targetAngle;

    if (d < 0) {
      d = -d;
    }
    if (d <= 32) {
      (p->e).mover.angle = targetAngle;
    } else if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      (p->e).mover.angle = angle + 32;
    } else {
      (p->e).mover.angle = angle - 32;
    }
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).animForceRestart) {
    s32 d = (p->e).unk_1dc - ((((((p->e).mover.angle + 0x10) & 0xFF) >> 5) + 3) & 7);

    if (d < 0) {
      d = -d;
    }
    if (d > 0) {
      Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
      return;
    }
    (p->e).subStateDone = 1;
    (p->e).mover.angle = ((((((p->e).mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3) * 64 - 64;
    Enemy_PlayAnim(&p->e, 0);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
    }
  }
#else
  INCFUNC("asm/func/FUN_080fba64.inc");
#endif
}

void FUN_080fc0b8(Boku* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 8);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      (p->e).flags3 |= ENEFLAG3_UNK_0;
    }
  }
  if (Mod(param_2, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, FUN_080fc174, ES_UNK_6);
  }
}

void FUN_080fc174(Boku* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_0);
  }

  if (param_2 == 40) {
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  }

  if ((p->e).animForceRestart != 0 && param_2 > 120) {
    (p->e).subStateDone = 1;
  }
}

void FUN_080fc1e4(Boku* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (param_2 > 26) {
    Enemy_PlayAnim(&p->e, 9);
    Enemy_EnterState(&p->e, FUN_080fc28c, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

void FUN_080fc28c(Boku* p) {
  AuxAnimState* anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.invincibleTime = 60;
  }
  anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
  if (anim->cmdIdx == 3 && anim->tick == 4) {
    PlaySound_082406e0(NOISE_UNK_128 | NOISE_HEARTBEAT);
  }
  if ((p->e).animForceRestart) {
    FUN_080ffad8(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

// 残差1命令, 最後の tick = 0 を原典は sprite + 0x48 を作ってから [+0xE] で書く (mimic.c の FUN_081475b8 と同じ), anim の取り直しは試済
NON_MATCH void FUN_080fc4ec(Boku* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
  }
  anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
  if (anim->cmdIdx == 7 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->cmdIdx = 2;
    ((EnemyAuxSpriteData*)(p->e).sprite)->anim.tick = 0;
  }
#else
  INCFUNC("asm/func/FUN_080fc4ec.inc");
#endif
}

void FUN_080fc548(Boku* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 12);
    (p->e).animForceRestart = 0;
  }
  if (param_2 > 60) {
    if ((p->e).animForceRestart) {
      (p->e).subStateDone = 1;
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
        Enemy_PlayAnim(&p->e, 0);
        Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
        SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      } else {
        Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
        Enemy_PlayAnim(&p->e, 0);
        Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
        Enemy_ResetState(&p->e, 0, 0, 7);
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      }
    }
  } else {
    AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

    if (anim->cmdIdx == 2 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
      anim->tick = 0;
    }
  }
}

// 1074/1056命令の下書き, 後半は FUN_080fe7f4 と同じ形, 原典は &flags4 を r5 に持ち越し状態フィールドのアドレスをスタックに作り置く (フレーム 0x8C, こちらは 0x70)
NON_MATCH void FUN_080fc6f4(Boku* p, s32 param_2) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 3);
  }
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  if (param_2 < 18) {
    AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
    if (anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
      anim->tick = 0;
    }
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, (p->e).unk_594, ES_SLEEP);
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    s32 tile;
    s32 idx;

    Enemy_PlayAnim(&p->e, 0);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, FUN_080e6794, ES_UNK_14);
    (p->e).unk_554 = 30;
    (p->e).unk_558 = (p->e).unk_5b8;
    (p->e).unk_550 = 0;
    (p->e).unk_551 = 0;
    (p->e).unk_552 = 12;
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }

    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        (p->e).unk_5c4(&p->e);
        return;
      }
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }

    // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
    if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      u8 angle;

      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
        return;
      }
      (p->e).unk_222 &= ~ENEMY222_UNK_2;
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
      } else {
        Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
        Enemy_ResetState(&p->e, 0, 0, 5);
        {
          Vec3* dst = (p->e).unk_4a8;
          PathWalker* walker = &(p->e).pathWalker;

          dst->x = walker->node->x;
          dst->z = walker->node->y;
          dst->y = TileHeightAt(dst);
        }
        (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
        (p->e).unk_4a8->val = 0;
      }
      angle = (p->e).mover.angle;
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
        s32 i;
        u32 a;

        for (i = 0; i < 4; i++) {
          a = (Random() & 3) << 6;
          if (a != angle) {
            break;
          }
        }
        if (i >= 4) {
          a = angle;
        }
        (p->e).unk_540 = a;
        (p->e).unk_548 = (p->e).handlerState;
        (p->e).unk_54f = (p->e).state;
        (p->e).unk_54c = (p->e).subState0;
        (p->e).unk_54d = (p->e).subState1;
        (p->e).unk_54e = (p->e).subState2;
        (p->e).unk_541 = angle;
        Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
        Enemy_ResetState(&p->e, 3, 1, 0);
        (p->e).unk_542 = 6;
      }
      FUN_080e7b6c(&p->e);
      (p->e).animSpeedDiv = 2;
      return;
    }

    {
      WorldPos tilePos;
      bool8 moved = FALSE;

      {
        s32 x = Mod(tile, gCollisionMap->tiledata->width);
        s32 z = Div(tile, gCollisionMap->tiledata->width);
        MapTileOverride* ov;

        tilePos.x = (x << 8) + 0x80;
        ov = Map_FindTileOverride(tile, 1);
        tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
        tilePos.z = (z << 8) + 0x80;
      }
      {
        NavAgent* agent = (p->e).navAgent;
        WorldPos* pos = &(p->e).mover.pos;

        if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
          s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

          if (result != 0) {
            if (result != 2) {
              ClearMemory(&(p->e).mover.delta, 8);
            }
            moved = TRUE;
          }
        }
        if (!moved) {
          CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
        }
      }
      if (!moved) {
        (p->e).unk_5c4(&p->e);
      }
    }
    return;
  }

  Enemy_PlayAnim(&p->e, 0);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, FUN_080e6794, ES_UNK_14);
  (p->e).unk_554 = 60;
  (p->e).unk_558 = (p->e).unk_5a0;
  (p->e).unk_550 = 0;
  (p->e).unk_551 = 0;
  (p->e).unk_552 = 7;
  (p->e).animSpeedDiv = 1;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  {
    Vec3* dst = (p->e).unk_4a8;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  {
    NavAgent* agent = (p->e).navAgent;
    WorldPos* pos = &(p->e).mover.pos;
    Vec3* dst = (p->e).unk_4a8;
    bool8 moved = FALSE;

    if (Map_IsPosInAgentIsland(agent, pos, dst)) {
      s32 result = Map_TryFindNavRoute(agent, pos, dst);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&(p->e).mover.delta, 8);
        }
        moved = TRUE;
      }
    }
    if (!moved) {
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    }
    if (moved) {
      (p->e).unk_4a8->val = 1;
    } else {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_080fc6f4.inc");
#endif
}

// 1893/1886命令の下書き, プレイヤーへ向かう部分は FUN_080fe7f4 と同じ形を2回展開, 原典は &flags を sb に持ち越し状態フィールドのアドレスをスタックに作り置く (フレーム 0xD0, こちらは 0xAC)
NON_MATCH void FUN_080fd08c(Boku* p, s32 param_2) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
  s32 dx;
  s32 dz;
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 3);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      PlaySound_082406e0(CRY_BOKU_DAMAGED);
      PlaySound_082406e0(SE_UNK_298);
    }
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    (p->e).animForceRestart = 0;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (param_2 < 18 && anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
  if (Mod(param_2, 12) == 0 && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
    Vec3 size;

    VEC3_SET(size, 60, 60, 40);
    EmitSmoke(&(p->e).mover.pos, (Random() & 3) + 1, &size, (p->e).mover.angle + 128, 10, 6, 2, 2);
  }

  // 吹き飛ばされた先の点へ残りの 1/4 ずつ寄せる, 1フレームに 200 まで
  dx = (p->e).unk_20c.x - (p->e).unk_214.x;
  if (dx < 0) {
    dx = -(-dx >> 2);
  } else {
    dx = dx >> 2;
  }
  dz = (p->e).unk_20c.z - (p->e).unk_214.z;
  if (dz < 0) {
    dz = -(-dz >> 2);
  } else {
    dz = dz >> 2;
  }
  if (dx > 200) {
    dx = 200;
  } else if (dx < -200) {
    dx = -200;
  }
  if (dz > 200) {
    dz = 200;
  } else if (dz < -200) {
    dz = -200;
  }
  (p->e).mover.delta.x += dx;
  (p->e).mover.delta.z += dz;
  (p->e).unk_214.x += dx;
  (p->e).unk_214.z += dz;
  if (dx != 0 || dz != 0) {
    return;
  }
  if (!(p->e).animForceRestart) {
    return;
  }

  (p->e).subStateDone = 1;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_19)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_1);
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, FUN_080fc6f4, ES_UNK_20);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_3);
    (p->e).animSpeedDiv = 1;
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).unk_4a8;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
            (p->e).unk_4a8->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).unk_540 = a;
            (p->e).unk_548 = (p->e).handlerState;
            (p->e).unk_54f = (p->e).state;
            (p->e).unk_54c = (p->e).subState0;
            (p->e).unk_54d = (p->e).subState1;
            (p->e).unk_54e = (p->e).subState2;
            (p->e).unk_541 = angle;
            Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          FUN_080e7b6c(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).unk_5c4(&p->e);
    }
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      (p->e).unk_5c4(&p->e);
    }
  } else {
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).unk_4a8->val = 0;
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).unk_4a8;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
            (p->e).unk_4a8->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).unk_540 = a;
            (p->e).unk_548 = (p->e).handlerState;
            (p->e).unk_54f = (p->e).state;
            (p->e).unk_54c = (p->e).subState0;
            (p->e).unk_54d = (p->e).subState1;
            (p->e).unk_54e = (p->e).subState2;
            (p->e).unk_541 = angle;
            Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          FUN_080e7b6c(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).unk_5c4(&p->e);
    }
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 2;
    } else {
      (p->e).unk_5c4(&p->e);
    }
  }
#else
  INCFUNC("asm/func/FUN_080fd08c.inc");
#endif
}

// unk_65c の bit1 の判定を bool8 を返す inline にすると 76/75 命令まで寄るが, 原典は &unk_65c を判定の中で作って r5 に持ち越し, q を r1 に置く, 1回目は r4/r5 が逆
NON_MATCH void FUN_080fe1bc(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;

  if (!Enemy_ConsumeStateBegun(&p->e)) {
    if (q->unk_65c & 2) {
      if ((p->e).unk_1e4 > 0xFFFF) {
        Enemy_PlayAnim(&p->e, 0);
      }
      FUN_080ffda8(p);
      CLEAR_FLAGS(q->unk_65c, 2);
      Enemy_ResetState(&p->e, 0, 0, 15);
    } else {
      Enemy_PlayAnim(&p->e, 1);
    }
  }
#else
  INCFUNC("asm/func/FUN_080fe1bc.inc");
#endif
}

// 514/514命令, 残差は最初の EmitSmoke の乱数の位置と, 原典のフレームが 4 バイト大きい (0x50) ことだけ
NON_MATCH void FUN_080fe274(Boku* p, s32 param_2) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = (AuxSprite*)(p->e).sprite;
  AuxAnimState* anim = &((EnemyAuxSpriteData*)sprite)->anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = 0;
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    FUN_080e64b4(&p->e, 4);
    sprite->flags |= SPRFLAG_AFFINE;
    PlayEnemyDeathCry(&p->e);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      PlaySound_082406e0(SE_UNK_298);
    }
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  }
  FUN_080e499c(&p->e);
  if (Mod(param_2, 12) == 0 && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
    Vec3 size;

    VEC3_SET(size, 60, 60, 40);
    EmitSmoke(&(p->e).mover.pos, (Random() & 3) + 1, &size, (p->e).mover.angle + 128, 10, 8, 2, 2);
  }
  if (param_2 < 35) {
    anim->tick = 0;
  }
  if (anim->cmdIdx < 3) {
    sprite->scaleX = 70;
    sprite->scaleY = 70;
  } else {
    sprite->scaleX = Q6(1);
    sprite->scaleY = Q6(1);
  }
  if ((p->e).animForceRestart) {
    s32 idx;

    (p->e).subStateDone = 1;
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      Vec3 size;
      WorldPos* pos;
      u8 kind;

      FUN_080e6658(&p->e);
      VEC3_SET(size, 80, 60, 60);
      pos = &(p->e).mover.pos;
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x40, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x80, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0xF0, 4, 20, 2, 1);
      kind = (p->e).kind;
      if (kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DARKROOT) {
        PlaySound_082406e0(SE_UNDEAD_EXORCISM);
      }
    }
    if ((p->e).unk_19a != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).unk_19a, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    (p->e).unk_192 = 0;
    sprite->scaleX = Q6(1);
    sprite->scaleY = Q6(1);
    sprite->flags = (sprite->flags & ~SPRFLAG_AFFINE) | SPRFLAG_HIDDEN;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
#else
  INCFUNC("asm/func/FUN_080fe274.inc");
#endif
}

// 97/99命令, 原典は FUN_080e6750 の後に kind のアドレスを作り直す, 1回目の下書きで切り上げ
NON_MATCH void FUN_080fe704(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_080f3cdc, ES_UNK_10);
    (p->e).mover.angle = (p->e).unk_1fc;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    FUN_080e6750(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
  }
  if ((p->e).subStateDone) {
    FUN_080ff67c(p);
    SET_FLAGS(q->unk_65c, 4);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_080fe704.inc");
#endif
}

// 938/932命令の下書き, enedefault.c の FUN_080f12c4 と同じ形, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x60, こちらは 0x30)
NON_MATCH void FUN_080fe7f4(Boku* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer <= 60) {
    (p->e).subStateTimer++;
    return;
  }

  Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, FUN_080e6794, ES_UNK_14);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    bool8 moved;

    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_4)) {
      (p->e).unk_554 = 30;
      (p->e).unk_558 = (p->e).unk_5a0;
      (p->e).unk_550 = 0;
      (p->e).unk_551 = 0;
      (p->e).unk_552 = 2;
      (p->e).animSpeedDiv = 1;
      return;
    }
    (p->e).unk_554 = 30;
    (p->e).unk_558 = (p->e).unk_5a0;
    (p->e).unk_550 = 0;
    (p->e).unk_551 = 0;
    (p->e).unk_552 = 7;
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      Vec3* dst = (p->e).unk_4a8;

      moved = FALSE;
      if (Map_IsPosInAgentIsland(agent, pos, dst)) {
        s32 result = Map_TryFindNavRoute(agent, pos, dst);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    } else {
      (p->e).unk_4a8->val = 1;
    }
    return;
  }

  (p->e).unk_554 = 30;
  (p->e).unk_558 = (p->e).unk_5b8;
  (p->e).unk_550 = 0;
  (p->e).unk_551 = 0;
  (p->e).unk_552 = 12;
  {
    Vec3* dst = (p->e).unk_4a8;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }

  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->unk_4 <= 3) {
      idx = m->unk_4;
    }
    if (m == NULL || idx < 0) {
      (p->e).unk_5c4(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }

  // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
  if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    u8 angle;

    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return;
    }
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 5);
      {
        Vec3* dst = (p->e).unk_4a8;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
      (p->e).unk_4a8->val = 0;
    }
    angle = (p->e).mover.angle;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i < 4; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i >= 4) {
        a = angle;
      }
      (p->e).unk_540 = a;
      (p->e).unk_548 = (p->e).handlerState;
      (p->e).unk_54f = (p->e).state;
      (p->e).unk_54c = (p->e).subState0;
      (p->e).unk_54d = (p->e).subState1;
      (p->e).unk_54e = (p->e).subState2;
      (p->e).unk_541 = angle;
      Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
      Enemy_ResetState(&p->e, 3, 1, 0);
      (p->e).unk_542 = 6;
    }
    FUN_080e7b6c(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }

  {
    WorldPos tilePos;
    bool8 moved = FALSE;

    {
      s32 x = Mod(tile, gCollisionMap->tiledata->width);
      s32 z = Div(tile, gCollisionMap->tiledata->width);
      MapTileOverride* ov;

      tilePos.x = (x << 8) + 0x80;
      ov = Map_FindTileOverride(tile, 1);
      tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
      tilePos.z = (z << 8) + 0x80;
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;

      if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
        s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      (p->e).unk_5c4(&p->e);
    }
  }
#else
  INCFUNC("asm/func/FUN_080fe7f4.inc");
#endif
}

void FUN_080ff05c(Boku* p) {
  static void (*const PTR_ARRAY_085ad488[2])(Boku*) = {
      FUN_080fe704,
      FUN_080fe7f4,
  };  // 0x085AD488
  (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad488;
}

void FUN_080ff06c(Boku* p) {
  Boku* q = (p->e).unk_1cc;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_080fe1bc, ES_UNK_35);
  }
  if (q->timer_670 == 0) {
    if ((p->e).unk_608(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
    if (FUN_080f0a0c(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
  }
  speed = (p->e).unk_588(&p->e);
  (p->e).animSpeedDiv = 6;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (FUN_080e5ed4(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 3, 0, 0);
      SET_FLAGS(q->unk_65c, 2);
      return;
    }
  } else {
    if (FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 16);
    }
  }
  (p->e).subStateTimer++;
}

void FUN_080ff270(Boku* p) {
  Boku* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  }
  if (q->timer_670 == 0) {
    if ((p->e).unk_608(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
    if (FUN_080f0a0c(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 15);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_080ff36c(Boku* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  }
  if (!(p->e).unk_608(&p->e) && !FUN_080f0a0c(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 5);
      Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void FUN_080ff45c(Boku* p) {
  // 先頭15要素は gEnemyHandlerTable2 と同じ中身
  static void (*const PTR_ARRAY_085ad490[18])(Boku*) = {
      (void*)FUN_080f2644,
      (void*)FUN_080f2864,
      (void*)FUN_080f248c,
      (void*)FUN_080f2364,
      NULL,
      (void*)FUN_080f2ec0,
      (void*)FUN_080f2d04,
      (void*)FUN_080f2a40,
      (void*)FUN_080f31c4,
      (void*)FUN_080f19cc,
      (void*)FUN_080f33e8,
      (void*)FUN_080f34a0,
      (void*)FUN_080f0e78,
      (void*)FUN_080f11d0,
      (void*)FUN_080f12c4,
      FUN_080ff06c,
      FUN_080ff270,
      FUN_080ff36c,
  };  // 0x085AD490
  (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad490;
}

// 198/208命令, 原典は経路を引けたかを 0/1 に落としてから unk_5c4 を呼ぶ (経路の inline の戻り値らしい) が, 引けなかったときの &flags3 は外側の r8 を使う, inline にすると r8 の持ち越しが消える
NON_MATCH void FUN_080ff470(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, FUN_080fb4d0, ES_UNK_34);
    q->timer_670 = q->unk_672;
  }
  if ((p->e).subStateDone) {
    EnemyFlags3* flags3 = &(p->e).flags3;
    NavAgent* agent;
    WorldPos* pos;
    s32 result;

    CLEAR_FLAGS(*flags3, ENEFLAG3_UNK_8);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
    Enemy_PlayAnim(&p->e, 0);
    (p->e).unk_554 = q->unk_67e;
    (p->e).unk_558 = (p->e).unk_5b8;
    (p->e).unk_550 = 0;
    (p->e).unk_551 = 0;
    (p->e).unk_552 = 12;
    Enemy_EnterState(&p->e, FUN_080e6794, ES_UNK_14);
    Enemy_ResetState(&p->e, 3, 0, 0);
    agent = (p->e).navAgent;
    pos = &(p->e).mover.pos;
    if (Map_IsPosInAgentIsland(agent, pos, &q->unk_660) && (result = Map_TryFindNavRoute(agent, pos, &q->unk_660)) != 0) {
      if (result != 2) {
        ClearMemory(&(p->e).mover.delta, 8);
      }
    } else {
      CLEAR_FLAGS(*flags3, ENEFLAG3_UNK_9);
      (p->e).unk_5c4(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_080ff470.inc");
#endif
}

void FUN_080ff668(Boku* p) {
  static void (*const PTR_ARRAY_085ad4d8[1])(Boku*) = {
      FUN_080ff470,
  };  // 0x085AD4D8
  (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad4d8;
}

void FUN_080ff67c(Boku* p) {
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 0, 2, 0);
}

void FUN_080ff6e8(Boku* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      return;
    }
    FUN_080ff67c(p);
  } else {
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
}

// 263/276命令, 経路の判定を bool8 の inline にしても同じ, 原典は &flags3 を r6 に持ち越す, 1回目の下書きで切り上げ
NON_MATCH void FUN_080ff7c0(Boku* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, FUN_080e6794, ES_UNK_14);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 2;
    (p->e).unk_554 = 60;
    (p->e).unk_558 = (p->e).unk_5a0;
    (p->e).unk_550 = 0;
    (p->e).unk_551 = 0;
    (p->e).unk_552 = 7;
  } else {
    (p->e).animSpeedDiv = 2;
    (p->e).unk_554 = 30;
    (p->e).unk_558 = (p->e).unk_5b8;
    (p->e).unk_550 = 0;
    (p->e).unk_551 = 0;
    (p->e).unk_552 = 12;
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      (p->e).unk_24e += 300;
      if ((p->e).unk_24e > (p->e).unk_24c) {
        (p->e).unk_24e = (p->e).unk_24c;
      }
    }
  }
  {
    Vec3* dst = (p->e).unk_4a8;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  (p->e).unk_4a8->val = 0;
  {
    NavAgent* agent = (p->e).navAgent;
    WorldPos* pos = &(p->e).mover.pos;
    WorldPos* dst = &(p->e).playerMover->pos;
    s32 result;

    if (Map_IsPosInAgentIsland(agent, pos, dst) && (result = Map_TryFindNavRoute(agent, pos, dst)) != 0) {
      if (result != 2) {
        ClearMemory(&(p->e).mover.delta, 8);
      }
    } else {
      Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
      (p->e).unk_5c4(&p->e);
    }
  }
#else
  INCFUNC("asm/func/FUN_080ff7c0.inc");
#endif
}

void Boku_InitHitboxes(Boku* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Boku_OnHurt, p);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Boku_OnHit, 0, p);
}

// 状態を初期化して待機アニメ 0 に戻し, 1コマ進める
// 残差1命令 (152/153), 原典は p->sprite を r0 に読んでから r5 へ移すが, こちらは r5 へ直接読む, 手動送りは AuxSprite_AdvanceAnim で一致
// aux のローカル化, 引数に直接書く形, 敵用の送り inline を挟む形は試済
NON_MATCH void FUN_080ffad8(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->unk_65e = 0;
  q->unk_65c = 0;
  q->timer_670 = 0;
  q->unk_67c = 0;
  ClearMemory((p->e).unk_4a8, sizeof(Vec3));
  ClearMemory(&q->unk_668, sizeof(Vec3));
  ClearMemory(&q->unk_660, sizeof(Vec3));
  Enemy_ClearPendingState(&p->e, s_bokucom_c_08251fc0, 147);
  FUN_080e6204(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
#else
  INCFUNC("asm/func/FUN_080ffad8.inc");
#endif
}

void FUN_080ffc28(void) {}

void Boku_InitAnims(Boku* p) {
  Enemy_SetAnimEntry(&p->e, 0, 7, 0);
  Enemy_SetAnimEntry(&p->e, 1, 8, 0);
  Enemy_SetAnimEntry(&p->e, 2, 9, 0);
  Enemy_SetAnimEntry(&p->e, 3, 2, 0);
  Enemy_SetAnimEntry(&p->e, 5, 10, 0);
  Enemy_SetAnimEntry(&p->e, 6, 5, 0);
  Enemy_SetAnimEntry(&p->e, 7, 6, 0);
  Enemy_SetAnimEntry(&p->e, 8, 5, 0);
  Enemy_SetAnimEntry(&p->e, 9, 6, 0);
  Enemy_SetAnimEntry(&p->e, 10, 4, 0);
  Enemy_SetAnimEntry(&p->e, 12, 1, 0);
  Enemy_SetAnimEntry(&p->e, 4, 3, 0);
  Enemy_SetAnimEntry(&p->e, 11, 0, 0);
}

const u16 u16_ARRAY_085ad4dc[4] = {336, 336, 0, 180};  // 0x085AD4DC

// 37/39命令, 原典は anim のポインタを r3 と r4 の2本に持ち, 10〜13 の側は r4 から cmdIdx を読み直す, 判定順の入れ替えは試済
NON_MATCH s32 FUN_080ffcd0(Boku* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if (anim->cmdIdx <= 3) {
      return u16_ARRAY_085ad4dc[anim->cmdIdx];
    }
    if (anim->cmdIdx >= 10 && anim->cmdIdx <= 13) {
      return u16_ARRAY_085ad4dc[anim->cmdIdx - 10];
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080ffcd0.inc");
#endif
}

void FUN_080ffd28(Boku* p) {
  Boku* q = (p->e).unk_1cc;

  if (q->timer_670 != 0) {
    q->timer_670--;
  }
}

void Boku_PickRandomPathNode(Boku* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

// 257/332命令, 原典はフレーム 0x14 で向きのベクトルや経路の塊をスタックに置く, 1回目の下書きで切り上げ
NON_MATCH void FUN_080ffda8(Boku* p) {
#ifdef NONMATCHING_C
  Mover* target = (p->e).playerMover;
  u8 angle = ArcTan2_8(target->pos.x - (p->e).mover.pos.x, target->pos.z - (p->e).mover.pos.z);
  s16 fx = (COS(angle) * 160) >> 16;
  s16 fz = (SIN(angle) * 160) >> 16;
  PathNode* node = Map_GetPathNodes((p->e).pathWalker.path);
  bool8 found = FALSE;
  s32 i;

  for (i = 0; i < (p->e).pathWalker.path->nodeCount && !found; i++) {
    s16 dx = node->x - (p->e).mover.pos.x;
    s16 dz = node->y - (p->e).mover.pos.z;

    if (dx * fx + fz * dz < 0) {
      if (node->x != (p->e).pathWalker.node->x || node->y != (p->e).pathWalker.node->y) {
        (p->e).pathWalker.nodeIdx = i;
        (p->e).pathWalker.waitTimer = 0;
        (p->e).pathWalker.node = node;
        found = TRUE;
      }
    } else {
      node++;
    }
  }
  if (!found) {
    Boku_PickRandomPathNode(p);
  }
  {
    Vec3* dst = (p->e).unk_4a8;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  {
    NavAgent* agent = (p->e).navAgent;
    WorldPos* pos = &(p->e).mover.pos;
    WorldPos* dst = (p->e).unk_4a8;
    s32 result;

    if (Map_IsPosInAgentIsland(agent, pos, dst) && (result = Map_TryFindNavRoute(agent, pos, dst)) != 0) {
      if (result != 2) {
        ClearMemory(&(p->e).mover.delta, 8);
      }
      (p->e).unk_4a8->val = 1;
    } else {
      Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_080ffda8.inc");
#endif
}

// 83/84命令, 原典は ~2 を movs/rsbs の 32bit で作って r6 に持つが, こちらは 16bit の ldr 0xFFFD になる, 型付き引数の inline は試済 (悪化)
NON_MATCH void FUN_081000a4(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;

  q->unk_67c = q->unk_67e;
  SET_FLAGS(q->unk_65c, 1);
  q->unk_65c &= ~2;
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
  Enemy_ResetState(&p->e, 0, 0, 15);
  Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_4b4[(p->e).unk_4b6 ^ 1], 0, 0);
  FUN_080ffda8(p);
  q->unk_65c &= ~2;
#else
  INCFUNC("asm/func/FUN_081000a4.inc");
#endif
}

// 44/48命令, 原典は unk_65b = 0 を両方の分岐に複写する, 分岐の向きの入れ替えは試済
NON_MATCH void Boku_InitDelayedScript(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;

  if (VM_SeekToNamedArg('x')) {
    q->scriptID_658 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    q->unk_65a = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    q->scriptID_658 = 0;
    q->unk_65a = 0;
  }
  q->unk_65b = 0;
#else
  INCFUNC("asm/func/Boku_InitDelayedScript.inc");
#endif
}

// 予約してあるスクリプトを unk_65a フレーム後に実行する
void Boku_UpdateDelayedScript(Boku* p) {
  Boku* q = (p->e).unk_1cc;

  if (q->scriptID_658 == 0) {
    return;
  }

  q->unk_65b++;
  if (q->unk_65b < q->unk_65a) {
    return;
  }

  VM_ExecByID(q->scriptID_658, NULL);
  q->scriptID_658 = 0;
  q->unk_65a = 0;
  q->unk_65b = 0;
}

// デカすぎて複数の関数を1つの関数として間違って扱っている可能性がある
// 2556/2565命令の下書き, プレイヤーへ向かう部分は FUN_080fd08c と同じ形を3回展開, 原典は &flags3 をスタックに置き状態フィールドのアドレスも作り置く (フレーム 0x100, こちらは 0xC4)
NON_MATCH bool32 FUN_08100228(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  if (!((p->e).weaponExpMask & 0x4000)) {
    if ((p->e).unk_48a == 0) {
      PlaySound_082406e0(SONG_529);
    } else {
      PlaySound_082406e0(CRY_BOKU_DAMAGED);
    }
  }
  Boku_UpdateDelayedScript(p);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_13)) {
    (p->e).mover.angle = (p->e).angle + 128;
    Enemy_PlayAnim(&p->e, 0);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13);
    (p->e).unk_544 = 300;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).unk_4a8->val = 0;
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).unk_4a8;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
            (p->e).unk_4a8->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).unk_540 = a;
            (p->e).unk_548 = (p->e).handlerState;
            (p->e).unk_54f = (p->e).state;
            (p->e).unk_54c = (p->e).subState0;
            (p->e).unk_54d = (p->e).subState1;
            (p->e).unk_54e = (p->e).subState2;
            (p->e).unk_541 = angle;
            Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          FUN_080e7b6c(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).unk_5c4(&p->e);
    }
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 2;
      return TRUE;
    }
    (p->e).unk_5c4(&p->e);
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_15)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) {
    Enemy_EnterState(&p->e, (p->e).unk_5cc, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_24);
    return TRUE;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if ((p->e).unk_4be != 0) {
    return FALSE;
  }
  q->unk_65c &= ~1;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
      (p->e).unk_4be = 45;
      (p->e).unk_48d = 65;
      Enemy_PlayAnim(&p->e, 3);
    }
    if ((p->e).playerMover == NULL) {
      return FALSE;
    }
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).unk_4a8;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
            (p->e).unk_4a8->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).unk_540 = a;
            (p->e).unk_548 = (p->e).handlerState;
            (p->e).unk_54f = (p->e).state;
            (p->e).unk_54c = (p->e).subState0;
            (p->e).unk_54d = (p->e).subState1;
            (p->e).unk_54e = (p->e).subState2;
            (p->e).unk_541 = angle;
            Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          FUN_080e7b6c(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).unk_5c4(&p->e);
    }
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return TRUE;
    }
    (p->e).unk_5c4(&p->e);
    return FALSE;
  } else {
    if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
      (p->e).unk_4be = 45;
      (p->e).unk_48d = 65;
      Enemy_PlayAnim(&p->e, 3);
    }
    if ((p->e).playerMover == NULL) {
      return FALSE;
    }
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).unk_4a8->val = 0;
    {
      Vec3* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).unk_4a8;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).unk_4a8->y = TileHeightAt((p->e).unk_4a8);
            (p->e).unk_4a8->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).unk_540 = a;
            (p->e).unk_548 = (p->e).handlerState;
            (p->e).unk_54f = (p->e).state;
            (p->e).unk_54c = (p->e).subState0;
            (p->e).unk_54d = (p->e).subState1;
            (p->e).unk_54e = (p->e).subState2;
            (p->e).unk_541 = angle;
            Enemy_EnterState(&p->e, (p->e).unk_5bc, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          FUN_080e7b6c(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).unk_5c4(&p->e);
    }
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 3;
      return TRUE;
    }
    (p->e).unk_5c4(&p->e);
    return FALSE;
  }
#else
  INCFUNC("asm/func/FUN_08100228.inc");
#endif
}

// 183/198命令, 1回目の下書きで切り上げ, 経路を引く塊は mimic.c の Enemy_TryRouteTo と同じ形
NON_MATCH bool32 FUN_081019e0(Boku* p) {
#ifdef NONMATCHING_C
  Boku* q = (p->e).unk_1cc;

  if (!Enemy_IsDead(&p->e) && (q->unk_65c & 1) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (q->unk_67c == 0) {
      CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
      Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
      Enemy_PlayAnim(&p->e, 0);
      (p->e).unk_554 = 30;
      (p->e).unk_558 = (p->e).unk_5b8;
      (p->e).unk_550 = 0;
      (p->e).unk_551 = 0;
      (p->e).unk_552 = 12;
      Enemy_EnterState(&p->e, FUN_080e6794, ES_UNK_14);
      Enemy_ResetState(&p->e, 3, 1, 0);
      Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
      {
        NavAgent* agent = (p->e).navAgent;
        WorldPos* pos = &(p->e).mover.pos;
        s32 result;

        if (!Map_IsPosInAgentIsland(agent, pos, &q->unk_660)) {
          Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
        } else {
          result = Map_TryFindNavRoute(agent, pos, &q->unk_660);
          if (result == 0) {
            Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
          } else if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
        }
      }
      q->unk_65c &= ~1;
    } else {
      q->unk_67c--;
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_081019e0.inc");
#endif
}

bool32 FUN_08101bb4(Boku* p) {
  FUN_080ffd28(p);
  return TRUE;
}

bool32 FUN_08101bc0(Boku* p) {
  FUN_081019e0(p);

  if (Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_13) || (p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }

  FUN_08101bb4(p);
  return TRUE;
}

// FUN_080edebc から呼ばれる
s32 EnemyBoku_Update(Boku* p) {
  FUN_080f06b0(&p->e);
  return 0;
}

s32 EnemyBoku_Destroy(Boku* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).unk_44c) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).unk_44c = 1;
  }
  if (!(p->e).unk_44d) {
    Eff082473e0Emitter_Destroy(&(p->e).emitter);
    (p->e).unk_44d = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  FUN_080ec6fc(&p->e);
  return 0;
}

// 1603/1773命令, Mimic_Init と同じ残差 (原典はフレーム 0x1B4 に Enemy のフィールドのアドレスを作り置く, 敵共通の初期化 inline), Curoro_Init の下書きを Boku 向けに直しただけ
NON_MATCH s32 EnemyBoku_Init(Boku* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  FUN_080e37e8(&p->e, p, 0);
  Boku_InitAnims(p);
  Boku_InitDelayedScript(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* aux;
    u8 k;

    (p->e).sprite = Malloc(sizeof(EnemyAuxSpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemyAuxSpriteData));
    aux = (EnemyAuxSpriteData*)(p->e).sprite;
    Video_GetAuxSprite(&aux->gfx, SPRITE_BOKU);
    AuxSprite_Add(&aux->sprite, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_BOKU);
    k = (p->e).kind;
    if (k == ENEK_CURORO || k == ENEK_GHOST) {
      aux->sprite.priority = 1;
    }
    (p->e).facing = 0;
  } else {
    EnemySpriteData* spr;
    MainSpriteGfxFile* f;
    Vec3 origin;

    (p->e).sprite = Malloc(sizeof(EnemySpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemySpriteData));
    spr = (p->e).sprite;
    Vec3_Clear(&origin);
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_BOKU);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->s, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

  (p->e).flags = 0;
  (p->e).flags2 = 0;
  (p->e).unk_46f = 0;
  (p->e).unk_1bc = 8;
  (p->e).flags5 = VM_GetNamedArgValue('M', 0);
  Vec3_Clear(&pos);
  (p->e).unk_4b6 = 0;
  if (!VM_SeekToNamedArg('r')) {
    (p->e).unk_250 = 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = 0;
    (p->e).prevPathNode = 0;
    (p->e).unk_4b4[(p->e).unk_4b6] = 0;
    (p->e).unk_4b4[(p->e).unk_4b6 ^ 1] = 0;
    onPath = FALSE;
  } else {
    u8 sel;

    (p->e).unk_250 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).prevPathNode = (p->e).unk_252;
    (p->e).unk_4b4[(p->e).unk_4b6] = (p->e).unk_250;
    sel = (p->e).unk_4b6;
    (p->e).unk_4b4[sel ^ 1] = VM_GetPC() != NULL ? VM_GetValue() : (p->e).unk_250;
    Map_GetPathNodePos(&pos, (p->e).unk_250, (p->e).unk_252);
    (p->e).unk_256 = GetCollisionTileIdx(&pos);
    pos.y = TileHeightAt(&pos);
    (p->e).floorY = pos.y;
    onPath = TRUE;
  }

  id = VM_GetNamedArgValue('N', 0);
  if (!VM_SeekToNamedArg('e')) {
    range0 = 48;
    range3 = 64;
  } else {
    range0 = VM_GetPC() != NULL ? VM_GetValue() : 48;
    range3 = VM_GetPC() != NULL ? (u8)VM_GetValue() : 64;
  }
  if (!VM_SeekToNamedArg('n')) {
    range1 = 0;
    (p->e).unk_1fe = 0;
  } else {
    range1 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_1fe = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  range2 = range0;

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      (p->e).atkPower[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkUnk40[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      (p->e).atkInvincibleTime[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (!VM_SeekToNamedArg('l')) {
    hpParam3 = 0;
    hpParam4 = 0;
    (p->e).unk_24c = 0;
  } else {
    hpParam3 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    hpParam4 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    (p->e).unk_24c = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  if (VM_GetNamedArgValue('b', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_9);
  }
  (p->e).scriptID = VM_GetNamedArgValue('F', 0);
  (p->e).unk_194 = VM_GetNamedArgValue('R', 0);
  if (VM_SeekToNamedArg('A')) {
    (p->e).maxHp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_546 = (p->e).maxHp >> 1;
    (p->e).power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_187 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_188 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  FUN_080e48e8(&p->e, (p->e).maxHp, hpParam3, hpParam4);
  Enemy_SetRanges(&p->e, 0, range0, range2, range1, range3);
  if (VM_SeekToNamedArg('X')) {
    (p->e).exp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weaponExp = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).unk_25a = VM_GetNamedArgValue('K', 2);
  if (VM_GetNamedArgValue('H', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_11);
  }
  if (VM_GetNamedArgValue('L', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_15);
  }

  Mover_Init(&(p->e).mover, id, &pos, 0, 4, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, FUN_080f48ac);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? (AuxSprite*)(p->e).sprite : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).moverTile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).moverTile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_31) {
    Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_3)) {
    (p->e).unk_1e8 = Div((p->e).range0Sq * 7, 10);
  } else {
    (p->e).unk_1e8 = (p->e).range0Sq;
  }
  (p->e).zoneSource.id = (p->e).mover.id;
  (p->e).zoneSource.pos = &(p->e).mover.pos;
  if (onPath) {
    (p->e).mover.angle = ((((p->e).pathWalker.node->delay >> 12 & 7) + 5) & 7) << 5;
  }
  if (!VM_SeekToNamedArg('P')) {
    p->unk_674 = 120;
    p->unk_67e = 120;
    p->unk_672 = 120;
  } else {
    p->unk_674 = VM_GetPC() != NULL ? VM_GetValue() : 120;
    p->unk_67e = VM_GetPC() != NULL ? VM_GetValue() : 120;
    p->unk_672 = VM_GetPC() != NULL ? VM_GetValue() : 120;
  }
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).unk_47a = 306;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 306;
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)(p->e).sprite)->gfx, (p->e).unk_47a + (p->e).variant);
  } else {
    (p->e).sprite->s.pltt = &gObjPlttData[((p->e).unk_47a + (p->e).variant) * 16];
  }
  if ((p->e).spriteKind == 1) {
    s16 n;

    if ((p->e).kind >= ENEK_SKELETON && (p->e).kind <= ENEK_LICH) {
      n = Enemy_CountByKind(ENEK_SKELETON) + 1 + Enemy_CountByKind(ENEK_SKELETON_F) + Enemy_CountByKind(ENEK_SKELETON_A) + Enemy_CountByKind(ENEK_LICH);
    } else {
      n = Enemy_CountByKind((p->e).kind) + 1;
    }
    (p->e).sprite->s.plttID = n + 220;
  }

  (p->e).unk_476 = (p->e).unk_47a + 4;
  (p->e).unk_478 = (p->e).unk_47a;
  Boku_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).unk_4a8 = &p->unk_6a4;
  (p->e).unk_580 = (EnemyHandler)FUN_08101bc0;
  (p->e).unk_588 = (void*)FUN_080ffcd0;
  (p->e).unk_590 = FUN_080fba64;
  (p->e).unk_5a0 = FUN_080fba28;
  (p->e).unk_5a4 = FUN_080fba40;
  (p->e).unk_5c0 = FUN_080fc0b8;
  (p->e).unk_5c4 = (EnemyHandler)FUN_080f62b0;
  (p->e).unk_5cc = FUN_080fd08c;
  (p->e).unk_5d0 = FUN_080fe274;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = FUN_080fc548;
  (p->e).unk_584 = FUN_080fc1e4;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).unk_608 = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).unk_60c = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).unk_5f8 = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).unk_5bc = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = FUN_080fc4ec;
  (p->e).unk_5ec = FUN_080f47c8;
  (p->e).unk_5d8 = FUN_080f54e4;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).unk_58c = FUN_080f64f0;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).unk_5b8 = FUN_080f624c;
  (p->e).unk_594 = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  FUN_080e6204(&p->e);
  (p->e).unk_5f8 = (EnemyHandler)FUN_080ffad8;
  (p->e).unk_5fc = FUN_080ffc28;
  (p->e).unk_5ac = (EnemyHandler)FUN_080ff6e8;
  (p->e).unk_5b0 = (EnemyHandler)FUN_080ff7c0;
  (p->e).unk_58c = (void*)FUN_08100228;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21 | ENEFLAG_UNK_22 | ENEFLAG_UNK_24);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_27);
  (p->e).hurtbox.flags &= ~HBFLAG_UNK_0;
  (p->e).kind = ENEK_BOKU;
  Enemy_Init_080e5dd4(&p->e);

  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg++ = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  (p->e).unk_19a = VM_GetNamedArgValue('D', 0);
  {
    s32 u = VM_GetNamedArgValue('u', 0);

    (p->e).unk_496[0] = 0x21;
    (p->e).unk_496[1] = 0;
    if (u != 0) {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_18);
      if (u == 2) {
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_18 | ENEFLAG_UNK_19);
      }
    }
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_2)) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
  } else {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_13);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_1)) {
    (p->e).zoneID = GetZoneAt(&(p->e).mover.pos);
  } else {
    (p->e).zoneID = gStat->zoneID;
  }
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_6)) {
    (p->e).hurtbox.flags &= ~HBFLAG_ANGLE;
  }
  if (VM_GetNamedArgValue('S', 0) != 0 || gStat->zoneID != (p->e).zoneID) {
    FUN_080f07d0(&p->e, NULL);
  }
  Enemy_PlayAnim(&p->e, 0);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* aux = (EnemyAuxSpriteData*)(p->e).sprite;

    AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
  } else {
    MainSprite_AdvanceAnim(&(p->e).sprite->s, &(p->e).sprite->gfx);
  }
  (p->e).hitTargetID = 0;
  kind = (p->e).kind;
  if (!IsLinkPlay() && (kind == ENEK_BOKU || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DOG || kind == ENEK_BEE || kind == ENEK_GHOST)) {
    MsgQueue_Register(&(p->e).mq, (p->e).mover.id, 3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_8);
  }
  Enemy_InitHandlerTables(&p->e);
  FUN_080ff45c(p);
  FUN_080ff05c(p);
  FUN_080ff668(p);
  (p->e).unk_572 = (p->e).flags5;
  (p->e).unk_570 = (p->e).heightAboveFloor;
  (p->e).unk_55c = (p->e).flags;
  (p->e).unk_560 = (p->e).flags2;
  (p->e).unk_564 = (p->e).mover.angle;
  (p->e).unk_565 = (p->e).subState0;
  (p->e).unk_566 = (p->e).subState1;
  (p->e).unk_567 = (p->e).subState2;
  (p->e).unk_568 = (p->e).handlerState;
  (p->e).unk_56c = (p->e).state;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)EnemyBoku_Update;
  (p->e).handlerDestroy = (EnemyHandler)EnemyBoku_Destroy;
  if (!Enemy_Init_080ec640(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/EnemyBoku_Init.inc");
#endif
}

void EnemyBoku_Create(void) {
  Boku* p = Malloc(sizeof(Boku));
  if (p != NULL) {
    ClearMemory(p, sizeof(Boku));
    if (EnemyBoku_Init(p) < 0) {
      EnemyBoku_Destroy(p);
      Free(p);
    }
  }
}
