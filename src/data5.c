#include "global.h"

const u8 u8_ARRAY_ARRAY_08dbd798[6][2] = {
    {2, 2},
    {2, 0},
    {0, 0},
    {0, 1},
    {1, 2},
    {2, 2},
};  // 0x08DBD798

const u16 u16_ARRAY_08dbd7a4[11] = {
    0x0, 0x5, 0xC, 0x16, 0x22, 0x31, 0x42, 0x56, 0x6D, 0x8B, 0x8C,
};  // 0x08DBD7A4

const u16 u16_ARRAY_08dbd7ba[11] = {
    0x0, 0x1, 0x6, 0xD, 0x17, 0x23, 0x32, 0x43, 0x57, 0x6E, 0x8C,
};  // 0x08DBD7BA

const u32 u32_ARRAY_ARRAY_08dbd7d0[6][2] = {
    {0x1,      0x2 },
    {0x2,      0x1 },
    {0x200004, 0x8 },
    {0x400008, 0x4 },
    {0x4010,   0x20},
    {0x8020,   0x10},
};  // 0x08DBD7D0

// --------------------------------------------

void FUN_08246090(unknown*, unknown*, unknown*);
void FUN_0824617c(unknown*, unknown*, unknown*);
void FUN_082462f4(unknown*, unknown*, unknown*);
void FUN_082463cc(unknown*, unknown*, unknown*);

void (*const PTR_ARRAY_08dbd800[4])(unknown*, unknown*, unknown*) = {
    FUN_08246090,
    FUN_0824617c,
    FUN_082462f4,
    FUN_082463cc,
};  // 0x08DBD800
