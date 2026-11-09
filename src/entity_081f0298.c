#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// 角度 angle の向きへ放物線を描いて飛び, 着地すると点滅して消える攻撃判定付きの物体1個
typedef struct {
  AuxSprite sprite;   // 0x00
  AuxAnimState anim;  // 0x2C, 飛行中は animIdx 18, 着地後は 19, variant は angle から決まる
  Vec3 vel;           // 0x3C, 毎フレーム sprite.pos に足す, y は毎フレーム 1 ずつ減る
  HitboxData hitbox;  // 0x44
  u16 unk_94;         // 0x94, 生成時に 0 が入るだけ
  u8 state;           // 0x96, PTR_ARRAY_085ae50c の添字 (0: 待機, 1: 飛行, 2: 着地)
  s8 slotIdx;         // 0x97, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;          // 0x98, 着地後は 19 フレームを超えると点滅を始め, 70 フレームを超えると消える
  bool8 stateBegun;   // 0x9A, 着地した次のフレームで着地アニメに切り替えて 0 に戻す
  u8 angle;           // 0x9B, 飛ぶ向き, gSineTable の添字
} Entity081f0298Elem;
static_assert(sizeof(Entity081f0298Elem) == 156);

// スケルトンが出す物体を最大12個まで管理するシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x018, SPRITE_SKELETON_MISC
  AuxAnimFile* animFile;         // 0x034, ANIM_1DC3
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f0298Elem elems[12];  // 0x03C
} Entity081f0298;
static_assert(sizeof(Entity081f0298) == 1932);

static Entity081f0298* gEntity081f0298;  // 0x030001E0

const u8 u8_ARRAY_085ae508[4] = {8, 4, 2, 1};  // 0x085AE508

NAKED void Entity081f0298_OnHit(HitboxData* a, HitboxData* b, Entity081f0298Elem* elem) { INCFUNC("asm/func/Entity081f0298_OnHit.inc"); }

NAKED void Entity081f0298_InitHitbox(Entity081f0298Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) { INCFUNC("asm/func/Entity081f0298_InitHitbox.inc"); }

NAKED void Entity081f0298_UpdateIdle(Entity081f0298* p, Entity081f0298Elem* elem) { INCFUNC("asm/func/Entity081f0298_UpdateIdle.inc"); }

NAKED void Entity081f0298_BlinkOut(Entity081f0298* p, Entity081f0298Elem* elem) { INCFUNC("asm/func/Entity081f0298_BlinkOut.inc"); }

NAKED void Entity081f0298_UpdateLanded(Entity081f0298* p, Entity081f0298Elem* elem) { INCFUNC("asm/func/Entity081f0298_UpdateLanded.inc"); }

NAKED void Entity081f0298_UpdateFly(Entity081f0298* p, Entity081f0298Elem* elem) { INCFUNC("asm/func/Entity081f0298_UpdateFly.inc"); }

NAKED Entity081f0298Elem* Entity081f0298_AllocElem(Entity081f0298* p) { INCFUNC("asm/func/Entity081f0298_AllocElem.inc"); }

NAKED Entity081f0298Elem* FUN_081f0088(Entity081f0298* p) { INCFUNC("asm/func/FUN_081f0088.inc"); }

NAKED void Entity081f0298_Spawn(Vec3* pos, u32 angle, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 speed) { INCFUNC("asm/func/Entity081f0298_Spawn.inc"); }

void (*const PTR_ARRAY_085ae50c[3])(Entity081f0298*, Entity081f0298Elem*) = {
    Entity081f0298_UpdateIdle,
    Entity081f0298_UpdateFly,
    Entity081f0298_UpdateLanded,
};  // 0x085AE50C

NAKED s32 Entity081f0298_Update(Entity081f0298* p) { INCFUNC("asm/func/Entity081f0298_Update.inc"); }

NAKED s32 Entity081f0298_Destroy(Entity081f0298* p) { INCFUNC("asm/func/Entity081f0298_Destroy.inc"); }

NAKED s32 Entity081f0298_Init(Entity081f0298* p) { INCFUNC("asm/func/Entity081f0298_Init.inc"); }

NAKED Entity081f0298* Entity081f0298_Create(void) { INCFUNC("asm/func/Entity081f0298_Create.inc"); }

NAKED void Entity081f0298_ClearGlobal(void) { INCFUNC("asm/func/Entity081f0298_ClearGlobal.inc"); }
