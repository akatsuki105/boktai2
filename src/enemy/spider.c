#include "enemy.h"
#include "enemy_inline.h"
#include "global.h"
#include "malloc.h"

// スパイダー(ENEID_SPIDER), ポイズンスパイダー(ENEID_PSPIDER)
// 見えない蜘蛛の巣を仕掛けて、プレイヤーがそれに触れると身動きが取れなくなる
// ポイズンスパイダーは毒液も吐く
typedef struct {
  Enemy e;
  u8 unk_654[1680 - sizeof(Enemy)];
} Spider;
static_assert(sizeof(Spider) == 1680);

void FUN_080e8614(Enemy* p);
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

NAKED void Spider_OnHit(HitboxData* a, HitboxData* b, Spider* p) { INCFUNC("asm/func/Spider_OnHit.inc"); }

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

NAKED void FUN_0812f358(Spider* p) { INCFUNC("asm/func/FUN_0812f358.inc"); }

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

NAKED void FUN_0812fbec(Spider* p) { INCFUNC("asm/func/FUN_0812fbec.inc"); }

NAKED void FUN_0812fcd8(Spider* p) { INCFUNC("asm/func/FUN_0812fcd8.inc"); }

NAKED void FUN_0812fdb8(Spider* p) { INCFUNC("asm/func/FUN_0812fdb8.inc"); }

NAKED void FUN_08130068(Spider* p) { INCFUNC("asm/func/FUN_08130068.inc"); }

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

NAKED void FUN_08130460(Spider* p) { INCFUNC("asm/func/FUN_08130460.inc"); }

NAKED bool8 FUN_081304a8(Spider* p, s32 rangeX, s32 rangeZ) { INCFUNC("asm/func/FUN_081304a8.inc"); }

NAKED bool8 FUN_08130508(Spider* p) { INCFUNC("asm/func/FUN_08130508.inc"); }

NAKED void FUN_08130610(Spider* p) { INCFUNC("asm/func/FUN_08130610.inc"); }

NAKED void FUN_0813069c(Spider* p) { INCFUNC("asm/func/FUN_0813069c.inc"); }

NAKED void FUN_081307b0(Spider* p) { INCFUNC("asm/func/FUN_081307b0.inc"); }

NAKED bool8 FUN_081309f0(Spider* p) { INCFUNC("asm/func/FUN_081309f0.inc"); }

NAKED bool8 FUN_08130ac4(Spider* p) { INCFUNC("asm/func/FUN_08130ac4.inc"); }

NAKED bool8 FUN_08130d34(Spider* p) { INCFUNC("asm/func/FUN_08130d34.inc"); }

NAKED void FUN_08130eec(Spider* p) { INCFUNC("asm/func/FUN_08130eec.inc"); }

NAKED void FUN_0813101c(Spider* p) { INCFUNC("asm/func/FUN_0813101c.inc"); }

NAKED s32 FUN_0813107c(Spider* p) { INCFUNC("asm/func/FUN_0813107c.inc"); }

NAKED s32 FUN_081310b8(Spider* p) { INCFUNC("asm/func/FUN_081310b8.inc"); }

s32 Spider_Update(Spider* p) {
  Enemy_Update(&p->e);
  return 0;
}

NAKED s32 Spider_Destroy(Spider* p) { INCFUNC("asm/func/Spider_Destroy.inc"); }

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
