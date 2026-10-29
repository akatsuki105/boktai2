#include "interrupts.h"

#include "entity.h"
#include "gba/m4a.h"
#include "global.h"
#include "video.h"

static bool32 sVCountAtMarquee;  // 0x03000250, 次の V カウント割り込みがマーキーの 144 ライン目か, VCountIntr が 64 ライン目と交互に切り替える

COMMON_DATA IntrFunc gIntrTable[13] = {};                  // 0x03002CB0
COMMON_DATA vu32 gVblankFlag = FALSE;                      // 0x03002CE4
COMMON_DATA u32 gMarqueeOffset = 0;                        // 0x03002CE8
COMMON_DATA bool32 gMarqueeActive2 = FALSE;                // 0x03002CEC
COMMON_DATA u32 gFrameCounter = 0;                         // 0x03002CF0, bit0 が点滅の偶奇を決める, 根拠: MainSprite_DrawList が tst #1 で SPRFLAG_BLINK_ODD / SPRFLAG_BLINK_EVEN を選ぶ
COMMON_DATA u8 u8_03002cf4[12] = {};                       // todo
COMMON_DATA u32 IntrMain_Buffer[0x200] = {0};              // 0x03002D00, INTR_MAIN のRAMコード
COMMON_DATA bool32 gVBlankDone = FALSE;                    // 0x03003500, VBlankIntr が立て、VideoCommit_Update が落とす
COMMON_DATA u32 gVBlankCount = 0;                          // 0x03003504, VBlankIntr が毎フレーム +1 する
COMMON_DATA u32 gMarqueeOffset2 = 0;                       // 0x03003508
COMMON_DATA bool32 gVBlankEnabled = FALSE;                 // 0x0300350C, 0 の間 VBlankIntr は m4aSoundVSync と gVblankFlag だけで抜ける, InitIntrAndVideo が立てる
COMMON_DATA u16 gHBlankDmaCount = 0;                       // 0x03003510, FUN_0822f0d8, FUN_0822eef4 が 1 を書く
COMMON_DATA u8 u8_03003512[2] = {};                        // todo
COMMON_DATA s16 gHBlankDmaMode = 0;                        // 0x03003514, FUN_0822f0d8 は 0、FUN_0822eef4 は 1 を書く
COMMON_DATA u8 u8_03003516[2] = {};                        // todo
COMMON_DATA u16* gHBlankEffectBuffer = NULL;               // 0x03003518, スキャンライン毎(160 ライン)の値のバッファ (= u16_ARRAY_02036c00), 根拠: FUN_0822f0d8, FUN_0822eef4
COMMON_DATA bool16 gEepromIdle = FALSE;                    // 0x0300351C, EEPROM_BeginAccess (EEPROM アクセス前) が 0、EEPROM_EndAccess (アクセス後) が 1 を書く
COMMON_DATA u8 u8_0300351e[0x03003520 - 0x0300351E] = {};  // todo
COMMON_DATA bool32 gMarqueeActive = FALSE;                 // 0x03003520, Marquee の表示中フラグと対で立つ

#define INTR_CHECK (*(u16*)0x3007FF8)
#define INTR_VECTOR (*(void**)0x3007FFC)

extern u16 gStagedBGOfs[8];
extern u16 gBg2AffineMode;
extern s16 gStagedBgAffineMatrix[4];
extern u32 gStagedBgAffineRef[2];
extern vu16* gHBlankEffectReg;
extern u32 u32_03002b54;
extern Entity gVideoCommit;
extern Entity gVideoRender;
extern u16 gObjTileRequestCount;
extern bool32 gDispcntLocked;

s32 FUN_0804ba48(void);
s32 JoyspotManager_IsActive(void);
void Time_AdvanceFrame(void);
void rfu_LMAN_syncVBlank(void);
u16 rfu_syncVBlank(void);
void Video_ResetMosaic(void);
void Video_InitBGMode(s32 mode);
void Video_SetWindowInOut(u32 win0In, u32 win1In, u32 winOut, u32 objWinIn);
void Video_Reset(void);
void Video_CreateSpriteLUT(void);
s32 FUN_0822f1b0(void);
void Video_ResetHBlankEffect(void);
s32 Font_LoadInfo(void);
s32 VideoCommit_Update(Entity* p);
s32 VideoRender_Update(Entity* p);

void IntrMain(void);
void VCountIntr(void);
void HBlankIntr(void);
void KeypadIntr(void);
void VBlankIntr(void);

// IntrMain が IF を調べる順 (VCOUNT, SERIAL, TIMER3, HBLANK, VBLANK, TIMER0-2, DMA0-3, KEYPAD) に並ぶ
const Procedure gIntrTableTemplate[13] = {
    VCountIntr,  // V-count interrupt
    IntrDummy,   // Serial communication interrupt
    IntrDummy,   // Timer 3 interrupt
    HBlankIntr,  // H-blank interrupt
    VBlankIntr,  // V-blank interrupt
    IntrDummy,   // Timer 0 interrupt
    IntrDummy,   // Timer 1 interrupt
    IntrDummy,   // Timer 2 interrupt
    IntrDummy,   // DMA 0 interrupt
    IntrDummy,   // DMA 1 interrupt
    IntrDummy,   // DMA 2 interrupt
    IntrDummy,   // DMA 3 interrupt
    KeypadIntr,  // Key interrupt
};

// 割り込みテーブルと IntrMain を RAM へ写し, VRAM/OAM/パレットを消して VBlank 割り込みだけを有効にする
void InitIntrHandlers(void) {
  DmaCopy32(3, gIntrTableTemplate, gIntrTable, sizeof(gIntrTableTemplate));
  DmaCopy32(3, IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer));
  INTR_VECTOR = IntrMain_Buffer;
  gVBlankEnabled = FALSE;
  gVblankFlag = FALSE;
  DmaFill32(3, 0, VRAM, VRAM_SIZE);
  DmaFill32(3, 0xA0, OAM, OAM_SIZE);
  DmaFill32(3, 0, PLTT, PLTT_SIZE);
  REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_GAMEPAK;
  REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
  REG_IME = 1;
}

// VRAM/OAM/パレットを消し, VBlank/HBlank/VCount の割り込みを有効にして描画まわりを初期化し, VideoCommit と VideoRender の Entity を登録する
void InitIntrAndVideo(void) {
  u16 ie;

  DmaFill32(3, 0, VRAM, VRAM_SIZE);
  DmaFill32(3, 0xA0, OAM, OAM_SIZE);
  DmaFill32(3, 0, PLTT, PLTT_SIZE);

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  gVBlankEnabled = TRUE;
  sVCountAtMarquee = FALSE;
  gEepromIdle = TRUE;
  ie = INTR_FLAG_GAMEPAK;
  REG_IE = ie;
  REG_IE |= INTR_FLAG_KEYPAD;
  REG_IE |= INTR_FLAG_VBLANK;
  REG_IE |= INTR_FLAG_HBLANK;
  REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
  REG_DISPSTAT |= DISPSTAT_HBLANK_INTR;
  REG_DISPSTAT |= DISPSTAT_VCOUNT_INTR;
  REG_DISPSTAT = (REG_DISPSTAT & 0xFF) | (64 << 8);
  REG_IME = 1;
  REG_KEYCNT = 0;
  gObjBlendEnabled = 0;

  Video_ResetMosaic();
  Video_InitBGMode(0);
  Video_SetWindowRect(0, 0, 0, 240, 180);
  Video_SetWindowRect(1, 0, 0, 240, 180);
  Video_SetWindowInOut(0x3F, 1, 0, 0);
  gObjTileRequestCount = 0;
  gDispcntLocked = FALSE;
  Video_Reset();
  Video_CreateSpriteLUT();
  FUN_0822f1b0();
  Video_ResetHBlankEffect();
  Font_LoadInfo();
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  gFrameCounter = 0;
  gVBlankCount = 0;

  SetEntityRoutine(&gVideoCommit, VideoCommit_Update, NULL);
  SetEntityRoutine(&gVideoRender, VideoRender_Update, NULL);
  gVideoCommit.kind = ENTITY_SYSTEM;
  gVideoCommit.unk_16 = 1;
  gVideoCommit.id = 0;
  gVideoRender.kind = ENTITY_UNK_13;
  gVideoRender.unk_16 = 1;
  gVideoRender.id = 0;
  AddEntity(&gVideoCommit);
  AddEntity(&gVideoRender);
}

void WaitForVBlank(void) {
  gVblankFlag = FALSE;

  while (!gVblankFlag) {
  }
}

// 割り込みを強制的に有効にして n 回 VBlank を待ち、IME を元に戻す
void WaitForVBlanks(u16 n) {
  u16 ime = REG_IME;

  REG_IME = 1;
  while (n-- != 0) {
    WaitForVBlank();
  }
  REG_IME = ime;
}

// VBlank 割り込み, 控えておいた BG のスクロールと回転拡大, HBlank DMA を反映し, 通信と時計を1フレーム進める
void VBlankIntr(void) {
  m4aSoundVSync();
  gVblankFlag = TRUE;
  if (gVBlankEnabled) {
    gMarqueeOffset2 = gMarqueeOffset;
    gMarqueeActive2 = gMarqueeActive;

    REG_BG0HOFS = gStagedBGOfs[0];
    REG_BG0VOFS = gStagedBGOfs[1];
    REG_BG1HOFS = gStagedBGOfs[2];
    REG_BG1VOFS = gStagedBGOfs[3];
    if (gBg2AffineMode == 0) {
      REG_BG2HOFS = gStagedBGOfs[4];
      REG_BG2VOFS = gStagedBGOfs[5];
      REG_BG3HOFS = gStagedBGOfs[6];
      REG_BG3VOFS = gStagedBGOfs[7];
    } else {
      REG_BG2PA = gStagedBgAffineMatrix[0];
      REG_BG2PB = gStagedBgAffineMatrix[1];
      REG_BG2PC = gStagedBgAffineMatrix[2];
      REG_BG2PD = gStagedBgAffineMatrix[3];
      REG_BG2X_L = gStagedBgAffineRef[0];
      REG_BG2X_H = (gStagedBgAffineRef[0] & 0x0FFF0000) >> 16;
      REG_BG2Y_L = gStagedBgAffineRef[1];
      REG_BG2Y_H = (gStagedBgAffineRef[1] & 0x0FFF0000) >> 16;
    }

    if (gHBlankDmaMode != 0) {
      REG_DMA0CNT = 0;
      REG_DMA0SAD = (u32)gHBlankEffectBuffer;
      REG_DMA0DAD = (u32)gHBlankEffectReg;
      REG_DMA0CNT = ((gHBlankDmaMode != 1 ? DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_32BIT | DMA_DEST_RELOAD : DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_16BIT | DMA_DEST_RELOAD) << 16) | gHBlankDmaCount;
    } else {
      DmaSet(0, 0, 0, 0);
    }

    gVBlankDone = TRUE;
    if (FUN_0804ba48()) {
      rfu_LMAN_syncVBlank();
    } else if (JoyspotManager_IsActive()) {
      u32_03002b54 = rfu_syncVBlank();
    }
    Time_AdvanceFrame();
    gVBlankCount++;
  }
  INTR_CHECK = INTR_FLAG_VBLANK;
}

// 64 ライン目でサウンドを回し, マーキー表示中は 144 ライン目でマーキー行の BG0HOFS を差し替える
void VCountIntr(void) {
  if (!sVCountAtMarquee) {
    if (gMarqueeActive2) {
      REG_DISPSTAT &= 0xFF;
      REG_DISPSTAT |= 144 << 8;
      sVCountAtMarquee = TRUE;
    }
    m4aSoundMain();
  } else {
    REG_BG0HOFS = gMarqueeOffset2 & 0xFF;
    REG_DISPSTAT &= 0xFF;
    REG_DISPSTAT |= 64 << 8;
    sVCountAtMarquee = FALSE;
  }
}

void HBlankIntr(void) {}

void KeypadIntr(void) {}

void IntrDummy(void) {}
