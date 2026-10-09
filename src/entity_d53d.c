#include "entity.h"
#include "global.h"
#include "signal_strength_icon.h"
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

void Video_ResetFrameState(u32 clearOam);  // src/video.c
void TextPanelManager_DestroyAll(void);    // src/text_panel.c
void MosaicFader_Stop(void);               // src/mosaic_fader.c
void nop_0822e738(void);                   // src/particle.c
void nop_0822b09c(void);                   // src/sprite_aux.c
void FUN_0822f584(void);                   // src/sprite_main.c
s32 FUN_0809c08c(s32 mode);                // src/entity_cc28.c
s32 FUN_0804e59c(void);

// 次の描画から BG を消す
static inline void HideBG(u32 bits) { gStagedDISPCNT &= ~bits; }

// 電波強度アイコンを作って表示位置を決める
void SignalStrengthIcon_CreateAt(s32 x, s32 y) {
  SignalStrengthIcon* p = SignalStrengthIcon_Create();

  if (p != NULL) {
    MainSprite* sprite = &p->sprite;

    sprite->pos.x = x;
    sprite->pos.y = y;
  }
}

EntityD53D* FUN_0804ea10(void) { return gEntityD53D; }

// テキストパネルとモザイクを片付けて, 描画パスを通常に戻す
void FUN_0804ea1c(void) {
  TextPanelManager_DestroyAll();
  MosaicFader_Stop();
  HideBG(DISPCNT_BG1_ON | DISPCNT_BG2_ON);
  Video_ResetFrameState(1);
  Video_SetDrawPasses(0, nop_0822e738, nop_0822b09c, FUN_0822f584);
  FUN_0809c08c(7);
  ClearBGTilemapBuffer(0);
}

NAKED void FUN_0804ea68(EntityD53D* p, s32 param_2) { INCFUNC("asm/func/FUN_0804ea68.inc"); }

NAKED void FUN_0804ead0(EntityD53D* p, s32 param_2) { INCFUNC("asm/func/FUN_0804ead0.inc"); }

void EntityD53D_UpdateState0(EntityD53D* p) {
  if (p->enter) {
    p->enter = 0;
  }
  p->timer++;
}

NAKED void FUN_0804eb50(EntityD53D* p) { INCFUNC("asm/func/FUN_0804eb50.inc"); }

NAKED void FUN_0804ebc4(EntityD53D* p) { INCFUNC("asm/func/FUN_0804ebc4.inc"); }

NAKED void FUN_0804ec58(EntityD53D* p) { INCFUNC("asm/func/FUN_0804ec58.inc"); }

void (*const sEntityD53DUpdates[4])(EntityD53D*) = {
    EntityD53D_UpdateState0,
    FUN_0804eb50,
    FUN_0804ebc4,
    FUN_0804ec58,
};  // 0x085AB664

s32 EntityD53D_Update(EntityD53D* p) {
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
    p->msgPc = FUN_0823d340();
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
  EntityD53D* p = FUN_0804ea10();

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
