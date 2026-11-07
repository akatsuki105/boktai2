#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

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
  s8 shadowId;            // 0x111, 0 のときだけ片付けで影を外す, 外したら -1
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

static inline bool8 Entity081f8a28_IsElemUsed(Entity081f8a28* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

// 当たったら爆発へ移る
void Entity081f8a28_OnHit(HitboxData* a, HitboxData* b, Entity081f8a28Elem* elem) {
  elem->state = 3;
  elem->stateBegun = TRUE;
}

NAKED void Entity081f8a28_InitHitbox(Entity081f8a28Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081f8a28_InitHitbox.inc"); }

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

NAKED void Entity081f8a28_SpawnTrail(Vec3* pos) { INCFUNC("asm/func/Entity081f8a28_SpawnTrail.inc"); }

void Entity081f8a28_UpdateIdle(Entity081f8a28* p, Entity081f8a28Elem* elem) {}

NAKED void Entity081f8a28_UpdateAppear(Entity081f8a28* p, Entity081f8a28Elem* elem) { INCFUNC("asm/func/Entity081f8a28_UpdateAppear.inc"); }

NAKED void Entity081f8a28_UpdateFly(Entity081f8a28* p, Entity081f8a28Elem* elem) { INCFUNC("asm/func/Entity081f8a28_UpdateFly.inc"); }

NAKED void Entity081f8a28_UpdateExplode(Entity081f8a28* p, Entity081f8a28Elem* elem) { INCFUNC("asm/func/Entity081f8a28_UpdateExplode.inc"); }

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

NAKED s32 Entity081f8a28_Destroy(Entity081f8a28* p) { INCFUNC("asm/func/Entity081f8a28_Destroy.inc"); }

NAKED s32 Entity081f8a28_Init(Entity081f8a28* p) { INCFUNC("asm/func/Entity081f8a28_Init.inc"); }

NAKED Entity081f8a28* Entity081f8a28_Create(void) { INCFUNC("asm/func/Entity081f8a28_Create.inc"); }

void Entity081f8a28_ClearGlobal(void) { gEntity081f8a28 = NULL; }

NAKED void FUN_081f8a80(void) { INCFUNC("asm/func/FUN_081f8a80.inc"); }

NAKED void FUN_081f8ab4(void) { INCFUNC("asm/func/FUN_081f8ab4.inc"); }
