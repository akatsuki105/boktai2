#include "global.h"

extern u32 gRNG_0300451c;

void FUN_081dfe5c(void);
void FUN_0804e36c(void);
void ReadKeyInput(void);
void FUN_08230eb4(void);

// gSystemManager.onUpdate
Entity* SystemManager_Update(Entity* p) {
  FUN_081dfe5c();
  FUN_0804e36c();
  ReadKeyInput();
  FUN_08230eb4();
  return NULL;
}

NAKED void InitSystemManager(void) { INCFUNC("asm/func/InitSystemManager.inc"); }

NAKED void ReadKeyInput(void) { INCFUNC("asm/func/ReadKeyInput.inc"); }

u16 FUN_08230860(char* s) {
  u16 hash = 0;
  while (*s != 0) {
    s32 lo = hash << 5;
    s32 hi = hash >> 0xB;
    hash = lo | hi;
    hash = hash + (u8)*s;
    s++;
  }
  return hash;
}

u32 GetRand_08230888(void) {
  gRNG_0300451c = (gRNG_0300451c * 0x5D588B65) + 1;
  return (gRNG_0300451c & 0x7FFF);
}
