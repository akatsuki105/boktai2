#include "entity.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "registry.h"

// 他のEntityと違い、SystemManager_Update のみ
IWRAM_DATA Entity gSystemManager = {};  // 0x03000728

extern u16 gEntityCount;  // 0x030044C0

void InitHeap(void);
void ResetEntityManager(void);
void ScriptRecord_ResetAll(void);
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

// 38/36 命令, gLinkKeyInput を埋める後ろ向きのループでカウンタが消えず, 符号付きのポインタ比較 (bge) で回す形が作れない
NON_MATCH void InitSystemManager(void) {
#ifdef NONMATCHING_C
  s32 i;

  InitHeap();
  ResetEntityManager();
  Registry_Reset();
  ScriptRecord_ResetAll();
  gRngValue = 123456;
  SetEntityRoutine(&gSystemManager, SystemManager_Update, NULL);
  gSystemManager.kind = ENTITY_SYSTEM;
  gSystemManager.unk_16 = TRUE;
  gSystemManager.id = 0;
  AddEntity(&gSystemManager);
  gEntityDisableFlags = 0;
  gEntityCount = 1;
  gUseLinkInput = FALSE;
  for (i = 3; i >= 0; i--) {
    gLinkKeyInput[i] = KEYS_MASK;
  }
#else
  INCFUNC("asm/func/InitSystemManager.inc");
#endif
}

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

// 識別子の文字列から16bitのIDを作るハッシュ, 5bit左ローテートしながら1バイトずつ足す, 原典はファイル名もVMのキーワードも文字列で書いていて、IDはこれで作られていた
// HashName("if"): 0x0D86 (VM_Ctrl_If)
// HashName("switch"): 0x4A6F (VM_Ctrl_Switch)
// HashName("return"): 0xCD3A (VM_Ctrl_Return)
// HashName("call"):  0x121F (VM_Ctrl_CallScriptIndirect)
// HashName("print"): 0xB96E (VM_Ctrl_DebugPrint)
// さらに chara 名 も EUC-JP 文字列をハッシュ化したもの
//   HashName("プレイヤー") -> 0xF5EB
//   HashName("シャイアン") -> 0x8E9F
// このリポジトリでも、 文字列で表記するために BOKHASH マクロを使って同じロジックで識別子のハッシュを生成している (tools/preproc で処理)
u16 HashName(const char* s) {
  u16 hash = 0;
  while (*s != 0) {
    s32 lo = hash << 5;
    s32 hi = hash >> 11;
    hash = lo | hi;
    hash = hash + (u8)*s;
    s++;
  }
  return hash;
}

// ゲームの初期化時に乱数表を作るために使う(それ以降は使用されない)
u32 RandomLCG(void) {
  gRngValue = (gRngValue * 0x5D588B65) + 1;
  return (gRngValue & 0x7FFF);
}
