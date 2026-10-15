#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

// 画面下から湧いて左右に揺れながら上がっていく粒, 32個を使い回す
typedef struct {
  bool8 active;      // 0x00, 立っている枠だけ動かす
  u8 riseSpeed;      // 0x01, (添字 & 1) + 3 + 乱数(0..1), 上昇量に掛かる
  s8 swayAmp;        // 0x02, ((乱数 & 3) + 5 - riseSpeed) >> 2, 左右の振れ幅
  u8 angleStep;      // 0x03, (乱数 & 7) + 1, angle に毎フレーム足す
  s8 angle;          // 0x04, gSineTable の添字, 左右の揺れと上昇量の両方に使う
  u8 unk_5;          // 0x05, 触られていない
  u16 unk_6;         // 0x06, 0 を書くだけ
  AuxSprite sprite;  // 0x08, y が -0x13 を下回ると画面下へ戻して作り直す
} Entity78C9Elem;
static_assert(sizeof(Entity78C9Elem) == 52);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_8
  u8 unk_18[4];              // 0x018, 触られていない
  AuxSpriteGfx gfx;          // 0x01C, SPRITE_DVALIN_2E7B
  Entity78C9Elem elems[32];  // 0x038
} Entity78C9;
static_assert(sizeof(Entity78C9) == 1720);

const u8 u8_ARRAY_085aa988[4] = {8, 14, 9, 15};  // 0x085AA988

NAKED void Entity78C9Elem_Respawn(Entity78C9* p, Entity78C9Elem* elem, u8 index) { INCFUNC("asm/func/Entity78C9Elem_Respawn.inc"); }

NAKED void Entity78C9Elem_Init(Entity78C9* p, Entity78C9Elem* elem, u32 index) { INCFUNC("asm/func/Entity78C9Elem_Init.inc"); }

NAKED void Entity78C9Elem_Destroy(Entity78C9* p, Entity78C9Elem* elem, u32 index) { INCFUNC("asm/func/Entity78C9Elem_Destroy.inc"); }

NAKED s32 Entity78C9_Update(Entity78C9* p) { INCFUNC("asm/func/Entity78C9_Update.inc"); }

NAKED s32 Entity78C9_Destroy(Entity78C9* p) { INCFUNC("asm/func/Entity78C9_Destroy.inc"); }

NAKED s32 Entity78C9_Init(Entity78C9* p) { INCFUNC("asm/func/Entity78C9_Init.inc"); }

NAKED Entity78C9* Entity78C9_Create(void) { INCFUNC("asm/func/Entity78C9_Create.inc"); }
