#include "sound.h"

#include "entity.h"
#include "global.h"
#include "vm.h"

IWRAM_DATA ALIGNED(16) MusicPlayerTrack gMPlayTracks[50] = {};  // 0x03001710

COMMON_DATA SoundID16 gSoundIDs[MUSIC_PLAYER_LENGTH] = {};  // 0x03004820

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
  if (VM_SeekToNamedArg('i') != 0) {
    sound_08240264(VM_GetValue());
  }
}

// 0xE7CA
void FUN_082402e0(void) {
  if (VM_SeekToNamedArg('i') != 0) {
    sound_08240264(VM_GetValue());
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

void sound_08240344(void) { sound_082402f8(VM_SeekToNamedArg('i') ? VM_GetValue() : 0); }

// 再生中のBGMを最小音量から指定速度でフェードインさせ直す
void Sound_FadeInBGM(u32 speed) {
  if (gSoundIDs[10] != 0) {
    SoundID16 id = gSoundIDs[10];
    u16 ms = gSongTable[id].ms;
    MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 1);
    m4aSongNumStop(id);
    m4aMPlayFadeIn(mplay, speed);
  }
}

void sound_082403b8(void) {
  if (VM_SeekToNamedArg('f') != 0) {
    Sound_FadeInBGM(VM_GetValue());
  }
}

// 再生中のBGMを指定速度でフェードアウトさせて一時停止する(Sound_FadeInBGM で再開できる)
void Sound_FadeOutBGMTemporarily(u32 speed) {
  if (gSoundIDs[10] != 0) {
    u16 ms = gSongTable[gSoundIDs[10]].ms;
    MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 0x100);
    m4aMPlayFadeOutTemporarily(mplay, speed);
    gSoundIDs[ms] = MUS_DUMMY;
  }
}

void FUN_08240428(void) {
  if (VM_SeekToNamedArg('f') != 0) {
    Sound_FadeOutBGMTemporarily(VM_GetValue());
  }
}

// 再生中のBGMを指定速度でフェードアウトさせて停止する(一時停止ではないので Sound_FadeInBGM では戻らない)
void Sound_FadeOutBGM(u32 speed) {
  if (gSoundIDs[10] != 0) {
    u16 ms = gSongTable[gSoundIDs[10]].ms;
    MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 0xFF);
    m4aMPlayFadeOut(mplay, speed);
    gSoundIDs[ms] = 0;
  }
}

void FUN_08240498(void) {
  if (VM_SeekToNamedArg('f') != 0) {
    Sound_FadeOutBGM(VM_GetValue());
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
    MusicPlayerInfo* mplay = gMPlayTable[12].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 1);
    m4aSongNumStop(id);
    m4aMPlayFadeIn(mplay, speed);
  }
}

void FUN_08240550(void) {
  if (VM_SeekToNamedArg('f') != 0) {
    FUN_082404fc(VM_GetValue());
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
  if (VM_SeekToNamedArg('f') != 0) {
    FUN_08240568(VM_GetValue());
  }
}

void FUN_082405c0(u32 speed) {
  SoundID16 id = gSoundIDs[12];

  if (id != 0) {
    u16 ms = gSongTable[id].ms;
    MusicPlayerInfo* mplay = gMPlayTable[ms].info;
    m4aMPlayImmInit(mplay);
    m4aMPlayVolumeControl(mplay, 0xFFFF, 0xFF);
    m4aMPlayFadeOut(mplay, speed);
    gSoundIDs[ms] = 0;
  }
}

void FUN_08240618(void) {
  if (VM_SeekToNamedArg('f') != 0) {
    FUN_082405c0(VM_GetValue());
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
  if (VM_SeekToNamedArg('t') != 0) {
    Sound_SetBGMTempo(VM_GetValue());
  }
}

// 再生中の BGM の音量をスクリプト引数 'v'(音量) と 't'(対象トラック、省略時 0xFF) で変更する
void FUN_08240680(void) {
  u32 volume, trackBits;
  SoundID16 id;

  if (VM_SeekToNamedArg('v') != 0) {
    volume = VM_GetValue();
    if (VM_SeekToNamedArg('t') != 0) {
      trackBits = VM_GetValue();
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
  if (!(gEntityDisableFlags & (ENTITY_DISABLE_2 | ENTITY_DISABLE_1))) gSoundIDs[gSongTable[id].ms] = id;
  m4aSongNumStart(id);
}

// サンミゲルで建物に入った時のNPCのボイス時に呼ばれる(それ以外はまだ不明)
void PlaySound_08240718(SoundID32 id) { m4aSongNumStart(id); }

void sound_08240728(void) {
  if (VM_SeekToNamedArg('i') != 0) {
    PlaySound_08240718(VM_GetValue());
  }
}

// サウンドを停止し、そのプレイヤーの再生中 ID として記録されていれば記録も消す
void sound_08240740(SoundID32 id) {
  if (gEntityDisableFlags & (ENTITY_DISABLE_2 | ENTITY_DISABLE_1)) {
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

#include "data/voicegroups.h"

// ./tools/bin.ts ./baserom.gba 0x0825dd6c 0x0825e3ec ./data/programmable_wave_samples.bin
const u8 ProgrammableWaveData[] = INCBIN_U8("data/programmable_wave_samples.bin");

const MusicPlayer gMPlayTable[MUSIC_PLAYER_LENGTH] = {
    [0] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [1] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [2] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [3] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [4] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [5] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [6] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [7] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [8] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [9] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [10] = {info : &gMPlayInfo_09, track : &gMPlayTracks[0],  numTracks : 12, unk_A : 0},
    [11] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [12] = {info : &gMPlayInfo_13, track : &gMPlayTracks[12], numTracks : 8,  unk_A : 0},
    [13] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [14] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [15] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [16] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [17] = {info : &gMPlayInfo_14, track : &gMPlayTracks[20], numTracks : 2,  unk_A : 1},
    [18] = {info : &gMPlayInfo_06, track : &gMPlayTracks[22], numTracks : 1,  unk_A : 1},
    [19] = {info : NULL,           track : NULL,              numTracks : 0,  unk_A : 0},
    [20] = {info : &gMPlayInfo_03, track : &gMPlayTracks[23], numTracks : 2,  unk_A : 1},
    [21] = {info : &gMPlayInfo_05, track : &gMPlayTracks[25], numTracks : 2,  unk_A : 1},
    [22] = {info : &gMPlayInfo_12, track : &gMPlayTracks[27], numTracks : 3,  unk_A : 1},
    [23] = {info : &gMPlayInfo_00, track : &gMPlayTracks[30], numTracks : 3,  unk_A : 1},
    [24] = {info : &gMPlayInfo_04, track : &gMPlayTracks[33], numTracks : 2,  unk_A : 1},
    [25] = {info : &gMPlayInfo_10, track : &gMPlayTracks[35], numTracks : 3,  unk_A : 1},
    [26] = {info : &gMPlayInfo_02, track : &gMPlayTracks[38], numTracks : 1,  unk_A : 1},
    [27] = {info : &gMPlayInfo_15, track : &gMPlayTracks[39], numTracks : 3,  unk_A : 1},
    [28] = {info : &gMPlayInfo_07, track : &gMPlayTracks[42], numTracks : 2,  unk_A : 1},
    [29] = {info : &gMPlayInfo_11, track : &gMPlayTracks[44], numTracks : 1,  unk_A : 1},
    [30] = {info : &gMPlayInfo_01, track : &gMPlayTracks[45], numTracks : 2,  unk_A : 1},
    [31] = {info : &gMPlayInfo_08, track : &gMPlayTracks[47], numTracks : 3,  unk_A : 1},
};
