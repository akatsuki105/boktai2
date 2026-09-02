#include "global.h"

NAKED s32 FUN_0824beb8(u16 param_1, u8* dst, u8* param_3, u8 param_4) { INCFUNC("asm/func/FUN_0824beb8.inc"); }

NAKED s32 FUN_0824bfc0(u16 param_1, u8 param_2, u16* partnerid) { INCFUNC("asm/func/FUN_0824bfc0.inc"); }

void FUN_0824c0f8(u8* src, u8* dst, u8 bytesize);

void FUN_0824c0c4(u8 pid, u8* dst) {
  FUN_0824c0f8(gRfuLinkStatus->partner[pid].gname, dst, 13);
  FUN_0824c0f8(gRfuLinkStatus->partner[pid].uname, dst + 13, 4);
}

void FUN_0824c0f8(u8* src, u8* dst, u8 bytesize) {
  u8 i;
  for (i = 0; i < bytesize; i++) {
    dst[i] = src[i];
  }
}

u8 FUN_0824c120(u8* p) { return (*p) >> 5; }

u16 FUN_0824c128(u8* p) { return ((p[1] & 0x1F) << 8) | p[0]; }

NAKED void FUN_0824c138(unknown* p, u8 slot) { INCFUNC("asm/func/FUN_0824c138.inc"); }
