#include "boss.h"
#include "entity.h"
#include "global.h"

// 各Bossの構造体の最初の方は共通部分っぽい？
typedef struct Duneyrr {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[1956 - 0x18];
} Duneyrr;
static_assert(sizeof(Duneyrr) == 1956);

const s16 s16_ARRAY_085aaabc[8] = {0x40, 0x80, 0xC0, 0x20, 0x40, 0x40, 0x60, 0x20};  // 0x085AAABC

const u8 u8_ARRAY_085aaacc[32] = {0, 2, 1, 2, 2, 2, 3, 2, 0, 3, 1, 2, 2, 3, 3, 2, 0, 0, 1, 0, 2, 0, 3, 0, 0, 3, 1, 0, 2, 3, 3, 0};  // 0x085AAACC

const u16 u16_ARRAY_085aaaec[5] = {15, 16, 12, 13, 14};  // 0x085AAAEC

const u16 u16_ARRAY_085aaaf6[9] = {0x400, 0x500, 0x900, 0x500, 0x400, 0xA00, 0x900, 0xA00, 0x0};  // 0x085AAAF6

void FUN_08024c38(Duneyrr*);
void FUN_08024c84(Duneyrr*);
void FUN_08024cec(Duneyrr*);
void FUN_08024e58(Duneyrr*);
void FUN_08024fe4(Duneyrr*);
void FUN_0802506c(Duneyrr*);
void FUN_08025170(Duneyrr*);
void FUN_080251f0(Duneyrr*);
void FUN_0802523c(Duneyrr*);

void (*const PTR_ARRAY_085aab08[9])(Duneyrr*) = {
    FUN_08024c38,
    FUN_08024c84,
    FUN_08024cec,
    FUN_08024e58,
    FUN_08024fe4,
    FUN_0802506c,
    FUN_08025170,
    FUN_080251f0,
    FUN_0802523c,
};  // 0x085AAB08

void FUN_0802534c(Duneyrr*);
void FUN_080253b8(Duneyrr*);

void (*const PTR_ARRAY_085aab2c[2])(Duneyrr*) = {
    FUN_0802534c,
    FUN_080253b8,
};  // 0x085AAB2C

void FUN_080253dc(Duneyrr*);
void FUN_08025414(Duneyrr*);
void FUN_08025458(Duneyrr*);
void FUN_0802549c(Duneyrr*);
void FUN_08025504(Duneyrr*);

void (*const PTR_ARRAY_085aab34[5])(Duneyrr*) = {
    FUN_080253dc,
    FUN_08025414,
    FUN_08025458,
    FUN_0802549c,
    FUN_08025504,
};  // 0x085AAB34

void FUN_08025568(Duneyrr*);

void (*const PTR_ARRAY_085aab48[1])(Duneyrr*) = {
    FUN_08025568,
};  // 0x085AAB48

void FUN_08025584(Duneyrr*);

void (*const PTR_ARRAY_085aab4c[1])(Duneyrr*) = {
    FUN_08025584,
};  // 0x085AAB4C

void FUN_080255a0(Duneyrr*);

void (*const PTR_ARRAY_085aab50[1])(Duneyrr*) = {
    FUN_080255a0,
};  // 0x085AAB50

void FUN_080255bc(Duneyrr*);
void FUN_080255f8(Duneyrr*);
void FUN_08025614(Duneyrr*);

void (*const PTR_ARRAY_085aab54[3])(Duneyrr*) = {
    FUN_080255bc,
    FUN_080255f8,
    FUN_08025614,
};  // 0x085AAB54

void FUN_08025654(Duneyrr*, s32);
void FUN_080256c4(Duneyrr*, s32);
void FUN_08025830(Duneyrr*, s32);
void FUN_08025948(Duneyrr*, s32);
void FUN_08025c84(Duneyrr*, s32);
void FUN_08025cf8(Duneyrr*, s32);
void FUN_08025e10(Duneyrr*, s32);
void FUN_08025f8c(Duneyrr*, s32);
void FUN_0802604c(Duneyrr*, s32);
void FUN_080261b4(Duneyrr*, s32);
void FUN_080262c0(Duneyrr*, s32);
void FUN_08026334(Duneyrr*, s32);
void FUN_08026514(Duneyrr*, s32);
void FUN_08026738(Duneyrr*, s32);
void FUN_08026968(Duneyrr*, s32);
void FUN_08026c50(Duneyrr*, s32);
void FUN_08027090(Duneyrr*, s32);
void FUN_08027188(Duneyrr*, s32);
void FUN_080271e0(Duneyrr*, s32);
void FUN_08027278(Duneyrr*, s32);
void FUN_0802730c(Duneyrr*, s32);
void FUN_08027454(Duneyrr*, s32);

// clang-format off
void (*const PTR_ARRAY_085aab60[23])(Duneyrr*, s32) = {
    NULL,
    FUN_08025654,
    FUN_080256c4,
    FUN_08025830,
    FUN_08025948,
    FUN_08025c84,
    FUN_08025cf8,
    FUN_08025e10,
    FUN_08025f8c,
    FUN_0802604c,
    FUN_080261b4,
    FUN_080262c0,
    FUN_08026334,
    FUN_08026514,
    FUN_08026738,
    FUN_08026968,
    FUN_08026c50,
    FUN_08027090,
    FUN_08027188,
    FUN_080271e0,
    FUN_08027278,
    FUN_0802730c,
    FUN_08027454,
};  // 0x085AAB60
// clang-format on

INCASM("asm/duneyrr.inc");

void FUN_08024500(Duneyrr*);
void FUN_08025630(Duneyrr*);
void FUN_08027588(Duneyrr*);
void FUN_080245e4(Duneyrr*);

s32 Duneyrr_Update(Duneyrr* p) {
  FUN_08024500(p);
  FUN_08025630(p);
  FUN_08027588(p);
  FUN_080245e4(p);
  return 0;
}

NAKED s32 Duneyrr_Destroy(Duneyrr* p) { INCFUNC("asm/func/Duneyrr_Destroy.inc"); }

NAKED s32 Duneyrr_Init(Duneyrr* p, u32 id) { INCFUNC("asm/func/Duneyrr_Init.inc"); }

Duneyrr* Duneyrr_Create(u32 id) {
  Duneyrr* p = FUN_08022a2c(BOSS_DUNEYRR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Duneyrr));
  if (p != NULL) {
    SetEntityRoutine(p, Duneyrr_Update, Duneyrr_Destroy);
    if (Duneyrr_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
