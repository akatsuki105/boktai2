#ifndef __INCLUDE_ANIMATION_H__
#define __INCLUDE_ANIMATION_H__

#include "gba/gba.h"

// https://boktaihacking.net/wiki/Animation_file

typedef u8 AnimPlayFlags;
#define ANIM_PLAY_XFLIP (1 << 0)    // bit0: XFLIP
#define ANIM_PLAY_YFLIP (1 << 1)    // bit1: YFLIP
#define ANIM_PLAY_REVERSE (1 << 2)  // bit2: 逆再生

typedef struct {
  u8 variantCount;  // 0x00
  u8 frameCount;    // 0x01
  u16 frameOffset;  // 0x02, Byte offset from start of the file to the 1st frame of the 1st variant for this animation. There are variantCount*frameCount frames in this animation.
} Animation;

// bit0-3: duration
// bit4: xflip
// bit5: yflip
// bit6-15: sprite index
typedef u16 AnimFrameCmd;

// ActorSprite's animation
typedef struct {
  u16 animationCount;  // 0x00
  u16 frameCount;      // 0x02
  // body:
  //   Animation animations[animationCount];
  //   AnimFrameCmd frames[frameCount];
  u8 body[0];
} AnimationFile;

// AnimationFile の1アニメーションを再生する状態, 根拠: FUN_08236fac (開始), FUN_08237098 (速度変更), Entity08015584_Update (進行)
typedef struct {
  AnimFrameCmd* frames;  // 0x00, 再生中のアニメーションのフレーム列
  AnimPlayFlags flags;   // 0x04, see AnimPlayFlags
  u8 frameCount;         // 0x05
  u8 duration;           // 0x06, 現フレームの表示時間 (AnimFrameCmd の bit0-3)
  u8 wait;               // 0x07, duration * speed >> 6 (0 なら 1)
  u16 frameIdx;          // 0x08, frames の添字
  u16 animIdx;           // 0x0A, 再生中のアニメーション番号, 同じ番号で FUN_08236fac を呼んでも再開しない
  u16 speed;             // 0x0C, 再生速度, 0x40 が等速
  u16 tick;              // 0x0E, 毎フレーム +1, wait に達したら 0 に戻して次のフレームへ
} AnimState;
static_assert(sizeof(AnimState) == 16);

#endif  // __INCLUDE_ANIMATION_H__
