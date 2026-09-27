#include "collision_map.h"
#include "entity.h"
#include "global.h"

struct Entity71BA;

typedef void Entity71BAFunc(struct Entity71BA* p);

// 条件 (プレイヤーのタイル位置・高さ・フォーム) が揃っている間だけ、あるタイルの当たり判定を上書きする
typedef struct Entity71BA {
  Entity e;                      // 0x00, ENTITY_UNK_8
  u16 unk_18;                    // 0x18, _Create の第1引数
  u8 unk_1a[2];                  // 0x1A, 読み手も書き手も見つかっていない
  u8 flags;                      // 0x1C, _Init が VM キーワード 't' (既定 9) を入れる. bit0/bit1 で fn を選び、bit3 で x/z のどちらを見るかが変わる
  bool8 tileOverrideActive;      // 0x1D, tileOverride を衝突マップに繋いであるか. _Destroy が立っていれば FUN_082342a8 で外す
  u16 tileIdx;                   // 0x1E, gCollisionMap->rowOffsets[z] + x. VM キーワード 'p' の x/z から _Init が計算する
  s16 height;                    // 0x20, VM キーワード 'p' の2つ目 (>> 8 した値)
  bool16 unk_22;                 // 0x22, FUN_080a035c が 0/1 を入れ替えるたび gPlayerPtr[0]->unk_3f3 を +1/-1 する
  MapTileOverride tileOverride;  // 0x24, _Destroy が FUN_082342a8 に渡す
  u32 unk_34;                    // 0x34, _Init が VM キーワード 'R' を入れる
  Entity71BAFunc* fn;            // 0x38, _Update が毎フレーム呼ぶ. flags bit0 なら FUN_080a01d8, bit1 なら FUN_080a035c, どちらでもなければ _UpdateTileOverride
} Entity71BA;
static_assert(sizeof(Entity71BA) == 60);

INCASM("asm/entity_71ba.inc");
