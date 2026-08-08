#include "entity.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "time.h"

IWRAM_DATA u8 u8_03000000[600] = {};  // todo, rfu_MBOOT_CHILD_inheritanceLinkStatus で RFU_LINK_STATUS の本体がここにあるが、メインゲーム開始時に別の構造体で上書きされてるように見える (つまり union)

IWRAM_DATA Entity gVideoManager = {};  // 0x03000258

IWRAM_DATA Entity gEntityKind13 = {};  // 0x03000270
IWRAM_DATA u8 u8_03000288[1184] = {};  // おそらく最初の方は gEntityKind13 の続きが入るが、どこまでが gEntityKind13 なのかは不明

IWRAM_DATA Entity gSystemManager = {};  // 0x03000728

IWRAM_DATA u8 u8_03000740[3968] = {};

IWRAM_DATA Unk_030016c0 gUnk030016c0 = {};  // 0x030016C0
IWRAM_DATA Unk_030016e8 gUnk030016e8 = {};
IWRAM_DATA u16 gUnk085a9208Counter = 0;   // 0x030016f4
IWRAM_DATA Entity2* PTR_030016f8 = NULL;  // 0x030016f8
IWRAM_DATA u32 DAT_030016fc = 0;
IWRAM_DATA u32 DAT_03001700 = 0;
IWRAM_DATA u32 DAT_03001704 = 0;
IWRAM_DATA Entity5* PTR_03001708 = 0;
IWRAM_DATA ALIGNED(16) struct MusicPlayerTrack gMPlayTracks[50] = {};
IWRAM_DATA u8 u8_030026b0[24] = {};
