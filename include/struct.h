#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "gba/gba.h"
#include "types.h"

// 用途不明の構造体　はここに置いておく

struct MainSprite;
struct AuxSprite;

// Collision or 座標計算 or スクリプト生成管理 のデータ?(まだわからない)
typedef struct Entity2UnkData {
  u16 id;                       // 0x00, EntityのID?
  u16 unk_2;                    // 0x02, フラグっぽい
  u8 unk_4;                     // 0x04
  u8 unk_5;                     // 0x05
  u8 unk_6[2];                  // 0x06, 読み手も書き手も未発見
  Vec3 pos;                     // 0x08
  Vec3 delta;                   // 0x10, FUN_0823b4b8 で .pos の変化量として使われている
  void* unk_18;                 // 0x18
  u16 unk_1c;                   // 0x1C
  u16 unk_1e;                   // 0x1E
  u32 unk_20;                   // 0x20
  void* unk_24;                 // 0x24
  struct AuxSprite* unk_28;     // 0x28, 非NULLなら FUN_0823b4b8 が pos を unk_28->pos に書き戻す, 根拠: FUN_0823b4b8 が +0x1C に8バイト書く
  struct MainSprite* unk_2c;    // 0x2C
  Vec3 unk_30;                  // 0x30, FUN_0823b47c が引数から8バイトまとめて書き、unk_2 に bit2 を立てる。読み手は未発見
  void* p_38;                   // 0x38, 親構造体のポインタ?
  struct Entity2UnkData* prev;  // 0x3C
  struct Entity2UnkData* next;  // 0x40
} Entity2UnkData;
static_assert(sizeof(Entity2UnkData) == 68);

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

// gEntity5941 の単方向リストのノード。敵は _Init で Entity5941_Register、_Destroy で FUN_0807f598 を呼んで出入りする
typedef struct Entity5941Node {
  void* owner;                  // 0x00, Entity5941_Register の第2引数 (敵の Entity2UnkData)
  u32 flags;                    // 0x04, bit0 が立っているノードだけ Entity5941_FindNearestInCone の対象になる
  void* fn;                     // 0x08, Entity5941_Register の第3引数
  struct Entity5941Node* next;  // 0x0C
} Entity5941Node;
static_assert(sizeof(Entity5941Node) == 16);

bool32 Entity5941_Register(unknown* node, unknown* owner, void* fn);

// --------------------------------------------

#endif  // __INCLUDE_STRUCT_H__
