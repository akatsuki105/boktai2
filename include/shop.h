#ifndef __INCLUDE_SHOP_H__
#define __INCLUDE_SHOP_H__

#include "gba/gba.h"
#include "menu.h"
#include "sprite_main.h"
#include "types.h"

// MainSpriteGfx ひとつと、そこから作った MainSprite 2枚をまとめた表示部品, メニュー系のエンティティが共通で持つ
typedef struct {
  MainSpriteGfx gfx;      // 0x00, FUN_080b99a0 / FUN_080b9814 が OpenMainSpriteFile で作る
  MainSprite sprites[2];  // 0x20, FUN_080b9a0c / FUN_080b9894 が MainSprite_Remove する
} MenuSpritePair;
static_assert(sizeof(MenuSpritePair) == 224);

void FUN_080b95d0(MenuCursor* cursor, s32 param_2, MainSprite* sprite1, MainSprite* sprite2);
void FUN_080b9a0c(MenuSpritePair* p);
void FUN_080b9400(s32 kind);
void FUN_080b94cc(s32 kind);
void FUN_080b9894(MenuSpritePair* p);
void MenuCursor_Init(MenuCursor* p, u32 kind, u32 row, u32 col, u32 unk);
void FUN_080b9fc4(MenuCursor* p, MainSprite* sprite);
s32 FUN_080b977c(MainSprite* sprite, MainSpriteGfx* gfx, u8* param_3);
void FUN_080b9fe8(MenuCursor* p);
void FUN_080b9d94(MenuCursor* p, u32 unk);
void FUN_080b9938(s16* param_1, s32 param_2);
void FUN_080b98c0(MainSpriteGfx* gfx, s32 param_2, s32 param_3);
void FUN_080b95bc(MainSprite* p, u16 plttID);
void FUN_080b99a0(MenuSpritePair* p);
void FUN_080b9814(MenuSpritePair* p);
bool32 FUN_080b9adc(unknown* p);
void FUN_080b9740(MainSprite* sprite, MainSpriteGfx* gfx, char* out, s32 val);
s32 FUN_080b9f70(MenuCursor* p);
void FUN_080b9fd8(MenuCursor* p);
void FUN_080b9a28(MainSpriteGfx* gfx, s32* param_2, WorldPos* pos1, WorldPos* pos2, s32* param_5, s32* param_6, s32 param_7);
void FUN_080b9724(MainSprite* sprites);
void FUN_080b9658(MainSpriteGfx* gfx, MainSprite* sprite, unknown* param_3, s32 param_4, s32 param_5);

#endif  // __INCLUDE_SHOP_H__
