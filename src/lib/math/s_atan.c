
#include "global.h"

// newlib/libm/s_atan.c

static const f64 atanhi[4] = {
    4.63647609000806093515e-01, /* atan(0.5)hi 0x3FDDAC67, 0x0561BB4F */
    7.85398163397448278999e-01, /* atan(1.0)hi 0x3FE921FB, 0x54442D18 */
    9.82793723247329054082e-01, /* atan(1.5)hi 0x3FEF730B, 0xD281F69B */
    1.57079632679489655800e+00, /* atan(inf)hi 0x3FF921FB, 0x54442D18 */
};

static const f64 atanlo[4] = {
    2.26987774529616870924e-17, /* atan(0.5)lo 0x3C7A2B7F, 0x222F65E2 */
    3.06161699786838301793e-17, /* atan(1.0)lo 0x3C81A626, 0x33145C07 */
    1.39033110312309984516e-17, /* atan(1.5)lo 0x3C700788, 0x7AF0CBBD */
    6.12323399573676603587e-17, /* atan(inf)lo 0x3C91A626, 0x33145C07 */
};

static const f64 aT[11] = {
    3.33333333333329318027e-01,  /* 0x3FD55555, 0x5555550D */
    -1.99999999998764832476e-01, /* 0xBFC99999, 0x9998EBC4 */
    1.42857142725034663711e-01,  /* 0x3FC24924, 0x920083FF */
    -1.11111104054623557880e-01, /* 0xBFBC71C6, 0xFE231671 */
    9.09088713343650656196e-02,  /* 0x3FB745CD, 0xC54C206E */
    -7.69187620504482999495e-02, /* 0xBFB3B0F2, 0xAF749A6D */
    6.66107313738753120669e-02,  /* 0x3FB10D66, 0xA0D03D51 */
    -5.83357013379057348645e-02, /* 0xBFADDE2D, 0x52DEFD9A */
    4.97687799461593236017e-02,  /* 0x3FA97B4B, 0x24760DEB */
    -3.65315727442169155270e-02, /* 0xBFA2B444, 0x2C6A6C2F */
    1.62858201153657823623e-02,  /* 0x3F90AD3A, 0xE322DA11 */
};

static const f64 one = 1.0, huge = 1.0e300;

// 0x0824E854
NAKED f64 fdlibm_atan(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x18\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, [sp]\n\
	mov sb, r0\n\
	ldr r4, _0824E890 @ =0x7FFFFFFF\n\
	ands r4, r0\n\
	ldr r0, _0824E894 @ =0x440FFFFF\n\
	cmp r4, r0\n\
	ble _0824E8DC\n\
	ldr r0, [sp, #4]\n\
	ldr r1, _0824E898 @ =0x7FF00000\n\
	cmp r4, r1\n\
	bgt _0824E880\n\
	cmp r4, r1\n\
	bne _0824E89C\n\
	cmp r0, #0\n\
	beq _0824E89C\n\
_0824E880:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	b _0824EBB6\n\
	.align 2, 0\n\
_0824E890: .4byte 0x7FFFFFFF\n\
_0824E894: .4byte 0x440FFFFF\n\
_0824E898: .4byte 0x7FF00000\n\
_0824E89C:\n\
	mov r2, sb\n\
	cmp r2, #0\n\
	ble _0824E8BC\n\
	ldr r0, _0824E8B4 @ =atanhi\n\
	ldr r2, _0824E8B8 @ =atanlo\n\
	ldr r1, [r0, #0x1c]\n\
	ldr r0, [r0, #0x18]\n\
	ldr r3, [r2, #0x1c]\n\
	ldr r2, [r2, #0x18]\n\
	bl __adddf3\n\
	b _0824EBB6\n\
	.align 2, 0\n\
_0824E8B4: .4byte atanhi\n\
_0824E8B8: .4byte atanlo\n\
_0824E8BC:\n\
	ldr r0, _0824E8D4 @ =atanhi\n\
	ldr r1, [r0, #0x1c]\n\
	ldr r0, [r0, #0x18]\n\
	bl __negdf2\n\
	ldr r2, _0824E8D8 @ =atanlo\n\
	ldr r3, [r2, #0x1c]\n\
	ldr r2, [r2, #0x18]\n\
	bl __subdf3\n\
	b _0824EBB6\n\
	.align 2, 0\n\
_0824E8D4: .4byte atanhi\n\
_0824E8D8: .4byte atanlo\n\
_0824E8DC:\n\
	ldr r0, _0824E908 @ =0x3FDBFFFF\n\
	cmp r4, r0\n\
	bgt _0824E928\n\
	ldr r0, _0824E90C @ =0x3E1FFFFF\n\
	cmp r4, r0\n\
	bgt _0824E920\n\
	ldr r2, _0824E910 @ =0x7E37E43C\n\
	ldr r3, _0824E914 @ =0x8800759C\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __adddf3\n\
	ldr r2, _0824E918 @ =0x3FF00000\n\
	ldr r3, _0824E91C @ =0x00000000\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	ble _0824E920\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	b _0824EBB6\n\
	.align 2, 0\n\
_0824E908: .4byte 0x3FDBFFFF\n\
_0824E90C: .4byte 0x3E1FFFFF\n\
_0824E910: .4byte 0x7E37E43C\n\
_0824E914: .4byte 0x8800759C\n\
_0824E918: .4byte 0x3FF00000\n\
_0824E91C: .4byte 0x00000000\n\
_0824E920:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	mov r8, r0\n\
	b _0824EA28\n\
_0824E928:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl fdlibm_fp_fabs\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, _0824E974 @ =0x3FF2FFFF\n\
	cmp r4, r0\n\
	bgt _0824E9C4\n\
	ldr r0, _0824E978 @ =0x3FE5FFFF\n\
	cmp r4, r0\n\
	bgt _0824E98C\n\
	movs r2, #0\n\
	mov r8, r2\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	ldr r2, _0824E97C @ =0x3FF00000\n\
	ldr r3, _0824E980 @ =0x00000000\n\
	bl __subdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r2, _0824E984 @ =0x40000000\n\
	ldr r3, _0824E988 @ =0x00000000\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	b _0824EA20\n\
	.align 2, 0\n\
_0824E974: .4byte 0x3FF2FFFF\n\
_0824E978: .4byte 0x3FE5FFFF\n\
_0824E97C: .4byte 0x3FF00000\n\
_0824E980: .4byte 0x00000000\n\
_0824E984: .4byte 0x40000000\n\
_0824E988: .4byte 0x00000000\n\
_0824E98C:\n\
	movs r0, #1\n\
	mov r8, r0\n\
	ldr r5, _0824E9C0 @ =0x00000000\n\
	ldr r4, _0824E9BC @ =0x3FF00000\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	b _0824EA20\n\
	.align 2, 0\n\
_0824E9BC: .4byte 0x3FF00000\n\
_0824E9C0: .4byte 0x00000000\n\
_0824E9C4:\n\
	ldr r0, _0824EA00 @ =0x40037FFF\n\
	cmp r4, r0\n\
	bgt _0824EA14\n\
	movs r2, #2\n\
	mov r8, r2\n\
	ldr r4, _0824EA04 @ =0x3FF80000\n\
	ldr r5, _0824EA08 @ =0x00000000\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __muldf3\n\
	ldr r2, _0824EA0C @ =0x3FF00000\n\
	ldr r3, _0824EA10 @ =0x00000000\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	b _0824EA20\n\
	.align 2, 0\n\
_0824EA00: .4byte 0x40037FFF\n\
_0824EA04: .4byte 0x3FF80000\n\
_0824EA08: .4byte 0x00000000\n\
_0824EA0C: .4byte 0x3FF00000\n\
_0824EA10: .4byte 0x00000000\n\
_0824EA14:\n\
	movs r0, #3\n\
	mov r8, r0\n\
	ldr r1, _0824EB68 @ =0x00000000\n\
	ldr r0, _0824EB64 @ =0xBFF00000\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
_0824EA20:\n\
	bl __divdf3\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
_0824EA28:\n\
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
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r6, _0824EB6C @ =0x085A8BE8\n\
	ldr r2, [r6, #0x50]\n\
	ldr r3, [r6, #0x54]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x40]\n\
	ldr r1, [r6, #0x44]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x30]\n\
	ldr r1, [r6, #0x34]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x20]\n\
	ldr r1, [r6, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x10]\n\
	ldr r1, [r6, #0x14]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6]\n\
	ldr r1, [r6, #4]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	bl __muldf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
	ldr r2, [r6, #0x48]\n\
	ldr r3, [r6, #0x4c]\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x38]\n\
	ldr r1, [r6, #0x3c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x28]\n\
	ldr r1, [r6, #0x2c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #0x18]\n\
	ldr r1, [r6, #0x1c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r6, #8]\n\
	ldr r1, [r6, #0xc]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	bge _0824EB70\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __subdf3\n\
	b _0824EBB6\n\
	.align 2, 0\n\
_0824EB64: .4byte 0xBFF00000\n\
_0824EB68: .4byte 0x00000000\n\
_0824EB6C: .4byte 0x085A8BE8\n\
_0824EB70:\n\
	ldr r5, _0824EBC0 @ =atanhi\n\
	mov r0, r8\n\
	lsls r4, r0, #3\n\
	adds r5, r4, r5\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __muldf3\n\
	ldr r2, _0824EBC4 @ =atanlo\n\
	adds r4, r4, r2\n\
	ldr r2, [r4]\n\
	ldr r3, [r4, #4]\n\
	bl __subdf3\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [r5]\n\
	ldr r1, [r5, #4]\n\
	bl __subdf3\n\
	mov r2, sb\n\
	cmp r2, #0\n\
	bge _0824EBB6\n\
	bl __negdf2\n\
_0824EBB6:\n\
	add sp, #0x18\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_0824EBC0: .4byte atanhi\n\
_0824EBC4: .4byte atanlo\n\
 .syntax divided\n");
}
