#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_2
  u8 unk_18[76 - 0x18];
} EntityFB53;
static_assert(sizeof(EntityFB53) == 76);

IWRAM_DATA s32 s32_030000d4 = 0;            // 0x030000D4
IWRAM_DATA EntityFB53* gEntityFB53 = NULL;  // 0x030000D8
IWRAM_DATA u8 u8_030000dc = 0;

const u8 u8_ARRAY_085ab5b0[8] = {0x67, 0x8E, 0xAA, 0x8F, 0xE0, 0x90, 0xD6, 0x8F};  // 0x085AB5B0

void FUN_0804b474(EntityFB53* p);
void FUN_0804b530(EntityFB53* p);
void FUN_0804b5f0(EntityFB53* p);
void FUN_0804b65c(EntityFB53* p);
void FUN_0804b6bc(EntityFB53* p);
void FUN_0804b71c(EntityFB53* p);
void FUN_0804b774(EntityFB53* p);
void FUN_0804b7d0(EntityFB53* p);
void FUN_0804b83c(EntityFB53* p);
void FUN_0804b870(EntityFB53* p);

void (*const PTR_ARRAY_085ab5b8[10])(EntityFB53*) = {
    FUN_0804b474, FUN_0804b530, FUN_0804b5f0, FUN_0804b65c, FUN_0804b6bc, FUN_0804b71c, FUN_0804b774, FUN_0804b7d0, FUN_0804b83c, FUN_0804b870,
};  // 0x085AB5B8

void FUN_0804c3cc(unknown*);
void FUN_0804c3e4(unknown*);
void FUN_0804c438(unknown*);
void FUN_0804c57c(unknown*);
void FUN_0804c5c0(unknown*);
void FUN_0804c5d8(unknown*);
void FUN_0804c650(unknown*);
void FUN_0804c6ac(unknown*);
void FUN_0804c7c8(unknown*);
void FUN_0804c888(unknown*);
void FUN_0804c8bc(unknown*);
void FUN_0804c8f4(unknown*);
void FUN_0804c940(unknown*);
void FUN_0804c978(unknown*);
void FUN_0804c9a8(unknown*);
void FUN_0804cb6c(unknown*);
void FUN_0804cb84(unknown*);
void FUN_0804cb9c(unknown*);
void FUN_0804cbb4(unknown*);
void FUN_0804d698(unknown*);
void FUN_0804d6d0(unknown*);
void FUN_0804da50(unknown*);
void FUN_0804de18(unknown*);
void FUN_0804da78(unknown*);
void FUN_0804de40(unknown*);
void FUN_0804dae4(unknown*);
void FUN_0804de58(unknown*);
void FUN_0804cbcc(unknown*);
void FUN_0804cbfc(unknown*);
void FUN_0804cc38(unknown*);
void FUN_0804cc7c(unknown*);
void FUN_0804cc98(unknown*);
void FUN_0804ccbc(unknown*);

void (*const PTR_ARRAY_085ab5e0[33])(unknown*) = {
    FUN_0804c3cc, FUN_0804c3e4, FUN_0804c438, FUN_0804c57c, FUN_0804c5c0, FUN_0804c5d8, FUN_0804c650, FUN_0804c6ac, FUN_0804c7c8, FUN_0804c888, FUN_0804c8bc, FUN_0804c8f4, FUN_0804c940, FUN_0804c978, FUN_0804c9a8, FUN_0804cb6c, FUN_0804cb84, FUN_0804cb9c, FUN_0804cbb4, FUN_0804d698, FUN_0804d6d0, FUN_0804da50, FUN_0804de18, FUN_0804da78, FUN_0804de40, FUN_0804dae4, FUN_0804de58, FUN_0804cbcc, FUN_0804cbfc, FUN_0804cc38, FUN_0804cc7c, FUN_0804cc98, FUN_0804ccbc,
};  // 0x085AB5E0

INCASM("asm/entity_fb53.inc");
