#include "global.h"

NAKED void sound_08240264(u32 id) { INCFUNC("asm/func/sound_08240264.inc"); }

void FUN_082402c8(void) {
  if (prepare_08231510(0x69) != 0) {
    sound_08240264(fetch_082316e4());
  }
}

void FUN_082402e0(void) {
  if (prepare_08231510(0x69) != 0) {
    sound_08240264(fetch_082316e4());
  }
}

extern u8 gSongTable[];
extern sound_t gSoundIDs[32];
void m4aSongNumStop(u16 id);

void sound_082402f8(u32 id) {
  if (id != 0) {
    u8* base = (u8*)gSoundIDs;
    u8* table = gSongTable;
    u8* entry = table + id * 8;
    s32 idx = *(u16*)(entry + 4) * 2;
    u16* q = (u16*)(base + idx);
    if (id == *q) {
      m4aSongNumStop(id);
      *q = 0;
    }
  } else if (gSoundIDs[10] != 0) {
    m4aSongNumStop(gSoundIDs[10]);
    gSoundIDs[10] = id;
  }
}

void sound_08240344(void) {
  sound_082402f8(prepare_08231510(0x69) ? fetch_082316e4() : 0);
}

NAKED void FUN_08240360(u32 id) { INCFUNC("asm/func/FUN_08240360.inc"); }

void sound_082403b8(void) {
  if (prepare_08231510(0x66) != 0) {
    FUN_08240360(fetch_082316e4());
  }
}

NAKED void FUN_082403d0(u32 speed) { INCFUNC("asm/func/FUN_082403d0.inc"); }

void FUN_08240428(void) {
  if (prepare_08231510(0x66) != 0) {
    FUN_082403d0(fetch_082316e4());
  }
}

NAKED void sound_fadeout_08240440(u16 speed) { INCFUNC("asm/func/sound_fadeout_08240440.inc"); }

INCASM("asm/sound.inc");
