#include "sound.h"

#include "global.h"
#include "vm.h"

IWRAM_DATA ALIGNED(16) struct MusicPlayerTrack gMPlayTracks[50] = {};  // 0x03001710

COMMON_DATA struct SoundInfo gSoundInfo = {};  // 0x03004890
COMMON_DATA MPlayFunc gMPlayJumpTable[36] = {};
COMMON_DATA struct CgbChannel gCgbChans[4] = {};

// 0x030053A0
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_00 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_01 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_02 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_03 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_04 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_05 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_06 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_07 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_08 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_09 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_10 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_11 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_12 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_13 = {};
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_14 = {};
COMMON_DATA u8 gMPlayMemAccArea[16] = {};                // 0x03005760
COMMON_DATA struct MusicPlayerInfo gMPlayInfo_15 = {0};  // 0x03005770

NAKED void sound_08240264(SoundID32 id) { INCFUNC("asm/func/sound_08240264.inc"); }

void FUN_082402c8(void) {
  if (VM_SeekToKeyword(0x69) != 0) {
    sound_08240264(Script_GetValue());
  }
}

void FUN_082402e0(void) {
  if (VM_SeekToKeyword(0x69) != 0) {
    sound_08240264(Script_GetValue());
  }
}

void sound_082402f8(SoundID32 id) {
  if (id != 0) {
    if (id == gSoundIDs[gSongTable[id].ms]) {
      m4aSongNumStop(id);
      gSoundIDs[gSongTable[id].ms] = 0;
    }
  } else if (gSoundIDs[10] != 0) {
    m4aSongNumStop(gSoundIDs[10]);
    gSoundIDs[10] = id;
  }
}

void sound_08240344(void) { sound_082402f8(VM_SeekToKeyword(0x69) ? Script_GetValue() : 0); }

NAKED void FUN_08240360(u32 id) { INCFUNC("asm/func/FUN_08240360.inc"); }

void sound_082403b8(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    FUN_08240360(Script_GetValue());
  }
}

NAKED void FUN_082403d0(u32 speed) { INCFUNC("asm/func/FUN_082403d0.inc"); }

void FUN_08240428(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    FUN_082403d0(Script_GetValue());
  }
}

NAKED void sound_fadeout_08240440(u16 speed) { INCFUNC("asm/func/sound_fadeout_08240440.inc"); }

NAKED void FUN_08240498(void) { INCFUNC("asm/func/FUN_08240498.inc"); }

NAKED void FUN_082404b0(SoundID32 id) { INCFUNC("asm/func/FUN_082404b0.inc"); }

NAKED void FUN_082404fc(u32 speed) { INCFUNC("asm/func/FUN_082404fc.inc"); }

NAKED void FUN_08240550(void) { INCFUNC("asm/func/FUN_08240550.inc"); }

NAKED void FUN_08240568(u32 speed) { INCFUNC("asm/func/FUN_08240568.inc"); }

NAKED void FUN_082405a8(void) { INCFUNC("asm/func/FUN_082405a8.inc"); }

NAKED void FUN_082405c0(u32 speed) { INCFUNC("asm/func/FUN_082405c0.inc"); }

NAKED void FUN_08240618(void) { INCFUNC("asm/func/FUN_08240618.inc"); }

NAKED void FUN_08240630(u32 tempo) { INCFUNC("asm/func/FUN_08240630.inc"); }

NAKED void FUN_08240668(void) { INCFUNC("asm/func/FUN_08240668.inc"); }

NAKED void FUN_08240680(void) { INCFUNC("asm/func/FUN_08240680.inc"); }

void PlaySound_082406e0(SoundID32 id) {
  if (!(gEntityDisableFlags & ((1 << 2) | (1 << 1)))) gSoundIDs[gSongTable[id].ms] = id;
  m4aSongNumStart(id);
}

// サンミゲルで建物に入った時のNPCのボイス時に呼ばれる(それ以外はまだ不明)
void PlaySound_08240718(SoundID16 id) { m4aSongNumStart(id); }

NAKED void sound_08240728(void) { INCFUNC("asm/func/sound_08240728.inc"); }

NAKED void sound_08240740(SoundID32 id) { INCFUNC("asm/func/sound_08240740.inc"); }

NAKED void PlaySound_0824078c(SoundID32 id) { INCFUNC("asm/func/PlaySound_0824078c.inc"); }

NAKED void FUN_082407b8(void) { INCFUNC("asm/func/FUN_082407b8.inc"); }

NAKED void FUN_082407e0(void) { INCFUNC("asm/func/FUN_082407e0.inc"); }

NAKED void FUN_0824082c(void) { INCFUNC("asm/func/FUN_0824082c.inc"); }

void FUN_0824087c(void) { FUN_0824082c(); }

NAKED void FUN_08240888(void) { INCFUNC("asm/func/FUN_08240888.inc"); }

NAKED void FUN_082408b8(void) { INCFUNC("asm/func/FUN_082408b8.inc"); }

NAKED void FUN_082408d0(void) { INCFUNC("asm/func/FUN_082408d0.inc"); }

NAKED void FUN_082408f4(void) { INCFUNC("asm/func/FUN_082408f4.inc"); }

NAKED void FUN_08240918(void) { INCFUNC("asm/func/FUN_08240918.inc"); }

NAKED void FUN_08240930(void) { INCFUNC("asm/func/FUN_08240930.inc"); }

void Sound_VSyncOff(void) { m4aSoundVSyncOff(); }

void Sound_VSyncOn(void) { m4aSoundVSyncOn(); }

NAKED bool32 sound_08240960(SoundID32 id) { INCFUNC("asm/func/sound_08240960.inc"); }

// --------------------------------------------
// data

INCBIN(".rodata", "data/sound.bin");  // ./tmp/bin.sh ./baserom.gba 0x08252c00 0x0825e3ec ./data/sound.bin

// clang-format off
const struct MusicPlayer gMPlayTable[MUSIC_PLAYER_LENGTH] = {
    [0]  =  {NULL, NULL,  0, 0},
    [1]  =  {NULL, NULL,  0, 0},
    [2]  =  {NULL, NULL,  0, 0},
    [3]  =  {NULL, NULL,  0, 0},
    [4]  =  {NULL, NULL,  0, 0},
    [5]  =  {NULL, NULL,  0, 0},
    [6]  =  {NULL, NULL,  0, 0},
    [7]  =  {NULL, NULL,  0, 0},
    [8]  =  {NULL, NULL,  0, 0},
    [9]  =  {NULL, NULL,  0, 0},
    [10] = {&gMPlayInfo_09, &gMPlayTracks[0], 12, 0},
    [11] = {NULL, NULL,  0, 0},
    [12] = {&gMPlayInfo_13, &gMPlayTracks[12], 8, 0},
    [13] = {NULL, NULL,  0, 0},
    [14] = {NULL, NULL,  0, 0},
    [15] = {NULL, NULL,  0, 0},
    [16] = {NULL, NULL,  0, 0},
    [17] = {&gMPlayInfo_14, &gMPlayTracks[20], 2, 1},
    [18] = {&gMPlayInfo_06, &gMPlayTracks[22], 1, 1},
    [19] = {NULL, NULL,  0, 0},
    [20] = {&gMPlayInfo_03, &gMPlayTracks[23], 2, 1},
    [21] = {&gMPlayInfo_05, &gMPlayTracks[25], 2, 1},
    [22] = {&gMPlayInfo_12, &gMPlayTracks[27], 3, 1},
    [23] = {&gMPlayInfo_00, &gMPlayTracks[30], 3, 1},
    [24] = {&gMPlayInfo_04, &gMPlayTracks[33], 2, 1},
    [25] = {&gMPlayInfo_10, &gMPlayTracks[35], 3, 1},
    [26] = {&gMPlayInfo_02, &gMPlayTracks[38], 1, 1},
    [27] = {&gMPlayInfo_15, &gMPlayTracks[39], 3, 1},
    [28] = {&gMPlayInfo_07, &gMPlayTracks[42], 2, 1},
    [29] = {&gMPlayInfo_11, &gMPlayTracks[44], 1, 1},
    [30] = {&gMPlayInfo_01, &gMPlayTracks[45], 2, 1},
    [31] = {&gMPlayInfo_08, &gMPlayTracks[47], 3, 1},
};
// clang-format on

// gSongTable + SongHeader[]
INCBIN(".rodata", "data/song.bin");  // ./tmp/bin.sh ./baserom.gba 0x0825e56c 0x085a8ae0 ./data/song.bin
