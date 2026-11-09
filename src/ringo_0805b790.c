#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

// おそらく リンゴとダーインのエネルギー弾の管理用構造体 (リンゴ が ソル属性 で、 ダーインが ダーク属性 の弾を放つ?)

// 弾1発
typedef struct {
  u8 kind;             // 0x00, 0 と 2 は state 0, 1 は state 1 で始まる
  bool8 stateEntered;  // 0x01, state が変わると 1, 各 state の最初のフレームで 0 に戻す
  u8 state;            // 0x02, PTR_ARRAY_085aba20 の添字 (0: 直進, 1: target を追う, 2: 着弾して消える)
  u8 angle;            // 0x03, 進む向き, gSineTable の添字
  u16 timer;           // 0x04, state に入ってからのフレーム数, state 0 と 1 では 128 を超えると消える
  u16 speed;           // 0x06, 1フレームの移動量, gSineTable との積を 12bit 右シフトして足す
  u8 turnRate;         // 0x08, state 1 で angle を target へ寄せる1フレームの上限, 1 固定
  u8 unk_9[3];         // 0x09
  Vec3* target;        // 0x0C, state 1 で追う座標
  HitboxData hitbox;   // 0x10, 当たると state 2 へ移る
  AuxSprite sprite;    // 0x60, pos が弾の座標, 地面より低くなると state 2 へ移る
} Entity0805b790Elem;
static_assert(sizeof(Entity0805b790Elem) == 140);

// 地形か相手に当たるまで直進または追尾する弾を最大16発管理する
typedef struct Entity0805b790 {
  Entity e;                      // 0x000, ENTITY_UNK_8
  u32 activeMask;                // 0x018, 1 << i で elems[i] が使用中
  u16 unk_1c;                    // 0x01C, 10 が入るだけ
  u16 unk_1e;                    // 0x01E, 10 が入るだけ
  bool32 isDark;                 // 0x020, 0 ならソル属性でパレット 44, それ以外はダーク属性でパレット 50
  AuxSpriteGfx gfx;              // 0x024, SPRITE_EBALL_210E
  Entity0805b790Elem elems[16];  // 0x040
} Entity0805b790;
static_assert(sizeof(Entity0805b790) == 2304);

NAKED Entity0805b790Elem* Entity0805b790_AllocElem(Entity0805b790* p, u32* outIdx) { INCFUNC("asm/func/Entity0805b790_AllocElem.inc"); }

NAKED void Entity0805b790_OnHit(HitboxData* a, HitboxData* b, Entity0805b790Elem* elem) { INCFUNC("asm/func/Entity0805b790_OnHit.inc"); }

NAKED s32 Entity0805b790_InitElem(Entity0805b790* p, Entity0805b790Elem* elem, s32 index) { INCFUNC("asm/func/Entity0805b790_InitElem.inc"); }

NAKED s32 Entity0805b790_DestroyElem(Entity0805b790* p, Entity0805b790Elem* elem, s32 index) { INCFUNC("asm/func/Entity0805b790_DestroyElem.inc"); }

NAKED s32 Entity0805b790_ReleaseElem(Entity0805b790* p, Entity0805b790Elem* elem, s32 index) { INCFUNC("asm/func/Entity0805b790_ReleaseElem.inc"); }

NAKED void Entity0805b790_TurnToTarget(Entity0805b790Elem* elem) { INCFUNC("asm/func/Entity0805b790_TurnToTarget.inc"); }

NAKED void Entity0805b790_UpdateMove(Entity0805b790* p, Entity0805b790Elem* elem, s32 index) { INCFUNC("asm/func/Entity0805b790_UpdateMove.inc"); }

NAKED void Entity0805b790_UpdateHoming(Entity0805b790* p, Entity0805b790Elem* elem, s32 index) { INCFUNC("asm/func/Entity0805b790_UpdateHoming.inc"); }

NAKED void Entity0805b790_UpdateImpact(Entity0805b790* p, Entity0805b790Elem* elem, s32 index) { INCFUNC("asm/func/Entity0805b790_UpdateImpact.inc"); }

void (*const PTR_ARRAY_085aba20[3])(Entity0805b790*, Entity0805b790Elem*, s32) = {
    Entity0805b790_UpdateMove,
    Entity0805b790_UpdateHoming,
    Entity0805b790_UpdateImpact,
};  // 0x085ABA20

NAKED s32 Entity0805b790_Update(Entity0805b790* p) { INCFUNC("asm/func/Entity0805b790_Update.inc"); }

NAKED s32 Entity0805b790_Destroy(Entity0805b790* p) { INCFUNC("asm/func/Entity0805b790_Destroy.inc"); }

NAKED s32 Entity0805b790_Init(Entity0805b790* p, bool32 isDark) { INCFUNC("asm/func/Entity0805b790_Init.inc"); }

NAKED Entity0805b790* Entity0805b790_Create(bool32 isDark) { INCFUNC("asm/func/Entity0805b790_Create.inc"); }

NAKED s32 Entity0805b790_Spawn(Entity0805b790* p, Vec3* pos, Vec3* target, u32 kind, u32 angle, s32 speed, s32 power, s32 knockback) { INCFUNC("asm/func/Entity0805b790_Spawn.inc"); }
