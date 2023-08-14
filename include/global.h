#ifndef GUARD_ZOKTAI_GLOBAL_H
#define GUARD_ZOKTAI_GLOBAL_H

#include "constants/constants.h"
#include "definition.h"
#include "gba/gba.h"
#include "incbin.h"
#include "types.h"
//
#include "game.h"
#include "player.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

struct Unk_0203b000 {
  u16 id;
  u8 unk_02;
  u8 unk_03;
  void* unk_04;
};

struct Unk_03004810 {
  u8 unk_0;
  u8 unk_1;
  u8 unk_2;
  u8 unk_3;
  u8 unk_4;
  u8 unk_5;
  u8 unk_6;
  u8 unk_7;
  u8 _[4];
};

// 0x085a9208
struct Unk_085a9208 {
  u32 unk;
  void* fn;
};

struct Unk_030016e8 {
  void* unk;
  u32 len;
  struct Unk_085a9208* arr;
};

struct VM {
  u8* pc;
  void* result;
  void* unk_08;
  void* unk_0c;
  u8 unk_10[92];
  void* unk_6c[33];
};

extern struct Unk_0203b000 gUnk_0203b000[128];
extern struct Unk_085a9208 gUnk085a9208[643];
extern struct Unk_085a9208 gUnk08dbd758[8];
extern struct Unk_030016e8 gUnk030016e8;
extern struct VM gVM;

#endif  // GUARD_ZOKTAI_GLOBAL_H
