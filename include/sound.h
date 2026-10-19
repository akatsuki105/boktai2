#ifndef __INCLUDE_SOUND_H__
#define __INCLUDE_SOUND_H__

#include "gba/gba.h"
#include "gba/m4a.h"
#include "types.h"

#define MUSIC_PLAYER_LENGTH 32

extern SoundID16 gSoundIDs[MUSIC_PLAYER_LENGTH];  // 0x3004820

// --------------------------------------------

void sound_08240264(SoundID32 id);
void PlaySound_082406e0(SoundID32 id);
void sound_08240740(SoundID32 id);
void FUN_082407e0(void);
void Sound_Resume(void);
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
