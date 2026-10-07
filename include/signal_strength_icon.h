#ifndef GUARD_ZOKTAI_SIGNAL_STRENGTH_ICON_H
#define GUARD_ZOKTAI_SIGNAL_STRENGTH_ICON_H

#include "entity.h"
#include "gba/gba.h"
#include "sprite_main.h"

// ワイヤレス通信(RFU)の電波強度インジケータ, gRfuLinkStatus->strength を見てアイコンを差し替える
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_11
  u32 updateCounter;  // 0x18, SignalStrengthIcon_Update が毎フレーム +1 するだけ, 読み手は見つかっていない
  u32 animCounter;    // 0x1C, SignalStrengthIcon_SetStrength が呼ばれるたびに +1, & 0x1F の値で同じ強度内の点滅段を選ぶ
  s32 poseIdx;        // 0x20, 現在表示しているアイコン番号 (62..66)
  MainSpriteGfx gfx;  // 0x24, SPRITE_UI_LINK
  MainSprite sprite;  // 0x44
} SignalStrengthIcon;
static_assert(sizeof(SignalStrengthIcon) == 164);

SignalStrengthIcon* SignalStrengthIcon_Create(void);

#endif  // GUARD_ZOKTAI_SIGNAL_STRENGTH_ICON_H
