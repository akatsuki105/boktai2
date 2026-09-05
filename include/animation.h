#ifndef __INCLUDE_ANIMATION_H__
#define __INCLUDE_ANIMATION_H__

#include "gba/gba.h"

// https://boktaihacking.net/wiki/Animation_file

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

#endif  // __INCLUDE_ANIMATION_H__
