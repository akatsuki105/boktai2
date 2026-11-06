#include "entity.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// 出現アニメ → delay フレーム待機 → 消滅アニメの順に1回だけ再生されるエフェクト1個
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxAnimState anim;      // 0x2C, animIdx 1, 出現は variant 0, 消滅は variant 1
  AuxAnimFile* animFile;  // 0x3C, ANIM_121B
  s32 delay;              // 0x40, state 2 の残りフレーム数
  u16 unk_44;             // 0x44, 生成時に 0 が入るだけ
  u8 state;               // 0x46, PTR_ARRAY_085ae5a4 の添字 (0:待機 1:出現 2:待ち 3:消滅)
  s8 slotIdx;             // 0x47, usedMask 上の自分のビット番号, 空きは -1
} Entity081f7974Elem;
static_assert(sizeof(Entity081f7974Elem) == 72);

// エフェクトを16個まで同時に出すシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x018, SPRITE_EFF_F422
  u8 unk_34[4];                  // 0x034
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f7974Elem elems[16];  // 0x03C
} Entity081f7974;
static_assert(sizeof(Entity081f7974) == 1212);

static Entity081f7974* gEntity081f7974;  // 0x03000200

void Entity081f7974_UpdateIdle(Entity081f7974*, Entity081f7974Elem*);
void Entity081f7974_UpdateAppear(Entity081f7974*, Entity081f7974Elem*);
void Entity081f7974_UpdateWait(Entity081f7974*, Entity081f7974Elem*);
void Entity081f7974_UpdateVanish(Entity081f7974*, Entity081f7974Elem*);

void (*const PTR_ARRAY_085ae5a4[4])(Entity081f7974*, Entity081f7974Elem*) = {
    Entity081f7974_UpdateIdle,
    Entity081f7974_UpdateAppear,
    Entity081f7974_UpdateWait,
    Entity081f7974_UpdateVanish,
};  // 0x085AE5A4

NAKED Entity081f7974Elem* Entity081f7974_AllocElem(Entity081f7974* p) { INCFUNC("asm/func/Entity081f7974_AllocElem.inc"); }

NAKED void Entity081f7974_UpdateIdle(Entity081f7974* p, Entity081f7974Elem* elem) { INCFUNC("asm/func/Entity081f7974_UpdateIdle.inc"); }

NAKED void Entity081f7974_UpdateAppear(Entity081f7974* p, Entity081f7974Elem* elem) { INCFUNC("asm/func/Entity081f7974_UpdateAppear.inc"); }

NAKED void Entity081f7974_UpdateWait(Entity081f7974* p, Entity081f7974Elem* elem) { INCFUNC("asm/func/Entity081f7974_UpdateWait.inc"); }

NAKED void Entity081f7974_UpdateVanish(Entity081f7974* p, Entity081f7974Elem* elem) { INCFUNC("asm/func/Entity081f7974_UpdateVanish.inc"); }

NAKED void Entity081f7974_Spawn(Vec3* pos, s32 delay) { INCFUNC("asm/func/Entity081f7974_Spawn.inc"); }

NAKED s32 Entity081f7974_Update(Entity081f7974* p) { INCFUNC("asm/func/Entity081f7974_Update.inc"); }

NAKED s32 Entity081f7974_Destroy(Entity081f7974* p) { INCFUNC("asm/func/Entity081f7974_Destroy.inc"); }

NAKED s32 Entity081f7974_Init(Entity081f7974* p) { INCFUNC("asm/func/Entity081f7974_Init.inc"); }

NAKED Entity081f7974* Entity081f7974_Create(void) { INCFUNC("asm/func/Entity081f7974_Create.inc"); }

NAKED void Entity081f7974_ClearGlobal(void) { INCFUNC("asm/func/Entity081f7974_ClearGlobal.inc"); }
