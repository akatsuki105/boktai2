#include "animation.h"
#include "global.h"

// TODO: いろんな用途のデータが区別されてないのであとで分ける
IWRAM_DATA u8 u8_03000784[4] = {};

// 通信 (SIO マルチプレイ) の送受信リングバッファ
IWRAM_DATA s32 gSioRecvWriteIdx = 0;  // 0x03000788
IWRAM_DATA s32 gSioRecvReadIdx = 0;   // 0x0300078C
IWRAM_DATA s32 gSioRecvCount = 0;     // 0x03000790
IWRAM_DATA s32 gSioSendWriteIdx = 0;  // 0x03000794
IWRAM_DATA s32 gSioSendReadIdx = 0;   // 0x03000798
IWRAM_DATA s32 gSioSendCount = 0;     // 0x0300079C
IWRAM_DATA u8 gSioRecvBuf[64] = {};   // 0x030007A0
IWRAM_DATA u8 gSioSendBuf[64] = {};   // 0x030007E0

IWRAM_DATA u8 u8_03000820[0x030016A0 - 0x03000820] = {};

NAKED bool32 FUN_08236fac(AnimState* p, AnimationFile* files, u16 animIdx, u8 param_4, AnimPlayFlags flags) { INCFUNC("asm/func/FUN_08236fac.inc"); }

NAKED bool32 FUN_08237040(AnimState* p, AnimationFile* files, u16 animIdx, u8 param_4, AnimPlayFlags flags) { INCFUNC("asm/func/FUN_08237040.inc"); }

NAKED bool32 FUN_08237064(AnimState* p, u16 val) { INCFUNC("asm/func/FUN_08237064.inc"); }

NAKED void FUN_08237098(AnimState* p, u16 speed) { INCFUNC("asm/func/FUN_08237098.inc"); }

NAKED void FUN_082370c0(AnimState* p) { INCFUNC("asm/func/FUN_082370c0.inc"); }
