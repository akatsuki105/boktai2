#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
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
  NavAgent navAgent;          // 0x658, Enemy.navAgent が指す
  Vec3 unk_67c;               // 0x67C, Enemy.unk_4a8 が指す
  WorldPos homePos;           // 0x684, 生成時の mover.pos, Mimic_TryRouteHome がここへの経路を引く
  u16 homeTileIdx;            // 0x68C, homePos のタイル番号
  u16 unk_68e;                // 0x68E
  u16 unk_690;                // 0x690, bit0 を FUN_081486d8 が落とす
  u8 unk_692;                 // 0x692, '.s=10'
  u8 unk_693;                 // 0x693
} Mimic;
static_assert(sizeof(Mimic) == 1684);

void FUN_081486d8(Mimic* p);
void FUN_08147030(Mimic* p);
void FUN_081473ac(Mimic* p);
void FUN_081489f0(Mimic* p);
void FUN_08147530(Mimic* p, s32 param_2);

static void FUN_0814830c(Mimic* p);
static bool8 Mimic_IsPlayerLost(Mimic* p);
static u32 FUN_08148750(s32 angle);

static inline bool8 IsLinkPlay(void) {
  if (gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) return TRUE;
  return FALSE;
}

// dst への経路を引けたら TRUE, 島の外か経路が無ければ経路追従の印を落として FALSE
static inline bool8 Enemy_TryRouteTo(Enemy* p, NavAgent* agent, WorldPos* pos, WorldPos* dst) {
  s32 result;

  if (Map_IsPosInAgentIsland(agent, pos, dst) && (result = Map_TryFindNavRoute(agent, pos, dst)) != 0) {
    if (result != 2) {
      ClearMemory(&p->mover.delta, 8);
    }
    return TRUE;
  }
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
  return FALSE;
}

static inline bool8 Mimic_TestUnk690(Mimic* p, u16 bit) {
  if (TEST_FLAGS(p->unk_690, bit)) {
    return TRUE;
  }
  return FALSE;
}

static inline bool8 AuxSprite_TestFlags(AuxSprite* sprite, SpriteFlags bits) {
  if (sprite->flags & bits) return TRUE;
  return FALSE;
}

static inline bool8 MainSprite_TestFlags(MainSprite* sprite, SpriteFlags bits) {
  if (sprite->flags & bits) return TRUE;
  return FALSE;
}

static inline bool8 Enemy_TestSpriteFlags(Enemy* p, SpriteFlags bits) {
  if (p->spriteKind == 0) {
    return AuxSprite_TestFlags((AuxSprite*)p->sprite, bits);
  }
  return MainSprite_TestFlags(&p->sprite->s, bits);
}

static inline u16 Enemy_GetUnk24e(Enemy* p) { return p->unk_24e; }

void FUN_081467bc(Mimic* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).animSpeedDiv = 1;
    (p->e).unk_222 = 0;
    (p->e).unk_24e = 0;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).unk_542 = 0xFF;
    (p->e).playerMover = NULL;
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
  }
  (p->e).unk_608(&p->e);
}

void FUN_081468c8(Mimic* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 15);
  } else {
    (p->e).unk_608(&p->e);
  }
}

void FUN_08146970(Mimic* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Mimic* q;

    (p->e).playerMover = NULL;
    q = (p->e).unk_1cc;
    SET_FLAGS(q->unk_690, 1);
    Enemy_EnterState(&p->e, FUN_08147530, ES_UNK_36);
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).unk_608(&p->e);
  }
}

void FUN_08146a34(Mimic* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_08147030, ES_UNK_34);
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 16);
  } else {
    (p->e).unk_608(&p->e);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

// 208/207命令, 原典は p を r5, unk_1cc を r7 に置き (こちらは r6 / r5), 分岐の並びも少し違う, 1回目の下書きで切り上げ
NON_MATCH void FUN_08146ae8(Mimic* p) {
#ifdef NONMATCHING_C
  Mimic* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081473ac, ES_UNK_35);
  }
  if (FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, 0)) {
    (p->e).jumpVel.x = 0;
    (p->e).jumpVel.z = 0;
  }

  if (!(p->e).subStateDone) {
    (p->e).unk_608(&p->e);
  } else if (Mimic_TestUnk690(q, 1)) {
    if (q->homeTileIdx == (p->e).unk_256) {
      CLEAR_FLAGS(q->unk_690, 1);
      Enemy_ResetState(&p->e, 0, 0, 0);
    } else {
      Enemy_ResetState(&p->e, 0, 0, 15);
    }
  } else if (Mimic_IsPlayerLost(p)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    (p->e).unk_24e = 0;
  } else {
    Enemy_ResetState(&p->e, 0, 0, 15);
  }
#else
  INCFUNC("asm/func/FUN_08146ae8.inc");
#endif
}

// 280/295命令, 原典は flags3 / flags / unk_1cc などのアドレスを r8-r10 に持ち越す (こちらは r8 のみ), 1回目の下書きで切り上げ
NON_MATCH void FUN_08146ce0(Mimic* p) {
#ifdef NONMATCHING_C
  Mimic* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).playerMover = NULL;
    (p->e).animSpeedDiv = 1;
    (p->e).unk_222 = 0;
    (p->e).unk_24e = 0;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).unk_542 = 0xFF;
  }

  if ((p->e).subStateTimer < 31) {
    (p->e).unk_608(&p->e);
    (p->e).subStateTimer++;
  } else {
    NavAgent* agent;
    WorldPos* pos;
    s32 route;

    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_8);
    SET_FLAGS(q->unk_690, 1);
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    agent = (p->e).navAgent;
    pos = &(p->e).mover.pos;
    if (!Map_IsPosInAgentIsland(agent, pos, &q->homePos) || (route = Map_TryFindNavRoute(agent, pos, &q->homePos)) == 0) {
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    } else if (route != 2) {
      ClearMemory(&(p->e).mover.delta, 8);
    }
    if (!Enemy_IsPosInRect(&p->e, &q->homePos, 32, 32)) {
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7);
      (p->e).pendingDelay = 30;
      (p->e).pendingHandler = (p->e).unk_5a0;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 2;
    } else {
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7);
      (p->e).pendingDelay = 30;
      (p->e).pendingHandler = (p->e).unk_5a4;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 0;
      CLEAR_FLAGS(q->unk_690, 1);
    }
    (p->e).animSpeedDiv = 1;
  }
#else
  INCFUNC("asm/func/FUN_08146ce0.inc");
#endif
}

void (*const PTR_ARRAY_085ad874[18])(Mimic*) = {
    FUN_081467bc,
    (void*)FUN_080f2864,
    FUN_081468c8,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    FUN_08146ce0,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_08146a34,
    FUN_08146ae8,
    FUN_08146970,
};  // 0x085AD874

void FUN_08146fac(Mimic* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad874; }

s32 FUN_08146fc0(Mimic* p) {
  FUN_0814830c(p);
  return 1;
}

void FUN_08146fcc(Mimic* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacingFlags(&p->e, 16, FUN_08148750((p->e).mover.angle));
    (p->e).atkHitbox.flags &= ~HBFLAG_HIDDEN;
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

NAKED void FUN_08147030(Mimic* p) { INCFUNC("asm/func/FUN_08147030.inc"); }

void FUN_081473ac(Mimic* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    if (Mimic_IsPlayerLost(p)) {
      Enemy_PlayAnimNoFacingFlags(&p->e, 15, FUN_08148750((p->e).mover.angle));
    } else {
      Enemy_PlayAnimNoFacingFlags(&p->e, 16, FUN_08148750((p->e).mover.angle));
    }
    ParticleShadow_Hide(&(p->e).shadow);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void FUN_08147428(Mimic* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacingFlags(&p->e, 0, FUN_08148750((p->e).mover.angle));
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    (p->e).hurtbox.flags &= ~HBFLAG_HIDDEN;
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
}

void FUN_081474e8(Mimic* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacingFlags(&p->e, 0, FUN_08148750((p->e).mover.angle));
    (p->e).atkHitbox.flags |= HBFLAG_HIDDEN;
  }
}

void FUN_08147530(Mimic* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacingFlags(&p->e, 0, FUN_08148750((p->e).mover.angle));
    (p->e).atkHitbox.flags |= HBFLAG_HIDDEN;
  }
  if (param_2 == 160) {
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  } else if (param_2 > 160 && Emote_IsInactive((p->e).emote)) {
    (p->e).subStateDone = 1;
  }
}

// 245/240命令, 原典は anim を (sprite + 0x48) で作って tick を [+0xE] で書く, stateTimer のアドレスを r5 に持つ, 消滅判定の後の並びも違う, 1回目の下書きで切り上げ
NON_MATCH void FUN_081475b8(Mimic* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacingFlags(&p->e, 10, FUN_08148750((p->e).mover.angle));
  }
  ((EnemyAuxSpriteData*)(p->e).sprite)->anim.tick = 0;

  if ((p->e).stateTimer < 20) {
    return;
  }
  if (!((p->e).stateTimer & 1)) {
    Vec3 size;

    VEC3_SET(size, 128, 64, 128);
    EmitSmoke(&(p->e).mover.pos, 1, &size, 0, 0, 0, 2, 2);
    if (!((p->e).stateTimer & 3)) {
      PlaySound_082406e0(SONG_366);
    }
  }

  if (Sprite_UpdateVanishBlink(&((AuxSprite*)(p->e).sprite)->flags, (p->e).stateTimer, 10, 30)) {
    s32 idx;

    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ((AuxSprite*)(p->e).sprite)->flags |= SPRFLAG_HIDDEN;
    ParticleShadow_Hide(&(p->e).shadow);
    FUN_080e6658(&p->e);
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
  } else if (Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else {
    ParticleShadow_Show(&(p->e).shadow);
  }
#else
  INCFUNC("asm/func/FUN_081475b8.inc");
#endif
}

// 255/273命令, 原典はフレーム 8 バイトで unk_20c / unk_214 のアドレスや差分をスタックとレジスタに持ち越す, 1回目の下書きで切り上げ
NON_MATCH void FUN_081477dc(Mimic* p) {
#ifdef NONMATCHING_C
  s32 dx, dz;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacingFlags(&p->e, 3, FUN_08148750((p->e).mover.angle));
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }

  dx = ((p->e).unk_20c.x - (p->e).unk_214.x) / 4;
  dz = ((p->e).unk_20c.z - (p->e).unk_214.z) / 4;
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

  if (dx == 0 && dz == 0 && (p->e).animForceRestart) {
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_5);
    if (!IsLinkPlay()) {
      (p->e).playerMover = &gPlayerPtr[0]->mover;
    } else if (!FUN_080faa98(&p->e)) {
      FUN_081489f0(p);
    }
    if ((p->e).playerMover == NULL) {
      Enemy_ResetState(&p->e, 0, 0, 0);
    } else {
      u8 angle = ArcTan2_8((p->e).playerMover->pos.x - (p->e).mover.pos.x, (p->e).playerMover->pos.z - (p->e).mover.pos.z);

      (p->e).unk_1fc = angle;
      (p->e).mover.angle = angle;
      if ((p->e).kind != ENEK_SPIDER) {
        SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      }
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
      (p->e).unk_24e = (p->e).unk_24c;
      CLEAR_FLAGS(((Mimic*)(p->e).unk_1cc)->unk_690, 1);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 2);
    }
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
#else
  INCFUNC("asm/func/FUN_081477dc.inc");
#endif
}

// 残差1命令 (174/175), 原典は p->sprite を r0 に読んでから r5 へ移すが, こちらは r5 へ直接読む (boku.c の Boku_OnReset と同じ), 試済: sprite のアクセサ inline, sprite / EnemySpriteData* のローカル, 引数に直接書く形
NON_MATCH void Mimic_OnReset(Mimic* p) {
#ifdef NONMATCHING_C
  Mimic* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->unk_68e = 0;
  q->unk_690 = 0;
  if (IsLinkPlay()) {
    q->homePos = (p->e).mover.pos;
    q->homeTileIdx = GetCollisionTileIdx(&(p->e).mover.pos);
  }
  Enemy_PlayAnimNoFacingFlags(&p->e, 0, FUN_08148750((p->e).mover.angle));
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
#else
  INCFUNC("asm/func/Mimic_OnReset.inc");
#endif
}

void Mimic_OnHit(HitboxData* a, HitboxData* b, Mimic* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 614/763命令, 原典は攻撃者を ignoreMask から覚える塊を3か所に展開し (inline らしい), 前半の分岐の並びも違う, 1回目の下書きで切り上げ
NON_MATCH void Mimic_OnHurt(HitboxData* a, HitboxData* b, Mimic* p) {
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
  INCFUNC("asm/func/Mimic_OnHurt.inc");
#endif
}

void Mimic_InitAnims(Mimic* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 14, 2, 0);
  Enemy_SetAnimEntry(&p->e, 15, 3, 0);
  Enemy_SetAnimEntry(&p->e, 16, 1, 0);
  Enemy_SetAnimEntry(&p->e, 3, 4, 0);
  Enemy_SetAnimEntry(&p->e, 10, 4, 0);
}

static void FUN_0814830c(Mimic* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7) && Enemy_GetUnk24e(&p->e) == 0 && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5)) {
    (p->e).playerMover = NULL;
    (p->e).animSpeedDiv = 1;
    (p->e).unk_222 = 0;
    (p->e).unk_24e = 0;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).unk_542 = 0xFF;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 17);
  }
}

void Mimic_InitHitboxes(Mimic* p) {
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 50, 30, 50);
  VEC3_SET(offset, 0, 40, 0);
  Enemy_InitAtkHitbox(&p->e, &halfSize, &offset, Mimic_OnHit, 0, p);
  VEC3_SET(halfSize, 80, 120, 80);
  VEC3_SET(offset, 0, 120, 0);
  Enemy_RegisterHurtbox(&p->e, &halfSize, &offset, Mimic_OnHurt, p);
}

bool8 Mimic_FindOpeningPlayer(Mimic* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Player* player = gPlayerPtr[i];

    if (player != NULL && !TEST_FLAGS(gPlayerModes[i], PMODE_UNK_3)) {
      Vec3 d;

      Vec3_Diff(&d, &player->mover.pos, &(p->e).mover.pos);
      if (d.x * d.x + d.z * d.z <= 96 * 96 && (gPlayerPtr[i]->input->pressed & A_BUTTON)) {
        (p->e).playerMover = &gPlayerPtr[i]->mover;
        return TRUE;
      }
    }
  }
  return FALSE;
}

bool8 Mimic_TryRouteToPlayer(Mimic* p) {
  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;
    s32 idx;

    if (m == NULL) {
      return FALSE;
    }
    idx = m->unk_4 < 4 ? m->unk_4 : -1;
    if (idx < 0 || TEST_FLAGS(gPlayerModes[idx], PMODE_UNK_3)) {
      return FALSE;
    }
  } else if ((p->e).playerMover == NULL) {
    return FALSE;
  }

  if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    return FALSE;
  }
  return TRUE;
}

// 経路を引く部分を (p, agent, pos, dst) を受けて if/else で TRUE/FALSE を返す bool8 inline にすると残差は最後の return TRUE の置き場所1箇所 (68/68命令) まで寄る, 直書きでは 64/68, Tier A 試済 (|| の形, 直書き)
NON_MATCH bool8 Mimic_TryRouteHome(Mimic* p) {
#ifdef NONMATCHING_C
  bool8 moved;
  NavAgent* agent = (p->e).navAgent;
  WorldPos* pos = &(p->e).mover.pos;
  WorldPos* dst = &p->homePos;

  if (!Map_IsPosInAgentIsland(agent, pos, dst)) {
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
    moved = FALSE;
  } else {
    s32 result = Map_TryFindNavRoute(agent, pos, dst);

    if (result != 0) {
      if (result != 2) {
        ClearMemory(&(p->e).mover.delta, 8);
      }
      moved = TRUE;
    } else {
      Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
      moved = FALSE;
    }
  }

  if (moved) {
    return TRUE;
  }
  Enemy_ResetState(&p->e, 0, 0, 17);
  return FALSE;
#else
  INCFUNC("asm/func/Mimic_TryRouteHome.inc");
#endif
}

// 残差は &kind の持ち越しで, 原典は Enemy_SetEmote の引数と呼び出し後の種族判定で 0x1DF から2回アドレスを作るが, こちらは r5 に持ち越す (54/56命令), Tier A 試済 (SET_FLAGS / 直書き, Enemy* ローカル), 未: 呼び出し側の inline
NON_MATCH void FUN_081486d8(Mimic* p) {
#ifdef NONMATCHING_C
  (p->e).mover.angle = (p->e).unk_1fc;
  Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
  Enemy_RunScript(&p->e);
  if ((p->e).kind != ENEK_SPIDER) {
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
  (p->e).unk_24e = (p->e).unk_24c;
  CLEAR_FLAGS(((Mimic*)(p->e).unk_1cc)->unk_690, 1);
#else
  INCFUNC("asm/func/FUN_081486d8.inc");
#endif
}

static u32 FUN_08148750(s32 angle) {
  switch (((angle + 16) & 0xFF) >> 6) {
    case 0:
    case 2: {
      return 0;
    }
    case 1:
    case 3: {
      return 1;
    }
  }
}

void FUN_08148780(void) {}

// 残差は最後のブロックの r2/r3 の入れ替わりだけ (143/143命令), 原典は &flags を r2, &flags4 を r3 に置く, Tier C 試済 (flags のポインタのローカル, playerMover のローカル, Enemy_TestFlag / Enemy_SetFlag)
NON_MATCH bool8 FUN_08148784(Mimic* p) {
#ifdef NONMATCHING_C
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    return FALSE;
  }
  if ((p->e).hitTargetID > 0) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    return TRUE;
  }

  if (IsLinkPlay()) {
    if (Mimic_FindOpeningPlayer(p)) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
      return TRUE;
    }
    if (Mimic_IsPlayerLost(p)) {
      return FALSE;
    }
  } else {
    s32 dy = (p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y;
    if (abs(dy) > Q8(2)) {
      return FALSE;
    }
    if (Mimic_FindOpeningPlayer(p)) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
      return TRUE;
    }
  }

  if ((p->e).playerMover != NULL && (p->e).unk_1e4 < (p->e).range0Sq && Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos) && TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08148784.inc");
#endif
}

// 残差は &flags の写しの位置だけ (102/102命令), 原典は ENEFLAG_UNK_26 の検査の直後 (分岐の前) に r6 へ写すが, こちらは分岐の後, Tier A-C 試済 (flags のポインタを検査の前/後に取る, Enemy_TestFlag, jumpVel を Vec3* で読む)
NON_MATCH void FUN_081488bc(Mimic* p) {
#ifdef NONMATCHING_C
  EnemyFlags* flags;
  Vec3* vel;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).unk_24e = (p->e).unk_24c;
    return;
  }
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    return;
  }

  flags = &(p->e).flags;
  vel = &(p->e).jumpVel;
  if (vel->x * vel->x + vel->y * vel->y + vel->z * vel->z != 0 || (p->e).heightAboveFloor != 0) {
    FUN_081486d8(p);
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 1, 0);
  }
  SET_FLAGS(*flags, ENEFLAG_UNK_26);
#else
  INCFUNC("asm/func/FUN_081488bc.inc");
#endif
}

// 残差は PFLAG20_INVISIBLE の定数で, 原典は gPlayerPtr を読んでから作るがこちらは先に作る (33/33命令), Tier A は試済 (条件の向き, || と && の組み方), 未: プレイヤー判定の inline
NON_MATCH static bool8 Mimic_IsPlayerLost(Mimic* p) {
#ifdef NONMATCHING_C
  Mover* m = (p->e).playerMover;

  if (m != NULL && (m->unk_4 >= 4 || (!TEST_FLAGS(gPlayerPtr[m->unk_4]->flag20, PFLAG20_INVISIBLE) && !TEST_FLAGS(gPlayerModes[m->unk_4], PMODE_UNK_3)))) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/Mimic_IsPlayerLost.inc");
#endif
}

s32 FUN_081489ec(Mimic* p) { return 0; }

void FUN_081489f0(Mimic* p) {
  Enemy_ResetState(&p->e, 0, 0, 17);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  (p->e).playerMover = NULL;
  (p->e).animSpeedDiv = 1;
  (p->e).unk_222 = 0;
  (p->e).unk_24e = 0;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    (p->e).unk_21c = 0;
    (p->e).unk_21e = 0;
    (p->e).unk_202 = 0;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
  (p->e).unk_542 = 0xFF;
}

bool8 Mimic_OnDamaged(Mimic* p) {
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  if ((p->e).flags6 & (ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) {
    Enemy_EnterState(&p->e, (p->e).unk_5cc, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    return TRUE;
  }

  Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_5);
  if ((p->e).playerMover != NULL) {
    if (Mimic_TestUnk690((p->e).unk_1cc, 1) || (p->e).hp < (p->e).unk_546) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
      CLEAR_FLAGS(((Mimic*)(p->e).unk_1cc)->unk_690, 1);
    }
  }
  return FALSE;
}

void FUN_08148c00(Mimic* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    FUN_081486d8(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08148c6c(Mimic* p) {
  static void (*const PTR_ARRAY_085ad8bc[1])(Mimic*) = {
      FUN_08148c00,
  };  // 0x085AD8BC
  (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad8bc;
}

s32 FUN_08148c7c(Mimic* p) {
  u32 idx = (p->e).subState0;
  EnemyHandler* table = (p->e).handlerTables[0];

  table[idx](&p->e);
  Enemy_RunStateHandler(&p->e);
  FUN_08146fc0(p);
  return 1;
}

bool32 Mimic_Update(Mimic* p) { return Enemy_Update(&p->e); }

s32 Mimic_Destroy(Mimic* p) {
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
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
// 1735/1866命令, 原典はフレーム 0x1A4 で Enemy のフィールドのアドレスを 80 個ほどスタックに作り置いてから使う (共通の初期化 inline が展開されたもの), こちらはフレーム 0x44, 1回目の下書きで切り上げ
NON_MATCH s32 Mimic_Init(Mimic* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_MIMIC;
  Mimic_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* aux;
    u8 k;

    (p->e).sprite = Malloc(sizeof(EnemyAuxSpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemyAuxSpriteData));
    aux = (EnemyAuxSpriteData*)(p->e).sprite;
    Video_GetAuxSprite(&aux->gfx, SPRITE_MIMIC);
    AuxSprite_Add(&aux->sprite, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_MIMIC);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_MIMIC);
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
  Enemy_InitHpAndState(&p->e, (p->e).maxHp, hpParam3, hpParam4);
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
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
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
  (p->e).mover.angle = VM_GetNamedArgValue('d', 0);
  p->unk_692 = VM_GetNamedArgValue('s', 10);
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_256 = GetCollisionTileIdx(&(p->e).mover.pos);
    (p->e).prevTileIdx = (p->e).unk_256;
    (p->e).floorY = TileHeightAt(&(p->e).mover.pos);
    (p->e).heightAboveFloor = 0;
    (p->e).mover.pos.y = (p->e).floorY;
  }
  p->homePos = (p->e).mover.pos;
  p->homeTileIdx = (p->e).unk_256;

  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).unk_47a = 650;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 650;
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

  Mimic_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).unk_4a8 = &p->unk_67c;
  (p->e).unk_580 = (EnemyHandler)FUN_08148c7c;
  (p->e).unk_588 = NULL;
  (p->e).unk_590 = NULL;
  (p->e).unk_5a0 = FUN_08146fcc;
  (p->e).unk_5a4 = FUN_081474e8;
  (p->e).unk_5c0 = NULL;
  (p->e).unk_5c4 = (EnemyHandler)FUN_081489ec;
  (p->e).unk_5cc = FUN_081477dc;
  (p->e).unk_5d0 = FUN_081475b8;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = NULL;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).unk_608 = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).unk_60c = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).unk_5bc = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = NULL;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).unk_58c = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).unk_5b8 = FUN_080f624c;
  (p->e).unk_594 = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  (p->e).onReset = (EnemyHandler)Mimic_OnReset;
  (p->e).unk_5ac = (EnemyHandler)FUN_081488bc;
  (p->e).unk_5b0 = NULL;
  (p->e).unk_608 = (void*)FUN_08148784;
  (p->e).unk_58c = (void*)Mimic_OnDamaged;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9 | ENEFLAG_UNK_22);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6);
  Enemy_InitShadowAndEmitter(&p->e);

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
    Enemy_Suspend(&p->e, NULL);
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
  {
    s32 height = VM_GetNamedArgValue('f', 0);

    if (height != 0) {
      (p->e).heightAboveFloor = height;
      Enemy_EnterState(&p->e, FUN_08147428, ES_UNK_37);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
  Enemy_InitHandlerTables(&p->e);
  FUN_08146fac(p);
  FUN_08148c6c(p);
  (p->e).unk_1bc = 0;
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
  (p->e).kind = ENEK_MIMIC;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)Mimic_Update;
  (p->e).handlerDestroy = (EnemyHandler)Mimic_Destroy;
  (p->e).unk_478 = 652;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Mimic_Init.inc");
#endif
}

void Mimic_Create(void) {
  Mimic* p = Malloc(sizeof(Mimic));

  if (p != NULL) {
    ClearMemory(p, sizeof(Mimic));
    if (Mimic_Init(p) < 0) {
      Mimic_Destroy(p);
      Free(p);
    }
  }
}
