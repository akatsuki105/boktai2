#include "entity.h"
#include "global.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// BG パレットの9枠 (sBgPlttSlots) を退避しておき、mask の立っている枠だけ gBgPlttBuffer[104] で塗りつぶす
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_12
  u16 mask;         // 0x18, _Init が '.f=0xFFFF' を入れる, bit i が立っている枠を塗りつぶす
  u8 unk_1a[2];     // 0x1A, 読み手も書き手も見つかっていない, padding?
  rgb555 saved[9];  // 0x1C, _SavePltt が退避した元の色, mask が立っていない枠はこれで書き戻す
  u8 unk_2e[14];    // 0x2E, 読み手も書き手も見つかっていない, saved が rgb555[16] なのかも？
} Entity5E27;
static_assert(sizeof(Entity5E27) == 60);

bool32 FUN_0800271c(void);

const u8 sBgPlttSlots[9] = {0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x67};  // 0x085AA964, 退避/塗りつぶしの対象になる gBgPlttBuffer の色番号

bool32 Entity5E27_TestSlot(Entity5E27* p, s32 slot) { return p->mask & (1 << slot); }

// 対象の9枠の色を退避する
void Entity5E27_SavePltt(Entity5E27* p) {
  rgb555* pltt = gBgPlttBuffer;
  s32 i;

  for (i = 0; i < 9; i++) {
    p->saved[i] = pltt[sBgPlttSlots[i]];
  }
}

// mask の立っている枠を gBgPlttBuffer[104] で塗りつぶし、立っていない枠は退避した色に戻す
void Entity5E27_ApplyPltt(Entity5E27* p) {
  rgb555* pltt = gBgPlttBuffer;
  s32 i;

  for (i = 0; i < 9; i++) {
    if (Entity5E27_TestSlot(p, i)) {
      pltt[sBgPlttSlots[i]] = pltt[104];
    } else {
      pltt[sBgPlttSlots[i]] = p->saved[i];
    }
  }
}

// 時間帯の区切り (夜明け前後と夜) に差しかかったときだけ退避し直して塗り直す
s32 Entity5E27_Update(Entity5E27* p) {
  if (FUN_0800271c()) {
    u32 span = Time_GetSpanOfTime();

    if (span == 4 || span == 5 || span == 0) {
      Entity5E27_SavePltt(p);
      Entity5E27_ApplyPltt(p);
    }
  }

  return 0;
}

s32 Entity5E27_Destroy(Entity5E27* p) { return 0; }

s32 Entity5E27_Init(Entity5E27* p) {
  p->mask = VM_GetNamedArgValue('f', 0xFFFF);
  Entity5E27_SavePltt(p);
  return 0;
}

Entity5E27* Entity5E27_Create(void) {
  Entity5E27* p = CreateEntity(ENTITY_UNK_12, sizeof(Entity5E27));

  if (p != NULL) {
    SetEntityRoutine(p, Entity5E27_Update, Entity5E27_Destroy);
    if (Entity5E27_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
