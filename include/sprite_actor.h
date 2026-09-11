#ifndef __INCLUDE_SPRITE_ACTOR_H__
#define __INCLUDE_SPRITE_ACTOR_H__

#include "gba/gba.h"
#include "types.h"  // Vec3

// GBAスプライト として使う場合は、 spriteset か actorsprite のどちらかを使う
// メインキャラクターなどのたくさんのグラフィックデータが必要な場合は、 spriteset で、 それ以外の少量のグラフィックデータの場合は、 actorsprite を使う という使い分けをしていたと思われる

typedef u32 ActorSpriteID32;  // spriteset と ID を共有しているっぽい?, see "include/constants/sprite.h"
typedef u16 ActorSpriteID16;

typedef u32 SpriteFlags;
#define SPRFLAG_UNK_0 (1 << 0)         // 0x00000001
#define SPRFLAG_AFFINE (1 << 1)        // 0x00000002, アフィン
#define SPRFLAG_XFLIP (1 << 2)         // 0x00000004, X軸反転
#define SPRFLAG_YFLIP (1 << 3)         // 0x00000008, Y軸反転
#define SPRFLAG_SCREEN_COORD (1 << 4)  // 0x00000010, スクリーン座標系
#define SPRFLAG_OAM_DIRECT (1 << 5)    // 0x00000020, OAM直書き
#define SPRFLAG_NO_CLIP (1 << 6)       // 0x00000040, クリップ省略
#define SPRFLAG_UNK_7 (1 << 7)         // 0x00000080, ???

// --------------------------------------------

// https://boktaihacking.net/wiki/Actor_sprites_file

#define ACTOR_SPRITE_COUNT 253
#define ACTOR_SPRITES_TILECOUNT 42418
#define ACTOR_SPRITE_SPRITE_COUNT 2164

typedef struct {
  u16 id;             // 0x00, ID of this actor, used for loading it
  u8 unk_02;          // 0x02, このゲームでは全て０, Video_GetActorSprite が ldrb で読むので u8
  u8 unk_03;          // 0x03, このゲームでは全て０
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
  s32 actorCount;                                          // 0x000004, actors[ACTOR_SPRITE_COUNT], Video_GetActorSprite が符号付きで比較する
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
// ゲーム側がRAM内で扱うもの

typedef struct {
  u8 unk_0;                      // 0x00, ActorSpritesActor.unk_02 が入る
  u8 unk_1;                      // 0x01
  u16 unk_2;                     // 0x02
  u16 subspriteCount;            // 0x04
  u16 plttID;                    // 0x06, &gObjPlttData[plttID*16]
  u8 pw;                         // 0x08, pixel width
  u8 ph;                         // 0x09, pixel height
  s8 px;                         // 0x0A, offset pixel x
  s8 py;                         // 0x0B, offset pixel y
  rgb555* pltt;                  // 0x0C, &gObjPlttData[plttID*16]
  u8* tiles;                     // 0x10
  ActorMetasprite* metasprites;  // 0x14
  u32 q_unk_18;                  // 0x18
} ActorSpriteState;
static_assert(sizeof(ActorSpriteState) == 28);

bool32 Video_GetActorSprite(ActorSpriteState* p, ActorSpriteID32 id);
void Video_SetActorSpritePltt(ActorSpriteState* p, s32 plttID);

// --------------------------------------------

// アクタースプライトの描画リストのノード
// ActorSpriteState が「何を描くか」(タイル・パレット・メタスプライト)を持つのに対し、こちらは「どこにどう描くか」(位置・回転・拡縮・優先度)を持つ
// 1つの ActorSpriteState を複数のノードが共有できる (FUN_08202a14 ではノード8個が ActorSpriteState 2個を共有している)
// PTR_ARRAY_03003560[q_listIdx] を先頭とする双方向リストに繋がれ、FUN_0822aaac などが走査して DrawSprite_0822a574 で OAM に書き出す
// 同じ描画システムの SpriteState は資源を自分自身に持つので、こちらとは資源の持ち方が異なる
typedef struct q_SpriteNode44 {
  SpriteFlags flags;            // 0x00, see SpriteFlags
  u8 q_active;                  // 0x04, リストに繋がれていれば 1, FUN_0822a340 / FUN_0822a36c
  u8 unk_05;                    // 0x05, FUN_0822a470 で 1 がセットされる
  u8 q_rotation;                // 0x06, gSineTable[-q_rotation & 0xFF] の索引として使われる
  u8 priority;                  // 0x07, OAM attr2 bit10-11
  s8 q_scaleX;                  // 0x08, 6.6固定小数, 0x40 = 1.0
  s8 q_scaleY;                  // 0x09, 同上
  u8 q_listIdx;                 // 0x0A, PTR_ARRAY_03003560 の添字
  u8 unk_0b;                    // 0x0B
  ActorSpriteState* q_sprite;   // 0x0C, FUN_0822a4fc がセットする
  s16 q_metaspriteIdx;          // 0x10, q_sprite->metasprites の添字
  u8 unk_12;                    // 0x12
  u8 q_plttOffset;              // 0x13, q_sprite->plttID に加算される
  u8 q_spriteWidth;             // 0x14, gOAMWidthTable[ActorSpriteState.unk_1]
  u8 q_spriteHeight;            // 0x15, gOAMHeightTable[ActorSpriteState.unk_1]
  s8 q_offsetX;                 // 0x16, フリップ時に符号反転して座標に加算される
  s8 q_offsetY;                 // 0x17, 同上
  u32 q_oamAttr;                // 0x18, OAM attr0 | attr1<<16 のベース値. SpriteState.q_oamAttr(0x3C) と同じ役割
  Vec3 q_pos;                   // 0x1C, SpriteState.pos と同じアイソメトリック投影にかけられる
  struct q_SpriteNode44* prev;  // 0x24
  struct q_SpriteNode44* next;  // 0x28
} q_SpriteNode44;
static_assert(sizeof(q_SpriteNode44) == 44);  // FUN_08202a14 のループで 44バイトずつアドレスが増える (puVar8 は u16* で += 0x16)

// --------------------------------------------

#endif  // __INCLUDE_SPRITE_ACTOR_H__
