#include "animation.h"
#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "shadow.h"
#include "sprite_aux.h"
#include "video.h"

typedef struct {
  u8 active;               // 0x00, FUN_080117d8 が 1 を入れる
  u8 unk_01;               // 0x01, FUN_080117d8 が 0 を入れる
  u8 unk_02[2];            // 0x02, まだ未解析
  u16 unk_04;              // 0x04, FUN_080117d8 が 0 を入れる
  u8 unk_06;               // 0x06, FUN_080117d8 が 0 を入れる
  u8 unk_07[0x40 - 0x07];  // 0x07, まだ未解析
  AuxSprite sprite;        // 0x40, AuxSprite_Add で登録する
  AuxSpriteGfx gfx;        // 0x6C, Video_GetAuxSprite(0xDA6D) / Video_SetAuxSpritePltt(0x263)
  ParticleShadow shadow;   // 0x88, ParticleShadow_Init(&shadow, &sprite.pos, 0) のあと Hide する
} EntityE534Elem;
static_assert(sizeof(EntityE534Elem) == 200);

typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  u32 unk_18;                 // 0x018, _Init が 0 を入れる
  u8 unk_1c[4];               // 0x01C, まだ未解析
  AuxAnimFile* anim;          // 0x020, GetFile(DIR_ANIMATION, 0x5BB7)
  EntityE534Elem elems[16];   // 0x024, _Init が FUN_080117d8 で16個初期化し、_Destroy が FUN_08011854 で片付ける
  u8 unk_ca4[2];              // 0xCA4, まだ未解析
  u16 unk_ca6;                // 0xCA6, _Init が 0 を入れる
  rgb555 pltt[16];            // 0xCA8, BlendPltt(&pltt, gObjPlttData+0x2630, gObjPlttData+0x2650, 0x40, 6), elems[i].gfx.pltt がここを指す
  u32 unk_cc8;                // 0xCC8, _Init が 0 を入れる
  u8 unk_ccc[0xCD4 - 0xCCC];  // 0xCCC, まだ未解析
  EntityMsgBox msgbox;        // 0xCD4, _Destroy が EntityMsgBus_Unregister に渡す
} EntityE534;
static_assert(sizeof(EntityE534) == 3336);

void FUN_080120d4(EntityE534*, void*, void*);
void FUN_0801230c(EntityE534*, void*, void*);
void FUN_08012194(EntityE534*, void*, void*);
void FUN_080124e0(EntityE534*, void*, void*);
void FUN_08012698(EntityE534*, void*, void*);
void FUN_0801280c(EntityE534*, void*, void*);
void FUN_080128cc(EntityE534*, void*, void*);

void (*const PTR_ARRAY_085aa81c[7])(EntityE534*, void*, void*) = {
    FUN_080120d4, FUN_0801230c, FUN_08012194, FUN_080124e0, FUN_08012698, FUN_0801280c, FUN_080128cc,
};  // 0x085aa81c

INCASM("asm/entity_e534.inc");

NAKED s32 EntityE534_Update(EntityE534* p) { INCFUNC("asm/func/EntityE534_Update.inc"); }

void FUN_08011854(EntityE534* p, EntityE534Elem* e, s32 idx);

s32 EntityE534_Destroy(EntityE534* p) {
  EntityE534Elem* e = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, e++) {
    FUN_08011854(p, e, i);
  }

  EntityMsgBus_Unregister(&p->msgbox);
  return 0;
}

NAKED s32 EntityE534_Init(EntityE534* p, u32 id) { INCFUNC("asm/func/EntityE534_Init.inc"); }

NAKED EntityE534* EntityE534_Create(u32 id) { INCFUNC("asm/func/EntityE534_Create.inc"); }
