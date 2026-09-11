#include "entity.h"
#include "global.h"

// 木のドア と 鍵付きの青い扉　と 鉄格子の扉 のグラフィックをロードしているのでドア?
typedef struct {
  Entity e;          // ENTITY_UNK_9
  u16 subroutineID;  // 0x18
  u16 unk_1a;        // 0x1A
  u8 unk_1c;         // 0x1C
  u8 unk_1d;         // 0x1D
  u8 unk_1e[1076 - 0x1E];
} Entity6D69;
static_assert(sizeof(Entity6D69) == 1076);

INCASM("asm/entity_6d69.inc");
