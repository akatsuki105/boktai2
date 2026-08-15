#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "types.h"

// 用途不明の構造体　はここに置いておく

// Collision or 座標計算 or スクリプト生成管理 のデータ?
typedef struct Unk_0200865c {
  u16 id;                     // 0x00
  u8 unk_02[54];              // 0x02
  void* p_38;                 // 0x38, 親構造体のポインタ?
  struct Unk_0200865c* prev;  // 0x3C
  struct Unk_0200865c* next;  // 0x40
} Unk_0200865c;

typedef struct {
  u16 id;
  u8 unk_02;
  u8 unk_03;
  void* unk_04;
} Unk_0203b000;

// 0x085af0ec
typedef struct {
  u16 unk_0;     // 0x000
  u16 unk_2;     // 0x002
  u16 unk_4;     // 0x004
  u16 unk_6;     // 0x006
  u16 unk_8;     // 0x008
  u8 unk_9;      // 0x009
  u8 unk_a;      // 0x00a
  u32 unk_c;     // 0x00c
  u32 unk_10;    // 0x010
  s8 unk_14;     // 0x014
  s8 unk_15;     // 0x015
  u8 unk_16[6];  // 0x016
  // TODO: まだ下にたくさんメンバがある
} Unk_085af0ec;

#endif  // __INCLUDE_STRUCT_H__
