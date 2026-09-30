#include "entity.h"
#include "global.h"
#include "sprite.h"

// クロスオーバー: コラボでロックマンエグゼ4との通信対戦ができた
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[1668 - 0x18];
} CrossoverLobby;
static_assert(sizeof(CrossoverLobby) == 1668);

typedef struct {
  SpriteID16 id;  // 0x0
  u16 unk_2;      // 0x2
  u8 unk_4;       // 0x4
  u8 unk_5;       // 0x5
  u8 unk_6;       // 0x6
  u8 unk_7;       // 0x7, padding?
} Unk085ab674;

const Unk085ab674 Unk085ab674_ARRAY_085ab674[2] = {
    {id : SPRITE_PORTRAITS, unk_2 : 0,  unk_4 : 0, unk_5 : 0x30, unk_6 : 0x20},
    {id : SPRITE_PORTRAITS, unk_2 : 24, unk_4 : 4, unk_5 : 0xC0, unk_6 : 0x20}
};  // 0x085AB674

void FUN_0804f16c(CrossoverLobby*);
void FUN_0804f1d8(CrossoverLobby*);
void FUN_0804f230(CrossoverLobby*);
void FUN_0804f3d8(CrossoverLobby*);
void FUN_0804f404(CrossoverLobby*);
void FUN_0804f448(CrossoverLobby*);
void FUN_0804f47c(CrossoverLobby*);
void FUN_0804f4b0(CrossoverLobby*);

void (*const sCrossoverLobbyUpdates[8])(CrossoverLobby*) = {
    FUN_0804f16c, FUN_0804f1d8, FUN_0804f230, FUN_0804f3d8, FUN_0804f404, FUN_0804f448, FUN_0804f47c, FUN_0804f4b0,
};  // 0x085AB684

NAKED void FUN_0804edc8(CrossoverLobby* p, s32 n) { INCFUNC("asm/func/FUN_0804edc8.inc"); }

INCASM("asm/crossover_lobby.inc");
