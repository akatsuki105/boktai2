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

// FUN_08230eec が u32_ARRAY_0203f400 のテーブルに登録するレコード
typedef struct {
  u32 id : 16;
  u32 unk_02 : 8;
  u32 count : 8;
  u16* values;
} Unk_0203f400;
static_assert(sizeof(Unk_0203f400) == 8);

// --------------------------------------------

// Entity4E69 で管理されてる?
typedef struct UnkStruct52 {
  u16 unk_0;                 // 0x00
  u8 unk_2;                  // 0x02
  u8 unk_3;                  // 0x03
  u8 unk_4[2];               // 0x04
  u8 unk_6[2];               // 0x06, Entity4E69.unk_24 (0 or 1) で添字される, 根拠: FUN_0802216c
  struct UnkStruct08daadb8* unk_8[2][4];  // 0x08, 同上, 根拠: FUN_08022128
  u8 unk_28[0x2C - 0x28];    // 0x28
  struct UnkStruct52* prev;  // 0x2C
  struct UnkStruct52* next;  // 0x30
} UnkStruct52;
static_assert(sizeof(UnkStruct52) == 52);  // 52バイトなのは確定, FUN_080220e8 で オフセット 0x34 に 4バイト書き込み, また Entity4E69 の オフセット 0x78 にこの構造体があるが、 Entity4E69 は 172バイトなので、 172 - 0x78 = 52 なので、 52バイト

s32 FUN_080223f4(UnkStruct52* p, u32 val1, s32 val2);
s32 FUN_08022428(UnkStruct52* p);

#endif  // __INCLUDE_STRUCT_H__
