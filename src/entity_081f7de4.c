#include "entity.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// Entity081f7de4 が出すエフェクト1個ぶん
typedef struct {
  AuxSprite spr;           // 0x000
  AuxAnimState anim;       // 0x02C
  u8 unk_3c[0x8C - 0x3C];  // 0x03C, まだ未解析
  AuxAnimFile* animFile;   // 0x08C, ANIM_8DC7
  u32 unk_90;              // 0x090, 生成時に120が入るだけ, 読み手は未発見
  u16 unk_94;              // 0x094, 生成時に0が入るだけ, 読み手は未発見
  u8 state;                // 0x096, PTR_ARRAY_085ae5b4 の添字 (0: 何もしない, 1: 回転中, 2: 片付け)
  s8 idx;                  // 0x097, Entity081f7de4.activeMask のビット位置, 負なら未使用
  u16 timer;               // 0x098, state 1 の間 1フレームごとに +1
  bool8 resetTimer;        // 0x09A, 次の更新で timer を 0 に戻す
  u8 unk_9b;               // 0x09B
} Entity081f7de4Elem;
static_assert(sizeof(Entity081f7de4Elem) == 156);

// 指定座標にアフィン回転するエフェクトを最大2個まで出すエンティティ
// おそらく、シャイアンの回転斬り
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_EFF_SHAIAN_SPIN
  u8 unk_34[4];                 // 0x034
  u32 activeMask;               // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f7de4Elem elems[2];  // 0x03C
} Entity081f7de4;
static_assert(sizeof(Entity081f7de4) == 372);

static Entity081f7de4* gEntity081f7de4;  // 0x03000204

void Entity081f7de4_UpdateState0(Entity081f7de4*, Entity081f7de4Elem*);
void Entity081f7de4_UpdateState1(Entity081f7de4*, Entity081f7de4Elem*);
void Entity081f7de4_UpdateState2(Entity081f7de4*, Entity081f7de4Elem*);

void (*const PTR_ARRAY_085ae5b4[3])(Entity081f7de4*, Entity081f7de4Elem*) = {
    Entity081f7de4_UpdateState0,
    Entity081f7de4_UpdateState1,
    Entity081f7de4_UpdateState2,
};  // 0x085AE5B4

NAKED Entity081f7de4Elem* Entity081f7de4_AllocElem(Entity081f7de4* p) { INCFUNC("asm/func/Entity081f7de4_AllocElem.inc"); }

NAKED void Entity081f7de4_UpdateState0(Entity081f7de4* p, Entity081f7de4Elem* elem) { INCFUNC("asm/func/Entity081f7de4_UpdateState0.inc"); }

NAKED void Entity081f7de4_UpdateState1(Entity081f7de4* p, Entity081f7de4Elem* elem) { INCFUNC("asm/func/Entity081f7de4_UpdateState1.inc"); }

NAKED void Entity081f7de4_UpdateState2(Entity081f7de4* p, Entity081f7de4Elem* elem) { INCFUNC("asm/func/Entity081f7de4_UpdateState2.inc"); }

NAKED void Entity081f7de4_Spawn(Vec3* pos, u32 rotation) { INCFUNC("asm/func/Entity081f7de4_Spawn.inc"); }

NAKED s32 Entity081f7de4_Update(Entity081f7de4* p) { INCFUNC("asm/func/Entity081f7de4_Update.inc"); }

NAKED s32 Entity081f7de4_Destroy(Entity081f7de4* p) { INCFUNC("asm/func/Entity081f7de4_Destroy.inc"); }

NAKED s32 Entity081f7de4_Init(Entity081f7de4* p) { INCFUNC("asm/func/Entity081f7de4_Init.inc"); }

NAKED Entity081f7de4* Entity081f7de4_Create(void) { INCFUNC("asm/func/Entity081f7de4_Create.inc"); }

NAKED void Entity081f7de4_ClearGlobal(void) { INCFUNC("asm/func/Entity081f7de4_ClearGlobal.inc"); }

NAKED void Entity081f7de4_RemoveAll(void) { INCFUNC("asm/func/Entity081f7de4_RemoveAll.inc"); }
