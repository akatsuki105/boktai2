#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "gba/gba.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "sprite_common.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "types.h"

// FUN_08055dac / FUN_08055e34 が作るスプライトの器, kind で AuxSprite と MainSprite を使い分ける
// 図鑑専用ではなく、Entity286FNode も1つ、PreviewStage は5つ持つ
typedef struct {
  u32 kind;  // 0x00, 0: 未使用, 1: AuxSprite, 2: MainSprite
  u8 unk_4[8];
  union {
    struct {
      AuxSpriteGfx gfx;       // 0x0C, FUN_08055dac が Video_GetAuxSprite で作る
      AuxSprite sprite;       // 0x28
      AuxAnimState anim;      // 0x54, SpriteHolder_SetAnim が AuxAnim_SetAnim に渡す
      AuxAnimFile* animFile;  // 0x64, 0 ならアニメーションなし
    } aux;
    struct {
      MainSpriteGfx gfx;  // 0x0C, FUN_08055e34 が OpenMainSpriteFile で作る
      MainSprite sprite;  // 0x2C, MainSprite は自身にアニメーションを持つので animFile はいらない
    } main;
  } u;                 // 0x0C
  Vec3* pos;           // 0x8C, 使っている方の sprite.pos を指す
  SpriteFlags* flags;  // 0x90, 使っている方の sprite.flags を指す
} SpriteHolder;
static_assert(sizeof(SpriteHolder) == 148);  // 根拠: 0x08055e54

// kind に応じて AuxSprite / MainSprite のパレットIDを設定する, kind == 0 なら -1
s32 SpriteHolder_SetPlttID(SpriteHolder* p, u32 plttID);

#endif  // __INCLUDE_SPRITE_H__
