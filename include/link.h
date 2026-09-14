#ifndef __INCLUDE_LINK_H__
#define __INCLUDE_LINK_H__

#include "gba/gba.h"

extern s32 gSioRecvWriteIdx;
extern s32 gSioRecvReadIdx;
extern s32 gSioRecvCount;
extern s32 gSioSendWriteIdx;
extern s32 gSioSendReadIdx;
extern s32 gSioSendCount;
extern u8 gSioRecvBuf[64];
extern u8 gSioSendBuf[64];
extern u16 gSioParentRecv;
extern s32 gSioTimerIntrCount;
extern s32 gSioSerialIntrCount;
extern s32 gSioMultiId;
extern u16 gSioChildRecv;
extern s32 gSioStatus;

void Sio_Reset(void);

#endif  // __INCLUDE_LINK_H__
