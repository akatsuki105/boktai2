#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

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
  u8 state;               // 0xBC, PTR_ARRAY_085ae4f8 の添字, 0: 空き, 1: 跳ねる, 2: アニメ再生, 3: 点滅して消える
  u8 idx;                 // 0xBD, elems の添字, 空きなら 0xFF
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

void FUN_081eeed8(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_StateBounce(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_StatePlayAnim(Entity081efa9c* p, Entity081efa9cElem* e);
void Entity081efa9c_StateVanish(Entity081efa9c* p, Entity081efa9cElem* e);

void (*const PTR_ARRAY_085ae4f8[4])(Entity081efa9c*, Entity081efa9cElem*) = {
    FUN_081eeed8,
    Entity081efa9c_StateBounce,
    Entity081efa9c_StatePlayAnim,
    Entity081efa9c_StateVanish,
};  // 0x085AE4F8

void FUN_081eeed8(Entity081efa9c* p, Entity081efa9cElem* e) {}

NAKED Entity081efa9cElem* Entity081efa9c_AllocElem(Entity081efa9c* p) { INCFUNC("asm/func/Entity081efa9c_AllocElem.inc"); }

NAKED void Entity081efa9c_StateBounce(Entity081efa9c* p, Entity081efa9cElem* e) { INCFUNC("asm/func/Entity081efa9c_StateBounce.inc"); }

NAKED void Entity081efa9c_StatePlayAnim(Entity081efa9c* p, Entity081efa9cElem* e) { INCFUNC("asm/func/Entity081efa9c_StatePlayAnim.inc"); }

NAKED void Entity081efa9c_StateVanish(Entity081efa9c* p, Entity081efa9cElem* e) { INCFUNC("asm/func/Entity081efa9c_StateVanish.inc"); }

void FUN_081ef668(void) {}

NAKED void Entity081efa9c_InitHitbox(Entity081efa9cElem* e, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081efa9c_InitHitbox.inc"); }

NAKED Entity081efa9cElem* Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15) {
  INCFUNC("asm/func/Entity081efa9c_Spawn.inc");
}

NAKED s32 Entity081efa9c_Update(Entity081efa9c* p) { INCFUNC("asm/func/Entity081efa9c_Update.inc"); }

NAKED s32 Entity081efa9c_Destroy(Entity081efa9c* p) { INCFUNC("asm/func/Entity081efa9c_Destroy.inc"); }

s32 Entity081efa9c_Init(Entity081efa9c* p) {
  p->usedMask = 0;
  gEntity081efa9c = p;
  return 0;
}

NAKED Entity081efa9c* Entity081efa9c_Create(void) { INCFUNC("asm/func/Entity081efa9c_Create.inc"); }

void FUN_081efae8(void) { gEntity081efa9c = NULL; }
