#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// グラフィックはボク系の敵が出すホルルン液(溶解液) だが使用箇所がまだわからない

// 目標へ向かって水平に飛び, 近づくと落ちて着地し, しばらく攻撃判定を残してから点滅して消える1個
typedef struct {
  AuxSprite sprite;   // 0x00, 生成時は SPRFLAG_HIDDEN, state 1, 2 に入ると見せる, state 3 に入ると pos.x を 128 引く
  AuxAnimState anim;  // 0x2C, アニメ 0 (飛行), 1 (着地後)
  Mover mover;        // 0x3C, Mover_Init されず, 動くたびに pos へ sprite.pos を写すだけ, state 1 は target との距離をここから測る
  Vec3 target;        // 0x80, 向かう先の座標, xz の距離の2乗が 48399 以下になると落ち始める
  Vec3 vel;           // 0x88, x と z は target の向きに speed, y は落ち始めると毎フレーム 4 ずつ減る, 着地すると全て 0
  Vec3 landPos;       // 0x90, 着地した位置, state 3 の攻撃判定と state 4 の煙をここに出す
  HitboxData hitbox;  // 0x98, 攻撃判定, 飛行中に当たると vel の x と z を 0 にして state 2 へ移る
  u16 flags;          // 0xE8, bit0: target に近づいて落ち始めた
  u8 state;           // 0xEA, PTR_ARRAY_085ae54c の添字 (0:待機 1:飛行 2:落下 3:着地 4:消滅)
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
  AuxSpriteGfx gfx;              // 0x018, SPRITE_ACID_0
  AuxAnimFile* anim;             // 0x034, ANIM_1752
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f3324Elem elems[12];  // 0x03C
} Entity081f3324;
static_assert(sizeof(Entity081f3324) == 2988);

static Entity081f3324* gEntity081f3324;  // 0x030001F0

const u8 u8_ARRAY_085ae548[4] = {8, 4, 2, 1};  // 0x085AE548, 消えるときの点滅の間隔 (フレーム), timer が 40 以下, 60 以下, それより上で 0, 1, 2 番を使う

NAKED void Entity081f3324_OnHit(HitboxData* a, HitboxData* b, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_OnHit.inc"); }

NAKED void Entity081f3324_InitHitbox(Entity081f3324Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) { INCFUNC("asm/func/Entity081f3324_InitHitbox.inc"); }

NAKED void Entity081f3324_UpdateIdle(Entity081f3324* p, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_UpdateIdle.inc"); }

NAKED void Entity081f3324_EmitSmoke(Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_EmitSmoke.inc"); }

NAKED bool32 Entity081f3324_Blink(Entity081f3324* p, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_Blink.inc"); }

NAKED void Entity081f3324_UpdateVanish(Entity081f3324* p, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_UpdateVanish.inc"); }

NAKED void Entity081f3324_UpdateLanded(Entity081f3324* p, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_UpdateLanded.inc"); }

NAKED void Entity081f3324_UpdateFly(Entity081f3324* p, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_UpdateFly.inc"); }

NAKED void Entity081f3324_UpdateFall(Entity081f3324* p, Entity081f3324Elem* elem) { INCFUNC("asm/func/Entity081f3324_UpdateFall.inc"); }

NAKED Entity081f3324Elem* Entity081f3324_AllocElem(Entity081f3324* p) { INCFUNC("asm/func/Entity081f3324_AllocElem.inc"); }

NAKED Entity081f3324Elem* Entity081f3324_TryAllocElem(Entity081f3324* p) { INCFUNC("asm/func/Entity081f3324_TryAllocElem.inc"); }

NAKED void Entity081f3324_Spawn(Vec3* pos, Vec3* target, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 groundTime, s32 speed, s32 unk_9) { INCFUNC("asm/func/Entity081f3324_Spawn.inc"); }

void (*const PTR_ARRAY_085ae54c[5])(Entity081f3324*, Entity081f3324Elem*) = {
    Entity081f3324_UpdateIdle,
    Entity081f3324_UpdateFly,
    Entity081f3324_UpdateFall,
    Entity081f3324_UpdateLanded,
    Entity081f3324_UpdateVanish,
};  // 0x085AE54C

NAKED s32 Entity081f3324_Update(Entity081f3324* p) { INCFUNC("asm/func/Entity081f3324_Update.inc"); }

NAKED s32 Entity081f3324_Destroy(Entity081f3324* p) { INCFUNC("asm/func/Entity081f3324_Destroy.inc"); }

NAKED s32 Entity081f3324_Init(Entity081f3324* p) { INCFUNC("asm/func/Entity081f3324_Init.inc"); }

NAKED Entity081f3324* Entity081f3324_Create(void) { INCFUNC("asm/func/Entity081f3324_Create.inc"); }

NAKED void Entity081f3324_ClearGlobal(void) { INCFUNC("asm/func/Entity081f3324_ClearGlobal.inc"); }
