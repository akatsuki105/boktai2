#include "animation.h"
#include "entity.h"
#include "shadow.h"
#include "sprite.h"
#include "global.h"

// 12枠ぶんの演出要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  AuxSprite spr;          // 0x000, _Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0xB0];        // 0x02C
  ParticleShadow shadow;  // 0x0DC, _Destroy が ParticleShadow_Remove に渡す
  u8 unk_11c[0x28];       // 0x11C
} Entity080dd1f8Elem;
static_assert(sizeof(Entity080dd1f8Elem) == 324);

typedef struct Entity080dd1f8 {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, _Init が Video_GetAuxSprite(&p->gfx, 0xE74B) を呼ぶ
  AuxAnimFile* anim;             // 0x034, _Init が GetFile(0x922E, 0x871C) を入れる
  Entity080dd1f8Elem elems[12];  // 0x038, 根拠: _Destroy の stride 0x144 × 12
  u32 activeMask;                // 0xF68, 使用中の elems のビットマスク。_Init が 0 にする
} Entity080dd1f8;
static_assert(sizeof(Entity080dd1f8) == 3948);

extern Entity080dd1f8* gEntity080dd1f8;  // 0x0300016C

void FUN_080dc4a4(void) {}

NAKED void FUN_080dc4a8(Entity080dd1f8* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080dc4a8.inc"); }

NAKED void FUN_080dc614(Entity080dd1f8* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080dc614.inc"); }

NAKED void FUN_080dc650(Entity080dd1f8* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080dc650.inc"); }

NAKED s32 FUN_080dc764(Entity080dd1f8* p) { INCFUNC("asm/func/FUN_080dc764.inc"); }

NAKED void FUN_080dc7bc(Entity080dd1f8* p, u32 param_2) { INCFUNC("asm/func/FUN_080dc7bc.inc"); }

NAKED void FUN_080dcdd8(Entity080dd1f8* p, u32 param_2) { INCFUNC("asm/func/FUN_080dcdd8.inc"); }

NAKED s32 FUN_080dce8c(Entity080dd1f8* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080dce8c.inc"); }

NAKED s32 Entity080dd1f8_Update(Entity080dd1f8* p) { INCFUNC("asm/func/Entity080dd1f8_Update.inc"); }

NAKED s32 Entity080dd1f8_Destroy(Entity080dd1f8* p) { INCFUNC("asm/func/Entity080dd1f8_Destroy.inc"); }

NAKED s32 Entity080dd1f8_Init(Entity080dd1f8* p) { INCFUNC("asm/func/Entity080dd1f8_Init.inc"); }

NAKED Entity080dd1f8* Entity080dd1f8_Create(void) { INCFUNC("asm/func/Entity080dd1f8_Create.inc"); }

void FUN_080dd244(void) { gEntity080dd1f8 = NULL; }

NAKED s32 FUN_080dd250(Entity080dd1f8* p) { INCFUNC("asm/func/FUN_080dd250.inc"); }
