#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

typedef struct {
  bool8 active;             // 0x000, 初期化で 1 を書く
  u8 state;                 // 0x001, PTR_ARRAY_085aba04 の添字
  u8 unk_2[4];              // 0x002, まだ未解析
  u16 timer;                // 0x006, 初期化で 0 を書く
  u8 unk_8[2];              // 0x008, まだ未解析
  u8 angle;                 // 0x00A, 被弾したとき攻撃元への角度を入れる
  u8 unk_b;                 // 0x00B, 初期化で 0 を書く
  u8 unk_c[6];              // 0x00C, まだ未解析
  u16 hp;                   // 0x012, 被弾で相手の damage の分だけ減り、0 で state 6 へ移る
  Vec3 pos;                 // 0x014, 両方の Hitbox_SetPos に渡す
  u8 unk_1c[44];            // 0x01C, まだ未解析
  HitboxData attackHitbox;  // 0x048, flags 0x2001, ignoreMask 0x10, 攻撃側
  HitboxData bodyHitbox;    // 0x098, flags 0x5005, ignoreMask 0x10, 被弾側
  AuxAnimState animState;   // 0x0E8, sprites[0] の再生状態
  AuxSprite sprites[4];     // 0x0F8, [0] は priority 1 でアニメ付き, [1..3] は priority 2
  AuxSpriteGfx gfx;         // 0x1A8, SPRITE_EFF_3668, パレット 200
} Entity0805b068Elem;
static_assert(sizeof(Entity0805b068Elem) == 452);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  u32 activeMask;               // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;                 // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;                    // 0x01E, Init の第3引数, 各枠の Hitbox_SetPowerAndAttributes に渡す
  AuxAnimFile* anim;            // 0x020, ANIM_78E1
  Entity0805b068Elem elems[8];  // 0x024
} Entity0805b068;
static_assert(sizeof(Entity0805b068) == 3652);

void FUN_0805a938(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805a988(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805a9e8(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ab18(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ab70(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ad78(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ae44(Entity0805b068*, Entity0805b068Elem*, s32);

// Entity0805b068_Update が引く
void (*const PTR_ARRAY_085aba04[7])(Entity0805b068*, Entity0805b068Elem*, s32) = {
    FUN_0805a938,
    FUN_0805a988,
    FUN_0805a9e8,
    FUN_0805ab18,
    FUN_0805ab70,
    FUN_0805ad78,
    FUN_0805ae44,
};  // 0x085ABA04

NAKED void FUN_0805a470(HitboxData* a, HitboxData* b, Entity0805b068Elem* owner) { INCFUNC("asm/func/FUN_0805a470.inc"); }

NAKED void FUN_0805a52c(HitboxData* a, HitboxData* b, Entity0805b068Elem* owner) { INCFUNC("asm/func/FUN_0805a52c.inc"); }

NAKED s32 FUN_0805a53c(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a53c.inc"); }

NAKED s32 FUN_0805a6c8(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a6c8.inc"); }

NAKED s32 FUN_0805a6ec(Entity0805b068Elem* elem) { INCFUNC("asm/func/FUN_0805a6ec.inc"); }

NAKED void FUN_0805a728(Entity0805b068Elem* elem) { INCFUNC("asm/func/FUN_0805a728.inc"); }

NAKED void FUN_0805a8b0(Entity0805b068Elem* elem) { INCFUNC("asm/func/FUN_0805a8b0.inc"); }

NAKED void FUN_0805a8d0(Entity0805b068Elem* elem) { INCFUNC("asm/func/FUN_0805a8d0.inc"); }

NAKED void FUN_0805a8f0(Entity0805b068Elem* elem) { INCFUNC("asm/func/FUN_0805a8f0.inc"); }

NAKED void FUN_0805a938(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a938.inc"); }

NAKED void FUN_0805a988(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a988.inc"); }

NAKED void FUN_0805a9e8(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a9e8.inc"); }

NAKED void FUN_0805ab18(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ab18.inc"); }

NAKED void FUN_0805ab70(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ab70.inc"); }

NAKED void FUN_0805ad78(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ad78.inc"); }

NAKED void FUN_0805ae44(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ae44.inc"); }

NAKED s32 Entity0805b068_Update(Entity0805b068* p) { INCFUNC("asm/func/Entity0805b068_Update.inc"); }

NAKED s32 Entity0805b068_Destroy(Entity0805b068* p) { INCFUNC("asm/func/Entity0805b068_Destroy.inc"); }

NAKED s32 Entity0805b068_Init(Entity0805b068* p, u16 attackID, u16 power) { INCFUNC("asm/func/Entity0805b068_Init.inc"); }

NAKED Entity0805b068* Entity0805b068_Create(u16 param_1, u16 param_2) { INCFUNC("asm/func/Entity0805b068_Create.inc"); }

NAKED s32 FUN_0805b0b0(unknown* p) { INCFUNC("asm/func/FUN_0805b0b0.inc"); }
