#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// 通信対戦の待合画面に並ぶプレイヤー1人分, players[0] が自分で players[1] が相手
typedef struct {
  bool8 nameShown;            // 0x000, name をテキストパネルに出していれば 1
  u8 unk_01[3];               // 0x001
  u32 unk_04;                 // 0x004, 名前を書き換えるときに 0 にされるだけで読み手がいない
  MainSpriteGfx portraitGfx;  // 0x008, SPRITE_PORTRAITS
  MainSprite portrait;        // 0x028, 顔グラ, 位置と pose は Unk085ab674_ARRAY_085ab674[idx]
  MainSprite digits[5];       // 0x088, 5桁の数字, 自分は FUN_0804e638 の値を x=24 に、相手は gname の後ろの u16 を x=136 に出す
  u8 name[16];                // 0x268, プレイヤー名, 自分は gStat->name, 相手は通信で受け取った名前
  u8 unk_278[4];              // 0x278
  u8 gname[24];               // 0x27C, players[1] だけが使う, 相手の RFU のゲームネーム
} CrossoverLobbyPlayer;
static_assert(sizeof(CrossoverLobbyPlayer) == 660);

// クロスオーバー: ロックマンエグゼ5との通信対戦
// 詳細は http://sunmiguere.web.fc2.com/zoktai_crossover_battle.html を参照
typedef struct {
  Entity e;                         // 0x000, ENTITY_UNK_11
  u8 linkState;                     // 0x018, 前フレームの RfuSession_GetState の値, 変わったときだけ state を切り替える
  u8 state;                         // 0x019, sCrossoverLobbyUpdates の添字, 7 は終了
  bool8 stateEntered;               // 0x01A, state を変えた直後の1フレームだけ 1
  u8 unk_1b;                        // 0x01B, padding?
  u8 connectSlot;                   // 0x01C, 前フレームの FUN_0804e474 の値, 0xFF にすると次のフレームで表示を作り直す
  u8 unk_1d[3];                     // 0x01D, padding?
  u32 stateTimer;                   // 0x020, state を変えると 0 に戻り毎フレーム +1
  TilemapFile* tilemap;             // 0x024, TILEMAP_CD91
  u8* script;                       // 0x028, '.s', テキストパネルのメッセージ元
  CrossoverLobbyPlayer players[2];  // 0x02C
  s32 textPanels[3];                // 0x554, [0] と [1] は players[i].name, [2] は案内メッセージ
  s32 scriptID;                     // 0x560, '.r', 終了時に実行する
  u8 nameBuf[16];                   // 0x564, 受け取った相手の名前を変換する前に置く作業用
  u8 unk_574[240];                  // 0x574
  MainSpriteGfx gfx;                // 0x664, SPRITE_UI_START_MENU, 数字を描くのに使う
} CrossoverLobby;
static_assert(sizeof(CrossoverLobby) == 1668);

extern u8 gCrossoverPlayerNames[2][16];
bool32 FUN_0804e59c(void);
u8* GetCrossoverPlayerName(s32 idx);
void FUN_0804e4c4(void);
void FUN_0804e4ac(void);
s32 FUN_0804e458(void);
s32 RfuSession_GetState(void);
u8* FUN_0804e438(void);
s32 FUN_0804e638(void);
void SignalStrengthIcon_CreateAt(s32 x, s32 y);
void Crossover_DecodeText(u8* src, u8* dst, s32 count);
void FUN_0804e5e8(void);
void FUN_0804e604(void);
void* FUN_0804ba3c(void);

static inline void CrossoverLobby_SetState(CrossoverLobby* p, u8 state) {
  p->state = state;
  p->stateEntered = TRUE;
  p->stateTimer = 0;
}
s32 FUN_0804e474(void);

typedef struct {
  SpriteID16 id;  // 0x0
  u16 poseIdx;    // 0x2
  u8 flags;       // 0x4, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN に足すスプライトフラグ
  u8 x;           // 0x5, 画面座標
  u8 y;           // 0x6, 画面座標
} Unk085ab674;

// 待合画面の BG1 と BG パレットを読み込む
void CrossoverLobby_LoadBG(CrossoverLobby* p, s32 bgIndex) {
  BgPlttFile* f;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  f = GetBgPlttFile(BGP_LINK);
  CpuCopy16(f->body, gBgPlttBuffer, sizeof(f->body));
}

s32 CrossoverLobby_InitPlayer(CrossoverLobby* p, CrossoverLobbyPlayer* player, s32 idx) {
  static const Unk085ab674 Unk085ab674_ARRAY_085ab674[2] = {
      {id : SPRITE_PORTRAITS, poseIdx : PORTRAIT_RDJANGO, flags : 0,             x : 48,  y : 32},
      {id : SPRITE_PORTRAITS, poseIdx : PORTRAIT_ROCKMAN, flags : SPRFLAG_XFLIP, x : 192, y : 32}
  };  // 0x085AB674

  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, Unk085ab674_ARRAY_085ab674[idx].id);
  Vec3 pos;
  s32 i;

  if (f == NULL) {
    return -1;
  }
  player->portraitGfx = *f;
  OpenMainSpriteFile(&player->portraitGfx, f);
  VEC3_SET(pos, Unk085ab674_ARRAY_085ab674[idx].x, Unk085ab674_ARRAY_085ab674[idx].y, 0);
  MainSprite_Add(&player->portrait, &player->portraitGfx, Unk085ab674_ARRAY_085ab674[idx].poseIdx, Unk085ab674_ARRAY_085ab674[idx].flags | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 1, 0, 60, &pos);
  for (i = 0; i < 5; i++) {
    MainSprite_Add(&player->digits[i], &p->gfx, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 1, 0, 60, NULL);
  }
  player->nameShown = FALSE;
  player->name[0] = 0;
  player->gname[0] = 0;
  return 0;
}

void CrossoverLobby_DestroyPlayer(CrossoverLobby* p, CrossoverLobbyPlayer* player, s32 idx) {
  s32 i;

  MainSprite_Remove(&player->portrait);
  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&player->digits[i]);
  }
}

// 残差はレジスタだけ, 原典は p を使わないのに r0 を避けて r2/r3 で読み書きする, インライン MainSprite_Show/Hide や SET_FLAGS/CLEAR_FLAGS も試済
NON_MATCH void CrossoverLobby_ShowPortrait(CrossoverLobby* p, CrossoverLobbyPlayer* player) {
#ifdef NONMATCHING_C
  player->portrait.flags &= ~SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/CrossoverLobby_ShowPortrait.inc");
#endif
}

// 残差はレジスタだけ, 原典は p を使わないのに r0 を避けて r2/r3 で読み書きする, インライン MainSprite_Show/Hide や SET_FLAGS/CLEAR_FLAGS も試済
NON_MATCH void CrossoverLobby_HidePortrait(CrossoverLobby* p, CrossoverLobbyPlayer* player) {
#ifdef NONMATCHING_C
  player->portrait.flags |= SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/CrossoverLobby_HidePortrait.inc");
#endif
}

s32 CrossoverLobby_SetPlayerName(CrossoverLobby* p, CrossoverLobbyPlayer* player, s32 idx, s32 n, u8* data) {
  u8* dst = GetCrossoverPlayerName(idx);

  player->unk_04 = 0;
  CpuFill32(0, p->nameBuf, 4);
  CopyMemory(p->nameBuf, &data[n * 10 + 4], sizeof(p->nameBuf));
  Crossover_DecodeText(p->nameBuf, player->name, 8);
  CopyMemory(dst, player->name, sizeof(player->name));
  TextPanel_SetMessage(p->textPanels[idx], idx + 3);
}

s32 CrossoverLobby_ClearPlayerName(CrossoverLobby* p, CrossoverLobbyPlayer* player, s32 idx) {
  u8* dst = GetCrossoverPlayerName(idx);
  s32 i;

  player->unk_04 = 0;
  for (i = 0; i < 16; i++) {
    player->name[i] = 0;
  }
  CopyMemory(dst, player->name, sizeof(player->name));
  TextPanel_SetMessage(p->textPanels[idx], idx + 3);
}

// 接続中の子機のうち最初のものを 1 始まりで返す, 誰もいなければ 0
s32 GetFirstConnectedSlot(u8* data) {
  s32 slots = FUN_0804e474();
  s32 i;

  for (i = 0; i < 4; i++) {
    if ((slots >> i) & 1) {
      return i + 1;
    }
  }
  return 0;
}

void CrossoverLobby_UpdatePlayer(CrossoverLobby* p, CrossoverLobbyPlayer* player, s32 idx) {
  u8* data = FUN_0804e438();
  s32 slot;

  if (idx == 0) {
    MainSprite_SetNumber(player->digits, &p->gfx, FUN_0804e638(), 5, 0, 24, 70, 8, FALSE);
    CrossoverLobby_ShowPortrait(p, player);
  } else if (FUN_0804e474() != 0) {
    CrossoverLobby_ShowPortrait(p, player);
  } else {
    CrossoverLobby_HidePortrait(p, player);
  }

  if (data == NULL) {
    return;
  }

  slot = GetFirstConnectedSlot(data);
  if (idx == 0) {
    u8* dst;

    if (player->nameShown) {
      return;
    }
    dst = GetCrossoverPlayerName(0);
    CpuFill32(0, p->nameBuf, 4);
    CopyMemory(dst, gStat->name, sizeof(gStat->name));
    CopyMemory(player->name, gStat->name, sizeof(gStat->name));
    TextPanel_SetMessage(p->textPanels[0], 3);
    player->nameShown = TRUE;
  } else if (slot != 0) {
    if (player->nameShown) {
      return;
    }
    CrossoverLobby_SetPlayerName(p, player, idx, slot, data);
    player->nameShown = TRUE;
  } else {
    if (!player->nameShown) {
      return;
    }
    CrossoverLobby_ClearPlayerName(p, player, idx);
    player->nameShown = FALSE;
  }
}

void FUN_0804f16c(CrossoverLobby* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }
  if (p->stateTimer > 15) {
    if (FUN_0804e458()) {
      if (gInput[0].pressed & B_BUTTON) {
        FUN_0804e4c4();
        CrossoverLobby_SetState(p, 7);
      }
    } else {
      if (gInput[0].pressed & L_BUTTON) {
        FUN_0804e4c4();
        CrossoverLobby_SetState(p, 7);
      }
    }
  }
  p->stateTimer++;
}

void FUN_0804f1d8(CrossoverLobby* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
    TextPanel_SetMessage(p->textPanels[2], 2);
    PlaySound_082406e0(SE_NG);
  }
  if (p->stateTimer > 35 && (gInput[0].pressed & (A_BUTTON | B_BUTTON))) {
    FUN_0804e4c4();
    CrossoverLobby_SetState(p, 7);
  }
  p->stateTimer++;
}

// 残差5命令 (179/184), 原典は相手スロットの探索ループの前で players[1] の gname/digits を作り, ループ後に &players[1] を作り直す
// partner ローカルの有無, while 形のループ, 数字の表示切替 inline を試済
NON_MATCH void FUN_0804f230(CrossoverLobby* p) {
#ifdef NONMATCHING_C
  u8 slots = FUN_0804e474();

  if (p->stateEntered) {
    p->stateEntered = FALSE;
    TextPanel_SetMessage(p->textPanels[2], 7);
    p->connectSlot = 0xFF;
  }
  if (slots != p->connectSlot) {
    CrossoverLobbyPlayer* partner = &p->players[1];
    s32 i;

    if (slots != 0 && slots == gRfuLinkStatus->connectSlot_flag) {
      if (FUN_0804e438() != NULL) {
        u8* name = p->players[1].gname;
        MainSprite* digits = p->players[1].digits;
        u8* gname;

        for (i = 0; i < 4; i++) {
          if ((gRfuLinkStatus->connectSlot_flag >> i) & 1) {
            break;
          }
        }
        ClearMemory(name, sizeof(p->players[1].gname));
        Crossover_DecodeText(gRfuLinkStatus->partner[i].gname, name, 11);
        gname = gRfuLinkStatus->partner[i].gname;
        MainSprite_SetNumber(digits, &p->gfx, gname[11] | (gname[12] << 8), 5, 0, 136, 70, 8, FALSE);
        for (i = 0; i < 5; i++) {
          p->players[1].digits[i].flags &= ~SPRFLAG_HIDDEN;
        }
        FUN_0804a40c(p->textPanels[2], 2, partner->gname);
        PlaySound_082406e0(SONG_495);
      }
      TextPanel_SetMessage(p->textPanels[2], 8);
    } else {
      TextPanel_SetMessage(p->textPanels[2], 7);
      for (i = 0; i < 5; i++) {
        partner->digits[i].flags |= SPRFLAG_HIDDEN;
      }
    }
    p->connectSlot = slots;
  }
  if ((gInput[0].pressed & A_BUTTON) && slots != 0) {
    FUN_0804e4c4();
  }
  if (gInput[0].pressed & B_BUTTON) {
    if (slots != 0) {
      FUN_0804e4ac();
    } else {
      FUN_0804e4c4();
      CrossoverLobby_SetState(p, 7);
    }
  }
  p->stateTimer++;
#else
  INCFUNC("asm/func/FUN_0804f230.inc");
#endif
}

void FUN_0804f3d8(CrossoverLobby* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
    TextPanel_SetMessage(p->textPanels[2], 9);
  }
  p->stateTimer++;
}

void FUN_0804f404(CrossoverLobby* p) {
  if (p->stateEntered) {
    s32 i;

    p->stateEntered = FALSE;
    TextPanel_SetMessage(p->textPanels[2], 6);
    for (i = 0; i < 5; i++) {
      p->players[1].digits[i].flags |= SPRFLAG_HIDDEN;
    }
  }
  p->stateTimer++;
}

void FUN_0804f448(CrossoverLobby* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
    TextPanel_SetMessage(p->textPanels[2], 0);
    PlaySound_082406e0(SE_NG);
  }
  p->stateTimer++;
}

void FUN_0804f47c(CrossoverLobby* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
    TextPanel_SetMessage(p->textPanels[2], 1);
    PlaySound_082406e0(SE_NG);
  }
  p->stateTimer++;
}

// 終了状態, キャンセル音を鳴らして後始末を進め, 24 フレーム後から '.r' のスクリプトへ移る
void CrossoverLobby_StateExit(CrossoverLobby* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
    PlaySound_082406e0(SE_CANCEL);
    FUN_0804e5e8();
  }
  if (p->stateTimer == 4) {
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
  }
  if (p->stateTimer == 24) {
    FUN_0804e604();
  }
  if (p->stateTimer >= 24 && FUN_0804ba3c() == NULL && p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
  p->stateTimer++;
}

// 通信の状態が変わったら, それに対応する state へ切り替える
void CrossoverLobby_SyncLinkState(CrossoverLobby* p) {
  s32 linkState = RfuSession_GetState();

  if (p->state == 7) {
    return;
  }
  if (linkState != p->linkState) {
    switch (linkState) {
      case 27: {
        CrossoverLobby_SetState(p, 1);
        break;
      }
      case 7: {
        CrossoverLobby_SetState(p, 2);
        break;
      }
      case 9: {
        CrossoverLobby_SetState(p, 3);
        break;
      }
      case 11: {
        CrossoverLobby_SetState(p, 4);
        break;
      }
      case 28: {
        CrossoverLobby_SetState(p, 5);
        break;
      }
      case 29: {
        CrossoverLobby_SetState(p, 6);
        break;
      }
    }
  }
  p->linkState = linkState;
}

s32 CrossoverLobby_Update(CrossoverLobby* p) {
  static void (*const sCrossoverLobbyUpdates[8])(CrossoverLobby*) = {
      FUN_0804f16c,
      FUN_0804f1d8,
      FUN_0804f230,
      FUN_0804f3d8,
      FUN_0804f404,
      FUN_0804f448,
      FUN_0804f47c,
      CrossoverLobby_StateExit,
  };  // 0x085AB684

  if (!FUN_0804e59c()) {
    CrossoverLobbyPlayer* player;
    s32 i;

    CrossoverLobby_SyncLinkState(p);
    sCrossoverLobbyUpdates[p->state](p);
    player = p->players;
    for (i = 0; i < 2; i++, player++) {
      CrossoverLobby_UpdatePlayer(p, player, i);
    }
  }
  return 0;
}

s32 CrossoverLobby_Destroy(CrossoverLobby* p) {
  CrossoverLobbyPlayer* player = p->players;
  s32 i;

  for (i = 0; i < 2; i++, player++) {
    CrossoverLobby_DestroyPlayer(p, player, i);
  }
  for (i = 0; i < 3; i++) {
    TextPanel_Destroy(p->textPanels[i]);
  }
  return 0;
}

s32 CrossoverLobby_Init(CrossoverLobby* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  CrossoverLobbyPlayer* player;
  s32* panel;
  s32 i;

  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  if (!VM_SeekToNamedArg('s')) {
    return -1;
  }
  p->script = VM_GetPC_Proxy();
  if (p->script == NULL) {
    return -1;
  }
  p->scriptID = VM_GetNamedArgValue('r', 0);
  CrossoverLobby_SetState(p, 0);
  CrossoverLobby_LoadBG(p, 11);

  player = p->players;
  for (i = 0; i < 2; i++, player++) {
    if (CrossoverLobby_InitPlayer(p, player, i) < 0) {
      return -1;
    }
  }

  panel = &p->textPanels[0];
  *panel = TextPanel_Create(3, 10, 10, 2);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  FUN_0804a40c(*panel, 0, p->players[0].name);
  TextPanel_SetMessage(*panel, 3);
  TextPanel_Start(*panel);

  panel = &p->textPanels[1];
  *panel = TextPanel_Create(17, 10, 10, 2);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  FUN_0804a40c(*panel, 1, p->players[1].name);
  TextPanel_SetMessage(*panel, 4);
  TextPanel_Start(*panel);

  panel = &p->textPanels[2];
  *panel = TextPanel_Create(0, 14, 30, 6);
  if (*panel < 0) {
    return -1;
  }
  TextPanel_SetScript(*panel, p->script);
  TextPanel_SetMessage(*panel, 7);
  TextPanel_Start(*panel);

  SignalStrengthIcon_CreateAt(0, 24);
  StartBgObjPlttFade(2, 4, 4, 4, 4, 0xFFFF, 0);
  return 0;
}

CrossoverLobby* CrossoverLobby_Create(void) {
  CrossoverLobby* p = CreateEntity(ENTITY_UNK_11, sizeof(CrossoverLobby));

  if (p != NULL) {
    SetEntityRoutine(p, CrossoverLobby_Update, CrossoverLobby_Destroy);
    if (CrossoverLobby_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

u8* GetCrossoverPlayerName(s32 idx) { return gCrossoverPlayerNames[idx]; }
