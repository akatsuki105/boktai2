#ifndef __INCLUDE_SPRITE_ACTOR_H__
#define __INCLUDE_SPRITE_ACTOR_H__

#include "animation.h"
#include "gba/gba.h"
#include "sprite_common.h"
#include "types.h"

typedef u8 AuxSpriteGfxFlags;  // AuxSpriteGfx.flags, ParticleGroupFlags と同じもの?
#define ASGFLAG_BPP8 (1 << 4)  // 0x10, 8bpp

typedef struct {
  u16 id;                   // 0x00, ID of this actor, used for loading it
  AuxSpriteGfxFlags flags;  // 0x02, このゲームでは全て０
  u8 unk_03;                // 0x03, このゲームでは全て０
  u8 pw;                    // 0x04, pixel width
  u8 ph;                    // 0x05, pixel height
  s8 px;                    // 0x06, offset pixel x
  s8 py;                    // 0x07, offset pixel y
  u32 spritesOffset;        // 0x08, metasprites[] の先頭からアクターの最初のスプライトまでのバイトオフセット, つまり metasprites[spritesOffset>>3]
} AuxSpriteEntry;
static_assert(sizeof(AuxSpriteEntry) == 12);

// メタスプライト
typedef struct {
  u8 subspriteCount;    // 0x00, このメタスプライトを構成する AuxSubsprite の数
  u8 unk_01;            // 0x01
  u16 plttID;           // 0x02, ObjPlttFile.body[plttID*16]
  u32 tileOffset;       // 0x04, tiles[]の先頭からこのスプライトの最初のタイルまでのバイトオフセット, つまり tiles[tileOffset >> 5]
  u32 subspriteOffset;  // 0x08, subsprites[]の先頭から、このスプライトの最初のsubspritesまでのバイトオフセット, つまり subsprites[subspriteOffset>>2] から subsprites[(subspriteOffset>>2) + subspriteCount] がこのメタスプライトのサブスプライト
} AuxSpritePose;
static_assert(sizeof(AuxSpritePose) == 12);

// これがGBAスプライトに対応
typedef struct {
  SpriteShape shape;  // 0x00, see SpriteShape
  u8 unk_01;          // 0x01, このゲームでは全て０
  s8 x;               // 0x02
  s8 y;               // 0x03
} AuxSubsprite;
static_assert(sizeof(AuxSubsprite) == 4);

typedef struct {
  u32 unk_00;                       // 0x000000, 0x0
  s32 actorCount;                   // 0x000004, entries[253], Video_GetAuxSprite が符号付きで比較する
  u32 unk_08;                       // 0x000008, 0x0
  u32 offsetToTiles;                // 0x00000C
  u32 offsetToMetasprites;          // 0x000010
  u32 offsetToSubsprites;           // 0x000014
  AuxSpriteEntry entries[253];      // 0x000018, メタスプライトをまとめたもの
  u8 tiles[42418 * 32];             // 0x000BF4, GBA tiles
  AuxSpritePose metasprites[2164];  // 0x14C234, メタスプライト
  AuxSubsprite subsprites[4641];    // 0x1527A4, GBAスプライト
} AuxSpriteFile;
static_assert(sizeof(AuxSpriteFile) == 1404968);

// --------------------------------------------
// ゲーム側がRAM内で扱うもの

// AuxSpriteGfx: AuxSprite の描画に必要な情報 (タイル・パレット・ポーズ配列) を保持する構造体
// Particle でいう ParticleGroup
typedef struct {
  AuxSpriteGfxFlags flags;     // 0x00, 初期値には AuxSpriteEntry.flags が入る (ただしこのゲームでは全て０)
  SpriteShape shape;           // 0x01, see SpriteShape
  u16 unk_2;                   // 0x02
  u16 subspriteCount;          // 0x04
  u16 plttID;                  // 0x06, &gObjPlttData[plttID*16]
  u8 pw;                       // 0x08, pixel width
  u8 ph;                       // 0x09, pixel height
  s8 px;                       // 0x0A, offset pixel x
  s8 py;                       // 0x0B, offset pixel y
  rgb555* pltt;                // 0x0C, &gObjPlttData[plttID*16]
  u8* tiles;                   // 0x10
  AuxSpritePose* metasprites;  // 0x14
  u32 q_unk_18;                // 0x18
} AuxSpriteGfx;
static_assert(sizeof(AuxSpriteGfx) == 28);

// MainSprite は MainSpriteGfx の内容を自分の中にコピーして持ち、 アニメーション状態も自分の中に保持するオールインワンなスプライトだが、
// AuxSprite は AuxSpriteGfx の参照を持つだけで、さらにアニメーション情報も持たない (アニメーションさせたいときは外部から AuxAnimState で行われる)
// グラフィックデータの小さい小道具的なスプライトは AuxSprite を使う
typedef struct AuxSprite {
  SpriteFlags flags;       // 0x00, see SpriteFlags
  bool8 active;            // 0x04, リストに繋がれていれば 1, Video_AddAuxSpriteIntoDrawList / Video_RemoveAuxSpriteFromDrawList
  u8 unk_05;               // 0x05, AuxSprite_Add で 1 がセットされる
  u8 rotation;             // 0x06, gSineTable[-rotation & 0xFF] の索引として使われる
  u8 priority;             // 0x07, OAM attr2 bit10-11
  s2_6 scaleX;             // 0x08
  s2_6 scaleY;             // 0x09
  u8 listIdx;              // 0x0A, gAuxSpriteLists の添字
  u8 unk_0b;               // 0x0B
  AuxSpriteGfx* gfx;       // 0x0C, FUN_0822a4fc がセットする
  s16 metaspriteIdx;       // 0x10, gfx->metasprites の添字
  u8 unk_12;               // 0x12
  u8 plttOffset;           // 0x13, gfx->plttID に加算される
  u8 spriteWidth;          // 0x14, gOAMWidthTable[AuxSpriteGfx.unk_1]
  u8 spriteHeight;         // 0x15, gOAMHeightTable[AuxSpriteGfx.unk_1]
  s8 offsetX;              // 0x16, フリップ時に符号反転して座標に加算される
  s8 offsetY;              // 0x17, 同上
  u32 oamAttr;             // 0x18, OAM attr0 | attr1<<16 のベース値. MainSprite.oamAttr(0x3C) と同じ役割
  Vec3 pos;                // 0x1C, MainSprite.pos と同じアイソメトリック投影にかけられる
  struct AuxSprite* prev;  // 0x24
  struct AuxSprite* next;  // 0x28
} AuxSprite;
static_assert(sizeof(AuxSprite) == 44);

// --------------------------------------------

extern AuxSprite* gAuxSpriteLists[2];
s32 Video_AddAuxSpriteIntoDrawList(AuxSprite* p, s32 idx);
void Video_RemoveAuxSpriteFromDrawList(AuxSprite* p, s32 idx);

extern AuxSpriteFile* gAuxSpriteFile;  // 0x030035A0
extern u8* gAuxSpriteTiles;
extern AuxSubsprite* gAuxSubsprites;
extern u16 gAuxSpriteTileCount;

void AuxSprite_Add(AuxSprite* p, AuxSpriteGfx* gfx, SpriteFlags flags);
void AuxSprite_Setup(AuxSprite* p, AuxSpriteGfx* gfx, SpriteFlags flags);
void AuxSprite_Remove(AuxSprite* p);
bool32 Video_GetAuxSprite(AuxSpriteGfx* gfx, SpriteID32 id);
void Video_SetAuxSpritePltt(AuxSpriteGfx* gfx, s32 plttID);
void FUN_0822a4fc(AuxSprite* p, AuxSpriteGfx* gfx);

static inline void AuxSprite_Show(AuxSprite* spr) { spr->flags &= ~SPRFLAG_HIDDEN; }
static inline void AuxSprite_Hide(AuxSprite* spr) { spr->flags |= SPRFLAG_HIDDEN; }
static inline void AuxSprite_SetPoseIdx(AuxSprite* spr, s32 val) { spr->metaspriteIdx = val; }

#endif  // __INCLUDE_SPRITE_ACTOR_H__
