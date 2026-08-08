#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "types.h"

// 用途不明の構造体　はここに置いておく

typedef struct {
  u16 id;
  u8 unk_02;
  u8 unk_03;
  void* unk_04;
} Unk_0203b000;

typedef struct Unk_030016c0 {
  u8 unk_0[4];
  s32 unk_4;
  u8 unk_8[32];
} Unk_030016c0;

// 0x085a9208
typedef struct {
  u32 unk;
  void* fn;
} Unk_085a9208;

typedef struct Unk_030016e8 {
  void* unk;
  u32 len;
  Unk_085a9208* arr;
} Unk_030016e8;

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
