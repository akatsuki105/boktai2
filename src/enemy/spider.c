#include "coffin.h"
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

// スパイダー(ENEID_SPIDER), ポイズンスパイダー(ENEID_PSPIDER)
// 見えない蜘蛛の巣を仕掛けて、プレイヤーがそれに触れると身動きが取れなくなる
// ポイズンスパイダーは毒液も吐く
typedef struct {
  Enemy e;
  u8 unk_654[0x660 - 0x654];  // 0x654
  u16 unk_660;                // 0x660, bit1 はプレイヤーが Entity080db520 の枠を持っていないとき落とす
  u16 unk_662;                // 0x662, 300 から数え下ろし, 0 になると棺桶を狙いに行く
  u8 unk_664[1680 - 0x664];   // 0x664
} Spider;
static_assert(sizeof(Spider) == 1680);

static inline bool8 Spider_TestUnk660(Spider* p, u16 bit) {
  if (p->unk_660 & bit) return TRUE;
  return FALSE;
}

void FUN_080e8614(Enemy* p);
void FUN_08130eec(Spider* p);
void FUN_0812f83c(Spider*);
void FUN_0812f840(Spider*);
void FUN_0812f9ec(Spider*);
void FUN_0812fbec(Spider*);
void FUN_0812fcd8(Spider*);
void FUN_0812fdb8(Spider*);
void FUN_08130068(Spider*);
void FUN_08130460(Spider*);
void FUN_08130610(Spider*);
void FUN_0813069c(Spider*);

void (*const PTR_ARRAY_085ad6bc[17])(Spider*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    FUN_0812fdb8,
    FUN_0812fbec,
    FUN_0812f9ec,
    NULL,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    FUN_0812f840,
    FUN_0812fcd8,
    NULL,
    FUN_08130068,
    FUN_0812f83c,
};  // 0x085AD6BC

void (*const PTR_ARRAY_085ad700[3])(Spider*) = {
    (void*)FUN_080f1c54,
    (void*)FUN_080f1cb8,
    (void*)FUN_080f1cf0,
};  // 0x085AD700

const u16 u16_ARRAY_085ad70c[2] = {486, 486};  // 0x085AD70C

void FUN_081302f8(Spider*, u16*);

void (*const PTR_ARRAY_085ad710[7])(Spider*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_081302f8,
};  // 0x085AD710

void Spider_OnHit(HitboxData* a, HitboxData* b, Spider* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void Spider_OnHurt(HitboxData* a, HitboxData* b, Spider* p) { INCFUNC("asm/func/Spider_OnHurt.inc"); }

void FUN_0812ea6c(Spider* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

void FUN_0812ea90(Spider* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

NAKED void FUN_0812eab4(Spider* p) { INCFUNC("asm/func/FUN_0812eab4.inc"); }

NAKED void FUN_0812edf8(Spider* p) { INCFUNC("asm/func/FUN_0812edf8.inc"); }

NAKED void FUN_0812ef50(Spider* p, s32 timer) { INCFUNC("asm/func/FUN_0812ef50.inc"); }

void FUN_0812f1b4(Spider* p) {}

void FUN_0812f1b8(Spider* p) {}

NAKED void FUN_0812f1bc(Spider* p, s32 timer) { INCFUNC("asm/func/FUN_0812f1bc.inc"); }

void FUN_0812f358(Spider* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Enemy_PlayAnim(&p->e, 1);
  if ((p->e).unk_24e == 0) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    Enemy_ResetState(&p->e, 0, 0, 7);
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
  }
}

NAKED void FUN_0812f3f8(Spider* p, s32 timer) { INCFUNC("asm/func/FUN_0812f3f8.inc"); }

NAKED void FUN_0812f5f4(Spider* p, s32 timer) { INCFUNC("asm/func/FUN_0812f5f4.inc"); }

s32 FUN_0812f818(Spider* p) {
  FUN_08130460(p);
  FUN_08130610(p);
  FUN_0813069c(p);
  FUN_080e8614(&p->e);
  return 1;
}

void FUN_0812f83c(Spider* p) {}

NAKED void FUN_0812f840(Spider* p) { INCFUNC("asm/func/FUN_0812f840.inc"); }

NAKED void FUN_0812f9ec(Spider* p) { INCFUNC("asm/func/FUN_0812f9ec.inc"); }

void FUN_0812fbec(Spider* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  } else if (!(p->e).unk_608(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 7);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void FUN_0812fcd8(Spider* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  } else if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
  } else {
    (p->e).subStateTimer++;
  }
}

NAKED void FUN_0812fdb8(Spider* p) { INCFUNC("asm/func/FUN_0812fdb8.inc"); }

void FUN_08130068(Spider* p) {
  Enemy_ConsumeSubStateBegun(&p->e);
  if (!(p->e).unk_608(&p->e)) {
    (p->e).subStateTimer++;
  }
}

void FUN_081300a8(Spider* p) {
  Enemy_ConsumeSubStateBegun(&p->e);
  (p->e).subStateTimer++;
}

void FUN_081300d0(Spider* p) {
  (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad6bc;
  (p->e).handlerTables[6] = (void*)PTR_ARRAY_085ad700;
}

void Spider_InitHitboxes(Spider* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 128, 128, 128);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtboxWithFlags(&p->e, &hurtSize, &hurtOffset, Spider_OnHurt, p, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_3 | HBFLAG_UNK_1 | HBFLAG_UNK_0);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Spider_OnHit, 0, p);
}

NAKED void Spider_OnReset(Spider* p) { INCFUNC("asm/func/Spider_OnReset.inc"); }

void Spider_InitAnims(Spider* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  Enemy_SetAnimEntry(&p->e, 2, 5, 0);
  Enemy_SetAnimEntry(&p->e, 3, 4, 0);
  Enemy_SetAnimEntry(&p->e, 5, 2, 0);
  Enemy_SetAnimEntry(&p->e, 14, 1, 0);
}

NAKED void FUN_081302f8(Spider* p, u16* msg) { INCFUNC("asm/func/FUN_081302f8.inc"); }

void FUN_08130460(Spider* p) {
  if (Enemy_IsDead(&p->e) == 0 && gPlayerPtr[0]->unk_3ff < 0) {
    Spider* q = (p->e).unk_1cc;

    CLEAR_FLAGS(q->unk_660, 2);
  }
}

NAKED bool8 FUN_081304a8(Spider* p, s32 rangeX, s32 rangeZ) { INCFUNC("asm/func/FUN_081304a8.inc"); }

NAKED bool8 FUN_08130508(Spider* p) { INCFUNC("asm/func/FUN_08130508.inc"); }

// 棺桶が空いて止まっている間, 300 フレームごとに棺桶を狙いに行く
void FUN_08130610(Spider* p) {
  if ((p->e).variant != 1) {
    Spider* q = (p->e).unk_1cc;

    if (FUN_08086878() != -1 || !Coffin_IsIdle()) {
      q->unk_662 = 300;
      CLEAR_FLAGS(q->unk_660, 4);
    } else if (q->unk_662 != 0) {
      q->unk_662--;
    } else {
      q->unk_662 = 300;
      if (!Spider_TestUnk660(q, 4)) {
        FUN_08130508(p);
      }
    }
  }
}

NAKED void FUN_0813069c(Spider* p) { INCFUNC("asm/func/FUN_0813069c.inc"); }

NAKED void FUN_081307b0(Spider* p) { INCFUNC("asm/func/FUN_081307b0.inc"); }

bool8 FUN_081309f0(Spider* p) {
  if ((p->e).hitTargetID > 0) {
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
    FUN_08130eec(p);
    Enemy_StepTowardPathNode(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
    return TRUE;
  }
  return FALSE;
}

NAKED bool8 FUN_08130ac4(Spider* p) { INCFUNC("asm/func/FUN_08130ac4.inc"); }

NAKED bool8 FUN_08130d34(Spider* p) { INCFUNC("asm/func/FUN_08130d34.inc"); }

NAKED void FUN_08130eec(Spider* p) { INCFUNC("asm/func/FUN_08130eec.inc"); }

void Spider_PickRandomPathNode(Spider* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

// 歩きアニメのコマが変わる瞬間だけ移動の速さを返す
s32 Spider_GetMoveSpeed(Spider* p) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    return u16_ARRAY_085ad70c[anim->cmdIdx & 1];
  }
  return 0;
}

s32 FUN_081310b8(Spider* p) {
  FUN_0812f818(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  return 1;
}

s32 Spider_Update(Spider* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Spider_Destroy(Spider* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (!(p->e).unk_44c) {
    AuxShadow_Remove(&(p->e).auxShadow);
  }
  FUN_08002a58(&(p->e).mover);
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Spider_Init(Spider* p) { INCFUNC("asm/func/Spider_Init.inc"); }

void Spider_Create(void) {
  Spider* p = Malloc(sizeof(Spider));

  if (p != NULL) {
    ClearMemory(p, sizeof(Spider));
    if (Spider_Init(p) < 0) {
      Spider_Destroy(p);
      Free(p);
    }
  }
}
