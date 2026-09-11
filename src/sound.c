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

// サウンドを音量最大で鳴らし(BGM は再生中なら継続)、再生中 ID として記録する
void sound_08240264(SoundID32 id) {
  if (gSongTable[id].ms == 10) {
    m4aSongNumStartOrContinue(id);
  } else {
    m4aSongNumStart(id);
  }
  m4aMPlayVolumeControl(gMPlayTable[gSongTable[id].ms].info, 0xFFFF, 0x100);
  gSoundIDs[gSongTable[id].ms] = id;
}

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

// 再生中のBGMを最小音量から指定速度でフェードインさせ直す
void Sound_FadeInBGM(u32 speed) {
  if (gSoundIDs[10] != 0) {
    SoundID16 id = gSoundIDs[10];
    u16 ms = gSongTable[id].ms;
    struct MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 1);
    m4aSongNumStop(id);
    m4aMPlayFadeIn(mplay, speed);
  }
}

void sound_082403b8(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    Sound_FadeInBGM(Script_GetValue());
  }
}

// 再生中のBGMを指定速度でフェードアウトさせて一時停止する(Sound_FadeInBGM で再開できる)
void Sound_FadeOutBGMTemporarily(u32 speed) {
  if (gSoundIDs[10] != 0) {
    u16 ms = gSongTable[gSoundIDs[10]].ms;
    struct MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 0x100);
    m4aMPlayFadeOutTemporarily(mplay, speed);
    gSoundIDs[ms] = MUS_DUMMY;
  }
}

void FUN_08240428(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    Sound_FadeOutBGMTemporarily(Script_GetValue());
  }
}

// 再生中のBGMを指定速度でフェードアウトさせて停止する(一時停止ではないので Sound_FadeInBGM では戻らない)
void Sound_FadeOutBGM(u32 speed) {
  if (gSoundIDs[10] != 0) {
    u16 ms = gSongTable[gSoundIDs[10]].ms;
    struct MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 0xFF);
    m4aMPlayFadeOut(mplay, speed);
    gSoundIDs[ms] = 0;
  }
}

void FUN_08240498(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    Sound_FadeOutBGM(Script_GetValue());
  }
}

// 環境音・ループするサブBGMのような同じ曲を鳴らしっぱなしにする用途?
void FUN_082404b0(SoundID32 id) {
  if (gSongTable[id].ms == 12) {
    m4aSongNumStartOrContinue(id);
    m4aMPlayVolumeControl(gMPlayTable[gSongTable[id].ms].info, 0xFFFF, 0x100);
    gSoundIDs[gSongTable[id].ms] = id;
  }
}

void FUN_082404fc(u32 speed) {
  SoundID16 id = gSoundIDs[12];

  if ((id != 0) && (gSongTable[id].ms == 12)) {
    struct MusicPlayerInfo* mplay = gMPlayTable[12].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 1);
    m4aSongNumStop(id);
    m4aMPlayFadeIn(mplay, speed);
  }
}

void FUN_08240550(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    FUN_082404fc(Script_GetValue());
  }
}

void FUN_08240568(u32 speed) {
  if (gSoundIDs[12] != 0) {
    u16 ms = gSongTable[gSoundIDs[12]].ms;
    m4aMPlayFadeOutTemporarily(gMPlayTable[ms].info, speed);
    gSoundIDs[ms] = 0;
  }
}

void FUN_082405a8(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    FUN_08240568(Script_GetValue());
  }
}

void FUN_082405c0(u32 speed) {
  SoundID16 id = gSoundIDs[12];

  if (id != 0) {
    u16 ms = gSongTable[id].ms;
    struct MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 0xFF);
    m4aMPlayFadeOut(mplay, speed);
    gSoundIDs[ms] = 0;
  }
}

void FUN_08240618(void) {
  if (VM_SeekToKeyword(0x66) != 0) {
    FUN_082405c0(Script_GetValue());
  }
}

void Sound_SetBGMTempo(u32 tempo) {
  SoundID16 id = gSoundIDs[10];

  if (id != 0) {
    u16 ms = gSongTable[id].ms;
    m4aMPlayTempoControl(gMPlayTable[ms].info, tempo);
  }
}

void FUN_08240668(void) {
  if (VM_SeekToKeyword(0x74) != 0) {
    Sound_SetBGMTempo(Script_GetValue());
  }
}

// 再生中の BGM の音量をスクリプト引数 'v'(音量) と 't'(対象トラック、省略時 0xFF) で変更する
void FUN_08240680(void) {
  u32 volume, trackBits;
  SoundID16 id;

  if (VM_SeekToKeyword(0x76) != 0) {
    volume = Script_GetValue();
    if (VM_SeekToKeyword(0x74) != 0) {
      trackBits = Script_GetValue();
    } else {
      trackBits = 0xFF;
    }
    id = gSoundIDs[10];
    if (id != 0) {
      u16 ms = gSongTable[id].ms;
      m4aMPlayVolumeControl(gMPlayTable[ms].info, trackBits, volume);
    }
  }
}

void PlaySound_082406e0(SoundID32 id) {
  if (!(gEntityDisableFlags & ((1 << 2) | (1 << 1)))) gSoundIDs[gSongTable[id].ms] = id;
  m4aSongNumStart(id);
}

// サンミゲルで建物に入った時のNPCのボイス時に呼ばれる(それ以外はまだ不明)
void PlaySound_08240718(SoundID32 id) { m4aSongNumStart(id); }

void sound_08240728(void) {
  if (VM_SeekToKeyword(0x69) != 0) {
    PlaySound_08240718(Script_GetValue());
  }
}

// サウンドを停止し、そのプレイヤーの再生中 ID として記録されていれば記録も消す
void sound_08240740(SoundID32 id) {
  if (gEntityDisableFlags & ((1 << 2) | (1 << 1))) {
    m4aSongNumStop(id);
  } else if (id == gSoundIDs[gSongTable[id].ms]) {
    gSoundIDs[gSongTable[id].ms] = 0;
    m4aSongNumStop(id);
  }
}

// GAMEOVER 中でなければサウンドを鳴らす
void PlaySound_0824078c(SoundID32 id) {
  u32 mask = FLAG030047A4_GAMEOVER;

  if (!((gFlag030047a4 | u32_030047a0) & mask)) PlaySound_082406e0(id);
}

// 全ミュージックプレイヤーで再生中として記録されたサウンドを停止し、記録を消す
void Sound_StopAll(void) {
  s32 i;

  for (i = 0; i < MUSIC_PLAYER_LENGTH; i++) {
    if (gSoundIDs[i] != 0) {
      m4aSongNumStop(gSoundIDs[i]);
      gSoundIDs[i] = 0;
    }
  }
}

// 全サウンドを停止し、再生中 ID の記録を消す (BGM(10) は再生中なら残し、12/29/30 は常に残す)
void FUN_082407e0(void) {
  s32 i;

  for (i = 0; i < MUSIC_PLAYER_LENGTH; i++) {
    if (i == 10) {
      if (!(gMPlayTable[10].info->status & MUSICPLAYER_STATUS_TRACK)) gSoundIDs[10] = 0;
    } else if (i != 12 && i != 29 && i != 30) {
      gSoundIDs[i] = 0;
    }
  }
  m4aMPlayAllStop();
}

// 記録されている BGM(10) と 12/29/30 のサウンドを再開する
void FUN_0824082c(void) {
  s32 i;

  for (i = 0; i < MUSIC_PLAYER_LENGTH; i++) {
    if (gSoundIDs[i] != 0) {
      if (i == 10) {
        m4aSongNumStartOrContinue(gSoundIDs[10]);
      } else if (i == 12 || i == 29 || i == 30) {
        m4aSongNumStartOrChange(gSoundIDs[i]);
      }
    }
  }
}

void FUN_0824087c(void) { FUN_0824082c(); }

// 全ミュージックプレイヤーを停止して再生中 ID の記録を消し、サウンドドライバを初期化し直す
void UNUSED Sound_Reset(void) {
  s32 i;

  for (i = 0; i < MUSIC_PLAYER_LENGTH; i++) {
    m4aMPlayStop(gMPlayTable[i].info);
    gSoundIDs[i] = 0;
  }
  m4aSoundInit();
}

void FUN_082408b8(void) {
  if (gSoundIDs[30] != 0) sound_08240740(gSoundIDs[30]);
}

void FUN_082408d0(void) {
  if (gSoundIDs[29] != 0) m4aSongNumStop(gSoundIDs[29]);
  if (gSoundIDs[30] != 0) m4aSongNumStop(gSoundIDs[30]);
}

void FUN_082408f4(void) {
  if (gSoundIDs[29] != 0) m4aSongNumStart(gSoundIDs[29]);
  if (gSoundIDs[30] != 0) m4aSongNumStart(gSoundIDs[30]);
}

void FUN_08240918(void) {
  if (gSoundIDs[30] != 0) m4aSongNumStop(gSoundIDs[30]);
}

void FUN_08240930(void) {
  if (gSoundIDs[30] != 0) m4aSongNumStart(gSoundIDs[30]);
}

void Sound_VSyncOff(void) { m4aSoundVSyncOff(); }

void Sound_VSyncOn(void) { m4aSoundVSyncOn(); }

// サウンドが再生中(一時停止中でなく、そのプレイヤーの再生中 ID として記録されている)か
bool32 sound_08240960(SoundID32 id) {
  u16 ms = gSongTable[id].ms;

  if (!(gMPlayTable[ms].info->status & MUSICPLAYER_STATUS_PAUSE) && gSoundIDs[ms] == id) return TRUE;
  return FALSE;
}

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
