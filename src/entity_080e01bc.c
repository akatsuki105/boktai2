#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x00
  u8 unk_2c[0x58 - 0x2C];  // 0x2C, まだ未解析
  u16 timer;               // 0x58, 0 でない間は毎フレーム減り, 0 になった瞬間に sprite を隠す
  u8 unk_5a[0x5C - 0x5A];  // 0x5A, まだ未解析
} Entity080e01bcSprite;
static_assert(sizeof(Entity080e01bcSprite) == 92);

typedef struct {
  AuxSprite sprite;                 // 0x000, pos は FUN_080dfeb0 の第1引数の写し
  AuxAnimState anim;                // 0x02C
  Entity080e01bcSprite sprites[2];  // 0x03C
  HitboxData hitbox_f4;             // 0x0F4
  HitboxData hitbox_144;            // 0x144
  u8 unk_194[0x19C - 0x194];        // 0x194, まだ未解析
  u8 unk_19c;                       // 0x19C
  u8 unk_19d;                       // 0x19D
  u8 unk_19e;                       // 0x19E
  u8 unk_19f;                       // 0x19F
  u16 unk_1a0;                      // 0x1A0
  u8 unk_1a2[0x1A4 - 0x1A2];        // 0x1A2, まだ未解析
  AuxAnimFile* animFile;            // 0x1A4, ANIM_8DC7
  u32 unk_1a8;                      // 0x1A8, 初期値 120
  u16 unk_1ac;                      // 0x1AC
  u8 state;                         // 0x1AE, PTR_ARRAY_085ad364 の添字, 1 なら Cmd_E0E1 が 2 にする
  s8 slotIdx;                       // 0x1AF, unk_38 上の自分のビット番号
  u16 timer;                        // 0x1B0, stateBegun が立っていると 0 に戻る
  bool8 stateBegun;                 // 0x1B2
  u8 unk_1b3;                       // 0x1B3
} Entity080e01bcElem;
static_assert(sizeof(Entity080e01bcElem) == 436);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_EFF_SHAIAN_SPIN
  u8 unk_34[0x38 - 0x34];       // 0x034, まだ未解析
  u32 unk_38;                   // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity080e01bcElem elems[8];  // 0x03C
} Entity080e01bc;
static_assert(sizeof(Entity080e01bc) == 3548);

IWRAM_DATA Entity080e01bc* gEntity080e01bc = NULL;  // 0x0300017C

static inline bool8 Entity080e01bc_IsActive(Entity080e01bc* p, s32 i) {
  if (TEST_FLAGS(p->unk_38, 1 << i)) return TRUE;
  return FALSE;
}

void nop_080dfa20(Entity080e01bc*, Entity080e01bcElem*);
void FUN_080dfa24(Entity080e01bc*, Entity080e01bcElem*);
void FUN_080dfbe4(Entity080e01bc*, Entity080e01bcElem*);
void FUN_080dfde8(Entity080e01bc*, Entity080e01bcElem*);

void (*const PTR_ARRAY_085ad364[4])(Entity080e01bc*, Entity080e01bcElem*) = {
    nop_080dfa20,
    FUN_080dfa24,
    FUN_080dfbe4,
    FUN_080dfde8,
};  // 0x085AD364

NAKED void FUN_080df4c4(Entity080e01bcElem* elem) { INCFUNC("asm/func/FUN_080df4c4.inc"); }

NAKED void FUN_080df540(Entity080e01bcElem* elem) { INCFUNC("asm/func/FUN_080df540.inc"); }

void FUN_080df6d4(Entity080e01bcElem* elem) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (elem->sprites[i].timer != 0) {
      elem->sprites[i].timer--;
      if (elem->sprites[i].timer == 0) {
        elem->sprites[i].sprite.flags |= SPRFLAG_HIDDEN;
        elem->sprites[i].sprite.flags &= ~SPRFLAG_AFFINE;
      }
    }
  }
}

void FUN_080df714(Entity080e01bcElem* elem) {
  s32 i;

  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&elem->sprites[i].sprite);
  }
}

void FUN_080df730(s32 param_1, s32 param_2, Entity080e01bcElem* elem) {
  HitboxData* hb;

  elem->state = 2;
  elem->stateBegun = 1;

  hb = &elem->hitbox_f4;
  hb->flags |= HBFLAG_HIDDEN;
  hb = &elem->hitbox_144;
  hb->flags |= HBFLAG_HIDDEN;
}

void FUN_080df760(s32 param_1, s32 param_2, Entity080e01bcElem* elem) {
  HitboxData* hb;

  elem->state = 2;
  elem->stateBegun = 1;

  hb = &elem->hitbox_f4;
  hb->flags |= HBFLAG_HIDDEN;
  hb = &elem->hitbox_144;
  hb->flags |= HBFLAG_HIDDEN;
}

NAKED void FUN_080df790(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080df790.inc"); }

void FUN_080df880(Entity080e01bcElem* elem) {
  Hitbox_SetPos(&elem->hitbox_f4, &elem->sprite.pos, 0);
  Hitbox_SetPos(&elem->hitbox_144, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox_f4);
}

// 空いている枠を1つ確保して返す, 空きが無ければ NULL
Entity080e01bcElem* FUN_080df8b0(Entity080e01bc* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity080e01bc_IsActive(p, i)) {
      Entity080e01bcElem* elem = &p->elems[i];

      p->unk_38 |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

NAKED void FUN_080df900(Entity080e01bcElem* elem) { INCFUNC("asm/func/FUN_080df900.inc"); }

void nop_080dfa20(Entity080e01bc* p, Entity080e01bcElem* elem) {}

NAKED void FUN_080dfa24(Entity080e01bc* p, Entity080e01bcElem* elem) { INCFUNC("asm/func/FUN_080dfa24.inc"); }

NAKED void FUN_080dfbe4(Entity080e01bc* p, Entity080e01bcElem* elem) { INCFUNC("asm/func/FUN_080dfbe4.inc"); }

NAKED void FUN_080dfde8(Entity080e01bc* p, Entity080e01bcElem* elem) { INCFUNC("asm/func/FUN_080dfde8.inc"); }

NAKED void FUN_080dfeb0(unknown* p, unknown* param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11) { INCFUNC("asm/func/FUN_080dfeb0.inc"); }

NAKED s32 Entity080e01bc_Update(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Update.inc"); }

NAKED s32 Entity080e01bc_Destroy(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Destroy.inc"); }

s32 Entity080e01bc_Init(Entity080e01bc* p) {
  p->unk_38 = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_SHAIAN_SPIN);
  gEntity080e01bc = p;
  return 0;
}

Entity080e01bc* Entity080e01bc_Create(void) {
  if (gEntity080e01bc == NULL) {
    Entity080e01bc* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080e01bc));

    if (p != NULL) {
      SetEntityRoutine(p, Entity080e01bc_Update, Entity080e01bc_Destroy);
      if (Entity080e01bc_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080e01bc;
}

void Entity080e01bc_ClearGlobal(void) { gEntity080e01bc = NULL; }

// 発動待ちの枠を 3 に置き換える
void FUN_080e0214(void) {
  Entity080e01bc* p = gEntity080e01bc;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 8; i++) {
    if (p->elems[i].state == 1) {
      p->elems[i].state = 3;
    }
  }
}

// 0xE0E1, 発動待ちの枠を発動済みにする
void Cmd_E0E1(void) {
  Entity080e01bc* p = gEntity080e01bc;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 8; i++) {
    if (p->elems[i].state == 1) {
      p->elems[i].state = 2;
      p->elems[i].stateBegun = 1;
    }
  }
}

// 0x983A
NAKED void Cmd_983A(void) { INCFUNC("asm/func/Cmd_983A.inc"); }
