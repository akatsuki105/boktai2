#include "entity.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "sound.h"
#include "time.h"
#include "video.h"

// 通信まわり, 他の Entity と 違って、 _Init, _Update, _Destroy を持たない
typedef struct {
  Entity e;  // ENTITY_UNK_1
  u8 unk_18;
  u8 unk_19;  // 0x19, 根拠: FUN_0804e474 が返す
  u8 unk_1a;
  u8 unk_1b;  // 0x1B, 根拠: FUN_0804e4ac が 1 を入れる
  u8 unk_1c;  // 0x1C, 根拠: FUN_0804e4c4 が 1 を入れる
  u8 unk_1d;  // 0x1D, 根拠: FUN_0804e604 が 1 を入れる
  u8 unk_1e;  // 0x1E, 根拠: FUN_0804bb30 が 0 を入れる
  u8 unk_1f;
  u8 unk_20;
  u8 unk_21;   // 0x21, 根拠: FUN_0804e3c0 が返す
  u16 unk_22;  // 0x22, 根拠: FUN_0804c888 が bit7 を見る
  u8 unk_24[0x26 - 0x24];
  u8 unk_26;  // 0x26, 根拠: FUN_0804dee8 が 0 を入れる
  u8 unk_27[0x30 - 0x27];
  u8 unk_30;  // 0x30, 根拠: FUN_0804d680 が立っていたら rfu_clearAllSlot する
  u8 unk_31;
  u8 unk_32;  // 0x32, 根拠: FUN_0804de40 が立っていたら 0 に戻す
  u8 unk_33;  // 0x33, 根拠: FUN_0804e584 が書く
  u8 unk_34;
  u8 unk_35;  // 0x35, 根拠: FUN_0804bb30 が 0 を入れる
  u8 unk_36;  // 0x36, 同上
  u8 unk_37;
  u16 unk_38;  // 0x38, 根拠: FUN_0804e490 が返す
  u8 unk_3a[0x3C - 0x3A];
  u8 unk_3c;  // 0x3C, 根拠: FUN_0804bb30 が 0 を入れる
  u8 unk_3d;  // 0x3D, 根拠: FUN_0804e5e8 が 1 を入れる
  u8 unk_3e;
  u8 unk_3f;  // 0x3F, 根拠: FUN_0804cc98 が rfu_LMAN_stopManager に渡す
  u8 unk_40[0x44 - 0x40];
  u32 unk_44;  // 0x44, 根拠: FUN_0804da50 が 0 を入れる
  u8 unk_48[0x50 - 0x48];
  u8 unk_50[0x6C - 0x50];  // 0x50, 根拠: FUN_0804e61c がこの位置のアドレスを返す
  u16 unk_6c;              // 0x6C, 根拠: FUN_0804e638 が返す
  u8 unk_6e[0xEA - 0x6E];
  u16 unk_ea;     // 0xEA, 根拠: FUN_0804ce0c が 0xFFFF を入れる
  u16 unk_ec;     // 0xEC, 根拠: FUN_0804bb70 が bit14 を見て unk_ee を書き込む
  u16 unk_ee;     // 0xEE, 根拠: FUN_0804bb68 が書く
  u16 unk_f0[5];  // 0xF0, 根拠: FUN_0804ce0c が5要素に -1 を OR する
  u8 unk_fa;
  u8 unk_fb;  // 0xFB, 根拠: FUN_0804e384 が 1 を入れる
  u8 unk_fc[0x134 - 0xFC];
  u8 unk_134[0x40];  // 0x134, 根拠: FUN_0804bb30 が ClearMemory で 0 にする
  u8 unk_174[908 - 0x174];
} Entity0804e2c0;
static_assert(sizeof(Entity0804e2c0) == 908);

typedef s32(Entity0804e2c0Func)(Entity0804e2c0* p);

IWRAM_DATA u8 u8_030000dc = 0;    // 0x030000DC
IWRAM_DATA u32 u32_030000e0 = 0;  // 0x030000E0, 型不明

COMMON_DATA Entity0804e2c0* gEntity0804e2c0 = NULL;  // 0x03002B58

extern const u8 u8_ARRAY_085ab5b0[8];  // src/entity_fb53.c

// クロスオーバー通信で送る文字列を1文字 = 1エントリに展開した表, 根拠: Crossover_LoadMappingBuf が 0x100 個まで strh で埋める
EWRAM_DATA u16 gCrossoverMappingBuf[256] = {};  // 0x0203FC00

// 状態をリセットしてモーション番号を設定する
static inline void Entity0804e2c0_SetMotion(Entity0804e2c0* p, u16 motion) {
  p->unk_1c = 0;
  p->unk_38 = motion;
  p->unk_44 = 0;
}

void FUN_08229f4c(u32 n);  // src/interrupts.c
void FUN_0804d868(Entity0804e2c0* p);

s32 FUN_0804c3cc(Entity0804e2c0*);
s32 FUN_0804c3e4(Entity0804e2c0*);
s32 FUN_0804c438(Entity0804e2c0*);
s32 FUN_0804c57c(Entity0804e2c0*);
s32 FUN_0804c5c0(Entity0804e2c0*);
s32 FUN_0804c5d8(Entity0804e2c0*);
s32 FUN_0804c650(Entity0804e2c0*);
s32 FUN_0804c6ac(Entity0804e2c0*);
s32 FUN_0804c7c8(Entity0804e2c0*);
s32 FUN_0804c888(Entity0804e2c0*);
s32 FUN_0804c8bc(Entity0804e2c0*);
s32 FUN_0804c8f4(Entity0804e2c0*);
s32 FUN_0804c940(Entity0804e2c0*);
s32 FUN_0804c978(Entity0804e2c0*);
s32 FUN_0804c9a8(Entity0804e2c0*);
s32 FUN_0804cb6c(Entity0804e2c0*);
s32 FUN_0804cb84(Entity0804e2c0*);
s32 FUN_0804cb9c(Entity0804e2c0*);
s32 FUN_0804cbb4(Entity0804e2c0*);
s32 FUN_0804cbcc(Entity0804e2c0*);
s32 FUN_0804cbfc(Entity0804e2c0*);
s32 FUN_0804cc38(Entity0804e2c0*);
s32 FUN_0804cc7c(Entity0804e2c0*);
s32 FUN_0804cc98(Entity0804e2c0*);
s32 FUN_0804ccbc(Entity0804e2c0*);
s32 FUN_0804d698(Entity0804e2c0*);
s32 FUN_0804d6d0(Entity0804e2c0*);
s32 FUN_0804da50(Entity0804e2c0*);
s32 FUN_0804da78(Entity0804e2c0*);
s32 FUN_0804dae4(Entity0804e2c0*);
s32 FUN_0804de18(Entity0804e2c0*);
s32 FUN_0804de40(Entity0804e2c0*);
s32 FUN_0804de58(Entity0804e2c0*);

// clang-format off
Entity0804e2c0Func* const PTR_ARRAY_085ab5e0[33] = {
    FUN_0804c3cc,
    FUN_0804c3e4,
    FUN_0804c438,
    FUN_0804c57c,
    FUN_0804c5c0,
    FUN_0804c5d8,
    FUN_0804c650,
    FUN_0804c6ac,
    FUN_0804c7c8,
    FUN_0804c888,
    FUN_0804c8bc,
    FUN_0804c8f4,
    FUN_0804c940,
    FUN_0804c978,
    FUN_0804c9a8,
    FUN_0804cb6c,
    FUN_0804cb84,
    FUN_0804cb9c,
    FUN_0804cbb4,
    FUN_0804d698,
    FUN_0804d6d0,
    FUN_0804da50,
    FUN_0804de18,
    FUN_0804da78,
    FUN_0804de40,
    FUN_0804dae4,
    FUN_0804de58,
    FUN_0804cbcc,
    FUN_0804cbfc,
    FUN_0804cc38,
    FUN_0804cc7c,
    FUN_0804cc98,
    FUN_0804ccbc,
};  // 0x085AB5E0
// clang-format on

NAKED s32 FUN_0804b9f4(void) { INCFUNC("asm/func/FUN_0804b9f4.inc"); }

Entity0804e2c0* FUN_0804ba3c(void) { return gEntity0804e2c0; }

s32 FUN_0804ba48(void) {
  if (gEntity0804e2c0 != NULL) {
    return 1;
  }
  return 0;
}

void FUN_0804e584(s32);

NAKED void FUN_0804ba64(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804ba64.inc"); }

// 通信用の状態をまとめて初期化する
void FUN_0804bb30(Entity0804e2c0* p) {
  p->unk_1e = 0;
  p->unk_22 = 0;
  p->unk_35 = 0;
  p->unk_36 = 0;
  p->unk_3c = 0;
  p->unk_3d = 0;
  p->unk_3e = 0;
  p->unk_3f = 0;
  ClearMemory(p->unk_134, sizeof(p->unk_134));
}

// 残差は 3 命令 vs 4 命令 で、原典は p を別レジスタに複写してから +0xEE している (局所コピーを置いても agbcc が畳んでしまう)
NON_MATCH void FUN_0804bb68(Entity0804e2c0* p, u16 val) {
#ifdef NONMATCHING_C
  p->unk_ee = val;
#else
  INCFUNC("asm/func/FUN_0804bb68.inc");
#endif
}

// unk_ec の bit14 が立っていたら unk_ee を取り込む
s32 FUN_0804bb70(Entity0804e2c0* p) {
  if (p->unk_ec & 0x4000) {
    p->unk_ec = p->unk_ee;
    return 0;
  }

  return -1;
}

NAKED s32 FUN_0804bb98(s32 param_1) { INCFUNC("asm/func/FUN_0804bb98.inc"); }

s32 FUN_0804bbf8(Entity0804e2c0* p) {
  if (p->unk_1b != 0) {
    p->unk_1b = 0;
    return 1;
  }
  return 0;
}

s32 FUN_0804bc10(Entity0804e2c0* p) {
  if (p->unk_1c != 0) {
    p->unk_1c = 0;
    return 1;
  }
  return 0;
}

NAKED void FUN_0804bc28(s32 param_1) { INCFUNC("asm/func/FUN_0804bc28.inc"); }

NAKED s32 FUN_0804bcc8(s32 param_1) { INCFUNC("asm/func/FUN_0804bcc8.inc"); }

NAKED s32 FUN_0804bdd4(s32 param_1) { INCFUNC("asm/func/FUN_0804bdd4.inc"); }

NAKED void FUN_0804bed4(s32 param_1) { INCFUNC("asm/func/FUN_0804bed4.inc"); }

NAKED void FUN_0804bf90(u8 param_1) { INCFUNC("asm/func/FUN_0804bf90.inc"); }

NAKED void FUN_0804c190(u8 param_1) { INCFUNC("asm/func/FUN_0804c190.inc"); }

void FUN_0804c3a8(void) { rfu_REQ_recvData(); }

void FUN_0804c3b4(void) {
  if (gEntity0804e2c0 != NULL) {
    rfu_REQ_recvData();
  }
}

s32 FUN_0804c3cc(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
}

NAKED s32 FUN_0804c3e4(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c3e4.inc"); }

NAKED s32 FUN_0804c438(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c438.inc"); }

NAKED s32 FUN_0804c57c(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c57c.inc"); }

s32 FUN_0804c5c0(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
  return 0;
}

NAKED s32 FUN_0804c5d8(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c5d8.inc"); }

NAKED s32 FUN_0804c650(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c650.inc"); }

NAKED s32 FUN_0804c6ac(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c6ac.inc"); }

NAKED s32 FUN_0804c7c8(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c7c8.inc"); }

s32 FUN_0804c888(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
    PlaySound_082406e0(0xDD);
  }

  if (p->unk_22 & 0x80) {
    FUN_08229f4c(8);
    FUN_0804d868(p);
  }
}

NAKED s32 FUN_0804c8bc(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c8bc.inc"); }

NAKED s32 FUN_0804c8f4(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c8f4.inc"); }

s32 FUN_0804c940(Entity0804e2c0* p) {
  bool8 mode;

  if (p->unk_32) {
    p->unk_32 = 0;
  }

  mode = rfu_getMasterSlave();
  if (mode == 1) {
    rfu_REQ_disconnect(gRfuLinkStatus->connectSlot_flag | gRfuLinkStatus->linkLossSlot_flag);
    rfu_waitREQComplete();
  }
}

// 120フレーム経ったらモーション 8 に切り替える
s32 FUN_0804c978(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }

  if (p->unk_44 > 120) {
    Entity0804e2c0_SetMotion(p, 8);
    p->unk_32 = 1;
  }
}

NAKED s32 FUN_0804c9a8(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804c9a8.inc"); }

s32 FUN_0804cb6c(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
}

s32 FUN_0804cb84(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
}

s32 FUN_0804cb9c(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
}

s32 FUN_0804cbb4(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
}

s32 FUN_0804cbcc(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
    p->unk_1b = 0;
    p->unk_1c = 0;
  }

  if (FUN_0804bc10(p)) {
    FUN_0804ba64(p);
  }

  return 0;
}

s32 FUN_0804cbfc(Entity0804e2c0* p) {
  if (p->unk_32 != 0) {
    p->unk_32 = 0;
    FUN_0804e584(1);
    rfu_LMAN_stopManager(1);
    p->unk_1b = 0;
    p->unk_1c = 0;
  }
  if (FUN_0804bc10(p)) {
    FUN_0804ba64(p);
  }
  return 0;
}

NAKED s32 FUN_0804cc38(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804cc38.inc"); }

s32 FUN_0804cc7c(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
    rfu_LMAN_powerDownRFU();
  }
  return 0;
}

s32 FUN_0804cc98(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
    rfu_LMAN_stopManager(p->unk_3f);
  }
  return 0;
}

s32 FUN_0804ccbc(Entity0804e2c0* p) {
  rfu_clearAllSlot();
  FUN_0804ba64(p);
}

NAKED void FUN_0804ccd0(s32 param_1) { INCFUNC("asm/func/FUN_0804ccd0.inc"); }

NAKED s32 FUN_0804cd1c(s32 param_1) { INCFUNC("asm/func/FUN_0804cd1c.inc"); }

NAKED void FUN_0804cde8(s32 param_1) { INCFUNC("asm/func/FUN_0804cde8.inc"); }

// 通信スロットの対応表を未割り当てに戻す
void FUN_0804ce0c(Entity0804e2c0* p) {
  s32 i;

  p->unk_ea = 0xFFFF;
  p->unk_ec = -1;

  for (i = 0; i < 5; i++) {
    p->unk_f0[i] |= -1;
  }
}

NAKED void FUN_0804ce3c(s32 param_1) { INCFUNC("asm/func/FUN_0804ce3c.inc"); }

NAKED void FUN_0804cf4c(s32 param_1) { INCFUNC("asm/func/FUN_0804cf4c.inc"); }

NAKED void FUN_0804d05c(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_0804d05c.inc"); }

NAKED void FUN_0804d0ac(u8 param_1) { INCFUNC("asm/func/FUN_0804d0ac.inc"); }

NAKED void FUN_0804d214(u8 param_1) { INCFUNC("asm/func/FUN_0804d214.inc"); }

NAKED void FUN_0804d308(void) { INCFUNC("asm/func/FUN_0804d308.inc"); }

void FUN_0804d36c(u16 param_1) {
  if (gEntity0804e2c0 != NULL) {
    if (param_1 == 0x27) {
      rfu_REQ_changeMasterSlave();
      rfu_waitREQComplete();
    } else {
      rfu_REQ_recvData();
    }
  }
}

NAKED void FUN_0804d394(s32 param_1) { INCFUNC("asm/func/FUN_0804d394.inc"); }

NAKED void FUN_0804d548(s32 param_1) { INCFUNC("asm/func/FUN_0804d548.inc"); }

s32 FUN_0804d680(Entity0804e2c0* p) {
  if (p->unk_30 != 0) {
    rfu_clearAllSlot();
    return 1;
  }
  return 0;
}

// 入ったフレームで BG を消して, キー入力に 0x2000 を立てて送る
// 残差1命令, 原典は gRawKeyInput を直接 r1 に読んで定数を r0 に置くが, こちらは読みを r0 / 定数を r2 に取って r1 へ写す
// u16 のローカルを挟む形, FUN_0804bb68 の第2引数を u32 にする形のどちらでも変わらない
NON_MATCH s32 FUN_0804d698(Entity0804e2c0* p) {
#ifdef NONMATCHING_C
  if (p->unk_32) {
    p->unk_32 = 0;
    ClearBGTilemapBuffer(0);
  }

  FUN_0804bb68(p, gRawKeyInput | 0x2000);
  p->unk_31 = 1;
#else
  INCFUNC("asm/func/FUN_0804d698.inc");
#endif
}

// 入ったフレームで BG を消して, キー入力に 0x2000 を立てて送る
// 残差1命令, 原典は gRawKeyInput を直接 r1 に読んで定数を r0 に置くが, こちらは読みを r0 / 定数を r2 に取って r1 へ写す
// u16 のローカルを挟む形, FUN_0804bb68 の第2引数を u32 にする形のどちらでも変わらない
NON_MATCH s32 FUN_0804d6d0(Entity0804e2c0* p) {
#ifdef NONMATCHING_C
  if (p->unk_32) {
    p->unk_32 = 0;
    ClearBGTilemapBuffer(0);
  }

  FUN_0804bb68(p, gRawKeyInput | 0x2000);
  p->unk_31 = 1;
#else
  INCFUNC("asm/func/FUN_0804d6d0.inc");
#endif
}

NAKED void FUN_0804d708(u8 param_1) { INCFUNC("asm/func/FUN_0804d708.inc"); }

void FUN_0804d85c(void) { rfu_REQ_recvData(); }

NAKED void FUN_0804d868(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804d868.inc"); }

NAKED s32 FUN_0804d90c(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804d90c.inc"); }

NAKED void FUN_0804d9a4(s32 param_1) { INCFUNC("asm/func/FUN_0804d9a4.inc"); }

// モーション 0x17 をセットする状態ハンドラ
s32 FUN_0804da50(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
  Entity0804e2c0_SetMotion(p, 0x17);
  p->unk_32 = 1;
  return 0;
}

NAKED s32 FUN_0804da78(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804da78.inc"); }

s32 FUN_0804dae4(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
  return 0;
}

NAKED void FUN_0804dafc(u8 param_1) { INCFUNC("asm/func/FUN_0804dafc.inc"); }

void FUN_0804dbc8(void) {
  if (gEntity0804e2c0 != NULL) {
    rfu_REQ_recvData();
  }
}

NAKED void FUN_0804dbe0(s32 param_1) { INCFUNC("asm/func/FUN_0804dbe0.inc"); }

NAKED s32 FUN_0804dc90(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804dc90.inc"); }

NAKED void FUN_0804dd80(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804dd80.inc"); }

// モーション 0x17 をセットする状態ハンドラ, FUN_0804da50 と同じ内容
s32 FUN_0804de18(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
  Entity0804e2c0_SetMotion(p, 0x17);
  p->unk_32 = 1;
  return 0;
}

s32 FUN_0804de40(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
  return 0;
}

s32 FUN_0804de58(Entity0804e2c0* p) {
  if (p->unk_32) {
    p->unk_32 = 0;
  }
  return 0;
}

NAKED s32 FUN_0804de70(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804de70.inc"); }

// unk_38 番の状態ハンドラを呼ぶ
// 残差はレジスタ割当だけ, 原典はテーブル先頭を r0 / 添字を r1 に取るがこちらは逆になる (命令数は同じ)
// 関数ポインタのローカルを挟んでも変わらない
NON_MATCH s32 FUN_0804dee8(Entity0804e2c0* p) {
#ifdef NONMATCHING_C
  if (p->unk_18) {
    p->unk_26 = 0;
    rfu_LMAN_manager_entity(0);
  }

  return PTR_ARRAY_085ab5e0[p->unk_38](p);
#else
  INCFUNC("asm/func/FUN_0804dee8.inc");
#endif
}

NAKED s32 FUN_0804df18(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804df18.inc"); }

NAKED s32 FUN_0804e028(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804e028.inc"); }

NAKED void FUN_0804e0bc(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804e0bc.inc"); }

// RFU の状態を進めてから unk_38 番の状態ハンドラを呼ぶ
s32 FUN_0804e128(Entity0804e2c0* p) {
  p->unk_31 = 0;
  rfu_LMAN_manager_entity(0);
  rfu_getMasterSlave();
  FUN_0804dc90(p);
  FUN_0804dd80(p);
  return PTR_ARRAY_085ab5e0[p->unk_38](p);
}

NAKED unknown* FUN_0804e164(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804e164.inc"); }

NAKED s32 FUN_0804e25c(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804e25c.inc"); }

NAKED Entity0804e2c0* Entity0804e2c0_Create(void) { INCFUNC("asm/func/Entity0804e2c0_Create.inc"); }

void FUN_0804e36c(void) {
  if (gEntity0804e2c0 != NULL) {
    FUN_0804e164(gEntity0804e2c0);
  }
}

void FUN_0804e384(void) {
  if (gEntity0804e2c0 != NULL) {
    gEntity0804e2c0->unk_fb = 1;
  }
}

NAKED s32 FUN_0804e3a0(void) { INCFUNC("asm/func/FUN_0804e3a0.inc"); }

// 子機として接続しているときだけ unk_21 を返す
s32 FUN_0804e3c0(void) {
  Entity0804e2c0* p = gEntity0804e2c0;

  if (p == NULL || gRfuLinkStatus->parent_child != 0) {
    return 0;
  }

  return p->unk_21;
}

NAKED s32 FUN_0804e3ec(void) { INCFUNC("asm/func/FUN_0804e3ec.inc"); }

NAKED s32 FUN_0804e438(void) { INCFUNC("asm/func/FUN_0804e438.inc"); }

s32 FUN_0804e458(void) {
  if (gEntity0804e2c0 == NULL) {
    return 0;
  }
  return gEntity0804e2c0->unk_30;
}

s32 FUN_0804e474(void) {
  if (gEntity0804e2c0 == NULL) {
    return 0;
  }
  return gEntity0804e2c0->unk_19;
}

s32 FUN_0804e490(void) {
  if (gEntity0804e2c0 == NULL) {
    return 0;
  }
  return gEntity0804e2c0->unk_38;
}

void FUN_0804e4ac(void) {
  if (gEntity0804e2c0 != NULL) {
    gEntity0804e2c0->unk_1b = 1;
  }
}

void FUN_0804e4c4(void) {
  if (gEntity0804e2c0 != NULL) {
    gEntity0804e2c0->unk_1c = 1;
  }
}

NAKED void FUN_0804e4dc(unknown* param_1, Entity* param_2, EntityFunc* param_3, EntityFunc* param_4) { INCFUNC("asm/func/FUN_0804e4dc.inc"); }

NAKED s32 FUN_0804e514(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804e514.inc"); }

NAKED s32 FUN_0804e55c(Entity0804e2c0* p) { INCFUNC("asm/func/FUN_0804e55c.inc"); }

void FUN_0804e584(s32 val) {
  if (gEntity0804e2c0 != NULL) {
    gEntity0804e2c0->unk_33 = val;
  }
}

s32 FUN_0804e59c(void) {
  if (gEntity0804e2c0 == NULL) {
    return u32_030000e0;
  }
  return gEntity0804e2c0->unk_33;
}

// モーション 0x1F をセットする
void FUN_0804e5bc(void) {
  Entity0804e2c0* p = gEntity0804e2c0;

  if (p != NULL) {
    p->unk_3f = 1;
    Entity0804e2c0_SetMotion(p, 0x1F);
    p->unk_32 = 1;
  }
}

void FUN_0804e5e8(void) {
  if (gEntity0804e2c0 != NULL) {
    gEntity0804e2c0->unk_3d = 1;
  }
}

void FUN_0804e604(void) {
  if (gEntity0804e2c0 != NULL) {
    gEntity0804e2c0->unk_1d = 1;
  }
}

u8* FUN_0804e61c(void) {
  if (gEntity0804e2c0 == NULL) {
    return NULL;
  }
  return gEntity0804e2c0->unk_50;
}

s32 FUN_0804e638(void) {
  if (gEntity0804e2c0 == NULL) {
    return 0;
  }
  return gEntity0804e2c0->unk_6c;
}

u16* Crossover_GetMappingBuf(void) { return gCrossoverMappingBuf; }

u16 FUN_0804e65c(u8 n) { return Crossover_GetMappingBuf()[n]; }

// クロスオーバーのマッピング表から id の位置を探す
// 残差は4命令, 原典はループの入口判定を上に置いたまま (rotation なし) だが agbcc は i == 0 の初回判定を剥がして複製する
// while (buf[i] != id) i++; でも while (TRUE) + if/break でも同じ形になる
NON_MATCH s32 FUN_0804e674(u16 id) {
#ifdef NONMATCHING_C
  u16* buf = Crossover_GetMappingBuf();
  u8 i = 0;

  while (buf[i] != id) {
    i++;
  }

  return i;
#else
  INCFUNC("asm/func/FUN_0804e674.inc");
#endif
}

NAKED void FUN_0804e69c(s32 param_1, u8* param_2, s32 param_3) { INCFUNC("asm/func/FUN_0804e69c.inc"); }

NAKED void FUN_0804e6d8(unknown* s, s32 param_2, s32 charcount) { INCFUNC("asm/func/FUN_0804e6d8.inc"); }

NAKED void Crossover_LoadMappingBuf(void) { INCFUNC("asm/func/Crossover_LoadMappingBuf.inc"); }
