#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite_aux.h"

// コウモリ1匹
typedef struct {
  u8 angle;               // 0x000, 進む向き, gSineTable の添字, 被弾すると当たった向きになる
  u8 speed;               // 0x001, state 3 の1フレームの移動量, gSineTable との積を 12bit 右シフトして vel にする
  s8 state;               // 0x002, PTR_ARRAY_085aba5c の添字 (0: 何もしない, 1: 散開, 2: targetPos を狙う, 3: 直進, 4: 被弾)
  bool8 stateEntered;     // 0x003, state が変わると 1, 各 state の最初のフレームで 0 に戻す
  u32 timer;              // 0x004, state に入ってからのフレーム数, state 3 は 120, state 4 は 20 フレームで消える
  u8 scatterTime;         // 0x008, state 1 に留まるフレーム数, 4..35 の乱数
  u8 scatterSpeed;        // 0x009, state 1 の1フレームの移動量, 20
  u8 aimTime;             // 0x00A, state 2 に留まるフレーム数, 添字 * 8 + 15
  u8 unk_0b;              // 0x00B
  Vec3 vel;               // 0x00C, 1フレームに sprite.pos へ足す量, y は常に 0
  HitboxData hitbox;      // 0x014, state 3 の間, 添字の偶奇が frameParity と合うフレームだけ登録する
  HitboxData hurtbox;     // 0x064, state 2, 3 の間だけ HBFLAG_HIDDEN を落とす, 当たると state 4 へ移る
  AuxAnimState anim;      // 0x0B4, コマ送りは自前で行う
  AuxSprite sprite;       // 0x0C4
  AuxSpriteGfx gfx;       // 0x0F0, SPRITE_BAT, パレット 611 (被弾直後の 6 フレームは 306), 群れで出すと pltt は Entity0805e67c.pltt を指す
  ParticleShadow shadow;  // 0x10C
} Entity0805e67cElem;
static_assert(sizeof(Entity0805e67cElem) == 332);

// シェードマンが出すコウモリを最大16匹まとめて動かす, 1匹ずつ直進させるか, 群れで左右へ散らしてから targetPos を狙って直進させる
typedef struct Entity0805e67c {
  Entity e;                      // 0x000, ENTITY_UNK_8
  u32 activeMask;                // 0x018, 1 << i で elems[i] が使用中, 0 の間は何も更新しない
  u32 timer;                     // 0x01C, activeMask が 0 でない間のフレーム数
  AuxAnimFile* anim;             // 0x020, ANIM_BAT
  Entity0805e67cElem elems[16];  // 0x024
  bool8 fadeActive;              // 0x14E4, 立っている間 pltt を毎フレーム作り直す, fadeLevel が 0 に戻ると 0
  s8 fadeLevel;                  // 0x14E5, pltt をパレット 611 から 615 へ寄せる度合い, 32 で 615 そのもの, 群れを出すと 20 から 31 まで上がって 0 まで下がる
  bool8 fadeOut;                 // 0x14E6, 0: fadeLevel を上げる, 1: 下げる
  u8 frameParity;                // 0x14E7, timer の最下位ビット
  rgb555 pltt[16];               // 0x14E8, 群れで出した要素の gfx.pltt がここを指す
  Vec3 targetPos;                // 0x1508, gPlayerPtr[0]->mover.pos の写し, gPlayerPtr[0] がいなければ前の値のまま
} Entity0805e67c;
static_assert(sizeof(Entity0805e67c) == 5392);

NAKED void Entity0805e67c_OnHurt(HitboxData* a, HitboxData* b, Entity0805e67cElem* elem) { INCFUNC("asm/func/Entity0805e67c_OnHurt.inc"); }

NAKED void Entity0805e67c_OnHit(HitboxData* a, HitboxData* b, Entity0805e67cElem* elem) { INCFUNC("asm/func/Entity0805e67c_OnHit.inc"); }

NAKED s32 Entity0805e67c_InitElem(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_InitElem.inc"); }

NAKED s32 Entity0805e67c_DestroyElem(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_DestroyElem.inc"); }

NAKED s32 Entity0805e67c_ReleaseElem(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_ReleaseElem.inc"); }

NAKED void Entity0805e67c_SetElemAnim(Entity0805e67c* p, Entity0805e67cElem* elem, u32 animIdx) { INCFUNC("asm/func/Entity0805e67c_SetElemAnim.inc"); }

NAKED void Entity0805e67c_UpdateIdle(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_UpdateIdle.inc"); }

NAKED void Entity0805e67c_UpdateScatter(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_UpdateScatter.inc"); }

NAKED void Entity0805e67c_UpdateAim(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_UpdateAim.inc"); }

NAKED void Entity0805e67c_UpdateFly(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_UpdateFly.inc"); }

NAKED void Entity0805e67c_UpdateHurt(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805e67c_UpdateHurt.inc"); }

void (*const PTR_ARRAY_085aba5c[5])(Entity0805e67c*, Entity0805e67cElem*, s32) = {
    Entity0805e67c_UpdateIdle,
    Entity0805e67c_UpdateScatter,
    Entity0805e67c_UpdateAim,
    Entity0805e67c_UpdateFly,
    Entity0805e67c_UpdateHurt,
};  // 0x085ABA5C

NAKED s32 Entity0805e67c_Update(Entity0805e67c* p) { INCFUNC("asm/func/Entity0805e67c_Update.inc"); }

NAKED s32 Entity0805e67c_Destroy(Entity0805e67c* p) { INCFUNC("asm/func/Entity0805e67c_Destroy.inc"); }

NAKED s32 Entity0805e67c_Init(Entity0805e67c* p) { INCFUNC("asm/func/Entity0805e67c_Init.inc"); }

NAKED Entity0805e67c* Entity0805e67c_Create(void) { INCFUNC("asm/func/Entity0805e67c_Create.inc"); }

NAKED s32 Entity0805e67c_Spawn(Entity0805e67c* p, Vec3* pos, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes) { INCFUNC("asm/func/Entity0805e67c_Spawn.inc"); }

NAKED s32 Entity0805e67c_SpawnSwarm(Entity0805e67c* p, Vec3* pos, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes) { INCFUNC("asm/func/Entity0805e67c_SpawnSwarm.inc"); }

NAKED s32 Entity0805e67c_SpawnSwarmN(Entity0805e67c* p, Vec3* pos, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 count) { INCFUNC("asm/func/Entity0805e67c_SpawnSwarmN.inc"); }
