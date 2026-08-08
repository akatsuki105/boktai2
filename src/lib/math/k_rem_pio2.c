#include "global.h"

// newlib/libm/k_rem_pio2.c

static const s32 init_jk[] = {2, 3, 4, 6}; /* initial value for jk */

static const f64 PIo2[] = {
    1.57079625129699707031e+00, /* 0x3FF921FB, 0x40000000 */
    7.54978941586159635335e-08, /* 0x3E74442D, 0x00000000 */
    5.39030252995776476554e-15, /* 0x3CF84698, 0x80000000 */
    3.28200341580791294123e-22, /* 0x3B78CC51, 0x60000000 */
    1.27065575308067607349e-29, /* 0x39F01B83, 0x80000000 */
    1.22933308981111328932e-36, /* 0x387A2520, 0x40000000 */
    2.73370053816464559624e-44, /* 0x36E38222, 0x80000000 */
    2.16741683877804819444e-51, /* 0x3569F31D, 0x00000000 */
};

static const f64 zero = 0.0, one = 1.0;
static const f64 two24 = 1.67772160000000000000e+07;  /* 0x41700000, 0x00000000 */
static const f64 twon24 = 5.96046447753906250000e-08; /* 0x3E700000, 0x00000000 */

// 0x08250538
NAKED s32 __kernel_rem_pio2(f64* x, f64* y, s32 e0, s32 nx, s32 prec, const s32* ipio2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r4, _082505A4 @ =0xFFFFFD9C\n\
	add sp, r4\n\
	str r0, [sp, #0x230]\n\
	str r1, [sp, #0x234]\n\
	adds r4, r2, #0\n\
	ldr r1, _082505A8 @ =init_jk\n\
	ldr r2, [sp, #0x284]\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [sp, #0x23c]\n\
	str r0, [sp, #0x240]\n\
	subs r3, #1\n\
	mov sl, r3\n\
	subs r0, r4, #3\n\
	movs r1, #0x18\n\
	bl __divsi3\n\
	str r0, [sp, #0x238]\n\
	cmp r0, #0\n\
	bge _08250570\n\
	movs r3, #0\n\
	str r3, [sp, #0x238]\n\
_08250570:\n\
	ldr r1, [sp, #0x238]\n\
	adds r1, #1\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	subs r4, r4, r0\n\
	str r4, [sp, #0x248]\n\
	ldr r0, [sp, #0x238]\n\
	mov r1, sl\n\
	subs r4, r0, r1\n\
	ldr r1, [sp, #0x23c]\n\
	add r1, sl\n\
	cmp r1, #0\n\
	blt _082505C0\n\
	lsls r0, r4, #2\n\
	ldr r2, [sp, #0x288]\n\
	adds r5, r0, r2\n\
	add r7, sp, #0x50\n\
	adds r6, r1, #1\n\
_08250596:\n\
	cmp r4, #0\n\
	blt _082505AC\n\
	ldr r0, [r5]\n\
	bl __floatsidf\n\
	b _082505B0\n\
	.align 2, 0\n\
_082505A4: .4byte 0xFFFFFD9C\n\
_082505A8: .4byte init_jk\n\
_082505AC:\n\
	ldr r1, _08250710 @ =0x00000000\n\
	ldr r0, _0825070C @ =0x00000000\n\
_082505B0:\n\
	str r0, [r7]\n\
	str r1, [r7, #4]\n\
	adds r7, #8\n\
	subs r6, #1\n\
	adds r5, #4\n\
	adds r4, #1\n\
	cmp r6, #0\n\
	bne _08250596\n\
_082505C0:\n\
	movs r6, #0\n\
	ldr r3, [sp, #0x240]\n\
	cmp r6, r3\n\
	bgt _08250620\n\
_082505C8:\n\
	movs r4, #0\n\
	ldr r1, _08250710 @ =0x00000000\n\
	ldr r0, _0825070C @ =0x00000000\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	lsls r1, r6, #3\n\
	mov r8, r1\n\
	adds r2, r6, #1\n\
	mov sb, r2\n\
	cmp r4, sl\n\
	bgt _0825060C\n\
	add r5, sp, #0x50\n\
	ldr r7, [sp, #0x230]\n\
_082505E2:\n\
	mov r3, sl\n\
	adds r2, r3, r6\n\
	subs r2, r2, r4\n\
	lsls r2, r2, #3\n\
	adds r2, r5, r2\n\
	ldm r7!, {r0, r1}\n\
	ldr r3, [r2, #4]\n\
	ldr r2, [r2]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	adds r4, #1\n\
	cmp r4, sl\n\
	ble _082505E2\n\
_0825060C:\n\
	add r0, sp, #0x190\n\
	add r0, r8\n\
	ldr r1, [sp, #0x258]\n\
	ldr r2, [sp, #0x25c]\n\
	str r1, [r0]\n\
	str r2, [r0, #4]\n\
	mov r6, sb\n\
	ldr r2, [sp, #0x240]\n\
	cmp r6, r2\n\
	ble _082505C8\n\
_08250620:\n\
	ldr r3, [sp, #0x240]\n\
	mov sb, r3\n\
_08250624:\n\
	mov r4, sb\n\
	add r0, sp, #0x190\n\
	lsls r1, r4, #3\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	ldr r3, [r0, #4]\n\
	str r2, [sp, #0x250]\n\
	str r3, [sp, #0x254]\n\
	cmp r4, #0\n\
	ble _08250688\n\
	mov r6, sp\n\
	add r0, sp, #0x188\n\
	adds r5, r0, r1\n\
_0825063E:\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	ldr r2, _08250714 @ =0x3E700000\n\
	ldr r3, _08250718 @ =0x00000000\n\
	bl __muldf3\n\
	bl __fixdfsi\n\
	bl __floatsidf\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	ldr r2, _0825071C @ =0x41700000\n\
	ldr r3, _08250720 @ =0x00000000\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __subdf3\n\
	bl __fixdfsi\n\
	stm r6!, {r0}\n\
	subs r4, #1\n\
	ldr r0, [r5]\n\
	ldr r1, [r5, #4]\n\
	ldr r2, [sp, #0x258]\n\
	ldr r3, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
	subs r5, #8\n\
	cmp r4, #0\n\
	bgt _0825063E\n\
_08250688:\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	ldr r2, [sp, #0x248]\n\
	bl scalbn\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
	ldr r2, _08250724 @ =0x3FC00000\n\
	ldr r3, _08250728 @ =0x00000000\n\
	bl __muldf3\n\
	bl fdlibm_floor\n\
	ldr r2, _0825072C @ =0x40200000\n\
	ldr r3, _08250730 @ =0x00000000\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __subdf3\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
	bl __fixdfsi\n\
	str r0, [sp, #0x244]\n\
	bl __floatsidf\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __subdf3\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
	movs r3, #0\n\
	str r3, [sp, #0x24c]\n\
	ldr r0, [sp, #0x248]\n\
	cmp r0, #0\n\
	ble _08250734\n\
	mov r0, sb\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	mov r1, sp\n\
	adds r2, r1, r0\n\
	movs r0, #0x18\n\
	ldr r3, [sp, #0x248]\n\
	subs r0, r0, r3\n\
	ldr r1, [r2]\n\
	adds r6, r1, #0\n\
	asrs r6, r0\n\
	ldr r3, [sp, #0x244]\n\
	adds r3, r3, r6\n\
	str r3, [sp, #0x244]\n\
	lsls r6, r0\n\
	subs r1, r1, r6\n\
	str r1, [r2]\n\
	movs r0, #0x17\n\
	ldr r2, [sp, #0x248]\n\
	subs r0, r0, r2\n\
	asrs r1, r0\n\
	str r1, [sp, #0x24c]\n\
	b _0825075C\n\
	.align 2, 0\n\
_0825070C: .4byte 0x00000000\n\
_08250710: .4byte 0x00000000\n\
_08250714: .4byte 0x3E700000\n\
_08250718: .4byte 0x00000000\n\
_0825071C: .4byte 0x41700000\n\
_08250720: .4byte 0x00000000\n\
_08250724: .4byte 0x3FC00000\n\
_08250728: .4byte 0x00000000\n\
_0825072C: .4byte 0x40200000\n\
_08250730: .4byte 0x00000000\n\
_08250734:\n\
	ldr r3, [sp, #0x248]\n\
	cmp r3, #0\n\
	bne _08250748\n\
	mov r0, sb\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	add r0, sp\n\
	ldr r0, [r0]\n\
	asrs r0, r0, #0x17\n\
	b _0825075A\n\
_08250748:\n\
	ldr r3, _08250790 @ =0x00000000\n\
	ldr r2, _0825078C @ =0x3FE00000\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __gedf2\n\
	cmp r0, #0\n\
	blt _0825075C\n\
	movs r0, #2\n\
_0825075A:\n\
	str r0, [sp, #0x24c]\n\
_0825075C:\n\
	ldr r1, [sp, #0x24c]\n\
	cmp r1, #0\n\
	ble _08250812\n\
	ldr r2, [sp, #0x244]\n\
	adds r2, #1\n\
	str r2, [sp, #0x244]\n\
	movs r7, #0\n\
	mov r3, sb\n\
	cmp r3, #0\n\
	ble _082507A4\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x11\n\
	ldr r2, _08250794 @ =0x00FFFFFF\n\
	mov r1, sp\n\
	mov r6, sb\n\
_0825077A:\n\
	ldr r4, [r1]\n\
	cmp r7, #0\n\
	bne _08250798\n\
	cmp r4, #0\n\
	beq _0825079C\n\
	movs r7, #1\n\
	subs r0, r3, r4\n\
	b _0825079A\n\
	.align 2, 0\n\
_0825078C: .4byte 0x3FE00000\n\
_08250790: .4byte 0x00000000\n\
_08250794: .4byte 0x00FFFFFF\n\
_08250798:\n\
	subs r0, r2, r4\n\
_0825079A:\n\
	str r0, [r1]\n\
_0825079C:\n\
	adds r1, #4\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _0825077A\n\
_082507A4:\n\
	ldr r0, [sp, #0x248]\n\
	cmp r0, #0\n\
	ble _082507DA\n\
	cmp r0, #1\n\
	beq _082507B4\n\
	cmp r0, #2\n\
	beq _082507C8\n\
	b _082507DA\n\
_082507B4:\n\
	mov r0, sb\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	mov r1, sp\n\
	adds r2, r1, r0\n\
	ldr r0, [r2]\n\
	ldr r1, _082507C4 @ =0x007FFFFF\n\
	b _082507D6\n\
	.align 2, 0\n\
_082507C4: .4byte 0x007FFFFF\n\
_082507C8:\n\
	mov r0, sb\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	mov r3, sp\n\
	adds r2, r3, r0\n\
	ldr r0, [r2]\n\
	ldr r1, _082508F0 @ =0x003FFFFF\n\
_082507D6:\n\
	ands r0, r1\n\
	str r0, [r2]\n\
_082507DA:\n\
	ldr r0, [sp, #0x24c]\n\
	cmp r0, #2\n\
	bne _08250812\n\
	ldr r4, _082508F4 @ =0x3FF00000\n\
	ldr r5, _082508F8 @ =0x00000000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x250]\n\
	ldr r3, [sp, #0x254]\n\
	bl __subdf3\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
	cmp r7, #0\n\
	beq _08250812\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x248]\n\
	bl scalbn\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __subdf3\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
_08250812:\n\
	ldr r2, _082508FC @ =0x00000000\n\
	ldr r3, _08250900 @ =0x00000000\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __eqdf2\n\
	cmp r0, #0\n\
	bne _08250904\n\
	movs r4, #0\n\
	mov r6, sb\n\
	subs r6, #1\n\
	ldr r1, [sp, #0x240]\n\
	cmp r6, r1\n\
	blt _08250842\n\
	lsls r0, r6, #2\n\
	mov r2, sp\n\
	adds r1, r0, r2\n\
_08250834:\n\
	ldr r0, [r1]\n\
	orrs r4, r0\n\
	subs r1, #4\n\
	subs r6, #1\n\
	ldr r3, [sp, #0x240]\n\
	cmp r6, r3\n\
	bge _08250834\n\
_08250842:\n\
	cmp r4, #0\n\
	bne _08250904\n\
	movs r4, #1\n\
	ldr r0, [sp, #0x240]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	add r0, sp\n\
	ldr r0, [r0]\n\
	mov r1, sb\n\
	adds r1, #1\n\
	cmp r0, #0\n\
	bne _0825086C\n\
	ldr r2, [sp, #0x240]\n\
	lsls r0, r2, #2\n\
	add r0, sp\n\
	subs r2, r0, #4\n\
_08250862:\n\
	subs r2, #4\n\
	adds r4, #1\n\
	ldr r0, [r2]\n\
	cmp r0, #0\n\
	beq _08250862\n\
_0825086C:\n\
	adds r6, r1, #0\n\
	mov r3, sb\n\
	adds r7, r3, r4\n\
	cmp r6, r7\n\
	bgt _082508EC\n\
	mov r0, sp\n\
	adds r0, #0x50\n\
	str r0, [sp, #0x260]\n\
_0825087C:\n\
	mov r1, sl\n\
	adds r0, r1, r6\n\
	lsls r0, r0, #3\n\
	ldr r2, [sp, #0x260]\n\
	adds r4, r2, r0\n\
	ldr r3, [sp, #0x238]\n\
	adds r0, r3, r6\n\
	lsls r0, r0, #2\n\
	ldr r1, [sp, #0x288]\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	bl __floatsidf\n\
	str r0, [r4]\n\
	str r1, [r4, #4]\n\
	ldr r2, _082508FC @ =0x00000000\n\
	ldr r3, _08250900 @ =0x00000000\n\
	str r2, [sp, #0x258]\n\
	str r3, [sp, #0x25c]\n\
	lsls r3, r6, #3\n\
	mov r8, r3\n\
	adds r6, #1\n\
	mov sb, r6\n\
	mov r0, sl\n\
	cmp r0, #0\n\
	blt _082508DA\n\
	adds r6, r4, #0\n\
	ldr r5, [sp, #0x230]\n\
	mov r4, sl\n\
	adds r4, #1\n\
_082508B8:\n\
	ldm r5!, {r0, r1}\n\
	ldr r2, [r6]\n\
	ldr r3, [r6, #4]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	subs r6, #8\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _082508B8\n\
_082508DA:\n\
	add r0, sp, #0x190\n\
	add r0, r8\n\
	ldr r1, [sp, #0x258]\n\
	ldr r2, [sp, #0x25c]\n\
	str r1, [r0]\n\
	str r2, [r0, #4]\n\
	mov r6, sb\n\
	cmp r6, r7\n\
	ble _0825087C\n\
_082508EC:\n\
	mov sb, r7\n\
	b _08250624\n\
	.align 2, 0\n\
_082508F0: .4byte 0x003FFFFF\n\
_082508F4: .4byte 0x3FF00000\n\
_082508F8: .4byte 0x00000000\n\
_082508FC: .4byte 0x00000000\n\
_08250900: .4byte 0x00000000\n\
_08250904:\n\
	ldr r3, _08250948 @ =0x00000000\n\
	ldr r2, _08250944 @ =0x00000000\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __eqdf2\n\
	cmp r0, #0\n\
	bne _0825094C\n\
	movs r2, #1\n\
	rsbs r2, r2, #0\n\
	add sb, r2\n\
	ldr r3, [sp, #0x248]\n\
	subs r3, #0x18\n\
	str r3, [sp, #0x248]\n\
	mov r1, sb\n\
	lsls r0, r1, #2\n\
	mov r2, sp\n\
	adds r1, r2, r0\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	bne _082509E6\n\
_0825092E:\n\
	subs r1, #4\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	add sb, r3\n\
	ldr r0, [sp, #0x248]\n\
	subs r0, #0x18\n\
	str r0, [sp, #0x248]\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0825092E\n\
	b _082509E6\n\
	.align 2, 0\n\
_08250944: .4byte 0x00000000\n\
_08250948: .4byte 0x00000000\n\
_0825094C:\n\
	ldr r1, [sp, #0x248]\n\
	rsbs r2, r1, #0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl scalbn\n\
	str r0, [sp, #0x250]\n\
	str r1, [sp, #0x254]\n\
	ldr r6, _082509C8 @ =0x00000000\n\
	ldr r5, _082509C4 @ =0x41700000\n\
	adds r3, r6, #0\n\
	adds r2, r5, #0\n\
	bl __gedf2\n\
	cmp r0, #0\n\
	blt _082509D4\n\
	ldr r2, _082509CC @ =0x3E700000\n\
	ldr r3, _082509D0 @ =0x00000000\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __muldf3\n\
	bl __fixdfsi\n\
	bl __floatsidf\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	mov r2, sb\n\
	lsls r0, r2, #2\n\
	mov r3, sp\n\
	adds r4, r3, r0\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	adds r3, r6, #0\n\
	adds r2, r5, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
	bl __subdf3\n\
	bl __fixdfsi\n\
	str r0, [r4]\n\
	movs r0, #1\n\
	add sb, r0\n\
	ldr r1, [sp, #0x248]\n\
	adds r1, #0x18\n\
	str r1, [sp, #0x248]\n\
	mov r2, sb\n\
	lsls r0, r2, #2\n\
	mov r3, sp\n\
	adds r4, r3, r0\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	b _082509E0\n\
	.align 2, 0\n\
_082509C4: .4byte 0x41700000\n\
_082509C8: .4byte 0x00000000\n\
_082509CC: .4byte 0x3E700000\n\
_082509D0: .4byte 0x00000000\n\
_082509D4:\n\
	mov r1, sb\n\
	lsls r0, r1, #2\n\
	mov r2, sp\n\
	adds r4, r2, r0\n\
	ldr r0, [sp, #0x250]\n\
	ldr r1, [sp, #0x254]\n\
_082509E0:\n\
	bl __fixdfsi\n\
	str r0, [r4]\n\
_082509E6:\n\
	ldr r1, _08250AB0 @ =0x00000000\n\
	ldr r0, _08250AAC @ =0x3FF00000\n\
	ldr r2, [sp, #0x248]\n\
	bl scalbn\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	mov r6, sb\n\
	cmp r6, #0\n\
	blt _08250A36\n\
	lsls r0, r6, #2\n\
	mov r3, sp\n\
	adds r5, r0, r3\n\
	add r1, sp, #0x190\n\
	lsls r0, r6, #3\n\
	adds r4, r1, r0\n\
_08250A06:\n\
	ldr r0, [r5]\n\
	bl __floatsidf\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __muldf3\n\
	str r0, [r4]\n\
	str r1, [r4, #4]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	ldr r2, _08250AB4 @ =0x3E700000\n\
	ldr r3, _08250AB8 @ =0x00000000\n\
	bl __muldf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	subs r5, #4\n\
	subs r4, #8\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bge _08250A06\n\
_08250A36:\n\
	mov r6, sb\n\
	cmp r6, #0\n\
	blt _08250A9A\n\
_08250A3C:\n\
	ldr r0, _08250ABC @ =0x00000000\n\
	ldr r1, _08250AC0 @ =0x00000000\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	movs r4, #0\n\
	subs r1, r6, #1\n\
	mov sl, r1\n\
	mov r2, sb\n\
	subs r5, r2, r6\n\
	add r3, sp, #0xf0\n\
	mov r8, r3\n\
	ldr r0, [sp, #0x23c]\n\
	cmp r4, r0\n\
	bgt _08250A88\n\
	cmp r4, r5\n\
	bgt _08250A88\n\
	lsls r1, r6, #3\n\
	add r0, sp, #0x190\n\
	adds r6, r1, r0\n\
	ldr r7, _08250AC4 @ =PIo2\n\
_08250A64:\n\
	ldm r7!, {r0, r1}\n\
	ldm r6!, {r2, r3}\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	adds r4, #1\n\
	ldr r1, [sp, #0x23c]\n\
	cmp r4, r1\n\
	bgt _08250A88\n\
	cmp r4, r5\n\
	ble _08250A64\n\
_08250A88:\n\
	lsls r0, r5, #3\n\
	add r0, r8\n\
	ldr r2, [sp, #0x258]\n\
	ldr r3, [sp, #0x25c]\n\
	str r2, [r0]\n\
	str r3, [r0, #4]\n\
	mov r6, sl\n\
	cmp r6, #0\n\
	bge _08250A3C\n\
_08250A9A:\n\
	ldr r3, [sp, #0x284]\n\
	cmp r3, #2\n\
	bgt _08250AC8\n\
	cmp r3, #1\n\
	bge _08250B28\n\
	cmp r3, #0\n\
	beq _08250AD2\n\
	b _08250CFA\n\
	.align 2, 0\n\
_08250AAC: .4byte 0x3FF00000\n\
_08250AB0: .4byte 0x00000000\n\
_08250AB4: .4byte 0x3E700000\n\
_08250AB8: .4byte 0x00000000\n\
_08250ABC: .4byte 0x00000000\n\
_08250AC0: .4byte 0x00000000\n\
_08250AC4: .4byte PIo2\n\
_08250AC8:\n\
	ldr r0, [sp, #0x284]\n\
	cmp r0, #3\n\
	bne _08250AD0\n\
	b _08250BD0\n\
_08250AD0:\n\
	b _08250CFA\n\
_08250AD2:\n\
	ldr r2, _08250B24 @ =0x00000000\n\
	ldr r1, _08250B20 @ =0x00000000\n\
	str r1, [sp, #0x258]\n\
	str r2, [sp, #0x25c]\n\
	mov r6, sb\n\
	cmp r6, #0\n\
	blt _08250AFE\n\
	add r1, sp, #0xf0\n\
	lsls r0, r6, #3\n\
	adds r4, r1, r0\n\
_08250AE6:\n\
	ldr r2, [r4]\n\
	ldr r3, [r4, #4]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	subs r4, #8\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bge _08250AE6\n\
_08250AFE:\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	ldr r3, [sp, #0x24c]\n\
	cmp r3, #0\n\
	bne _08250B10\n\
	b _08250CFA\n\
_08250B10:\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __negdf2\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	b _08250CFA\n\
	.align 2, 0\n\
_08250B20: .4byte 0x00000000\n\
_08250B24: .4byte 0x00000000\n\
_08250B28:\n\
	ldr r1, _08250BCC @ =0x00000000\n\
	ldr r0, _08250BC8 @ =0x00000000\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	mov r6, sb\n\
	add r1, sp, #0xf0\n\
	mov r8, r1\n\
	cmp r6, #0\n\
	blt _08250B56\n\
	lsls r0, r6, #3\n\
	adds r4, r0, r1\n\
_08250B3E:\n\
	ldr r2, [r4]\n\
	ldr r3, [r4, #4]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	subs r4, #8\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bge _08250B3E\n\
_08250B56:\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	ldr r3, [sp, #0x24c]\n\
	cmp r3, #0\n\
	beq _08250B74\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __negdf2\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
_08250B74:\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	ldr r1, [r3, #4]\n\
	ldr r2, [sp, #0x258]\n\
	ldr r3, [sp, #0x25c]\n\
	bl __subdf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	ble _08250BA6\n\
	mov r4, r8\n\
	adds r4, #8\n\
	mov r6, sb\n\
_08250B92:\n\
	ldm r4!, {r2, r3}\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _08250B92\n\
_08250BA6:\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	ldr r3, [sp, #0x24c]\n\
	cmp r3, #0\n\
	bne _08250BB8\n\
	b _08250CFA\n\
_08250BB8:\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __negdf2\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	b _08250CFA\n\
	.align 2, 0\n\
_08250BC8: .4byte 0x00000000\n\
_08250BCC: .4byte 0x00000000\n\
_08250BD0:\n\
	mov r6, sb\n\
	add r3, sp, #0xf0\n\
	mov r8, r3\n\
	cmp r6, #0\n\
	ble _08250C20\n\
	lsls r0, r6, #3\n\
	subs r0, #8\n\
	adds r7, r0, r3\n\
_08250BE0:\n\
	subs r6, #1\n\
	ldr r4, [r7]\n\
	ldr r5, [r7, #4]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [r7, #8]\n\
	ldr r3, [r7, #0xc]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x258]\n\
	ldr r3, [sp, #0x25c]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r7, #8]\n\
	ldr r1, [r7, #0xc]\n\
	bl __adddf3\n\
	str r0, [r7, #8]\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	str r0, [r7]\n\
	str r1, [r7, #4]\n\
	subs r7, #8\n\
	cmp r6, #0\n\
	bgt _08250BE0\n\
_08250C20:\n\
	mov r6, sb\n\
	cmp r6, #1\n\
	ble _08250C6E\n\
	lsls r0, r6, #3\n\
	subs r0, #8\n\
	mov r1, r8\n\
	adds r7, r0, r1\n\
_08250C2E:\n\
	subs r6, #1\n\
	ldr r4, [r7]\n\
	ldr r5, [r7, #4]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [r7, #8]\n\
	ldr r3, [r7, #0xc]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	ldr r2, [sp, #0x258]\n\
	ldr r3, [sp, #0x25c]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r7, #8]\n\
	ldr r1, [r7, #0xc]\n\
	bl __adddf3\n\
	str r0, [r7, #8]\n\
	str r1, [r7, #0xc]\n\
	ldr r2, [sp, #0x258]\n\
	ldr r3, [sp, #0x25c]\n\
	str r2, [r7]\n\
	str r3, [r7, #4]\n\
	subs r7, #8\n\
	cmp r6, #1\n\
	bgt _08250C2E\n\
_08250C6E:\n\
	ldr r1, _08250CC8 @ =0x00000000\n\
	ldr r0, _08250CC4 @ =0x00000000\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	mov r6, sb\n\
	cmp r6, #1\n\
	ble _08250C9A\n\
	lsls r0, r6, #3\n\
	mov r1, r8\n\
	adds r4, r0, r1\n\
_08250C82:\n\
	ldr r2, [r4]\n\
	ldr r3, [r4, #4]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __adddf3\n\
	str r0, [sp, #0x258]\n\
	str r1, [sp, #0x25c]\n\
	subs r4, #8\n\
	subs r6, #1\n\
	cmp r6, #1\n\
	bgt _08250C82\n\
_08250C9A:\n\
	ldr r2, [sp, #0x24c]\n\
	cmp r2, #0\n\
	bne _08250CCC\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	ldr r1, [r3, #4]\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	ldr r0, [r3, #8]\n\
	ldr r1, [r3, #0xc]\n\
	ldr r3, [sp, #0x234]\n\
	str r0, [r3, #8]\n\
	str r1, [r3, #0xc]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2, #0x10]\n\
	str r1, [r2, #0x14]\n\
	b _08250CFA\n\
	.align 2, 0\n\
_08250CC4: .4byte 0x00000000\n\
_08250CC8: .4byte 0x00000000\n\
_08250CCC:\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	ldr r1, [r3, #4]\n\
	bl __negdf2\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	mov r3, r8\n\
	ldr r0, [r3, #8]\n\
	ldr r1, [r3, #0xc]\n\
	bl __negdf2\n\
	ldr r2, [sp, #0x234]\n\
	str r0, [r2, #8]\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [sp, #0x258]\n\
	ldr r1, [sp, #0x25c]\n\
	bl __negdf2\n\
	ldr r3, [sp, #0x234]\n\
	str r0, [r3, #0x10]\n\
	str r1, [r3, #0x14]\n\
_08250CFA:\n\
	movs r0, #7\n\
	ldr r1, [sp, #0x244]\n\
	ands r0, r1\n\
	movs r3, #0x99\n\
	lsls r3, r3, #2\n\
	add sp, r3\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7, pc}\n\
 .syntax divided\n");
}
