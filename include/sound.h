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

#endif  // __INCLUDE_SOUND_H__
