#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "gba/gba.h"

// --------------------------------------------
// https://boktaihacking.net/wiki/Actor_sprites_file

#define ACTOR_SPRITE_COUNT 253
#define ACTOR_SPRITES_TILECOUNT 42418
#define ACTOR_SPRITE_SPRITE_COUNT 2164

typedef struct {
  u16 id;             // 0x00, ID of this actor, used for loading it
  u16 unk_02;         // 0x02, このゲームでは全て０
  u8 pw;              // 0x04, pixel width
  u8 ph;              // 0x05, pixel height
  s8 px;              // 0x06, offset pixel x
  s8 py;              // 0x07, offset pixel y
  u32 spritesOffset;  // 0x08, metasprites[] の先頭からアクターの最初のスプライトまでのバイトオフセット, つまり metasprites[spritesOffset>>3]
} ActorSpritesActor;
static_assert(sizeof(ActorSpritesActor) == 12);

// メタスプライト
typedef struct {
  u8 subspriteCount;    // 0x00, このメタスプライトを構成する ActorSubsprite の数
  u8 unk_01;            // 0x01
  u16 plttID;           // 0x02, ObjPlttFile.body[plttID*16]
  u32 tileOffset;       // 0x04, tiles[]の先頭からこのスプライトの最初のタイルまでのバイトオフセット, つまり tiles[tileOffset >> 5]
  u32 subspriteOffset;  // 0x08, subsprites[]の先頭から、このスプライトの最初のsubspritesまでのバイトオフセット, つまり subsprites[subspriteOffset>>2] から subsprites[(subspriteOffset>>2) + subspriteCount] がこのメタスプライトのサブスプライト
} ActorMetasprite;
static_assert(sizeof(ActorMetasprite) == 12);

// これがGBAスプライトに対応
typedef struct {
  u8 shape;   // 0x00, (OAM1.14-15 << 2) | (OAM0.14-15); (size << 2) | shape
  u8 unk_01;  // 0x01, このゲームでは全て０
  s8 x;       // 0x02
  s8 y;       // 0x03
} ActorSubsprite;
static_assert(sizeof(ActorSubsprite) == 4);

typedef struct {
  u32 unk_00;                                              // 0x000000, 0x0
  u32 actorCount;                                          // 0x000004, actors[ACTOR_SPRITE_COUNT]
  u32 unk_08;                                              // 0x000008, 0x0
  u32 offsetToTiles;                                       // 0x00000C
  u32 offsetToMetasprites;                                 // 0x000010
  u32 offsetToSubsprites;                                  // 0x000014
  ActorSpritesActor actors[ACTOR_SPRITE_COUNT];            // 0x000018, メタスプライトをまとめたもの
  u8 tiles[ACTOR_SPRITES_TILECOUNT * 32];                  // 0x000BF4, GBA tiles
  ActorMetasprite metasprites[ACTOR_SPRITE_SPRITE_COUNT];  // 0x14C234, メタスプライト
  ActorSubsprite subsprites[4641];                         // 0x1527A4, GBAスプライト
} ActorSpritesFile;
static_assert(sizeof(ActorSpritesFile) == 1404968);

extern const ActorSpritesFile gActorSpritesFile0;  // 0x08A2291C

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

bool32 OpenSpriteSetFile(SpriteSet* data, spriteset_header* f);

// --------------------------------------------
// https://boktaihacking.net/wiki/Sprite_set_file#Palettes

#define OBJ_PLTT_LENGTH 768

typedef struct {
  u16 length;                      // 0x00, OBJ_PLTT_LENGTH
  u16 unk_02;                      // 0x02, ???
  u16 body[OBJ_PLTT_LENGTH * 16];  // 0x04, RGB555 array
} ObjPlttFile;
static_assert(sizeof(ObjPlttFile) == 24580);

extern const ObjPlttFile gObjPlttFile0;  // 0x08CB9244

// --------------------------------------------

// スプライト関連のデータ, Player などの様々なEntityでこの構造体が使われる
typedef struct SpriteState {
  u16 unk_0;   // 0x00, Metasprite.unk_0
  u16 unk_2;   // 0x02
  u8 unk_4;    // 0x04, FUN_0822f1c0
  u32 unk_8;   // 0x08, FUN_08060a24 で bitfield として使われている
  u16 unk_c;   // 0x0C
  u16 unk_e;   // 0x0E
  u16 unk_10;  // 0x10
  u16 unk_12;  // 0x12
  u16 unk_14;  // 0x14
  u16 unk_16;  // 0x16
  u16 unk_18;  // 0x18
  u8 unk_1a;   // 0x1A
  u8 unk_1b;   // 0x1B
  u8 unk_1c;   // 0x1C
  u8 unk_1d;   // 0x1D
  u8 unk_1e[2];
  u16 offsetX;  // 0x20, SpriteSet で定義された初期位置 からの X方向のオフセット
  u16 offsetY;  // 0x22, SpriteSet で定義された初期位置 からの Y方向のオフセット
  u8 unk_24[4];
  u16 unk_28;  // 0x28
  u16 unk_2a;  // 0x2a
  u16 unk_2c;  // 0x2c
  u16 unk_2e;  // 0x2e
  u16 unk_30;  // 0x30
  u16 unk_32;  // 0x32

  // ここから Video_GetActorSprite の dst?
  u8 unk_34;           // 0x34
  u8 unk_35;           // 0x35
  u16 unk_36;          // 0x36
  u16 subspriteCount;  // 0x38, Metasprite.subspriteCount
  u16 plttID;          // 0x3A, &gObjPlttData[plttID*16]
  u8 unk_3c[12];
  rgb555* pltt;           // 0x48, &gObjPlttData[plttID*16]
  Subsprite* subsprites;  // 0x4C, SpriteSet.subsprites[Metasprite.subspriteOffset/sizeof(Subsprite)]
  u8* tiles;              // 0x50, SpriteSet.tiles
  u8 unk_54[12];
} SpriteState;
static_assert(sizeof(SpriteState) == 96);  // 確定したわけではないが、 0x0808b2a0 や プロパティの使い方から見て、96バイトで合っていると思う

// FUN_082372cc の呼び出し(例: 0x081a64f4) で SpriteState にオフセットでアクセスしているので同じ構造体にありそう, また EnemyのInit関数で Malloc(128) しているのも根拠 (例: 0x08101da6)
typedef struct {
  SpriteSet tmpl;  // 0x00, スプライトのROMデータを指す構造体
  SpriteState s;   // 0x20
} SpriteData;      // 他に特にSprite系の重要な構造体が出てこなかったら、この構造体の名前は Sprite にする予定
static_assert(sizeof(SpriteData) == 128);

s32 Sprite_LoadSprite(SpriteState* p, SpriteSet* src, u16 spriteIdx);
s32 Sprite_SetSprite(SpriteState* p, SpriteSet* src, u16 param_3, u8 unk_1b);
bool32 FUN_082372cc(SpriteState* p, SpriteSet* src);

#endif  // __INCLUDE_SPRITE_H__
