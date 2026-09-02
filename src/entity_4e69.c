#include "entity.h"
#include "global.h"

typedef struct Entity4E69 {
  Entity e;         // ENTITY_UNK_2
  s16 unk_18;       // 0x18
  s16 unk_1a;       // 0x1A
  u16 unk_1c;       // 0x1C
  u8 unk_1e;        // 0x1E
  u8 unk_1f;        // 0x1F
  u16 scriptID_20;  // 0x20, 0x08022308
  u8 unk_22;        // 0x22
  u8 unk_23;        // 0x23
  u8 unk_24;        // 0x24
  u8 unk_25[0x78 - 0x25];
  UnkStruct52 unk_78;  // 0x78
} Entity4E69;
static_assert(sizeof(Entity4E69) == 172);

extern Entity4E69* gEntity4E69;  // 0x03002B4C

INCASM("asm/entity_4e69.inc");
