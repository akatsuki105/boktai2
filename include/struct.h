#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "types.h"

// 用途不明の構造体　はここに置いておく

// Collision or 座標計算 or スクリプト生成管理 のデータ?
typedef struct Entity2UnkData {
  u16 id;     // 0x00
  u16 unk_2;  // 0x02
  u8 unk_4;   // 0x04
  u8 unk_5;   // 0x05
  u8 unk_6[2];
  vec3 pos;  // 0x08
  u8 unk_e[2];
  u16 unk_10[3];  // 0x10
  u16 unk_16;     // 0x16
  u32 unk_18;     // 0x18
  u16 unk_1c;     // 0x1C
  u16 unk_1e;     // 0x1E
  u32 unk_20;     // 0x20
  void* unk_24;   // 0x24
  u32 unk_28;     // 0x28
  u32 unk_2c;     // 0x2C
  u8 unk_30[8];
  void* p_38;                   // 0x38, 親構造体のポインタ?
  struct Entity2UnkData* prev;  // 0x3C
  struct Entity2UnkData* next;  // 0x40
} Entity2UnkData;

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
