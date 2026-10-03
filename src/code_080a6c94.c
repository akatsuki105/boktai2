#include "entity.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "sound.h"
#include "vm.h"

static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }

// スクリプトの配列変数に, 続く引数を先頭から順に書き込む
s32 VM_InitArray(void) {
  u8 desc[8];
  s32 i;

  FUN_0823167c(desc);
  for (i = 0; VM_GetPC() != NULL; i++) {
    FUN_0823206c(desc, i, VM_GetValue());
  }
  return 0;
}

// 'a' 個の引数を読み直しながら 'e' のスクリプトを 'r' 回呼ぶ
s32 VM_Loop(void) {
  ScriptArgs args;
  s32 count;
  s32 repeat;

  VM_SeekToNamedArg('a');
  count = VM_GetValue();
  VM_SeekToNamedArg('r');
  repeat = VM_GetValue();
  {
    u32 argv[count];
    u8* script;
    u8* pc;
    s32 i;

    args.argc = count, args.argv = argv;
    if (!VM_SeekToNamedArg('e')) return 0;
    script = (u8*)VM_GetValue();
    VM_SeekToNamedArg('d');
    pc = VM_GetPC();
    for (i = 0; i < repeat; i++) {
      s32 j;

      for (j = 0; j < count; j++) {
        argv[j] = VM_GetValueAt(pc);
        pc = VM_GetPC();
      }
      VM_ExecByPointer(script, &args);
    }
  }
  return 0;
}

// スクリプトへ乱数を返す, 'p' があればその値未満に収める
s32 VM_Random(void) {
  s32 r;

  if (VM_SeekToNamedArg('p')) {
    s32 n = VM_GetValue();

    if (n > 0) {
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      r = *(gRandomTable + gRandTableIdx);
      return Mod(r >> 3, n);
    }
  }
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  return *(gRandomTable + gRandTableIdx);
}

// スクリプトへ1Pのキー入力を返す, 既定は押された瞬間のボタン
s32 VM_GetKeys(void) {
  if (VM_SeekToNamedArg('p')) return gInput[0].pressed;
  if (VM_SeekToNamedArg('s')) return gInput[0].down;
  if (VM_SeekToNamedArg('r')) return gInput[0].released;
  return gInput[0].pressed;
}

// 0x43A0, 文字列テーブルのエントリをデータテーブルとして引く, '.s' の要素幅の規約は VM_LoadPointer と同じ
s32 VM_ReadTable(void) {
  void* base;  // .r: テーブルの先頭ポインタ
  s32 idx;     // .i: テーブルのインデックス
  s32 size;    // .s: 要素のサイズ規約 (0: u8[idx], 1: s16[idx], それ以外: s16[idx*2])

  if (!VM_SeekToNamedArg('r')) return -1;
  base = VM_GetValueSafe2();

  if (!VM_SeekToNamedArg('i')) return -1;
  idx = VM_GetValue();

  if (!VM_SeekToNamedArg('s')) return -1;
  size = VM_GetValue();

  if (size == 0) return ((u8*)base)[idx];
  return *(s16*)((u8*)base + (size != 1 ? idx * 4 : idx * 2));
}

// FLAG030047A4_UNK_9 で停止させ, stopSound なら対象のEntityとBGMも止める
void FUN_080a6e88(bool32 stopSound) {
  gFlag030047a4 |= FLAG030047A4_UNK_9;
  if (stopSound && !(gEntityDisableFlags & ENTITY_DISABLE_3)) {
    FUN_08240918();
    gEntityDisableFlags |= ENTITY_DISABLE_3;
  }
}

void FUN_080a6ec0(void) { FUN_080a6e88(VM_SeekToNamedArg('p') ? VM_GetValue() : 0); }

// FLAG030047A4_UNK_9 による停止を解除し, 止めていたEntityとBGMを再開する
void FUN_080a6edc(void) {
  gFlag030047a4 &= ~FLAG030047A4_UNK_9;
  if (gEntityDisableFlags & ENTITY_DISABLE_3) {
    FUN_08240930();
    EnableEntityFlags(ENTITY_DISABLE_3);
  }
}

void FUN_080a6f14(void) { FUN_080a6edc(); }

bool32 FUN_080a6f20(void) {
  if (gFlag030047a4 & FLAG030047A4_UNK_9) return TRUE;
  return FALSE;
}

s32 VM_Sub15B3(void) { gFlag030047a4 |= FLAG030047A4_LINK; }
