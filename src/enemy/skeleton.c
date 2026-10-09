#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1960 - sizeof(Enemy)];
} Skeleton;
static_assert(sizeof(Skeleton) == 1960);

void FUN_08102e20(Enemy* p, u16* msg);
void FUN_08102e90(Enemy* p, u16* msg);
void FUN_08103120(Enemy* p, u16* msg);
void FUN_0810323c(Enemy* p, u16* msg);
void FUN_0810ece4(Enemy* p);
void FUN_0810f680(Enemy* p);
void FUN_0810ff58(Enemy* p);
void FUN_08110030(Enemy* p);
void FUN_081100f4(Enemy* p);
void FUN_081101b4(Enemy* p);
void FUN_0811028c(Enemy* p);
void FUN_08110ad0(Enemy* p);
void FUN_08110c80(Enemy* p);
void FUN_08110e30(Enemy* p);
void FUN_08110eec(Enemy* p);
void FUN_08111090(Enemy* p);
void FUN_08111268(Enemy* p);
void FUN_08112e84(Enemy* p);
void FUN_081130bc(Enemy* p);
void FUN_081131bc(Enemy* p);
void FUN_081132c0(Enemy* p);
void FUN_08113544(Enemy* p);
void FUN_08113628(Enemy* p);
void FUN_08113724(Enemy* p);
void FUN_08113970(Enemy* p);
void FUN_08113a44(Enemy* p);

const u16 u16_ARRAY_085ad4e4[8] = {400, 400, 0, 260, 380, 340, 0, 380};  // 0x085AD4E4
const u16 u16_ARRAY_085ad4f4[8] = {480, 480, 0, 312, 504, 408, 0, 456};  // 0x085AD4F4
const u16 u16_ARRAY_085ad504[8] = {600, 600, 0, 390, 570, 510, 0, 570};  // 0x085AD504
const u16 u16_ARRAY_085ad514[8] = {720, 720, 0, 468, 756, 612, 0, 684};  // 0x085AD514

void (*const PTR_ARRAY_085ad524[2])(Enemy*) = {
    FUN_0810ece4,
    FUN_0810f680,
};  // 0x085AD524

void (*const PTR_ARRAY_085ad52c[11])(Enemy*) = {
    FUN_0810ff58,
    FUN_08110030,
    FUN_081100f4,
    FUN_081101b4,
    FUN_08110ad0,
    FUN_08110c80,
    FUN_08110e30,
    FUN_08110eec,
    FUN_08111090,
    FUN_08111268,
    FUN_0811028c,
};  // 0x085AD52C

// clang-format off
void (*const PTR_ARRAY_085ad558[24])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_080f12c4,
    FUN_08112e84,
    FUN_081130bc,
    FUN_081131bc,
    FUN_081132c0,
    FUN_08113544,
    FUN_08113628,
    FUN_08113724,
    FUN_08113970,
    FUN_08113a44,
};  // 0x085AD558
// clang-format on

void (*const PTR_ARRAY_085ad5b8[8])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08102e20,
    FUN_08102e90,
};  // 0x085AD5B8

void (*const PTR_ARRAY_085ad5d8[8])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08103120,
    FUN_0810323c,
};  // 0x085AD5D8

INCASM("asm/skeleton.inc");

NAKED s32 EnemySkeleton_Destroy(Skeleton* p) { INCFUNC("asm/func/EnemySkeleton_Destroy.inc"); }

NAKED s32 EnemySkeleton_Init(Skeleton* p) { INCFUNC("asm/func/EnemySkeleton_Init.inc"); }

void EnemySkeleton_Create(void) {
  Skeleton* p = Malloc(sizeof(Skeleton));

  if (p != NULL) {
    ClearMemory(p, sizeof(Skeleton));
    if (EnemySkeleton_Init(p) < 0) {
      EnemySkeleton_Destroy(p);
      Free(p);
    }
  }
}
