#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite.h"

typedef struct {
  AuxSprite spr;              // 0x000, _Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0xB0];            // 0x02C
  ParticleShadow shadow;      // 0x0DC, _Destroy が ParticleShadow_Remove に渡す
  u8 unk_11c[0x12E - 0x11C];  // 0x11C
  u8 unk_12e;                 // 0x12E, 2 だと FUN_080dd324 が 0 を返す
  s8 unk_12f;                 // 0x12F, 負だと FUN_080dd324 が 0 を返す
  u8 unk_130[2];              // 0x130
  u16 unk_132;                // 0x132, 0 だと FUN_080dd324 が 0 を返す, 0x59 を超えていると unk_13e に戻される
  u8 unk_134[0x13E - 0x134];  // 0x134
  u16 unk_13e;                // 0x13E, unk_132 の戻し先の値
  u8 unk_140[0x144 - 0x140];  // 0x140
} Entity080dd1f8Elem;
static_assert(sizeof(Entity080dd1f8Elem) == 324);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, SPRITE_BOMB
  AuxAnimFile* anim;             // 0x034, ANIM_871C
  Entity080dd1f8Elem elems[12];  // 0x038, 根拠: _Destroy の stride 0x144 × 12
  u32 activeMask;                // 0xF68, 使用中の elems のビットマスク, _Init が 0 にする
} Entity080dd1f8;
static_assert(sizeof(Entity080dd1f8) == 3948);

IWRAM_DATA Entity080dd1f8* gEntity080dd1f8 = NULL;  // 0x0300016C

const u8 u8_ARRAY_085ad338[4] = {0, 8, 4, 2};  // 0x085AD338

void FUN_080dc4a4(Entity080dd1f8* p, Entity080dd1f8Elem* elem) {}

NAKED void FUN_080dc4a8(Entity080dd1f8* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080dc4a8.inc"); }

// 判定の属性でタイマーを止めるか初期値に戻すかを決める
// 残差2命令 (28 対 30), 原典は elem を r12 に逃がして第2分岐で add r1, ip を使うが, こちらは r3 に置けてしまう (leaf なので r4-r7 は使えない)
// && / 条件の反転 / u16* ローカルは試済
NON_MATCH void FUN_080dc614(HitboxData* a, HitboxData* b, Entity080dd1f8Elem* elem) {
#ifdef NONMATCHING_C
  if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
    elem->unk_132 = 0;
  } else if (Hitbox_TestAttr(a, HBATTR_FROST)) {
    if (elem->unk_132 > 0x59) {
      elem->unk_132 = elem->unk_13e;
    }
  }
#else
  INCFUNC("asm/func/FUN_080dc614.inc");
#endif
}

NAKED void FUN_080dc650(Entity080dd1f8* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080dc650.inc"); }

NAKED s32 FUN_080dc764(Entity080dd1f8* p) { INCFUNC("asm/func/FUN_080dc764.inc"); }

NAKED void FUN_080dc7bc(Entity080dd1f8* p, Entity080dd1f8Elem* elem) { INCFUNC("asm/func/FUN_080dc7bc.inc"); }

NAKED void FUN_080dcdd8(Entity080dd1f8* p, Entity080dd1f8Elem* elem) { INCFUNC("asm/func/FUN_080dcdd8.inc"); }

NAKED s32 FUN_080dce8c(Entity080dd1f8* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080dce8c.inc"); }

void (*const PTR_ARRAY_085ad33c[3])(Entity080dd1f8*, Entity080dd1f8Elem*) = {
    FUN_080dc4a4,
    FUN_080dc7bc,
    FUN_080dcdd8,
};  // 0x085AD33C

NAKED s32 Entity080dd1f8_Update(Entity080dd1f8* p) { INCFUNC("asm/func/Entity080dd1f8_Update.inc"); }

NAKED s32 Entity080dd1f8_Destroy(Entity080dd1f8* p) { INCFUNC("asm/func/Entity080dd1f8_Destroy.inc"); }

s32 Entity080dd1f8_Init(Entity080dd1f8* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_BOMB);
  p->anim = GetFile(DIR_ANIMATION, ANIM_871C);
  p->activeMask = 0;
  gEntity080dd1f8 = p;
  return 0;
}

Entity080dd1f8* Entity080dd1f8_Create(void) {
  if (gEntity080dd1f8 == NULL) {
    Entity080dd1f8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080dd1f8));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080dd1f8_Update, Entity080dd1f8_Destroy);
      if (Entity080dd1f8_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080dd1f8;
}

void FUN_080dd244(void) { gEntity080dd1f8 = NULL; }

NAKED s32 FUN_080dd250(Entity080dd1f8* p) { INCFUNC("asm/func/FUN_080dd250.inc"); }

// elem が生きていて片付け待ちでもないかを返す
s32 FUN_080dd324(void* p) {
  Entity080dd1f8Elem* elem = p;

  if (elem == NULL) {
    return 0;
  }
  if (elem->unk_12f < 0) {
    return 0;
  }
  if (elem->unk_132 == 0) {
    return 0;
  }
  if (elem->unk_12e == 2) {
    return 0;
  }
  return 1;
}

NAKED void Cmd_AE71(void) { INCFUNC("asm/func/Cmd_AE71.inc"); }
