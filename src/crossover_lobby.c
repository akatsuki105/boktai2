#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[1668 - 0x18];
} CrossoverLobby;
static_assert(sizeof(CrossoverLobby) == 1668);

NAKED void FUN_0804edc8(CrossoverLobby* p, s32 n) { INCFUNC("asm/func/FUN_0804edc8.inc"); }

INCASM("asm/crossover_lobby.inc");
