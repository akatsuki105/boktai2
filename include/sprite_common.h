#ifndef __INCLUDE_SPRITE_COMMON_H__
#define __INCLUDE_SPRITE_COMMON_H__

#include "gba/gba.h"

// see "include/constants/sprite.h"
typedef u32 SpriteID32;
typedef u16 SpriteID16;

typedef u32 SpriteFlags;
#define SPRFLAG_HIDDEN (1 << 0)        // 0x00000001, 描画しない
#define SPRFLAG_AFFINE (1 << 1)        // 0x00000002, アフィン
#define SPRFLAG_XFLIP (1 << 2)         // 0x00000004, X軸反転
#define SPRFLAG_YFLIP (1 << 3)         // 0x00000008, Y軸反転
#define SPRFLAG_SCREEN_COORD (1 << 4)  // 0x00000010, スクリーン座標系
#define SPRFLAG_OAM_DIRECT (1 << 5)    // 0x00000020, OAM直書き
#define SPRFLAG_NO_CLIP (1 << 6)       // 0x00000040, クリップ省略
#define SPRFLAG_DRAWLIST (1 << 7)      // 0x00000080, セットされていると描画リスト(gAuxSpriteLists, gMainSpriteLists, gParticleLists) の idx が 1の方に追加される
#define SPRFLAG_BLINK_ODD (1 << 9)     // 0x00000200, 奇数フレームだけ描画しない (点滅), 根拠: FUN_0822aaac / MainSprite_DrawList
#define SPRFLAG_BLINK_EVEN (1 << 10)   // 0x00000400, 偶数フレームだけ描画しない (点滅), 根拠: 同上
#define SPRFLAG_UNK_11 (1 << 11)       // 0x00000800, 不明

// 0x00001000, ゲームオーバー画面に残すスプライト。
// ゲームオーバー中は Video_SetDrawPasses がこのビットだけを描くパス (Particle: FUN_0822e110 / AuxSprite: FUN_0822adac / MainSprite: FUN_082303c8) に差し替えるので、立っていないものは一斉に消える
#define SPRFLAG_GAMEOVER (1 << 12)

// 0x00002000, SPRFLAG_GAMEOVER と同じ用途(特定の場面での描画制御), まだどの場面かで使われるかは未解析
// Particle: FUN_0822e424, AuxSprite: FUN_0822af38, MainSprite: FUN_08230594
#define SPRFLAG_UNK_13 (1 << 13)

// 0..15
// (OAM1.14-15 << 2) | (OAM0.14-15), ie. ((sizeidx << 2) | shape)
typedef u8 SpriteShape;

extern u32 gSpriteListIdx;
extern const u16 gSpriteSizeTable[16];  // SpriteShape が idx

#endif  // __INCLUDE_SPRITE_COMMON_H__
