#include "entity.h"
#include "global.h"
#include "player.h"
#include "shadow.h"
#include "sprite_aux.h"

typedef struct Entity150F Entity150F;
typedef struct Entity150FSlot Entity150FSlot;
typedef void(Entity150FSlotFunc)(Entity150F* p, Entity150FSlot* slot, s32 idx);

struct Entity150FSlot {
  s8 unk_00;               // 0x00, FUN_081e1220 の第3引数, gEntity9A9F->unk_118[i]
  u8 unk_01;               // 0x01, FUN_081e1220 が 0 を入れる
  u8 unk_02;               // 0x02, FUN_081e1220 が 0 を入れる
  u8 unk_03;               // 0x03, FUN_081e1220 が 0 を入れる
  u8 unk_04[2];            // 0x04, まだ未解析
  u16 unk_06;              // 0x06, FUN_081e1220 が 0 を入れる
  u8 unk_08[0x20 - 0x08];  // 0x08, まだ未解析
  Entity150FSlotFunc* fn;  // 0x20, _Update が 0 以外のときだけ呼ぶ
  AuxSprite sprite;        // 0x24
  ParticleShadow shadow;   // 0x50, ParticleShadow_Init(&shadow, &sprite.pos, 0) の直後に Hide
};
static_assert(sizeof(Entity150FSlot) == 144);

struct Entity150F {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u32 frameCount;           // 0x018, _Update が毎フレーム +1
  s16 unk_1c;               // 0x01C, '.p=0'
  u8 unk_1e[2];             // 0x01E, padding?
  AuxSpriteGfx gfx;         // 0x020, SPRITE_2712
  Vec3 unk_3c[4];           // 0x03C, players[i] の位置を射影したもの, x=(pos.x-pos.z)*0x30>>8, y=sum-pos.y*0x18>>8, z=sum+pos.y*0x18>>8
  Player* players[4];       // 0x05C, gPlayerPtr[0..3] の写し
  Entity150FSlot slots[5];  // 0x06C, _Init が FUN_081e1220 で5個作り、_Destroy が FUN_081e1260 で片付ける
};
static_assert(sizeof(Entity150F) == 828);

extern Entity150F* gEntity150F;  // 0x030001B0

void FUN_081e0c14(void) { gEntity150F = NULL; }

NAKED void FUN_081e0c20(Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e0c20.inc"); }

NAKED void FUN_081e0ec0(Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e0ec0.inc"); }

NAKED void FUN_081e10b8(Entity150FSlot* slot, u32 param_2) { INCFUNC("asm/func/FUN_081e10b8.inc"); }

NAKED s32 FUN_081e1220(Entity150F* p, Entity150FSlot* slot, s32 param_3) { INCFUNC("asm/func/FUN_081e1220.inc"); }

s32 FUN_081e1260(Entity150F* p, Entity150FSlot* slot) {
  AuxSprite_Remove(&slot->sprite);
  ParticleShadow_Remove(&slot->shadow);
  return 0;
}

NAKED void FUN_081e127c(Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e127c.inc"); }

NAKED s32 FUN_081e12a4(Entity150F* p, s32 param_2) { INCFUNC("asm/func/FUN_081e12a4.inc"); }

NAKED s32 FUN_081e12c8(Entity150F* p, Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e12c8.inc"); }

NAKED s32 FUN_081e1344(Entity150F* p, Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e1344.inc"); }

NAKED void FUN_081e1438(Entity150F* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e1438.inc"); }

NAKED void FUN_081e1524(Entity150F* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e1524.inc"); }

NAKED void FUN_081e15b4(Entity150F* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e15b4.inc"); }

NAKED void FUN_081e169c(Entity150F* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e169c.inc"); }

NAKED void FUN_081e1734(Entity150F* p) { INCFUNC("asm/func/FUN_081e1734.inc"); }

NAKED s32 Entity150F_Update(Entity150F* p) { INCFUNC("asm/func/Entity150F_Update.inc"); }

NAKED s32 Entity150F_Destroy(Entity150F* p) { INCFUNC("asm/func/Entity150F_Destroy.inc"); }

NAKED s32 Entity150F_Init(Entity150F* p) { INCFUNC("asm/func/Entity150F_Init.inc"); }

NAKED Entity150F* Entity150F_Create(void) { INCFUNC("asm/func/Entity150F_Create.inc"); }

NAKED s32 FUN_081e1984(unknown* param_1) { INCFUNC("asm/func/FUN_081e1984.inc"); }
