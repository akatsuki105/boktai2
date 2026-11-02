#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

typedef u32 GameResultFlags;
#define GRF_UNK_0 (1 << 0)  // 0x1, unk_4c を止める
#define GRF_UNK_1 (1 << 1)  // 0x2, unk_54 を止める

// ゲームクリア時のリザルト画面
// なんか GameResultFlags とかが TitleFlags と似てるし、 他にも Title との共通点がある気がする...
typedef struct GameResult {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx;                           // 0x018, SPRITE_42E2
  Tilemaps* tilemap;                           // 0x038, TILEMAP_33B2
  rgb555* pltt;                                // 0x03C, BGP_E9C3
  GameResultFlags unk_40;                      // 0x040, なんかのbitfield?
  u32 scriptID_44;                             // 0x044, 0x08222954
  s32 unk_48;                                  // 0x048, sUpdates の idx (このゲームでは常に 0)
  s32 unk_4c;                                  // 0x04C
  s32 unk_50;                                  // 0x050
  s32 unk_54;                                  // 0x054
  s32 unk_58;                                  // 0x058
  u8 unk_5c[8];                                // 0x05C
  char timeText[9];                            // 0x064, "HH:MM:SS"
  char sunText[11];                            // 0x06D, 今まで浴びた太陽, カンマ区切りで右詰め
  MainSprite sprites[8];                       // 0x078, 0x082226a6 で 8回ループ処理してるので長さは8
  bool32 unk_378;                              // 0x378
  void (*updateCallback)(struct GameResult*);  // 0x37C
} GameResult;
static_assert(sizeof(GameResult) == 896);

const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_08252894[8] = {144, 152, 168, 176, 184, 200, 208, 216};

const __attribute__((section(".rodata.faraddr"))) char s_RED_0825289c[3][6] = {"  RED", "BLACK", " GRAY"};
const __attribute__((section(".rodata.faraddr"))) char s_STYLE_082528ae[6][9] = {"   SWORD", "   SPEAR", "  HAMMER", "    FIST", "     GUN", "NO STYLE"};
const __attribute__((section(".rodata.faraddr"))) char s_PUSH_A_BUTTON_082528e4[] = "PUSH A BUTTON";

// 8枚のスプライトを横一列に並べて隠しておく
NON_MATCH void FUN_08222270(GameResult* p) {
#ifdef NONMATCHING_C
  u8 xs[8] = {0x90, 0x98, 0xA8, 0xB0, 0xB8, 0xC8, 0xD0, 0xD8};
  Vec3 pos;
  MainSprite* spr;
  s32 i;

  pos.y = 56, pos.z = 0;
  spr = p->sprites;
  for (i = 0; i < 8; spr++, i++) {
    pos.x = xs[i];
    MainSprite_Add(spr, &p->gfx, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
    spr->flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_08222270.inc");
#endif
}

void FUN_082222f0(GameResult* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void FUN_0822230c(GameResult* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_SetFlags(&p->sprites[i], SPRFLAG_HIDDEN);
  }
}

s32 UpdateSolDarkSide(void);
s32 UpdateWeaponStyle(void);
bool32 FUN_0821b21c(s32* p, s32 val1, s32 val2, u16 val3);

// 681/705 命令, 下書き段階, r10 まで使う局所の持ち方が違う
NON_MATCH static void _GameResult_Update(GameResult* p) {
#ifdef NONMATCHING_C
  char sides[3][6];
  char styles[6][9];
  char push[14];
  char text[9];
  char sun[11];

  memcpy(sides, s_RED_0825289c, sizeof(sides));
  memcpy(styles, s_STYLE_082528ae, sizeof(styles));
  memcpy(push, s_PUSH_A_BUTTON_082528e4, sizeof(push));

  if (p->unk_40 & GRF_UNK_0) {
    p->unk_40 &= ~GRF_UNK_0;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    Video_SetBGLayer(2, p->tilemap, 11);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_58 = 11;
    UpdateSolDarkSide();
    UpdateWeaponStyle();
  } else {
    p->unk_40 &= ~GRF_UNK_0;
  }

  switch (p->unk_50) {
    case 0: {
      p->unk_40 &= ~GRF_UNK_1;
      if (FUN_0821b21c((s32*)p->unk_5c, 0, 60, 0xFFFF)) {
        p->unk_50 = 1;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 1: {
      bool32 first = p->unk_40 & GRF_UNK_1;

      p->unk_40 &= ~GRF_UNK_1;
      if (first) {
        p->unk_378 = FALSE;
      }
      text[5] = ':';
      text[2] = ':';
      if (p->unk_54 < 60) {
        text[0] = Mod(Random(), 10) + '0';
        text[1] = Mod(Random(), 10) + '0';
      } else {
        text[0] = p->timeText[0];
        text[1] = p->timeText[1];
      }
      if (p->unk_54 < 105) {
        text[3] = Mod(Random(), 10) + '0';
        text[4] = Mod(Random(), 10) + '0';
      } else {
        text[3] = p->timeText[3];
        text[4] = p->timeText[4];
      }
      if (p->unk_54 < 150) {
        text[6] = Mod(Random(), 10) + '0';
        text[7] = Mod(Random(), 10) + '0';
        if (p->unk_54 & 1) {
          PlaySound_082406e0(SE_627);
        }
      } else {
        text[6] = p->timeText[6];
        text[7] = p->timeText[7];
        if (!p->unk_378) {
          PlaySound_082406e0(SE_LINK_359);
          p->unk_378 = TRUE;
        }
      }
      text[8] = '\0';
      Video_ClearTextRect(20, 4, 8, 2);
      Video_DrawText(20, 4, text);
      if (p->unk_54 >= 211 || (gInput[0].pressed & A_BUTTON)) {
        if (!p->unk_378) {
          PlaySound_082406e0(SE_LINK_359);
          p->unk_378 = TRUE;
        }
        p->unk_50 = 2;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 2: {
      bool32 first = p->unk_40 & GRF_UNK_1;

      p->unk_40 &= ~GRF_UNK_1;
      if (first) {
        Video_ClearTextRect(20, 4, 8, 2);
        Video_DrawText(20, 4, p->timeText);
        p->unk_378 = FALSE;
        sun[0] = ' ';
        sun[1] = ' ';
        sun[2] = ',';
        sun[3] = ' ';
        sun[4] = ' ';
        sun[5] = ' ';
        sun[6] = ',';
        sun[7] = ' ';
        sun[8] = ' ';
        sun[9] = ' ';
        sun[10] = '\0';
        Video_ClearTextRect(18, 7, 10, 2);
        Video_DrawText(18, 7, sun);
      }
      if (p->unk_54 < 60) {
        MainSprite* sprite = p->sprites;
        s32 i;

        for (i = 0; i < 8; i++) {
          MainSprite_SetPose(sprite, &p->gfx, Mod(Random(), 10), PLAYMODE_LOOP);
          sprite->flags &= ~SPRFLAG_HIDDEN;
          sprite++;
        }
        if (p->unk_54 & 1) {
          PlaySound_082406e0(SE_627);
        }
      } else {
        FUN_0822230c(p);
        Video_ClearTextRect(18, 7, 10, 2);
        Video_DrawText(18, 7, p->sunText);
        if (!p->unk_378) {
          PlaySound_082406e0(SE_LINK_359);
          p->unk_378 = TRUE;
        }
        p->unk_50 = 3;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      if (gInput[0].pressed & A_BUTTON) {
        if (!p->unk_378) {
          PlaySound_082406e0(SE_LINK_359);
          p->unk_378 = TRUE;
        }
        p->unk_50 = 3;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 3: {
      bool32 first = p->unk_40 & GRF_UNK_1;

      p->unk_40 &= ~GRF_UNK_1;
      if (first) {
        FUN_0822230c(p);
        Video_ClearTextRect(18, 7, 10, 2);
        Video_DrawText(18, 7, p->sunText);
      }
      if (p->unk_54 >= 61 || (gInput[0].pressed & A_BUTTON)) {
        Video_ClearTextRect(23, 10, 5, 2);
        Video_DrawText(23, 10, sides[gStat->side]);
        PlaySound_082406e0(SE_LINK_359);
        p->unk_50 = 4;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 4: {
      p->unk_40 &= ~GRF_UNK_1;
      if (p->unk_54 >= 61 || (gInput[0].pressed & A_BUTTON)) {
        Video_ClearTextRect(20, 13, 8, 2);
        Video_DrawText(20, 13, styles[gStat->style]);
        PlaySound_082406e0(SE_LINK_359);
        p->unk_50 = 5;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 5: {
      p->unk_40 &= ~GRF_UNK_1;
      if (p->unk_54 >= 61) {
        Video_DrawText(9, 16, push);
        p->unk_50 = 6;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 6: {
      p->unk_40 &= ~GRF_UNK_1;
      if (Mod(p->unk_54, 30) == 0) {
        if (Div(p->unk_54, 30) & 1) {
          Video_ClearTextRect(9, 16, 15, 2);
        } else {
          Video_ClearTextRect(9, 16, 15, 2);
          Video_DrawText(9, 16, push);
        }
      }
      if (gInput[0].pressed & A_BUTTON) {
        PlaySound_082406e0(SE_SELECT);
        p->unk_50 = 7;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 7: {
      p->unk_40 &= ~GRF_UNK_1;
      if (FUN_0821b21c((s32*)p->unk_5c, 1, 60, 0xFFFF)) {
        p->unk_50 = 99;
        p->unk_54 = 0;
        SET_FLAGS(p->unk_40, GRF_UNK_1);
      }
      break;
    }
    case 99: {
      p->unk_40 &= ~GRF_UNK_1;
      if (p->unk_54 >= 31) {
        VM_ExecByID(p->scriptID_44, NULL);
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        ClearBGTilemapBuffer(2);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        ClearBGTilemapBuffer(3);
        Video_GenerateBGMap(3, 0, 0, 0, 0);
        KillEntity(&p->e);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/_GameResult_Update.inc");
#endif
}

// BG11 にリザルト画面のタイルマップを敷く
void FUN_082229ac(GameResult* p) {
  s32 bgIndices[1];
  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_33B2);
  bgIndices[0] = 11;
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, bgIndices);
}

// 背景パレットを読み込んで作業用バッファへ流す
void FUN_082229e8(GameResult* p) {
  p->pltt = GetBgPlttFile(BGP_E9C3)->body;
  CpuCopy32(p->pltt, gBgPlttBuffer, 80 * sizeof(rgb555));
}

// リザルト画面のスプライトファイルを開く
void FUN_08222a18(GameResult* p) {
  MainSpriteGfxFile* file = GetFile(DIR_MAIN_SPRITE, SPRITE_42E2);

  p->gfx = *(MainSpriteGfx*)file;
  OpenMainSpriteFile(&p->gfx, file);
  FUN_08222270(p);
}

void FUN_08222a54(GameResult* p, s32 idx) {
  static void (*const sUpdates[1])(GameResult*) = {
      _GameResult_Update,
  };  // 0x085B0080

  p->unk_48 = idx;
  p->unk_4c = 0;
  p->updateCallback = sUpdates[idx];
  SET_FLAGS(p->unk_40, GRF_UNK_0);
  p->unk_50 = 0;
  p->unk_54 = 0;
  SET_FLAGS(p->unk_40, GRF_UNK_1);
}

s32 GameResult_Update(GameResult* p) {
  if (!(p->unk_40 & GRF_UNK_0)) p->unk_4c++;
  if (!(p->unk_40 & GRF_UNK_1)) p->unk_54++;
  p->updateCallback(p);  // このゲームでは常に _GameResult_Update
  return 0;
}

s32 GameResult_Destroy(GameResult* p) {
  FUN_082222f0(p);
  return 0;
}

// 198/199 命令, 除算の結果を局所に受ける形と sunText の終端の持ち方が合わない
NON_MATCH s32 GameResult_Init(GameResult* p) {
#ifdef NONMATCHING_C
  s32 hours;
  s32 minutes;
  s32 seconds;
  s32 sun;
  s32 i;
  char* c;

  if (VM_SeekToNamedArg('e')) {
    p->scriptID_44 = VM_GetValue();
  }
  p->unk_40 = 0;
  p->unk_48 = 0;
  p->unk_4c = 0;
  p->unk_50 = 0;
  p->unk_54 = 0;
  p->unk_58 = -1;
  FUN_082229ac(p);
  FUN_082229e8(p);
  FUN_08222a18(p);

  hours = Div(gStat->playTime, 216000);
  minutes = Div(gStat->playTime, 3600) - hours * 60;
  seconds = Div(gStat->playTime, 60) - hours * 3600 - minutes * 60;
  if (hours >= 100) {
    p->timeText[0] = '9';
    p->timeText[1] = '9';
    p->timeText[3] = '5';
    p->timeText[4] = '9';
    p->timeText[6] = '5';
    p->timeText[7] = '9';
  } else {
    p->timeText[1] = Mod(hours, 10) + '0';
    p->timeText[0] = Mod(Div(hours, 10), 10) + '0';
    p->timeText[4] = Mod(minutes, 10) + '0';
    p->timeText[3] = Mod(Div(minutes, 10), 10) + '0';
    p->timeText[7] = Mod(seconds, 10) + '0';
    p->timeText[6] = Mod(Div(seconds, 10), 10) + '0';
  }
  p->timeText[5] = ':';
  p->timeText[2] = ':';
  p->timeText[8] = '\0';

  sun = gStat->treeExp;
  if (sun > 99999999) {
    sun = 99999999;
  }
  c = &p->sunText[9];
  for (i = 9; i >= 0; i--) {
    if (sun == 0) {
      if (i == 9) {
        p->sunText[9] = '0';
      } else {
        *c = ' ';
      }
    } else if (i == 2 || i == 6) {
      *c = ',';
    } else {
      *c = Mod(sun, 10) + '0';
      sun = Div(sun, 10);
    }
    c--;
  }
  p->sunText[10] = '\0';
  FUN_08222a54(p, 0);
  return 0;
#else
  INCFUNC("asm/func/GameResult_Init.inc");
#endif
}

GameResult* GameResult_Create(void) {
  GameResult* p = CreateEntity(ENTITY_UNK_11, sizeof(GameResult));

  if (p != NULL) {
    SetEntityRoutine(p, GameResult_Update, GameResult_Destroy);
    if (GameResult_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
