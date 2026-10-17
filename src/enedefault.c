#include "enemy.h"
#include "enemy_target.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"

// Enemy の共通部分?
// 原典のファイル名は enedefault.c, 根拠: FUN_080f00ec / FUN_080f0430 が、抜き取られた assert の引数として文字列 "enedefault.c" (0x08251F80) と行番号を積む

typedef u16 EnemyFlags222;       // Enemy.unk_222
#define ENEMY222_UNK_0 (1 << 0)  // FUN_080f624c が unk_1e4 < 0x100000 のときだけ立てる

extern u32 u32_03002bc0;

void FUN_080f22e8(Enemy* p);
void FUN_080f230c(Enemy* p);
void FUN_080f2330(Enemy* p);
void FUN_080f229c(Enemy* p);

const EnemyHandler gEnemyHandlerTable0[4] = {
    FUN_080f22e8,
    FUN_080f230c,
    FUN_080f2330,
    FUN_080f229c,
};  // 0x085AD3D4

void FUN_080f34ec(Enemy* p);
void FUN_080f35fc(Enemy* p);
void FUN_080f3574(Enemy* p);

const EnemyHandler gEnemyHandlerTable1[3] = {
    FUN_080f34ec,
    FUN_080f35fc,
    FUN_080f3574,
};  // 0x085AD3E4

void FUN_080f2644(Enemy* p);
void FUN_080f2864(Enemy* p);
void FUN_080f248c(Enemy* p);
void FUN_080f2364(Enemy* p);
void FUN_080f2ec0(Enemy* p);
void FUN_080f2d04(Enemy* p);
void FUN_080f2a40(Enemy* p);
void FUN_080f31c4(Enemy* p);
void FUN_080f19cc(Enemy* p);
void FUN_080f33e8(Enemy* p);
void FUN_080f34a0(Enemy* p);
void FUN_080f0e78(Enemy* p);
void FUN_080f11d0(Enemy* p);
void FUN_080f12c4(Enemy* p);

const EnemyHandler gEnemyHandlerTable2[15] = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_080f12c4,
};  // 0x085AD3F0

const EnemyHandler gEnemyHandlerTable3[1] = {
    NULL,
};  // 0x085AD42C

const EnemyHandler gEnemyHandlerTable4[1] = {
    NULL,
};  // 0x085AD430

void FUN_080f2254(Enemy* p);

const EnemyHandler gEnemyHandlerTable5[1] = {
    FUN_080f2254,
};  // 0x085AD434

void FUN_080f1c54(Enemy* p);
void FUN_080f1cb8(Enemy* p);
void FUN_080f1cf0(Enemy* p);

const EnemyHandler gEnemyHandlerTable6[3] = {
    FUN_080f1c54,
    FUN_080f1cb8,
    FUN_080f1cf0,
};  // 0x085AD438

void FUN_080f2278(Enemy* p);

const EnemyHandler gEnemyHandlerTable7[1] = {
    FUN_080f2278,
};  // 0x085AD444

void FUN_080f1de4(Enemy* p);
void FUN_080f1e0c(Enemy* p);
void FUN_080f1e78(Enemy* p);
void FUN_080f1ef8(Enemy* p);
void FUN_080f2074(Enemy* p);
void FUN_080f2160(Enemy* p);

const EnemyHandler gEnemyHandlerTable8[6] = {
    FUN_080f1de4,
    FUN_080f1e0c,
    FUN_080f1e78,
    FUN_080f1ef8,
    FUN_080f2074,
    FUN_080f2160,
};  // 0x085AD448

void FUN_080f22c0(Enemy* p);
void FUN_080f22c4(Enemy* p);

const EnemyHandler gEnemyHandlerTable9[2] = {
    FUN_080f22c0,
    FUN_080f22c4,
};  // 0x085AD460

static inline u32 TestFlag030047a4(u32 flags) { return (gFlag030047a4 | u32_030047a0) & flags; }

static inline u32 TestFlag03002bc0(u32 flags) { return u32_03002bc0 & flags; }

// 状態を指定の組に戻して経過フレームを0に巻き戻す, unk_46c は巻き戻した印
static inline void Enemy_ResetState(Enemy* p, u8 state, u8 unk_469, u8 step) {
  p->unk_468 = state;
  p->unk_469 = unk_469;
  p->unk_46a = step;
  p->unk_484 = 0;
  p->unk_46c = 1;
}

// 状態ハンドラを差し替えて入場フラグを立てる
static inline void Enemy_EnterState(Enemy* p, void* handler, u8 state) {
  p->stateBegun = TRUE;
  p->unk_46b = 0;
  p->state = state;
  p->handlerState = handler;
  p->unk_1c8 = 0;
}

static inline void Enemy_SetFlags222(Enemy* p, EnemyFlags222 bits) { p->unk_222 |= bits; }
static inline void Enemy_ClearFlags222(Enemy* p, EnemyFlags222 bits) { p->unk_222 &= ~bits; }

void FUN_080ee738(Enemy* p);
void FUN_080e4a68(Enemy* p);
void FUN_080ee2c8(Enemy* p);
bool8 FUN_080f3718(Enemy* p);
void Entity4B15_ShowTrackingMarker(s32 playerIdx, Vec3* pos);
s32 FUN_080d9a9c(void* p, u32 param_2, u32 param_3);
void FUN_080e5098(Enemy* p, s32 param_2, s32 param_3);
void FUN_080e499c(Enemy* p);
void FUN_080e5718(Enemy* p, s32 param_2, s32 param_3, s32 param_4);

void FUN_080f09a4(Enemy* p);
void FUN_080f07d0(Enemy* p);
void FUN_080f0914(Enemy* p);
void FUN_080f0868(Enemy* p);
void FUN_080e6624(Enemy* p, u16* msg);
void FUN_080e664c(Enemy* p, u16* msg);

// FUN_080f2644 / FUN_080f2864 が添字として引く, 用途は未解析
const u8 u8_ARRAY_085ad468[5] = {0, 1, 2, 3, 4};  // 0x085AD468

// 全 Enemy*_Init が Enemy のフィールドに代入する既定のメッセージハンドラ表, FUN_080f09e0 が table[msg[0]](p, msg) で呼ぶ
void (*const PTR_ARRAY_085ad470[6])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
};  // 0x085AD470

// --------------------------------------------

// "enedefault.c" を参照しているので、この関数が "enedefault.c" 内にあるのは間違いない
NAKED void FUN_080f00ec(Enemy* p) { INCFUNC("asm/func/FUN_080f00ec.inc"); }

NAKED s32 FUN_080f0320(Enemy* p) { INCFUNC("asm/func/FUN_080f0320.inc"); }

NAKED s32 FUN_080f0430(Enemy* p) { INCFUNC("asm/func/FUN_080f0430.inc"); }

void FUN_080f06ac(void) {}

NAKED bool32 FUN_080f06b0(Enemy* p) { INCFUNC("asm/func/FUN_080f06b0.inc"); }

// 活動を止める, スプライトを隠して影も消す
void FUN_080f07d0(Enemy* p) {
  if (Enemy_IsDead(p)) {
    return;
  }
  if (Enemy_TestFlag(p, ENEFLAG_UNK_1)) {
    return;
  }

  Enemy_SetFlag(p, ENEFLAG_UNK_1);
  Enemy_ClearSpriteFlags(p, SPRFLAG_AFFINE);
  Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
  p->hitbox.flags |= HBFLAG_UNK_2;
  if (p->unk_44c == 0) {
    ParticleShadow_Hide(&p->shadow);
  }
}

// 経路追従をやり直して状態12へ移す
void FUN_080f0868(Enemy* p) {
  if (Enemy_TestFlag(p, ENEFLAG_UNK_0)) {
    FUN_080e4a68(p);
    if (p->unk_44c == 0) {
      ParticleShadow_Show(&p->shadow);
    }
    p->hitbox.flags &= ~HBFLAG_UNK_2;
    FUN_080ee2c8(p);
    Enemy_ResetState(p, 3, 0, 0);
    Enemy_EnterState(p, p->unk_584, 12);
  }
}

// 活動停止から復帰する, 影を出し直してアフィンを解除する
void FUN_080f0914(Enemy* p) {
  if (Enemy_IsDead(p)) {
    return;
  }
  if (Enemy_TestFlag(p, ENEFLAG_UNK_0)) {
    return;
  }
  if (!Enemy_TestFlag(p, ENEFLAG_UNK_1)) {
    return;
  }

  Enemy_ClearFlag(p, ENEFLAG_UNK_1);
  if (p->unk_44c == 0) {
    ParticleShadow_Show(&p->shadow);
  }
  p->hitbox.flags &= ~HBFLAG_UNK_2;
  p->hitbox.unk_44 = 0;
  if (p->spriteKind == 0) {
    AuxSprite_ClearFlags((AuxSprite*)p->sprite, SPRFLAG_HIDDEN);
  } else {
    MainSprite_ClearFlags(&p->sprite->s, SPRFLAG_HIDDEN);
  }
}

void FUN_080f09a4(Enemy* p) {
  if ((Enemy_IsDead(p) == 0) && (Enemy_TestFlag(p, ENEFLAG_UNK_0) == 0) && (Enemy_TestFlag(p, ENEFLAG_UNK_1) != 0)) {
    FUN_080ee738(p);
    p->hitbox.unk_44 = 0;
  }
}

void FUN_080f09e0(Enemy* p, u16* msg) {
  if (msg != NULL) {
    u32 idx = msg[0];
    EnemyMsgHandler* table = p->unk_60c;
    table[idx](p, msg);
  }
}

NAKED bool8 FUN_080f0a0c(Enemy* p) { INCFUNC("asm/func/FUN_080f0a0c.inc"); }

NAKED void FUN_080f0b3c(Enemy* p) { INCFUNC("asm/func/FUN_080f0b3c.inc"); }

NAKED void FUN_080f0e78(Enemy* p) { INCFUNC("asm/func/FUN_080f0e78.inc"); }

// いろんなEnemyで使われるハンドラ
NAKED void FUN_080f11d0(Enemy* p) { INCFUNC("asm/func/FUN_080f11d0.inc"); }

NAKED void FUN_080f12c4(Enemy* p) { INCFUNC("asm/func/FUN_080f12c4.inc"); }

NAKED void FUN_080f19cc(Enemy* p) { INCFUNC("asm/func/FUN_080f19cc.inc"); }

// ENEFLAG3_UNK_5 が落ちている間は状態を 0/0/10 に戻してから unk_484 を1つ進める
void FUN_080f1c54(Enemy* p) {
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }

  if (Enemy_GetFlag3(p, ENEFLAG3_UNK_5) == 0) {
    Enemy_ResetState(p, 0, 0, 10);
  }

  p->unk_484++;
}

void FUN_080f1cb8(Enemy* p) {
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_1)) {
    p->unk_484++;
  }
}

NAKED void FUN_080f1cf0(Enemy* p) { INCFUNC("asm/func/FUN_080f1cf0.inc"); }

void FUN_080f1de4(Enemy* p) {
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  p->unk_484++;
}

// 巻き戻しの印が立っていたら状態16(入場フラグを食うだけのハンドラ)へ移す
// 残差2命令, unk_46c を食った印の 0/1 が畳まれる (FUN_080f3cdc と同じ)
NON_MATCH void FUN_080f1e0c(Enemy* p) {
#ifdef NONMATCHING_C
  bool32 reset = FALSE;

  if (p->unk_46c) {
    p->unk_46c = 0;
    reset = TRUE;
  }
  if (reset) {
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 0x10;
    p->handlerState = Enemy_ClearStateBegun;
    p->unk_1c8 = 0;
  }
  p->unk_484++;
#else
  INCFUNC("asm/func/FUN_080f1e0c.inc");
#endif
}

// 巻き戻しの印が立っていたら unk_5a4 のハンドラへ移し、そうでなければ最初のフレームでデモの待ちを解除する
// 残差1命令, unk_46c を食った印の 0/1 が畳まれる (FUN_080f3cdc と同じ)
NON_MATCH void FUN_080f1e78(Enemy* p) {
#ifdef NONMATCHING_C
  bool32 reset = FALSE;

  if (p->unk_46c) {
    p->unk_46c = 0;
    reset = TRUE;
  }
  if (reset) {
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 0;
    p->handlerState = p->unk_5a4;
    p->unk_1c8 = 0;
  } else {
    if (p->unk_484 == 0) {
      MsgQueue_EndWait(&p->mq, 1);
    }
    p->unk_484++;
  }
#else
  INCFUNC("asm/func/FUN_080f1e78.inc");
#endif
}

NAKED void FUN_080f1ef8(Enemy* p) { INCFUNC("asm/func/FUN_080f1ef8.inc"); }

NAKED void FUN_080f2074(Enemy* p) { INCFUNC("asm/func/FUN_080f2074.inc"); }

NAKED void FUN_080f2160(Enemy* p) { INCFUNC("asm/func/FUN_080f2160.inc"); }

void FUN_080f2254(Enemy* p) {
  u32 idx = p->unk_46a;
  EnemyHandler* table = p->handlerTables[6];
  table[idx](p);
}

void FUN_080f2278(Enemy* p) {
  u32 idx = p->unk_46a;
  EnemyHandler* table = p->handlerTables[8];
  table[idx](p);
}

void FUN_080f229c(Enemy* p) {
  u32 idx = p->unk_469;
  EnemyHandler* table = p->handlerTables[9];
  table[idx](p);
}

void FUN_080f22c0(Enemy* _) {}

void FUN_080f22c4(Enemy* p) {
  if (!p->unk_608(p)) {
    FUN_080f0a0c(p);
  }
}

void FUN_080f22e8(Enemy* p) {
  u32 idx = p->unk_469;
  EnemyHandler* table = p->handlerTables[1];
  table[idx](p);
}

void FUN_080f230c(Enemy* p) {
  u32 idx = p->unk_469;
  EnemyHandler* table = p->handlerTables[5];
  table[idx](p);
}

void FUN_080f2330(Enemy* p) {
  if (FUN_080f3718(p)) {
    u32 idx = p->unk_469;
    EnemyHandler* table = p->handlerTables[7];
    table[idx](p);
  }
}

NAKED void FUN_080f2364(Enemy* p) { INCFUNC("asm/func/FUN_080f2364.inc"); }

NAKED void FUN_080f248c(Enemy* p) { INCFUNC("asm/func/FUN_080f248c.inc"); }

NAKED void FUN_080f2644(Enemy* p) { INCFUNC("asm/func/FUN_080f2644.inc"); }

NAKED void FUN_080f2864(Enemy* p) { INCFUNC("asm/func/FUN_080f2864.inc"); }

NAKED void FUN_080f2a40(Enemy* p) { INCFUNC("asm/func/FUN_080f2a40.inc"); }

NAKED void FUN_080f2d04(Enemy* p) { INCFUNC("asm/func/FUN_080f2d04.inc"); }

NAKED void FUN_080f2ec0(Enemy* p) { INCFUNC("asm/func/FUN_080f2ec0.inc"); }

NAKED void FUN_080f31c4(Enemy* p) { INCFUNC("asm/func/FUN_080f31c4.inc"); }

NAKED void FUN_080f33e8(Enemy* p) { INCFUNC("asm/func/FUN_080f33e8.inc"); }

void FUN_080f34a0(Enemy* p) {
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  if (!p->unk_608(p)) {
    if (FUN_080f0a0c(p) == 0) {
      p->unk_484++;
    }
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[2] を回す
void FUN_080f34ec(Enemy* p) {
  if (TestFlag030047a4(FLAG030047A4_GAMEOVER) || TestFlag03002bc0(4)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->unk_46a;
    EnemyHandler* table = p->handlerTables[2];
    table[idx](p);
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[4] を回す
void FUN_080f3574(Enemy* p) {
  if (TestFlag030047a4(FLAG030047A4_GAMEOVER) || TestFlag03002bc0(4)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->unk_46a;
    EnemyHandler* table = p->handlerTables[4];
    table[idx](p);
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[3] を回す
void FUN_080f35fc(Enemy* p) {
  if (TestFlag030047a4(FLAG030047A4_GAMEOVER) || TestFlag03002bc0(4)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->unk_46a;
    EnemyHandler* table = p->handlerTables[3];
    table[idx](p);
  }
}

// 状態ごとのハンドラ表を10本割り当てる
void Enemy_InitHandlerTables(Enemy* p) {
  p->handlerTables[0] = (void*)gEnemyHandlerTable0;
  p->handlerTables[1] = (void*)gEnemyHandlerTable1;
  p->handlerTables[2] = (void*)gEnemyHandlerTable2;
  p->handlerTables[3] = (void*)gEnemyHandlerTable3;
  p->handlerTables[4] = (void*)gEnemyHandlerTable4;
  p->handlerTables[5] = (void*)gEnemyHandlerTable5;
  p->handlerTables[6] = (void*)gEnemyHandlerTable6;
  p->handlerTables[7] = (void*)gEnemyHandlerTable7;
  p->handlerTables[8] = (void*)gEnemyHandlerTable8;
  p->handlerTables[9] = (void*)gEnemyHandlerTable9;
}

NAKED bool8 FUN_080f3718(Enemy* p) { INCFUNC("asm/func/FUN_080f3718.inc"); }

// state に入った最初のフレームだけ11番のアニメを鳴らす
// 残差2命令, 原典は then と else で 0 を別々に作るが agbcc は begun の初期化と共有してロードより前に巻き上げる
NON_MATCH void FUN_080f3cdc(Enemy* p) {
#ifdef NONMATCHING_C
  bool32 begun = FALSE;

  if (p->stateBegun) {
    p->stateBegun = FALSE;
    begun = TRUE;
  }
  if (begun) {
    Enemy_PlayAnim(p, 0xB);
  }
  if (p->animForceRestart != 0) {
    p->unk_46b = 1;
  }
#else
  INCFUNC("asm/func/FUN_080f3cdc.inc");
#endif
}

NAKED void UNUSED FUN_080f3d28(Enemy* p) { INCFUNC("asm/func/FUN_080f3d28.inc"); }

NAKED void FUN_080f410c(Enemy* p) { INCFUNC("asm/func/FUN_080f410c.inc"); }

NAKED void FUN_080f44f4(Enemy* p) { INCFUNC("asm/func/FUN_080f44f4.inc"); }

NAKED void FUN_080f46a4(Enemy* p) { INCFUNC("asm/func/FUN_080f46a4.inc"); }

NAKED void FUN_080f47c8(Enemy* p) { INCFUNC("asm/func/FUN_080f47c8.inc"); }

NAKED bool32 FUN_080f48ac(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080f48ac.inc"); }

NAKED void FUN_080f5208(Enemy* p) { INCFUNC("asm/func/FUN_080f5208.inc"); }

NAKED void FUN_080f54e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f54e4.inc"); }

NAKED void FUN_080f56ec(Enemy* p) { INCFUNC("asm/func/FUN_080f56ec.inc"); }

NAKED void FUN_080f5b34(Enemy* p) { INCFUNC("asm/func/FUN_080f5b34.inc"); }

NAKED void FUN_080f5c0c(Enemy* p) { INCFUNC("asm/func/FUN_080f5c0c.inc"); }

NAKED void FUN_080f5fac(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f5fac.inc"); }

// unk_1e4 が 0x100000 未満かどうかで unk_222 の bit0 を切り替えてから1番のアニメを鳴らす
void FUN_080f624c(Enemy* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = 0;
  }

  if (p->unk_1e4 <= 0xFFFFF) {
    Enemy_SetFlags222(p, ENEMY222_UNK_0);
  } else {
    Enemy_ClearFlags222(p, ENEMY222_UNK_0);
  }

  Enemy_PlayAnim(p, 1);
}

void FUN_080f62a8(void) {}

s32 FUN_080f62ac(void) { return 0; }

NAKED s32 FUN_080f62b0(Enemy* p) { INCFUNC("asm/func/FUN_080f62b0.inc"); }

// 状態18へ移して飛行/浮遊系のフラグを落とす
bool32 FUN_080f64f0(Enemy* p) {
  if (p->flags6 & ENEFLAG6_UNK_18) {
    Enemy_SetFlag3(p, ENEFLAG3_UNK_5);
  }

  Enemy_EnterState(p, p->unk_5cc, 0x12);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  return TRUE;
}

bool32 FUN_080f65a8(Enemy* p) {
  Enemy_SetFlag3(p, ENEFLAG3_UNK_5);
  FUN_080e5718(p, 3, 0, p->kind);
  Enemy_ClearFlag(p, ENEFLAG_UNK_26);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  PlaySound_082406e0(0x13E);
  return TRUE;
}

NAKED s32 FUN_080f6604(Enemy* p) { INCFUNC("asm/func/FUN_080f6604.inc"); }

NAKED s32 FUN_080f6868(Enemy* p) { INCFUNC("asm/func/FUN_080f6868.inc"); }

NAKED s32 FUN_080f6af0(Enemy* p) { INCFUNC("asm/func/FUN_080f6af0.inc"); }

// 種族10(かつ ENEFLAG6_UNK_14 付き)の敵だけ状態3に戻して hitbox.unk_44 を 0x26 にする, 原典はフラグが立っていない経路の return を書き忘れている
bool32 FUN_080f6bac(Enemy* p) {
  if (p->kind != 10) {
    return FALSE;
  }
  if (p->flags6 & ENEFLAG6_UNK_14) {
    p->unk_192 = p->unk_190;
    FUN_080e5098(p, 0, 0);
    FUN_080e499c(p);
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    Enemy_SetFlag3(p, ENEFLAG3_UNK_1);
    Enemy_ResetState(p, 3, 0, 0);
    p->hitbox.unk_44 = 0x26;
    if (Enemy_GetFlag3(p, ENEFLAG3_UNK_1)) {
      FUN_080d9a9c(p->unk_454, 3, p->mover.id);
    }
    return TRUE;
  }
}

NAKED bool32 FUN_080f6c74(Enemy* p) { INCFUNC("asm/func/FUN_080f6c74.inc"); }

void FUN_080f6e34(Enemy* p) {
  if ((p->flags6 & (ENEFLAG6_UNK_14 | ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) != 0) {
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  }
}

NAKED s32 FUN_080f6e64(Enemy* p) { INCFUNC("asm/func/FUN_080f6e64.inc"); }

// 種族ごとの効果音を鳴らしてから状態18へ移す
bool32 FUN_080f8400(Enemy* p) {
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_8);
  switch (p->kind) {
    case 0x12: {
      PlaySound_082406e0(0x108);
      break;
    }
    case 0x13: {
      PlaySound_082406e0(0x109);
      break;
    }
  }

  Enemy_EnterState(p, p->unk_5cc, 0x12);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  return TRUE;
}

NAKED s32 FUN_080f84d4(Enemy* p) { INCFUNC("asm/func/FUN_080f84d4.inc"); }

NAKED void FUN_080f8844(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f8844.inc"); }

NAKED void FUN_080f897c(unknown* param_1) { INCFUNC("asm/func/FUN_080f897c.inc"); }

s32 FUN_080f8abc(Enemy* p) {
  switch (p->unk_480) {
    case 0: {
      return 4;
    }
    case 1:
    case 3:
    case 5: {
      return 3;
    }
    default: {
      return 4;
    }
  }
}

NAKED void FUN_080f8ae0(Enemy* p) { INCFUNC("asm/func/FUN_080f8ae0.inc"); }

// 残差5命令, 原典はフラグ判定の結果を 0/1 に起こしてから if で見るが agbcc は条件を直接分岐に畳む, ローカルの bool32 と static inline (引数あり/オペランド順) は試済
NON_MATCH void FUN_080f8bb8(Mover* owner) {
#ifdef NONMATCHING_C
  if (gFlag030047a4 & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) {
    s32 idx;

    switch (owner->unk_4) {
      case 0: {
        idx = 0;
        break;
      }
      case 1: {
        idx = 1;
        break;
      }
      case 2: {
        idx = 2;
        break;
      }
      case 3: {
        idx = 3;
        break;
      }
      default: {
        return;
      }
    }
    Entity4B15_ShowTrackingMarker(idx, &owner->pos);
  }
#else
  INCFUNC("asm/func/FUN_080f8bb8.inc");
#endif
}
