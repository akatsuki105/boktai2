#include "global.h"

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
