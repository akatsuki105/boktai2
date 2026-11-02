#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  Mover mover;        // 0x00, id は idx + 0x309
  AuxSprite sprite;   // 0x44, mover の sprite に結びつけるが AuxSprite_Add されない
  Vec3 pos;           // 0x70, 毎フレーム vel を足してタイルの高さに合わせる
  Vec3 vel;           // 0x78
  HitboxData hitbox;  // 0x80
  s16 count;          // 0xD0, 動くたびに 1 減り, 0 になると状態 2 で片付く
  u8 kind;            // 0xD2, 2 なら hitbox の属性が変わり, 移動のたびに周りへ FUN_081eec74 を8個出す
  u8 unk_d3;          // 0xD3
  u16 tileIdx;        // 0xD4, pos のタイル番号
  u8 idx;             // 0xD6, elems の添字, 空きは 0xFF
  u8 state;           // 0xD7, PTR_ARRAY_085ae4bc の添字
  s16 timer;          // 0xD8, 0 になるまで動かない
} Entity081edcc4Elem;
static_assert(sizeof(Entity081edcc4Elem) == 220);

// 不使用?
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  Entity081edcc4Elem elems[2];  // 0x018
  u32 activeMask;               // 0x1D0, elems の使用中ビット
} Entity081edcc4;
static_assert(sizeof(Entity081edcc4) == 468);

static Entity081edcc4* gEntity081edcc4;  // 0x030001C8

void Entity081edcc4Elem_UpdateState0(Entity081edcc4*, Entity081edcc4Elem*);
void Entity081edcc4Elem_UpdateState1(Entity081edcc4*, Entity081edcc4Elem*);
void Entity081edcc4Elem_UpdateState2(Entity081edcc4*, Entity081edcc4Elem*);

void (*const PTR_ARRAY_085ae4bc[3])(Entity081edcc4*, Entity081edcc4Elem*) = {
    Entity081edcc4Elem_UpdateState0,
    Entity081edcc4Elem_UpdateState1,
    Entity081edcc4Elem_UpdateState2,
};  // 0x085AE4BC

NAKED bool32 FUN_081eb348(Entity081edcc4Elem* elem, s32 angle, u32 tileIdx) { INCFUNC("asm/func/FUN_081eb348.inc"); }

NAKED void Entity081edcc4Elem_OnHit(HitboxData* a, HitboxData* b, Entity081edcc4Elem* elem) { INCFUNC("asm/func/Entity081edcc4Elem_OnHit.inc"); }

NAKED bool32 FUN_081ed650(Vec3* from, Vec3* to) { INCFUNC("asm/func/FUN_081ed650.inc"); }

NAKED void Entity081edcc4Elem_UpdateState0(Entity081edcc4* p, Entity081edcc4Elem* elem) { INCFUNC("asm/func/Entity081edcc4Elem_UpdateState0.inc"); }

NAKED void Entity081edcc4Elem_UpdateState1(Entity081edcc4* p, Entity081edcc4Elem* elem) { INCFUNC("asm/func/Entity081edcc4Elem_UpdateState1.inc"); }

NAKED void Entity081edcc4Elem_UpdateState2(Entity081edcc4* p, Entity081edcc4Elem* elem) { INCFUNC("asm/func/Entity081edcc4Elem_UpdateState2.inc"); }

NAKED Entity081edcc4Elem* Entity081edcc4_AllocElem(Entity081edcc4* p) { INCFUNC("asm/func/Entity081edcc4_AllocElem.inc"); }

NAKED s32 Entity081edcc4_Spawn(Vec3* pos, Vec3* vel, u32 count, u32 kind, s32 power, s32 knockbackPower, s32 invincibleTime) { INCFUNC("asm/func/Entity081edcc4_Spawn.inc"); }

NAKED s32 Entity081edcc4_Update(Entity081edcc4* p) { INCFUNC("asm/func/Entity081edcc4_Update.inc"); }

NAKED s32 Entity081edcc4_Destroy(Entity081edcc4* p) { INCFUNC("asm/func/Entity081edcc4_Destroy.inc"); }

NAKED s32 Entity081edcc4_Init(Entity081edcc4* p) { INCFUNC("asm/func/Entity081edcc4_Init.inc"); }

NAKED Entity081edcc4* Entity081edcc4_Create(void) { INCFUNC("asm/func/Entity081edcc4_Create.inc"); }

NAKED void Entity081edcc4_ClearGlobal(void) { INCFUNC("asm/func/Entity081edcc4_ClearGlobal.inc"); }
