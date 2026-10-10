#include "link.h"

#include "global.h"
#include "interrupts.h"

EWRAM_DATA u32 u32_ARRAY_0203f800[256] = {};  // 0x0203F800

IWRAM_DATA s32 gSioRecvWriteIdx = 0;        // 0x03000788
IWRAM_DATA s32 gSioRecvReadIdx = 0;         // 0x0300078C
IWRAM_DATA s32 gSioRecvCount = 0;           // 0x03000790
IWRAM_DATA s32 gSioSendWriteIdx = 0;        // 0x03000794
IWRAM_DATA s32 gSioSendReadIdx = 0;         // 0x03000798
IWRAM_DATA s32 gSioSendCount = 0;           // 0x0300079C
IWRAM_DATA u8 gSioRecvBuf[64] = {};         // 0x030007A0
IWRAM_DATA u8 gSioSendBuf[64] = {};         // 0x030007E0
IWRAM_DATA void* ptr_03000820 = NULL;       // 0x03000820, 0x30C バイトのコンテキストを指す, FUN_08238138 が u32_ARRAY_0203f800 を割り当てる
IWRAM_DATA u16 u16_03000824 = 0;            // 0x03000824, 送信スロット, bit14 が立っているときだけ FUN_08238e14 が上書きできる
IWRAM_DATA s32 s32_03000828 = 0;            // 0x03000828, 0x03004720 の u16[4] を読む面 (0 or 1), 割り込みは 1 - これ の面に書いてから反転する
IWRAM_DATA bool32 bool32_0300082c = FALSE;  // 0x0300082C, 0x03004720 に未読データあり, FUN_08238da8 が読み出すと 0 に戻る
IWRAM_DATA s32 s32_03000830 = 0;            // 0x03000830, 0x030046F0 の u16[4] を読む面 (0 or 1), 同じく割り込みが反転する

void Sio_ParentTimerIntr(void);

// タイマー3 を約 100Hz の割り込みで動かし、そのハンドラに Sio_ParentTimerIntr を登録する
void Sio_StartParentTimer(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_L = 0xF5D8;
  REG_TM3CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_64CLK;
  gIntrTable[2] = Sio_ParentTimerIntr;
  ie |= INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_TIMER3;
}

// 親用のタイマー3割り込みを止め、ハンドラを IntrDummy に戻す
void Sio_StopParentTimer(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_H = 0;
  REG_TM3CNT_L = 0;
  gIntrTable[2] = IntrDummy;
  ie &= ~INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_TIMER3;
}

// 親のタイマー3割り込み: 子のデータを受信バッファに積み、送信バッファから1バイト送る
void Sio_ParentTimerIntr(void) {
  s32 recv, m2, m3;
  s32 send;

  recv = REG_SIOMULTI1;
  m2 = REG_SIOMULTI2;
  m3 = REG_SIOMULTI3;
  send = 0;
  gSioParentRecv = recv;
  if ((REG_SIOCNT & (SIO_ERROR | SIO_MULTI_BUSY)) || m2 != 0xFFFF || m3 != 0xFFFF) {
    if (m2 != 0xFFFF || m3 != 0xFFFF) {
      gSioStatus = -7;
    } else {
      gSioStatus = -8;
    }
  } else {
    if ((recv & 0x2000) && recv != 0xFFFF) {
      gSioRecvBuf[gSioRecvWriteIdx] = recv;
      gSioRecvWriteIdx = (gSioRecvWriteIdx + 1) & 0x3F;
      gSioRecvCount++;
    }
    if (gSioRecvCount > 62) {
      send |= 0x4000;
    }
    if (gSioSendCount > 0 && !(recv & 0x4000)) {
      send |= gSioSendBuf[gSioSendReadIdx];
      gSioSendReadIdx = (gSioSendReadIdx + 1) & 0x3F;
      gSioSendCount--;
      send |= 0x2000;
    }
    if (send == 0xFFFF) {
      send = 0x8000;
    }
    REG_SIOMLT_SEND = send;
  }
  REG_SIOCNT |= SIO_START;
  REG_TM3CNT_L = 0xF5D8;
  gSioTimerIntrCount++;
}

void Sio_ChildSerialIntr(void);

// 子用のシリアル割り込みを有効にし、ハンドラに Sio_ChildSerialIntr を登録する
void Sio_StartChildIntr(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  gIntrTable[1] = Sio_ChildSerialIntr;
  REG_SIOCNT |= SIO_INTR_ENABLE;
  ie |= INTR_FLAG_SERIAL;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
}

// 子用のシリアル割り込みを止め、ハンドラを IntrDummy に戻す
void Sio_StopChildIntr(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  gIntrTable[1] = IntrDummy;
  REG_SIOCNT &= ~SIO_INTR_ENABLE;
  ie &= ~INTR_FLAG_SERIAL;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
}

// 子のシリアル割り込み: 親のデータを受信バッファに積み、送信バッファから1バイト送る
void Sio_ChildSerialIntr(void) {
  s32 recv, m2, m3;
  s32 send;

  recv = REG_SIOMULTI0;
  m2 = REG_SIOMULTI2;
  m3 = REG_SIOMULTI3;
  send = 0;
  gSioChildRecv = recv;
  if ((REG_SIOCNT & SIO_ERROR) || m2 != 0xFFFF || m3 != 0xFFFF) {
    if (m2 != 0xFFFF || m3 != 0xFFFF) {
      gSioStatus = -7;
    } else {
      gSioStatus = -8;
    }
  } else {
    if ((recv & 0x2000) && recv != 0xFFFF) {
      gSioRecvBuf[gSioRecvWriteIdx] = recv;
      gSioRecvWriteIdx = (gSioRecvWriteIdx + 1) & 0x3F;
      gSioRecvCount++;
    }
    if (gSioRecvCount > 62) {
      send |= 0x4000;
    }
    if (gSioSendCount > 0 && !(recv & 0x4000)) {
      send |= gSioSendBuf[gSioSendReadIdx];
      gSioSendReadIdx = (gSioSendReadIdx + 1) & 0x3F;
      gSioSendCount--;
      send |= 0x2000;
    }
    if (send == 0xFFFF) {
      send = 0x8000;
    }
    REG_SIOMLT_SEND = send;
    if (gSioMultiId == -1) {
      gSioMultiId = (REG_SIOCNT >> 4) & 3;
      if (gSioMultiId != 1) {
        gSioStatus = -5;
      }
    }
  }
  gSioSerialIntrCount++;
}

// SIO を 115200bps のマルチプレイモードに初期化する
void Sio_Init(void) {
  gSioStatus = 0;
  gSioMultiId = -1;
  REG_IME = 0;
  REG_IE &= ~INTR_FLAG_SERIAL;
  REG_IME = 1;
  REG_RCNT = 0;
  REG_SIOCNT = SIO_MULTI_MODE;
  REG_SIOCNT |= SIO_115200_BPS;
}

NON_MATCH void Sio_CheckConnection(void) {
#ifdef NONMATCHING_C
  u16 cnt, busy;

  REG_SIOMLT_SEND = 0;
  cnt = REG_SIOCNT;
  if (!(cnt & SIO_MULTI_SD)) {
    gSioStatus = -9;
    return;
  }
  busy = cnt & SIO_MULTI_BUSY;
  if (busy) {
    gSioStatus = -4;
    return;
  }
  if (!(cnt & SIO_MULTI_SI)) {
    gSioMultiId = 0;
  } else {
    gSioMultiId = -1;
  }
  REG_SIOMLT_SEND = 0;
#else
  INCFUNC("asm/func/Sio_CheckConnection.inc");
#endif
}

// 通信状態をリセットして SIO を初期化し直す
void Sio_Reset(void) {
  gSioStatus = -1;
  Sio_Init();
}

void FUN_08237eb0(void) {}

NON_MATCH s32 Sio_Start(void) {
#ifdef NONMATCHING_C
  s32 i;

  gSioRecvWriteIdx = gSioRecvReadIdx = 0;
  gSioSendWriteIdx = gSioSendReadIdx = 0;
  gSioRecvCount = 0;
  gSioSendCount = 0;
  for (i = 0; i < 64; i++) {
    gSioRecvBuf[i] = 0;
    gSioSendBuf[i] = 0;
  }
  gSioStatus = 0;
  gSioMultiId = -1;
  gSioTimerIntrCount = gSioSerialIntrCount = 0;
  Sio_CheckConnection();
  if (gSioStatus < 0) {
    return gSioStatus;
  }
  if (gSioMultiId == 0) {
    Sio_StartParentTimer();
    return 0;
  }
  Sio_StartChildIntr();
  return 1;
#else
  INCFUNC("asm/func/Sio_Start.inc");
#endif
}

// 通信を止める (親ならタイマー3、子ならシリアル割り込みを止める)
s32 Sio_Stop(void) {
  if (gSioMultiId == 0) {
    Sio_StopParentTimer();
  } else {
    Sio_StopChildIntr();
  }
  return 0;
}

NAKED s32 FUN_08237f74(unknown* p) { INCFUNC("asm/func/FUN_08237f74.inc"); }

NAKED s32 FUN_08238014(unknown* p, s32 param_2) { INCFUNC("asm/func/FUN_08238014.inc"); }

// 通信エラーが出ていればそのエラーコード, 出ていなければ 0
s32 Sio_GetError(void) {
  if (gSioStatus < 0) {
    return gSioStatus;
  }
  return 0;
}

NAKED s32 FUN_082380a8(void) { INCFUNC("asm/func/FUN_082380a8.inc"); }

// 子が親からデータを受け取っているか (0xFFFF はデータなし)
bool32 Sio_HasParentData(void) {
  if (gSioChildRecv != 0xFFFF) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_082380f4(void) { INCFUNC("asm/func/FUN_082380f4.inc"); }

s32 Sio_GetTimerIntrCount(void) { return gSioTimerIntrCount; }

s32 Sio_GetSerialIntrCount(void) { return gSioSerialIntrCount; }

s32 Sio_GetMultiId(void) { return gSioMultiId; }

NAKED void FUN_08238138(void) { INCFUNC("asm/func/FUN_08238138.inc"); }

NAKED void FUN_08238148(unknown* p) { INCFUNC("asm/func/FUN_08238148.inc"); }

NAKED void FUN_08238158(unknown* p) { INCFUNC("asm/func/FUN_08238158.inc"); }

NAKED void FUN_08238178(s32 param_1, unknown* param_2) { INCFUNC("asm/func/FUN_08238178.inc"); }

NAKED void FUN_08238198(s32 param_1, unknown* param_2) { INCFUNC("asm/func/FUN_08238198.inc"); }

NAKED s32 FUN_082381b4(s32 param_1) { INCFUNC("asm/func/FUN_082381b4.inc"); }

NAKED s32 FUN_082381c8(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_082381c8.inc"); }

NAKED u32 FUN_082381e8(s32 param_1) { INCFUNC("asm/func/FUN_082381e8.inc"); }

NAKED s32 FUN_082381fc(s32 param_1) { INCFUNC("asm/func/FUN_082381fc.inc"); }

NAKED void FUN_08238228(s32 param_1) { INCFUNC("asm/func/FUN_08238228.inc"); }

NAKED s32 FUN_08238250(u32 param_1, s32 param_2, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08238250.inc"); }

NAKED s32 FUN_0823829c(s32 param_1, u8 param_2) { INCFUNC("asm/func/FUN_0823829c.inc"); }

NAKED void FUN_082382ec(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_082382ec.inc"); }

NAKED void FUN_082382f8(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_082382f8.inc"); }

NAKED void FUN_08238354(s32 param_1) { INCFUNC("asm/func/FUN_08238354.inc"); }

NAKED u32 FUN_08238400(void) { INCFUNC("asm/func/FUN_08238400.inc"); }

NAKED s32 FUN_0823840c(unknown* p) { INCFUNC("asm/func/FUN_0823840c.inc"); }

NAKED s32 FUN_08238480(void) { INCFUNC("asm/func/FUN_08238480.inc"); }

NAKED void FUN_0823849c(void) { INCFUNC("asm/func/FUN_0823849c.inc"); }

NAKED s32 FUN_082384b0(u32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_082384b0.inc"); }

NAKED s32 FUN_082384f4(u32 param_1) { INCFUNC("asm/func/FUN_082384f4.inc"); }

NAKED s32 FUN_08238538(unknown* p) { INCFUNC("asm/func/FUN_08238538.inc"); }

NAKED s32 FUN_08238590(void) { INCFUNC("asm/func/FUN_08238590.inc"); }

NAKED void FUN_082385b0(void) { INCFUNC("asm/func/FUN_082385b0.inc"); }

void Sio_DisableInterrupts(void) { REG_IME = 0; }

void Sio_EnableInterrupts(void) { REG_IME = 1; }

void Sio_StartTransfer(void) { REG_SIOCNT |= SIO_START; }

NAKED void FUN_08238634(void) { INCFUNC("asm/func/FUN_08238634.inc"); }

NAKED void FUN_0823869c(void) { INCFUNC("asm/func/FUN_0823869c.inc"); }

NAKED void FUN_082386e4(void) { INCFUNC("asm/func/FUN_082386e4.inc"); }

// 保留中のシリアル割り込みを捨ててから VBlank を待ち、SIO を 115200bps のマルチプレイモードに組み直す
void Sio_Reinit(void) {
  gSioStatus = 0;
  gSioMultiId = -1;
  REG_IME = 0;
  REG_IE &= ~INTR_FLAG_SERIAL;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
  WaitForVBlank();
  REG_RCNT = 0;
  REG_SIOCNT = SIO_MULTI_MODE;
  REG_SIOCNT |= SIO_115200_BPS;
}

NAKED void FUN_08238a30(void) { INCFUNC("asm/func/FUN_08238a30.inc"); }

NAKED void FUN_08238aac(void) { INCFUNC("asm/func/FUN_08238aac.inc"); }

NAKED s32 FUN_08238b04(void) { INCFUNC("asm/func/FUN_08238b04.inc"); }

NAKED s32 FUN_08238bc0(void) { INCFUNC("asm/func/FUN_08238bc0.inc"); }

NAKED s32 FUN_08238bf4(void) { INCFUNC("asm/func/FUN_08238bf4.inc"); }

NAKED void FUN_08238c24(void) { INCFUNC("asm/func/FUN_08238c24.inc"); }

NAKED void FUN_08238cd4(void) { INCFUNC("asm/func/FUN_08238cd4.inc"); }

NAKED void FUN_08238d84(void) { INCFUNC("asm/func/FUN_08238d84.inc"); }

NAKED s32 FUN_08238da8(u16* param_1) { INCFUNC("asm/func/FUN_08238da8.inc"); }

NAKED s32 FUN_08238e14(u16 param_1) { INCFUNC("asm/func/FUN_08238e14.inc"); }

NAKED s32 FUN_08238e48(u16* param_1) { INCFUNC("asm/func/FUN_08238e48.inc"); }
