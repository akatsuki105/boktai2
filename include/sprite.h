#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "animation.h"
#include "gba/gba.h"
#include "sprite_aux.h"
#include "sprite_common.h"
#include "sprite_main.h"
#include "sprite_pltt.h"

// FUN_08055dac / FUN_08055e34 が作るスプライトの器, kind で AuxSprite と MainSprite を使い分ける
typedef struct {
  u32 kind;  // 0x00, 0: 未使用, 1: AuxSprite, 2: MainSprite
  u8 unk_4[8];
  union {
    struct {
      AuxSpriteGfx gfx;       // 0x0C, FUN_08055dac が Video_GetAuxSprite で作る
      AuxSprite sprite;       // 0x28
      AuxAnimState anim;      // 0x54, FUN_08055b5c が FUN_08236fac に渡す
      AuxAnimFile* animFile;  // 0x64, FUN_08055dac が GetFile(DIR_ANIMATION, animFileID), 0 ならアニメーションなし
    } aux;
    struct {
      MainSpriteGfx gfx;  // 0x0C, FUN_08055e34 が OpenSpriteSetFile で作る
      MainSprite sprite;  // 0x2C, MainSprite は自身にアニメーションを持つので animFile はいらない
    } main;
  } u;                 // 0x0C
  Vec3* pos;           // 0x8C, 使っている方の sprite.pos を指す
  SpriteFlags* flags;  // 0x90, 使っている方の sprite.flags を指す
} DexPreview;
static_assert(sizeof(DexPreview) == 148);  // 根拠: 0x08055e54

#endif  // __INCLUDE_SPRITE_H__
