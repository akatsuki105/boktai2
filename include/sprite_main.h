#ifndef __INCLUDE_SPRITE_MAIN_H__
#define __INCLUDE_SPRITE_MAIN_H__

#include "gba/gba.h"
#include "sprite_common.h"
#include "types.h"

typedef u16 MainAnimPlayFlags16;
#define MAIN_ANIM_KEEP_FRAME (1 << 0)  // 0x0001, 頭出しせずに今のコマ番号から続ける, 根拠: MainSprite_SetAnim が animCmdIdx と animCmdTimer を初期化しない
#define MAIN_ANIM_REVERSE (1 << 1)     // 0x0002, 逆再生, 根拠: MainSprite_SetAnim が末尾のコマから始め、MainSprite_AdvanceAnim が animCmdIdx を減らして 0 で終端とみなす
#define MAIN_ANIM_FORCE_POSE (1 << 2)  // 0x0004, 同じアニメを指定してもポーズを当て直す, 根拠: MainSprite_SetAnim

// MainSprite.animEvents。MainSprite_AdvanceAnim が毎フレーム先頭でクリアしてから立て直す
typedef u8 MainAnimEvents8;
#define MAIN_ANIM_EVENT_WILL_END (1 << 0)  // 0x01, 次のコマで終わる
#define MAIN_ANIM_EVENT_ENDED (1 << 1)     // 0x02, 今終わった
#define MAIN_ANIM_EVENT_ADVANCED (1 << 2)  // 0x04, コマが進んだ

typedef struct {
  u16 palStart;            // 0x00, palette start index in the sprite palettes file
  u16 spriteCount;         // 0x02, number of sprites in this sprite set
  u16 unk1Count;           // 0x04, このファイルの MainAnim の数
  u16 subspriteCount;      // 0x06, このファイルの MainSubsprite の数
  u16 unk2Count;           // 0x08, このファイルの MainAnimCmd の数
  u16 tileCount;           // 0x0A, このファイルのタイル枚数
  u32 offsetToSprites;     // 0x0C, この構造体の先頭から MainSpritePose[spriteCount] 配列までのバイトオフセット
  u32 offset_unk1;         // 0x10, この構造体の先頭から MainAnim[unk1Count] 配列までのバイトオフセット
  u32 offsetToSubsprites;  // 0x14, この構造体の先頭から MainSubsprite[subspriteCount] 配列までのバイトオフセット
  u32 offset_unk2;         // 0x18, この構造体の先頭から MainAnimCmd[unk2Count] 配列までのバイトオフセット
  u32 offsetToTiles;       // 0x1C, この構造体の先頭から spriteset_tile[] 配列までのバイトオフセット
  // body:
  //   MainSpritePose sprites[spriteCount];
  //   MainAnim unk1[unk1Count];
  //   MainSubsprite subsprites[subspriteCount];
  //   MainAnimCmd unk2[unk2Count];
  //   u8 tiles[tileCount * 32];
} MainSpriteFile;
static_assert(sizeof(MainSpriteFile) == 32);

// 所謂メタスプライト, a.k.a. spriteset_sprite
typedef struct {
  u16 unk_0;            // 0x00
  u16 subspriteCount;   // 0x02, このメタスプライトを構成する MainSubsprite の数
  u16 offsetX;          // 0x04
  u16 offsetY;          // 0x06
  u16 boxRight;         // 0x08
  u16 boxBottom;        // 0x0A
  u16 boxLeft;          // 0x0C
  u16 boxTop;           // 0x0E
  u32 subspriteOffset;  // 0x10, サブスプライト配列 MainSubsprite[] の先頭から、このメタスプライトの最初の サブスプライト までのバイトオフセット
} MainSpritePose;
static_assert(sizeof(MainSpritePose) == 20);

typedef struct {
  u16 unk_0;      // 0x00
  u16 cmdCount;   // 0x02, MainAnimCmd の数
  u32 cmdOffset;  // 0x04, unk2 の先頭からこのアニメの最初のコマ (MainAnimCmd) までのバイトオフセット, 根拠: MainSprite_SetAnimFrame
} MainAnim;
static_assert(sizeof(MainAnim) == 8);

// これがGBAスプライトに対応, a.k.a. spriteset_obj
typedef struct {
  u8 flip;             // 0x00, bit2: xflip, bit3: yflip, TODO: other bits?
  u8 shape;            // 0x01, (OAM1.14-15 << 2) | (OAM0.14-15); (size << 2) | shape
  s16 x;               // 0x02
  s16 y;               // 0x04
  u16 tileNum : 12;    // 0x06.0-11, GBAのタイルIDは 10bitなので、 bit10-11　が本当にタイル番号かは要検証
  u16 paletteNum : 4;  // 0x06.12-15
} MainSubsprite;
static_assert(sizeof(MainSubsprite) == 8);

// アニメーションの1コマ, 根拠: MainSprite_AdvanceAnim が MainSprite.animCmds を idx*4 で進めて +0 と +2 を ldrh している
typedef struct {
  u16 spriteIdx;  // 0x00, MainSprite_SetPose に渡すスプライト番号
  u16 duration;   // 0x02, このコマの表示フレーム数, MainSprite.animSpeed を掛けて 6.6 固定小数として扱う
} MainAnimCmd;
static_assert(sizeof(MainAnimCmd) == 4);

// MainSpriteGfx: MainSpriteFile のオフセットをポインタに直したもの。1キャラ分の絵 (タイル・パレット・ポーズ配列) の所在を持つ
// MainSprite が読み込み時にここからグラフィックを取り出す
typedef struct {
  u16 palStart;               // 0x00, MainSprite_LoadPose で MainSprite.plttID にセットされる, gObjPlttData[(MainSpriteGfx.palStart + MainSubsprite.paletteNum) * 16] が実際のパレットデータ
  u16 spriteCount;            // 0x02, number of sprites in this sprite set
  u16 unk1Count;              // 0x04, このファイルの MainAnim の数
  u16 subspriteCount;         // 0x06, このファイルの MainSubsprite の数
  u16 unk2Count;              // 0x08, このファイルの MainAnimCmd の数
  u16 tileCount;              // 0x0A, このファイルのタイル枚数
  MainSpritePose* sprites;    // 0x0C, MainSpritePose[spriteCount]
  MainAnim* unk1;             // 0x10, MainAnim[unk1Count]
  MainSubsprite* subsprites;  // 0x14, MainSubsprite[subspriteCount]
  MainAnimCmd* unk2;          // 0x18, MainAnimCmd[unk2Count]
  u8* tiles;                  // 0x1C, tiles[tileCount * 32]
} MainSpriteGfx;
static_assert(sizeof(MainSpriteGfx) == 32);

// --------------------------------------------

// MainSprite: Player やボスなどが使うスプライト。 MainSpriteGfx から絵の場所をコピーし、アニメの再生位置と座標もあわせて1つに持つオールインワンなスプライト
// 主人公やメインのNPC、ボスなどのたくさんグラフィックのある主要キャラクターを扱う時はこれを使っている
typedef struct MainSprite {
  u16 unk_0;                      // 0x00, MainSpritePose.unk_0
  u8 unk_2;                       // 0x02, FUN_080609dc
  u8 unk_3;                       // 0x03, FUN_080609dc
  bool8 active;                   // 0x04, MainSprite_Remove
  SpriteFlags flags;              // 0x08, see SpriteFlags, FUN_08060a24
  u16 animCmdTimer;               // 0x0C, 現在のコマの経過フレーム数, 根拠: MainSprite_AdvanceAnim が毎フレーム +1 してコマ切り替えで 0 に戻す
  u16 animCmdDuration;            // 0x0E, 現在のコマの表示フレーム数, MainAnimCmd.duration * animSpeed / 64 (0 なら 1)
  u16 animSpeed;                  // 0x10, 再生速度, 6.6固定小数 (MainSprite_Load が 0x40 = 等速をセット)
  u16 unk_12;                     // 0x12
  u16 animCmdIdx;                 // 0x14, 現在のコマ番号, animCmds の添字
  u16 animCmdLength;              // 0x16, コマ総数, 根拠: MainSprite_AdvanceAnim の animCmdIdx の上限
  MainAnimPlayFlags16 animFlags;  // 0x18, see MainAnimPlayFlags16
  u8 priority;                    // 0x1A
  u8 playMode;                    // 0x1B, 0=停止, 2=1回再生して停止, 3=1回再生して非表示, その他=ループ, 根拠: MainSprite_AdvanceAnim
  u8 listIdx;                     // 0x1C, MainSprite_Remove
  MainAnimEvents8 animEvents;     // 0x1D, see MainAnimEvents8
  u8 unk_1e[2];                   // 0x1E
  Vec3 pos;                       // 0x20, ワールド座標. flags bit4 が立っていればスクリーン座標としてそのまま使われる, 根拠: FUN_08230134 のアイソメトリック投影と MainSprite_Load の Vec3 コピー
  u16 offsetX;                    // 0x28, 投影後のスクリーン座標に加算される, MainSpritePose.unk_4
  u16 offsetY;                    // 0x2A, MainSpritePose.unk_6
  s16 boxRight;                   // 0x2C, 画面外判定に使う矩形, MainSpritePose.unk_8
  s16 boxBottom;                  // 0x2E, MainSpritePose.unk_a
  s16 boxLeft;                    // 0x30, MainSpritePose.unk_c
  s16 boxTop;                     // 0x32, MainSpritePose.unk_e
  u8 scaleX;                      // 0x34, 6.6固定小数, MainSprite_LoadPose で 0x40 (= 1.0) がセットされる
  u8 scaleY;                      // 0x35, 同上
  u16 rotation;                   // 0x36, gSineTable の索引として使われる
  u16 subspriteCount;             // 0x38, MainSpritePose.subspriteCount
  u16 plttID;                     // 0x3A, &gObjPlttData[plttID*16]
  u32 oamAttr;                    // 0x3C, OAM attr0 | attr1<<16 のベース値, AuxSprite.oamAttr と同じ役割
  s32 q_unk_40;                   // 0x40, MainSprite_Add で -1 が入る
  s32 q_unk_44;                   // 0x44, 同上
  rgb555* pltt;                   // 0x48, &gObjPlttData[plttID*16]
  MainSubsprite* subsprites;      // 0x4C, MainSpriteGfx.subsprites[MainSpritePose.subspriteOffset/sizeof(MainSubsprite)]
  u8* tiles;                      // 0x50, MainSpriteGfx.tiles
  MainAnimCmd* animCmds;          // 0x54, アニメーションのコマ配列, MainSprite_Add で 0 が入る
  struct MainSprite* prev;        // 0x58
  struct MainSprite* next;        // 0x5C
} MainSprite;
static_assert(sizeof(MainSprite) == 96);

// --------------------------------------------

extern MainSprite* gMainSpriteLists[2];

s32 OpenMainSpriteFile(MainSpriteGfx* data, MainSpriteFile* f);
s32 MainSprite_LoadPose(MainSprite* p, MainSpriteGfx* src, u16 spriteIdx);
s32 MainSprite_SetPose(MainSprite* p, MainSpriteGfx* src, u16 param_3, u8 playMode);
s32 MainSprite_Add(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 playMode, u8 animCmdDuration, Vec3* pos);
bool32 MainSprite_AdvanceAnim(MainSprite* p, MainSpriteGfx* src);
void MainSprite_Remove(MainSprite* p);
void MainSprite_SetAnim(MainSprite* p, MainSpriteGfx* gfx, u16 animIdx, u16 playMode, MainAnimPlayFlags16 flags);

#endif  // __INCLUDE_SPRITE_MAIN_H__
