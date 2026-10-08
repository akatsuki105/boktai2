#include "global.h"

// ---------------- code_08052eb8.s -----------------

void FUN_08055fe4(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080561b8(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080563b0(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080573a0(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08057478(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805758c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080579a4(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08057db0(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080581dc(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08058460(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080587cc(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08058a98(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08058ae4(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080595a4(unknown* p, unknown* param_2, unknown* param_3);
void FUN_080595a8(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805965c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08059804(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08059d60(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08059d98(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08059e9c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_08059f1c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805a09c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805a0dc(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805a938(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805a988(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805a9e8(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805ab18(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805ab70(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805ad78(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805ae44(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805b36c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805b4d0(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805b640(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805bd68(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805be28(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805bf60(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805c330(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805c4c4(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805c644(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805c9b4(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805cb7c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805cd08(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805ce28(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805d0a0(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805d0f0(unknown* p, unknown* param_2, unknown* param_3);

// FUN_08055fe4 / FUN_080561b8 が引く
const u16 u16_ARRAY_085ab990[4] = {4, 1, 2, 4};  // 0x085AB990

// FUN_080564f0 が引く
void (*const PTR_ARRAY_085ab998[3])(unknown*, unknown*, unknown*) = {
    FUN_08055fe4,
    FUN_080561b8,
    FUN_080563b0,
};  // 0x085AB998

// 推測: u32[4] = {64, 16, 0, 0}
const u8 u8_ARRAY_085ab9a4[16] = {0x40, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};  // 0x085AB9A4

// FUN_08058ca8 が引く
void (*const PTR_ARRAY_085ab9b4[10])(unknown*, unknown*, unknown*) = {
    FUN_080573a0,
    FUN_08057478,
    FUN_0805758c,
    FUN_080579a4,
    FUN_08057db0,
    FUN_080581dc,
    FUN_08058460,
    FUN_080587cc,
    FUN_08058a98,
    FUN_08058ae4,
};  // 0x085AB9B4

// FUN_08059820 が引く
void (*const PTR_ARRAY_085ab9dc[4])(unknown*, unknown*, unknown*) = {
    FUN_080595a4,
    FUN_080595a8,
    FUN_0805965c,
    FUN_08059804,
};  // 0x085AB9DC

// FUN_0805a22c が引く
void (*const PTR_ARRAY_085ab9ec[6])(unknown*, unknown*, unknown*) = {
    FUN_08059d60,
    FUN_08059d98,
    FUN_08059e9c,
    FUN_08059f1c,
    FUN_0805a09c,
    FUN_0805a0dc,
};  // 0x085AB9EC

// FUN_0805afb8 が引く
void (*const PTR_ARRAY_085aba04[7])(unknown*, unknown*, unknown*) = {
    FUN_0805a938,
    FUN_0805a988,
    FUN_0805a9e8,
    FUN_0805ab18,
    FUN_0805ab70,
    FUN_0805ad78,
    FUN_0805ae44,
};  // 0x085ABA04

// FUN_0805b6e0 が引く
void (*const PTR_ARRAY_085aba20[3])(unknown*, unknown*, unknown*) = {
    FUN_0805b36c,
    FUN_0805b4d0,
    FUN_0805b640,
};  // 0x085ABA20

// FUN_0805d124 が引く
void (*const PTR_ARRAY_085aba2c[12])(unknown*, unknown*, unknown*) = {
    FUN_0805bd68,
    FUN_0805bf60,
    FUN_0805be28,
    FUN_0805c330,
    FUN_0805c4c4,
    FUN_0805c644,
    FUN_0805c9b4,
    FUN_0805cb7c,
    FUN_0805cd08,
    FUN_0805ce28,
    FUN_0805d0a0,
    FUN_0805d0f0,
};  // 0x085ABA2C

// ---------------- entity_0805e67c.c -----------------

void FUN_0805e04c(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805e050(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805e110(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805e1fc(unknown* p, unknown* param_2, unknown* param_3);
void FUN_0805e2fc(unknown* p, unknown* param_2, unknown* param_3);

// Entity0805e67c_Update が引く
void (*const PTR_ARRAY_085aba5c[5])(unknown*, unknown*, unknown*) = {
    FUN_0805e04c,
    FUN_0805e050,
    FUN_0805e110,
    FUN_0805e1fc,
    FUN_0805e2fc,
};  // 0x085ABA5C
