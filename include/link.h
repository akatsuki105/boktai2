#ifndef __INCLUDE_LINK_H__
#define __INCLUDE_LINK_H__

#include "gba/gba.h"

extern u16 gSioParentRecv;

void Sio_Reset(void);
s32 Sio_Stop(void);
s32 Sio_Connect(void);
s32 Sio_Disconnect(void);
void Sio_StartTransferIfIdle(void);
s32 Sio_SetSendData(u16 data);
s32 Sio_GetRecvData(u16* dst);
s32 Sio_SendPacket(u8* src, s32 len);
s32 Sio_GetPacketStatus(u32 id);
s32 Sio_RecvPacket(u8* dst);
s32 Sio_PeekRecvData(u16* dst);

#endif  // __INCLUDE_LINK_H__
