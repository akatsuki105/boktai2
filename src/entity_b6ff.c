#include "entity.h"
#include "global.h"
#include "sprite_aux.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;      // 0x00, EntityB6FF_Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[92 - 0x2C];  // 0x2C, まだ未解析
} EntityB6FFElem;
static_assert(sizeof(EntityB6FFElem) == 92);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  u16 unk_18;                // 0x018, EntityB6FF_Create の引数, 読み手が見つかっていない
  u8 unk_1a[2];              // 0x01A, まだ未解析
  u8 unk_1c[36];             // 0x01C, _Init が stride 0xC で4回まわして u16 を3つずつ書く ('.c'/'.r'), 4回目は elems[0] の先頭に重なる
  EntityB6FFElem elems[24];  // 0x040, _Destroy が stride 0x5C で24枚 AuxSprite_Remove する
  u8 unk_8e0[2276 - 0x8E0];  // 0x8E0, まだ未解析
} EntityB6FF;
static_assert(sizeof(EntityB6FF) == 2276);

NAKED void FUN_080ac5b4(u32 param_1) { INCFUNC("asm/func/FUN_080ac5b4.inc"); }

void FUN_080ac5f4(void) {
  if (VM_SeekToNamedArg('n')) {
    FUN_080ac5b4(VM_GetValue());
  }
}

NAKED void FUN_080ac60c(u16 param_1, unknown* param_2, u16 param_3, u16 param_4) { INCFUNC("asm/func/FUN_080ac60c.inc"); }

NAKED void FUN_080ac698(void) { INCFUNC("asm/func/FUN_080ac698.inc"); }

NAKED void FUN_080ac738(unknown* param_1) { INCFUNC("asm/func/FUN_080ac738.inc"); }

NAKED void FUN_080ac874(unknown* param_1, Vec3* param_2, u16 param_3) { INCFUNC("asm/func/FUN_080ac874.inc"); }

NAKED s32 EntityB6FF_Update(EntityB6FF* p) { INCFUNC("asm/func/EntityB6FF_Update.inc"); }

s32 EntityB6FF_Destroy(EntityB6FF* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    AuxSprite_Remove(&p->elems[i].sprite);
  }
  return 0;
}

NAKED void FUN_080aca60(unknown* param_1) { INCFUNC("asm/func/FUN_080aca60.inc"); }

NAKED s32 EntityB6FF_Init(EntityB6FF* p) { INCFUNC("asm/func/EntityB6FF_Init.inc"); }

EntityB6FF* EntityB6FF_Create(u32 param_1) {
  EntityB6FF* p = CreateEntity(ENTITY_UNK_10, sizeof(EntityB6FF));

  if (p != NULL) {
    p->unk_18 = param_1;
    SetEntityRoutine(p, EntityB6FF_Update, EntityB6FF_Destroy);
    if (EntityB6FF_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
