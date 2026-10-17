#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct EntityB87B {
  Entity e;                                    // 0x000, ENTITY_UNK_8
  MainSpriteGfx gfx;                           // 0x018
  MainSprite sprites[5];                       // 0x038
  u8 unk_218[4];                               // 0x218, まだ未解析
  s16 kind;                                    // 0x21C, '.i=0'
  u16 animTimer;                               // 0x21E, FUN_080c1b08 が毎フレーム +1
  u16 unk_220;                                 // 0x220, 0x11 と比べて START/A での送りを許すかを決める
  u8 unk_222[2];                               // 0x222, まだ未解析
  s16 step;                                    // 0x224, unk_226 と一致すると次へ進む数え上げ
  s16 unk_226;                                 // 0x226, step の上限
  u16 unk_228;                                 // 0x228, 終わるとき 0 を書く
  s16 finished;                                // 0x22A, 終わると 1 を書く
  u16 progress;                                // 0x22C, unk_22e と比べて進み具合を見る
  u16 unk_22e;                                 // 0x22E, progress の上限
  s32 scriptID;                                // 0x230, '.p=0'
  void (*updateCallback)(struct EntityB87B*);  // 0x234
} EntityB87B;
static_assert(sizeof(EntityB87B) == 568);

void FUN_080c1b08(EntityB87B* p) {
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  MainSprite_AdvanceAnim(&p->sprites[2], &p->gfx);
  MainSprite_AdvanceAnim(&p->sprites[4], &p->gfx);
  p->animTimer++;
}

NAKED void FUN_080c1b44(EntityB87B* p) { INCFUNC("asm/func/FUN_080c1b44.inc"); }

NAKED s32 EntityB87B_Update(EntityB87B* p) { INCFUNC("asm/func/EntityB87B_Update.inc"); }

s32 EntityB87B_Destroy(EntityB87B* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  return 0;
}

NAKED void FUN_080c1f5c(EntityB87B* p) { INCFUNC("asm/func/FUN_080c1f5c.inc"); }

NAKED void FUN_080c1f88(EntityB87B* p) { INCFUNC("asm/func/FUN_080c1f88.inc"); }

NAKED void FUN_080c2034(EntityB87B* p) { INCFUNC("asm/func/FUN_080c2034.inc"); }

NAKED void FUN_080c20fc(EntityB87B* p) { INCFUNC("asm/func/FUN_080c20fc.inc"); }

NAKED void FUN_080c250c(EntityB87B* p) { INCFUNC("asm/func/FUN_080c250c.inc"); }

NAKED s32 EntityB87B_Init(EntityB87B* p) { INCFUNC("asm/func/EntityB87B_Init.inc"); }

// 0xB87B
EntityB87B* EntityB87B_Create(void) {
  EntityB87B* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityB87B));

  if (p != NULL) {
    SetEntityRoutine(p, EntityB87B_Update, EntityB87B_Destroy);
    if (EntityB87B_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
