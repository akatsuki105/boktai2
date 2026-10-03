#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;       // 0x00
  u8 unk_2c[100 - 0x2C];  // 0x2C, まだ未解析
} Entity5292Elem;
static_assert(sizeof(Entity5292Elem) == 100);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  u16 unk_18;                // 0x018, _Create の引数
  u8 unk_1a[0x024 - 0x01A];  // 0x01A, まだ未解析
  u16 unk_24;                // 0x024, _Init が gRandomTable から 0..31 の乱数を入れる
  u16 unk_26;                // 0x026, _Init が 0x60 を入れる
  u8 unk_28[2];              // 0x028, まだ未解析
  u16 unk_2a;                // 0x02A, _Init が '.p=6' を入れる
  Entity5292Elem elems[16];  // 0x02C, _Destroy が stride 0x64 で16枚 AuxSprite_Remove する
} Entity5292;
static_assert(sizeof(Entity5292) == 1644);

INCASM("asm/entity_5292.inc");
