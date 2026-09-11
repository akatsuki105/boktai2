#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "gba/gba.h"
#include "sprite_actor.h"
#include "sprite_pltt.h"

// --------------------------------------------
// https://boktaihacking.net/wiki/Sprite_set_file

typedef struct {
  u16 palStart;            // 0x00, palette start index in the sprite palettes file
  u16 spriteCount;         // 0x02, number of sprites in this sprite set
  u16 unk1Count;           // 0x04, このファイルの spriteset_unk1 の数
  u16 subspriteCount;      // 0x06, このファイルの Subsprite の数
  u16 unk2Count;           // 0x08, このファイルの spriteset_unk2 の数
  u16 tileCount;           // 0x0A, このファイルのタイル枚数
  u32 offsetToSprites;     // 0x0C, この構造体の先頭から Metasprite[spriteCount] 配列までのバイトオフセット
  u32 offset_unk1;         // 0x10, この構造体の先頭から spriteset_unk1[unk1Count] 配列までのバイトオフセット
  u32 offsetToSubsprites;  // 0x14, この構造体の先頭から Subsprite[subspriteCount] 配列までのバイトオフセット
  u32 offset_unk2;         // 0x18, この構造体の先頭から spriteset_unk2[unk2Count] 配列までのバイトオフセット
  u32 offsetToTiles;       // 0x1C, この構造体の先頭から spriteset_tile[] 配列までのバイトオフセット
  // body:
  //   Metasprite sprites[spriteCount];
  //   spriteset_unk1 unk1[unk1Count];
  //   Subsprite subsprites[subspriteCount];
  //   spriteset_unk2 unk2[unk2Count];
  //   u8 tiles[tileCount * 32];
} spriteset_header;
static_assert(sizeof(spriteset_header) == 32);

// 所謂メタスプライト, a.k.a. spriteset_sprite
typedef struct {
  u16 unk_0;            // 0x00
  u16 subspriteCount;   // 0x02, このメタスプライトを構成する Subsprite の数
  u16 unk_4;            // 0x04
  u16 unk_6;            // 0x06
  u16 unk_8;            // 0x08
  u16 unk_a;            // 0x0A
  u16 unk_c;            // 0x0C
  u16 unk_e;            // 0x0E
  u32 subspriteOffset;  // 0x10, サブスプライト配列 Subsprite[] の先頭から、このメタスプライトの最初の サブスプライト までのバイトオフセット
} Metasprite;
static_assert(sizeof(Metasprite) == 20);

typedef struct {
  u8 unk_0[8];  // 0x0
} spriteset_unk1;
static_assert(sizeof(spriteset_unk1) == 8);

// これがGBAスプライトに対応, a.k.a. spriteset_obj
typedef struct {
  u8 flip;             // 0x00, bit2: xflip, bit3: yflip, TODO: other bits?
  u8 shape;            // 0x01, (OAM1.14-15 << 2) | (OAM0.14-15); (size << 2) | shape
  s16 x;               // 0x02
  s16 y;               // 0x04
  u16 tileNum : 12;    // 0x06.0-11, GBAのタイルIDは 10bitなので、 bit10-11　が本当にタイル番号かは要検証
  u16 paletteNum : 4;  // 0x06.12-15
} Subsprite;
static_assert(sizeof(Subsprite) == 8);

typedef struct {
  u8 unk_0[4];  // 0x0
} spriteset_unk2;
static_assert(sizeof(spriteset_unk2) == 4);

// spriteset_header のオフセット計算を行っただけ, ゲームではこれを扱う
typedef struct {
  u16 palStart;           // 0x00, Sprite_LoadSprite で SpriteState.plttID にセットされる, gObjPlttData[(SpriteSet.palStart + Subsprite.paletteNum) * 16] が実際のパレットデータ
  u16 spriteCount;        // 0x02, number of sprites in this sprite set
  u16 unk1Count;          // 0x04, このファイルの spriteset_unk1 の数
  u16 subspriteCount;     // 0x06, このファイルの Subsprite の数
  u16 unk2Count;          // 0x08, このファイルの spriteset_unk2 の数
  u16 tileCount;          // 0x0A, このファイルのタイル枚数
  Metasprite* sprites;    // 0x0C, Metasprite[spriteCount]
  spriteset_unk1* unk1;   // 0x10, spriteset_unk1[unk1Count]
  Subsprite* subsprites;  // 0x14, Subsprite[subspriteCount]
  spriteset_unk2* unk2;   // 0x18, spriteset_unk2[unk2Count]
  u8* tiles;              // 0x1C, tiles[tileCount * 32]
} SpriteSet;
static_assert(sizeof(SpriteSet) == 32);

s32 OpenSpriteSetFile(SpriteSet* data, spriteset_header* f);

// --------------------------------------------

// スプライト関連のデータ, Player などの様々なEntityでこの構造体が使われる
typedef struct SpriteState {
  u16 unk_0;                 // 0x00, Metasprite.unk_0
  u8 unk_2;                  // 0x02, FUN_080609dc
  u8 unk_3;                  // 0x03, FUN_080609dc
  u8 active;                 // 0x04, FUN_0822f1c0
  SpriteFlags flags;         // 0x08, see SpriteFlags, FUN_08060a24
  u16 unk_c;                 // 0x0C
  u16 unk_e;                 // 0x0E
  u16 unk_10;                // 0x10
  u16 unk_12;                // 0x12
  u16 unk_14;                // 0x14
  u16 unk_16;                // 0x16
  u16 unk_18;                // 0x18
  u8 priority;               // 0x1A
  u8 unk_1b;                 // 0x1B
  u8 listIdx;                // 0x1C, FUN_0822f1c0
  u8 unk_1d;                 // 0x1D
  u8 unk_1e[2];              // 0x1E
  Vec3 pos;                  // 0x20, ワールド座標. flags bit4 が立っていればスクリーン座標としてそのまま使われる, 根拠: FUN_08230134 のアイソメトリック投影と FUN_0822f364 の Vec3 コピー
  u16 offsetX;               // 0x28, 投影後のスクリーン座標に加算される, Metasprite.unk_4
  u16 offsetY;               // 0x2A, Metasprite.unk_6
  s16 q_boxRight;            // 0x2C, 画面外判定に使う矩形, Metasprite.unk_8
  s16 q_boxBottom;           // 0x2E, Metasprite.unk_a
  s16 q_boxLeft;             // 0x30, Metasprite.unk_c
  s16 q_boxTop;              // 0x32, Metasprite.unk_e
  u8 q_scaleX;               // 0x34, 6.6固定小数, Sprite_LoadSprite で 0x40 (= 1.0) がセットされる
  u8 q_scaleY;               // 0x35, 同上
  u16 q_rotation;            // 0x36, gSineTable の索引として使われる
  u16 subspriteCount;        // 0x38, Metasprite.subspriteCount
  u16 plttID;                // 0x3A, &gObjPlttData[plttID*16]
  u32 q_oamAttr;             // 0x3C, OAM attr0 | attr1<<16 のベース値, q_SpriteNode44.q_oamAttr と同じ役割
  s32 q_unk_40;              // 0x40, FUN_0822f3fc で -1 が入る
  s32 q_unk_44;              // 0x44, 同上
  rgb555* pltt;              // 0x48, &gObjPlttData[plttID*16]
  Subsprite* subsprites;     // 0x4C, SpriteSet.subsprites[Metasprite.subspriteOffset/sizeof(Subsprite)]
  u8* tiles;                 // 0x50, SpriteSet.tiles
  u32 q_unk_54;              // 0x54, FUN_0822f3fc で 0 が入る
  struct SpriteState* prev;  // 0x58, 根拠: FUN_0822a3f0 / FUN_0822a41c
  struct SpriteState* next;  // 0x5C, 根拠: FUN_0822f1d8
} SpriteState;
static_assert(sizeof(SpriteState) == 96);  // 確定したわけではないが、 0x0808b2a0 や プロパティの使い方から見て、96バイトで合っていると思う

s32 Sprite_LoadSprite(SpriteState* p, SpriteSet* src, u16 spriteIdx);
s32 Sprite_SetSprite(SpriteState* p, SpriteSet* src, u16 param_3, u8 unk_1b);
bool32 FUN_082372cc(SpriteState* p, SpriteSet* src);
void FUN_0822f1c0(SpriteState* p);

#endif  // __INCLUDE_SPRITE_H__
