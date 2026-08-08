#ifndef GUARD_ZOKTAI_GLOBAL_H
#define GUARD_ZOKTAI_GLOBAL_H

#include "constants/constants.h"
#include "definition.h"
#include "gba/gba.h"
#include "incbin.h"
#include "struct.h"
#include "types.h"
//
#include "game.h"
#include "player.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

// NAKED void funcXXX(void) {
//  INCFUNC("asm/funcXXX.inc");
// }
#define INCFUNC(file) \
  asm(".syntax unified\n\
  .include \"" file   \
      "\"\n\
    .align 2, 0\n    \
 .syntax divided\n");

typedef struct {
  u8* pc;
  void* result;
  void* unk_08;
  void* unk_0c;
  u8 unk_10[92];
  void* unk_6c[33];
} VM;

extern Unk_0203b000 gUnk_0203b000[128];
extern Unk_085a9208 gUnk085a9208[643];
extern Unk_085a9208 gUnk08dbd758[8];
extern Unk_030016c0* gUnkPtr_030047a8;
extern Unk_030016e8 gUnk030016e8;
extern VM gVM;

// --------------------------------------------

void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める

#endif  // GUARD_ZOKTAI_GLOBAL_H
