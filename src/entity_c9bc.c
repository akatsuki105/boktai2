#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"
#include "struct.h"

// EntityC9BC が count 個まとめて管理する要素
typedef struct {
  bool8 active;  // 0x00, 0 以外なら使用中, FUN_0800cb7c で 0 に戻る
  u8 unk_01[3 - 1];
  u8 state;  // 0x03, PTR_ARRAY_085aa774 の添字
  u8 unk_04[0x44 - 0x04];
  bool8 releaseReq;  // 0x44, 0 以外なら EntityC9BC_Update が FUN_0800cb7c で解放する
  u8 unk_45[0x48 - 0x45];
  Entity2UnkData obj;  // 0x48, 根拠: FUN_0800cb7c, obj.id は FUN_0800db48 の検索キー
  AuxSpriteGfx gfx;    // 0x8C, 根拠: FUN_0800ccd0 が Video_SetAuxSpritePltt に渡す
  AuxSprite spr_a8;    // 0xA8, 根拠: FUN_0800cb7c
  u8 unk_d4[0xF0 - 0xD4];
  AuxSprite spr_f0;  // 0xF0, 根拠: FUN_0800cb7c
  u8 unk_11c[0x12C - 0x11C];
  HitboxData hitbox;  // 0x12C, 根拠: FUN_0800cb7c
  u8 unk_17c[0x1FC - 0x17C];
} EntityC9BCElem;
static_assert(sizeof(EntityC9BCElem) == 508);

// count 個の要素を状態関数で動かし、全体をサイン波で上下に揺らしながら、パレット 120 と 121 / 122 の間で色を点滅させる
typedef struct {
  Entity e;               // ENTITY_UNK_9
  u32 unk_18;             // 0x18, EntityC9BC_Init で 0 を入れるだけ
  u32 count;              // 0x1C, '.m=4', 要素数
  s16 bobOffset;          // 0x20, sin(bobAngle) * 16, 各要素の高さに加算される
  u8 bobAngle;            // 0x22, gSineTable の添字, 毎フレーム +2
  u8 fadeDir;             // 0x23, 0 なら fadeLevel を増やし 32 で 1 に, 1 なら減らし 0 で 0 に戻る
  s16 fadeLevel;          // 0x24, 0..32, BlendPltt の混合率
  u8 unk_26[2];           // 0x26, padding?
  rgb555* plttBase;       // 0x28, &gObjPlttData[120 * 16]
  rgb555* plttBlendA;     // 0x2C, &gObjPlttData[121 * 16]
  rgb555* plttBlendB;     // 0x30, &gObjPlttData[122 * 16]
  rgb555 plttBufA[16];    // 0x34, plttBase と plttBlendA の中間色, 要素のパレットが 121 のとき使う
  rgb555 plttBufB[16];    // 0x54, plttBase と plttBlendB の中間色
  EntityC9BCElem* elems;  // 0x74, Malloc(count * sizeof(EntityC9BCElem))
} EntityC9BC;
static_assert(sizeof(EntityC9BC) == 120);

COMMON_DATA EntityC9BC* gEntityC9BC = NULL;  // 0x03002B38

void FUN_0800cf9c(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void FUN_0800d074(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void FUN_0800d134(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void FUN_0800d17c(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void FUN_0800d1cc(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void FUN_0800d364(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void FUN_0800d3f4(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);

// clang-format off
void (*const PTR_ARRAY_085aa774[7])(EntityC9BC*, EntityC9BCElem*, u32) = {
  FUN_0800cf9c,
  FUN_0800d074,
  FUN_0800d134,
  FUN_0800d17c,
  FUN_0800d1cc,
  FUN_0800d364,
  FUN_0800d3f4,
};  // 0x085aa774
// clang-format on

NAKED s32 HazardManager_SpawnScripted(void) { INCFUNC("asm/func/HazardManager_SpawnScripted.inc"); }

EntityC9BC* FUN_0800cb70(void) { return gEntityC9BC; }

NAKED void FUN_0800cb7c(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cb7c.inc"); }

INCASM("asm/entity_c9bc.inc");

NAKED s32 EntityC9BC_Update(EntityC9BC* p) { INCFUNC("asm/func/EntityC9BC_Update.inc"); }

NAKED s32 EntityC9BC_Destroy(EntityC9BC* p) { INCFUNC("asm/func/EntityC9BC_Destroy.inc"); }

NAKED s32 EntityC9BC_Init(EntityC9BC* p, u32 _) { INCFUNC("asm/func/EntityC9BC_Init.inc"); }

NAKED EntityC9BC* EntityC9BC_Create(u32 val) { INCFUNC("asm/func/EntityC9BC_Create.inc"); }
