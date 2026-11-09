#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// スクリプト命令 0xD53D が作る失敗画面, 全画面のタイルマップとパレットを読み込み、SE_NG を鳴らしてメッセージを出し、最後に scriptID のスクリプトを起動する
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_12
  u8 state;           // 0x18, sEntityD53DUpdates[state]
  u8 enter;           // 0x19, state が変わるたび 1, 各ハンドラが最初のフレームで 0 に戻す
  u8 unk_1a[2];       // 0x1A, padding?
  u32 timer;          // 0x1C, 毎フレーム +1、state が変わると 0
  s32 windowID;       // 0x20, TextPanel_Create の戻り値, なければ -1, _Destroy が TextPanel_Destroy に渡して解放する
  Tilemaps* tilemap;  // 0x24
  u8* msgPc;          // 0x28, _Init 時点の VM_GetPC(), TextPanel_SetScript(windowID, msgPc) に渡す
  s32 scriptID;       // 0x2C, '.r=0', state 3 が VM_ExecByID に渡す
} EntityD53D;
static_assert(sizeof(EntityD53D) == 48);

IWRAM_DATA EntityD53D* gEntityD53D = NULL;  // 0x030000E8

void MosaicFader_Stop(void);
void MainMenu_SetHudMode(s32 mode);
s32 FUN_0804e59c(void);
void FUN_0804e5bc(void);
void FUN_0804e5e8(void);
void FUN_0804e604(void);
void* FUN_0804ba3c(void);

static inline void EntityD53D_SetState(EntityD53D* p, u8 state) {
  p->state = state;
  p->enter = 1;
  p->timer = 0;
}

EntityD53D* EntityD53D_Get(void) { return gEntityD53D; }

// テキストパネルとモザイクを片付けて, 描画パスを通常に戻す
void FUN_0804ea1c(EntityD53D* p) {
  TextPanelManager_DestroyAll();
  MosaicFader_Stop();
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON | DISPCNT_BG2_ON);
  Video_ResetFrameState(1);
  Video_SetDrawPasses(0, nop_0822e738, nop_0822b09c, FUN_0822f584);
  MainMenu_SetHudMode(7);
  ClearBGTilemapBuffer(0);
}

void EntityD53D_LoadBG(EntityD53D* p, s32 param_2) {
  BgPlttFile* f;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &param_2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  f = GetBgPlttFile(BGP_EFDA);
  CpuCopy16(f->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

void EntityD53D_LoadLinkBG(EntityD53D* p, s32 param_2) {
  BgPlttFile* f;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &param_2);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  f = GetBgPlttFile(BGP_LINK);
  CpuCopy16(f->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

void EntityD53D_UpdateState0(EntityD53D* p) {
  if (p->enter) {
    p->enter = 0;
  }
  p->timer++;
}

void EntityD53D_UpdateState1(EntityD53D* p) {
  SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
  if (p->enter) {
    p->enter = 0;
    FUN_0804e5bc();
  }
  if (p->timer == 4) {
    s32 id;

    Sound_FadeOutBGM(1);
    FUN_0804ea1c(p);
    EntityD53D_LoadBG(p, 3);
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

void EntityD53D_UpdateState2(EntityD53D* p) {
  SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
  if (p->enter) {
    s32 id;

    p->enter = 0;
    Sound_FadeOutBGM(1);
    FUN_0804ea1c(p);
    FUN_0804e5bc();
    EntityD53D_LoadLinkBG(p, 13);
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
    EntityD53D_SetState(p, 3);
  } else {
    p->timer++;
  }
}

void EntityD53D_UpdateState3(EntityD53D* p) {
  if (p->enter) {
    p->enter = 0;
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

s32 EntityD53D_Update(EntityD53D* p) {
  static void (*const sEntityD53DUpdates[4])(EntityD53D*) = {
      EntityD53D_UpdateState0,
      EntityD53D_UpdateState1,
      EntityD53D_UpdateState2,
      EntityD53D_UpdateState3,
  };  // 0x085AB664

  if (p->state == 0) {
    s32 status = FUN_0804e59c();

    if (status == 1) {
      p->state = 1;
      p->enter = 1;
      p->timer = 0;
    } else if (status == 2) {
      p->state = 2;
      p->enter = 1;
      p->timer = 0;
    }
  }

  sEntityD53DUpdates[p->state](p);
  return 0;
}

s32 EntityD53D_Destroy(EntityD53D* p) {
  TextPanel_Destroy(p->windowID);
  gEntityD53D = NULL;
  return 0;
}

s32 EntityD53D_Init(EntityD53D* p) {
  gEntityD53D = p;
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
  p->state = 0;
  p->enter = 1;
  p->timer = 0;
  return 0;
}

EntityD53D* EntityD53D_Create(void) {
  EntityD53D* p = EntityD53D_Get();

  if (p != NULL) {
    return p;
  }
  p = CreateEntity(ENTITY_UNK_12, sizeof(EntityD53D));
  if (p != NULL) {
    SetEntityRoutine(p, EntityD53D_Update, EntityD53D_Destroy);
    if (EntityD53D_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
