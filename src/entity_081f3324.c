#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// グラフィックはボク系の敵が出すホルルン液(溶解液) だが使用箇所がまだわからない

#define ENTITY081F3324_FALLING (1 << 0)  // 0x1, target に近づいて落ち始めた

// 目標へ向かって水平に飛び, 近づくと落ちて着地し, しばらく攻撃判定を残してから点滅して消える1個
typedef struct {
  AuxSprite sprite;   // 0x00, 生成時は SPRFLAG_HIDDEN, state 1, 2 に入ると見せる, state 3 に入ると pos.x を 128 引く
  AuxAnimState anim;  // 0x2C, アニメ 0 (飛行), 1 (着地後)
  Mover mover;        // 0x3C, Mover_Init されず, 動くたびに pos へ sprite.pos を写すだけ, state 1 は target との距離をここから測る
  Vec3 target;        // 0x80, 向かう先の座標, xz の距離の2乗が 48399 以下になると落ち始める
  Vec3 vel;           // 0x88, x と z は target の向きに speed, y は落ち始めると毎フレーム 4 ずつ減る, 着地すると全て 0
  Vec3 landPos;       // 0x90, 着地した位置, state 3 の攻撃判定と state 4 の煙をここに出す
  Hitbox hitbox;      // 0x98, 攻撃判定, 飛行中に当たると vel の x と z を 0 にして state 2 へ移る
  u16 flags;          // 0xE8, ENTITY081F3324_*
  u8 state;           // 0xEA, sEntity081f3324States の添字 (0:待機 1:飛行 2:落下 3:着地 4:消滅)
  s8 slotIdx;         // 0xEB, usedMask 上の自分のビット番号
  u8 unk_ec[2];       // 0xEC
  s16 timer;          // 0xEE, state 1, 2 に入ると 0, state 1, 2 で毎フレーム +1, state 4 では 90 を超えるまで +1 して点滅の間隔を決め, 超えると消える
  bool8 stateBegun;   // 0xF0, 立っていると次の更新で state の初期化をする
  u8 groundTime;      // 0xF1, 着地後に攻撃判定を残すフレーム数, 毎フレーム -1 して 0 になると state 4 へ移る
} Entity081f3324Elem;
static_assert(sizeof(Entity081f3324Elem) == 244);

// Boku が投げる弾を12個まで同時に動かすシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, SPR_ACID_0
  AuxAnimFile* anim;             // 0x034, ANIM_LIQUID
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f3324Elem elems[12];  // 0x03C
} Entity081f3324;
static_assert(sizeof(Entity081f3324) == 2988);

static Entity081f3324* gEntity081f3324;  // 0x030001F0

static inline bool8 Entity081f3324_IsUsed(Entity081f3324* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

static inline bool8 Entity081f3324_IsFalling(Entity081f3324Elem* elem) {
  if (TEST_FLAGS(elem->flags, ENTITY081F3324_FALLING)) return TRUE;
  return FALSE;
}

Entity081f3324* Entity081f3324_Create(void);

const u8 sEntity081f3324BlinkIntervals[4] = {8, 4, 2, 1};  // 0x085AE548, 消えるときの点滅の間隔 (フレーム), timer が 40 以下, 60 以下, それより上で 0, 1, 2 番を使う

// 飛行中に当たったら水平の速度を止めて落下へ移る
void Entity081f3324_OnHit(Hitbox* a, Hitbox* b, Entity081f3324Elem* elem) {
  if (elem->state == 1) {
    elem->vel.x = 0;
    elem->vel.z = 0;
    elem->state = 2;
  }
}

// 弾の攻撃判定を作り, スプライトの位置に置く
void Entity081f3324_InitHitbox(Entity081f3324Elem* elem, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes) {
  Vec3 size;
  Vec3 offset;
  Hitbox* hitbox;

  VEC3_SET(size, Q8(0.125), Q8(0.125), Q8(0.125));
  VEC3_SET(offset, 0, Q8(0.125), 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081f3324_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
}

void Entity081f3324_UpdateIdle(Entity081f3324* p, Entity081f3324Elem* elem) {}

// 着地した位置に煙を1つ出す
void Entity081f3324_EmitSmoke(Entity081f3324Elem* elem) {
  Vec3 size;

  size.x = Q8(0.625), size.y = 0, size.z = Q8(0.625);
  EmitSmoke(&elem->landPos, 1, &size, 0, 0, 20, 1, 2);
}

// timer に応じた間隔で点滅させ, 見せるたびに煙を出す, 90 フレームを超えたら消してスロットを空け TRUE を返す
bool32 Entity081f3324_Blink(Entity081f3324* p, Entity081f3324Elem* elem) {
  AuxSprite* sprite = &elem->sprite;
  s32 i;

  if (elem->timer > 60) {
    i = 2;
  } else if (elem->timer > 40) {
    i = 1;
  } else {
    i = 0;
  }
  if (Mod(elem->timer, sEntity081f3324BlinkIntervals[i]) == 0) {
    if (sprite->flags & SPRFLAG_HIDDEN) {
      sprite->flags &= ~SPRFLAG_HIDDEN;
    } else {
      sprite->flags |= SPRFLAG_HIDDEN;
      Entity081f3324_EmitSmoke(elem);
    }
  }
  if (elem->timer > 90) {
    Entity081f3324_EmitSmoke(elem);
    sprite->flags |= SPRFLAG_HIDDEN;
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    AuxSprite_Remove(&elem->sprite);
    elem->state = 0;
    return TRUE;
  }
  elem->timer++;
  return FALSE;
}

// state 4, アニメを進めながら点滅させて消す
void Entity081f3324_UpdateVanish(Entity081f3324* p, Entity081f3324Elem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
  }
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  Entity081f3324_Blink(p, elem);
}

// state 3, 着地した位置に攻撃判定を groundTime フレーム残し, 尽きたら消滅へ移る
void Entity081f3324_UpdateLanded(Entity081f3324* p, Entity081f3324Elem* elem) {
  if (elem->stateBegun) {
    elem->landPos = elem->sprite.pos;
    elem->sprite.pos.x -= 128;
    AuxAnim_SetAnim(&elem->anim, p->anim, 1, 0, 0);
    elem->sprite.priority = 2;
    elem->stateBegun = FALSE;
  }
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  Hitbox_SetPos(&elem->hitbox, &elem->landPos, 0);
  Hitbox_Register(&elem->hitbox);
  if (elem->groundTime != 0) {
    elem->groundTime--;
  } else {
    elem->state = 4;
  }
}

// state 1, target へ向かって水平に飛ぶ, 近づいたら重力で落とし, 床に着いたら着地へ移る
void Entity081f3324_UpdateFly(Entity081f3324* p, Entity081f3324Elem* elem) {
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim = &elem->anim;
  Vec3 front;
  s32 angle;
  s16 groundY;

  if (elem->stateBegun) {
    AuxSprite_Show(&elem->sprite);
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  AuxSprite_AdvanceAnim(sprite, anim);
  Vec3_Sum(&sprite->pos, &elem->vel, &sprite->pos);
  elem->mover.pos = elem->sprite.pos;
  angle = ArcTan2_8(elem->vel.x, elem->vel.z);
  Vec3_SetPolar(&front, angle, 32);
  Vec3_Sum(&front, &sprite->pos, &front);
  if (Entity081f3324_IsFalling(elem)) {
    elem->vel.y -= 4;
  } else {
    Vec3 d;

    Vec3_Delta(&d, &elem->mover.pos, &elem->target);
    if (d.x * d.x + d.z * d.z <= 48399) {
      elem->flags |= ENTITY081F3324_FALLING;
      elem->vel.y -= 4;
    }
  }
  groundY = TileHeightAt(&front);
  Hitbox_SetPos(&elem->hitbox, &sprite->pos, 0);
  Hitbox_Register(&elem->hitbox);
  elem->timer++;
  if (sprite->pos.y <= 0) {
    AuxSprite_Hide(sprite);
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    AuxSprite_Remove(&elem->sprite);
    elem->state = 0;
  } else if (sprite->pos.y <= groundY) {
    sprite->pos.x -= elem->vel.x;
    sprite->pos.y -= elem->vel.y;
    sprite->pos.z -= elem->vel.z;
    elem->vel.x = 0;
    elem->vel.y = 0;
    elem->vel.z = 0;
    elem->state = 3;
    elem->stateBegun = TRUE;
    elem->mover.pos = elem->sprite.pos;
    PlaySound_082406e0(SONG_242);
  }
}

// state 2, 重力で落とし, 床に着いたら着地へ移る, 高さ 0 以下に落ちたら消す
void Entity081f3324_UpdateFall(Entity081f3324* p, Entity081f3324Elem* elem) {
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim = &elem->anim;
  s16 groundY;

  if (elem->stateBegun) {
    AuxSprite_Show(&elem->sprite);
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  AuxSprite_AdvanceAnim(sprite, anim);
  elem->vel.y -= 4;
  Vec3_Sum(&sprite->pos, &elem->vel, &sprite->pos);
  elem->mover.pos = elem->sprite.pos;
  groundY = TileHeightAt(&sprite->pos);
  elem->timer++;
  if (sprite->pos.y <= 0) {
    AuxSprite_Hide(sprite);
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    AuxSprite_Remove(&elem->sprite);
    elem->state = 0;
  } else if (sprite->pos.y <= groundY) {
    sprite->pos.y = groundY;
    elem->vel.x = 0;
    elem->vel.y = 0;
    elem->vel.z = 0;
    elem->state = 3;
    elem->stateBegun = TRUE;
    elem->mover.pos = elem->sprite.pos;
    PlaySound_082406e0(SONG_242);
  }
}

// 空いているスロットを1つ確保して 0 で埋める
Entity081f3324Elem* Entity081f3324_AllocElem(Entity081f3324* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity081f3324_IsUsed(p, i)) {
      Entity081f3324Elem* elem = &p->elems[i];

      ClearMemory(elem, sizeof(Entity081f3324Elem));
      p->usedMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

// 空いているスロットを1つ確保する, 無ければ NULL
Entity081f3324Elem* Entity081f3324_TryAllocElem(Entity081f3324* p) {
  Entity081f3324Elem* elem = Entity081f3324_AllocElem(p);

  if (elem == NULL) {
    return NULL;
  }
  return elem;
}

// pos から target へ speed で飛ぶ弾を1つ出す
void Entity081f3324_Spawn(Vec3* pos, Vec3* target, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 groundTime, s32 speed, s32 unk_9) {
  Entity081f3324* p = gEntity081f3324;
  Entity081f3324Elem* elem;
  AuxSprite* sprite;
  Vec3 diff;
  s32 angle;

  if (p == NULL) {
    p = Entity081f3324_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f3324_TryAllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->flags = 0;
  elem->groundTime = groundTime;
  elem->target = *target;
  elem->stateBegun = TRUE;
  sprite = &elem->sprite;
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->anim, 0, 0, 0);
  Video_SetAuxSpritePltt(sprite->gfx, 1);
  sprite->pos = *pos;
  Vec3_Delta(&diff, &sprite->pos, target);
  angle = ArcTan2_8(diff.x, diff.z);
  elem->vel.x = POLAR_X(speed, angle);
  elem->vel.z = POLAR_Z(speed, angle);
  elem->vel.y = 0;
  AuxSprite_Hide(sprite);
  sprite->priority = 2;
  Entity081f3324_InitHitbox(elem, power, knockback, attrs, iframes);
}

void (*const sEntity081f3324States[5])(Entity081f3324*, Entity081f3324Elem*) = {
    Entity081f3324_UpdateIdle,
    Entity081f3324_UpdateFly,
    Entity081f3324_UpdateFall,
    Entity081f3324_UpdateLanded,
    Entity081f3324_UpdateVanish,
};  // 0x085AE54C

// 使用中のスロットを state ごとに動かす
s32 Entity081f3324_Update(Entity081f3324* p) {
  Entity081f3324Elem* elems = p->elems;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081f3324_IsUsed(p, i)) {
      sEntity081f3324States[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081f3324_Destroy(Entity081f3324* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081f3324_IsUsed(p, i)) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }
  gEntity081f3324 = NULL;
  return 0;
}

s32 Entity081f3324_Init(Entity081f3324* p) {
  Video_GetAuxSprite(&p->gfx, SPR_ACID_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_LIQUID);
  p->usedMask = 0;
  gEntity081f3324 = p;
  return 0;
}

Entity081f3324* Entity081f3324_Create(void) {
  if (gEntity081f3324 == NULL) {
    Entity081f3324* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081f3324));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f3324_Update, Entity081f3324_Destroy);
      if (Entity081f3324_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f3324;
}

void Entity081f3324_ClearGlobal(void) { gEntity081f3324 = NULL; }
