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
  Entity080e01bcSprite sprites[2];  // 0x000
  HitboxData hitbox_b8;             // 0x0B8, FUN_080df880 が Hitbox_Register する
  HitboxData hitbox_108;            // 0x108
  u8 unk_158[0x172 - 0x158];        // 0x158, まだ未解析
  u8 unk_172;                       // 0x172
  u8 unk_173[0x176 - 0x173];        // 0x173, まだ未解析
  u8 unk_176;                       // 0x176
  u8 unk_177[0x1AE - 0x177];        // 0x177, まだ未解析
  u8 unk_1ae;                       // 0x1AE, 1 なら FUN_080e0248 が 2 にして unk_1b2 を立てる
  u8 unk_1af[0x1B2 - 0x1AF];        // 0x1AF, まだ未解析
  u8 unk_1b2;                       // 0x1B2
  u8 unk_1b3[0x1B4 - 0x1B3];        // 0x1B3, まだ未解析
} Entity080e01bcElem;
static_assert(sizeof(Entity080e01bcElem) == 436);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  u8 unk_18[0x1C - 0x18];       // 0x018, _Init が Video_GetAuxSprite の AuxSpriteGfx としてここを渡す (28バイトぶんは pos 以降と重なる)
  Vec3 pos;                     // 0x01C, elems[0] の2本の Hitbox の位置に渡す
  u8 unk_24[0x38 - 0x24];       // 0x024, まだ未解析
  u32 unk_38;                   // 0x038, _Init が 0 を入れる
  Entity080e01bcElem elems[8];  // 0x03C, 根拠: FUN_080e0248 が 0x1B4 刻みで8個まわり, 8個で構造体末尾ぴったり
} Entity080e01bc;
static_assert(sizeof(Entity080e01bc) == 3548);

IWRAM_DATA Entity080e01bc* gEntity080e01bc = NULL;  // 0x0300017C

void nop_080dfa20(Entity080e01bc*, s32);
void FUN_080dfa24(Entity080e01bc*, s32);
void FUN_080dfbe4(Entity080e01bc*, s32);
void FUN_080dfde8(Entity080e01bc*, s32);

void (*const PTR_ARRAY_085ad364[4])(Entity080e01bc*, s32) = {
    nop_080dfa20,
    FUN_080dfa24,
    FUN_080dfbe4,
    FUN_080dfde8,
};  // 0x085AD364

NAKED void FUN_080df4c4(unknown* p) { INCFUNC("asm/func/FUN_080df4c4.inc"); }

NAKED void FUN_080df540(unknown* p) { INCFUNC("asm/func/FUN_080df540.inc"); }

void FUN_080df6d4(Entity080e01bc* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (p->elems[0].sprites[i].timer != 0) {
      p->elems[0].sprites[i].timer--;
      if (p->elems[0].sprites[i].timer == 0) {
        p->elems[0].sprites[i].sprite.flags = (p->elems[0].sprites[i].sprite.flags | SPRFLAG_HIDDEN) & ~SPRFLAG_AFFINE;
      }
    }
  }
}

void FUN_080df714(Entity080e01bc* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&p->elems[0].sprites[i].sprite);
  }
}

void FUN_080df730(s32 param_1, s32 param_2, Entity080e01bc* p) {
  HitboxData* hb;

  p->elems[0].unk_172 = 2;
  p->elems[0].unk_176 = 1;

  hb = &p->elems[0].hitbox_b8;
  hb->flags |= HBFLAG_UNK_2;
  hb = &p->elems[0].hitbox_108;
  hb->flags |= HBFLAG_UNK_2;
}

void FUN_080df760(s32 param_1, s32 param_2, Entity080e01bc* p) {
  HitboxData* hb;

  p->elems[0].unk_172 = 2;
  p->elems[0].unk_176 = 1;

  hb = &p->elems[0].hitbox_b8;
  hb->flags |= HBFLAG_UNK_2;
  hb = &p->elems[0].hitbox_108;
  hb->flags |= HBFLAG_UNK_2;
}

NAKED void FUN_080df790(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080df790.inc"); }

void FUN_080df880(Entity080e01bc* p) {
  Hitbox_SetPos(&p->elems[0].hitbox_b8, &p->pos, 0);
  Hitbox_SetPos(&p->elems[0].hitbox_108, &p->pos, 0);
  Hitbox_Register(&p->elems[0].hitbox_b8);
}

// 空いている枠を1つ確保して返す, 空きが無ければ NULL
// 残差3命令 (33 対 36), 原典はビット判定の結果を 1/0 として作ってから改めて 0 と比べる (0/1 の作り置き)
// さらに原典は i * 0x1B4 を分岐の中で掛け算のまま残すが, gcc は giv にしてループ外へ出す
// 枠のアドレスをローカルに取らず p->elems[i] を2回書くと giv は消えるが r8 まで使い出して 38命令に増える
NON_MATCH Entity080e01bcElem* FUN_080df8b0(Entity080e01bc* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->unk_38 & (1 << i))) {
      Entity080e01bcElem* elem = &p->elems[i];

      p->unk_38 |= 1 << i;
      elem->unk_1af[0] = 0;
      return elem;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_080df8b0.inc");
#endif
}

NAKED void FUN_080df900(unknown* p) { INCFUNC("asm/func/FUN_080df900.inc"); }

void nop_080dfa20(Entity080e01bc* p, s32 idx) {}

NAKED void FUN_080dfa24(Entity080e01bc* p, s32 idx) { INCFUNC("asm/func/FUN_080dfa24.inc"); }

NAKED void FUN_080dfbe4(Entity080e01bc* p, s32 idx) { INCFUNC("asm/func/FUN_080dfbe4.inc"); }

NAKED void FUN_080dfde8(Entity080e01bc* p, s32 idx) { INCFUNC("asm/func/FUN_080dfde8.inc"); }

NAKED void FUN_080dfeb0(unknown* p, unknown* param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11) { INCFUNC("asm/func/FUN_080dfeb0.inc"); }

NAKED s32 Entity080e01bc_Update(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Update.inc"); }

NAKED s32 Entity080e01bc_Destroy(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Destroy.inc"); }

s32 Entity080e01bc_Init(Entity080e01bc* p) {
  p->unk_38 = 0;
  Video_GetAuxSprite((AuxSpriteGfx*)p->unk_18, SPRITE_EFF_354D);
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
    if (p->elems[i].unk_1ae == 1) {
      p->elems[i].unk_1ae = 3;
    }
  }
}

// 発動待ちの枠を発動済みにする
void FUN_080e0248(void) {
  Entity080e01bc* p = gEntity080e01bc;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 8; i++) {
    if (p->elems[i].unk_1ae == 1) {
      p->elems[i].unk_1ae = 2;
      p->elems[i].unk_1b2 = 1;
    }
  }
}

NAKED void FUN_080e028c(void) { INCFUNC("asm/func/FUN_080e028c.inc"); }
