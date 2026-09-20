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
#define SPRFLAG_UNK_7 (1 << 7)         // 0x00000080, ???
#define SPRFLAG_BLINK_ODD (1 << 9)     // 0x00000200, 奇数フレームだけ描画しない (点滅), 根拠: FUN_0822aaac / FUN_08230134
#define SPRFLAG_BLINK_EVEN (1 << 10)   // 0x00000400, 偶数フレームだけ描画しない (点滅), 根拠: 同上

// 0..15
// (OAM1.14-15 << 2) | (OAM0.14-15), ie. ((sizeidx << 2) | shape)
typedef u8 SpriteShape;

#endif  // __INCLUDE_SPRITE_COMMON_H__
