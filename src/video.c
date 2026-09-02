#include "entity.h"
#include "global.h"
#include "sprite.h"

extern u8 u8_ARRAY_02036c00[512];
extern u16 u16_030044b8;

const u8 u8_ARRAY_085b0110[32] = {0};

#define SPRITE_SIZE(widthPixel, heightPixel) ((heightPixel << 8) | widthPixel)

// clang-format off
// idx: (OAM1.14-15 << 2) | (OAM0.14-15), ie. ((sizeidx << 2) | shape)
const u16 gSpriteSizeTable[16] = {
// OAM0.14-15:  Square(0)             Horizontal(1)         Vertical(2)           Prohibited(3)
                SPRITE_SIZE( 8,  8),  SPRITE_SIZE(16,  8),  SPRITE_SIZE( 8, 16),  0x0,
                SPRITE_SIZE(16, 16),  SPRITE_SIZE(32,  8),  SPRITE_SIZE( 8, 32),  0x0,
                SPRITE_SIZE(32, 32),  SPRITE_SIZE(32, 16),  SPRITE_SIZE(16, 32),  0x0,
                SPRITE_SIZE(64, 64),  SPRITE_SIZE(64, 32),  SPRITE_SIZE(32, 64),  0x0,
}; // 0x085b0130
// clang-format on

#undef SPRITE_SIZE

// fileID に SPRITE_SHAIAN が渡されている in 0x0818352c
void Video_GetActorSprite(void* p, u32 fileID);

void FUN_0822a41c(SpriteState* p, s32 idx);

NAKED s32 VideoManager_Update(Entity* p) { INCFUNC("asm/func/VideoManager_Update.inc"); }

NAKED s32 EntityKind13_Update(Entity* p) { INCFUNC("asm/func/EntityKind13_Update.inc"); }

NAKED void FUN_0822a2a8(void) { INCFUNC("asm/func/FUN_0822a2a8.inc"); }

INCASM("asm/video.inc");

void* FUN_0822ee74(void) { return u8_ARRAY_02036c00; }

NAKED void* Video_GetBGnHOFS(s32 bg) { INCFUNC("asm/func/Video_GetBGnHOFS.inc"); }

NAKED void* Video_GetBGnVOFS(s32 bg) { INCFUNC("asm/func/Video_GetBGnVOFS.inc"); }

NAKED void FUN_0822eef4(void) { INCFUNC("asm/func/FUN_0822eef4.inc"); }

NAKED void FUN_0822f0d8(void) { INCFUNC("asm/func/FUN_0822f0d8.inc"); }

void FUN_0822f178(s32 idx, u32 evb, u32 eva) {
  static const u16 u16_ARRAY_085b0150[4] = {
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG0,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG1,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG2,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG3,
  };  // 0x085b0150
  REG_BLDCNT = u16_ARRAY_085b0150[idx] | BLDCNT_EFFECT_BLEND;
  REG_BLDALPHA = BLDALPHA_BLEND(eva, evb);
  REG_BLDY = 0;
}

s32 FUN_0822f1b0(void) {
  u16_030044b8 = 0;
  return 0;
}

void FUN_0822f1c0(SpriteState* p) {
  if (p->unk_4 != 0) {
    FUN_0822a41c(p, p->unk_1c);
  }
}

NAKED void FUN_0822f1d8(void) { INCFUNC("asm/func/FUN_0822f1d8.inc"); }
