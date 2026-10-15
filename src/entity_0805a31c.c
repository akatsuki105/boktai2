#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

typedef struct {
  u8 unk_0;                 // 0x000, まだ未解析
  bool8 stateEntered;       // 0x001, state を変えるたびに 1 を書く
  u8 state;                 // 0x002, PTR_ARRAY_085ab9ec の添字
  u8 plttState;             // 0x003, いま設定してあるパレットの種別
  u8 plttWanted;            // 0x004, 0 で 301, 1 で 304, 2 で 305 にする
  u8 unk_5[3];              // 0x005, まだ未解析
  u16 timer;                // 0x008, state を変えるたびに 0 に戻る
  u8 unk_a[2];              // 0x00A, まだ未解析
  u8 unk_c;                 // 0x00C, 初期化で 0 を書く
  s8 angle;                 // 0x00D, sprite の +0x06 に -(angle + 0x60) として入れる向き
  u8 unk_e[14];             // 0x00E, まだ未解析
  HitboxData attackHitbox;  // 0x01C, flags 0x2001, ignoreMask 0x10, 攻撃側
  HitboxData bodyHitbox;    // 0x06C, flags 0x4005, ignoreMask 0x10, 被弾側
  AuxSprite sprite;         // 0x0BC, AFFINE|UNK_0, +0x1C の Vec3 を両方の Hitbox_SetPos に渡す
  AuxSpriteGfx gfx;         // 0x0E8, SPRITE_5292
} Entity0805a31cElem;
static_assert(sizeof(Entity0805a31cElem) == 260);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  u32 activeMask;               // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;                 // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;                    // 0x01E, 10, 各枠の Hitbox_SetPowerAndAttributes に渡す
  Entity0805a31cElem elems[8];  // 0x020
} Entity0805a31c;
static_assert(sizeof(Entity0805a31c) == 2112);

void FUN_08059d60(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_08059d98(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_08059e9c(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_08059f1c(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_0805a09c(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_0805a0dc(Entity0805a31c*, Entity0805a31cElem*, s32);

// Entity0805a31c_Update が引く
void (*const PTR_ARRAY_085ab9ec[6])(Entity0805a31c*, Entity0805a31cElem*, s32) = {
    FUN_08059d60,
    FUN_08059d98,
    FUN_08059e9c,
    FUN_08059f1c,
    FUN_0805a09c,
    FUN_0805a0dc,
};  // 0x085AB9EC

NAKED Entity0805a31cElem* FUN_08059b7c(Entity0805a31c* p, u32* outIndex) { INCFUNC("asm/func/FUN_08059b7c.inc"); }

NAKED void FUN_08059bb0(HitboxData* a, HitboxData* b, Entity0805a31cElem* owner) { INCFUNC("asm/func/FUN_08059bb0.inc"); }

NAKED void FUN_08059bcc(void) { INCFUNC("asm/func/FUN_08059bcc.inc"); }

NAKED s32 FUN_08059bd0(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059bd0.inc"); }

NAKED s32 FUN_08059d1c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059d1c.inc"); }

NAKED s32 FUN_08059d38(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059d38.inc"); }

NAKED void FUN_08059d60(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059d60.inc"); }

NAKED void FUN_08059d98(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059d98.inc"); }

NAKED void FUN_08059e9c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059e9c.inc"); }

NAKED void FUN_08059f1c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059f1c.inc"); }

NAKED void FUN_0805a09c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a09c.inc"); }

NAKED void FUN_0805a0dc(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a0dc.inc"); }

NAKED s32 Entity0805a31c_Update(Entity0805a31c* p) { INCFUNC("asm/func/Entity0805a31c_Update.inc"); }

NAKED s32 Entity0805a31c_Destroy(Entity0805a31c* p) { INCFUNC("asm/func/Entity0805a31c_Destroy.inc"); }

NAKED s32 Entity0805a31c_Init(Entity0805a31c* p, u16 attackID) { INCFUNC("asm/func/Entity0805a31c_Init.inc"); }

NAKED Entity0805a31c* Entity0805a31c_Create(u16 param_1) { INCFUNC("asm/func/Entity0805a31c_Create.inc"); }

NAKED s32 FUN_0805a360(u32 param_1, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_0805a360.inc"); }

NAKED s32 FUN_0805a43c(Entity0805a31c* p, u32 param_2) { INCFUNC("asm/func/FUN_0805a43c.inc"); }
