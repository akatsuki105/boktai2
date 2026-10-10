#include "global.h"
#include "interrupts.h"
#include "video.h"

#define MULTI_SIO_TIMER_NO 3

IWRAM_DATA u32 gRfuAPIBuffer[RFU_API_BUFF_SIZE_RAM / 4] = {};  // 0x03000838, rfu_initializeAPI に渡す

s32 InitRfuAPI(void) {
  if (rfu_initializeAPI(gRfuAPIBuffer, RFU_API_BUFF_SIZE_RAM, &gIntrTable[1], TRUE) != 0) {
    return -1;
  }
  rfu_setTimerInterrupt(MULTI_SIO_TIMER_NO, &gIntrTable[2]);
  return 0;
}

// 通信カートリッジの応答を待つ, 応答があれば 1、待ち時間を使い切ったら -1
s32 PollRfuSoftReset(void) {
  if (rfu_REQBN_softReset_and_checkID() == RFU_ID) {
    return 1;
  }
  if (gVBlankCount > 449) {
    return -1;
  }
  return 0;
}

// 呼び出し元の FUN_0804c438 が PollRfuSoftReset を呼び出すので FUN_0804c438 も rfu関係の関数であると思われ、そうなるとこれも rfu.c の関数と思われる
NAKED void FUN_0823a730(unknown* p, u32 param_2, u32 param_3, u16 param_4, u32 param_5, unknown* param_6, unknown* param_7) { INCFUNC("asm/func/FUN_0823a730.inc"); }

// 呼び出し元 4つ (FUN_0804d868 / FUN_0804dbe0 / FUN_0804d394 / FUN_0804d548) がいずれも rfu_setRecvBuffer と rfu_LMAN_setLMANCallback を呼ぶ文脈でこれを呼ぶので、通信用バッファの初期化とみられる
void FUN_0823a76c(u8* p) {
  CpuFill32(0, p, 516);
  p[0] = 1;
}

// 呼び出し元の FUN_0804cd1c が rfu_UNI_clearRecvNewDataFlag を呼ぶので rfu 関係の関数とみられる
NAKED bool32 FUN_0823a790(unknown* p, unknown* src) { INCFUNC("asm/func/FUN_0823a790.inc"); }

// 根拠は FUN_0823a790 と (p, src) / (p, dst) の対になっていることとアドレスが隣接していることだけで、呼び出し元の FUN_0804bb98 は rfu の API を直接は呼んでいない
NAKED bool32 FUN_0823a7d8(unknown* p, unknown* dst) { INCFUNC("asm/func/FUN_0823a7d8.inc"); }
