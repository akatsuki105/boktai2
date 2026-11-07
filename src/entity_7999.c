#include "bg_pltt.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "magic.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// 通信対戦関連?
typedef struct Entity7999 {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  Tilemaps* tilemap;                           // 0x018, TILEMAP_CD91
  rgb555* bgp;                                 // 0x01C, bg_link_col_arr
  MainSprite sprites[5];                       // 0x020, FUN_081da468 が stride 0x60 で pos を書き換える5枚
  MainSpriteGfx gfxLink;                       // 0x200, SPRITE_UI_LINK
  MainSpriteGfx gfxIcon;                       // 0x220, SPRITE_INVENTORY_ICONS
  MainSpriteGfxFile* fileLink;                 // 0x240, SPRITE_UI_LINK
  MainSpriteGfxFile* fileIcon;                 // 0x244, SPRITE_INVENTORY_ICONS
  rgb555 savedPltt[16];                        // 0x248, _SavePltt が gObjPlttData + 0x2930 から16色コピーする
  u16 unk_268;                                 // 0x268, _SavePltt が 0 を入れる
  u8 unk_26a[2];                               // 0x26A, 読み手も書き手も見つかっていない, padding?
  void (*updateCallback)(struct Entity7999*);  // 0x26C, _Init で FUN_081da930
  u8* script;                                  // 0x270, '.s' の後の VM_GetPC_Proxy() の戻り値, NULL なら _Init が失敗する
  u32 flags;                                   // 0x274, _InitPanels が bit0 を立てる
  s32 windowID0;                               // 0x278, TextPanel_Create(18, 4, 10, 2)
  s32 windowID1;                               // 0x27C, TextPanel_Create(18, 8, 10, 2)
  s32 windowID2;                               // 0x280, TextPanel_Create(16, 12, 12, 2)
  u8 unk_284;                                  // 0x284, _Init が 0 を入れる
  u8 unk_285;                                  // 0x285, 読み手も書き手も見つかっていない
  u8 unk_286;                                  // 0x286, gEntity9A9F->self.unk_40[0] の写し, 0/1/2 で分岐する種別
  u8 unk_287;                                  // 0x287, 同 +0x41 の写し
  u8 unk_288;                                  // 0x288, 同 +0x42 の写し
  u8 unk_289;                                  // 0x289
  u8 unk_28a;                                  // 0x28A
  u8 unk_28b;                                  // 0x28B, 種別ごとに magicCount / 2 / 1 のどれかが入る
  u16 magicCount;                              // 0x28C, magicIDs に詰めた数
  u8 unk_28e[0x290 - 0x28E];                   // 0x28E, まだ未解析
  u8 magicIDs[0x298 - 0x290];                  // 0x290, 解放済みの魔法ID, u32_ARRAY_085ae144 から詰める
  u8 unk_298;                                  // 0x298, _Init が -1 を入れる
  u8 unk_299;                                  // 0x299, _Init が -1 を入れる
  u8 unk_29a;                                  // 0x29A, _Init が -1 を入れる
  u8 unk_29b;                                  // 0x29B, _Init が 0xFF を入れる
  u8 unk_29c;                                  // 0x29C, _Init が 1 を入れる
  u8 unk_29d;                                  // 0x29D, FUN_081da468 が添字として読む
  u16 state_29e;                               // 0x29E, FUN_081da890 が毎フレーム +1 し, 10 で終了処理へ入る
  u16 unk_2a0;                                 // 0x2A0, _Init が '.l' を入れる
  u16 unk_2a2;                                 // 0x2A2, _Init が '.e' を入れる
} Entity7999;
static_assert(sizeof(Entity7999) == 676);

void FUN_081df974(void);
bool32 FUN_081dfa04(void);

static void Entity7999_HidePanels(Entity7999* p);
static void Entity7999_HideSprites(Entity7999* p);
void FUN_081da0c4(Entity7999* p);
void FUN_081da930(Entity7999* p);
void FUN_081da218(Entity7999* p);
void FUN_081da814(Entity7999* p);
void FUN_081da69c(Entity7999* p);
void FUN_081da468(Entity7999* p);
void MainMenu_SetHudMode(s32 mode);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7);
void FUN_080e1238(s32 x, s32 y, s32 width, s32 height, u32 value, s32 bgIdx);

static inline bool8 Entity7999_IsUnk56Set(void) {
  if (gEntity9A9F != NULL && gEntity9A9F->unk_54[2] == 1) {
    return TRUE;
  }
  return FALSE;
}

const u32 u32_ARRAY_085ae144[7] = {0, 2, 3, 4, 5, 11, 13};  // 0x085AE144

// FUN_081d9da4 / FUN_081d9e50 / FUN_081da14c が引く
const u32 u32_ARRAY_085ae160[3] = {1, 16, 8};  // 0x085AE160

// FUN_081d9e50 / FUN_081da468 が引く
const s32 s32_ARRAY_085ae16c[3][6] = {
    {0, 0, 0, 32, 0,   64},
    {0, 0, 0, 32, -16, 64},
    {0, 0, 0, 32, 0,   64},
};  // 0x085AE16C

// gEntity9A9F->self の NULL 判定の形が未解決, Tier A の途中
NON_MATCH s32 FUN_081d9da4(Entity7999* p) {
#ifdef NONMATCHING_C
  Entity9A9F* e = gEntity9A9F;
  u8* out;
  const u32* table;

  if (e == NULL || &e->self == NULL) {
    return -1;
  }
  out = e->self.unk_40;
  out[0] = p->unk_286;
  e->self.unk_40[1] = p->unk_287;
  switch (out[0]) {
    case 0: {
      e->self.unk_40[2] = p->magicIDs[p->unk_288];
      break;
    }
    case 1: {
      table = u32_ARRAY_085ae160;
      e->self.unk_40[2] = table[p->unk_288];
      break;
    }
    case 2: {
      table = u32_ARRAY_085ae160 + 2;
      e->self.unk_40[2] = table[p->unk_288];
      break;
    }
    default: {
      e->self.unk_40[2] = p->magicIDs[0];
      break;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081d9da4.inc");
#endif
}

// 命令数は一致, 残差は magicIDs 走査の配置とレジスタ
NON_MATCH void FUN_081d9e50(Entity7999* p) {
#ifdef NONMATCHING_C
  s32 i;
  const u32* table;

  switch (p->unk_286) {
    case 0: {
      for (i = 0; i < p->magicCount; i++) {
        if (p->unk_288 == p->magicIDs[i]) {
          p->unk_288 = i;
          return;
        }
      }
      return;
    }
    case 1: {
      for (i = 0, table = u32_ARRAY_085ae160; i < 2; i++) {
        if (p->unk_288 == *table) {
          p->unk_288 = i;
          return;
        }
        table++;
      }
      return;
    }
    case 2: {
      for (i = 0, table = u32_ARRAY_085ae160 + 2; i < 1; i++) {
        if (p->unk_288 == *table) {
          p->unk_288 = i;
          return;
        }
        table++;
      }
      return;
    }
  }
  p->unk_288 = 0;
#else
  INCFUNC("asm/func/FUN_081d9e50.inc");
#endif
}

void FUN_081d9ef4(Entity7999* p) {
  Entity7999_HidePanels(p);
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(1);
  ClearBGTilemapBuffer(2);
  ClearBGTilemapBuffer(3);
  Marquee_Clear();
  Entity7999_HideSprites(p);
  if (p->unk_2a0 != 0) {
    VM_ExecByID(p->unk_2a0, 0);
    KillEntity((Entity*)p);
  }
}

void FUN_081d9f3c(Entity7999* p) {
  Marquee_CloseGlobal();
  Entity7999_HidePanels(p);
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(1);
  ClearBGTilemapBuffer(2);
  ClearBGTilemapBuffer(3);
  Entity7999_HideSprites(p);
  FUN_081df974();
  if (p->unk_2a2 != 0) {
    VM_ExecByID(p->unk_2a2, NULL);
    KillEntity((Entity*)p);
  }
}

void Entity7999_InitBG(Entity7999* p) {
  TilemapFile* f = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  s32 param;

  p->tilemap = f;
  param = 5;
  Video_SetupBGLayout(2, 0, f, 0, 0, 1, &param);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  p->bgp = GetBgPlttFile(0x26BB)->body;
  CpuCopy16(p->bgp, gBgPlttBuffer, 512);
  if (!Entity7999_IsUnk56Set()) {
    s32 i;

    for (i = 0; i < 5; i++) {
      FUN_080e1238(i + 25, 16, 1, 1, i + 22, 3);
    }
  }
}

// 解放済みの魔法だけを magicIDs に詰め直す
void FUN_081da038(Entity7999* p) {
  s32 count = 0;
  const u32* id = u32_ARRAY_085ae144;
  s32 i;

  for (i = 0; i < 7; id++, i++) {
    if (IsMagicUnlocked(*id)) {
      p->magicIDs[count] = *id;
      count++;
    }
  }
  p->magicCount = count;
}

// 種別ごとに unk_28b を決める
void FUN_081da074(Entity7999* p) {
  switch (p->unk_286) {
    case 0: {
      p->unk_28b = p->magicCount;
      break;
    }
    case 1: {
      p->unk_28b = 2;
      break;
    }
    case 2: {
      p->unk_28b = 1;
      break;
    }
  }
}

void FUN_081da0c4(Entity7999* p) {
  p->unk_29d = 0;
  p->unk_286 = 0;
  p->unk_287 = 0;
  p->unk_288 = 0;
  if (gStat->lap >= 1) {
    p->unk_289 = 3;
  } else if (*(s16*)&gStat->unk_232[6] != 0) {
    p->unk_289 = 2;
  } else {
    p->unk_289 = 1;
  }
  p->unk_28a = 4;
  FUN_081da038(p);
  FUN_081da074(p);
}

// 命令数は一致, 残差は id と id + 25 のレジスタ (r1, r4) だけ
NON_MATCH void FUN_081da14c(Entity7999* p) {
#ifdef NONMATCHING_C
  u32 id;
  const u32* table;

  switch (p->unk_29d) {
    case 0: {
      id = p->unk_286;
      break;
    }
    case 1: {
      id = p->unk_287 + 3;
      break;
    }
    case 2: {
      switch (p->unk_286) {
        case 0: {
          id = p->magicIDs[p->unk_288] + 7;
          break;
        }
        case 1: {
          table = u32_ARRAY_085ae160;
          id = table[p->unk_288] + 7;
          break;
        }
        case 2: {
          table = u32_ARRAY_085ae160 + 2;
          id = table[p->unk_288] + 7;
          break;
        }
        default: {
          id = 0;
          break;
        }
      }
      break;
    }
    default: {
      id = 0;
      break;
    }
  }
  if ((s8)p->unk_29b != id + 25) {
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + (id + 25)));
    p->unk_29b = id + 25;
  }
#else
  INCFUNC("asm/func/FUN_081da14c.inc");
#endif
}

void FUN_081da218(Entity7999* p) {
  u32 id;
  const u32* table;

  TextPanel_SetScript(p->windowID0, p->script);
  TextPanel_SetMessage(p->windowID0, p->unk_286);
  TextPanel_Start(p->windowID0);
  p->unk_298 = p->unk_286;
  TextPanel_SetScript(p->windowID1, p->script);
  TextPanel_SetMessage(p->windowID1, p->unk_287 + 3);
  TextPanel_Start(p->windowID1);
  p->unk_299 = p->unk_287;
  switch (p->unk_286) {
    case 0: {
      id = p->magicIDs[p->unk_288];
      break;
    }
    case 1: {
      table = u32_ARRAY_085ae160;
      id = table[p->unk_288];
      break;
    }
    case 2: {
      table = u32_ARRAY_085ae160 + 2;
      id = table[p->unk_288];
      break;
    }
    default: {
      id = 0;
      break;
    }
  }
  TextPanel_SetScript(p->windowID2, p->script);
  TextPanel_SetMessage(p->windowID2, id + 7);
  TextPanel_Start(p->windowID2);
  p->unk_29a = p->unk_288;
}

void Entity7999_InitPanels(Entity7999* p) {
  p->windowID0 = TextPanel_Create(18, 4, 10, 2);
  p->windowID1 = TextPanel_Create(18, 8, 10, 2);
  p->windowID2 = TextPanel_Create(16, 12, 12, 2);
  FUN_08049f5c();
  Marquee_Clear();
  SET_FLAGS(p->flags, 1);
  FUN_081da0c4(p);
}

static void Entity7999_HidePanels(Entity7999* p) {
  TextPanel_Hide(p->windowID0);
  TextPanel_Hide(p->windowID1);
  TextPanel_Hide(p->windowID2);
}

void Entity7999_InitSprites(Entity7999* p) {
  s32 i;

  p->fileLink = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  OpenMainSpriteFile(&p->gfxLink, p->fileLink);
  p->fileIcon = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  OpenMainSpriteFile(&p->gfxIcon, p->fileIcon);
  for (i = 0; i < 5; i++) {
    MainSpriteGfx* gfx;
    u16 poseIdx;

    switch (i) {
      case 0: {
        poseIdx = 0x33;
        gfx = &p->gfxLink;
        break;
      }
      case 1: {
        poseIdx = 0x34;
        gfx = &p->gfxLink;
        break;
      }
      case 2: {
        poseIdx = 0x35;
        gfx = &p->gfxLink;
        break;
      }
      case 3: {
        poseIdx = 0xB6;
        gfx = &p->gfxIcon;
        break;
      }
      case 4: {
        poseIdx = 0x15;
        gfx = &p->gfxLink;
        break;
      }
      default: {
        poseIdx = 0;
        gfx = &p->gfxIcon;
        break;
      }
    }
    MainSprite_Add(&p->sprites[i], gfx, poseIdx, SPRFLAG_SCREEN_COORD, 0, 0, 0, NULL);
  }
}

// 151/143 命令, case 1, 2 の後半を共有する形が未解決
NON_MATCH void FUN_081da468(Entity7999* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 5; i++) {
    switch (i) {
      case 0: {
        p->sprites[i].pos.x = s32_ARRAY_085ae16c[0][p->unk_29d * 2];
        p->sprites[i].pos.y = s32_ARRAY_085ae16c[0][p->unk_29d * 2 + 1];
        break;
      }
      case 1: {
        if ((p->unk_29d == 0 && p->unk_289 < 2) || (p->unk_29d == 2 && p->unk_28b < 2)) {
          p->sprites[i].flags |= SPRFLAG_HIDDEN;
        } else {
          p->sprites[i].pos.x = s32_ARRAY_085ae16c[1][p->unk_29d * 2];
          p->sprites[i].pos.y = s32_ARRAY_085ae16c[1][p->unk_29d * 2 + 1];
          p->sprites[i].flags &= ~SPRFLAG_HIDDEN;
        }
        break;
      }
      case 2: {
        if ((p->unk_29d == 0 && p->unk_289 < 2) || (p->unk_29d == 2 && p->unk_28b < 2)) {
          p->sprites[i].flags |= SPRFLAG_HIDDEN;
        } else {
          p->sprites[i].pos.x = s32_ARRAY_085ae16c[2][p->unk_29d * 2];
          p->sprites[i].pos.y = s32_ARRAY_085ae16c[2][p->unk_29d * 2 + 1];
          p->sprites[i].flags &= ~SPRFLAG_HIDDEN;
        }
        break;
      }
      case 3: {
        p->sprites[i].pos.x = 72;
        p->sprites[i].pos.y = 96;
        break;
      }
      case 4: {
        p->sprites[i].pos.x = 0;
        p->sprites[i].pos.y = 0;
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081da468.inc");
#endif
}

static void Entity7999_HideSprites(Entity7999* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Entity7999_RemoveSprites(Entity7999* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void Entity7999_SavePltt(Entity7999* p) {
  rgb555* src = &gObjPlttData[0x2930];
  s32 i;

  for (i = 0; i < 16; i++) {
    p->savedPltt[i] = src[i];
  }
  p->sprites[0].pltt = p->savedPltt;
  p->unk_268 = 0;
}

void FUN_081da64c(Entity7999* p) {
  rgb555 color;

  if (p->unk_268 < 10) {
    color = 31;
  } else if (p->unk_268 < 18) {
    color = 27;
  } else if (p->unk_268 < 26) {
    color = 18;
  } else if (p->unk_268 < 34) {
    color = 10;
  } else if (p->unk_268 < 42) {
    color = 18;
  } else {
    color = 27;
  }
  if (++p->unk_268 >= 50) {
    p->unk_268 = 0;
  }
  p->savedPltt[12] = color;
}

void FUN_081da69c(Entity7999* p) {
  u32 id;
  const u32* table;

  if (p->unk_288 == (s8)p->unk_29a) {
    return;
  }
  switch (p->unk_286) {
    case 0: {
      id = p->magicIDs[p->unk_288];
      break;
    }
    case 1: {
      table = u32_ARRAY_085ae160;
      id = table[p->unk_288];
      break;
    }
    case 2: {
      table = u32_ARRAY_085ae160 + 2;
      id = table[p->unk_288];
      break;
    }
    default: {
      id = 0;
      break;
    }
  }
  TextPanel_SetScript(p->windowID2, p->script);
  TextPanel_SetMessage(p->windowID2, id + 7);
  TextPanel_Start(p->windowID2);
  p->unk_29a = p->unk_288;
}

void FUN_081da730(Entity7999* p) {
  switch (p->unk_29d) {
    case 0: {
      if (p->unk_286 != (s8)p->unk_298) {
        TextPanel_SetScript(p->windowID0, p->script);
        TextPanel_SetMessage(p->windowID0, p->unk_286);
        TextPanel_Start(p->windowID0);
        p->unk_298 = p->unk_286;
        p->unk_29a = -1;
        p->unk_288 = 0;
        FUN_081da074(p);
        FUN_081da69c(p);
        FUN_081da814(p);
      }
      break;
    }
    case 1: {
      if (p->unk_287 != (s8)p->unk_299) {
        TextPanel_SetScript(p->windowID1, p->script);
        TextPanel_SetMessage(p->windowID1, p->unk_287 + 3);
        TextPanel_Start(p->windowID1);
        p->unk_299 = p->unk_287;
      }
      break;
    }
    case 2: {
      FUN_081da69c(p);
      break;
    }
  }
}

void FUN_081da814(Entity7999* p) {
  u32 id;
  const u32* table;

  switch (p->unk_286) {
    case 0: {
      id = p->magicIDs[p->unk_288];
      break;
    }
    case 1: {
      table = u32_ARRAY_085ae160;
      id = table[p->unk_288];
      break;
    }
    case 2: {
      table = u32_ARRAY_085ae160 + 2;
      id = table[p->unk_288];
      break;
    }
    default: {
      id = 0;
      break;
    }
  }
  id += 0xB6;
  MainSprite_LoadPose(&p->sprites[3], &p->gfxIcon, id);
}

void FUN_081da890(Entity7999* p) {
  if (p->unk_29c != 0) {
    p->state_29e = 0;
    p->unk_29c = 0;
  }

  if (p->state_29e == 10) {
    FUN_081d9da4(p);
    FUN_081d9ef4(p);
  }
  p->state_29e++;
}

void FUN_081da8d4(Entity7999* p) {
  if (p->unk_29c) {
    FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
    p->state_29e = 0;
    p->unk_29c = FALSE;
  }
  if (p->state_29e == 20) {
    FUN_081d9f3c(p);
  }
  p->state_29e++;
}

// 左右入力の switch の形が未解決, 下書き段階
NON_MATCH void FUN_081da930(Entity7999* p) {
#ifdef NONMATCHING_C
  u32 cursor;
  u32 keys;
  u8* entered = &p->unk_29c;
  u8* repeat;
  u32 wait;

  if (*entered != 0) {
    s32 id;

    Marquee_Clear();
    id = p->unk_286 + 25;
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + id));
    FUN_081da730(p);
    p->unk_29d = 0;
    p->state_29e = 0;
    *entered = 0;
  }

  if (p->state_29e < 30) {
    FUN_081da64c(p);
    FUN_081da14c(p);
    p->state_29e++;
    return;
  }

  cursor = p->unk_29d;
  repeat = &p->unk_285;
  keys = 0;
  if (gInput[0].pressed & DPAD_UP) {
    keys = 1;
  } else if (gInput[0].pressed & DPAD_DOWN) {
    keys = 2;
  } else if (gInput[0].pressed & DPAD_LEFT) {
    keys = 4;
  } else if (gInput[0].pressed & DPAD_RIGHT) {
    keys = 8;
  } else if (gInput[0].pressed & START_BUTTON) {
    keys = 32;
  } else if (gInput[0].pressed & B_BUTTON) {
    keys = 16;
  }

  wait = gInput[0].down & DPAD_ANY;
  if (wait != 0) {
    wait = *repeat;
    if (wait >= 12) {
      if (gInput[0].down & DPAD_UP) {
        keys |= 1;
      } else if (gInput[0].down & DPAD_DOWN) {
        keys |= 2;
      }
      if (gInput[0].down & DPAD_LEFT) {
        keys |= 4;
      } else if (gInput[0].down & DPAD_RIGHT) {
        keys |= 8;
      }
      wait = 0;
    } else {
      wait++;
    }
  }
  *repeat = wait;

  if (TEST_FLAGS(keys, 1)) {
    if (cursor == 0) {
      cursor = 2;
    } else {
      cursor--;
    }
    p->unk_285 = 0;
  } else if (TEST_FLAGS(keys, 2)) {
    if (cursor == 2) {
      cursor = 0;
    } else {
      cursor++;
    }
    p->unk_285 = 0;
  } else if (TEST_FLAGS(keys, 4)) {
    u32 prev;
    u32 next;

    switch (p->unk_29d) {
      case 0: {
        prev = p->unk_286;
        if (prev == 0) {
          next = p->unk_289 - 1;
        } else {
          next = prev - 1;
        }
        p->unk_286 = next;
        if (prev != next) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
        }
        break;
      }
      case 1: {
        prev = p->unk_287;
        if (prev == 0) {
          next = p->unk_28a - 1;
        } else {
          next = prev - 1;
        }
        p->unk_287 = next;
        if (prev != next) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
        }
        break;
      }
      case 2: {
        prev = p->unk_288;
        if (prev == 0) {
          next = p->unk_28b - 1;
        } else {
          next = prev - 1;
        }
        p->unk_288 = next;
        if (prev != next) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
        }
        FUN_081da814(p);
        break;
      }
    }
    FUN_081da730(p);
    p->unk_285 = 0;
  } else if (TEST_FLAGS(keys, 8)) {
    u32 prev;
    u32 next;

    switch (p->unk_29d) {
      case 0: {
        prev = p->unk_286;
        next = prev + 1;
        if (prev == p->unk_289 - 1) {
          next = 0;
        }
        p->unk_286 = next;
        if (prev != next) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
        }
        break;
      }
      case 1: {
        prev = p->unk_287;
        next = prev + 1;
        if (prev == p->unk_28a - 1) {
          next = 0;
        }
        p->unk_287 = next;
        if (prev != next) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
        }
        break;
      }
      case 2: {
        prev = p->unk_288;
        next = prev + 1;
        if (prev == p->unk_28b - 1) {
          next = 0;
        }
        p->unk_288 = next;
        if (prev != next) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
        }
        FUN_081da814(p);
        break;
      }
    }
    FUN_081da730(p);
    p->unk_285 = 0;
  } else if (TEST_FLAGS(keys, 32)) {
    p->updateCallback = FUN_081da890;
    p->unk_29c = 1;
    p->unk_284 = 2;
    PlaySound_082406e0(SE_SELECT);
    return;
  } else if (TEST_FLAGS(keys, 16) && !Entity7999_IsUnk56Set()) {
    p->updateCallback = FUN_081da8d4;
    p->unk_29c = 1;
    p->unk_284 = 1;
    PlaySound_082406e0(SE_CANCEL);
    return;
  }

  if (p->unk_29d != cursor) {
    p->unk_29d = cursor;
    FUN_081da468(p);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }
  FUN_081da64c(p);
  FUN_081da14c(p);
#else
  INCFUNC("asm/func/FUN_081da930.inc");
#endif
}

s32 Entity7999_Update(Entity7999* p) {
  if (!FUN_081dfa04()) {
    Marquee_CloseGlobal();
    Entity7999_HideSprites(p);
    KillEntity((Entity*)p);
    return -1;
  }

  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 Entity7999_Destroy(Entity7999* p) {
  Entity7999_RemoveSprites(p);
  Entity7999_HidePanels(p);
  return 1;
}

s32 Entity7999_Init(Entity7999* p) {
  Entity9A9FRecord* data;
  void (*update)(Entity7999*);

  if (VM_SeekToNamedArg('s')) {
    p->script = VM_GetPC_Proxy();
    if (p->script == NULL) {
      return -1;
    }
  }
  p->unk_2a0 = VM_GetNamedArgValue('l', 0);
  p->unk_2a2 = VM_GetNamedArgValue('e', 0);
  Entity7999_InitBG(p);
  Entity7999_InitPanels(p);
  Entity7999_InitSprites(p);
  FUN_081da468(p);
  Entity7999_SavePltt(p);
  p->unk_29b = -1;
  p->unk_298 = -1;
  p->unk_299 = -1;
  p->unk_29a = -1;
  update = FUN_081da930;
  p->updateCallback = update;
  p->unk_29c = TRUE;
  p->unk_284 = 0;
  if (VM_GetNamedArgValue('f', 0)) {
    FUN_0823ce68(2, 4, 4, 4, 4, 0xFFFF, 0);
  }
  MainMenu_SetHudMode(7);
  data = &gEntity9A9F->self;
  if (gEntity9A9F == NULL) {
    data = NULL;
  }
  p->unk_286 = data->unk_40[0];
  p->unk_287 = data->unk_40[1];
  p->unk_288 = data->unk_40[2];
  FUN_081d9e50(p);
  FUN_081da814(p);
  FUN_081da074(p);
  FUN_081da218(p);
  return 1;
}

Entity7999* Entity7999_Create(void) {
  Entity7999* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity7999));

  if (p != NULL) {
    SetEntityRoutine(p, Entity7999_Update, Entity7999_Destroy);
    if (Entity7999_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
