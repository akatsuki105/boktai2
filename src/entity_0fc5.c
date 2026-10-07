#include "entity.h"
#include "global.h"
#include "sprite_aux.h"
#include "sprite_main.h"

typedef struct Entity0FC5 {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[0x38 - 0x18];
  MainSprite sprite_38;  // 0x38, 根拠: Entity0FC5_RemoveSprites が unk_f4 == 0 のとき MainSprite_Remove に渡す
  AuxSprite sprite_98;   // 0x98, 根拠: Entity0FC5_RemoveSprites が unk_f4 != 0 のとき AuxSprite_Remove に渡す
  u8 unk_c4[0xF4 - 0xC4];
  s32 unk_f4;  // 0xF4, gEntity0FC5s での自分の添字, '.k' の値
  u8 unk_f8[0x13C - 0xF8];
  AuxSprite sprite_13c;  // 0x13C, 根拠: Entity0FC5_RemoveSprites が AuxSprite_Remove に渡す
  u8 unk_168[392 - 0x168];
} Entity0FC5;
static_assert(sizeof(Entity0FC5) == 392);

extern Entity0FC5* gEntity0FC5s[2];  // 0x03002C98

NAKED void FUN_0821a87c(void) { INCFUNC("asm/func/FUN_0821a87c.inc"); }

NAKED void FUN_0821a974(void) { INCFUNC("asm/func/FUN_0821a974.inc"); }

NAKED void FUN_0821a9d8(void) { INCFUNC("asm/func/FUN_0821a9d8.inc"); }

NAKED void FUN_0821aa3c(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821aa3c.inc"); }

NAKED s32 FUN_0821aac0(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821aac0.inc"); }

NAKED void FUN_0821abfc(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821abfc.inc"); }

NAKED void FUN_0821ae64(Entity0FC5* p, s32 val) { INCFUNC("asm/func/FUN_0821ae64.inc"); }

NAKED void FUN_0821aeb0(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821aeb0.inc"); }

// スプライトを描画リストから外す
void Entity0FC5_RemoveSprites(Entity0FC5* p) {
  if (p->unk_f4 == 0) {
    MainSprite_Remove(&p->sprite_38);
  } else {
    AuxSprite_Remove(&p->sprite_98);
  }

  AuxSprite_Remove(&p->sprite_13c);
}

NAKED s32 Entity0FC5_Update(Entity0FC5* p) { INCFUNC("asm/func/Entity0FC5_Update.inc"); }

// 描画を畳んで gEntity0FC5s の登録枠を空ける
s32 Entity0FC5_Destroy(Entity0FC5* p) {
  Entity0FC5_RemoveSprites(p);
  gEntity0FC5s[p->unk_f4] = NULL;
  return 0;
}

NAKED s32 Entity0FC5_Init(Entity0FC5* p) { INCFUNC("asm/func/Entity0FC5_Init.inc"); }

Entity0FC5* Entity0FC5_Create(void) {
  Entity0FC5* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0FC5));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0FC5_Update, Entity0FC5_Destroy);
    if (Entity0FC5_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void (*const PTR_ARRAY_085affa4[1])(Entity0FC5*) = {
    FUN_0821abfc,
};
