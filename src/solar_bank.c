#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// dark_loans.c と同形

// 太陽バンクのメニュー
typedef struct SolarBank {
  Entity e;                                   // ENTITY_UNK_11
  MainSpriteGfx gfx[2];                       // 0x018
  MainSprite sprites[13];                     // 0x058
  AuxSprite auxSprites[2];                    // 0x538
  AuxSpriteGfx auxGfx[2];                     // 0x590
  TilemapFile* tilemap;                       // 0x5C8, TILEMAP_BANK
  rgb555* bgPltt;                             // 0x5CC, BGP_BANK[208]
  u8* textPc;                                 // 0x5D0, MessageWindow_Start に渡すバイトコード位置
  s32 bank;                                   // 0x5D4, 預けている太陽
  s32 stand;                                  // 0x5D8, 持っている太陽
  u32 scriptID;                               // 0x5DC, 閉じるときに VM_ExecByID に渡す
  u16 unk_5e0;                                // 0x5E0
  u16 unk_5e2[4];                             // 0x5E2
  u16 unk_5ea;                                // 0x5EA
  u16 stateTimer;                             // 0x5EC
  u16 unk_5ee;                                // 0x5EE
  void (*updateCallback)(struct SolarBank*);  // 0x5F0
} SolarBank;
static_assert(sizeof(SolarBank) == 1524);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);

void FUN_080b3c98(SolarBank* p);
void solar_bank_080b3f38(SolarBank* p);
void FUN_080b3dd0(SolarBank* p);
void FUN_080b3e3c(SolarBank* p);
void FUN_080b3e80(SolarBank* p);
void FUN_080b4334(SolarBank* p);
void FUN_080b438c(SolarBank* p);

// 0x61A0
// 77/77 命令, 末尾の + 65 が格納先のアドレス計算より後に来る形にならない
NON_MATCH void Cmd_CalcInterestRate(void) {
#ifdef NONMATCHING_C
  s32 days;
  s32 amount;
  s32 i;

  if (gGameFlags & GAMEFLAG_LINK) {
    return;
  }

  if (VM_SeekToNamedArg('d')) {
    days = VM_GetValue();
    if (days > 10) {
      days = 10;
    }
  } else {
    days = 0;
  }
  if (days < 1) {
    return;
  }

  amount = (s16)gStat->solarBank;
  if (amount >= 1 && amount <= 9998) {
    for (i = 0; i < days; i++) {
      amount = ((amount * gStat->solarBankInterestRate) >> 6) + 1;
      if (amount >= 9999) {
        amount = 9999;
        break;
      }
    }
    gStat->solarBank = amount;
  }

  gStat->solarBankInterestRate = Mod(gStat->playTime ^ Time_GetSecond(), 13) + 65;
#else
  INCFUNC("asm/func/Cmd_CalcInterestRate.inc");
#endif
}

// 0x9E8B
s32 Cmd_GetSolarBankBalance(void) { return gStat->solarBank; }

// 0x7A77
void Cmd_SetSolarBankBalance(void) {
  if (VM_SeekToNamedArg('a')) {
    s32 amount = VM_GetValue();
    if (amount > 9999) {
      amount = 9999;
    }
    gStat->solarBank = amount;
  }
}

// 130/126 命令, 桁を 0 で埋めるループでカウンタが消えず &digits[3] から sp まで符号付き比較で回す形にならない (InitSystemManager と同じ)
NON_MATCH void solar_bank_080b3a10(SolarBank* p) {
#ifdef NONMATCHING_C
  s32 digits[4];
  s32 amount;
  s32 i;

  amount = p->bank;
  if (amount == 0) {
    for (i = 3; i >= 0; i--) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(amount, 1000);
    amount -= digits[0] * 1000;
    digits[1] = Div(amount, 100);
    amount -= digits[1] * 100;
    digits[2] = Div(amount, 10);
    digits[3] = amount - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    MainSprite_SetPose(&p->sprites[9 + i], &p->gfx[1], digits[i], PLAYMODE_LOOP);
  }

  amount = p->stand;
  if (amount == 0) {
    for (i = 3; i >= 0; i--) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(amount, 1000);
    amount -= digits[0] * 1000;
    digits[1] = Div(amount, 100);
    amount -= digits[1] * 100;
    digits[2] = Div(amount, 10);
    digits[3] = amount - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    MainSprite_SetPose(&p->sprites[5 + i], &p->gfx[1], digits[i], PLAYMODE_LOOP);
  }
#else
  INCFUNC("asm/func/solar_bank_080b3a10.inc");
#endif
}

// スプライトを全部隠す
void SolarBank_HideAllSprites(SolarBank* p) {
  s32 i;
  for (i = 0; i < 13; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 2; i++) {
    p->auxSprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void SolarBank_SetState(SolarBank* p, void* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080b3b74(SolarBank* p) {
  Video_SetBGLayer(0, p->tilemap, 0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(p->sprites, p->gfx, 0, PLAYMODE_ONCE_AND_STOP, 0);
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  MessageWindow_ShowLine(0);
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  SolarBank_SetState(p, FUN_080b3e3c);
}

void FUN_080b3c08(SolarBank* p) {
  Video_SetBGLayer(0, p->tilemap, 0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->unk_5ea = 1;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[1], &p->gfx[1], 4, PLAYMODE_LOOP, 0);
  MessageWindow_ShowLine(1);
  SolarBank_SetState(p, FUN_080b3e80);
}

void FUN_080b3c98(SolarBank* p) {
  s32 i;

  Video_SetBGLayer(0, p->tilemap, 1);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[0], &p->gfx[0], 1, PLAYMODE_LOOP, 0);
  p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[4], &p->gfx[0], 18, PLAYMODE_LOOP);
  p->stand = gStat->solarStand;
  p->bank = (s16)gStat->solarBank;
  for (i = 0; i < 4; i++) {
    p->sprites[5 + i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[9 + i].flags &= ~SPRFLAG_HIDDEN;
  }
  solar_bank_080b3a10(p);
  for (i = 0; i < 2; i++) {
    p->auxSprites[i].flags &= ~SPRFLAG_HIDDEN;
  }
  Video_SetAuxSpritePltt(&p->auxGfx[0], 317);
  Video_SetAuxSpritePltt(&p->auxGfx[1], 320);
  MessageWindow_ShowLine(2);
  p->unk_5e2[0] = 0;
  p->unk_5e2[1] = 0;
  p->unk_5e2[2] = 0;
  p->unk_5e2[3] = 0;
  p->unk_5e0 = 0;
  SolarBank_SetState(p, solar_bank_080b3f38);
}

void FUN_080b3dd0(SolarBank* p) {
  Video_SetBGLayer(0, p->tilemap, 2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  SolarBank_HideAllSprites(p);
  PlaySound_082406e0(SONG_703);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(p->sprites, p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 0);
  MessageWindow_ShowLine(3);
  SolarBank_SetState(p, FUN_080b4334);
}

void FUN_080b3e3c(SolarBank* p) {
  if (p->stateTimer == 32) {
    PlaySound_082406e0(SONG_702);
  }
  MainSprite_AdvanceAnim(p->sprites, p->gfx);
  p->stateTimer++;
  if (p->stateTimer > 104) {
    FUN_080b3c08(p);
  }
}

void FUN_080b3e80(SolarBank* p) {
  if (gInput[0].pressed & A_BUTTON) {
    if (p->unk_5ea != 0) {
      PlaySound_082406e0(SE_SELECT);
      FUN_080b3c98(p);
    } else {
      PlaySound_082406e0(SE_CANCEL);
      FUN_080b3dd0(p);
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b3dd0(p);
  } else if (gInput[0].pressed & (DPAD_RIGHT | DPAD_LEFT)) {
    PlaySound_082406e0(SE_CURSOR_MOVE);
    p->unk_5ea = 1 - p->unk_5ea;
    if (p->unk_5ea != 0) {
      MainSprite_SetAnim(&p->sprites[1], &p->gfx[1], 4, PLAYMODE_LOOP, 0);
    } else {
      MainSprite_SetAnim(&p->sprites[1], &p->gfx[1], 5, PLAYMODE_LOOP, 0);
    }
  } else {
    MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx[1]);
  }
  MainSprite_AdvanceAnim(p->sprites, p->gfx);
}

// 403/413 命令, gStat の読み方と左右の枝の共有が違う, 下書き段階
NON_MATCH void solar_bank_080b3f38(SolarBank* p) {
#ifdef NONMATCHING_C
  if (gInput[0].pressed & A_BUTTON) {
    gStat->solarStand = p->stand;
    gStat->solarBank = p->bank;
    PlaySound_082406e0(SE_SELECT);
    FUN_080b3dd0(p);
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b3c08(p);
  } else {
    s32 anim;

    if (gInput[0].down & DPAD_LEFT) {
      if (p->stand < 9999 && p->bank != 0) {
        if (p->unk_5e2[0] == 0) {
          p->unk_5e2[1] = 0;
        }
        p->unk_5e2[3] = 0;
        p->unk_5e2[2] = 16;
        if (p->unk_5e2[0] >= 128) {
          s32 from;
          s32 to;

          PlaySound_082406e0(SE_MONEY_TRANSFER);
          from = 10;
          if (p->bank < 10) {
            from = p->bank;
          }
          to = 10;
          if (p->stand + 10 > 9999) {
            to = 9999 - p->stand;
          }
          if (from < to) {
            p->stand += from;
            p->bank -= from;
          } else {
            p->stand += to;
            p->bank -= to;
          }
          solar_bank_080b3a10(p);
          p->unk_5e2[1] = 2;
          p->unk_5e2[2] = 4;
        } else if (p->unk_5e2[0] >= 64) {
          if ((p->unk_5e2[0] & 3) == 0) {
            PlaySound_082406e0(SE_MONEY_TRANSFER);
          }
          p->stand++;
          p->bank--;
          solar_bank_080b3a10(p);
          p->unk_5e2[1] = 1;
          p->unk_5e2[2] = 4;
          p->unk_5e2[0]++;
        } else if ((p->unk_5e2[0]++ & 7) == 0) {
          PlaySound_082406e0(SE_MONEY_TRANSFER);
          p->stand++;
          p->bank--;
          solar_bank_080b3a10(p);
        }
      } else {
        p->unk_5e2[0] = 0;
      }
    } else if (gInput[0].down & DPAD_RIGHT) {
      if (p->stand != 0 && p->bank < 9999) {
        if (p->unk_5e2[0] == 0) {
          p->unk_5e2[1] = 0;
        }
        p->unk_5e2[3] = 1;
        p->unk_5e2[2] = 16;
        if (p->unk_5e2[0] >= 128) {
          s32 from;
          s32 to;

          PlaySound_082406e0(SE_MONEY_TRANSFER);
          from = 10;
          if (p->stand < 10) {
            from = p->stand;
          }
          to = 10;
          if (p->bank + 10 > 9999) {
            to = 9999 - p->bank;
          }
          if (from < to) {
            p->bank += from;
            p->stand -= from;
          } else {
            p->bank += to;
            p->stand -= to;
          }
          solar_bank_080b3a10(p);
          p->unk_5e2[1] = 2;
          p->unk_5e2[2] = 4;
        } else if (p->unk_5e2[0] >= 64) {
          if ((p->unk_5e2[0] & 3) == 0) {
            PlaySound_082406e0(SE_MONEY_TRANSFER);
          }
          p->bank++;
          p->stand--;
          solar_bank_080b3a10(p);
          p->unk_5e2[1] = 1;
          p->unk_5e2[2] = 4;
          p->unk_5e2[0]++;
        } else if ((p->unk_5e2[0]++ & 7) == 0) {
          PlaySound_082406e0(SE_MONEY_TRANSFER);
          p->bank++;
          p->stand--;
          solar_bank_080b3a10(p);
        }
      } else {
        p->unk_5e2[0] = 0;
      }
    } else {
      p->unk_5e2[0] = 0;
    }

    if (p->unk_5e2[2] != 0) {
      if (p->unk_5e2[1] == 2) {
        p->unk_5e0 += 4;
      } else if (p->unk_5e2[1] == 1) {
        p->unk_5e0 += 2;
      } else {
        p->unk_5e0++;
      }
      p->unk_5e2[2]--;
    } else {
      p->unk_5e0 = 0;
    }

    if (p->unk_5e0 != 0) {
      switch ((p->unk_5e0 & 0x1F) >> 3) {
        case 0:
        case 2: {
          anim = 1;
          break;
        }
        case 1: {
          anim = 2;
          break;
        }
        default: {
          anim = 0;
          break;
        }
      }
      Video_SetAuxSpritePltt(&p->auxGfx[0], anim + 317);
      Video_SetAuxSpritePltt(&p->auxGfx[1], anim + 320);
      MainSprite_SetPose(&p->sprites[4], &p->gfx[0], p->unk_5e2[3] * 3 + 19 + anim, PLAYMODE_LOOP);
    } else {
      Video_SetAuxSpritePltt(&p->auxGfx[0], 317);
      Video_SetAuxSpritePltt(&p->auxGfx[1], 320);
      MainSprite_SetPose(&p->sprites[4], &p->gfx[0], 18, PLAYMODE_LOOP);
    }
  }

  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx[0]);
#else
  INCFUNC("asm/func/solar_bank_080b3f38.inc");
#endif
}

void FUN_080b4334(SolarBank* p) {
  MainSprite_AdvanceAnim(p->sprites, p->gfx);
  p->stateTimer++;
  if (p->stateTimer > 149) {
    FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
    SolarBank_SetState(p, FUN_080b438c);
  }
}

void FUN_080b438c(SolarBank* p) {
  p->stateTimer++;
  if (p->stateTimer > 31 && p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
    KillEntity((Entity*)p);
  }
}

s32 SolarBank_Update(SolarBank* p) {
  p->updateCallback(p);
  return 0;
}

s32 SolarBank_Destroy(SolarBank* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&p->auxSprites[i]);
  }

  return 0;
}

void SolarBank_InitBgLayout(SolarBank* p) {
  s32 indices;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_BANK);
  indices = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &indices);
}

void SolarBank_InitBgPltt(SolarBank* p) {
  p->bgPltt = &GetBgPlttFile(BGP_BANK)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 96);
}

// 297/302 命令, 16 バイトのスタックの持ち方が違う
NON_MATCH void FUN_080b4490(SolarBank* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* file;
  MainSpriteGfx* gfx0;
  MainSpriteGfx* gfx1;
  Vec3 pos;
  Vec3* posPtr;
  s32 rate;
  s32 tens;
  s32 i;

  file = GetFile(DIR_MAIN_SPRITE, 0x92F0);
  p->gfx[0] = *file;
  gfx0 = &p->gfx[0];
  OpenMainSpriteFile(gfx0, file);
  file = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  p->gfx[1] = *file;
  gfx1 = &p->gfx[1];
  OpenMainSpriteFile(gfx1, file);

  posPtr = &pos;
  pos.x = 0, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->sprites[0], gfx0, 0, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  if (gStat->solarBankInterestRate == 0) {
    gStat->solarBankInterestRate = Mod(gStat->playTime ^ Time_GetSecond(), 13) + 65;
  }
  rate = ((gStat->solarBankInterestRate * 100) >> 6) - 100;
  tens = Div(rate, 10);
  MainSprite_Add(&p->sprites[2], gfx0, tens + 8, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x += 8;
  MainSprite_Add(&p->sprites[3], gfx0, rate - tens * 10 + 8, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x = 0;
  MainSprite_Add(&p->sprites[4], gfx0, 18, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  posPtr->y = -8;
  MainSprite_Add(&p->sprites[1], gfx1, 148, SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x = 40;
  posPtr->y = 40;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[5 + i], gfx1, 0, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }
  pos.x = 136;
  pos.y = 40;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[9 + i], gfx1, 0, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }
  for (i = 0; i < 2; i++) {
    Video_GetAuxSprite(&p->auxGfx[i], 0xA47C);
    AuxSprite_Add(&p->auxSprites[i], &p->auxGfx[i], 0);
    p->auxSprites[i].priority = 0;
    p->auxSprites[i].flags = 48;
    if (i == 0) {
      p->auxSprites[i].flags |= SPRFLAG_XFLIP;
    }
    if (i == 1) {
      Video_SetAuxSpritePltt(&p->auxGfx[1], 320);
    }
    p->auxSprites[i].pos.x = i * 96 + 56;
    p->auxSprites[i].pos.y = 88;
    p->auxSprites[i].pos.z = 0;
  }
#else
  INCFUNC("asm/func/FUN_080b4490.inc");
#endif
}

void SolarBank_InitTextBox(SolarBank* p) {
  if (VM_SeekToNamedArg('r')) {
    p->textPc = VM_GetPC_Proxy();
  }
  MessageWindow_SetBgPltt(BGP_BANK);
  MessageWindow_Start(p->textPc);
  MessageWindow_SetRect(1, 15, 28, 4);
  MessageWindow_SetInstant(1);
}

s32 SolarBank_Init(SolarBank* p) {
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

SolarBank* SolarBank_Create(u32 unused1, u32 unused2) {
  SolarBank* p = CreateEntity(ENTITY_UNK_11, sizeof(SolarBank));

  if (p != NULL) {
    SetEntityRoutine(p, SolarBank_Update, SolarBank_Destroy);
    if (SolarBank_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
