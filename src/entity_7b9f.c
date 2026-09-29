#include "entity.h"
#include "global.h"
#include "shadow.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x00, Entity7B9F_Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0x8C - 0x2C];  // 0x2C, まだ未解析
  ParticleShadow shadow;   // 0x8C, unk_d2 が -1 でなければ _Destroy が ParticleShadow_Remove に渡す
  u8 unk_cc[4];            // 0xCC, まだ未解析
  s16 slotIdx;             // 0xD0, _AllocElem が確保したスロット番号
  s16 unk_d2;              // 0xD2, _AllocElem が -1 を入れる, -1 でなければ shadow が生きている
  u8 unk_d4[220 - 0xD4];   // 0xD4, まだ未解析
} Entity7B9FElem;
static_assert(sizeof(Entity7B9FElem) == 220);

typedef struct Entity7B9F {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u8 unk_18[32];            // 0x018, まだ未解析
  Entity7B9FElem elems[4];  // 0x038, _AllocElem が usedMask の空きビットを探して確保する
  u32 usedMask;             // 0x3A8, elems[i] が使用中なら bit i が立つ
} Entity7B9F;
static_assert(sizeof(Entity7B9F) == 940);

extern Entity7B9F* gEntity7B9F;  // 0x030001A0

INCASM("asm/entity_7b9f.inc");
