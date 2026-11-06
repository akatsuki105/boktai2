#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// プレイヤー付近へ曲線を描いて飛び, y を 340 下げた位置に Entity081f0b90 の攻撃判定を出すのを attackCount 回くり返す1体
typedef struct {
  AuxSprite sprite;        // 0x000, パレットは 0xFB, 攻撃判定を出してからアニメが一巡するまでは 0xFE
  AuxSpriteGfx gfx;        // 0x02C, SPRITE_SKELETON_MISC
  AuxAnimState anim;       // 0x048, アニメ 0x17 (出現), 0x0E (飛行, 滞空, 攻撃), 4 (消滅)
  PathWalker path;         // 0x058, 経路 3, 曲線を作り直すたびに別のノードへ進めるが, その座標は使わない
  AuxShadow shadow;        // 0x064
  Vec3 dest;               // 0x0D0, 曲線の終点 (プレイヤーの位置を乱数でずらし y は 0), state 1 では y だけ上昇先 (生成位置 + 968) に使う
  Vec3 curve[12];          // 0x0D8, sprite.pos から dest へ向かう曲線上の点, state 2 で順にたどる
  Vec3 unk_138;            // 0x138, 曲線を作るたびに dest と同じ値が入る, 読み手は未発見
  Vec3 vel;                // 0x140, x と z だけ使う, state 1 では出現先の座標, state 2 では1フレームの移動量で, 曲線の始点の向きにもなる
  Vec3 basePos;            // 0x148, 上下の揺れを足す前の座標, state 4 ではここへ戻す
  u16 unk_150;             // 0x150, 0 が入るだけ
  u8 state;                // 0x152, PTR_ARRAY_085ae560 の添字 (0:待機 1:出現 2:飛行 3:滞空 4:攻撃 5:消滅)
  s8 slotIdx;              // 0x153, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;               // 0x154, state に入ってからのフレーム数 (state 2 は曲線を作り直すたびに 0), state 2 では moveTime から毎フレーム引く量にもなる
  bool8 stateBegun;        // 0x156, 立っていると次の更新で state の初期化をする
  u8 unk_157;              // 0x157, state 2 へ移るときに 1 が入るだけ
  bool8 animEnded;         // 0x158, state 1 で出現アニメが一巡すると立つ
  u8 appearAngle;          // 0x159, 出現先を決める向き (256 で1周), 距離は 64〜319 の乱数
  u8 phase;                // 0x15A, 上下に揺れる位相 (256 で1周), state 2 は毎フレーム +6, state 3 は 0 から +4 ずつ 128 まで
  s8 shadowId;             // 0x15B, 0 のときだけ片付けで影を外す
  u8 pointIdx;             // 0x15C, curve のいま向かっている点, 12 を超えると曲線を作り直す
  u8 knockbackPower;       // 0x15D, Entity081f0b90 の攻撃判定に渡す
  u8 invincibleTime;       // 0x15E, Entity081f0b90 の攻撃判定に渡す
  u8 unk_15f;              // 0x15F, スケルトンは 20 を渡す, 読み手は未発見
  HitboxAttributes attrs;  // 0x160, Entity081f0b90 の攻撃判定に渡す
  u16 power;               // 0x164, Entity081f0b90 の攻撃判定に渡す
  u8 unk_166;              // 0x166, 曲線を作ると 0, state 2 へ移ると 1, 読み手は未発見
  u8 unk_167;              // 0x167
  u16 attackCount;         // 0x168, 残りの攻撃回数, 攻撃のたびに -1 して 0 になると消滅へ移る
  u16 flyTime;             // 0x16A, state 2 の最短フレーム数
  u16 flyTimer;            // 0x16C, state 2 の残りフレーム数, 0 になったあと曲線を作り直すと state 3 へ移る
  s16 moveTime;            // 0x16E, state 1 は出現先までの残りフレーム数 (初期値 20), state 2 は曲線ごとに 1120 から毎フレーム timer ずつ減り, 1/64 を次の点までのフレーム数にする
  u16 scriptID;            // 0x170, 攻撃判定を出すときに 0 でなければ VM_ExecByID で実行する
  u16 explodeScriptID;     // 0x172, Entity081f0b90 の攻撃判定の scriptID に渡す
} Entity081f4554Elem;
static_assert(sizeof(Entity081f4554Elem) == 372);

// スケルトンが呼び出し, 最大4体まで同時に飛ばすシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;            // 0x018, ANIM_1DC3
  u32 usedMask;                 // 0x01C, elems のどのスロットが使用中かのビットマスク
  Entity081f4554Elem elems[4];  // 0x020
} Entity081f4554;
static_assert(sizeof(Entity081f4554) == 1520);

static Entity081f4554* gEntity081f4554;  // 0x030001F4

NAKED void Entity081f4554_ExecScript(Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_ExecScript.inc"); }

NAKED void Entity081f4554_UpdateIdle(Entity081f4554* p, Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_UpdateIdle.inc"); }

NAKED void Entity081f4554_UpdateVanish(Entity081f4554* p, Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_UpdateVanish.inc"); }

NAKED void Entity081f4554_UpdateAppear(Entity081f4554* p, Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_UpdateAppear.inc"); }

NAKED void Entity081f4554_BuildCurve(Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_BuildCurve.inc"); }

NAKED void Entity081f4554_UpdateFly(Entity081f4554* p, Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_UpdateFly.inc"); }

NAKED void Entity081f4554_UpdateHover(Entity081f4554* p, Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_UpdateHover.inc"); }

NAKED void Entity081f4554_UpdateAttack(Entity081f4554* p, Entity081f4554Elem* elem) { INCFUNC("asm/func/Entity081f4554_UpdateAttack.inc"); }

NAKED Entity081f4554Elem* Entity081f4554_AllocElem(Entity081f4554* p) { INCFUNC("asm/func/Entity081f4554_AllocElem.inc"); }

NAKED Entity081f4554Elem* Entity081f4554_TryAllocElem(Entity081f4554* p) { INCFUNC("asm/func/Entity081f4554_TryAllocElem.inc"); }

NAKED void Entity081f4554_Spawn(Vec3* pos, Vec3* target, s32 flyTime, s32 attackCount, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime, s32 unk_9, u32 scriptID, u32 explodeScriptID) { INCFUNC("asm/func/Entity081f4554_Spawn.inc"); }

void (*const PTR_ARRAY_085ae560[6])(Entity081f4554*, Entity081f4554Elem*) = {
    Entity081f4554_UpdateIdle,
    Entity081f4554_UpdateAppear,
    Entity081f4554_UpdateFly,
    Entity081f4554_UpdateHover,
    Entity081f4554_UpdateAttack,
    Entity081f4554_UpdateVanish,
};  // 0x085AE560

NAKED s32 Entity081f4554_Update(Entity081f4554* p) { INCFUNC("asm/func/Entity081f4554_Update.inc"); }

NAKED s32 Entity081f4554_Destroy(Entity081f4554* p) { INCFUNC("asm/func/Entity081f4554_Destroy.inc"); }

NAKED s32 Entity081f4554_Init(Entity081f4554* p) { INCFUNC("asm/func/Entity081f4554_Init.inc"); }

NAKED Entity081f4554* Entity081f4554_Create(void) { INCFUNC("asm/func/Entity081f4554_Create.inc"); }

NAKED void Entity081f4554_ClearGlobal(void) { INCFUNC("asm/func/Entity081f4554_ClearGlobal.inc"); }

NAKED void Entity081f4554_VanishAll(void) { INCFUNC("asm/func/Entity081f4554_VanishAll.inc"); }

NAKED bool8 Entity081f4554_IsFull(void) { INCFUNC("asm/func/Entity081f4554_IsFull.inc"); }
