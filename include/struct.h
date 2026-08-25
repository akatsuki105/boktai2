#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "gba/gba.h"
#include "types.h"

// 用途不明の構造体　はここに置いておく

struct SpriteState;

// Collision or 座標計算 or スクリプト生成管理 のデータ?
typedef struct Entity2UnkData {
  u16 id;     // 0x00, Player_Create で作った Player の場合、 Player_Createの サブルーチンID (0xF5EB) がセットされていた
  u16 unk_2;  // 0x02, フラグっぽい
  u8 unk_4;   // 0x04, Playerの場合は gPlayerPtr のインデックス, 0..3
  u8 unk_5;   // 0x05
  u8 unk_6[2];
  Vec3 pos;                    // 0x08
  Vec3 delta;                  // 0x10, FUN_0823b4b8 で .pos の変化量として使われている (速度ではなさそう)
  void* unk_18;                // 0x18, Player の場合は、 &Player.unk_1bc
  u16 unk_1c;                  // 0x1C
  u16 unk_1e;                  // 0x1E
  u32 unk_20;                  // 0x20
  void* unk_24;                // 0x24
  u32 unk_28;                  // 0x28
  struct SpriteState* unk_2c;  // 0x2C, Player の場合は、 &Player.sprite
  u8 unk_30[8];
  void* p_38;                   // 0x38, 親構造体のポインタ?
  struct Entity2UnkData* prev;  // 0x3C
  struct Entity2UnkData* next;  // 0x40
} Entity2UnkData;
static_assert(sizeof(Entity2UnkData) == 68);  // 0x08142700 で、 0x44以降から別の構造体っぽいので多分サイズは 68バイトのはず

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

// --------------------------------------------

typedef struct {
  u8 unk_0[52];  // 0x00
} UnkStruct52;
static_assert(sizeof(UnkStruct52) == 52);  // 52バイトなのは確定, FUN_080220e8 で オフセット 0x34 に 4バイト書き込み, また Entity4E69 の オフセット 0x78 にこの構造体があるが、 Entity4E69 は 172バイトなので、 172 - 0x78 = 52 なので、 52バイト

s32 FUN_080223f4(UnkStruct52* p, u32 val1, s32 val2);

// --------------------------------------------

typedef struct {
  u8 unk_0[60];
} UnkStruct60;
static_assert(sizeof(UnkStruct60) == 60);  // 根拠: FUN_080a8384

// --------------------------------------------

#endif  // __INCLUDE_STRUCT_H__
