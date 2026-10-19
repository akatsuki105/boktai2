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
// rfu_LMAN_initializeRFU に渡す初期設定を組む
// 残差はレジスタ割当だけ (30 対 30), 原典は p/isParent/mbootFlag/gameName の4本を callee-saved に置き r1 を定数のスクラッチに使うが, こちらは mbootFlag を r1 に置くので r7 を使わない
// 文の順 (フィールド順/現状), if/else と三項, 戻り値 s32, 引数の型は試済
NON_MATCH void FUN_0823a730(INIT_PARAM* p, u32 isParent, u32 serialNo, u16 availSlot, u32 mbootFlag, u8* gameName, u8* userName) {
#ifdef NONMATCHING_C
  p->maxMFrame = 4;
  p->MC_TimerCount = 40;
  p->mboot_flag = mbootFlag;
  p->serialNo = serialNo;
  p->gameName = gameName;
  p->linkRecovery_enable = 1;
  p->linkRecovery_period = 240;
  p->NI_failCounter_limit = 480;
  p->availSlot_flag = isParent ? availSlot : 0;
  p->userName = userName;
#else
  INCFUNC("asm/func/FUN_0823a730.inc");
#endif
}

// 16バイト × 32件のリングバッファ, FUN_0823a790 が書き込み FUN_0823a7d8 が取り出す
typedef struct {
  bool8 empty;         // 0x000, FUN_0823a76c が 1 を入れ, 書き込むと 0 になる
  u8 readIdx;          // 0x001, FUN_0823a7d8 が読む側の添字
  u8 writeIdx;         // 0x002, FUN_0823a790 が書く側の添字 (0..31)
  u8 writeCount;       // 0x003, 書き込んだ回数
  u8 entries[32][16];  // 0x004
} RfuRingBuf;
static_assert(sizeof(RfuRingBuf) == 516);

// 呼び出し元 4つ (FUN_0804d868 / FUN_0804dbe0 / FUN_0804d394 / FUN_0804d548) がいずれも rfu_setRecvBuffer と rfu_LMAN_setLMANCallback を呼ぶ文脈でこれを呼ぶので、通信用バッファの初期化とみられる
void FUN_0823a76c(RfuRingBuf* p) {
  CpuFill32(0, p, sizeof(RfuRingBuf));
  p->empty = TRUE;
}

// 呼び出し元の FUN_0804cd1c が rfu_UNI_clearRecvNewDataFlag を呼ぶので rfu 関係の関数とみられる
// src の 16バイトをリングバッファへ積む, 満杯なら何もせず TRUE
bool32 FUN_0823a790(RfuRingBuf* p, void* src) {
  if (!p->empty && p->readIdx == p->writeIdx) {
    return TRUE;
  }

  CpuCopy32(src, p->entries[p->writeIdx], 16);
  p->writeCount++;
  p->writeIdx = (p->writeIdx + 1) & 0x1F;
  p->empty = FALSE;
}

// 根拠は FUN_0823a790 と (p, src) / (p, dst) の対になっていることとアドレスが隣接していることだけで、呼び出し元の FUN_0804bb98 は rfu の API を直接は呼んでいない
// リングバッファから 16バイト取り出して枠を 0 で埋める, 空なら FALSE
bool32 FUN_0823a7d8(RfuRingBuf* p, void* dst) {
  if (p->empty) {
    return FALSE;
  }

  REG_IME = 0;
  CpuCopy32(p->entries[p->readIdx], dst, 16);
  CpuFill32(0, p->entries[p->readIdx], 16);
  p->writeCount--;
  p->readIdx = (p->readIdx + 1) & 0x1F;
  if (p->readIdx == p->writeIdx) {
    p->empty = TRUE;
  }
  REG_IME = 1;
  return TRUE;
}
