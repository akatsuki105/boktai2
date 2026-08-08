#include "global.h"

// newlib/libm/k_tan.c

static const f64 one = 1.00000000000000000000e+00;     // 0x3FF00000, 0x00000000
static const f64 pio4 = 7.85398163397448278999e-01;    // 0x3FE921FB, 0x54442D18
static const f64 pio4lo = 3.06161699786838301793e-17;  // 0x3C81A626, 0x33145C07

static const f64 T[] = {
    3.33333333333334091986e-01,  /* 0x3FD55555, 0x55555563 */
    1.33333333333201242699e-01,  /* 0x3FC11111, 0x1110FE7A */
    5.39682539762260521377e-02,  /* 0x3FABA1BA, 0x1BB341FE */
    2.18694882948595424599e-02,  /* 0x3F9664F4, 0x8406D637 */
    8.86323982359930005737e-03,  /* 0x3F8226E3, 0xE96E8493 */
    3.59207910759131235356e-03,  /* 0x3F6D6D22, 0xC9560328 */
    1.45620945432529025516e-03,  /* 0x3F57DBC8, 0xFEE08315 */
    5.88041240820264096874e-04,  /* 0x3F4344D8, 0xF2F26501 */
    2.46463134818469906812e-04,  /* 0x3F3026F7, 0x1A8D1068 */
    7.81794442939557092300e-05,  /* 0x3F147E88, 0xA03792A6 */
    7.14072491382608190305e-05,  /* 0x3F12B80F, 0x32F0A7E9 */
    -1.85586374855275456654e-05, /* 0xBEF375CB, 0xDB605373 */
    2.59073051863633712884e-05,  /* 0x3EFB2A70, 0x74BF7AD4 */
};

// 0x08250E90
NAKED f64 __kernel_tan(f64 x, f64 y, s32 iy) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0x40\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	str r2, [sp, #8]\n\
	str r3, [sp, #0xc]\n\
	ldr r0, [sp]\n\
	mov r8, r0\n\
	ldr r5, _08250EE0 @ =0x7FFFFFFF\n\
	ands r5, r0\n\
	ldr r0, _08250EE4 @ =0x3E2FFFFF\n\
	cmp r5, r0\n\
	bgt _08250F12\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __fixdfsi\n\
	cmp r0, #0\n\
	bne _08250F12\n\
	ldr r1, [sp, #4]\n\
	orrs r5, r1\n\
	ldr r0, [sp, #0x58]\n\
	adds r0, #1\n\
	orrs r5, r0\n\
	cmp r5, #0\n\
	bne _08250EF0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl fdlibm_fp_fabs\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, _08250EE8 @ =0x3FF00000\n\
	ldr r1, _08250EEC @ =0x00000000\n\
	bl __divdf3\n\
	b _08251248\n\
	.align 2, 0\n\
_08250EE0: .4byte 0x7FFFFFFF\n\
_08250EE4: .4byte 0x3E2FFFFF\n\
_08250EE8: .4byte 0x3FF00000\n\
_08250EEC: .4byte 0x00000000\n\
_08250EF0:\n\
	ldr r0, [sp, #0x58]\n\
	cmp r0, #1\n\
	beq _08250F0C\n\
	ldr r1, _08250F08 @ =0x00000000\n\
	ldr r0, _08250F04 @ =0xBFF00000\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __divdf3\n\
	b _08251248\n\
	.align 2, 0\n\
_08250F04: .4byte 0xBFF00000\n\
_08250F08: .4byte 0x00000000\n\
_08250F0C:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	b _08251248\n\
_08250F12:\n\
	ldr r0, _0825118C @ =0x3FE59427\n\
	cmp r5, r0\n\
	ble _08250F6E\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	bge _08250F36\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __negdf2\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __negdf2\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
_08250F36:\n\
	ldr r0, _08251190 @ =0x3FE921FB\n\
	ldr r1, _08251194 @ =0x54442D18\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __subdf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r0, _08251198 @ =0x3C81A626\n\
	ldr r1, _0825119C @ =0x33145C07\n\
	ldr r2, [sp, #8]\n\
	ldr r3, [sp, #0xc]\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __adddf3\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, _082511A0 @ =0x00000000\n\
	ldr r1, _082511A4 @ =0x00000000\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
_08250F6E:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r4, _082511A8 @ =0x085A9048\n\
	ldr r2, [r4, #0x58]\n\
	ldr r3, [r4, #0x5c]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x48]\n\
	ldr r1, [r4, #0x4c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x38]\n\
	ldr r1, [r4, #0x3c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	ldr r1, [r4, #0x2c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x18]\n\
	ldr r1, [r4, #0x1c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #8]\n\
	ldr r1, [r4, #0xc]\n\
	bl __adddf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r2, [r4, #0x60]\n\
	ldr r3, [r4, #0x64]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x50]\n\
	ldr r1, [r4, #0x54]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x40]\n\
	ldr r1, [r4, #0x44]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x30]\n\
	ldr r1, [r4, #0x34]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x20]\n\
	ldr r1, [r4, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r4, #0x10]\n\
	ldr r1, [r4, #0x14]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	bl __muldf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __muldf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __muldf3\n\
	ldr r2, [sp, #8]\n\
	ldr r3, [sp, #0xc]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __adddf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, [r4]\n\
	ldr r1, [r4, #4]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x28]\n\
	str r1, [sp, #0x2c]\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	ldr r2, [sp, #0x28]\n\
	ldr r3, [sp, #0x2c]\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, _0825118C @ =0x3FE59427\n\
	cmp r5, r0\n\
	ble _082511AC\n\
	ldr r0, [sp, #0x58]\n\
	bl __floatsidf\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	mov r0, r8\n\
	asrs r1, r0, #0x1e\n\
	movs r0, #2\n\
	ands r1, r0\n\
	movs r0, #1\n\
	subs r0, r0, r1\n\
	bl __floatsidf\n\
	str r0, [sp, #0x30]\n\
	str r1, [sp, #0x34]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __divdf3\n\
	ldr r2, [sp, #0x28]\n\
	ldr r3, [sp, #0x2c]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x30]\n\
	ldr r1, [sp, #0x34]\n\
	bl __muldf3\n\
	b _08251248\n\
	.align 2, 0\n\
_0825118C: .4byte 0x3FE59427\n\
_08251190: .4byte 0x3FE921FB\n\
_08251194: .4byte 0x54442D18\n\
_08251198: .4byte 0x3C81A626\n\
_0825119C: .4byte 0x33145C07\n\
_082511A0: .4byte 0x00000000\n\
_082511A4: .4byte 0x00000000\n\
_082511A8: .4byte T\n\
_082511AC:\n\
	ldr r1, [sp, #0x58]\n\
	cmp r1, #1\n\
	beq _08251244\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	bl __subdf3\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	ldr r1, _08251238 @ =0x00000000\n\
	ldr r0, _08251234 @ =0xBFF00000\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __divdf3\n\
	str r0, [sp, #0x38]\n\
	str r1, [sp, #0x3c]\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	movs r5, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x10]\n\
	ldr r3, [sp, #0x14]\n\
	bl __muldf3\n\
	ldr r2, _0825123C @ =0x3FF00000\n\
	ldr r3, _08251240 @ =0x00000000\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x38]\n\
	ldr r1, [sp, #0x3c]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __adddf3\n\
	b _08251248\n\
	.align 2, 0\n\
_08251234: .4byte 0xBFF00000\n\
_08251238: .4byte 0x00000000\n\
_0825123C: .4byte 0x3FF00000\n\
_08251240: .4byte 0x00000000\n\
_08251244:\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
_08251248:\n\
	add sp, #0x40\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7, pc}\n\
 .syntax divided\n");
}
