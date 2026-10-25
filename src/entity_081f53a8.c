#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x000, priority 1, flags に bit0 を立てて作る
  AuxSpriteGfx gfx;        // 0x02C, SPRITE_D45E, パレット 250
  AuxAnimState animState;  // 0x048, 親の anim のアニメ 0x14
  HitboxData hitbox0;      // 0x058
  HitboxData hitbox1;      // 0x0A8
  u8 unk_f8[118];          // 0x0F8, まだ未解析
  u8 state;                // 0x16E, PTR_FUN_081f48ac_1_085ae578 の添字
  u8 unk_16f[3];           // 0x16F, まだ未解析
  u8 unk_172;              // 0x172, FUN_081f4650 が 1 を書く
  u8 unk_173[17];          // 0x173, まだ未解析
} Entity081f53a8Elem;
static_assert(sizeof(Entity081f53a8Elem) == 388);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  AuxAnimFile* anim;            // 0x018, ANIM_1DC3
  u32 activeMask;               // 0x01C, 立っているビットの枠だけ Update と Destroy が触る
  Entity081f53a8Elem elems[8];  // 0x020
} Entity081f53a8;
static_assert(sizeof(Entity081f53a8) == 3136);

static Entity081f53a8* gEntity081f53a8;  // 0x030001F8

NAKED void FUN_081f4650(unknown* param_1, unknown* param_2, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4650.inc"); }

NAKED void FUN_081f4704(unknown* param_1, u32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_081f4704.inc"); }

NAKED void FUN_081f4758(Entity081f53a8Elem* elem, u16 param_2, u16 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_081f4758.inc"); }

// 判定2つを今の位置で登録し直し, hitbox1 は unk_44 が残っている間だけ有効にする
void FUN_081f4858(Entity081f53a8Elem* elem) {
  HitboxData* hitbox0 = &elem->hitbox0;
  Vec3* pos = &elem->sprite.pos;
  HitboxData* hitbox1;

  Hitbox_SetPos(hitbox0, pos, 0);

  hitbox1 = &elem->hitbox1;
  Hitbox_SetPos(hitbox1, pos, 0);
  Hitbox_Register(hitbox0);
  Hitbox_Register(hitbox1);

  if (hitbox1->unk_44 != 0) {
    hitbox1->unk_44--;
    hitbox1->flags |= HBFLAG_HIDDEN;
  } else {
    Hitbox_ClearFlags(hitbox1, HBFLAG_HIDDEN);
  }
}

void FUN_081f48ac(Entity081f53a8* p, Entity081f53a8Elem* elem) {}

NAKED void FUN_081f48b0(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f48b0.inc"); }

NAKED void FUN_081f4a08(Vec3* pos, u32 angle) { INCFUNC("asm/func/FUN_081f4a08.inc"); }

NAKED void FUN_081f4af4(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4af4.inc"); }

NAKED void FUN_081f4d80(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f4d80.inc"); }

NAKED s32 FUN_081f5138(Entity081f53a8* p, Entity081f53a8Elem* elem) { INCFUNC("asm/func/FUN_081f5138.inc"); }

s32 FUN_081f519c(Entity081f53a8* p, Entity081f53a8Elem* elem) {
  s32 result = FUN_081f5138(p, elem);

  if (result == 0) {
    return 0;
  }
  return result;
}

NAKED void FUN_081f51ac(Vec3* pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, s16 param_7, s16 param_8, u16 param_9, u8 param_10) { INCFUNC("asm/func/FUN_081f51ac.inc"); }

void (*const PTR_ARRAY_085ae578[4])(Entity081f53a8*, Entity081f53a8Elem*) = {
    FUN_081f48ac,
    FUN_081f4af4,
    FUN_081f4d80,
    FUN_081f48b0,
};  // 0x085AE578

NAKED s32 Entity081f53a8_Update(Entity081f53a8* p) { INCFUNC("asm/func/Entity081f53a8_Update.inc"); }

// 残差8命令 (28 対 36), 原典はビット判定の結果を 1/0 として作ってから改めて 0 と比べる (0/1 の作り置き)
// 加えて原典は sprite と hitbox1 を別々のポインタで進めるが, gcc は elem 1本に +0xA8 を足す形を選ぶ
NON_MATCH s32 Entity081f53a8_Destroy(Entity081f53a8* p) {
#ifdef NONMATCHING_C
  s32 i;
  Entity081f53a8Elem* elem = &p->elems[0];

  for (i = 0; i < 8; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      AuxSprite_Remove(&elem->sprite);
      Hitbox_Unregister(&elem->hitbox1);
    }
  }
  gEntity081f53a8 = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity081f53a8_Destroy.inc");
#endif
}

s32 Entity081f53a8_Init(Entity081f53a8* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_1DC3);
  p->activeMask = 0;
  gEntity081f53a8 = p;
  return 0;
}

Entity081f53a8* Entity081f53a8_Create(void) {
  if (gEntity081f53a8 == NULL) {
    Entity081f53a8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081f53a8));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f53a8_Update, Entity081f53a8_Destroy);
      if (Entity081f53a8_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f53a8;
}

void FUN_081f53f4(void) { gEntity081f53a8 = NULL; }

NAKED void FUN_081f5400(void) { INCFUNC("asm/func/FUN_081f5400.inc"); }
