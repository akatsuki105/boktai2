#include "constants/songs.h"
#include "constants/sprite.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"

// 跳ねて転がる破片 1 つ, Entity081efa9c_Spawn で出す
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxAnimState anim;      // 0x2C
  AuxSpriteGfx gfx;       // 0x3C, Entity081efa9c_Spawn の spriteID
  HitboxData hitbox;      // 0x58, flags の bit0 が立っているときだけ登録する
  AuxAnimFile* animFile;  // 0xA8, Entity081efa9c_Spawn の animID
  Vec3 vel;               // 0xAC, 着地するたびに減衰する
  u8 unk_b4;              // 0xB4
  s8 spinDir;             // 0xB5, SPRFLAG_AFFINE のとき回転の向き, 着地で反転する
  u8 spinSpeed;           // 0xB6
  u8 flags;               // 0xB7, bit0: hitbox が有効
  u16 vanishTimer;        // 0xB8, 消える状態で点滅させる経過フレーム
  u16 unk_ba;             // 0xBA
  u8 state;               // 0xBC, sEntity081efa9cStates の添字, 0: 空き, 1: 跳ねる, 2: アニメ再生, 3: 点滅して消える
  s8 idx;                 // 0xBD, elems の添字, 空きなら 0xFF
  u8 unk_be[2];           // 0xBE
  u32 spriteID;           // 0xC0
  bool8 stateEntered;     // 0xC4
  u8 bounceSoundWait;     // 0xC5, 着地音を鳴らしたあと 10 フレームは鳴らさない
  u16 life;               // 0xC6, 0 になると消える状態へ
  u16 tileIdx;            // 0xC8, いま乗っているタイル
  u8 unk_ca[6];           // 0xCA
} Entity081efa9cElem;
static_assert(sizeof(Entity081efa9cElem) == 208);

// 破片を 10 個まで動かす
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  Entity081efa9cElem elems[10];  // 0x018
  u32 usedMask;                  // 0x838, bit i が立っていれば elems[i] が使用中
} Entity081efa9c;
static_assert(sizeof(Entity081efa9c) == 2108);

static Entity081efa9c* gEntity081efa9c;  // 0x030001DC

static inline bool8 Entity081efa9c_IsUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081efa9c_StateNone(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_StateBounce(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_StatePlayAnim(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_StateVanish(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_OnHit(void);
s32 Entity081efa9c_Update(Entity081efa9c* p);
s32 Entity081efa9c_Destroy(Entity081efa9c* p);
s32 Entity081efa9c_Init(Entity081efa9c* p);
Entity081efa9c* Entity081efa9c_Create(void);

void (*const sEntity081efa9cStates[4])(Entity081efa9c*, Entity081efa9cElem*) = {
    Entity081efa9c_StateNone,
    Entity081efa9c_StateBounce,
    Entity081efa9c_StatePlayAnim,
    Entity081efa9c_StateVanish,
};  // 0x085AE4F8

void Entity081efa9c_StateNone(Entity081efa9c* p, Entity081efa9cElem* e) {}

// 空いている破片を1つ確保する
Entity081efa9cElem* Entity081efa9c_AllocElem(Entity081efa9c* p) {
  s32 i;

  for (i = 0; i < 10; i++) {
    if (!Entity081efa9c_IsUsed(&p->usedMask, i)) {
      Entity081efa9cElem* e = &p->elems[i];

      SET_BIT(p->usedMask, i);
      e->idx = i;
      return e;
    }
  }
  return NULL;
}

// 残差はレジスタ割当, TileHeightAtIndex に渡す pos が別レジスタへ写される (原典は r8 のまま使う), pos / vel をローカルに出す形までは試済
NON_MATCH void Entity081efa9c_StateBounce(Entity081efa9c* p, Entity081efa9cElem* e) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &e->sprite;
  WorldPos next;
  s32 curIdx;
  s32 groundY;
  s32 nextIdx;
  s32 nextY;
  u32 attr;
  WorldPos* pos;
  Vec3* vel;

  if (e->stateEntered) {
    AuxSprite_Show(&e->sprite);
    e->stateEntered = FALSE;
  }
  e->tileIdx = GetCollisionTileIdx(&e->sprite.pos);
  pos = &sprite->pos;
  vel = &e->vel;
  curIdx = e->tileIdx;
  ArcTan2_8(vel->x, vel->z);
  groundY = TileHeightAtIndex(curIdx, &sprite->pos);
  if (pos->y > groundY) {
    vel->y -= 4;
  }
  Vec3_Sum(&next, pos, vel);
  if (next.y < groundY) {
    vel->x = Div(vel->x * 5, 10);
    vel->y = -Div(vel->y * 4, 10);
    vel->z = Div(vel->z * 5, 10);
    if (e->sprite.flags & SPRFLAG_AFFINE) {
      e->spinDir *= -1;
    }
    if (e->bounceSoundWait == 0) {
      if (e->spriteID == SPRITE_SLIME && e->anim.animIdx == 6) {
        PlaySound_082406e0(SONG_964);
      } else if (e->spriteID == SPRITE_SKELETON_MISC && e->anim.animIdx == 6) {
        PlaySound_082406e0(SONG_944);
      }
      e->bounceSoundWait = 10;
    }
    pos->y = groundY;
    if (vel->x * vel->x + vel->y * vel->y + vel->z * vel->z == 0) {
      vel->x = 0;
      vel->y = 0;
      vel->z = 0;
      e->spinDir = 0;
      e->state = 3;
      e->stateEntered = TRUE;
      goto end;
    }
  } else {
    pos->y = next.y;
  }

  nextIdx = GetCollisionTileIdx(&next);
  nextY = TileHeightAtIndex(nextIdx, &next);
  attr = TileAttrAtIndex(nextIdx);
  if (curIdx != nextIdx) {
    if (groundY < nextY || (TileAttrAtIndex(nextIdx) & 3)) {
      vel->x = -Div(vel->x * 5, 10);
      vel->z = -Div(vel->z * 5, 10);
    }
  }
  if ((nextY <= 0 || (attr & 0x40)) && next.y <= nextY) {
    Entity081efa9c* q = gEntity081efa9c;

    CLEAR_BIT(q->usedMask, e->idx);
    e->state = 0;
    AuxSprite_Remove(&e->sprite);
    e->idx = -1;
    e->unk_ba = 0;
    e->life = 0;
  } else {
    pos->x += vel->x;
    pos->z += vel->z;
  }

end:
  if (sprite->flags & SPRFLAG_AFFINE) {
    sprite->rotation += e->spinSpeed * e->spinDir;
  }
  AuxSprite_AdvanceAnim(sprite, &e->anim);
  if (e->flags & 1) {
    Hitbox_SetPos(&e->hitbox, &e->sprite.pos, 0);
    Hitbox_Register(&e->hitbox);
  }
  if (e->bounceSoundWait != 0) {
    e->bounceSoundWait--;
  }
  if (e->life != 0) {
    e->life--;
  } else {
    e->state = 3;
    e->stateEntered = TRUE;
  }
#else
  INCFUNC("asm/func/Entity081efa9c_StateBounce.inc");
#endif
}

// 残差は e と cmd の r5 / r6 入れ替えのみ, sprite のローカル化 (位置と宣言順) と anim / hitbox のローカル化は試済
NON_MATCH void Entity081efa9c_StatePlayAnim(Entity081efa9c* p, Entity081efa9cElem* e) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &e->sprite;
  bool32 finished;

  if (e->stateEntered) {
    AuxSprite_Show(&e->sprite);
    e->stateEntered = FALSE;
  }
  e->tileIdx = GetCollisionTileIdx(&e->sprite.pos);
  finished = AuxSprite_AdvanceAnim(sprite, &e->anim);
  if (e->flags & 1) {
    Hitbox_SetPos(&e->hitbox, &e->sprite.pos, 0);
    Hitbox_Register(&e->hitbox);
  }
  if (e->life == 0 || finished) {
    Entity081efa9c* q = gEntity081efa9c;

    CLEAR_BIT(q->usedMask, e->idx);
    e->state = 0;
    AuxSprite_Remove(&e->sprite);
    e->idx = -1;
    e->unk_ba = 0;
    e->life = 0;
    e->stateEntered = TRUE;
  } else {
    e->life--;
  }
#else
  INCFUNC("asm/func/Entity081efa9c_StatePlayAnim.inc");
#endif
}

// state 3, 点滅させて消し, 消えきったら空きに戻す
void Entity081efa9c_StateVanish(Entity081efa9c* p, Entity081efa9cElem* e) {
  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->vanishTimer = 0;
  }
  if (Sprite_UpdateVanishBlink(&e->sprite.flags, e->vanishTimer, 60, 40)) {
    Entity081efa9c* q = gEntity081efa9c;

    CLEAR_BIT(q->usedMask, e->idx);
    e->state = 0;
    AuxSprite_Remove(&e->sprite);
    e->idx = -1;
    e->unk_ba = 0;
    e->life = 0;
  } else {
    e->vanishTimer++;
  }
}

void Entity081efa9c_OnHit(void) {}

// 破片の攻撃判定を作る
void Entity081efa9c_InitHitbox(Entity081efa9cElem* e, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Vec3 size;
  Vec3 offset;
  HitboxData* hitbox;

  VEC3_SET(size, Q8(0.0625), Q8(0.125), Q8(0.0625));
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &e->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081efa9c_OnHit, e);
  Hitbox_SetPos(hitbox, &e->sprite.pos, 0);
}

// 残差はレジスタ割当のみ, 原典は power をスタックから読み直し, 3回目の乱数で表の番地を読み直す
NON_MATCH Entity081efa9cElem* Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, u32 animIdx, u32 life, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 animVariant, u32 animFlags, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
#ifdef NONMATCHING_C
  Entity081efa9c* p = gEntity081efa9c;
  Entity081efa9cElem* e;
  AuxSprite* sprite;

  if (p == NULL) {
    p = Entity081efa9c_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return NULL;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return NULL;
  }
  e = Entity081efa9c_AllocElem(p);
  if (e == NULL) {
    return NULL;
  }
  e->unk_ba = 0;
  e->stateEntered = TRUE;
  e->vel = *vel;
  e->life = life;
  e->flags = flags;
  e->spriteID = spriteID;
  e->bounceSoundWait = 0;
  if (e->flags == 0) {
    e->state = 1;
  } else {
    e->state = 2;
  }
  sprite = &e->sprite;
  sprite->pos = *pos;
  Video_GetAuxSprite(&e->gfx, spriteID);
  e->animFile = GetFile(DIR_ANIMATION, animID);
  AuxSprite_Add(sprite, &e->gfx, 0);
  AuxAnim_SetAnim(&e->anim, e->animFile, animIdx, animVariant, animFlags);
  Video_SetAuxSpritePltt(sprite->gfx, plttID);
  AuxSprite_AdvanceAnim(sprite, &e->anim);
  AuxSprite_Hide(sprite);
  sprite->priority = 1;
  sprite->flags |= sprFlags;
  if (sprFlags & SPRFLAG_AFFINE) {
    sprite->rotation = RandomNext();
    if ((RandomNext() & 0xFF) < 128) {
      e->spinDir = -1;
    } else {
      e->spinDir = 1;
    }
    e->spinSpeed = (Random() & 7) + 7;
  }
  if (power > 0) {
    Entity081efa9c_InitHitbox(e, power, knockback, attrs, iframes);
    e->flags |= 1;
  }
  return e;
#else
  INCFUNC("asm/func/Entity081efa9c_Spawn.inc");
#endif
}

// 使用中の破片を state ごとに動かす
s32 Entity081efa9c_Update(Entity081efa9c* p) {
  Entity081efa9cElem* elems = p->elems;
  s32 i;

  if (p->usedMask == 0) {
    return 0;
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return 0;
  }
  for (i = 0; i < 10; i++) {
    if (Entity081efa9c_IsUsed(&p->usedMask, i)) {
      sEntity081efa9cStates[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081efa9c_Destroy(Entity081efa9c* p) {
  s32 i;

  for (i = 0; i < 10; i++) {
    if (Entity081efa9c_IsUsed(&p->usedMask, i)) {
      Entity081efa9cElem* e = &p->elems[i];

      AuxSprite_Remove(&e->sprite);
    }
  }
  gEntity081efa9c = NULL;
  return 0;
}

s32 Entity081efa9c_Init(Entity081efa9c* p) {
  p->usedMask = 0;
  gEntity081efa9c = p;
  return 0;
}

Entity081efa9c* Entity081efa9c_Create(void) {
  if (gEntity081efa9c == NULL) {
    Entity081efa9c* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081efa9c));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081efa9c_Update, Entity081efa9c_Destroy);
      if (Entity081efa9c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081efa9c;
}

void Entity081efa9c_ClearGlobal(void) { gEntity081efa9c = NULL; }
