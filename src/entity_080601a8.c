#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

// Entity080601a8 が持つ粒子1個。FUN_08060220 が角度と速度を与えて飛ばし、
// FUN_0805ff58 が毎フレーム sprite.pos を動かして lifetime で解放する
typedef struct Entity080601a8Elem {
  u8 state;          // 0x00, PTR_ARRAY_085abaa4 の添字 (0 = 何もしない, 1 = 飛行中), 根拠: Entity080601a8_Update
  u8 unk_1;          // 0x01, 生成時に1、最初の更新で0にされる。読み手は未発見, 根拠: FUN_0805ff58
  u16 timer;         // 0x02, 毎フレーム +1, 根拠: Entity080601a8_Update
  s16 speed;         // 0x04, gSineTable との積が移動量になる, 根拠: FUN_0805ff58 の ldrsh
  s16 velY;          // 0x06, 毎フレーム sprite.pos.y に加算される, 根拠: FUN_0805ff58
  s8 angle;          // 0x08, gSineTable の添字 (向き)。毎フレーム angleStep が足される, 根拠: FUN_0805ff58 の ldrsb
  s8 angleStep;      // 0x09, 生成時 (rand & 3) - 2, 根拠: FUN_0805ff58
  u8 frame;          // 0x0A, 0..3。sprite.metaspriteIdx = frame + 0x36, 根拠: FUN_0805ff58 / FUN_08060220
  u8 frameTimer;     // 0x0B, 毎フレーム +1、frameDuration に達したら frame を進めて0に戻す, 根拠: FUN_0805ff58
  u8 frameDuration;  // 0x0C, 生成時 (rand & 3) + 7, 根拠: FUN_0805ff58
  u8 unk_d;          // 0x0D, FUN_08060220 の第6引数が入る。読み手は未発見
  u16 lifetime;      // 0x0E, timer がこれ以上になると解放される, 根拠: FUN_0805ff58
  AuxSprite sprite;  // 0x10, 根拠: AuxSprite_Setup / AuxSprite_Remove に渡される
} Entity080601a8Elem;
static_assert(sizeof(Entity080601a8Elem) == 60);

// 粒子を32個まで抱えるエンティティ。空きスロットは activeMask のビットで管理する
typedef struct Entity080601a8 {
  Entity e;                      // 0x00, ENTITY_UNK_8
  u32 unk_18;                    // 0x18, 読み手も書き手も未発見
  u32 activeMask;                // 0x1C, 1 << i で elems[i] が使用中, 根拠: Entity080601a8_Init が0クリア、FUN_0805ff34 がビットを落とす
  u32 unk_20;                    // 0x20, 読み手も書き手も未発見
  u32 unk_24;                    // 0x24, 読み手も書き手も未発見
  AuxSpriteGfx gfx;              // 0x28, 根拠: Video_GetAuxSprite / Video_SetAuxSpritePltt に渡される
  Entity080601a8Elem elems[32];  // 0x44, 根拠: _Init / _Update / _Destroy が stride 0x3C で32回まわす
} Entity080601a8;
static_assert(sizeof(Entity080601a8) == 1988);

NAKED void FUN_0805ff04(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ff04.inc"); }

NAKED void FUN_0805ff34(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ff34.inc"); }

NAKED void FUN_0805ff54(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ff54.inc"); }

NAKED void FUN_0805ff58(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_0805ff58.inc"); }

void (*const PTR_ARRAY_085abaa4[2])(Entity080601a8*, Entity080601a8Elem*, s32) = {
    FUN_0805ff54,
    FUN_0805ff58,
};  // 0x085ABAA4

NAKED s32 Entity080601a8_Update(Entity080601a8* p) { INCFUNC("asm/func/Entity080601a8_Update.inc"); }

NAKED s32 Entity080601a8_Destroy(Entity080601a8* p) { INCFUNC("asm/func/Entity080601a8_Destroy.inc"); }

NAKED s32 Entity080601a8_Init(Entity080601a8* p, u16 plttID, rgb555* pltt) { INCFUNC("asm/func/Entity080601a8_Init.inc"); }

NAKED Entity080601a8* Entity080601a8_Create(u16 plttID, rgb555* pltt) { INCFUNC("asm/func/Entity080601a8_Create.inc"); }

NAKED Entity080601a8Elem* FUN_080601f0(Entity080601a8* p, u32* outIdx) { INCFUNC("asm/func/FUN_080601f0.inc"); }

NAKED s32 FUN_08060220(Entity080601a8* p, s8 angle, s16 speed, s16 velY, u16 lifetime, u8 unk_d, Vec3* pos) { INCFUNC("asm/func/FUN_08060220.inc"); }
