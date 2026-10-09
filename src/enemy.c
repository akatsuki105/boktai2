#include "enemy.h"

#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// 原典のファイル名は enemy.c, 根拠: FUN_080e6794 / FUN_080e6834 / FUN_080e68d8 が、抜き取られた assert の引数として文字列 "enemy.c" (0x08251F60) と行番号をレジスタに積んでから Enemy_ClearPendingState を呼ぶ
// 引数の個数と void/値返しはアセンブリから機械的に出したもの, 型は第1引数が Enemy だと言えるものだけ Enemy*, 残りは未解析の unknown*

const s16 s16_ARRAY_085ad3c4[4] = {8, 4, 2};  // 0x085AD3C4

const s16 s16_ARRAY_085ad3cc[4] = {1600, 0, 1600};  // 0x085AD3CC

// --------------------------------------------

s32 FUN_08240b98(u8* param_1, s8 param_2);  // asm/entity_794c.inc
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

NAKED s32 FUN_080e191c(Enemy* p) { INCFUNC("asm/func/FUN_080e191c.inc"); }

NAKED s32 FUN_080e1f48(Enemy* p) { INCFUNC("asm/func/FUN_080e1f48.inc"); }

NAKED s32 FUN_080e35b4(Enemy* p) { INCFUNC("asm/func/FUN_080e35b4.inc"); }

// 状態ハンドラに渡す引数と、スプライトの種類を差し替える
void FUN_080e37e8(Enemy* p, void* arg, u8 spriteKind) {
  p->unk_1cc = arg;
  p->spriteKind = spriteKind;
}

NAKED void FUN_080e3804(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080e3804.inc"); }

NAKED void FUN_080e3834(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e3834.inc"); }

NAKED void FUN_080e38a8(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080e38a8.inc"); }

NAKED void FUN_080e391c(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_080e391c.inc"); }

NAKED void FUN_080e3984(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080e3984.inc"); }

NAKED void FUN_080e3a14(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_080e3a14.inc"); }

NAKED void FUN_080e3a90(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080e3a90.inc"); }

NAKED s32 FUN_080e3afc(s32 param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e3afc.inc"); }

NAKED s32 FUN_080e3cc8(unknown* param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080e3cc8.inc"); }

NAKED s32 FUN_080e3ed8(unknown* param_1, unknown* param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e3ed8.inc"); }

NAKED s32 FUN_080e3f50(Enemy* p, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e3f50.inc"); }

NAKED s32 FUN_080e4384(Enemy* p, unknown* param_2) { INCFUNC("asm/func/FUN_080e4384.inc"); }

NAKED s32 FUN_080e4444(Enemy* p) { INCFUNC("asm/func/FUN_080e4444.inc"); }

// 入場フラグを食うだけの状態ハンドラ, 入場処理は何もしない
void Enemy_ClearStateBegun(Enemy* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

NAKED void FUN_080e48e8(Enemy* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e48e8.inc"); }

void FUN_080e4964(Enemy* p) {
  u16 prev;

  p->unk_46b = 0;
  prev = p->unk_1c8++;
  if (p->handlerState != NULL) {
    ((void (*)(Enemy*, u16))p->handlerState)(p, prev);
  }
}

void FUN_080e499c(Enemy* p) {
  p->unk_116 = 0;
  p->unk_48a = 0;
  p->unk_48c = 0;
}

NAKED void FUN_080e49c4(Enemy* p) { INCFUNC("asm/func/FUN_080e49c4.inc"); }

NAKED void FUN_080e4a68(Enemy* p) { INCFUNC("asm/func/FUN_080e4a68.inc"); }

NAKED s32 FUN_080e4aac(unknown* param_1, unknown* param_2, unknown* param_3, unknown* param_4, s32 param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_080e4aac.inc"); }

NAKED s32 FUN_080e4b3c(Enemy* p) { INCFUNC("asm/func/FUN_080e4b3c.inc"); }

NAKED void FUN_080e4e20(Enemy* p) { INCFUNC("asm/func/FUN_080e4e20.inc"); }

NAKED s32 FUN_080e4f90(Enemy* p, unknown* param_2) { INCFUNC("asm/func/FUN_080e4f90.inc"); }

NAKED void FUN_080e5098(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080e5098.inc"); }

NAKED void FUN_080e510c(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080e510c.inc"); }

void FUN_080e5388(u8 param_1, u8 param_2, u8 param_3, u8 param_4) {
  if (param_1 == 0) {
    FUN_080e510c(param_2, param_3, param_4);
  }
}

NAKED void FUN_080e53a8(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e53a8.inc"); }

NAKED void FUN_080e53ec(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e53ec.inc"); }

NAKED void FUN_080e5438(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e5438.inc"); }

NAKED void FUN_080e547c(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e547c.inc"); }

NAKED void FUN_080e54c8(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e54c8.inc"); }

NAKED void FUN_080e5508(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e5508.inc"); }

NAKED void FUN_080e554c(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e554c.inc"); }

NAKED void FUN_080e5590(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e5590.inc"); }

NAKED void FUN_080e55d0(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e55d0.inc"); }

NAKED void FUN_080e5610(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5610.inc"); }

NAKED void FUN_080e5718(Enemy* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5718.inc"); }

// pathWalker を初期化する
void FUN_080e59c4(Enemy* p, u32 pathIdx, u32 param_3, u32 nodeIdx) { Map_InitPathWalker(&p->pathWalker, pathIdx, param_3, nodeIdx); }

NAKED void FUN_080e59d0(Enemy* p, u16* param_2) { INCFUNC("asm/func/FUN_080e59d0.inc"); }

NAKED void FUN_080e5b2c(Enemy* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5b2c.inc"); }

NAKED void Enemy_SetAnimFacing(Enemy* p, u8* variant, AuxAnimPlayFlags* flags) { INCFUNC("asm/func/Enemy_SetAnimFacing.inc"); }

NAKED s32 FUN_080e5d80(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_080e5d80.inc"); }

NAKED void Enemy_Init_080e5dd4(Enemy* p) { INCFUNC("asm/func/Enemy_Init_080e5dd4.inc"); }

NAKED s32 FUN_080e5e94(unknown* param_1, unknown* param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5e94.inc"); }

NAKED s32 FUN_080e5ed4(unknown* param_1, unknown* param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e5ed4.inc"); }

NAKED s32 FUN_080e5fe4(unknown* param_1, unknown* param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e5fe4.inc"); }

NAKED s32 FUN_080e60b8(unknown* param_1, unknown* param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e60b8.inc"); }

NAKED void FUN_080e6148(s32 param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e6148.inc"); }

NAKED void FUN_080e6204(Enemy* p) { INCFUNC("asm/func/FUN_080e6204.inc"); }

// (x, z) の方を向かせる
void FUN_080e6304(Enemy* p, s16 x, s16 z) {
  s16 dx = x - p->mover.pos.x;
  s16 dz = z - p->mover.pos.z;

  p->mover.angle = ArcTan2_8(dx, dz);
}

NAKED s32 FUN_080e6330(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e6330.inc"); }

NAKED void FUN_080e6408(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080e6408.inc"); }

// パーティクルを count 個フェードさせる
void FUN_080e64b4(Enemy* p, s32 count) {
  s32 i;

  if (p->unk_44d == 0) {
    for (i = 0; i < count; i++) {
      Eff082473e0Emitter_FadeParticle(&p->emitter);
    }
  }
}

NAKED void FUN_080e64e4(s32 param_1) { INCFUNC("asm/func/FUN_080e64e4.inc"); }

// 生きている敵なら param_2[1..3] で pathWalker を初期化する
void FUN_080e6624(Enemy* p, u16* param_2) {
  if (p->hp > 0) {
    FUN_080e59c4(p, param_2[1], param_2[2], param_2[3]);
  }
}

// FUN_080e59d0 を1語進めた位置から呼ぶ
void FUN_080e664c(Enemy* p, u16* param_2) { FUN_080e59d0(p, param_2 + 1); }

NAKED void FUN_080e6658(Enemy* p) { INCFUNC("asm/func/FUN_080e6658.inc"); }

// scriptID が入っていればスクリプトを実行する
void FUN_080e6750(Enemy* p) {
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
}

/**
 * @brief 状態遷移の要求をクリアする
 * @param filename 使われていないデバッグ用の引数, "enemy.c", "slimecom.c" などの呼び出し元のファイル名が文字列で渡される
 * @param val 使われていないデバッグ用の引数, 呼び出し元のファイルの行番号?
 */
void Enemy_ClearPendingState(Enemy* p, char* filename, s32 val) {
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 0;
  p->unk_554 = 0;
  p->unk_558 = NULL;
}

NAKED void FUN_080e6794(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e6794.inc"); }

NAKED void FUN_080e6834(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e6834.inc"); }

NAKED void FUN_080e68d8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e68d8.inc"); }

NAKED void FUN_080e6978(Enemy* p, unknown* param_2, unknown* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e6978.inc"); }

NAKED s32 FUN_080e7078(unknown* param_1) { INCFUNC("asm/func/FUN_080e7078.inc"); }

NAKED void FUN_080e7150(s32 param_1, unknown* param_2) { INCFUNC("asm/func/FUN_080e7150.inc"); }

NAKED void FUN_080e7204(Enemy* p) { INCFUNC("asm/func/FUN_080e7204.inc"); }

NAKED void FUN_080e72b0(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e72b0.inc"); }

NAKED void FUN_080e73c8(Enemy* p) { INCFUNC("asm/func/FUN_080e73c8.inc"); }

NAKED void FUN_080e7b6c(Enemy* p) { INCFUNC("asm/func/FUN_080e7b6c.inc"); }

NAKED void FUN_080e7f30(Enemy* p) { INCFUNC("asm/func/FUN_080e7f30.inc"); }

NAKED s32 FUN_080e8038(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e8038.inc"); }

NAKED void FUN_080e81dc(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e81dc.inc"); }

NAKED void FUN_080e8360(Enemy* p) { INCFUNC("asm/func/FUN_080e8360.inc"); }

NAKED void FUN_080e850c(Enemy* p) { INCFUNC("asm/func/FUN_080e850c.inc"); }

NAKED void FUN_080e8614(Enemy* p) { INCFUNC("asm/func/FUN_080e8614.inc"); }

bool8 Enemy_IsDead(Enemy* p) {
  if (p == NULL) {
    return FALSE;
  }

  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_6) || Enemy_TestFlag2(p, ENEFLAG2_UNK_17) || p->hp <= 0) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_080e8aa0(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080e8aa0.inc"); }

NAKED void FUN_080e8ae4(Enemy* p, u8* param_2, u8* param_3) { INCFUNC("asm/func/FUN_080e8ae4.inc"); }

void FUN_080e8f20(Enemy* p, s32 param_2) {
  p->unk_21e = FUN_08240b98(p->unk_204, param_2);

  if (p->unk_21e == 0xB546) {
    FUN_080e8ae4(p, p->unk_204, p->unk_204);
  }
}

NAKED s32 FUN_080e8f5c(unknown* param_1) { INCFUNC("asm/func/FUN_080e8f5c.inc"); }

NAKED s32 FUN_080e907c(Enemy* p) { INCFUNC("asm/func/FUN_080e907c.inc"); }

NAKED void FUN_080e9178(Enemy* p) { INCFUNC("asm/func/FUN_080e9178.inc"); }

NAKED s32 FUN_080eafdc(Enemy* p) { INCFUNC("asm/func/FUN_080eafdc.inc"); }

NAKED s32 FUN_080eb168(Enemy* p) { INCFUNC("asm/func/FUN_080eb168.inc"); }

NAKED s32 FUN_080eb2a0(Enemy* p) { INCFUNC("asm/func/FUN_080eb2a0.inc"); }

NAKED s32 FUN_080ec438(Enemy* p, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080ec438.inc"); }

void nop_080ec4c8(void) {}

void nop_080ec4cc(void) {}

// gStat->unk_308 を丸ごと 0 にする
void FUN_080ec4d0(void) { ClearMemory(gStat->unk_308, sizeof(gStat->unk_308)); }

NAKED s32 FUN_080ec4ec(void) { INCFUNC("asm/func/FUN_080ec4ec.inc"); }

NAKED s32 FUN_080ec518(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_080ec518.inc"); }

NAKED void FUN_080ec554(void) { INCFUNC("asm/func/FUN_080ec554.inc"); }

NAKED void FUN_080ec5b4(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_080ec5b4.inc"); }

bool32 FUN_080ec5f0(u16 param_1, u16 param_2) {
  if (FUN_080ec518(param_1, param_2) == 0 && FUN_080ec4ec() != 0) {
    return TRUE;
  }

  return FALSE;
}
