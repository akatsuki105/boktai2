#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "gba/gba.h"
#include "sprite_aux.h"
#include "sprite_common.h"
#include "sprite_main.h"
#include "sprite_pltt.h"

// FUN_08055dac / FUN_08055e34 が作るスプライトの器, unk_0 が 1 なら AuxSpriteGfx(0x0C) + AuxSprite(0x28) + Vec3(0x44) + アニメファイル(0x64) を、
// 2 なら下の MainSpriteGfx + MainSprite を使う, pos / flags は使っている方を指す
typedef struct {
  u32 unk_0;  // 0x00
  u8 unk_4[8];
  MainSpriteGfx gfx;   // 0x0C
  MainSprite sprite;   // 0x2C
  Vec3* pos;           // 0x8C
  SpriteFlags* flags;  // 0x90
} DexPreview;
static_assert(sizeof(DexPreview) == 148);  // 根拠: 0x08055e54

#endif  // __INCLUDE_SPRITE_H__
