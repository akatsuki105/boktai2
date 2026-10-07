#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// 太陽バンクのメニュー
typedef struct Entity7F5E {
  Entity e;                                    // ENTITY_UNK_11
  MainSpriteGfx gfx[2];                        // 0x018
  MainSprite sprites[13];                      // 0x058
  AuxSprite auxSprites[2];                     // 0x538
  u8 unk_590[0x5C8 - 0x590];                   // 0x590
  TilemapFile* tilemap;                        // 0x5C8, TILEMAP_83C0
  rgb555* bgPltt;                              // 0x5CC, BGP_EAA8[208]
  u8* textPc;                                  // 0x5D0, TextBox_Start に渡すバイトコード位置
  u8 unk_5d4[0x5DC - 0x5D4];                   // 0x5D4
  u32 scriptID;                                // 0x5DC, 閉じるときに VM_ExecByID に渡す
  u8 unk_5e0[0x5EA - 0x5E0];                   // 0x5E0
  u16 unk_5ea;                                 // 0x5EA
  u16 stateTimer;                              // 0x5EC
  u16 unk_5ee;                                 // 0x5EE
  void (*updateCallback)(struct Entity7F5E*);  // 0x5F0
} Entity7F5E;
static_assert(sizeof(Entity7F5E) == 1524);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);

void FUN_080b3c98(Entity7F5E* p);
void FUN_080b3dd0(Entity7F5E* p);
void FUN_080b3e3c(Entity7F5E* p);
void FUN_080b3e80(Entity7F5E* p);
void FUN_080b4334(Entity7F5E* p);
void FUN_080b438c(Entity7F5E* p);

// 0x61A0
NAKED void SolarBank_CalcInterestRate(void) { INCFUNC("asm/func/SolarBank_CalcInterestRate.inc"); }

s32 SolarBank_GetBalanceScripted(void) { return (s16)gStat->solarBank; }

void SolarBank_SetBalanceScripted(void) {
  if (VM_SeekToNamedArg('a')) {
    s32 n = VM_GetValue();

    if (n > 9999) {
      n = 9999;
    }
    gStat->solarBank = n;
  }
}

NAKED void solar_bank_080b3a10(Entity7F5E* p) { INCFUNC("asm/func/solar_bank_080b3a10.inc"); }

// スプライトを全部隠す
void SolarBank_HideAllSprites(Entity7F5E* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }

  for (i = 0; i < 2; i++) {
    p->auxSprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void SolarBank_SetState(Entity7F5E* p, void (*fn)(Entity7F5E*)) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080b3b74(Entity7F5E* p) {
  Video_SetBGLayer(0, p->tilemap, 0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(p->sprites, p->gfx, 0, 2, 0);
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  TextBox_ShowLine(0);
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  SolarBank_SetState(p, FUN_080b3e3c);
}

void FUN_080b3c08(Entity7F5E* p) {
  Video_SetBGLayer(0, p->tilemap, 0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->unk_5ea = 1;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[1], &p->gfx[1], 4, 1, 0);
  TextBox_ShowLine(1);
  SolarBank_SetState(p, FUN_080b3e80);
}

NAKED void FUN_080b3c98(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b3c98.inc"); }

void FUN_080b3dd0(Entity7F5E* p) {
  Video_SetBGLayer(0, p->tilemap, 2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  PlaySound_082406e0(0x2BF);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(p->sprites, p->gfx, 2, 2, 0);
  TextBox_ShowLine(3);
  SolarBank_SetState(p, FUN_080b4334);
}

void FUN_080b3e3c(Entity7F5E* p) {
  if (p->stateTimer == 32) {
    PlaySound_082406e0(0x2BE);
  }
  MainSprite_AdvanceAnim(p->sprites, p->gfx);
  p->stateTimer++;
  if (p->stateTimer > 104) {
    FUN_080b3c08(p);
  }
}

void FUN_080b3e80(Entity7F5E* p) {
  if (gInput[0].pressed & A_BUTTON) {
    if (p->unk_5ea != 0) {
      PlaySound_082406e0(0xDD);
      FUN_080b3c98(p);
    } else {
      PlaySound_082406e0(0xDE);
      FUN_080b3dd0(p);
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(0xDE);
    FUN_080b3dd0(p);
  } else if (gInput[0].pressed & (DPAD_RIGHT | DPAD_LEFT)) {
    PlaySound_082406e0(0xDC);
    p->unk_5ea = 1 - p->unk_5ea;
    if (p->unk_5ea != 0) {
      MainSprite_SetAnim(&p->sprites[1], &p->gfx[1], 4, 1, 0);
    } else {
      MainSprite_SetAnim(&p->sprites[1], &p->gfx[1], 5, 1, 0);
    }
  } else {
    MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx[1]);
  }
  MainSprite_AdvanceAnim(p->sprites, p->gfx);
}

NAKED void solar_bank_080b3f38(Entity7F5E* p) { INCFUNC("asm/func/solar_bank_080b3f38.inc"); }

void FUN_080b4334(Entity7F5E* p) {
  MainSprite_AdvanceAnim(p->sprites, p->gfx);
  p->stateTimer++;
  if (p->stateTimer > 149) {
    FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
    SolarBank_SetState(p, FUN_080b438c);
  }
}

void FUN_080b438c(Entity7F5E* p) {
  p->stateTimer++;
  if (p->stateTimer > 31 && p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
    KillEntity((Entity*)p);
  }
}

s32 Entity7F5E_Update(Entity7F5E* p) {
  p->updateCallback(p);
  return 0;
}

s32 Entity7F5E_Destroy(Entity7F5E* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&p->auxSprites[i]);
  }

  return 0;
}

void SolarBank_InitBgLayout(Entity7F5E* p) {
  s32 indices;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_83C0);
  indices = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &indices);
}

void SolarBank_InitBgPltt(Entity7F5E* p) {
  p->bgPltt = &GetBgPlttFile(BGP_EAA8)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 96);
}

NAKED void FUN_080b4490(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4490.inc"); }

void SolarBank_InitTextBox(Entity7F5E* p) {
  if (VM_SeekToNamedArg('r')) {
    p->textPc = FUN_0823d340();
  }
  TextBox_SetBgPltt(BGP_EAA8);
  TextBox_Start(p->textPc);
  TextBox_SetRect(1, 15, 28, 4);
  TextBox_SetInstant(1);
}

s32 Entity7F5E_Init(Entity7F5E* p) {
  SolarBank_InitBgLayout(p);
  SolarBank_InitBgPltt(p);
  FUN_080b4490(p);
  SolarBank_InitTextBox(p);
  if (VM_SeekToNamedArg('e')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  FUN_080b3b74(p);
  return 0;
}

Entity7F5E* Entity7F5E_Create(u32 unused1, u32 unused2) {
  Entity7F5E* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity7F5E));

  if (p != NULL) {
    SetEntityRoutine(p, Entity7F5E_Update, Entity7F5E_Destroy);
    if (Entity7F5E_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
