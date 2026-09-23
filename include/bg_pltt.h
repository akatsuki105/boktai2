#ifndef __INCLUDE_BG_PLTT_H__
#define __INCLUDE_BG_PLTT_H__

#include "gba/gba.h"
#include "types.h"

typedef struct {
  u8 header[20];     // 0x00, なにかのメタデータと思われるがゲーム内で使われてるか不明
  rgb555 body[256];  // 0x14
} BgPlttFile;
static_assert(sizeof(BgPlttFile) == 532);

#define GetBgPlttFile(fileID) ((BgPlttFile*)GetFile(DIR_BGPLTT, fileID))

#endif  // __INCLUDE_BG_PLTT_H__
