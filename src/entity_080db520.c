#include "animation.h"
#include "entity.h"
#include "file.h"
#include "hitbox.h"
#include "sprite.h"
#include "global.h"

// 8枠ぶんの要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  AuxSprite spr;      // 0x00, _Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0x14];    // 0x2C
  u16 unk_40;         // 0x40, FUN_080dacac が bit1 を立てる
  u8 unk_42[10];      // 0x42
  HitboxData hitbox;  // 0x4C, _Destroy が Hitbox_Unregister に渡す
  u8 unk_9c[8];       // 0x9C
} Entity080db520Elem;
static_assert(sizeof(Entity080db520Elem) == 164);

typedef struct Entity080db520 {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018
  AuxAnimFile* anim;            // 0x034
  u32 activeMask;               // 0x038, 使用中の elems のビットマスク
  Entity080db520Elem elems[8];  // 0x03C, 根拠: _Destroy の stride 0xA4 × 8
} Entity080db520;
static_assert(sizeof(Entity080db520) == 1372);

extern Entity080db520* gEntity080db520;  // 0x03000160

NAKED s32 FUN_080da9c4(Entity080db520* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) { INCFUNC("asm/func/FUN_080da9c4.inc"); }

NAKED void FUN_080dab9c(Entity080db520* p) { INCFUNC("asm/func/FUN_080dab9c.inc"); }

NAKED void FUN_080dabe4(Entity080db520* p) { INCFUNC("asm/func/FUN_080dabe4.inc"); }

void FUN_080dac20(void) {}

NAKED void FUN_080dac24(Entity080db520* p, u32 param_2) { INCFUNC("asm/func/FUN_080dac24.inc"); }

void FUN_080dacac(Entity080db520* p, u32 param_2, Entity080db520Elem* elem) {
  elem->unk_40 |= 2;
  elem->hitbox.flags |= 4;
}

NAKED void FUN_080dacc4(Entity080db520* p) { INCFUNC("asm/func/FUN_080dacc4.inc"); }

NAKED s32 FUN_080dad4c(Entity080db520* p) { INCFUNC("asm/func/FUN_080dad4c.inc"); }

NAKED s32 FUN_080dad94(Entity080db520* p) { INCFUNC("asm/func/FUN_080dad94.inc"); }

NAKED void FUN_080dadec(Entity080db520* p) { INCFUNC("asm/func/FUN_080dadec.inc"); }

NAKED void FUN_080dae60(Entity080db520* p, u32 param_2) { INCFUNC("asm/func/FUN_080dae60.inc"); }

NAKED void FUN_080db040(Entity080db520* p, u32 param_2) { INCFUNC("asm/func/FUN_080db040.inc"); }

NAKED void FUN_080db0f8(Entity080db520* p) { INCFUNC("asm/func/FUN_080db0f8.inc"); }

NAKED void FUN_080db260(Entity080db520* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080db260.inc"); }

NAKED s32 FUN_080db290(Entity080db520* p, u32 param_2) { INCFUNC("asm/func/FUN_080db290.inc"); }

NAKED s32 Entity080db520_Update(Entity080db520* p) { INCFUNC("asm/func/Entity080db520_Update.inc"); }

NAKED s32 Entity080db520_Destroy(Entity080db520* p) { INCFUNC("asm/func/Entity080db520_Destroy.inc"); }

s32 Entity080db520_Init(Entity080db520* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_1C1B);
  p->activeMask = 0;
  p->anim = GetFile(DIR_ANIMATION, 0x3DC2);
  gEntity080db520 = p;
  return 0;
}

Entity080db520* Entity080db520_Create(void) {
  if (gEntity080db520 == NULL) {
    Entity080db520* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080db520));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080db520_Update, Entity080db520_Destroy);
      if (Entity080db520_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080db520;
}

void FUN_080db56c(void) { gEntity080db520 = NULL; }

NAKED void FUN_080db578(void) { INCFUNC("asm/func/FUN_080db578.inc"); }

NAKED void FUN_080db780(void) { INCFUNC("asm/func/FUN_080db780.inc"); }
