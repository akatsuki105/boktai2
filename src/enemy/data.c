#include "enemy.h"
#include "global.h"

// src/enemy.c / src/enedefault.c にある共通ハンドラ
void FUN_080e6624(Enemy* p, u16* msg);
void FUN_080e664c(Enemy* p, u16* msg);
void FUN_080f07d0(Enemy* p);
void FUN_080f0868(Enemy* p);
void FUN_080f0914(Enemy* p);
void FUN_080f09a4(Enemy* p);
void FUN_080f0e78(Enemy* p);
void FUN_080f11d0(Enemy* p);
void FUN_080f12c4(Enemy* p);
void FUN_080f19cc(Enemy* p);
void FUN_080f1c54(Enemy* p);
void FUN_080f1cb8(Enemy* p);
void FUN_080f1cf0(Enemy* p);
void FUN_080f1de4(Enemy* p);
void FUN_080f1e0c(Enemy* p);
void FUN_080f1e78(Enemy* p);
void FUN_080f1ef8(Enemy* p);
void FUN_080f2074(Enemy* p);
void FUN_080f2160(Enemy* p);
void FUN_080f2364(Enemy* p);
void FUN_080f248c(Enemy* p);
void FUN_080f2644(Enemy* p);
void FUN_080f2864(Enemy* p);
void FUN_080f2a40(Enemy* p);
void FUN_080f2d04(Enemy* p);
void FUN_080f2ec0(Enemy* p);
void FUN_080f31c4(Enemy* p);
void FUN_080f33e8(Enemy* p);
void FUN_080f34a0(Enemy* p);
void FUN_080f9c20(Enemy* p);
void FUN_080f9e34(Enemy* p);
void FUN_080f9ee0(Enemy* p);

// ---------------- skeleton.c -----------------

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

// ---------------- golem.c -----------------

void FUN_0811cfb8(Enemy* p);
void FUN_0811d090(Enemy* p);
void FUN_0811d980(Enemy* p);
void FUN_0811dc98(Enemy* p);
void FUN_0811dd80(Enemy* p);
void FUN_0811edf4(Enemy* p);
void FUN_0811f04c(Enemy* p);
void FUN_0811f90c(Enemy* p);
void FUN_0811f990(Enemy* p);
void FUN_0811fab8(Enemy* p);
void FUN_0811fbd0(Enemy* p);
void FUN_0812019c(Enemy* p);

const u16 u16_ARRAY_085ad5f8[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085AD5F8
const u16 u16_ARRAY_085ad608[2] = {0, 4};                                // 0x085AD608

void (*const PTR_ARRAY_085ad60c[2])(Enemy*) = {
    FUN_0811cfb8,
    FUN_0811d090,
};  // 0x085AD60C

void (*const PTR_ARRAY_085ad614[10])(Enemy*) = {
    FUN_0811d980,
    FUN_0811dd80,
    FUN_0811edf4,
    FUN_0811f04c,
    FUN_0811f90c,
    FUN_0811f990,
    FUN_0811dc98,
    FUN_0811fbd0,
    FUN_0811fab8,
    FUN_0812019c,
};  // 0x085AD614

// ---------------- mummy.s -----------------

void FUN_08125d3c(Enemy* p);
void FUN_08125e1c(Enemy* p);
void FUN_081266f4(Enemy* p);
void FUN_08126780(Enemy* p);
void FUN_08126b34(Enemy* p);
void FUN_081272d0(Enemy* p);
void FUN_08127434(Enemy* p);
void FUN_08127524(Enemy* p);
void FUN_0812c038(Enemy* p);
void FUN_0812c7c0(Enemy* p);

void (*const PTR_ARRAY_085ad63c[2])(Enemy*) = {
    FUN_08125d3c,
    FUN_08125e1c,
};  // 0x085AD63C

// clang-format off
void (*const PTR_ARRAY_085ad644[19])(Enemy*) = {
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
    FUN_08126780,
    FUN_080f11d0,
    FUN_08126b34,
    FUN_081266f4,
    FUN_081272d0,
    FUN_08127434,
    FUN_08127524,
};  // 0x085AD644
// clang-format on

const u16 u16_ARRAY_085ad690[4] = {0, 120, 260, 200};  // 0x085AD690

const u8 u8_ARRAY_085ad698[4] = {0, 4, 8, 8};  // 0x085AD698

const s16 s16_ARRAY_085ad69c[12] = {-102, 102, 0, 0, 0, 0, 102, -102, -48, 48, 0, 0};  // 0x085AD69C

void (*const PTR_ARRAY_085ad6b4[2])(Enemy*) = {
    FUN_0812c038,
    FUN_0812c7c0,
};  // 0x085AD6B4

// ---------------- spider.c -----------------

void FUN_0812f83c(Enemy* p);
void FUN_0812f840(Enemy* p);
void FUN_0812f9ec(Enemy* p);
void FUN_0812fbec(Enemy* p);
void FUN_0812fcd8(Enemy* p);
void FUN_0812fdb8(Enemy* p);
void FUN_08130068(Enemy* p);
void FUN_081302f8(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad6bc[17])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_0812fdb8,
    FUN_0812fbec,
    FUN_0812f9ec,
    NULL,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_0812f840,
    FUN_0812fcd8,
    NULL,
    FUN_08130068,
    FUN_0812f83c,
};  // 0x085AD6BC

void (*const PTR_ARRAY_085ad700[3])(Enemy*) = {
    FUN_080f1c54,
    FUN_080f1cb8,
    FUN_080f1cf0,
};  // 0x085AD700

const u16 u16_ARRAY_085ad70c[2] = {486, 486};  // 0x085AD70C

void (*const PTR_ARRAY_085ad710[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_081302f8,
};  // 0x085AD710

// ---------------- centipede.s -----------------

void FUN_08134448(Enemy* p);
void FUN_08134738(Enemy* p);
void FUN_081349dc(Enemy* p);
void FUN_08134ccc(Enemy* p);
void FUN_08134e88(Enemy* p);
void FUN_08134fb4(Enemy* p);
void FUN_081352d4(Enemy* p);
void FUN_0813544c(Enemy* p);
void FUN_08138b34(Enemy* p);

void (*const PTR_ARRAY_085ad72c[12])(Enemy*) = {
    FUN_08134ccc,
    FUN_08134fb4,
    FUN_08134448,
    FUN_080f2364,
    FUN_0813544c,
    FUN_081352d4,
    FUN_08134e88,
    FUN_08134738,
    FUN_081349dc,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
};  // 0x085AD72C

const u32 u32_ARRAY_085ad75c[4] = {28, 31, 38, 48};  // 0x085AD75C

void (*const PTR_ARRAY_085ad76c[1])(Enemy*) = {
    FUN_08138b34,
};  // 0x085AD76C

// ---------------- curoro.c -----------------

void FUN_0813b824(Enemy* p);
void FUN_0813bb04(Enemy* p);
void FUN_0813bc50(Enemy* p);
void FUN_0813be38(Enemy* p);
void FUN_0813bf78(Enemy* p);
void FUN_0813ce1c(Enemy* p);
void FUN_0813d080(Enemy* p);
void FUN_0813d1d0(Enemy* p);
void FUN_0813d274(Enemy* p);

void FUN_0813c14c(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad770[5])(Enemy*) = {
    FUN_0813bc50,
    FUN_0813bb04,
    FUN_0813b824,
    FUN_0813bf78,
    FUN_0813be38,
};  // 0x085AD770

const u32 u32_ARRAY_085ad784[8] = {2, 3, 4, 6, 8, 9, 10, 12};  // 0x085AD784

void (*const PTR_ARRAY_085ad7a4[2])(Enemy*) = {
    FUN_0813d080,
    FUN_0813ce1c,
};  // 0x085AD7A4

void (*const PTR_ARRAY_085ad7ac[2])(Enemy*) = {
    FUN_0813d1d0,
    FUN_0813d274,
};  // 0x085AD7AC

// メッセージ表
void (*const PTR_ARRAY_085ad7b4[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0813c14c,
};  // 0x085AD7B4

// ---------------- bat.c -----------------

void FUN_0813f9a8(Enemy* p);
void FUN_0813fbf8(Enemy* p);
void FUN_0813fc9c(Enemy* p);
void FUN_0813fd24(Enemy* p);
void FUN_0813fe34(Enemy* p);
void FUN_08140eb0(Enemy* p);
void FUN_081410cc(Enemy* p);

void FUN_08140278(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad7d0[5])(Enemy*) = {
    FUN_0813fc9c,
    FUN_0813fbf8,
    FUN_0813f9a8,
    FUN_0813fd24,
    FUN_0813fe34,
};  // 0x085AD7D0

const u32 u32_ARRAY_085ad7e4[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085AD7E4

void (*const PTR_ARRAY_085ad804[2])(Enemy*) = {
    FUN_08140eb0,
    FUN_081410cc,
};  // 0x085AD804

// メッセージ表
void (*const PTR_ARRAY_085ad80c[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08140278,
};  // 0x085AD80C

// ---------------- crow.c -----------------

void FUN_081436b4(Enemy* p);
void FUN_081439d8(Enemy* p);
void FUN_08143dd4(Enemy* p);
void FUN_08143ef8(Enemy* p);
void FUN_08143fac(Enemy* p);
void FUN_08144cd0(Enemy* p);
void FUN_08144ec8(Enemy* p);
void FUN_081452cc(Enemy* p);

void FUN_08144160(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad828[5])(Enemy*) = {
    FUN_08143dd4,
    FUN_081439d8,
    FUN_081436b4,
    FUN_08143ef8,
    FUN_08143fac,
};  // 0x085AD828

const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

void (*const PTR_ARRAY_085ad84c[3])(Enemy*) = {
    FUN_08144cd0,
    FUN_08144ec8,
    FUN_081452cc,
};  // 0x085AD84C

// メッセージ表
void (*const PTR_ARRAY_085ad858[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08144160,
};  // 0x085AD858

// ---------------- mimic.c -----------------

void FUN_081467bc(Enemy* p);
void FUN_081468c8(Enemy* p);
void FUN_08146970(Enemy* p);
void FUN_08146a34(Enemy* p);
void FUN_08146ae8(Enemy* p);
void FUN_08146ce0(Enemy* p);
void FUN_08148c00(Enemy* p);

void (*const PTR_ARRAY_085ad874[18])(Enemy*) = {
    FUN_081467bc,
    FUN_080f2864,
    FUN_081468c8,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_08146ce0,
    FUN_080f33e8,
    FUN_080f34a0,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_08146a34,
    FUN_08146ae8,
    FUN_08146970,
};  // 0x085AD874

void (*const PTR_ARRAY_085ad8bc[1])(Enemy*) = {
    FUN_08148c00,
};  // 0x085AD8BC

const u16 u16_ARRAY_085ad8c0[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AD8C0

// ---------------- dog.s -----------------

void FUN_0814fba4(Enemy* p);
void FUN_0814fc7c(Enemy* p);
void FUN_08150534(Enemy* p);
void FUN_08150660(Enemy* p);
void FUN_08150790(Enemy* p);
void FUN_08150b18(Enemy* p);
void FUN_08150de8(Enemy* p);
void FUN_081514f0(Enemy* p);
void FUN_081516d8(Enemy* p);
void FUN_081517a8(Enemy* p);

void (*const PTR_ARRAY_085ad8e0[2])(Enemy*) = {
    FUN_0814fba4,
    FUN_0814fc7c,
};  // 0x085AD8E0

void (*const PTR_ARRAY_085ad8e8[2])(Enemy*) = {
    FUN_08150534,
    FUN_08150660,
};  // 0x085AD8E8

// clang-format off
void (*const PTR_ARRAY_085ad8f0[20])(Enemy*) = {
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
    FUN_08150de8,
    FUN_08150790,
    FUN_08150b18,
    FUN_081514f0,
    FUN_081516d8,
    FUN_081517a8,
};  // 0x085AD8F0
// clang-format on

// ---------------- cockatrice.s -----------------

void FUN_081574b4(Enemy* p);
void FUN_0815758c(Enemy* p);
void FUN_08157df4(Enemy* p);
void FUN_08158180(Enemy* p);
void FUN_08158314(Enemy* p);
void FUN_0815849c(Enemy* p);
void FUN_081585bc(Enemy* p);
void FUN_08158784(Enemy* p);
void FUN_08158914(Enemy* p);
void FUN_081589f0(Enemy* p);
void FUN_08158a08(Enemy* p);
void FUN_08158a20(Enemy* p);
void FUN_08158d90(Enemy* p);
void FUN_08158e8c(Enemy* p);
void FUN_08159594(Enemy* p);

void (*const PTR_ARRAY_085ad940[3])(Enemy*) = {
    FUN_081574b4,
    FUN_0815758c,
    FUN_08157df4,
};  // 0x085AD940

// clang-format off
void (*const PTR_ARRAY_085ad94c[21])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_08159594,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_08158a20,
    FUN_08158d90,
    FUN_08158e8c,
    FUN_0815849c,
    FUN_081585bc,
    FUN_08158180,
    FUN_08158314,
    FUN_08158784,
    FUN_08158914,
};  // 0x085AD94C
// clang-format on

void (*const PTR_ARRAY_085ad9a0[2])(Enemy*) = {
    FUN_081589f0,
    FUN_08158a08,
};  // 0x085AD9A0

const u16 u16_ARRAY_085ad9a8[14] = {512, 256, 384, 408, 674, 674, 0, 578, 642, 674, 674, 0, 578, 642};  // 0x085AD9A8

// ---------------- slime.c -----------------

void FUN_08163b04(Enemy* p);
void FUN_08163bbc(Enemy* p);
void FUN_08163d94(Enemy* p);
void FUN_08163e10(Enemy* p);

void (*const PTR_ARRAY_085ad9c4[1])(Enemy*) = {
    FUN_08163b04,
};  // 0x085AD9C4

void (*const PTR_ARRAY_085ad9c8[16])(Enemy*) = {
    FUN_08163d94,
    FUN_080f2864,
    FUN_08163bbc,
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
    FUN_08163e10,
};  // 0x085AD9C8

const u16 u16_ARRAY_085ada08[6] = {0, 16, 32, 20, 12, 0};  // 0x085ADA08

// ---------------- bee.c -----------------

void FUN_081678bc(Enemy* p);
void FUN_0816883c(Enemy* p);
void FUN_08168d2c(Enemy* p);
void FUN_08168df0(Enemy* p);
void FUN_08168eb0(Enemy* p);
void FUN_08169050(Enemy* p);
void FUN_08169188(Enemy* p);

void FUN_08167a38(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ada14[1])(Enemy*) = {
    FUN_081678bc,
};  // 0x085ADA14

const u32 u32_ARRAY_085ada18[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085ADA18

void (*const PTR_ARRAY_085ada38[5])(Enemy*) = {
    FUN_0816883c,
    FUN_08168d2c,
    FUN_08168df0,
    FUN_08168eb0,
    FUN_08169050,
};  // 0x085ADA38

void (*const PTR_ARRAY_085ada4c[7])(Enemy*) = {
    FUN_080f1de4,
    FUN_080f1e0c,
    FUN_080f1e78,
    FUN_080f1ef8,
    FUN_080f2074,
    FUN_080f2160,
    FUN_08169188,
};  // 0x085ADA4C

// メッセージ表
void (*const PTR_ARRAY_085ada68[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08167a38,
};  // 0x085ADA68

// ---------------- ghost.s -----------------

void FUN_0816be8c(Enemy* p);
void FUN_0816c164(Enemy* p);
void FUN_0816c29c(Enemy* p);
void FUN_0816c45c(Enemy* p);
void FUN_0816c6a0(Enemy* p);
void FUN_0816e1a4(Enemy* p);
void FUN_0816e3b8(Enemy* p);
void FUN_0816e828(Enemy* p);
void FUN_0816ec60(Enemy* p);
void FUN_0816ed04(Enemy* p);
void FUN_0816ee98(Enemy* p);

void FUN_0816cbf0(Enemy* p, u16* msg);
void FUN_0816cc94(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ada84[5])(Enemy*) = {
    FUN_0816c29c,
    FUN_0816c164,
    FUN_0816be8c,
    FUN_0816c45c,
    FUN_0816c6a0,
};  // 0x085ADA84

void (*const PTR_ARRAY_085ada98[3])(Enemy*) = {
    FUN_0816e1a4,
    FUN_0816e3b8,
    FUN_0816e828,
};  // 0x085ADA98

void (*const PTR_ARRAY_085adaa4[2])(Enemy*) = {
    FUN_0816ec60,
    FUN_0816ed04,
};  // 0x085ADAA4

void (*const PTR_ARRAY_085adaac[6])(Enemy*) = {
    FUN_0816ee98,
    FUN_080f1e0c,
    FUN_080f1e78,
    FUN_080f1ef8,
    FUN_080f2074,
    FUN_080f2160,
};  // 0x085ADAAC

// メッセージ表
void (*const PTR_ARRAY_085adac4[8])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0816cbf0,
    FUN_0816cc94,
};  // 0x085ADAC4

// ---------------- sandworm.s -----------------

void FUN_08172848(Enemy* p);
void FUN_08172b4c(Enemy* p);
void FUN_08172df4(Enemy* p);
void FUN_081730a4(Enemy* p);
void FUN_0817324c(Enemy* p);
void FUN_08173318(Enemy* p);
void FUN_081736b0(Enemy* p);
void FUN_081738e0(Enemy* p);
void FUN_08173a28(Enemy* p);
void FUN_08173b88(Enemy* p);
void FUN_08173f2c(Enemy* p);
void FUN_081741f0(Enemy* p);
void FUN_0817456c(Enemy* p);
void FUN_0817497c(Enemy* p);
void FUN_08174ae8(Enemy* p);
void FUN_081750ec(Enemy* p);
void FUN_08175234(Enemy* p);
void FUN_0817552c(Enemy* p);
void FUN_0817a05c(Enemy* p);

void FUN_0817568c(Enemy* p, u16* msg);

// clang-format off
void (*const PTR_ARRAY_085adae4[22])(Enemy*) = {
    FUN_081730a4,
    FUN_08173318,
    FUN_08172848,
    FUN_080f2364,
    FUN_08173a28,
    FUN_081736b0,
    FUN_0817324c,
    FUN_08172b4c,
    FUN_08172df4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_08173b88,
    FUN_081741f0,
    FUN_0817456c,
    FUN_0817497c,
    FUN_08174ae8,
    FUN_081750ec,
    FUN_08173f2c,
    FUN_08175234,
    FUN_081738e0,
    FUN_0817552c,
};  // 0x085ADAE4
// clang-format on

const u32 u32_ARRAY_085adb3c[4] = {14, 15, 19, 24};  // 0x085ADB3C

void (*const PTR_ARRAY_085adb4c[1])(Enemy*) = {
    FUN_0817a05c,
};  // 0x085ADB4C

// メッセージ表
void (*const PTR_ARRAY_085adb50[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0817568c,
};  // 0x085ADB50

const u16 u16_ARRAY_085adb6c[16] = {576, 696, 864, 480, 576, 624, 840, 696, 748, 904, 1123, 624, 748, 811, 1092, 904};  // 0x085ADB6C

// ---------------- cheye.s -----------------

void FUN_08180ad4(Enemy* p);
void FUN_081811b0(Enemy* p);
void FUN_08181a88(Enemy* p);
void FUN_08181c00(Enemy* p);
void FUN_08181d78(Enemy* p);
void FUN_08181f70(Enemy* p);
void FUN_08182410(Enemy* p);
void FUN_0818266c(Enemy* p);
void FUN_081829e8(Enemy* p);
void FUN_08182d1c(Enemy* p);
void FUN_08182de8(Enemy* p);
void FUN_08182e98(Enemy* p);
void FUN_08182fec(Enemy* p);
void FUN_081831c4(Enemy* p);
void FUN_0818327c(Enemy* p);

void (*const PTR_ARRAY_085adb8c[2])(Enemy*) = {
    FUN_08180ad4,
    FUN_081811b0,
};  // 0x085ADB8C

void (*const PTR_ARRAY_085adb94[4])(Enemy*) = {
    FUN_08181a88,
    FUN_08181c00,
    FUN_08181d78,
    FUN_08181f70,
};  // 0x085ADB94

// clang-format off
void (*const PTR_ARRAY_085adba4[22])(Enemy*) = {
    FUN_081829e8,
    NULL,
    FUN_0818266c,
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
    FUN_08182fec,
    FUN_081831c4,
    FUN_0818327c,
    FUN_08182d1c,
    FUN_08182e98,
    FUN_08182de8,
    FUN_08182410,
};  // 0x085ADBA4
// clang-format on

const Vec3 vec3_ARRAY_085adbfc[14] = {
    {82,  250, 0  },
    {112, 270, -5 },
    {118, 270, -5 },
    {118, 270, -5 },
    {92,  260, -5 },
    {-24, 250, 82 },
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {28,  250, 48 },
    {38,  0,   24 },
    {42,  250, 48 },
    {12,  0,   24 }
};  // 0x085ADBFC

// ---------------- octopus.c -----------------

void FUN_08186484(Enemy* p);
void FUN_081865a8(Enemy* p);
void FUN_08186734(Enemy* p);
void FUN_08186844(Enemy* p);
void FUN_08186988(Enemy* p);
void FUN_08186a7c(Enemy* p);
void FUN_08186b10(Enemy* p);
void FUN_08186b28(Enemy* p);
void FUN_08186b7c(Enemy* p);
void FUN_08186c00(Enemy* p);
void FUN_08186c88(Enemy* p);
void FUN_08186ca0(Enemy* p);
void FUN_08186d00(Enemy* p);
void FUN_08186d7c(Enemy* p);

void FUN_081870f4(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085adc6c[6])(Enemy*) = {
    FUN_08186a7c,
    FUN_08186b7c,
    FUN_08186c00,
    FUN_08186b10,
    FUN_08186c88,
    FUN_08186734,
};  // 0x085ADC6C

void (*const PTR_ARRAY_085adc84[5])(Enemy*) = {
    FUN_08186988,
    FUN_08186484,
    FUN_08186844,
    FUN_08186b28,
    FUN_081865a8,
};  // 0x085ADC84

void (*const PTR_ARRAY_085adc98[4])(Enemy*) = {
    FUN_08186ca0,
    FUN_080f1cb8,
    FUN_08186d7c,
    FUN_08186d00,
};  // 0x085ADC98

// メッセージ表
void (*const PTR_ARRAY_085adca8[10])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    NULL,
    NULL,
    NULL,
    FUN_081870f4,
};  // 0x085ADCA8

// ---------------- serpent.s -----------------

void FUN_0818b4a8(Enemy* p);
void FUN_0818b818(Enemy* p);
void FUN_0818bc28(Enemy* p);
void FUN_0818bdf0(Enemy* p);
void FUN_0818bee0(Enemy* p);
void FUN_0818c080(Enemy* p);
void FUN_0818c1bc(Enemy* p);
void FUN_0818c31c(Enemy* p);
void FUN_0818c3bc(Enemy* p);
void FUN_0818c894(Enemy* p);
void FUN_0818cb5c(Enemy* p);
void FUN_0818cfb8(Enemy* p);
void FUN_0818d3d8(Enemy* p);
void FUN_0818d5b0(Enemy* p);
void FUN_0818d804(Enemy* p);
void FUN_0818dd0c(Enemy* p);
void FUN_0818de20(Enemy* p);
void FUN_0818e158(Enemy* p);
void FUN_08193ca4(Enemy* p);
void FUN_08193dc8(Enemy* p);
void FUN_08193fa4(Enemy* p);
void FUN_081940d8(Enemy* p);

void FUN_08188784(Enemy* p, u16* msg);
void FUN_081887c0(Enemy* p, u16* msg);
void FUN_0818e2b8(Enemy* p, u16* msg);

// メッセージ表
void (*const PTR_ARRAY_085adcd0[9])(Enemy*, u16*) = {
    NULL,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    NULL,
    FUN_08188784,
    FUN_081887c0,
};  // 0x085ADCD0

// clang-format off
void (*const PTR_ARRAY_085adcf4[24])(Enemy*) = {
    FUN_0818bc28,
    FUN_0818b818,
    FUN_0818b4a8,
    FUN_080f2364,
    FUN_0818c1bc,
    FUN_0818bee0,
    FUN_0818bdf0,
    NULL,
    NULL,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_0818c3bc,
    FUN_0818cb5c,
    FUN_0818cfb8,
    FUN_0818d3d8,
    FUN_0818d804,
    FUN_0818dd0c,
    FUN_0818c894,
    FUN_0818de20,
    FUN_0818c080,
    FUN_0818e158,
    FUN_0818d5b0,
    FUN_0818c31c,
};  // 0x085ADCF4
// clang-format on

const u32 u32_ARRAY_085add54[4] = {16, 16, 19, 24};  // 0x085ADD54

void (*const PTR_ARRAY_085add64[4])(Enemy*) = {
    FUN_08193ca4,
    FUN_08193dc8,
    FUN_08193fa4,
    FUN_081940d8,
};  // 0x085ADD64

// メッセージ表
void (*const PTR_ARRAY_085add74[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0818e2b8,
};  // 0x085ADD74

const s32 s32_ARRAY_085add90[6] = {-100, 0, 100, -70, 0, 130};  // 0x085ADD90

// ---------------- ax.c -----------------

void FUN_08198250(Enemy* p);
void FUN_08198254(Enemy* p);
void FUN_08199eec(Enemy* p);
void FUN_08199ef0(Enemy* p);
void FUN_0819d664(Enemy* p);
void FUN_0819d89c(Enemy* p);
void FUN_0819d998(Enemy* p);
void FUN_0819db7c(Enemy* p);
void FUN_0819dc50(Enemy* p);
void FUN_081a057c(Enemy* p);
void FUN_081a0680(Enemy* p);
void FUN_081a0714(Enemy* p);
void FUN_081a082c(Enemy* p);
void FUN_081a08a4(Enemy* p);
void FUN_081a09bc(Enemy* p);
void FUN_081a0a34(Enemy* p);
void FUN_081a0b70(Enemy* p);
void FUN_081a0c2c(Enemy* p);
void FUN_081a0d3c(Enemy* p);
void FUN_081a1160(Enemy* p);
void FUN_081a158c(Enemy* p);
void FUN_081a1630(Enemy* p);

void (*const PTR_ARRAY_085adda8[2])(Enemy*) = {
    FUN_08198250,
    FUN_08198254,
};  // 0x085ADDA8

void (*const PTR_ARRAY_085addb0[2])(Enemy*) = {
    FUN_08199eec,
    FUN_08199ef0,
};  // 0x085ADDB0

void (*const PTR_ARRAY_085addb8[5])(Enemy*) = {
    FUN_0819dc50,
    FUN_0819d89c,
    FUN_0819d664,
    FUN_0819d998,
    FUN_0819db7c,
};  // 0x085ADDB8

const u16 u16_ARRAY_085addcc[8] = {12, 8, 4, 0, 4, 8, 12, 0};  // 0x085ADDCC

void (*const PTR_ARRAY_085adddc[11])(Enemy*) = {
    FUN_081a057c,
    FUN_081a0680,
    FUN_081a0714,
    FUN_081a082c,
    FUN_081a08a4,
    FUN_081a09bc,
    FUN_081a0a34,
    FUN_081a0b70,
    FUN_081a0c2c,
    FUN_081a0d3c,
    FUN_081a1160,
};  // 0x085ADDDC

void (*const PTR_ARRAY_085ade08[2])(Enemy*) = {
    FUN_081a158c,
    FUN_081a1630,
};  // 0x085ADE08

// 0x085ADBFC の先頭10要素と同じ中身
const Vec3 vec3_ARRAY_085ade10[10] = {
    {82,  250, 0  },
    {112, 270, -5 },
    {118, 270, -5 },
    {118, 270, -5 },
    {92,  260, -5 },
    {-24, 250, 82 },
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106}
};  // 0x085ADE10

// ---------------- root_of_darkness.c -----------------

void FUN_081a4648(Enemy* p);
void FUN_081a473c(Enemy* p);
void FUN_081a483c(Enemy* p);
void FUN_081a48d0(Enemy* p);
void FUN_081a48e8(Enemy* p);
void FUN_081a493c(Enemy* p);
void FUN_081a49c0(Enemy* p);
void FUN_081a4a44(Enemy* p);
void FUN_081a4aa0(Enemy* p);
void FUN_081a4b30(Enemy* p);

void FUN_081a4ccc(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ade60[4])(Enemy*) = {
    FUN_081a483c,
    FUN_081a493c,
    FUN_081a49c0,
    FUN_081a48d0,
};  // 0x085ADE60

void (*const PTR_ARRAY_085ade70[4])(Enemy*) = {
    FUN_081a4648,
    FUN_081a473c,
    FUN_081a48e8,
    FUN_081a4b30,
};  // 0x085ADE70

void (*const PTR_ARRAY_085ade80[3])(Enemy*) = {
    FUN_081a4a44,
    FUN_080f1cb8,
    FUN_081a4aa0,
};  // 0x085ADE80

// メッセージ表
void (*const PTR_ARRAY_085ade8c[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_081a4ccc,
};  // 0x085ADE8C

// ---------------- unk_flame_snake.s -----------------

void FUN_081a8278(Enemy* p);
void FUN_081a8514(Enemy* p);
void FUN_081a8748(Enemy* p);
void FUN_081a8814(Enemy* p);
void FUN_081a8b28(Enemy* p);
void FUN_081a8c88(Enemy* p);
void FUN_081a8fe8(Enemy* p);
void FUN_081a9220(Enemy* p);
void FUN_081a94bc(Enemy* p);
void FUN_081a95fc(Enemy* p);
void FUN_081acd90(Enemy* p);

void FUN_081a9724(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085adea8[11])(Enemy*) = {
    FUN_081a8514,
    FUN_081a8814,
    FUN_081a8278,
    FUN_080f2364,
    FUN_081a8b28,
    FUN_081a8748,
    FUN_081a8c88,
    FUN_081a9220,
    FUN_081a94bc,
    FUN_081a8fe8,
    FUN_081a95fc,
};  // 0x085ADEA8

void (*const PTR_ARRAY_085aded4[1])(Enemy*) = {
    FUN_081acd90,
};  // 0x085ADED4

// メッセージ表
void (*const PTR_ARRAY_085aded8[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_081a9724,
};  // 0x085ADED8

// ---------------- boku_link.s -----------------

void FUN_081b1ec4(Enemy* p);
void FUN_081b1fb4(Enemy* p);
void FUN_081b282c(Enemy* p);
void FUN_081b2a30(Enemy* p);
void FUN_081b2b2c(Enemy* p);
void FUN_081b2c30(Enemy* p);
void FUN_081b3bec(Enemy* p);
void FUN_081b3dd4(Enemy* p);
void FUN_081b3ebc(Enemy* p);

void (*const PTR_ARRAY_085adef4[2])(Enemy*) = {
    FUN_081b1ec4,
    FUN_081b1fb4,
};  // 0x085ADEF4

void (*const PTR_ARRAY_085adefc[18])(Enemy*) = {
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
    FUN_081b282c,
    FUN_081b2a30,
    FUN_081b2b2c,
};  // 0x085ADEFC

void (*const PTR_ARRAY_085adf44[1])(Enemy*) = {
    FUN_081b2c30,
};  // 0x085ADF44

const u16 u16_ARRAY_085adf48[4] = {336, 336, 0, 180};  // 0x085ADF48

void (*const PTR_ARRAY_085adf50[18])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f9c20,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f9e34,
    FUN_080f9ee0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_080f12c4,
    FUN_081b3bec,
    FUN_081b3dd4,
    FUN_081b3ebc,
};  // 0x085ADF50

// ---------------- golem_link.s -----------------

void FUN_081bdf44(Enemy* p);
void FUN_081be01c(Enemy* p);
void FUN_081be858(Enemy* p);
void FUN_081beb70(Enemy* p);
void FUN_081bec58(Enemy* p);
void FUN_081bfccc(Enemy* p);
void FUN_081bff24(Enemy* p);
void FUN_081c07e4(Enemy* p);
void FUN_081c0868(Enemy* p);
void FUN_081c0990(Enemy* p);
void FUN_081c0aa8(Enemy* p);
void FUN_081c1074(Enemy* p);

const u16 u16_ARRAY_085adf98[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085ADF98

const u16 u16_ARRAY_085adfa8[2] = {0, 4};  // 0x085ADFA8

void (*const PTR_ARRAY_085adfac[2])(Enemy*) = {
    FUN_081bdf44,
    FUN_081be01c,
};  // 0x085ADFAC

void (*const PTR_ARRAY_085adfb4[10])(Enemy*) = {
    FUN_081be858,
    FUN_081bec58,
    FUN_081bfccc,
    FUN_081bff24,
    FUN_081c07e4,
    FUN_081c0868,
    FUN_081beb70,
    FUN_081c0aa8,
    FUN_081c0990,
    FUN_081c1074,
};  // 0x085ADFB4

void (*const PTR_ARRAY_085adfdc[15])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f9c20,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f9e34,
    FUN_080f9ee0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_080f12c4,
};  // 0x085ADFDC

// ---------------- dog_link.s -----------------

void FUN_081ca7f4(Enemy* p);
void FUN_081ca8cc(Enemy* p);
void FUN_081cb148(Enemy* p);
void FUN_081cb274(Enemy* p);
void FUN_081cb400(Enemy* p);
void FUN_081cb7e8(Enemy* p);
void FUN_081cbaa8(Enemy* p);
void FUN_081cc1a4(Enemy* p);
void FUN_081cc380(Enemy* p);
void FUN_081cc444(Enemy* p);

const u16 u16_ARRAY_085ae018[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AE018

void (*const PTR_ARRAY_085ae038[2])(Enemy*) = {
    FUN_081ca7f4,
    FUN_081ca8cc,
};  // 0x085AE038

void (*const PTR_ARRAY_085ae040[2])(Enemy*) = {
    FUN_081cb148,
    FUN_081cb274,
};  // 0x085AE040

// clang-format off
void (*const PTR_ARRAY_085ae048[20])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f9c20,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f9e34,
    FUN_080f9ee0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_081cbaa8,
    FUN_081cb400,
    FUN_081cb7e8,
    FUN_081cc1a4,
    FUN_081cc380,
    FUN_081cc444,
};  // 0x085AE048
// clang-format on
