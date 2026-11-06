#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// クロスオーバー対戦関連

// オジャマバット1体, AuxSprite 2枚 (本体と影) を抱えて state ごとに動く
typedef struct {
  u8 state;           // 0x00, PTR_ARRAY_085ab6d4 の添字
  bool8 entered;      // 0x01, state に入った最初のフレームだけ立つ
  u8 slot;            // 0x02, 自分の添字 & 3, sprite2 のポーズ番号
  u8 count;           // 0x03, 0..10, sprite1 のポーズ番号, 0 なら両方隠す
  u8 shakeTimer;      // 0x04, 8 から毎フレーム減り, 0 でない間 sprite2 を乱数で揺らす
  u8 unk_05;          // 0x05
  s16 wobble;         // 0x06, 移動中に x と y へ足す揺れの振幅, 符号は乱数で決まる
  u32 timer;          // 0x08, state に入ってからのフレーム数
  Vec3 from;          // 0x0C, 移動の始点
  Vec3 to;            // 0x14, 移動の終点
  Vec3 vel;           // 0x1C, 毎フレーム sprite2.pos に足す
  AuxSprite sprite1;  // 0x24, gfx2 を使う
  AuxSprite sprite2;  // 0x50, gfx1 を使う, poseIdx は添字 & 3
} Entity08051b70Elem;
static_assert(sizeof(Entity08051b70Elem) == 124);

// オジャマバットを8体出す通信画面のシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_11
  u32 timer;                    // 0x018, state に入ってからのフレーム数
  u8 state;                     // 0x01C, PTR_ARRAY_085ab6f0 の添字
  bool8 entered;                // 0x01D, state に入った最初のフレームだけ立つ
  u16 unk_1e;                   // 0x01E, bit0 と bit1 で次の state を選ぶ
  s8 unk_20[4];                 // 0x020, elems[4..7].count の元, 0..10 に切り詰めて使う
  s8 unk_24[4];                 // 0x024
  s8 unk_28[4];                 // 0x028, unk_24 を写してから unk_24 を 0 にする
  u8 nextIdx;                   // 0x02C, 次に飛ばす elems[4 + nextIdx], 8 フレームごとに進む
  u8 shakeTimer;                // 0x02D, 0 でない間 sprite.pos を乱数で揺らしながら減る
  u8 unk_2e[2];                 // 0x02E
  void (*onFinish)(void);       // 0x030, 演出の最後に呼ぶ
  AuxSpriteGfx gfx1;            // 0x034, SPRITE_OJAMA_BAT
  AuxSpriteGfx gfx2;            // 0x050, SPRITE_OJAMA_BAT_CTR
  MainSpriteGfx mainGfx;        // 0x06C, SPRITE_UI_LINK
  MainSprite sprite;            // 0x08C
  Entity08051b70Elem elems[8];  // 0x0EC
} Entity08051b70;
static_assert(sizeof(Entity08051b70) == 1228);

IWRAM_DATA Entity08051b70* gEntity08051b70 = NULL;  // 0x03000118

bool32 FUN_0804e59c(void);
void LerpVec3(Vec3* dst, Vec3* a, Vec3* b, s32 t, s32 shift);

void FUN_08050f80(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void FUN_08050fa0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void FUN_080510e0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void FUN_080511b0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void FUN_0805128c(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void FUN_0805136c(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void FUN_080514f0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);

void (*const PTR_ARRAY_085ab6d4[7])(Entity08051b70*, Entity08051b70Elem*, s32) = {
    FUN_08050f80,
    FUN_08050fa0,
    FUN_080510e0,
    FUN_080511b0,
    FUN_0805128c,
    FUN_0805136c,
    FUN_080514f0,
};  // 0x085AB6D4

void FUN_08051640(Entity08051b70*);
void FUN_08051658(Entity08051b70*);
void FUN_0805169c(Entity08051b70*);
void FUN_08051710(Entity08051b70*);
void FUN_08051830(Entity08051b70*);
void FUN_08051898(Entity08051b70*);
void FUN_08051950(Entity08051b70*);

void (*const PTR_ARRAY_085ab6f0[7])(Entity08051b70*) = {
    FUN_08051640,
    FUN_08051658,
    FUN_0805169c,
    FUN_08051710,
    FUN_08051830,
    FUN_08051898,
    FUN_08051950,
};  // 0x085AB6F0

void FUN_08050e9c(Entity08051b70* p, s32 param_2) {
  if (p->unk_1e & 1) {
    p->unk_1e &= ~1;
    p->state = 3;
    p->entered = TRUE;
    p->timer = 0;
  } else if (p->unk_1e & 2) {
    p->unk_1e &= ~2;
    p->state = 4;
    p->entered = TRUE;
    p->timer = 0;
  } else if (param_2) {
    p->state = 5;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->state = 6;
    p->entered = TRUE;
    p->timer = 0;
  }
}

void Entity08051b70Elem_SetRandomWobble(Entity08051b70Elem* elem, s32 base, u32 mask) {
  u16* table = gRandomTable;
  s32 wobble = base + (_Random(table) & mask);

  if ((u8)_Random(table) < 128) {
    elem->wobble = wobble;
  } else {
    elem->wobble = -wobble;
  }
}

// 残差は t * 4 の lsls と gSineTable のプール読みの順序だけ (27/27), 原典は添字を先に作る, Tier A-B (POLAR_Z / SIN * amp, d の型) は試済
NON_MATCH void FUN_08050f44(Vec3* pos, u32 t, s32 amp) {
#ifdef NONMATCHING_C
  s32 d = FixToInt(12, SIN(t * 4) * amp);

  pos->x += d;
  pos->y += d;
#else
  INCFUNC("asm/func/FUN_08050f44.inc");
#endif
}

void FUN_08050f80(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  if (elem->entered) {
    elem->entered = FALSE;
    AuxSprite_Hide(&elem->sprite1);
    AuxSprite_Hide(&elem->sprite2);
  }
}

NAKED void FUN_08050fa0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_08050fa0.inc"); }

void FUN_080510e0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  AuxSprite* sprite1 = &elem->sprite1;
  AuxSprite* sprite2 = &elem->sprite2;

  if (elem->entered) {
    Vec3* to;

    elem->entered = FALSE;
    sprite1->poseIdx = elem->count;
    sprite2->poseIdx = elem->slot;
    AuxSprite_Show(&elem->sprite1);
    AuxSprite_Show(&elem->sprite2);
    to = &elem->to;
    VEC3_SET(*to, (idx & 3) * 24 + 80, 144, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
  }
  LerpVec3(&sprite2->pos, &elem->from, &elem->to, elem->timer, 5);
  FUN_08050f44(&sprite2->pos, elem->timer, elem->wobble);
  sprite1->pos = sprite2->pos;
  if (elem->timer >= 32) {
    p->elems[idx & 3].count += elem->count;
    p->elems[idx & 3].shakeTimer = 8;
    elem->count = 0;
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
}

void FUN_080511b0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  AuxSprite* sprite1 = &elem->sprite1;
  AuxSprite* sprite2 = &elem->sprite2;

  if (elem->entered) {
    Vec3* v;
    s16 x;

    elem->entered = FALSE;
    sprite1->poseIdx = elem->count;
    sprite2->poseIdx = elem->slot;
    AuxSprite_Show(&elem->sprite1);
    AuxSprite_Show(&elem->sprite2);
    v = &elem->from;
    x = (idx & 3) * 24;
    VEC3_SET(*v, x + 80, 144, 0);
    v = &elem->to;
    VEC3_SET(*v, x + 272, 32, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
    p->elems[idx & 3].count = 0;
  }
  LerpVec3(&sprite2->pos, &elem->from, &elem->to, elem->timer, 5);
  FUN_08050f44(&sprite2->pos, elem->timer, elem->wobble);
  sprite1->pos = sprite2->pos;
  if (elem->timer >= 32) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
}

// 残差は entered を落とす 0 と from/to を指すポインタの r2/r3 入れ替えだけ (109/109), Tier A-C (Vec3 ポインタの使い回し, inline setter, sprite1/2 の宣言順) は試済
NON_MATCH void FUN_0805128c(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite2 = &elem->sprite2;
  AuxSprite* sprite1 = &elem->sprite1;

  if (elem->entered) {
    Vec3* v;
    s16 x;

    elem->entered = FALSE;
    sprite1->poseIdx = elem->count;
    sprite2->poseIdx = elem->slot;
    AuxSprite_Show(&elem->sprite1);
    AuxSprite_Show(&elem->sprite2);
    v = &elem->from;
    x = (idx & 3) * 24;
    VEC3_SET(*v, x + 272, 32, 0);
    v = &elem->to;
    VEC3_SET(*v, x + 80, 144, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
  }
  LerpVec3(&sprite2->pos, &elem->from, &elem->to, elem->timer, 5);
  FUN_08050f44(&sprite2->pos, elem->timer, elem->wobble);
  sprite1->pos = sprite2->pos;
  if (elem->timer >= 32) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
    p->elems[idx & 3].count += elem->count;
    p->elems[idx & 3].shakeTimer = 8;
    elem->count = 0;
  }
  elem->timer++;
#else
  INCFUNC("asm/func/FUN_0805128c.inc");
#endif
}

NAKED void FUN_0805136c(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805136c.inc"); }

void FUN_080514f0(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  if (elem->entered) {
    elem->entered = FALSE;
    AuxSprite_SetPoseIdx(&elem->sprite1, elem->count);
    AuxSprite_SetPoseIdx(&elem->sprite2, elem->slot);
    AuxSprite_Show(&elem->sprite1);
    AuxSprite_Show(&elem->sprite2);
  }
  if (elem->timer >= 32) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
}

void Entity08051b70Elem_Init(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  u32 slot = idx & 3;

  elem->slot = slot;
  elem->count = 0;
  AuxSprite_Add(&elem->sprite1, &p->gfx2, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&elem->sprite1, 0);
  elem->sprite1.priority = 0;
  AuxSprite_Add(&elem->sprite2, &p->gfx1, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&elem->sprite2, slot);
  elem->sprite2.priority = 0;
  if (idx < 4) {
    elem->state = 1;
    elem->entered = TRUE;
    elem->timer = 0;
  } else {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
}

void Entity08051b70Elem_Destroy(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  AuxSprite_Remove(&elem->sprite1);
  AuxSprite_Remove(&elem->sprite2);
}

void Entity08051b70_LaunchNext(Entity08051b70* p, u32 state) {
  if (p->nextIdx < 4 && (p->timer & 7) == 0) {
    Entity08051b70Elem* elem = &p->elems[p->nextIdx + 4];

    if (elem->count != 0) {
      elem->state = state;
      elem->entered = TRUE;
      elem->timer = 0;
    }
    p->nextIdx++;
  }
}

void Entity08051b70_HideAllElems(Entity08051b70* p) {
  Entity08051b70Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    elem->count = 0;
    AuxSprite_Hide(&elem->sprite1);
    AuxSprite_Hide(&elem->sprite2);
  }
}

void FUN_08051640(Entity08051b70* p) {
  if (p->entered) {
    p->entered = FALSE;
    Entity08051b70_HideAllElems(p);
  }
}

void FUN_08051658(Entity08051b70* p) {
  if (p->entered) {
    p->entered = FALSE;
    p->nextIdx = 0;
  }
  Entity08051b70_LaunchNext(p, 3);
  if (p->timer >= 80) {
    if (p->onFinish != NULL) {
      p->onFinish();
    }
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  }
  p->timer++;
}

NAKED void FUN_0805169c(Entity08051b70* p) { INCFUNC("asm/func/FUN_0805169c.inc"); }

NAKED void FUN_08051710(Entity08051b70* p) { INCFUNC("asm/func/FUN_08051710.inc"); }

void FUN_08051830(Entity08051b70* p) {
  if (p->entered) {
    p->entered = FALSE;
    p->nextIdx = 0;
    MainSprite_SetPose(&p->sprite, &p->mainGfx, 50, 0);
    MainSprite_Show(&p->sprite);
    p->shakeTimer = 8;
    PlaySound_082406e0(SONG_492);
  }
  if (p->timer >= 80) {
    MainSprite_Hide(&p->sprite);
    FUN_08050e9c(p, 1);
  }
  p->timer++;
}

NAKED void FUN_08051898(Entity08051b70* p) { INCFUNC("asm/func/FUN_08051898.inc"); }

NAKED void FUN_08051950(Entity08051b70* p) { INCFUNC("asm/func/FUN_08051950.inc"); }

s32 Entity08051b70_Update(Entity08051b70* p) {
  if (FUN_0804e59c() == FALSE) {
    Entity08051b70Elem* elem;
    s32 i;

    PTR_ARRAY_085ab6f0[p->state](p);
    elem = p->elems;
    for (i = 0; i < 8; i++, elem++) {
      PTR_ARRAY_085ab6d4[elem->state](p, elem, i);
    }
    if (p->shakeTimer != 0) {
      Vec3* pos = &p->sprite.pos;

      p->shakeTimer--;
      pos->x = 0;
      pos->y = 64;
      if (p->shakeTimer != 0) {
        u16* table = gRandomTable;

        pos->x = (_Random(table) & 3) - 2;
        pos->y = (_Random(table) & 3) + 62;
      }
    }
  }
  return 0;
}

s32 Entity08051b70_Destroy(Entity08051b70* p) {
  Entity08051b70Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    Entity08051b70Elem_Destroy(p, elem, i);
  }
  MainSprite_Remove(&p->sprite);
  gEntity08051b70 = NULL;
  return 0;
}

s32 Entity08051b70_Init(Entity08051b70* p) {
  MainSpriteGfxFile* f;
  Vec3 pos;
  Entity08051b70Elem* elem;
  s32 i;

  gEntity08051b70 = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  if (f == NULL) {
    return -1;
  }
  p->mainGfx = *f;
  OpenMainSpriteFile(&p->mainGfx, f);
  if (!Video_GetAuxSprite(&p->gfx1, SPRITE_OJAMA_BAT) || !Video_GetAuxSprite(&p->gfx2, SPRITE_OJAMA_BAT_CTR)) {
    return -1;
  }

  VEC3_SET(pos, 0, 64, 0);
  MainSprite_Add(&p->sprite, &p->mainGfx, 49, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, &pos);
  p->state = 0;
  p->entered = TRUE;
  p->timer = 0;
  elem = p->elems;
  for (i = 0; i < 8; i++, elem++) {
    Entity08051b70Elem_Init(p, elem, i);
  }
  return 0;
}

Entity08051b70* Entity08051b70_Create(u32 id, u32 unused) {
  Entity08051b70* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity08051b70));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08051b70_Update, Entity08051b70_Destroy);
    if (Entity08051b70_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 FUN_08051bb0(void (*onFinish)(void), s8* counts) { INCFUNC("asm/func/FUN_08051bb0.inc"); }

NAKED s32 FUN_08051c50(void (*onFinish)(void), s8* counts0, s8* counts1, s8* out) { INCFUNC("asm/func/FUN_08051c50.inc"); }

NAKED s32 FUN_08051d18(Vec3* pos, s32 idx, s32 count) { INCFUNC("asm/func/FUN_08051d18.inc"); }
