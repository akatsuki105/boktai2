#include "emote.h"
#include "enemy.h"
#include "enemy_target.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"

// Enemy の共通部分?
// 原典のファイル名は enedefault.c, 根拠: FUN_080f00ec / FUN_080f0430 が、抜き取られた assert の引数として文字列 "enedefault.c" (0x08251F80) と行番号を積む

typedef u16 EnemyFlags222;       // Enemy.unk_222
#define ENEMY222_UNK_0 (1 << 0)  // FUN_080f624c が unk_1e4 < 0x100000 のときだけ立てる

void FUN_080f897c(Enemy* p);
void FUN_080e6794(Enemy* p, s32 priority);
s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
void FUN_080e81dc(Enemy* p, s32 param_2);
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

void FUN_080ee738(Enemy* p);
void FUN_080e4a68(Enemy* p);
void FUN_080ee2c8(Enemy* p);
bool8 FUN_080f3718(Enemy* p);
void Entity4B15_ShowTrackingMarker(s32 playerIdx, Vec3* pos);
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
  p->hitbox.flags |= HBFLAG_HIDDEN;
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
    p->hitbox.flags &= ~HBFLAG_HIDDEN;
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
  p->hitbox.flags &= ~HBFLAG_HIDDEN;
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
// 残差11命令 (92/103): 先頭の unk_46c 消費の 0/1 が分岐に畳まれる
NON_MATCH void FUN_080f11d0(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->unk_46c) {
    p->unk_46c = 0;
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 2;
    p->handlerState = p->unk_590;
    p->unk_1c8 = 0;
  }

  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }
  if (p->unk_46b) {
    Enemy_PlayAnim(p, 0);
    p->unk_46a = 12;
    p->unk_484 = 0;
    p->unk_46c = 1;
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 26;
    p->handlerState = p->unk_5b8;
    p->unk_1c8 = 0;
  } else {
    p->unk_484++;
  }
#else
  INCFUNC("asm/func/FUN_080f11d0.inc");
#endif
}

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
NON_MATCH void FUN_080f1e0c(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
    Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
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

// 残差6命令 (89/95): begun の 0/1 が分岐に畳まれる
NON_MATCH void FUN_080f2074(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 restart = p->unk_46c;
  bool32 begun = FALSE;

  if (restart) {
    p->unk_46c = 0;
    begun = TRUE;
  }
  if (begun) {
    void* handler = p->unk_590;

    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 1;
    p->handlerState = p->unk_59c;
    p->unk_1c8 = 0;
  } else if (p->unk_46b) {
    void* handler;

    MsgQueue_EndWait(&p->mq, 1);
    handler = p->unk_5a4;
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 0;
    p->handlerState = p->unk_59c;
    p->unk_1c8 = 0;
    p->unk_468 = 2;
    p->unk_469 = 0;
    p->unk_46a = 2;
    p->unk_484 = 0;
    p->unk_46c = 1;
  } else {
    p->unk_484++;
  }
#else
  INCFUNC("asm/func/FUN_080f2074.inc");
#endif
}

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

// 残差5命令 (73/78): begun の 0/1 が分岐に畳まれる
NON_MATCH void FUN_080f33e8(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 restart = p->unk_46c;
  bool32 begun = FALSE;

  if (restart) {
    p->unk_46c = 0;
    begun = TRUE;
  }
  if (begun) {
    void* handler = p->unk_5a4;

    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 0;
    p->handlerState = handler;
    p->unk_1c8 = 0;
  }

  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }
  if (p->unk_484 > 0x3B) {
    p->unk_468 = 0;
    p->unk_469 = 0;
    p->unk_46a = 2;
    p->unk_484 = 0;
    p->unk_46c = 1;
  } else {
    p->unk_484++;
  }
#else
  INCFUNC("asm/func/FUN_080f33e8.inc");
#endif
}

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
  if (TEST_FLAGS((gFlag030047a4 | u32_030047a0), FLAG030047A4_GAMEOVER) || TEST_FLAGS(u32_03002bc0[0], FLAG03002BC0_UNK_2)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->unk_46a;
    EnemyHandler* table = p->handlerTables[2];
    table[idx](p);
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[4] を回す
void FUN_080f3574(Enemy* p) {
  if (TEST_FLAGS((gFlag030047a4 | u32_030047a0), FLAG030047A4_GAMEOVER) || TEST_FLAGS(u32_03002bc0[0], FLAG03002BC0_UNK_2)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->unk_46a;
    EnemyHandler* table = p->handlerTables[4];
    table[idx](p);
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[3] を回す
void FUN_080f35fc(Enemy* p) {
  if (TEST_FLAGS((gFlag030047a4 | u32_030047a0), FLAG030047A4_GAMEOVER) || TEST_FLAGS(u32_03002bc0[0], FLAG03002BC0_UNK_2)) {
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
// 残差2命令 (27/29): 原典は then の中で 0 を作って strb し else でも別に 0 を作るが, agbcc は p->stateBegun = FALSE と begun の初期値で 0 を1つ共有する
// Tier A-C は試済: levers の「先頭オペランドをローカルに退避」で 24→27 まで戻せた (これが無いと diamond ごと畳まれる), 明示 else を足すと逆に 24 に戻る
NON_MATCH void FUN_080f3cdc(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 stateBegun = p->stateBegun;
  bool32 begun = FALSE;

  if (stateBegun) {
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

// 残差4命令 (98/102): begun の 0/1 が分岐に畳まれる
// 残りは ENEFLAG2_UNK_4 のマスク 0x10 の materialize 位置で, diamond が合えば追随する見込み
NON_MATCH void FUN_080f47c8(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 stateBegun = p->stateBegun;
  bool32 begun = FALSE;

  if (stateBegun) {
    p->stateBegun = FALSE;
    begun = TRUE;
  }
  if (begun) {
    p->mover.angle = ((p->mover.angle + 0x80) & 0xFF) >> 6 << 6;
    Enemy_PlayAnim(p, 0);
  }

  if (p->flags2 & ENEFLAG2_UNK_4) {
    p->flags |= ENEFLAG_UNK_4;
    p->unk_554 = 0x1E;
    p->unk_558 = FUN_080f3cdc;
    p->unk_550 = 0;
    p->unk_551 = 1;
    p->unk_552 = 1;
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 14;
    p->handlerState = FUN_080e6794;
    p->unk_1c8 = 0;
    p->unk_468 = 3;
    p->unk_469 = 1;
    p->unk_46a = 0;
    p->unk_484 = 0;
    p->unk_46c = 1;
    p->unk_482 = 1;
  }
#else
  INCFUNC("asm/func/FUN_080f47c8.inc");
#endif
}

NAKED bool32 FUN_080f48ac(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080f48ac.inc"); }

NAKED void FUN_080f5208(Enemy* p) { INCFUNC("asm/func/FUN_080f5208.inc"); }

NAKED void FUN_080f54e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f54e4.inc"); }

NAKED void FUN_080f56ec(Enemy* p) { INCFUNC("asm/func/FUN_080f56ec.inc"); }

// 残差4命令 (96/92): stateBegun の 0/1 が分岐に畳まれるのに加え,
// こちらは r8/r9 を push するぶん長い. Tier A-C は試済: 2文形+オペランド退避は 99 と悪化, handler のローカル化は無影響
NON_MATCH void FUN_080f5b34(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    Enemy_PlayAnim(p, 7);
    FUN_080e499c(p);
    p->flags3 &= ~(ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1);
  }

  if (p->animForceRestart) {
    p->unk_192 = 0;
    p->unk_46b = 1;
    p->flags |= ENEFLAG_UNK_4;
    Enemy_PlayAnim(p, 0);
    p->unk_468 = 3;
    p->unk_469 = 1;
    p->unk_46a = 0;
    p->unk_484 = 0;
    p->unk_46c = 1;
    p->stateBegun = TRUE;
    p->unk_46b = 0;
    p->state = 15;
    p->handlerState = p->unk_59c;
    p->unk_1c8 = 0;
  }
#else
  INCFUNC("asm/func/FUN_080f5b34.inc");
#endif
}

NAKED void FUN_080f5c0c(Enemy* p) { INCFUNC("asm/func/FUN_080f5c0c.inc"); }

NAKED void FUN_080f5fac(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f5fac.inc"); }

// unk_1e4 が 0x100000 未満かどうかで unk_222 の bit0 を切り替えてから1番のアニメを鳴らす
void FUN_080f624c(Enemy* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = 0;
  }

  if (p->unk_1e4 <= 0xFFFFF) {
    SET_FLAGS(p->unk_222, ENEMY222_UNK_0);
  } else {
    CLEAR_FLAGS(p->unk_222, ENEMY222_UNK_0);
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

  Enemy_EnterState(p, p->unk_5cc, 18);
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
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  return TRUE;
}

NAKED s32 FUN_080f6604(Enemy* p) { INCFUNC("asm/func/FUN_080f6604.inc"); }

NAKED s32 FUN_080f6868(Enemy* p) { INCFUNC("asm/func/FUN_080f6868.inc"); }

// 残差13命令 (98/85) でこちらが長い: 原典は delta をスタックに置き strh/ldrsh で往復するが agbcc は Vec3 をレジスタに展開し, そのぶん p が r8 に追い出されてフィールドアクセスごとに mov/add が余る
// Tier A-C は試済: src/pos のローカルポインタで 102→98, delta を関数スコープへ上げるのは無影響, s16 ローカル3つは 72 / s32 は 70 と逆に短くなる
NON_MATCH s32 FUN_080f6af0(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->kind == 3 && (p->flags3 & ENEFLAG3_UNK_8) && (p->unk_498 & 0x80)) {
    Vec3* src = &p->unk_20c;
    Vec3* pos = &p->mover.pos;
    Vec3 delta;

    delta.x = src->x - pos->x;
    delta.y = src->y - pos->y;
    delta.z = src->z - pos->z;
    p->unk_1c0 = Div(delta.x, 0x24);
    p->unk_1c2 = 0x14;
    p->unk_1c4 = Div(delta.z, 0x24);
    p->mover.angle = ArcTan2_8(delta.x, delta.z);
    FUN_080f897c(p);
    FUN_080e81dc(p, 6);
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080f6af0.inc");
#endif
}

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
      Emote_RemovePtcl(p->emote, 3, p->mover.id);
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
      PlaySound_082406e0(SONG_264);
      break;
    }
    case 0x13: {
      PlaySound_082406e0(SONG_265);
      break;
    }
  }

  Enemy_EnterState(p, p->unk_5cc, 18);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  return TRUE;
}

NAKED s32 FUN_080f84d4(Enemy* p) { INCFUNC("asm/func/FUN_080f84d4.inc"); }

NAKED void FUN_080f8844(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f8844.inc"); }

NAKED void FUN_080f897c(Enemy* p) { INCFUNC("asm/func/FUN_080f897c.inc"); }

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

// 残差3命令 (96/93) でこちらが長い: 原典は定数 0x18 を使用箇所ごとに movs で作るが agbcc は r9 に巻き上げて使い回す, 他はレジスタ順列
// Tier A-C は試済: table の代入を vel.x の後に下げると 97, Random() 形も 97 と悪化
NON_MATCH void FUN_080f8ae0(Enemy* p) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 velRange;
  u16* table = gRandomTable;
  vel.x = -12;
  vel.y = _Random(table) & 7;
  vel.z = -12;
  velRange.x = 24;
  velRange.y = (_Random(table) & 7) + 3;
  velRange.z = 24;
  FUN_08014730((_Random(table) & 3) + 4, FUN_080f8abc(p), &p->mover.pos, &vel, &velRange, 0x3C, 0x3F);
#else
  INCFUNC("asm/func/FUN_080f8ae0.inc");
#endif
}

// 残差5命令 (34/39): 原典は linked の 0/1 を materialize して cmp で読み直すが, agbcc は分岐に畳む
// 約400箇所で未解決の return-value 形と同じ. 先頭オペランドのローカル退避と2文形で hunk 1件まで詰めた
NON_MATCH void FUN_080f8bb8(Mover* owner) {
#ifdef NONMATCHING_C
  u32 flags = gFlag030047a4;
  bool32 linked = FALSE;

  if (flags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) {
    linked = TRUE;
  }
  if (linked) {
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
