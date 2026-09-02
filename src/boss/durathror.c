#include "boss.h"
#include "entity.h"
#include "global.h"

// カワイイ
typedef struct Durathror {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[3620 - 0x18];
} Durathror;
static_assert(sizeof(Durathror) == 3620);

INCASM("asm/durathror.inc");

s32 Durathror_Init(Durathror* p, unknown* param);
s32 Durathror_Update(Durathror* p);
s32 Durathror_Destroy(Durathror* p);

Durathror* Durathror_Create(unknown* param) {
  Durathror* p = FUN_08022a2c(BOSS_DURATHROR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Durathror));
  if (p != NULL) {
    SetEntityRoutine(p, Durathror_Update, Durathror_Destroy);
    if (Durathror_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
