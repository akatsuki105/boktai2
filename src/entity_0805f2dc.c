#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"
#include "vec3.h"

// 飛んでいく輪っか1つ, 当たると kind の効果かモザイクをかける
typedef struct {
  bool8 active;           // 0x00
  u8 kind;                // 0x01, 0 ならプレイヤーにモザイクをかけ, それ以外はこの値で FUN_0807ad60 を呼ぶ, gfx[0] / gfx[1] の選択にも使う
  u32 timer;              // 0x04, 毎フレーム +1, 6 から lifetime - 31 まで当たり判定を出し, lifetime - 30 から点滅して (lifetime - 15 からは速く) lifetime で消える
  u16 mosaicInterval[4];  // 0x08, MosaicFader_Start の interval
  Vec3 vel;               // 0x10, 毎フレーム sprite.pos に足す, y は 0
  HitboxData hitbox;      // 0x18
  AuxSprite sprite;       // 0x68
} Entity0805f2dcElem;
static_assert(sizeof(Entity0805f2dcElem) == 148);

// 輪っか (SPRITE_5AFE) を最大 12 個まで飛ばす
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx[2];           // 0x018, SPRITE_5AFE, [0] は kind が 0 以外, [1] は kind が 0 の輪っか用
  u32 lifetime;                  // 0x050, 輪っかが消えるまでのフレーム数, 60 未満なら 60
  Entity0805f2dcElem elems[12];  // 0x054
} Entity0805f2dc;
static_assert(sizeof(Entity0805f2dc) == 1860);

NAKED void Entity0805f2dc_OnHit(HitboxData* a, HitboxData* b, Entity0805f2dcElem* elem) { INCFUNC("asm/func/Entity0805f2dc_OnHit.inc"); }

NAKED s32 Entity0805f2dc_InitElem(Entity0805f2dc* p, Entity0805f2dcElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805f2dc_InitElem.inc"); }

NAKED void Entity0805f2dc_RemoveElem(Entity0805f2dc* p, Entity0805f2dcElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805f2dc_RemoveElem.inc"); }

NAKED s32 Entity0805f2dc_Update(Entity0805f2dc* p) { INCFUNC("asm/func/Entity0805f2dc_Update.inc"); }

NAKED s32 Entity0805f2dc_Destroy(Entity0805f2dc* p) { INCFUNC("asm/func/Entity0805f2dc_Destroy.inc"); }

NAKED s32 Entity0805f2dc_Init(Entity0805f2dc* p, u32 lifetime) { INCFUNC("asm/func/Entity0805f2dc_Init.inc"); }

NAKED Entity0805f2dcElem* Entity0805f2dc_FindFreeElem(Entity0805f2dc* p) { INCFUNC("asm/func/Entity0805f2dc_FindFreeElem.inc"); }

NAKED Entity0805f2dc* Entity0805f2dc_Create(u32 lifetime) { INCFUNC("asm/func/Entity0805f2dc_Create.inc"); }

NAKED s32 Entity0805f2dc_Spawn(Entity0805f2dc* p, s32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 kind, s32 mosaicInterval, Vec3* pos) { INCFUNC("asm/func/Entity0805f2dc_Spawn.inc"); }
