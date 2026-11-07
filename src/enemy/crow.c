#include "enemy.h"
#include "global.h"
#include "malloc.h"
#include "player.h"

// クロウ(ENEID_CROW), ガーゴイル(ENEID_GARGOYLE)
typedef struct {
  Enemy e;
  u8 unk_654[1728 - sizeof(Enemy)];
} Crow;
static_assert(sizeof(Crow) == 1728);

void FUN_081436b4(Crow*);
void FUN_081439d8(Crow*);
void FUN_08143dd4(Crow*);
void FUN_08143ef8(Crow*);
void FUN_08143fac(Crow*);
void FUN_08144cd0(Crow*);
void FUN_08144ec8(Crow*);
void FUN_081452cc(Crow*);

void (*const PTR_ARRAY_085ad828[5])(Crow*) = {
    FUN_08143dd4,
    FUN_081439d8,
    FUN_081436b4,
    FUN_08143ef8,
    FUN_08143fac,
};  // 0x085AD828

const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

void (*const PTR_ARRAY_085ad84c[3])(Crow*) = {
    FUN_08144cd0,
    FUN_08144ec8,
    FUN_081452cc,
};  // 0x085AD84C

void FUN_08144160(Crow*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad858[7])(Crow*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08144160,
};  // 0x085AD858

NAKED void Crow_OnHit(HitboxData* a, HitboxData* b, Crow* p) { INCFUNC("asm/func/Crow_OnHit.inc"); }

NAKED void Crow_OnHurt(HitboxData* a, HitboxData* b, Crow* p) { INCFUNC("asm/func/Crow_OnHurt.inc"); }

NAKED void FUN_08142fd8(Crow* p) { INCFUNC("asm/func/FUN_08142fd8.inc"); }

NAKED void FUN_08143004(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_08143004.inc"); }

NAKED void FUN_08143094(Crow* p) { INCFUNC("asm/func/FUN_08143094.inc"); }

NAKED void FUN_0814312c(Crow* p) { INCFUNC("asm/func/FUN_0814312c.inc"); }

NAKED void FUN_081431e0(Crow* p) { INCFUNC("asm/func/FUN_081431e0.inc"); }

NAKED void FUN_081432ec(Crow* p) { INCFUNC("asm/func/FUN_081432ec.inc"); }

NAKED void FUN_08143310(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_08143310.inc"); }

NAKED void FUN_081434e0(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_081434e0.inc"); }

NAKED void FUN_081436b4(Crow* p) { INCFUNC("asm/func/FUN_081436b4.inc"); }

NAKED void FUN_081439d8(Crow* p) { INCFUNC("asm/func/FUN_081439d8.inc"); }

NAKED void FUN_08143dd4(Crow* p) { INCFUNC("asm/func/FUN_08143dd4.inc"); }

NAKED void FUN_08143ef8(Crow* p) { INCFUNC("asm/func/FUN_08143ef8.inc"); }

NAKED void FUN_08143fac(Crow* p) { INCFUNC("asm/func/FUN_08143fac.inc"); }

NAKED void FUN_0814414c(Crow* p) { INCFUNC("asm/func/FUN_0814414c.inc"); }

NAKED void FUN_08144160(Crow* p, u16* msg) { INCFUNC("asm/func/FUN_08144160.inc"); }

NAKED void Crow_OnReset(Crow* p) { INCFUNC("asm/func/Crow_OnReset.inc"); }

NAKED void FUN_08144414(Crow* p) { INCFUNC("asm/func/FUN_08144414.inc"); }

NAKED void FUN_08144608(Crow* p) { INCFUNC("asm/func/FUN_08144608.inc"); }

NAKED void Crow_InitHitboxes(Crow* p) { INCFUNC("asm/func/Crow_InitHitboxes.inc"); }

NAKED s32 FUN_081446fc(Crow* p) { INCFUNC("asm/func/FUN_081446fc.inc"); }

NAKED void FUN_0814472c(Crow* p, Vec3* pos) { INCFUNC("asm/func/FUN_0814472c.inc"); }

NAKED void Crow_InitAnims(Crow* p) { INCFUNC("asm/func/Crow_InitAnims.inc"); }

NAKED void FUN_081447cc(Crow* p) { INCFUNC("asm/func/FUN_081447cc.inc"); }

NAKED void FUN_0814480c(u16 angle, s32* outX, s32* outY) { INCFUNC("asm/func/FUN_0814480c.inc"); }

NAKED void FUN_0814483c(Crow* p, Vec3* pos) { INCFUNC("asm/func/FUN_0814483c.inc"); }

NAKED void FUN_081448d8(Crow* p) { INCFUNC("asm/func/FUN_081448d8.inc"); }

NAKED void FUN_08144910(Crow* p) { INCFUNC("asm/func/FUN_08144910.inc"); }

NAKED void FUN_081449f8(Crow* p) { INCFUNC("asm/func/FUN_081449f8.inc"); }

NAKED void FUN_08144b70(Crow* p) { INCFUNC("asm/func/FUN_08144b70.inc"); }

NAKED bool8 FUN_08144b90(Crow* p) { INCFUNC("asm/func/FUN_08144b90.inc"); }

NAKED void FUN_08144bfc(Crow* p) { INCFUNC("asm/func/FUN_08144bfc.inc"); }

s32 FUN_08144cb8(Crow* p) {
  FUN_08144414(p);
  return 1;
}

s32 FUN_08144cc4(Crow* p) {
  FUN_081449f8(p);
  return 1;
}

NAKED void FUN_08144cd0(Crow* p) { INCFUNC("asm/func/FUN_08144cd0.inc"); }

NAKED void FUN_08144ec8(Crow* p) { INCFUNC("asm/func/FUN_08144ec8.inc"); }

NAKED void FUN_081452cc(Crow* p) { INCFUNC("asm/func/FUN_081452cc.inc"); }

NAKED void FUN_08145424(Crow* p) { INCFUNC("asm/func/FUN_08145424.inc"); }

NAKED s32 FUN_08145438(Crow* p) { INCFUNC("asm/func/FUN_08145438.inc"); }

s32 Crow_Update(Crow* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

NAKED s32 Crow_Destroy(Crow* p) { INCFUNC("asm/func/Crow_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Crow_Init(Crow* p) { INCFUNC("asm/func/Crow_Init.inc"); }

NAKED void Crow_Create(void) { INCFUNC("asm/func/Crow_Create.inc"); }
