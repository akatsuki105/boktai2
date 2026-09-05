#include "entity.h"
#include "global.h"

struct EntityC946;

typedef struct {
  s16 unk_0;  // 0x0
  u16 unk_2;  // 0x2
  u16 unk_4;  // 0x4
  u16 unk_6;  // 0x6
  u16 unk_8;  // 0x8
  s16 unk_a;  // 0xA
} Entity4DDFData;
static_assert(sizeof(Entity4DDFData) == 12);  // 0x08211db8

typedef struct Entity4DDF {
  Entity e;                    // 0x0, ENTITY_UNK_8
  Entity4DDFData list[64];     // 0x18, 0x08211e50 で 64回ループしている
  struct EntityC946* unk_318;  // 0x318, 0x08211eb0
  s32 unk_31c;                 // 0x31C, 0x08211e48
  s16 unk_320;                 // 0x320, 0x08211daa
  u16 unk_322;                 // 0x322
  u8 unk_324;                  // 0x324, PTR_ARRAY_08252738 の idx
  u8 unk_325[808 - 0x325];
} Entity4DDF;
static_assert(sizeof(Entity4DDF) == 808);

INCASM("asm/entity_4ddf.inc");

NAKED void FUN_08211d7c(Entity4DDF* p) { INCFUNC("asm/func/FUN_08211d7c.inc"); }

NAKED s32 Entity4DDF_Update(Entity4DDF* p) { INCFUNC("asm/func/Entity4DDF_Update.inc"); }

s32 Entity4DDF_Destroy(Entity4DDF* _) {
  return 0;
}

NAKED s32 Entity4DDF_Init(Entity4DDF* p, void* _) { INCFUNC("asm/func/Entity4DDF_Init.inc"); }

Entity4DDF* Entity4DDF_Create(void* _) {
  Entity4DDF* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity4DDF));
  if (p != NULL) {
    SetEntityRoutine(p, Entity4DDF_Update, Entity4DDF_Destroy);
    if (Entity4DDF_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
