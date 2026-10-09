#ifndef __INCLUDE_SOUND_H__
#define __INCLUDE_SOUND_H__

#include "gba/gba.h"
#include "gba/m4a.h"
#include "types.h"

#define MUSIC_PLAYER_LENGTH 32

extern struct MusicPlayerInfo gMPlayInfo_00;
extern struct MusicPlayerInfo gMPlayInfo_01;
extern struct MusicPlayerInfo gMPlayInfo_02;
extern struct MusicPlayerInfo gMPlayInfo_03;
extern struct MusicPlayerInfo gMPlayInfo_04;
extern struct MusicPlayerInfo gMPlayInfo_05;
extern struct MusicPlayerInfo gMPlayInfo_06;
extern struct MusicPlayerInfo gMPlayInfo_07;
extern struct MusicPlayerInfo gMPlayInfo_08;
extern struct MusicPlayerInfo gMPlayInfo_09;
extern struct MusicPlayerInfo gMPlayInfo_10;
extern struct MusicPlayerInfo gMPlayInfo_11;
extern struct MusicPlayerInfo gMPlayInfo_12;
extern struct MusicPlayerInfo gMPlayInfo_13;
extern struct MusicPlayerInfo gMPlayInfo_14;
extern struct MusicPlayerInfo gMPlayInfo_15;

extern struct MusicPlayerTrack gMPlayTracks[50];

extern SoundID16 gSoundIDs[MUSIC_PLAYER_LENGTH];  // 0x3004820

// --------------------------------------------

void sound_08240264(SoundID32 id);
void PlaySound_082406e0(SoundID32 id);
void sound_08240740(SoundID32 id);
void FUN_082407e0(void);
void FUN_0824082c(void);
void FUN_082408d0(void);
void FUN_082408f4(void);
void FUN_08240918(void);
void FUN_08240930(void);
void Sound_StopAll(void);
void Sound_FadeInBGM(u32 speed);
void Sound_FadeOutBGM(u32 speed);
void Sound_FadeOutBGMTemporarily(u32 speed);
void PlaySound_08240718(SoundID32 id);
void FUN_082404b0(SoundID32 id);
void FUN_082404fc(u32 speed);
void FUN_08240568(u32 speed);
void FUN_082405c0(u32 speed);

#endif  // __INCLUDE_SOUND_H__
