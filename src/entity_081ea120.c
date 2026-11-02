#include "entity.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  Vec3 pos;      // 0x00, sprites[idx] の位置
  u8 unk_08[2];  // 0x08
  u8 state;      // 0x0A, PTR_ARRAY_085ae45c の添字, 1 でアニメを流し, 一巡すると 2 で片付ける
  s8 idx;        // 0x0B, sprites と anims の添字, 空きは -1
} Entity081ea120Item;
static_assert(sizeof(Entity081ea120Item) == 12);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxAnimFile* animFile;        // 0x018, ANIM_931E
  AuxSprite sprites[8];         // 0x01C
  AuxSpriteGfx gfx;             // 0x17C, SPRITE_863A
  AuxAnimState anims[8];        // 0x198
  u32 activeMask;               // 0x218, items の使用中ビット
  Entity081ea120Item items[8];  // 0x21C
} Entity081ea120;
static_assert(sizeof(Entity081ea120) == 636);

static Entity081ea120* gEntity081ea120;  // 0x030001B8

void Entity081ea120Item_UpdateState0(Entity081ea120*, Entity081ea120Item*);
void Entity081ea120Item_UpdateState1(Entity081ea120*, Entity081ea120Item*);
void Entity081ea120Item_UpdateState2(Entity081ea120*, Entity081ea120Item*);

// Entity081ea120_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae45c[3])(Entity081ea120*, Entity081ea120Item*) = {
    Entity081ea120Item_UpdateState0,
    Entity081ea120Item_UpdateState1,
    Entity081ea120Item_UpdateState2,
};  // 0x085AE45C

const u8 u8_ARRAY_085ae468[4] = {8, 4, 2, 1};  // 0x085AE468, Entity081ea820Elem_UpdateState2 が Mod の除数として引く

NAKED void Entity081ea120Item_UpdateState0(Entity081ea120* p, Entity081ea120Item* item) { INCFUNC("asm/func/Entity081ea120Item_UpdateState0.inc"); }

NAKED void Entity081ea120Item_UpdateState1(Entity081ea120* p, Entity081ea120Item* item) { INCFUNC("asm/func/Entity081ea120Item_UpdateState1.inc"); }

NAKED void Entity081ea120Item_UpdateState2(Entity081ea120* p, Entity081ea120Item* item) { INCFUNC("asm/func/Entity081ea120Item_UpdateState2.inc"); }

NAKED Entity081ea120Item* Entity081ea120_AllocItem(Entity081ea120* p) { INCFUNC("asm/func/Entity081ea120_AllocItem.inc"); }

NAKED s32 Entity081ea120_Spawn(Vec3* pos, s32 count, u32 priority, u32 animIdx, s32 plttID) { INCFUNC("asm/func/Entity081ea120_Spawn.inc"); }

NAKED s32 Entity081ea120_Update(Entity081ea120* p) { INCFUNC("asm/func/Entity081ea120_Update.inc"); }

NAKED s32 Entity081ea120_Destroy(Entity081ea120* p) { INCFUNC("asm/func/Entity081ea120_Destroy.inc"); }

NAKED void Entity081ea120_LoadAuxSprite(Entity081ea120* p) { INCFUNC("asm/func/Entity081ea120_LoadAuxSprite.inc"); }

NAKED s32 Entity081ea120_Init(Entity081ea120* p, u32 _) { INCFUNC("asm/func/Entity081ea120_Init.inc"); }

NAKED Entity081ea120* Entity081ea120_Create(u32 id, u32 param_2) { INCFUNC("asm/func/Entity081ea120_Create.inc"); }

NAKED void Entity081ea120_ClearGlobal(void) { INCFUNC("asm/func/Entity081ea120_ClearGlobal.inc"); }
