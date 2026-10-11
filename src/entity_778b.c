#include "entity.h"
#include "global.h"
#include "video.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[412 - 0x18];
} Entity778B;
static_assert(sizeof(Entity778B) == 412);

IWRAM_DATA Entity778B* gEntity778B = NULL;  // 0x03000180

void Entity081eaf6c_Create(void);

const u8 u8_ARRAY_085ad374[80] = {
    0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0,
};  // 0x085AD374

NAKED s32 FUN_080e0404(s32 param_1, s32 param_2, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e0404.inc"); }

NAKED void FUN_080e0588(s32 param_1, s32 param_2, unknown* param_3, unknown* param_4) { INCFUNC("asm/func/FUN_080e0588.inc"); }

NAKED s32 FUN_080e05f0(s32 param_1, unknown* param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e05f0.inc"); }

NAKED s32 FUN_080e0748(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e0748.inc"); }

NAKED s32 FUN_080e0884(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e0884.inc"); }

NAKED s32 FUN_080e09b8(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_080e09b8.inc"); }

NAKED s32 FUN_080e0c28(unknown* param_1, unknown* param_2, unknown* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e0c28.inc"); }

NAKED void FUN_080e0fbc(void) { INCFUNC("asm/func/FUN_080e0fbc.inc"); }

NAKED s32 FUN_080e1080(unknown* param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e1080.inc"); }

NAKED s32 FUN_080e1100(Vec3* pos, Vec3* size, u32* out) { INCFUNC("asm/func/FUN_080e1100.inc"); }

NAKED s32 FUN_080e11a8(Vec3* pos, Vec3* size, s32 idx) { INCFUNC("asm/func/FUN_080e11a8.inc"); }

// 指定BGのタイルマップから (x, y) のエントリのアドレスを返す
BgMapEntry* FUN_080e1218(s32 bgIdx, s32 x, s32 y) {
  BgState* s = &gBgStates[bgIdx];
  BgMapEntry* map = s->tilemap;

  return map + (x & 31) + (y & 31) * 32;
}

NAKED void FUN_080e1238(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080e1238.inc"); }

NAKED void FUN_080e1280(void) { INCFUNC("asm/func/FUN_080e1280.inc"); }

NAKED s32 FUN_080e1334(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e1334.inc"); }

NAKED s32 FUN_080e138c(unknown* param_1) { INCFUNC("asm/func/FUN_080e138c.inc"); }

NAKED s32 Entity778B_Update(Entity778B* p) { INCFUNC("asm/func/Entity778B_Update.inc"); }

s32 Entity778B_Destroy(Entity778B* p) {
  gEntity778B = NULL;
  return 0;
}

s32 Entity778B_Init(Entity778B* p, s32 unused) {
  Entity081eaf6c_Create();
  gEntity778B = p;
  return 0;
}

// 0x778B
Entity778B* Entity778B_Create(s32 param_1) {
  if (gEntity778B == NULL) {
    Entity778B* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity778B));

    if (p != NULL) {
      SetEntityRoutine(p, Entity778B_Update, Entity778B_Destroy);
      if (Entity778B_Init(p, param_1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity778B;
}

NAKED void FUN_080e154c(void) { INCFUNC("asm/func/FUN_080e154c.inc"); }

void Entity778B_ClearGlobal(void) { gEntity778B = NULL; }

NAKED void FUN_080e16f4(void) { INCFUNC("asm/func/FUN_080e16f4.inc"); }
