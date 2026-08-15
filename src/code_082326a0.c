#include "global.h"
#include "malloc.h"

typedef struct Unk030046a4 {
  u8 unk_0[3620];
} Unk030046a4;
static_assert(sizeof(Unk030046a4) == 3620);

extern Unk030046a4* gUnk030046a4;

void FUN_08230e30(u16 id, void* r1, s32 r2);
bool32 FUN_082326d8(void);

void FUN_082326a0(void) {
  void* p = Malloc(3620);
  ClearMemory(p, 3620);
  FUN_08230e30(0x56c2, p, 1);
  gUnk030046a4 = p;
  FUN_082326d8();
}
