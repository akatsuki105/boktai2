#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x00
  AuxSpriteGfx gfx;        // 0x2C, SPRITE_CC88
  s16 x;                   // 0x48, 下位4ビットが小数, 0xFFF で折り返すので画面の 0..255 を回る
  s16 y;                   // 0x4A, x と同じ
  u8 unk_4c[0x50 - 0x4C];  // 0x4C, 読み手も書き手も未発見
  s16 velX;                // 0x50, 毎フレーム x に足す, angle と speed から作る
  s16 velY;                // 0x52, 毎フレーム y に足す
  u8 unk_54[0x5C - 0x54];  // 0x54, 読み手も書き手も未発見
  u16 animTimer;           // 0x5C, 毎フレーム +1, (animTimer >> 2) & 3 が sprite.metaspriteIdx
  u16 turnTimer;           // 0x5E, 15..30, 0 になると向きと速さを選び直す
  u16 angle;               // 0x60, Entity5292.baseAngle の写し, 向きを選ぶときの中心
  u16 speed;               // 0x62, 16..31, 向きを選ぶときの速さの基準
} Entity5292Elem;
static_assert(sizeof(Entity5292Elem) == 100);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  u16 id;                    // 0x018
  u8 unk_1a[0x024 - 0x01A];  // 0x01A, まだ未解析
  u16 unk_24;                // 0x024, _Init が gRandomTable から 0..31 の乱数を入れる
  u16 baseAngle;             // 0x026, 0x60, 各要素の angle の初期値
  u8 unk_28[2];              // 0x028, まだ未解析
  u16 plttOffset;            // 0x02A, '.p=6', 要素のパレットは 0x1D3 + plttOffset
  Entity5292Elem elems[16];  // 0x02C, _Destroy が stride 0x64 で16枚 AuxSprite_Remove する
} Entity5292;
static_assert(sizeof(Entity5292) == 1644);

NAKED void Entity5292_UpdateElem(Entity5292Elem* elem) { INCFUNC("asm/func/Entity5292_UpdateElem.inc"); }

NAKED s32 Entity5292_Update(Entity5292* p) { INCFUNC("asm/func/Entity5292_Update.inc"); }

NAKED s32 Entity5292_Destroy(Entity5292* p) { INCFUNC("asm/func/Entity5292_Destroy.inc"); }

NAKED void Entity5292_InitElems(Entity5292* p) { INCFUNC("asm/func/Entity5292_InitElems.inc"); }

NAKED s32 Entity5292_Init(Entity5292* p) { INCFUNC("asm/func/Entity5292_Init.inc"); }

NAKED Entity5292* Entity5292_Create(u32 id) { INCFUNC("asm/func/Entity5292_Create.inc"); }
