#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

// _Create が Entity080d84f8_Create と FUN_080d8568 と FUN_080d85d8 の 3つある (_Init, _Update, _Destroy は共有)
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_10
  AuxSprite sprite;   // 0x18, poseIdx は timer >> 2
  AuxSpriteGfx gfx;   // 0x44
  HitboxData hitbox;  // 0x60, timer が 8 未満の間だけ毎フレーム登録し直す
  u16 delay;          // 0xB0, 0 になるまで何もしない
  u16 timer;          // 0xB2, 毎フレーム +1, 0x17 を越えると自分を消す
} Entity080d84f8;
static_assert(sizeof(Entity080d84f8) == 180);

NAKED s32 Entity080d84f8_Update(Entity080d84f8* p) { INCFUNC("asm/func/Entity080d84f8_Update.inc"); }

s32 Entity080d84f8_Destroy(Entity080d84f8* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

NAKED void FUN_080d83a8(AuxSprite* sprite, AuxSpriteGfx* gfx, Vec3* pos, u32 param_4) { INCFUNC("asm/func/FUN_080d83a8.inc"); }

NAKED void FUN_080d8400(Entity080d84f8* p, HitboxData* hitbox, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) { INCFUNC("asm/func/FUN_080d8400.inc"); }

NAKED s32 Entity080d84f8_Init(Entity080d84f8* p, Vec3* pos, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u16 delay) { INCFUNC("asm/func/Entity080d84f8_Init.inc"); }

NAKED Entity080d84f8* Entity080d84f8_Create(Vec3* pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/Entity080d84f8_Create.inc"); }

NAKED Entity080d84f8* FUN_080d8568(Vec3* pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_080d8568.inc"); }

NAKED Entity080d84f8* FUN_080d85d8(Vec3* pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080d85d8.inc"); }
