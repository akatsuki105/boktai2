#ifndef __INCLUDE_ANIMATION_H__
#define __INCLUDE_ANIMATION_H__

#include "gba/gba.h"

typedef u8 AuxAnimPlayFlags;
#define ANIM_PLAY_XFLIP (1 << 0)    // bit0: XFLIP
#define ANIM_PLAY_YFLIP (1 << 1)    // bit1: YFLIP
#define ANIM_PLAY_REVERSE (1 << 2)  // bit2: 逆再生

typedef struct {
  u8 variantCount;  // 0x00
  u8 cmdCount;      // 0x01
  u16 cmdOffset;    // 0x02, この AuxAnim を持つ 　AuxAnimFile の先頭から、 最初のコマンドへのバイトオフセット
} AuxAnim;

// bit0-3: duration
// bit4: xflip
// bit5: yflip
// bit6-15: sprite index
typedef u16 AuxAnimCmd;

// AuxSprite's animation
typedef struct {
  u16 animationCount;  // 0x00
  u16 cmdCount;        // 0x02
  // body:
  //   AuxAnim animations[animationCount];
  //   AuxAnimCmd cmds[cmdCount];
  u8 body[0];
} AuxAnimFile;

// AuxAnimFile の1アニメーションを再生する状態, 根拠: FUN_08236fac (開始), FUN_08237098 (速度変更), Entity08015584_Update (進行)
typedef struct {
  AuxAnimCmd* cmds;        // 0x00, 再生中のアニメーションコマンド列
  AuxAnimPlayFlags flags;  // 0x04, see AuxAnimPlayFlags
  u8 cmdCount;             // 0x05
  u8 duration;             // 0x06, 現フレームの表示時間 (AuxAnimCmd の bit0-3)
  u8 wait;                 // 0x07, duration * speed >> 6 (0 なら 1)
  u16 cmdIdx;              // 0x08, cmds の添字
  u16 animIdx;             // 0x0A, 再生中のアニメーション番号, 同じ番号で FUN_08236fac を呼んでも再開しない
  u16 speed;               // 0x0C, 再生速度, 0x40 が等速
  u16 tick;                // 0x0E, 毎フレーム +1, wait に達したら 0 に戻して次のコマンドへ
} AuxAnimState;
static_assert(sizeof(AuxAnimState) == 16);

// アニメーションの再生を開始する。同じ animIdx で呼んでも再開はしない (src/sprite_anim_aux.c)
bool32 FUN_08236fac(AuxAnimState* p, AuxAnimFile* files, u16 animIdx, u8 variant, AuxAnimPlayFlags flags);

#endif  // __INCLUDE_ANIMATION_H__
