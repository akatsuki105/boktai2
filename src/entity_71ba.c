#include "collision_map.h"
#include "entity.h"
#include "global.h"

struct Entity71BA;
typedef void Entity71BAFunc(struct Entity71BA* p);

// 条件 (プレイヤーのタイル位置・高さ・フォーム) が揃っている間だけ、あるタイルの当たり判定を上書きする
typedef struct Entity71BA {
  Entity e;                        // 0x00, ENTITY_UNK_8
  u16 unk_18;                      // 0x18, _Create の第1引数
  u8 unk_1a[2];                    // 0x1A, padding?
  u8 flags;                        // 0x1C, '.t=9', bit0/bit1 で fn を選び、bit3 で x/z のどちらを見るかが変わる
  bool8 tileOverrideActive;        // 0x1D, tileOverride を衝突マップに繋いであるか, _Destroy が立っていれば Map_RemoveTileOverride で外す
  u16 tileIdx;                     // 0x1E, gCollisionMap->rowOffsets[z] + x, '.p' の x/z から _Init が計算する
  s16 height;                      // 0x20, '.p[1]' (>> 8 した値)
  bool16 unk_22;                   // 0x22, FUN_080a035c が 0/1 を入れ替えるたび gPlayerPtr[0]->unk_3f3 を +1/-1 する
  MapTileOverride tileOverride;    // 0x24, _Destroy が Map_RemoveTileOverride に渡す
  u32 unk_34;                      // 0x34, '.R'
  Entity71BAFunc* updateCallback;  // 0x38, .flags bit0 なら FUN_080a01d8, bit1 なら FUN_080a035c, どちらでもなければ _UpdateTileOverride
} Entity71BA;
static_assert(sizeof(Entity71BA) == 60);

INCASM("asm/entity_71ba.inc");
