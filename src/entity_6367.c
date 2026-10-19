#include "entity.h"
#include "global.h"
#include "sprite.h"

// SPRITE_EVENT_SUN_RAY をロードしている
typedef struct Entity6367 {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx;                           // 0x018
  MainSprite sprites[3];                       // 0x038
  u32 unk_158;                                 // 0x158
  s32 scriptID_15c;                            // 0x15C
  s32 mode;                                    // 0x160, PTR_ARRAY_085affa0 の idx
  u32 timer_164;                               // 0x164, unk_158 の bit0 が立っていない間だけ毎フレーム +1
  u32 unk_168;                                 // 0x168, まだ未解析
  u32 timer_16c;                               // 0x16C, unk_158 の bit1 が立っていない間だけ毎フレーム +1
  u2_6 scaleX;                                 // 0x170, 3枚のスプライトへ写す拡大率
  u2_6 scaleY;                                 // 0x171, 同上
  u8 unk_172[0x190 - 0x172];                   // 0x172, まだ未解析
  void (*updateCallback)(struct Entity6367*);  // 0x190
} Entity6367;
static_assert(sizeof(Entity6367) == 404);

// 拡大率を3枚のスプライトへ配る
void FUN_0821a2bc(Entity6367* p) {
  p->sprites[0].scaleX = p->scaleX;
  p->sprites[0].scaleY = p->scaleY;
  p->sprites[1].scaleX = p->scaleX;
  p->sprites[1].scaleY = p->scaleY;
  p->sprites[2].scaleX = p->scaleX;
  p->sprites[2].scaleY = p->scaleY;
}

NAKED void FUN_0821a308(Entity6367* p) { INCFUNC("asm/func/FUN_0821a308.inc"); }

void (*const PTR_ARRAY_085affa0[1])(Entity6367*) = {
    FUN_0821a308,
};  // 0x085AFFA0

NAKED void FUN_0821a5d4(Entity6367* p) { INCFUNC("asm/func/FUN_0821a5d4.inc"); }

void Entity6367_Destroy_Internal(Entity6367* p) {
  MainSprite_Remove(p->sprites);
  MainSprite_Remove(p->sprites + 1);
  MainSprite_Remove(p->sprites + 2);
}

NAKED void FUN_0821a714(Entity6367* p, s32 idx) { INCFUNC("asm/func/FUN_0821a714.inc"); }

s32 Entity6367_Update(Entity6367* p) {
  if (!(p->unk_158 & 1)) {
    p->timer_164++;
  }
  if (!(p->unk_158 & 2)) {
    p->timer_16c++;
  }
  p->updateCallback(p);
  return 0;
}

s32 Entity6367_Destroy(Entity6367* p) {
  Entity6367_Destroy_Internal(p);
  return 0;
}

NAKED s32 Entity6367_Init(Entity6367* p) { INCFUNC("asm/func/Entity6367_Init.inc"); }

// 0x6367, HashName("エンディング"), SPRITE_EVENT_SUN_RAY は ラスボス撃破時に使うので、 エンディングで合ってる可能性は高い
Entity6367* Entity6367_Create(void) {
  Entity6367* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity6367));
  if (p != NULL) {
    SetEntityRoutine(p, Entity6367_Update, Entity6367_Destroy);
    if (Entity6367_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
