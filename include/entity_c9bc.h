#ifndef GUARD_ZOKTAI_ENTITY_C9BC_H
#define GUARD_ZOKTAI_ENTITY_C9BC_H

#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite.h"

// EntityC9BC が count 個まとめて管理する要素
typedef struct {
  bool8 active;  // 0x00, 0 以外なら使用中, FUN_0800cb7c で 0 に戻る
  u8 unk_01;
  u8 unk_02;  // 0x02, 根拠: EntityC9BCElem_SaveState が unk_46 に退避する
  u8 state;   // 0x03, sC9BCElemUpdates の添字
  u8 unk_04[0x2A - 0x04];
  u16 unk_2a;  // 0x2A, 根拠: EntityC9BCElem_SaveState が 0 に戻し、各 UpdateState 関数がビットを立てる
  u8 unk_2c[0x44 - 0x2C];
  bool8 releaseReq;  // 0x44, 0 以外なら EntityC9BC_Update が FUN_0800cb7c で解放する
  u8 unk_45;         // 0x45, 根拠: EntityC9BCElem_SaveState が state を退避する
  u8 unk_46;         // 0x46, 根拠: EntityC9BCElem_SaveState が unk_02 を退避する
  u8 unk_47;
  Mover obj;         // 0x48, 根拠: FUN_0800cb7c, obj.id は EntityC9BC_FindElemById の検索キー
  AuxSpriteGfx gfx;  // 0x8C, 根拠: FUN_0800ccd0 が Video_SetAuxSpritePltt に渡す
  AuxSprite spr_a8;  // 0xA8, 根拠: FUN_0800cb7c
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

EntityC9BC* GetEntityC9BC(void);

#endif  // GUARD_ZOKTAI_ENTITY_C9BC_H
