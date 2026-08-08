#include "global.h"

// newlib/libm/e_asin.c

static const f64 one = 1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
static const f64 huge = 1.000e+300;
static const f64 pio2_hi = 1.57079632679489655800e+00; /* 0x3FF921FB, 0x54442D18 */
static const f64 pio2_lo = 6.12323399573676603587e-17; /* 0x3C91A626, 0x33145C07 */
static const f64 pio4_hi = 7.85398163397448278999e-01; /* 0x3FE921FB, 0x54442D18 */
static const f64 pS0 = 1.66666666666666657415e-01;     /* 0x3FC55555, 0x55555555 */
static const f64 pS1 = -3.25565818622400915405e-01;    /* 0xBFD4D612, 0x03EB6F7D */
static const f64 pS2 = 2.01212532134862925881e-01;     /* 0x3FC9C155, 0x0E884455 */
static const f64 pS3 = -4.00555345006794114027e-02;    /* 0xBFA48228, 0xB5688F3B */
static const f64 pS4 = 7.91534994289814532176e-04;     /* 0x3F49EFE0, 0x7501B288 */
static const f64 pS5 = 3.47933107596021167570e-05;     /* 0x3F023DE1, 0x0DFDF709 */
static const f64 qS1 = -2.40339491173441421878e+00;    /* 0xC0033A27, 0x1C8A2D4B */
static const f64 qS2 = 2.02094576023350569471e+00;     /* 0x40002AE5, 0x9C598AC8 */
static const f64 qS3 = -6.88283971605453293030e-01;    /* 0xBFE6066C, 0x1B8D0159 */
static const f64 qS4 = 7.70381505559019352791e-02;     /* 0x3FB3B8C5, 0xB12E9282 */

// 0x0824F55C
NAKED f64 __ieee754_asin(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x30\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, [sp]\n\
	mov sb, r0\n\
	ldr r1, _0824F5B0 @ =0x7FFFFFFF\n\
	ands r0, r1\n\
	mov r8, r0\n\
	ldr r0, _0824F5B4 @ =0x3FEFFFFF\n\
	cmp r8, r0\n\
	ble _0824F5E2\n\
	ldr r0, _0824F5B8 @ =0xC0100000\n\
	add r0, r8\n\
	ldr r1, [sp, #4]\n\
	orrs r0, r1\n\
	cmp r0, #0\n\
	bne _0824F5CC\n\
	ldr r2, _0824F5BC @ =0x3FF921FB\n\
	ldr r3, _0824F5C0 @ =0x54442D18\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r2, _0824F5C4 @ =0x3C91A626\n\
	ldr r3, _0824F5C8 @ =0x33145C07\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __adddf3\n\
	b _0824FA28\n\
	.align 2, 0\n\
_0824F5B0: .4byte 0x7FFFFFFF\n\
_0824F5B4: .4byte 0x3FEFFFFF\n\
_0824F5B8: .4byte 0xC0100000\n\
_0824F5BC: .4byte 0x3FF921FB\n\
_0824F5C0: .4byte 0x54442D18\n\
_0824F5C4: .4byte 0x3C91A626\n\
_0824F5C8: .4byte 0x33145C07\n\
_0824F5CC:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __divdf3\n\
	b _0824FA28\n\
_0824F5E2:\n\
	ldr r0, _0824F610 @ =0x3FDFFFFF\n\
	cmp r8, r0\n\
	ble _0824F5EA\n\
	b _0824F784\n\
_0824F5EA:\n\
	ldr r0, _0824F614 @ =0x3E3FFFFF\n\
	cmp r8, r0\n\
	bgt _0824F628\n\
	ldr r2, _0824F618 @ =0x7E37E43C\n\
	ldr r3, _0824F61C @ =0x8800759C\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __adddf3\n\
	ldr r2, _0824F620 @ =0x3FF00000\n\
	ldr r3, _0824F624 @ =0x00000000\n\
	bl __gtdf2\n\
	cmp r0, #0\n\
	ble _0824F638\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	b _0824FA28\n\
	.align 2, 0\n\
_0824F610: .4byte 0x3FDFFFFF\n\
_0824F614: .4byte 0x3E3FFFFF\n\
_0824F618: .4byte 0x7E37E43C\n\
_0824F61C: .4byte 0x8800759C\n\
_0824F620: .4byte 0x3FF00000\n\
_0824F624: .4byte 0x00000000\n\
_0824F628:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
_0824F638:\n\
	ldr r3, _0824F730 @ =0x0DFDF709\n\
	ldr r2, _0824F72C @ =0x3F023DE1\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F734 @ =0x3F49EFE0\n\
	ldr r3, _0824F738 @ =0x7501B288\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F73C @ =0xBFA48228\n\
	ldr r3, _0824F740 @ =0xB5688F3B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F744 @ =0x3FC9C155\n\
	ldr r3, _0824F748 @ =0x0E884455\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F74C @ =0xBFD4D612\n\
	ldr r3, _0824F750 @ =0x03EB6F7D\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F754 @ =0x3FC55555\n\
	ldr r3, _0824F758 @ =0x55555555\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, _0824F75C @ =0x3FB3B8C5\n\
	ldr r3, _0824F760 @ =0xB12E9282\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F764 @ =0xBFE6066C\n\
	ldr r3, _0824F768 @ =0x1B8D0159\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F76C @ =0x40002AE5\n\
	ldr r3, _0824F770 @ =0x9C598AC8\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F774 @ =0xC0033A27\n\
	ldr r3, _0824F778 @ =0x1C8A2D4B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F77C @ =0x3FF00000\n\
	ldr r3, _0824F780 @ =0x00000000\n\
	bl __adddf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	ldr r2, [sp, #0x18]\n\
	ldr r3, [sp, #0x1c]\n\
	bl __divdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __adddf3\n\
	b _0824FA28\n\
	.align 2, 0\n\
_0824F72C: .4byte 0x3F023DE1\n\
_0824F730: .4byte 0x0DFDF709\n\
_0824F734: .4byte 0x3F49EFE0\n\
_0824F738: .4byte 0x7501B288\n\
_0824F73C: .4byte 0xBFA48228\n\
_0824F740: .4byte 0xB5688F3B\n\
_0824F744: .4byte 0x3FC9C155\n\
_0824F748: .4byte 0x0E884455\n\
_0824F74C: .4byte 0xBFD4D612\n\
_0824F750: .4byte 0x03EB6F7D\n\
_0824F754: .4byte 0x3FC55555\n\
_0824F758: .4byte 0x55555555\n\
_0824F75C: .4byte 0x3FB3B8C5\n\
_0824F760: .4byte 0xB12E9282\n\
_0824F764: .4byte 0xBFE6066C\n\
_0824F768: .4byte 0x1B8D0159\n\
_0824F76C: .4byte 0x40002AE5\n\
_0824F770: .4byte 0x9C598AC8\n\
_0824F774: .4byte 0xC0033A27\n\
_0824F778: .4byte 0x1C8A2D4B\n\
_0824F77C: .4byte 0x3FF00000\n\
_0824F780: .4byte 0x00000000\n\
_0824F784:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl fdlibm_fp_fabs\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r5, _0824F8C8 @ =0x00000000\n\
	ldr r4, _0824F8C4 @ =0x3FF00000\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r2, _0824F8CC @ =0x3FE00000\n\
	ldr r3, _0824F8D0 @ =0x00000000\n\
	bl __muldf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
	ldr r2, _0824F8D4 @ =0x3F023DE1\n\
	ldr r3, _0824F8D8 @ =0x0DFDF709\n\
	bl __muldf3\n\
	ldr r2, _0824F8DC @ =0x3F49EFE0\n\
	ldr r3, _0824F8E0 @ =0x7501B288\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F8E4 @ =0xBFA48228\n\
	ldr r3, _0824F8E8 @ =0xB5688F3B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F8EC @ =0x3FC9C155\n\
	ldr r3, _0824F8F0 @ =0x0E884455\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F8F4 @ =0xBFD4D612\n\
	ldr r3, _0824F8F8 @ =0x03EB6F7D\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F8FC @ =0x3FC55555\n\
	ldr r3, _0824F900 @ =0x55555555\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, _0824F904 @ =0x3FB3B8C5\n\
	ldr r3, _0824F908 @ =0xB12E9282\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F90C @ =0xBFE6066C\n\
	ldr r3, _0824F910 @ =0x1B8D0159\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F914 @ =0x40002AE5\n\
	ldr r3, _0824F918 @ =0x9C598AC8\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F91C @ =0xC0033A27\n\
	ldr r3, _0824F920 @ =0x1C8A2D4B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __ieee754_sqrt\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	ldr r0, _0824F924 @ =0x3FEF3332\n\
	cmp r8, r0\n\
	ble _0824F938\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	ldr r2, [sp, #0x18]\n\
	ldr r3, [sp, #0x1c]\n\
	bl __divdf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	ldr r2, _0824F928 @ =0x3C91A626\n\
	ldr r3, _0824F92C @ =0x33145C07\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, _0824F930 @ =0x3FF921FB\n\
	ldr r1, _0824F934 @ =0x54442D18\n\
	b _0824F9FA\n\
	.align 2, 0\n\
_0824F8C4: .4byte 0x3FF00000\n\
_0824F8C8: .4byte 0x00000000\n\
_0824F8CC: .4byte 0x3FE00000\n\
_0824F8D0: .4byte 0x00000000\n\
_0824F8D4: .4byte 0x3F023DE1\n\
_0824F8D8: .4byte 0x0DFDF709\n\
_0824F8DC: .4byte 0x3F49EFE0\n\
_0824F8E0: .4byte 0x7501B288\n\
_0824F8E4: .4byte 0xBFA48228\n\
_0824F8E8: .4byte 0xB5688F3B\n\
_0824F8EC: .4byte 0x3FC9C155\n\
_0824F8F0: .4byte 0x0E884455\n\
_0824F8F4: .4byte 0xBFD4D612\n\
_0824F8F8: .4byte 0x03EB6F7D\n\
_0824F8FC: .4byte 0x3FC55555\n\
_0824F900: .4byte 0x55555555\n\
_0824F904: .4byte 0x3FB3B8C5\n\
_0824F908: .4byte 0xB12E9282\n\
_0824F90C: .4byte 0xBFE6066C\n\
_0824F910: .4byte 0x1B8D0159\n\
_0824F914: .4byte 0x40002AE5\n\
_0824F918: .4byte 0x9C598AC8\n\
_0824F91C: .4byte 0xC0033A27\n\
_0824F920: .4byte 0x1C8A2D4B\n\
_0824F924: .4byte 0x3FEF3332\n\
_0824F928: .4byte 0x3C91A626\n\
_0824F92C: .4byte 0x33145C07\n\
_0824F930: .4byte 0x3FF921FB\n\
_0824F934: .4byte 0x54442D18\n\
_0824F938:\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	movs r1, #0\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __subdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __divdf3\n\
	str r0, [sp, #0x28]\n\
	str r1, [sp, #0x2c]\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	ldr r2, [sp, #0x18]\n\
	ldr r3, [sp, #0x1c]\n\
	bl __divdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __muldf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp, #0x28]\n\
	ldr r1, [sp, #0x2c]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r1, _0824FA18 @ =0x33145C07\n\
	ldr r0, _0824FA14 @ =0x3C91A626\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r4, _0824FA1C @ =0x3FE921FB\n\
	ldr r5, _0824FA20 @ =0x54442D18\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __subdf3\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	ldr r2, [sp, #0x18]\n\
	ldr r3, [sp, #0x1c]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
_0824F9FA:\n\
	bl __subdf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	bgt _0824FA24\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __negdf2\n\
	b _0824FA28\n\
	.align 2, 0\n\
_0824FA14: .4byte 0x3C91A626\n\
_0824FA18: .4byte 0x33145C07\n\
_0824FA1C: .4byte 0x3FE921FB\n\
_0824FA20: .4byte 0x54442D18\n\
_0824FA24:\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
_0824FA28:\n\
	add sp, #0x30\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7, pc}\n\
   .syntax divided\n");
}
