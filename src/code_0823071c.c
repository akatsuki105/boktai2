#include "entity.h"
#include "global.h"
#include "input.h"
#include "random.h"

// 他のEntityと違い、SystemManager_Update のみ
IWRAM_DATA Entity gSystemManager = {};  // 0x03000728

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

// KEYINPUT (通信対戦時は受信したキー) から gInput の5人分の押下・押した瞬間・離した瞬間を更新する
void ReadKeyInput(void) {
  u16 keys, prev;
  s32 i;

  gRawKeyInput = REG_KEYINPUT;
  if (!gUseLinkInput) {
    keys = gRawKeyInput ^ KEYS_MASK;
    prev = gInput[0].down;
    gInput[0].down = keys;
    gInput[0].pressed = keys & ~prev;
    gInput[0].released = prev & ~keys;
    keys = 0;
    for (i = 1; i < 5; i++) {
      prev = gInput[i].down;
      gInput[i].down = keys;
      gInput[i].pressed = keys;
      gInput[i].released = prev;
    }
  } else if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    for (i = 0; i < 5; i++) {
      if (gLinkKeyInput[i] == 0xFFFF) {
        keys = 0;
      } else {
        keys = gLinkKeyInput[i] ^ KEYS_MASK;
      }
      prev = gInput[i].down;
      gInput[i].down = keys;
      gInput[i].pressed = keys & ~prev;
      gInput[i].released = prev & ~keys;
    }
  }
}

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
