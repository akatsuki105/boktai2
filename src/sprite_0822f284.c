#include "global.h"
#include "sprite.h"

NAKED bool32 OpenSpriteSetFile(SpriteSet* data, spriteset_header* f) { INCFUNC("asm/func/OpenSpriteSetFile.inc"); }

// Unused?
NAKED unknown* FUN_0822f2bc(unknown* a, unknown* b) { INCFUNC("asm/func/FUN_0822f2bc.inc"); }

NAKED s32 Sprite_LoadSprite(SpriteState* p, SpriteSet* src, u16 param_3) { INCFUNC("asm/func/Sprite_LoadSprite.inc"); }

INCASM("asm/sprite_0822f284.inc");

void FUN_0822f584(void) {}

NAKED void FUN_0822f588(unknown* a, unknown* b, u32 val) { INCFUNC("asm/func/FUN_0822f588.inc"); }

NAKED void Sprite_SetPlttID(SpriteState* p, u32 plttID) { INCFUNC("asm/func/Sprite_SetPlttID.inc"); }
