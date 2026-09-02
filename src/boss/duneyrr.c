#include "boss.h"
#include "entity.h"
#include "global.h"

typedef struct Duneyrr {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[1956 - 0x18];
} Duneyrr;
static_assert(sizeof(Duneyrr) == 1956);

s32 Duneyrr_Init(Duneyrr* p, unknown* param);
s32 Duneyrr_Update(Duneyrr* p);
s32 Duneyrr_Destroy(Duneyrr* p);

INCASM("asm/duneyrr.inc");

Duneyrr* Duneyrr_Create(unknown* param) {
  Duneyrr* p = FUN_08022a2c(BOSS_DUNEYRR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Duneyrr));
  if (p != NULL) {
    SetEntityRoutine(p, Duneyrr_Update, Duneyrr_Destroy);
    if (Duneyrr_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
