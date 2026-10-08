#include "boss.h"
#include "entity.h"
#include "global.h"

// 紅のリンゴ, ダーイン
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[4188 - 0x18];
} EntityBA4B;
static_assert(sizeof(EntityBA4B) == 4188);

// s8 かも?
const u8 u8_ARRAY_085aabbc[20] = {0x9, 0xFC, 0x9, 0xF9, 0x7, 0xF8, 0x7, 0xFA, 0x7, 0xFB, 0x7, 0xFA, 0x7, 0xFB, 0x7, 0xFA, 0x7, 0xFB, 0x7, 0xF8};  // 0x085AABBC

// s8 かも?
const u8 u8_ARRAY_085aabd0[8] = {0x1, 0xE4, 0x0, 0xE0, 0x0, 0xE1, 0x2, 0xE8};  // 0x085AABD0

const u8 u8_ARRAY_085aabd8[64] = {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,  0x0, 0x4,  0x2, 0x6,  0x4, 0x8,  0x6,  0x9,  0x8,  0xA,  0xA,  0xB,  0xC,  0xC,  0xE,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x8, 0xFC, 0xA, 0xF8, 0xC, 0xF6, 0xE, 0xF4, 0x10, 0xF2, 0x13, 0xF0, 0x17, 0xEE, 0x1C, 0xEC, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};  // 0x085AABD8

const rgb555 rgb555_ARRAY_085aac18[16] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};  // 0x085AAC18

void FUN_0802c3a0(EntityBA4B*);
void FUN_0802c564(EntityBA4B*);
void FUN_0802c6e8(EntityBA4B*);
void FUN_0802c73c(EntityBA4B*);
void FUN_0802c7e0(EntityBA4B*);
void FUN_0802c87c(EntityBA4B*);
void FUN_0802c8e0(EntityBA4B*);
void FUN_0802cca0(EntityBA4B*);
void FUN_0802cd2c(EntityBA4B*);
void FUN_0802cda4(EntityBA4B*);
void FUN_0802ce30(EntityBA4B*);
void FUN_0802cea8(EntityBA4B*);
void FUN_0802cf34(EntityBA4B*);
void FUN_0802cff4(EntityBA4B*);
void FUN_0802d074(EntityBA4B*);
void FUN_0802d134(EntityBA4B*);
void FUN_0802d294(EntityBA4B*);
void FUN_0802d36c(EntityBA4B*);
void FUN_0802d420(EntityBA4B*);
void FUN_0802d4bc(EntityBA4B*);
void FUN_0802d5dc(EntityBA4B*);
void FUN_0802d648(EntityBA4B*);
void FUN_0802d6c8(EntityBA4B*);
void FUN_0802d738(EntityBA4B*);
void FUN_0802d85c(EntityBA4B*);
void FUN_0802d8d0(EntityBA4B*);
void FUN_0802d92c(EntityBA4B*);
void FUN_0802d988(EntityBA4B*);
void FUN_0802d9f8(EntityBA4B*);
void FUN_0802da30(EntityBA4B*);

// clang-format off
void (*const PTR_ARRAY_085aac38[30])(EntityBA4B*) = {
    FUN_0802c3a0,
    FUN_0802c564,
    FUN_0802c6e8,
    FUN_0802c73c,
    FUN_0802c7e0,
    FUN_0802c87c,
    FUN_0802c8e0,
    FUN_0802cca0,
    FUN_0802cd2c,
    FUN_0802cda4,
    FUN_0802ce30,
    FUN_0802cea8,
    FUN_0802cf34,
    FUN_0802cff4,
    FUN_0802d074,
    FUN_0802d134,
    FUN_0802d294,
    FUN_0802d36c,
    FUN_0802d420,
    FUN_0802d4bc,
    FUN_0802d5dc,
    FUN_0802d648,
    FUN_0802d6c8,
    FUN_0802d738,
    FUN_0802d85c,
    FUN_0802d8d0,
    FUN_0802d92c,
    FUN_0802d988,
    FUN_0802d9f8,
    FUN_0802da30,
};  // 0x085AAC38
// clang-format on

void FUN_0802daa0(EntityBA4B*);
void FUN_0802db18(EntityBA4B*);

void (*const PTR_ARRAY_085aacb0[2])(EntityBA4B*) = {
    FUN_0802daa0,
    FUN_0802db18,
};  // 0x085AACB0

void FUN_0802db3c(EntityBA4B*);
void FUN_0802db74(EntityBA4B*);
void FUN_0802dbb8(EntityBA4B*);
void FUN_0802dbfc(EntityBA4B*);
void FUN_0802dc5c(EntityBA4B*);
void FUN_0802dcbc(EntityBA4B*);
void FUN_0802dd24(EntityBA4B*);
void FUN_0802dd84(EntityBA4B*);
void FUN_0802dde8(EntityBA4B*);
void FUN_0802de2c(EntityBA4B*);
void FUN_0802dea4(EntityBA4B*);
void FUN_0802df04(EntityBA4B*);
void FUN_0802df64(EntityBA4B*);
void FUN_0802dfb4(EntityBA4B*);
void FUN_0802e004(EntityBA4B*);
void FUN_0802e054(EntityBA4B*);
void FUN_0802e0a4(EntityBA4B*);
void FUN_0802e0e8(EntityBA4B*);
void FUN_0802e138(EntityBA4B*);
void FUN_0802e198(EntityBA4B*);
void FUN_0802e210(EntityBA4B*);
void FUN_0802e274(EntityBA4B*);
void FUN_0802e2d8(EntityBA4B*);
void FUN_0802e340(EntityBA4B*);
void FUN_0802e384(EntityBA4B*);
void FUN_0802e3e4(EntityBA4B*);

// clang-format off
void (*const PTR_ARRAY_085aacb8[26])(EntityBA4B*) = {
    FUN_0802db3c,
    FUN_0802db74,
    FUN_0802dbb8,
    FUN_0802dbfc,
    FUN_0802dc5c,
    FUN_0802dcbc,
    FUN_0802dd24,
    FUN_0802dd84,
    FUN_0802dde8,
    FUN_0802de2c,
    FUN_0802dea4,
    FUN_0802df04,
    FUN_0802df64,
    FUN_0802dfb4,
    FUN_0802e004,
    FUN_0802e054,
    FUN_0802e0a4,
    FUN_0802e0e8,
    FUN_0802e138,
    FUN_0802e198,
    FUN_0802e210,
    FUN_0802e274,
    FUN_0802e2d8,
    FUN_0802e340,
    FUN_0802e384,
    FUN_0802e3e4,
};  // 0x085AACB8
// clang-format on

void FUN_0802e434(EntityBA4B*);
void FUN_0802e450(EntityBA4B*);
void FUN_0802e46c(EntityBA4B*);

void (*const PTR_ARRAY_085aad20[3])(EntityBA4B*) = {
    FUN_0802e434,
    FUN_0802e450,
    FUN_0802e46c,
};  // 0x085AAD20

void FUN_0802e488(EntityBA4B*);
void FUN_0802e4c4(EntityBA4B*);
void FUN_0802e4e0(EntityBA4B*);

void (*const PTR_ARRAY_085aad2c[3])(EntityBA4B*) = {
    FUN_0802e488,
    FUN_0802e4c4,
    FUN_0802e4e0,
};  // 0x085AAD2C

void FUN_0802e520(EntityBA4B*, s32);
void FUN_0802e6ac(EntityBA4B*, s32);
void FUN_0802e8d0(EntityBA4B*, s32);
void FUN_0802eac0(EntityBA4B*, s32);
void FUN_0802ece0(EntityBA4B*, s32);
void FUN_0802ef68(EntityBA4B*, s32);
void dainn_0802f134(EntityBA4B*, s32);
void FUN_0802f368(EntityBA4B*, s32);
void FUN_0802f4a8(EntityBA4B*, s32);
void FUN_0802f5e8(EntityBA4B*, s32);
void FUN_0802fabc(EntityBA4B*, s32);
void dainn_0802fc08(EntityBA4B*, s32);
void dainn_0802fea0(EntityBA4B*, s32);
void FUN_08030148(EntityBA4B*, s32);
void FUN_080304c0(EntityBA4B*, s32);
void FUN_08030680(EntityBA4B*, s32);
void dainn_08030960(EntityBA4B*, s32);
void FUN_08030b80(EntityBA4B*, s32);
void dainn_08030d6c(EntityBA4B*, s32);
void dainn_0803110c(EntityBA4B*, s32);
void dainn_0803141c(EntityBA4B*, s32);
void FUN_080315e0(EntityBA4B*, s32);
void FUN_0803166c(EntityBA4B*, s32);
void FUN_08031734(EntityBA4B*, s32);
void FUN_080317f0(EntityBA4B*, s32);
void FUN_08031f14(EntityBA4B*, s32);
void FUN_08032180(EntityBA4B*, s32);
void dainn_080323c8(EntityBA4B*, s32);
void FUN_08032934(EntityBA4B*, s32);
void FUN_08032988(EntityBA4B*, s32);
void FUN_08032acc(EntityBA4B*, s32);
void FUN_08032bac(EntityBA4B*, s32);
void FUN_08032e1c(EntityBA4B*, s32);
void dainn_08032f18(EntityBA4B*, s32);
void FUN_0803331c(EntityBA4B*, s32);
void FUN_080333a4(EntityBA4B*, s32);
void FUN_080334b4(EntityBA4B*, s32);
void FUN_080335e8(EntityBA4B*, s32);
void FUN_080337b8(EntityBA4B*, s32);
void FUN_08033970(EntityBA4B*, s32);
void FUN_08033b28(EntityBA4B*, s32);
void FUN_08033c60(EntityBA4B*, s32);
void FUN_08033d84(EntityBA4B*, s32);
void FUN_08033e3c(EntityBA4B*, s32);
void FUN_08034014(EntityBA4B*, s32);
void FUN_0803419c(EntityBA4B*, s32);
void FUN_0803427c(EntityBA4B*, s32);
void FUN_0803446c(EntityBA4B*, s32);
void FUN_08034570(EntityBA4B*, s32);
void FUN_080346cc(EntityBA4B*, s32);
void FUN_08034804(EntityBA4B*, s32);
void FUN_0803495c(EntityBA4B*, s32);
void FUN_08034a2c(EntityBA4B*, s32);
void FUN_08034b18(EntityBA4B*, s32);
void FUN_08034dd8(EntityBA4B*, s32);
void FUN_08034ebc(EntityBA4B*, s32);
void FUN_08035268(EntityBA4B*, s32);
void FUN_080353ac(EntityBA4B*, s32);
void FUN_0803558c(EntityBA4B*, s32);
void FUN_08035634(EntityBA4B*, s32);
void FUN_080356f8(EntityBA4B*, s32);

// clang-format off
void (*const PTR_ARRAY_085aad38[62])(EntityBA4B*, s32) = {
    NULL,
    FUN_0802e520,
    FUN_0802e6ac,
    FUN_0802e8d0,
    FUN_0802eac0,
    FUN_0802ece0,
    FUN_0802ef68,
    dainn_0802f134,
    FUN_0802f368,
    FUN_0802f4a8,
    FUN_0802f5e8,
    FUN_0802fabc,
    dainn_0802fc08,
    dainn_0802fea0,
    FUN_08030148,
    FUN_080304c0,
    FUN_08030680,
    dainn_08030960,
    FUN_08030b80,
    dainn_08030d6c,
    dainn_0803110c,
    dainn_0803141c,
    FUN_080315e0,
    FUN_0803166c,
    FUN_08031734,
    FUN_080317f0,
    FUN_08031f14,
    FUN_08032180,
    dainn_080323c8,
    FUN_08032934,
    FUN_08032988,
    FUN_08032acc,
    FUN_08032bac,
    FUN_08032e1c,
    dainn_08032f18,
    FUN_0803331c,
    FUN_080333a4,
    FUN_080334b4,
    FUN_080335e8,
    FUN_080337b8,
    FUN_08033970,
    FUN_08033b28,
    FUN_08033c60,
    FUN_08033d84,
    FUN_08033e3c,
    FUN_08034014,
    FUN_0803419c,
    FUN_0803427c,
    FUN_0803446c,
    FUN_08034570,
    FUN_080346cc,
    FUN_08034804,
    FUN_0803495c,
    FUN_08034a2c,
    FUN_08034b18,
    FUN_08034dd8,
    FUN_08034ebc,
    FUN_08035268,
    FUN_080353ac,
    FUN_0803558c,
    FUN_08035634,
    FUN_080356f8,
};  // 0x085AAD38
// clang-format on

INCASM("asm/entity_ba4b.inc");

NAKED s32 EntityBA4B_Update(EntityBA4B* p) { INCFUNC("asm/func/EntityBA4B_Update.inc"); }

NAKED s32 EntityBA4B_Destroy(EntityBA4B* p) { INCFUNC("asm/func/EntityBA4B_Destroy.inc"); }

NAKED s32 EntityBA4B_Init(EntityBA4B* p, u32 id) { INCFUNC("asm/func/EntityBA4B_Init.inc"); }

NAKED EntityBA4B* EntityBA4B_Create(u32 id) { INCFUNC("asm/func/EntityBA4B_Create.inc"); }
