#ifndef __INCLUDE_RFU_H__
#define __INCLUDE_RFU_H__

#include "global.h"

// 16バイト × 32件のリングバッファ, FUN_0823a790 が書き込み FUN_0823a7d8 が取り出す
typedef struct {
  bool8 empty;         // 0x000, FUN_0823a76c が 1 を入れ, 書き込むと 0 になる
  u8 readIdx;          // 0x001, FUN_0823a7d8 が読む側の添字
  u8 writeIdx;         // 0x002, FUN_0823a790 が書く側の添字 (0..31)
  u8 writeCount;       // 0x003, 書き込んだ回数
  u8 entries[32][16];  // 0x004
} RfuRingBuf;
static_assert(sizeof(RfuRingBuf) == 516);

s32 InitRfuAPI(void);
s32 PollRfuSoftReset(void);
void FUN_0823a730(INIT_PARAM* p, u32 isParent, u32 serialNo, u16 availSlot, u32 mbootFlag, u8* gameName, u8* userName);
void FUN_0823a76c(RfuRingBuf* p);
bool32 FUN_0823a790(RfuRingBuf* p, void* src);
bool32 FUN_0823a7d8(RfuRingBuf* p, void* dst);

#endif  // __INCLUDE_RFU_H__
