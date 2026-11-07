#include "enemy.h"
#include "global.h"
#include "malloc.h"
#include "player.h"

// バット(ENEID_BAT), ヴァンパイアバット(ENEID_VBAT)
// ヴァンパイアバット は 吸血攻撃をしてくる
// プレイヤーが変身するCバット(PLAYER_BAT)などと混同しない様に構造体名は Bat ではなく EnemyBat にした
typedef struct {
  Enemy e;
  u8 unk_654[1728 - sizeof(Enemy)];
} EnemyBat;
static_assert(sizeof(EnemyBat) == 1728);

void FUN_0813f9a8(EnemyBat*);
void FUN_0813fbf8(EnemyBat*);
void FUN_0813fc9c(EnemyBat*);
void FUN_0813fd24(EnemyBat*);
void FUN_0813fe34(EnemyBat*);
void FUN_08140eb0(EnemyBat*);
void FUN_081410cc(EnemyBat*);

void (*const PTR_ARRAY_085ad7d0[5])(EnemyBat*) = {
    FUN_0813fc9c,
    FUN_0813fbf8,
    FUN_0813f9a8,
    FUN_0813fd24,
    FUN_0813fe34,
};  // 0x085AD7D0

const u32 u32_ARRAY_085ad7e4[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085AD7E4

void (*const PTR_ARRAY_085ad804[2])(EnemyBat*) = {
    FUN_08140eb0,
    FUN_081410cc,
};  // 0x085AD804

void FUN_08140278(EnemyBat*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad80c[7])(EnemyBat*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08140278,
};  // 0x085AD80C

NAKED void EnemyBat_OnHit(HitboxData* a, HitboxData* b, EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnHit.inc"); }

NAKED void EnemyBat_OnHurt(HitboxData* a, HitboxData* b, EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnHurt.inc"); }

NAKED void FUN_0813f06c(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f06c.inc"); }

NAKED void FUN_0813f180(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f180.inc"); }

NAKED void FUN_0813f1f0(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f1f0.inc"); }

NAKED void FUN_0813f268(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f268.inc"); }

NAKED void FUN_0813f2a8(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f2a8.inc"); }

NAKED void FUN_0813f2fc(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f2fc.inc"); }

NAKED void FUN_0813f320(EnemyBat* p, s32 timer) { INCFUNC("asm/func/FUN_0813f320.inc"); }

NAKED void FUN_0813f44c(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f44c.inc"); }

NAKED void FUN_0813f5fc(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f5fc.inc"); }

NAKED void FUN_0813f7d4(EnemyBat* p, s32 timer) { INCFUNC("asm/func/FUN_0813f7d4.inc"); }

NAKED void FUN_0813f9a8(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f9a8.inc"); }

NAKED void FUN_0813fbf8(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fbf8.inc"); }

NAKED void FUN_0813fc9c(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fc9c.inc"); }

NAKED void FUN_0813fd24(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fd24.inc"); }

NAKED void FUN_0813fe34(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fe34.inc"); }

void FUN_08140014(EnemyBat* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad7d0; }

NAKED void EnemyBat_OnReset(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnReset.inc"); }

NAKED void FUN_08140278(EnemyBat* p, u16* msg) { INCFUNC("asm/func/FUN_08140278.inc"); }

NAKED void FUN_0814031c(EnemyBat* p) { INCFUNC("asm/func/FUN_0814031c.inc"); }

NAKED void FUN_081404c0(EnemyBat* p) { INCFUNC("asm/func/FUN_081404c0.inc"); }

NAKED void FUN_08140520(EnemyBat* p) { INCFUNC("asm/func/FUN_08140520.inc"); }

NAKED void EnemyBat_InitHitboxes(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_InitHitboxes.inc"); }

NAKED s32 FUN_08140614(EnemyBat* p) { INCFUNC("asm/func/FUN_08140614.inc"); }

NAKED void FUN_08140680(EnemyBat* p, Vec3* pos) { INCFUNC("asm/func/FUN_08140680.inc"); }

NAKED u8 FUN_081406b8(EnemyBat* p) { INCFUNC("asm/func/FUN_081406b8.inc"); }

void EnemyBat_InitAnims(EnemyBat* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 3, 1, 0);
  Enemy_SetAnimEntry(&p->e, 15, 2, 0);
  Enemy_SetAnimEntry(&p->e, 16, 3, 0);
  Enemy_SetAnimEntry(&p->e, 17, 4, 0);
  Enemy_SetAnimEntry(&p->e, 18, 5, 0);
  Enemy_SetAnimEntry(&p->e, 10, 1, 0);
}

NAKED void FUN_08140904(EnemyBat* p) { INCFUNC("asm/func/FUN_08140904.inc"); }

NAKED void FUN_08140940(u16 angle, s32* outX, s32* outY) { INCFUNC("asm/func/FUN_08140940.inc"); }

NAKED void FUN_08140970(EnemyBat* p, Vec3* pos) { INCFUNC("asm/func/FUN_08140970.inc"); }

NAKED void FUN_08140a10(EnemyBat* p) { INCFUNC("asm/func/FUN_08140a10.inc"); }

NAKED void FUN_08140a48(EnemyBat* p) { INCFUNC("asm/func/FUN_08140a48.inc"); }

NAKED void FUN_08140b30(EnemyBat* p) { INCFUNC("asm/func/FUN_08140b30.inc"); }

NAKED void FUN_08140c14(EnemyBat* p) { INCFUNC("asm/func/FUN_08140c14.inc"); }

NAKED bool8 FUN_08140cd4(EnemyBat* p) { INCFUNC("asm/func/FUN_08140cd4.inc"); }

NAKED void FUN_08140d48(EnemyBat* p) { INCFUNC("asm/func/FUN_08140d48.inc"); }

NAKED void FUN_08140dd0(EnemyBat* p) { INCFUNC("asm/func/FUN_08140dd0.inc"); }

s32 FUN_08140ea0(EnemyBat* p) {
  FUN_0814031c(p);
  return 1;
}

s32 FUN_08140eac(EnemyBat* p) { return 1; }

NAKED void FUN_08140eb0(EnemyBat* p) { INCFUNC("asm/func/FUN_08140eb0.inc"); }

NAKED void FUN_081410cc(EnemyBat* p) { INCFUNC("asm/func/FUN_081410cc.inc"); }

void FUN_08141448(EnemyBat* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad804; }

NAKED s32 FUN_0814145c(EnemyBat* p) { INCFUNC("asm/func/FUN_0814145c.inc"); }

s32 EnemyBat_Update(EnemyBat* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

NAKED s32 EnemyBat_Destroy(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 EnemyBat_Init(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Init.inc"); }

void EnemyBat_Create(void) {
  EnemyBat* p = Malloc(sizeof(EnemyBat));

  if (p != NULL) {
    ClearMemory(p, sizeof(EnemyBat));
    if (EnemyBat_Init(p) < 0) {
      EnemyBat_Destroy(p);
      Free(p);
    }
  }
}
