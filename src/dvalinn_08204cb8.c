#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct Entity08204cb8Elem {
  AuxSprite sprite;   // 0x00, SPRFLAG_HIDDEN が立っていて timer が 0 以下なら空き
  AuxAnimState anim;  // 0x2C, state 0 は ANIM_38E2 の 0 番, state 1 は 1 番
  s16 timer;          // 0x3C, state 0 で毎フレーム減らし, 0 になった後にアニメが一巡すると state 1 へ
  u8 state;           // 0x3E, sEntity08204cb8ElemStates の添字
  bool8 stateInited;  // 0x3F, state に入った最初の更新で立てる
  bool8 active;       // 0x40, Entity08204cb8_Update は 1 のものだけ更新する
  u8 unk_41[3];       // 0x41, padding?
} Entity08204cb8Elem;
static_assert(sizeof(Entity08204cb8Elem) == 68);

// ドヴァリンの出す水の波紋のアニメを最大 16 個まで管理する
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, SPRITE_DVALIN_2E78
  AuxAnimFile* animFile;         // 0x034, ANIM_38E2
  u32 unk_38;                    // 0x038, Init が 0 を書くだけで読み手は未発見
  u8 activeCount;                // 0x03C, 使用中の elems の数, 奇数番目と偶数番目で点滅させるフレームを分ける
  u8 unk_3d[3];                  // 0x03D, padding?
  Entity08204cb8Elem elems[16];  // 0x040
} Entity08204cb8;
static_assert(sizeof(Entity08204cb8) == 1152);

static Entity08204cb8* gEntity08204cb8;  // 0x03000220

void Entity08204cb8_ElemStateLoop(Entity08204cb8* p, Entity08204cb8Elem* elem);
void Entity08204cb8_ElemStateEnd(Entity08204cb8* p, Entity08204cb8Elem* elem);

void (*const sEntity08204cb8ElemStates[2])(Entity08204cb8*, Entity08204cb8Elem*) = {
    Entity08204cb8_ElemStateLoop,
    Entity08204cb8_ElemStateEnd,
};  // 0x085AE834

NAKED Entity08204cb8Elem* Entity08204cb8_FindFreeElem(void) { INCFUNC("asm/func/Entity08204cb8_FindFreeElem.inc"); }

NAKED void Entity08204cb8_SetElemState(Entity08204cb8Elem* elem, u32 state) { INCFUNC("asm/func/Entity08204cb8_SetElemState.inc"); }

NAKED void Entity08204cb8_AddElem(Vec3* pos, s32 timer) { INCFUNC("asm/func/Entity08204cb8_AddElem.inc"); }

NAKED void Entity08204cb8_RemoveElem(Entity08204cb8Elem* elem) { INCFUNC("asm/func/Entity08204cb8_RemoveElem.inc"); }

NAKED void Entity08204cb8_ElemStateLoop(Entity08204cb8* p, Entity08204cb8Elem* elem) { INCFUNC("asm/func/Entity08204cb8_ElemStateLoop.inc"); }

NAKED void Entity08204cb8_ElemStateEnd(Entity08204cb8* p, Entity08204cb8Elem* elem) { INCFUNC("asm/func/Entity08204cb8_ElemStateEnd.inc"); }

NAKED s32 Entity08204cb8_Update(Entity08204cb8* p) { INCFUNC("asm/func/Entity08204cb8_Update.inc"); }

NAKED s32 Entity08204cb8_Destroy(Entity08204cb8* p) { INCFUNC("asm/func/Entity08204cb8_Destroy.inc"); }

NAKED s32 Entity08204cb8_InitElems(Entity08204cb8* p) { INCFUNC("asm/func/Entity08204cb8_InitElems.inc"); }

NAKED s32 Entity08204cb8_Init(Entity08204cb8* p) { INCFUNC("asm/func/Entity08204cb8_Init.inc"); }

NAKED Entity08204cb8* Entity08204cb8_Create(void) { INCFUNC("asm/func/Entity08204cb8_Create.inc"); }

NAKED void Entity08204cb8_Spawn(Vec3* pos, s32 timer) { INCFUNC("asm/func/Entity08204cb8_Spawn.inc"); }
