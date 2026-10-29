#include "enemy.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "vm.h"

// 状態に入った最初の呼び出しだけ TRUE, 入場フラグを下ろす
static inline bool8 Enemy_ConsumeStateBegun(Enemy* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    return TRUE;
  }
  return FALSE;
}

typedef struct {
  ENEMY_HDR;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u16 scriptID_658;           // 0x658, 0 でなければ unk_65b が unk_65a に届いたときに実行する
  u8 unk_65a;                 // 0x65A, scriptID_658 を実行するまでのフレーム数
  u8 unk_65b;                 // 0x65B, 毎フレーム +1
  u8 unk_65c[0x670 - 0x65C];  // 0x65C
  u16 timer_670;              // 0x670, FUN_080ffd28 が毎フレーム 1 減らす, 0 になるまで FUN_080ff270 が状態ハンドラを呼ばない
  u16 unk_672;                // 0x672, FUN_080ff470 が timer_670 の初期値として写す
  u8 unk_674[1708 - 0x674];   // 0x674
} Boku;
static_assert(sizeof(Boku) == 1708);

void Enemy_RunStateHandler(Enemy* p);

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
void FUN_080ff36c(Enemy* p);

void FUN_080fadd4(unknown* param_1, MsgPacket* msg, Enemy* enemy) {
  if (Enemy_IsDead(enemy) == 0) {
    if ((msg->args[1] & 0xF) != 0) {
      enemy->unk_1d4 = msg->unk_4;
      Enemy_ClearFlag2(enemy, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void FUN_080fae14(HitboxData* a, HitboxData* b, Enemy* enemy) { INCFUNC("asm/func/FUN_080fae14.inc"); }

NAKED void FUN_080fb4d0(unknown* p) { INCFUNC("asm/func/FUN_080fb4d0.inc"); }

void FUN_080fba28(Enemy* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = 0;
  }
}

void FUN_080fba40(Enemy* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = 0;
  }
  Enemy_PlayAnim(p, 0);
}

NAKED void FUN_080fba64(Enemy* p) { INCFUNC("asm/func/FUN_080fba64.inc"); }

NAKED void FUN_080fc0b8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc0b8.inc"); }

void FUN_080fc174(Enemy* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(p)) {
    Enemy_PlayAnim(p, 7);
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_0);
  }

  if (param_2 == 40) {
    Enemy_SetFlag4(p, ENEFLAG4_UNK_4);
  }

  if (p->animForceRestart != 0 && param_2 > 120) {
    p->subStateDone = 1;
  }
}

NAKED void FUN_080fc1e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc1e4.inc"); }

NAKED void FUN_080fc28c(Enemy* p) { INCFUNC("asm/func/FUN_080fc28c.inc"); }

NAKED void FUN_080fc4ec(Enemy* p) { INCFUNC("asm/func/FUN_080fc4ec.inc"); }

NAKED void FUN_080fc548(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc548.inc"); }

NAKED void FUN_080fc6f4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc6f4.inc"); }

NAKED void FUN_080fd08c(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fd08c.inc"); }

NAKED void FUN_080fe1bc(Enemy* p) { INCFUNC("asm/func/FUN_080fe1bc.inc"); }

NAKED void FUN_080fe274(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fe274.inc"); }

NAKED void FUN_080fe704(Enemy* p) { INCFUNC("asm/func/FUN_080fe704.inc"); }

NAKED void FUN_080fe7f4(Enemy* p) { INCFUNC("asm/func/FUN_080fe7f4.inc"); }

void FUN_080ff05c(Enemy* p) {
  static void (*const PTR_ARRAY_085ad488[2])(Enemy*) = {
      FUN_080fe704,
      FUN_080fe7f4,
  };  // 0x085AD488
  p->handlerTables[3] = (void*)PTR_ARRAY_085ad488;
}

NAKED void FUN_080ff06c(Enemy* p) { INCFUNC("asm/func/FUN_080ff06c.inc"); }

NAKED void FUN_080ff270(Enemy* p) { INCFUNC("asm/func/FUN_080ff270.inc"); }

INCASM("asm/boku.inc");

void FUN_080ff45c(Boku* p) {
  // 先頭15要素は gEnemyHandlerTable2 と同じ中身
  static void (*const PTR_ARRAY_085ad490[18])(Enemy*) = {
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
      FUN_080ff06c,
      FUN_080ff270,
      FUN_080ff36c,
  };  // 0x085AD490
  p->handlerTables[2] = (void*)PTR_ARRAY_085ad490;
}

NAKED void FUN_080ff470(Enemy* p) { INCFUNC("asm/func/FUN_080ff470.inc"); }

void FUN_080ff668(Boku* p) {
  static void (*const PTR_ARRAY_085ad4d8[1])(Enemy*) = {
      FUN_080ff470,
  };  // 0x085AD4D8
  p->handlerTables[4] = (void*)PTR_ARRAY_085ad4d8;
}

NAKED void FUN_080ff67c(unknown* p) { INCFUNC("asm/func/FUN_080ff67c.inc"); }

NAKED void FUN_080ff6e8(unknown* p) { INCFUNC("asm/func/FUN_080ff6e8.inc"); }

NAKED void FUN_080ff7c0(unknown* p) { INCFUNC("asm/func/FUN_080ff7c0.inc"); }

NAKED void FUN_080ffa44(unknown* p) { INCFUNC("asm/func/FUN_080ffa44.inc"); }

NAKED void FUN_080ffad8(unknown* p) { INCFUNC("asm/func/FUN_080ffad8.inc"); }

void FUN_080ffc28(void) {}

NAKED void FUN_080ffc2c(Boku* p) { INCFUNC("asm/func/FUN_080ffc2c.inc"); }

const u16 u16_ARRAY_085ad4dc[4] = {336, 336, 0, 180};  // 0x085AD4DC

NAKED unknown* FUN_080ffcd0(unknown* p) { INCFUNC("asm/func/FUN_080ffcd0.inc"); }

void FUN_080ffd28(Boku* p) {
  Boku* q = p->unk_1cc;

  if (q->timer_670 != 0) {
    q->timer_670--;
  }
}

NAKED void FUN_080ffd48(Boku* p) { INCFUNC("asm/func/FUN_080ffd48.inc"); }

NAKED void FUN_080ffda8(Boku* p) { INCFUNC("asm/func/FUN_080ffda8.inc"); }

NAKED void FUN_081000a4(Boku* p) { INCFUNC("asm/func/FUN_081000a4.inc"); }

NAKED void FUN_08100164(Boku* p) { INCFUNC("asm/func/FUN_08100164.inc"); }

// 予約してあるスクリプトを unk_65a フレーム後に実行する
void FUN_081001dc(Boku* p) {
  Boku* q = p->unk_1cc;

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
NAKED bool32 FUN_08100228(Boku* p) { INCFUNC("asm/func/FUN_08100228.inc"); }

NAKED bool32 FUN_081019e0(Boku* p) { INCFUNC("asm/func/FUN_081019e0.inc"); }

bool32 FUN_08101bb4(Boku* p) {
  FUN_080ffd28(p);
  return TRUE;
}

bool32 FUN_08101bc0(Boku* p) {
  FUN_081019e0(p);

  if (Enemy_TestFlag3((Enemy*)p, ENEFLAG3_UNK_13) || p->unk_4be == 0) {
    u32 idx = p->subState0;
    EnemyHandler* table = p->handlerTables[0];
    table[idx]((Enemy*)p);
    Enemy_RunStateHandler((Enemy*)p);
  }

  FUN_08101bb4(p);
  return TRUE;
}

// FUN_080edebc から呼ばれる
s32 FUN_08101c1c(Boku* p) {
  FUN_080f06b0((Enemy*)p);
  return 0;
}

NAKED s32 EnemyBoku_Destroy(Boku* p) { INCFUNC("asm/func/EnemyBoku_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 EnemyBoku_Init(Boku* p) { INCFUNC("asm/func/EnemyBoku_Init.inc"); }

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
