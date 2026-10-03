#include "entity.h"
#include "global.h"
#include "video.h"

// BG パレットの9枠 (u8_ARRAY_085aa964) を退避しておき、mask の立っている枠だけ gBgPlttBuffer[104] で塗りつぶす
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_12
  u16 mask;         // 0x18, _Init が '.f=0xFFFF' を入れる, bit i が立っている枠を塗りつぶす
  u8 unk_1a[2];     // 0x1A, 読み手も書き手も見つかっていない, padding?
  rgb555 saved[9];  // 0x1C, _SavePltt が退避した元の色, mask が立っていない枠はこれで書き戻す
  u8 unk_2e[14];    // 0x2E, 読み手も書き手も見つかっていない, saved が rgb555[16] なのかも？
} Entity5E27;
static_assert(sizeof(Entity5E27) == 60);

const u8 u8_ARRAY_085aa964[9] = {0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x67};  // 0x085AA964

INCASM("asm/entity_5e27.inc");
