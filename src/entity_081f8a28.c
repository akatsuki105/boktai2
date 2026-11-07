#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// 目標へ向かって曲がりながら飛び, 何かに当たるか寿命が尽きると爆発する弾1発
typedef struct {
  AuxSprite sprite;       // 0x000
  AuxAnimState anim;      // 0x02C
  AuxShadow shadow;       // 0x03C, SPRITE_EFF_1C1B
  HitboxData hitbox;      // 0x0A8, 攻撃判定, 当たると state 3 へ移る
  Vec3 vel;               // 0x0F8, x と z は speed と angle から毎フレーム作り直す, y は落ち始めると毎フレーム 3 ずつ減る
  Vec3 target;            // 0x100, 向かう先の座標
  u8 unk_108;             // 0x108, 生成時の angle, 読み手は未発見
  u8 angle;               // 0x109, 進む向き (256 で1周), sprite.rotation にも符号反転して写す
  u8 homingTime;          // 0x10A, 0 になるまで target へ向きを変え続ける, 曲がるたびに -1
  u8 turnSpeed;           // 0x10B, 1回に曲がる角度
  u16 speed;              // 0x10C, 6フレームごとに accel ずつ maxSpeed まで上がる
  u16 maxSpeed;           // 0x10E
  u8 accel;               // 0x110, state 2 に入ると 1, 加速するたびに +4
  u8 shadowId;            // 0x111, AuxShadow_Init の戻り値, 0 のときだけ片付けで影を外す, 外したら 0xFF
  s16 growTime;           // 0x112, state 1 の残りフレーム数 (初期値 15), この間 sprite.scaleX/Y を 64 へ近づける
  AuxAnimFile* animFile;  // 0x114, ANIM_121B
  s32 lifetime;           // 0x118, state 2 の残りフレーム数 (初期値 120), 60 未満になると追尾をやめて落ち始める
  u16 unk_11c;            // 0x11C, 生成時に 0 が入るだけ
  u8 state;               // 0x11E, PTR_ARRAY_085ae5c0 の添字 (0:待機 1:出現 2:飛行 3:爆発)
  s8 slotIdx;             // 0x11F, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;              // 0x120, state に入ってからのフレーム数
  bool8 stateBegun;       // 0x122, 立っていると次の更新で state の初期化をする
  u8 homingDelay;         // 0x123, 0 になるまで向きを変えない
} Entity081f8a28Elem;
static_assert(sizeof(Entity081f8a28Elem) == 292);

// 追尾して爆発する弾を8発まで同時に飛ばすシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_EFF_F422
  u8 unk_34[4];                 // 0x034
  u32 usedMask;                 // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f8a28Elem elems[8];  // 0x03C
} Entity081f8a28;
static_assert(sizeof(Entity081f8a28) == 2396);

static Entity081f8a28* gEntity081f8a28;  // 0x03000208

s32 SpawnAttackBox(Vec3* pos, u32 kind, u32 unk_60, s32 power, s32 knockback, s32 invincibleTime, s32 ignoreMask);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, s32 kind);

static inline bool8 Entity081f8a28_IsElemUsed(Entity081f8a28* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

// 当たったら爆発へ移る
void Entity081f8a28_OnHit(HitboxData* a, HitboxData* b, Entity081f8a28Elem* elem) {
  elem->state = 3;
  elem->stateBegun = TRUE;
}

void Entity081f8a28_InitHitbox(Entity081f8a28Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) {
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 64, 128, 64);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_10 | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockbackPower, 0, attrs, invincibleTime);
  Hitbox_SetHandler(hitbox, Entity081f8a28_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
}

void Entity081f8a28_UpdateHitbox(Entity081f8a28Elem* elem) {
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
}

Entity081f8a28Elem* Entity081f8a28_AllocElem(Entity081f8a28* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081f8a28_IsElemUsed(p, i)) {
      Entity081f8a28Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

NAKED void Entity081f8a28_TurnToTarget(Entity081f8a28Elem* elem) { INCFUNC("asm/func/Entity081f8a28_TurnToTarget.inc"); }

// pos の周りにランダムな向きで火の粉を1つ飛ばす
// 79/78命令, Entity081f959c_SpawnTrail と同じ壁 (原典は乱数表のアドレスを gRandTableIdx より先に r4 に置き, 0xFF を ldrb の直前に作る), 試済: 3つとも _Random(table), angle を u8 にする (77/78), 宣言と代入を分ける
NON_MATCH void Entity081f8a28_SpawnTrail(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u16* table = gRandomTable;
  u32 angle;
  s32 speed;

  angle = _Random(table) & 0xFF;
  speed = (_Random(table) & 31) - 16;
  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 63) - 48;
  Entity081ee2a0_SpawnDefault(pos, &vel, 60, 3);
#else
  INCFUNC("asm/func/Entity081f8a28_SpawnTrail.inc");
#endif
}

void Entity081f8a28_UpdateIdle(Entity081f8a28* p, Entity081f8a28Elem* elem) {}

// state 1, 15 フレームかけて拡大しながら現れ, 終わったら飛行へ移る
void Entity081f8a28_UpdateAppear(Entity081f8a28* p, Entity081f8a28Elem* elem) {
  if (elem->stateBegun) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    elem->sprite.flags |= SPRFLAG_AFFINE;
    elem->growTime = 15;
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->sprite.scaleX = 1;
    elem->sprite.scaleY = 1;
  }
  if (Mod(elem->timer, 8) == 0) {
    Entity081f8a28_SpawnTrail(&elem->sprite.pos);
  }
  if (elem->growTime > 0) {
    elem->sprite.scaleX += Div(64 - elem->sprite.scaleX, elem->growTime);
    elem->sprite.scaleY += Div(64 - elem->sprite.scaleY, elem->growTime);
    elem->growTime--;
  }
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  if (elem->growTime <= 0) {
    elem->state = 2;
    elem->sprite.flags &= ~SPRFLAG_AFFINE;
    elem->stateBegun = TRUE;
  } else {
    elem->timer++;
  }
}

NAKED void Entity081f8a28_UpdateFly(Entity081f8a28* p, Entity081f8a28Elem* elem) { INCFUNC("asm/func/Entity081f8a28_UpdateFly.inc"); }

// 爆発の攻撃判定を出して自分を片付ける
void Entity081f8a28_UpdateExplode(Entity081f8a28* p, Entity081f8a28Elem* elem) {
  if (elem->stateBegun) {
    SpawnAttackBox(&elem->sprite.pos, 2, 0, 128, 64, 40, 16);
    elem->timer = 0;
    if (elem->shadowId == 0) {
      AuxShadow_Remove(&elem->shadow);
      elem->shadowId = 0xFF;
    }
    AuxSprite_Remove(&elem->sprite);
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    elem->slotIdx = -1;
    elem->state = 0;
    elem->stateBegun = FALSE;
  }
}

NAKED void Entity081f8a28_Spawn(Vec3* pos, Vec3* target, s32 velY, s32 angle, s32 homingTime, s32 turnSpeed, s32 homingDelay, s32 speed, s32 maxSpeed, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081f8a28_Spawn.inc"); }

void (*const PTR_ARRAY_085ae5c0[4])(Entity081f8a28*, Entity081f8a28Elem*) = {
    Entity081f8a28_UpdateIdle,
    Entity081f8a28_UpdateAppear,
    Entity081f8a28_UpdateFly,
    Entity081f8a28_UpdateExplode,
};  // 0x085AE5C0

s32 Entity081f8a28_Update(Entity081f8a28* p) {
  Entity081f8a28Elem* elems = p->elems;
  s32 i;

  if (p->usedMask != 0) {
    for (i = 0; i < 8; i++) {
      if (Entity081f8a28_IsElemUsed(p, i)) {
        PTR_ARRAY_085ae5c0[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 Entity081f8a28_Destroy(Entity081f8a28* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081f8a28_IsElemUsed(p, i)) {
      if (p->elems[i].shadowId == 0) {
        AuxShadow_Remove(&p->elems[i].shadow);
        p->elems[i].shadowId = 0xFF;
      }
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }
  gEntity081f8a28 = NULL;
  return 0;
}

s32 Entity081f8a28_Init(Entity081f8a28* p) {
  p->usedMask = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  gEntity081f8a28 = p;
  return 0;
}

Entity081f8a28* Entity081f8a28_Create(void) {
  Entity081f8a28* p;

  if (gEntity081f8a28 != NULL) {
    return gEntity081f8a28;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f8a28));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081f8a28_Update, Entity081f8a28_Destroy);
    if (Entity081f8a28_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081f8a28_ClearGlobal(void) { gEntity081f8a28 = NULL; }

// 飛んでいる弾をすべて爆発させる
void Entity081f8a28_ExplodeAll(void) {
  Entity081f8a28* p = gEntity081f8a28;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (p->elems[i].state == 2) {
        p->elems[i].state = 3;
      }
    }
  }
}

// 決まった位置から 1P へ向けて弾を1発撃つ
void FUN_081f8ab4(void) {
  Vec3 pos;
  Vec3 diff;

  VEC3_SET(pos, 0x980, 0x2DC, 0x880);
  Vec3_Delta(&diff, &pos, &gPlayerPtr[0]->mover.pos);
  Entity081f8a28_Spawn(&pos, &gPlayerPtr[0]->mover.pos, 20, ArcTan2_8(diff.x, diff.z), 60, 4, 12, 4, 24, 0, 0, 0, 0);
}
