#include "entity.h"
#include "global.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "vm.h"

// 通信対戦の自キャラ?

NAKED void FUN_08080c64(Player* p) { INCFUNC("asm/func/FUN_08080c64.inc"); }

NAKED void FUN_08080cac(Player* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_08080cac.inc"); }

NAKED void FUN_08080d2c(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_08080d2c.inc"); }

void FUN_08080e0c(Player* p, u8 action, u8 state) {
  p->action = action;
  p->state = state;
  p->stateTimer = 0;
}

NAKED void FUN_08080e34(Player* param_1) { INCFUNC("asm/func/FUN_08080e34.inc"); }

void FUN_08080ec8(Player* p, u32 bits) { p->unk_35a |= bits; }

u32 FUN_08080ed8(Player* p, u16 bits) { return p->unk_35a & bits; }

// サバタのときだけ3つの音を鳴らす
void FUN_08080ee8(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    sound_08240740(0xD8);
  } else {
    sound_08240740(0x239);
    sound_08240740(0x202);
    sound_08240740(0x366);
  }
}

NAKED s32 FUN_08080f20(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_08080f20.inc"); }

NAKED void FUN_08080f80(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08080f80.inc"); }

NAKED s32 FUN_080810a4(Player* p) { INCFUNC("asm/func/FUN_080810a4.inc"); }

NAKED s32 FUN_080810f8(void) { INCFUNC("asm/func/FUN_080810f8.inc"); }

NAKED void FUN_08081118(Player* p, u32 param_2) { INCFUNC("asm/func/FUN_08081118.inc"); }

void FUN_08081150(Player* p, u32 bits) { p->unk_9bc |= bits; }

u32 FUN_08081160(Player* p, u16 bits) { return p->unk_9bc & bits; }

void FUN_08081170(Player* p) {
  if (p->scriptID_9c0 != 0) {
    VM_ExecByID(p->scriptID_9c0, NULL);
  }
}

NAKED void FUN_08081188(Player* p) { INCFUNC("asm/func/FUN_08081188.inc"); }

NAKED s32 FUN_08081240(Player* p) { INCFUNC("asm/func/FUN_08081240.inc"); }

NAKED void FUN_0808128c(s32 param_1) { INCFUNC("asm/func/FUN_0808128c.inc"); }

NAKED void FUN_080812d4(s32 param_1, unknown* param_2, s32 param_3, s32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_080812d4.inc"); }

NAKED void FUN_080813d0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080813d0.inc"); }

NAKED void FUN_080815ac(s32 param_1) { INCFUNC("asm/func/FUN_080815ac.inc"); }

NAKED s32 FUN_080815f0(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_080815f0.inc"); }

NAKED void FUN_08081628(Player* p) { INCFUNC("asm/func/FUN_08081628.inc"); }

void FUN_0808168c(Player* p) { ParticleShadow_Remove(&p->shadow); }

NAKED void FUN_080816a0(Player* p) { INCFUNC("asm/func/FUN_080816a0.inc"); }

NAKED void FUN_0808175c(Player* p) { INCFUNC("asm/func/FUN_0808175c.inc"); }

NAKED s32 FUN_080817ec(Player* p) { INCFUNC("asm/func/FUN_080817ec.inc"); }

NAKED void FUN_08081830(s32 param_1) { INCFUNC("asm/func/FUN_08081830.inc"); }

NAKED void* FUN_08081ab0(Player* p, void* r1) { INCFUNC("asm/func/FUN_08081ab0.inc"); }

NAKED void FUN_08081c04(Player* p) { INCFUNC("asm/func/FUN_08081c04.inc"); }

NAKED void FUN_08081d18(Player* p, s16 param_2) { INCFUNC("asm/func/FUN_08081d18.inc"); }

NAKED s32 FUN_08081da4(Player* p) { INCFUNC("asm/func/FUN_08081da4.inc"); }

NAKED s32 FUN_08081de0(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_08081de0.inc"); }

// 行動中なら行動を止めてから FUN_08080cac を呼ぶ
void FUN_08081f80(Player* p) {
  if (p->action) {
    FUN_08080e0c(p, 0, 0);
    FUN_08080c64(p);
  }

  FUN_08080cac(p, 0x19E, 0x40);
}

NAKED void FUN_08081fb4(Player* p) { INCFUNC("asm/func/FUN_08081fb4.inc"); }

// 日光が当たっていなくて EN に余裕があるか
s32 FUN_08082124(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_UNK_4) && p->ene < p->maxEne) {
    return 1;
  }

  return 0;
}

NAKED void FUN_08082154(Player* p) { INCFUNC("asm/func/FUN_08082154.inc"); }

// unk_3fe で unk_35a に立てるビットを選ぶ
void FUN_08082464(Player* p) {
  if (p->unk_3fe) {
    FUN_08080ec8(p, 0x3C);
  } else {
    FUN_08080ec8(p, 0x3D);
  }

  Player_SetFlag20(p, PFLAG20_UNK_12);
}

NAKED void FUN_08082498(Player* p) { INCFUNC("asm/func/FUN_08082498.inc"); }

NAKED void FUN_08082670(Player* p) { INCFUNC("asm/func/FUN_08082670.inc"); }

NAKED void FUN_08082970(Player* p) { INCFUNC("asm/func/FUN_08082970.inc"); }

NAKED void FUN_08082a94(Player* p) { INCFUNC("asm/func/FUN_08082a94.inc"); }

NAKED void FUN_08082bdc(Player* p) { INCFUNC("asm/func/FUN_08082bdc.inc"); }

NAKED void FUN_08082dac(Player* p) { INCFUNC("asm/func/FUN_08082dac.inc"); }

NAKED void FUN_0808301c(Player* p) { INCFUNC("asm/func/FUN_0808301c.inc"); }

NAKED void FUN_080831e0(Player* p, s32 param_2, u16 param_3, u16 param_4) { INCFUNC("asm/func/FUN_080831e0.inc"); }

NAKED void FUN_080832b8(Player* p) { INCFUNC("asm/func/FUN_080832b8.inc"); }

NAKED void FUN_080835d8(Player* p) { INCFUNC("asm/func/FUN_080835d8.inc"); }

NAKED s32 FUN_08083eac(Player* p) { INCFUNC("asm/func/FUN_08083eac.inc"); }

NAKED void FUN_08084078(s32 param_1) { INCFUNC("asm/func/FUN_08084078.inc"); }

NAKED void FUN_08084330(Player* p) { INCFUNC("asm/func/FUN_08084330.inc"); }

NAKED void FUN_080843ac(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080843ac.inc"); }

NAKED void FUN_08084540(Player* p) { INCFUNC("asm/func/FUN_08084540.inc"); }

NAKED s32 LinkPlayer_Update(Player* p) { INCFUNC("asm/func/LinkPlayer_Update.inc"); }

NAKED s32 LinkPlayer_Destroy(Player* p) { INCFUNC("asm/func/LinkPlayer_Destroy.inc"); }

NAKED s32 LinkPlayer_Init(Player* p, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/LinkPlayer_Init.inc"); }

NAKED Player* LinkPlayer_Create(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/LinkPlayer_Create.inc"); }
