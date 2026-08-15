#include "global.h"

extern u32 gRngValue;

void FUN_081dfe5c(void);
void FUN_0804e36c(void);
void ReadKeyInput(void);
void FUN_08230eb4(void);

// gSystemManager.onUpdate
s32 SystemManager_Update(Entity* p) {
  FUN_081dfe5c();
  FUN_0804e36c();
  ReadKeyInput();
  FUN_08230eb4();
  return 0;
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

// ゲームの初期化時に乱数表を作るために使う(それ以降は使用されない)
u32 Random(void) {
  gRngValue = (gRngValue * 0x5D588B65) + 1;
  return (gRngValue & 0x7FFF);
}
