#include "link.h"

#include "global.h"
#include "interrupts.h"

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

INCASM("asm/link.inc");
