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

NAKED Entity7B9FElem* Entity7B9F_AllocElem(Entity7B9F* p) { INCFUNC("asm/func/Entity7B9F_AllocElem.inc"); }

NAKED void FUN_081d822c(Entity7B9FElem* e) { INCFUNC("asm/func/FUN_081d822c.inc"); }

NAKED void FUN_081d8298(Entity7B9FElem* e) { INCFUNC("asm/func/FUN_081d8298.inc"); }

void nop_081d8368(void) {}

NAKED void FUN_081d836c(Entity7B9FElem* e) { INCFUNC("asm/func/FUN_081d836c.inc"); }

NAKED void FUN_081d8560(Entity7B9FElem* e) { INCFUNC("asm/func/FUN_081d8560.inc"); }

NAKED void FUN_081d85a8(Entity7B9FElem* e) { INCFUNC("asm/func/FUN_081d85a8.inc"); }

NAKED void FUN_081d8714(Entity7B9FElem* e, s32 param_2) { INCFUNC("asm/func/FUN_081d8714.inc"); }

NAKED s32 Entity7B9F_Update(Entity7B9F* p) { INCFUNC("asm/func/Entity7B9F_Update.inc"); }

NAKED s32 Entity7B9F_Destroy(Entity7B9F* p) { INCFUNC("asm/func/Entity7B9F_Destroy.inc"); }

s32 Entity7B9F_Init(Entity7B9F* p) {
  gEntity7B9F = p;
  return 0;
}

Entity7B9F* Entity7B9F_Create(void) {
  if (gEntity7B9F == NULL) {
    Entity7B9F* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity7B9F));

    if (p != NULL) {
      SetEntityRoutine(p, Entity7B9F_Update, Entity7B9F_Destroy);
      if (Entity7B9F_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity7B9F;
}

void nop_081d88a4(void) {}

NAKED void FUN_081d88a8(Entity7B9FElem* e, u16 param_2, u16 param_3) { INCFUNC("asm/func/FUN_081d88a8.inc"); }

NAKED void FUN_081d8948(void) { INCFUNC("asm/func/FUN_081d8948.inc"); }

void ClearEntity7B9F(void) { gEntity7B9F = NULL; }
