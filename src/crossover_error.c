#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "menu.h"
#include "sound.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// クロスオーバーの通信エラー画面
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_12
  u8 state;           // 0x18, sCrossoverErrorUpdates[state]
  bool8 stateBegun;   // 0x19, state が変わるたび 1, 各ハンドラが最初のフレームで 0 に戻す
  u8 unk_1a[2];       // 0x1A, padding?
  u32 timer;          // 0x1C, 毎フレーム +1、state が変わると 0
  s32 windowID;       // 0x20, TextPanel_Create の戻り値, なければ -1, _Destroy が TextPanel_Destroy に渡して解放する
  Tilemaps* tilemap;  // 0x24, TILEMAP_A413 or TILEMAP_CD91
  u8* msgPc;          // 0x28, _Init 時点の VM_GetPC(), TextPanel_SetScript(windowID, msgPc) に渡す
  s32 scriptID;       // 0x2C, '.r=0', state 3 が VM_ExecByID に渡す
} CrossoverError;
static_assert(sizeof(CrossoverError) == 48);

static CrossoverError* sCrossoverError;  // 0x030000E8

void MosaicFader_Stop(void);
s32 FUN_0804e59c(void);
void FUN_0804e5bc(void);
void FUN_0804e5e8(void);
void FUN_0804e604(void);
void* FUN_0804ba3c(void);

static inline void CrossoverError_SetState(CrossoverError* p, u8 state) {
  p->state = state;
  p->stateBegun = TRUE;
  p->timer = 0;
}

CrossoverError* CrossoverError_Get(void) { return sCrossoverError; }

// テキストパネルとモザイクを片付けて, 描画パスを通常に戻す
void CrossoverError_ResetVideo(CrossoverError* p) {
  TextPanelManager_DestroyAll();
  MosaicFader_Stop();
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON | DISPCNT_BG2_ON);
  Video_ResetFrameState(1);
  Video_SetDrawPasses(0, nop_0822e738, nop_0822b09c, FUN_0822f584);
  MainMenu_SetHudMode(7);
  ClearBGTilemapBuffer(0);
}

void CrossoverError_LoadFatalBG(CrossoverError* p, s32 param_2) {
  BgPlttFile* f;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &param_2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  f = GetBgPlttFile(BGP_EFDA);
  CpuCopy16(f->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

void CrossoverError_LoadErrorBG(CrossoverError* p, s32 param_2) {
  BgPlttFile* f;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &param_2);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  f = GetBgPlttFile(BGP_LINK);
  CpuCopy16(f->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

void CrossoverError_UpdateWatch(CrossoverError* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  p->timer++;
}

void CrossoverError_UpdateFatal(CrossoverError* p) {
  SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    FUN_0804e5bc();
  }
  if (p->timer == 4) {
    s32 id;

    Sound_FadeOutBGM(1);
    CrossoverError_ResetVideo(p);
    CrossoverError_LoadFatalBG(p, 3);
    PlaySound_082406e0(SE_NG);
    id = TextPanel_Create(1, 7, 28, 6);
    p->windowID = id;
    if (id >= 0) {
      TextPanel_SetScript(id, p->msgPc);
      TextPanel_SetMessage(p->windowID, 0);
      TextPanel_Start(p->windowID);
    }
  }
  p->timer++;
}

void CrossoverError_UpdateRecoverable(CrossoverError* p) {
  SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
  if (p->stateBegun) {
    s32 id;

    p->stateBegun = FALSE;
    Sound_FadeOutBGM(1);
    CrossoverError_ResetVideo(p);
    FUN_0804e5bc();
    CrossoverError_LoadErrorBG(p, 13);
    id = TextPanel_Create(1, 14, 28, 6);
    p->windowID = id;
    if (id >= 0) {
      TextPanel_SetScript(id, p->msgPc);
      TextPanel_SetMessage(p->windowID, 1);
      TextPanel_Start(p->windowID);
    }
    PlaySound_082406e0(SE_NG);
  }
  if (p->timer >= 60 && (gInput[0].pressed & (START_BUTTON | B_BUTTON | A_BUTTON))) {
    CrossoverError_SetState(p, 3);
  } else {
    p->timer++;
  }
}

void CrossoverError_UpdateExit(CrossoverError* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
    PlaySound_082406e0(SE_CANCEL);
    FUN_0804e5e8();
  }
  if (p->timer == 20) {
    FUN_0804e604();
  }
  if (p->timer >= 20 && FUN_0804ba3c() == NULL && p->scriptID != 0) {
    Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
    VM_ExecByID(p->scriptID, NULL);
  }
  p->timer++;
}

s32 CrossoverError_Update(CrossoverError* p) {
  static void (*const sCrossoverErrorUpdates[4])(CrossoverError*) = {
      CrossoverError_UpdateWatch,
      CrossoverError_UpdateFatal,
      CrossoverError_UpdateRecoverable,
      CrossoverError_UpdateExit,
  };  // 0x085AB664

  if (p->state == 0) {
    s32 status = FUN_0804e59c();
    if (status == 1) {
      CrossoverError_SetState(p, 1);
    } else if (status == 2) {
      CrossoverError_SetState(p, 2);
    }
  }

  sCrossoverErrorUpdates[p->state](p);
  return 0;
}

s32 CrossoverError_Destroy(CrossoverError* p) {
  TextPanel_Destroy(p->windowID);
  sCrossoverError = NULL;
  return 0;
}

s32 CrossoverError_Init(CrossoverError* p) {
  sCrossoverError = p;
  MosaicFader_Stop();

  if (VM_SeekToNamedArg('s')) {
    p->msgPc = VM_GetPC_Proxy();
    if (p->msgPc == NULL) {
      return -1;
    }
  } else {
    return -1;
  }

  p->scriptID = VM_GetNamedArgValue('r', 0);
  p->windowID = -1;
  CrossoverError_SetState(p, 0);
  return 0;
}

// 0xD53D
CrossoverError* CrossoverError_Create(void) {
  CrossoverError* p = CrossoverError_Get();

  if (p != NULL) {
    return p;
  }
  p = CreateEntity(ENTITY_UNK_12, sizeof(CrossoverError));
  if (p != NULL) {
    SetEntityRoutine(p, CrossoverError_Update, CrossoverError_Destroy);
    if (CrossoverError_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
