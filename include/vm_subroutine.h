#ifndef __INCLUDE_VM_SUBROUTINE_H__
#define __INCLUDE_VM_SUBROUTINE_H__

#include "gba/gba.h"
#include "types.h"

typedef bool32 (*CtrlHandler)(u8* pc);
typedef void (*EntityCreateFn)(u32 param, void* unused);
typedef void* (*SubroutineFn)(void);

// Subroutine (サブルーチン) スクリプトから呼び出す ネイティブ関数 のこと
// ID と 関数ポインタを持つのは共通だが、呼び出し方や引数の有無はサブルーチンごとに異なる
typedef struct Subroutine {
  u32 id;  // サブルーチンID
  union {
    void* fn;          // raw
    CtrlHandler ctrl;  // 制御命令 (0x60) のハンドラもサブルーチンと同じ機構を使う
    // VM_Ctrl_CreateEntity が呼ぶ Entity 生成関数, 第1引数に種別/パラメータが入り第2引数は常に NULL
    // 生成物はマネージャ側に登録されるのでスクリプトは受け取る必要がなく, 戻り値は捨てられる
    EntityCreateFn create;
    // VM_Ctrl_CallSubroutine が呼ぶ汎用のサブルーチン, C の仮引数は持たず
    // 必要な値は VM_GetValue や VM_SeekToNamedArg で自分で読み出す, 戻り値は gVM.result に入る
    SubroutineFn call;
  } fn;
} Subroutine;

typedef struct CtrlHandlerTable {
  struct CtrlHandlerTable* next;  // 0x00, 次のテーブルへのポインタ
  u32 len;                        // 0x04, arr のエントリ数
  const Subroutine* arr;          // 0x08
} CtrlHandlerTable;

s32 VM_AddCtrlHandlers(CtrlHandlerTable*);  // gCtrlHandlers に gCtrlHandlers1 or gCtrlHandlers2 を追加する

#endif  // __INCLUDE_VM_SUBROUTINE_H__
