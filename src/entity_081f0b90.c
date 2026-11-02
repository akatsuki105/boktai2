#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  AuxSprite sprites[4];   // 0x000, 画面座標で描く, 状態 1 では 3 枚を縦に 32 ずつずらし, 状態 2 では 4 枚を十字に広げる
  AuxAnimState anims[4];  // 0x0B0
  Vec3 pos;               // 0x0F0, 生成位置 (ワールド座標)
  Vec3 hitPos;            // 0x0F8, pos から y を 0x300 下げた hitbox の位置
  HitboxData hitbox;      // 0x100
  s16 unk_150;            // 0x150
  u8 state;               // 0x152, PTR_ARRAY_085ae518 の添字, 1 で 5 フレーム判定を出し, 2 で広がり, アニメが一巡すると 3 で片付く
  s8 idx;                 // 0x153, elems の添字, 空きは -1
  u16 scriptID;           // 0x154, 片付けるときに 0 でなければ VM_ExecByID で実行する
  u8 unk_156[2];          // 0x156
  u16 timer;              // 0x158, 状態に入ってからのフレーム数
  bool8 stateEntered;     // 0x15A, 状態が変わったときに 1, 次の状態関数の最初で 0 に戻る
} Entity081f0b90Elem;
static_assert(sizeof(Entity081f0b90Elem) == 348);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_SKELETON_MISC
  AuxAnimFile* animFile;        // 0x034, ANIM_1DC3
  u32 activeMask;               // 0x038, elems の使用中ビット
  Entity081f0b90Elem elems[4];  // 0x03C
} Entity081f0b90;
static_assert(sizeof(Entity081f0b90) == 1452);

static Entity081f0b90* gEntity081f0b90;  // 0x030001E4

void Entity081f0b90Elem_UpdateState0(Entity081f0b90*, Entity081f0b90Elem*);
void Entity081f0b90Elem_UpdateState2(Entity081f0b90*, Entity081f0b90Elem*);
void Entity081f0b90Elem_UpdateState3(Entity081f0b90*, Entity081f0b90Elem*);
void Entity081f0b90Elem_UpdateState1(Entity081f0b90*, Entity081f0b90Elem*);

void (*const PTR_ARRAY_085ae518[4])(Entity081f0b90*, Entity081f0b90Elem*) = {
    Entity081f0b90Elem_UpdateState0,
    Entity081f0b90Elem_UpdateState1,
    Entity081f0b90Elem_UpdateState2,
    Entity081f0b90Elem_UpdateState3,
};  // 0x085AE518

NAKED void Entity081f0b90Elem_ExecScript(Entity081f0b90Elem* elem) { INCFUNC("asm/func/Entity081f0b90Elem_ExecScript.inc"); }

NAKED void Entity081f0b90Elem_OnHit(HitboxData* a, HitboxData* b, Entity081f0b90Elem* elem) { INCFUNC("asm/func/Entity081f0b90Elem_OnHit.inc"); }

NAKED void Entity081f0b90Elem_InitHitbox(Entity081f0b90Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081f0b90Elem_InitHitbox.inc"); }

NAKED void Entity081f0b90Elem_UpdateState0(Entity081f0b90* p, Entity081f0b90Elem* elem) { INCFUNC("asm/func/Entity081f0b90Elem_UpdateState0.inc"); }

NAKED void Entity081f0b90Elem_UpdateState2(Entity081f0b90* p, Entity081f0b90Elem* elem) { INCFUNC("asm/func/Entity081f0b90Elem_UpdateState2.inc"); }

NAKED void Entity081f0b90Elem_UpdateState3(Entity081f0b90* p, Entity081f0b90Elem* elem) { INCFUNC("asm/func/Entity081f0b90Elem_UpdateState3.inc"); }

NAKED void Entity081f0b90Elem_UpdateState1(Entity081f0b90* p, Entity081f0b90Elem* elem) { INCFUNC("asm/func/Entity081f0b90Elem_UpdateState1.inc"); }

NAKED Entity081f0b90Elem* Entity081f0b90_AllocElem(Entity081f0b90* p) { INCFUNC("asm/func/Entity081f0b90_AllocElem.inc"); }

NAKED Entity081f0b90Elem* FUN_081f08dc(Entity081f0b90* p) { INCFUNC("asm/func/FUN_081f08dc.inc"); }

NAKED void Entity081f0b90_Spawn(Vec3* pos, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime, s32 _, u32 scriptID) { INCFUNC("asm/func/Entity081f0b90_Spawn.inc"); }

NAKED s32 Entity081f0b90_Update(Entity081f0b90* p) { INCFUNC("asm/func/Entity081f0b90_Update.inc"); }

NAKED s32 Entity081f0b90_Destroy(Entity081f0b90* p) { INCFUNC("asm/func/Entity081f0b90_Destroy.inc"); }

NAKED s32 Entity081f0b90_Init(Entity081f0b90* p) { INCFUNC("asm/func/Entity081f0b90_Init.inc"); }

NAKED Entity081f0b90* Entity081f0b90_Create(void) { INCFUNC("asm/func/Entity081f0b90_Create.inc"); }

NAKED void Entity081f0b90_ClearGlobal(void) { INCFUNC("asm/func/Entity081f0b90_ClearGlobal.inc"); }
