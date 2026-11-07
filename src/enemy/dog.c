#include "enemy.h"
#include "global.h"
#include "malloc.h"

// バンデット(ENEID_BANDIT), ヘルハウンド(ENEID_HELLHOUND), グレイブキーパー(ENEID_GRAVEKEEPER)
// 共通の特徴として におい でサーチする (処理の上でどうしているのかはまだ不明)
// バンデットは攻撃時にプレイヤーからアイテムを奪う, ヘルハウンドはファイヤーブレスを吐く
typedef struct {
  Enemy e;
  u8 unk_654[1808 - sizeof(Enemy)];
} Dog;
static_assert(sizeof(Dog) == 1808);

const u16 u16_ARRAY_085ad8c0[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AD8C0

void FUN_0814fba4(Dog*);
void FUN_0814fc7c(Dog*);
void FUN_08150534(Dog*);
void FUN_08150660(Dog*);
void FUN_08150790(Dog*);
void FUN_08150b18(Dog*);
void FUN_08150de8(Dog*);
void FUN_081514f0(Dog*);
void FUN_081516d8(Dog*);
void FUN_081517a8(Dog*);

void (*const PTR_ARRAY_085ad8e0[2])(Dog*) = {
    FUN_0814fba4,
    FUN_0814fc7c,
};  // 0x085AD8E0

void (*const PTR_ARRAY_085ad8e8[2])(Dog*) = {
    FUN_08150534,
    FUN_08150660,
};  // 0x085AD8E8

// clang-format off
void (*const PTR_ARRAY_085ad8f0[20])(Dog*) = {
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
    FUN_08150de8,
    FUN_08150790,
    FUN_08150b18,
    FUN_081514f0,
    FUN_081516d8,
    FUN_081517a8,
};  // 0x085AD8F0
// clang-format on

NAKED void enemy_dog_08149f6c(Dog* p) { INCFUNC("asm/func/enemy_dog_08149f6c.inc"); }

NAKED void FUN_0814a098(Dog* p) { INCFUNC("asm/func/FUN_0814a098.inc"); }

NAKED void enemy_dog_0814a320(Dog* p) { INCFUNC("asm/func/enemy_dog_0814a320.inc"); }

NAKED bool8 FUN_0814a5e0(Dog* p, u32 angle) { INCFUNC("asm/func/FUN_0814a5e0.inc"); }

NAKED void Dog_InitAnims(Dog* p) { INCFUNC("asm/func/Dog_InitAnims.inc"); }

NAKED void Dog_OnReset(Dog* p) { INCFUNC("asm/func/Dog_OnReset.inc"); }

void FUN_0814a8c8(Dog* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

NAKED s32 FUN_0814a8dc(Dog* p) { INCFUNC("asm/func/FUN_0814a8dc.inc"); }

NAKED void FUN_0814aad4(Dog* p) { INCFUNC("asm/func/FUN_0814aad4.inc"); }

NAKED void Dog_InitHitboxes(Dog* p) { INCFUNC("asm/func/Dog_InitHitboxes.inc"); }

NAKED void FUN_0814ac10(Dog* p) { INCFUNC("asm/func/FUN_0814ac10.inc"); }

NAKED void FUN_0814ae80(Dog* p) { INCFUNC("asm/func/FUN_0814ae80.inc"); }

NAKED void FUN_0814aeb0(Dog* p) { INCFUNC("asm/func/FUN_0814aeb0.inc"); }

NAKED void FUN_0814aed0(Dog* p) { INCFUNC("asm/func/FUN_0814aed0.inc"); }

NAKED void FUN_0814afc8(Dog* p) { INCFUNC("asm/func/FUN_0814afc8.inc"); }

NAKED bool8 FUN_0814b090(Dog* p, u32 angle) { INCFUNC("asm/func/FUN_0814b090.inc"); }

NAKED u8 FUN_0814b3a0(Dog* p) { INCFUNC("asm/func/FUN_0814b3a0.inc"); }

NAKED bool8 FUN_0814b3e0(Dog* p) { INCFUNC("asm/func/FUN_0814b3e0.inc"); }

NAKED void enemy_dog_0814b500(Dog* p) { INCFUNC("asm/func/enemy_dog_0814b500.inc"); }

NAKED void FUN_0814b78c(Dog* p) { INCFUNC("asm/func/FUN_0814b78c.inc"); }

NAKED void FUN_0814b7a4(Vec3* pos) { INCFUNC("asm/func/FUN_0814b7a4.inc"); }

NAKED void Dog_OnHit(HitboxData* a, HitboxData* b, Dog* p) { INCFUNC("asm/func/Dog_OnHit.inc"); }

NAKED void FUN_0814b89c(HitboxData* a, HitboxData* b, Dog* p) { INCFUNC("asm/func/FUN_0814b89c.inc"); }

NAKED void Dog_OnHurt(HitboxData* a, HitboxData* b, Dog* p) { INCFUNC("asm/func/Dog_OnHurt.inc"); }

NAKED void FUN_0814c28c(Dog* p) { INCFUNC("asm/func/FUN_0814c28c.inc"); }

NAKED void FUN_0814c2b0(Dog* p) { INCFUNC("asm/func/FUN_0814c2b0.inc"); }

NAKED void FUN_0814c2d4(Dog* p) { INCFUNC("asm/func/FUN_0814c2d4.inc"); }

void FUN_0814c970(Dog* p) {}

NAKED void FUN_0814c974(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814c974.inc"); }

NAKED void FUN_0814ca30(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814ca30.inc"); }

NAKED void FUN_0814caa0(Dog* p) { INCFUNC("asm/func/FUN_0814caa0.inc"); }

NAKED void FUN_0814cb8c(Dog* p) { INCFUNC("asm/func/FUN_0814cb8c.inc"); }

NAKED void FUN_0814ccfc(Dog* p) { INCFUNC("asm/func/FUN_0814ccfc.inc"); }

NAKED void FUN_0814dd38(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814dd38.inc"); }

NAKED void FUN_0814de34(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814de34.inc"); }

NAKED void FUN_0814deb0(Dog* p) { INCFUNC("asm/func/FUN_0814deb0.inc"); }

NAKED void FUN_0814df40(Dog* p) { INCFUNC("asm/func/FUN_0814df40.inc"); }

NAKED void FUN_0814e1b0(Dog* p) { INCFUNC("asm/func/FUN_0814e1b0.inc"); }

NAKED void FUN_0814e1fc(Dog* p) { INCFUNC("asm/func/FUN_0814e1fc.inc"); }

NAKED void FUN_0814e248(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814e248.inc"); }

void FUN_0814e420(Dog* p) {}

NAKED void FUN_0814e424(Dog* p) { INCFUNC("asm/func/FUN_0814e424.inc"); }

NAKED void FUN_0814e530(Dog* p) { INCFUNC("asm/func/FUN_0814e530.inc"); }

NAKED void FUN_0814e680(Dog* p) { INCFUNC("asm/func/FUN_0814e680.inc"); }

NAKED void FUN_0814e8ec(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814e8ec.inc"); }

NAKED bool8 FUN_0814eacc(Dog* p) { INCFUNC("asm/func/FUN_0814eacc.inc"); }

NAKED void FUN_0814fba4(Dog* p) { INCFUNC("asm/func/FUN_0814fba4.inc"); }

NAKED void FUN_0814fc7c(Dog* p) { INCFUNC("asm/func/FUN_0814fc7c.inc"); }

void FUN_081504e8(Dog* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad8e0; }

s32 FUN_081504f8(Dog* p) {
  FUN_0814aad4(p);
  FUN_0814aed0(p);
  return 1;
}

s32 FUN_08150510(Dog* p) {
  FUN_0814ac10(p);
  FUN_0814ae80(p);
  FUN_0814aeb0(p);
  FUN_0814b78c(p);
  return 1;
}

NAKED void FUN_08150534(Dog* p) { INCFUNC("asm/func/FUN_08150534.inc"); }

NAKED void FUN_08150660(Dog* p) { INCFUNC("asm/func/FUN_08150660.inc"); }

NAKED void FUN_0815077c(Dog* p) { INCFUNC("asm/func/FUN_0815077c.inc"); }

NAKED void FUN_08150790(Dog* p) { INCFUNC("asm/func/FUN_08150790.inc"); }

NAKED void FUN_08150b18(Dog* p) { INCFUNC("asm/func/FUN_08150b18.inc"); }

NAKED void FUN_08150de8(Dog* p) { INCFUNC("asm/func/FUN_08150de8.inc"); }

NAKED void FUN_081514f0(Dog* p) { INCFUNC("asm/func/FUN_081514f0.inc"); }

NAKED void FUN_081516d8(Dog* p) { INCFUNC("asm/func/FUN_081516d8.inc"); }

NAKED void FUN_081517a8(Dog* p) { INCFUNC("asm/func/FUN_081517a8.inc"); }

NAKED void FUN_081518ac(Dog* p) { INCFUNC("asm/func/FUN_081518ac.inc"); }

NAKED s32 FUN_081518c0(Dog* p) { INCFUNC("asm/func/FUN_081518c0.inc"); }

s32 Dog_Update(Dog* p) {
  Enemy_Update(&p->e);
  return 0;
}

NAKED s32 Dog_Destroy(Dog* p) { INCFUNC("asm/func/Dog_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Dog_Init(Dog* p) { INCFUNC("asm/func/Dog_Init.inc"); }

NAKED void Dog_Create(void) { INCFUNC("asm/func/Dog_Create.inc"); }
