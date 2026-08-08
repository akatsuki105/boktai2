#include "global.h"

// newlib/libm/e_acos.c

static const f64 one = 1.00000000000000000000e+00;     /* 0x3FF00000, 0x00000000 */
static const f64 pi = 3.14159265358979311600e+00;      /* 0x400921FB, 0x54442D18 */
static const f64 pio2_hi = 1.57079632679489655800e+00; /* 0x3FF921FB, 0x54442D18 */
static const f64 pio2_lo = 6.12323399573676603587e-17; /* 0x3C91A626, 0x33145C07 */
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

// 0x0824EFF4
NAKED f64 __ieee754_acos(f64 x) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0x28\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	adds r2, r1, #0\n\
	adds r1, r0, #0\n\
	ldr r3, _0824F020 @ =0x7FFFFFFF\n\
	ands r3, r1\n\
	ldr r0, _0824F024 @ =0x3FEFFFFF\n\
	cmp r3, r0\n\
	ble _0824F05A\n\
	ldr r4, _0824F028 @ =0xC0100000\n\
	adds r0, r3, r4\n\
	ldr r3, [sp, #4]\n\
	orrs r0, r3\n\
	cmp r0, #0\n\
	bne _0824F044\n\
	cmp r1, #0\n\
	ble _0824F034\n\
	ldr r0, _0824F02C @ =0x00000000\n\
	ldr r1, _0824F030 @ =0x00000000\n\
	b _0824F4E8\n\
	.align 2, 0\n\
_0824F020: .4byte 0x7FFFFFFF\n\
_0824F024: .4byte 0x3FEFFFFF\n\
_0824F028: .4byte 0xC0100000\n\
_0824F02C: .4byte 0x00000000\n\
_0824F030: .4byte 0x00000000\n\
_0824F034:\n\
	ldr r1, _0824F040 @ =0x54442D18\n\
	ldr r0, _0824F03C @ =0x400921FB\n\
	b _0824F4E8\n\
	.align 2, 0\n\
_0824F03C: .4byte 0x400921FB\n\
_0824F040: .4byte 0x54442D18\n\
_0824F044:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __divdf3\n\
	b _0824F4E8\n\
_0824F05A:\n\
	ldr r0, _0824F070 @ =0x3FDFFFFF\n\
	cmp r3, r0\n\
	ble _0824F062\n\
	b _0824F1F8\n\
_0824F062:\n\
	ldr r0, _0824F074 @ =0x3C600000\n\
	cmp r3, r0\n\
	bgt _0824F080\n\
	ldr r0, _0824F078 @ =0x3FF921FB\n\
	ldr r1, _0824F07C @ =0x54442D18\n\
	b _0824F4E8\n\
	.align 2, 0\n\
_0824F070: .4byte 0x3FDFFFFF\n\
_0824F074: .4byte 0x3C600000\n\
_0824F078: .4byte 0x3FF921FB\n\
_0824F07C: .4byte 0x54442D18\n\
_0824F080:\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
	ldr r3, _0824F194 @ =0x0DFDF709\n\
	ldr r2, _0824F190 @ =0x3F023DE1\n\
	bl __muldf3\n\
	ldr r2, _0824F198 @ =0x3F49EFE0\n\
	ldr r3, _0824F19C @ =0x7501B288\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1A0 @ =0xBFA48228\n\
	ldr r3, _0824F1A4 @ =0xB5688F3B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1A8 @ =0x3FC9C155\n\
	ldr r3, _0824F1AC @ =0x0E884455\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1B0 @ =0xBFD4D612\n\
	ldr r3, _0824F1B4 @ =0x03EB6F7D\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1B8 @ =0x3FC55555\n\
	ldr r3, _0824F1BC @ =0x55555555\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, _0824F1C0 @ =0x3FB3B8C5\n\
	ldr r3, _0824F1C4 @ =0xB12E9282\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1C8 @ =0xBFE6066C\n\
	ldr r3, _0824F1CC @ =0x1B8D0159\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1D0 @ =0x40002AE5\n\
	ldr r3, _0824F1D4 @ =0x9C598AC8\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1D8 @ =0xC0033A27\n\
	ldr r3, _0824F1DC @ =0x1C8A2D4B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F1E0 @ =0x3FF00000\n\
	ldr r3, _0824F1E4 @ =0x00000000\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __divdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, _0824F1E8 @ =0x3C91A626\n\
	ldr r1, _0824F1EC @ =0x33145C07\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, _0824F1F0 @ =0x3FF921FB\n\
	ldr r1, _0824F1F4 @ =0x54442D18\n\
	b _0824F4E4\n\
	.align 2, 0\n\
_0824F190: .4byte 0x3F023DE1\n\
_0824F194: .4byte 0x0DFDF709\n\
_0824F198: .4byte 0x3F49EFE0\n\
_0824F19C: .4byte 0x7501B288\n\
_0824F1A0: .4byte 0xBFA48228\n\
_0824F1A4: .4byte 0xB5688F3B\n\
_0824F1A8: .4byte 0x3FC9C155\n\
_0824F1AC: .4byte 0x0E884455\n\
_0824F1B0: .4byte 0xBFD4D612\n\
_0824F1B4: .4byte 0x03EB6F7D\n\
_0824F1B8: .4byte 0x3FC55555\n\
_0824F1BC: .4byte 0x55555555\n\
_0824F1C0: .4byte 0x3FB3B8C5\n\
_0824F1C4: .4byte 0xB12E9282\n\
_0824F1C8: .4byte 0xBFE6066C\n\
_0824F1CC: .4byte 0x1B8D0159\n\
_0824F1D0: .4byte 0x40002AE5\n\
_0824F1D4: .4byte 0x9C598AC8\n\
_0824F1D8: .4byte 0xC0033A27\n\
_0824F1DC: .4byte 0x1C8A2D4B\n\
_0824F1E0: .4byte 0x3FF00000\n\
_0824F1E4: .4byte 0x00000000\n\
_0824F1E8: .4byte 0x3C91A626\n\
_0824F1EC: .4byte 0x33145C07\n\
_0824F1F0: .4byte 0x3FF921FB\n\
_0824F1F4: .4byte 0x54442D18\n\
_0824F1F8:\n\
	cmp r1, #0\n\
	bge _0824F1FE\n\
	b _0824F3BC\n\
_0824F1FE:\n\
	ldr r7, _0824F360 @ =0x00000000\n\
	ldr r6, _0824F35C @ =0x3FF00000\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	ldr r2, [sp]\n\
	ldr r3, [sp, #4]\n\
	bl __subdf3\n\
	ldr r2, _0824F364 @ =0x3FE00000\n\
	ldr r3, _0824F368 @ =0x00000000\n\
	bl __muldf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
	bl __ieee754_sqrt\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	movs r1, #0\n\
	str r0, [sp, #0x20]\n\
	str r1, [sp, #0x24]\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __muldf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __subdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	ldr r2, [sp, #0x20]\n\
	ldr r3, [sp, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	adds r1, r5, #0\n\
	adds r0, r4, #0\n\
	bl __divdf3\n\
	adds r5, r1, #0\n\
	adds r4, r0, #0\n\
	ldr r2, _0824F36C @ =0x3F023DE1\n\
	ldr r3, _0824F370 @ =0x0DFDF709\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F374 @ =0x3F49EFE0\n\
	ldr r3, _0824F378 @ =0x7501B288\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F37C @ =0xBFA48228\n\
	ldr r3, _0824F380 @ =0xB5688F3B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F384 @ =0x3FC9C155\n\
	ldr r3, _0824F388 @ =0x0E884455\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F38C @ =0xBFD4D612\n\
	ldr r3, _0824F390 @ =0x03EB6F7D\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F394 @ =0x3FC55555\n\
	ldr r3, _0824F398 @ =0x55555555\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, _0824F39C @ =0x3FB3B8C5\n\
	ldr r3, _0824F3A0 @ =0xB12E9282\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F3A4 @ =0xBFE6066C\n\
	ldr r3, _0824F3A8 @ =0x1B8D0159\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F3AC @ =0x40002AE5\n\
	ldr r3, _0824F3B0 @ =0x9C598AC8\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F3B4 @ =0xC0033A27\n\
	ldr r3, _0824F3B8 @ =0x1C8A2D4B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __divdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r2, [sp, #0x18]\n\
	ldr r3, [sp, #0x1c]\n\
	bl __muldf3\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x20]\n\
	ldr r1, [sp, #0x24]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	b _0824F4E8\n\
	.align 2, 0\n\
_0824F35C: .4byte 0x3FF00000\n\
_0824F360: .4byte 0x00000000\n\
_0824F364: .4byte 0x3FE00000\n\
_0824F368: .4byte 0x00000000\n\
_0824F36C: .4byte 0x3F023DE1\n\
_0824F370: .4byte 0x0DFDF709\n\
_0824F374: .4byte 0x3F49EFE0\n\
_0824F378: .4byte 0x7501B288\n\
_0824F37C: .4byte 0xBFA48228\n\
_0824F380: .4byte 0xB5688F3B\n\
_0824F384: .4byte 0x3FC9C155\n\
_0824F388: .4byte 0x0E884455\n\
_0824F38C: .4byte 0xBFD4D612\n\
_0824F390: .4byte 0x03EB6F7D\n\
_0824F394: .4byte 0x3FC55555\n\
_0824F398: .4byte 0x55555555\n\
_0824F39C: .4byte 0x3FB3B8C5\n\
_0824F3A0: .4byte 0xB12E9282\n\
_0824F3A4: .4byte 0xBFE6066C\n\
_0824F3A8: .4byte 0x1B8D0159\n\
_0824F3AC: .4byte 0x40002AE5\n\
_0824F3B0: .4byte 0x9C598AC8\n\
_0824F3B4: .4byte 0xC0033A27\n\
_0824F3B8: .4byte 0x1C8A2D4B\n\
_0824F3BC:\n\
	ldr r5, _0824F4F0 @ =0x00000000\n\
	ldr r4, _0824F4EC @ =0x3FF00000\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	ldr r2, _0824F4F4 @ =0x3FE00000\n\
	ldr r3, _0824F4F8 @ =0x00000000\n\
	bl __muldf3\n\
	str r0, [sp, #8]\n\
	str r1, [sp, #0xc]\n\
	ldr r2, _0824F4FC @ =0x3F023DE1\n\
	ldr r3, _0824F500 @ =0x0DFDF709\n\
	bl __muldf3\n\
	ldr r2, _0824F504 @ =0x3F49EFE0\n\
	ldr r3, _0824F508 @ =0x7501B288\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F50C @ =0xBFA48228\n\
	ldr r3, _0824F510 @ =0xB5688F3B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F514 @ =0x3FC9C155\n\
	ldr r3, _0824F518 @ =0x0E884455\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F51C @ =0xBFD4D612\n\
	ldr r3, _0824F520 @ =0x03EB6F7D\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F524 @ =0x3FC55555\n\
	ldr r3, _0824F528 @ =0x55555555\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, _0824F52C @ =0x3FB3B8C5\n\
	ldr r3, _0824F530 @ =0xB12E9282\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F534 @ =0xBFE6066C\n\
	ldr r3, _0824F538 @ =0x1B8D0159\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F53C @ =0x40002AE5\n\
	ldr r3, _0824F540 @ =0x9C598AC8\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	ldr r2, _0824F544 @ =0xC0033A27\n\
	ldr r3, _0824F548 @ =0x1C8A2D4B\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __muldf3\n\
	adds r3, r5, #0\n\
	adds r2, r4, #0\n\
	bl __adddf3\n\
	adds r7, r1, #0\n\
	adds r6, r0, #0\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl __ieee754_sqrt\n\
	str r0, [sp, #0x18]\n\
	str r1, [sp, #0x1c]\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, [sp, #0x14]\n\
	adds r3, r7, #0\n\
	adds r2, r6, #0\n\
	bl __divdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r2, [sp, #0x18]\n\
	ldr r3, [sp, #0x1c]\n\
	bl __muldf3\n\
	ldr r2, _0824F54C @ =0x3C91A626\n\
	ldr r3, _0824F550 @ =0x33145C07\n\
	bl __subdf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, [sp, #0x1c]\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	bl __adddf3\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
	ldr r0, _0824F554 @ =0x400921FB\n\
	ldr r1, _0824F558 @ =0x54442D18\n\
_0824F4E4:\n\
	bl __subdf3\n\
_0824F4E8:\n\
	add sp, #0x28\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_0824F4EC: .4byte 0x3FF00000\n\
_0824F4F0: .4byte 0x00000000\n\
_0824F4F4: .4byte 0x3FE00000\n\
_0824F4F8: .4byte 0x00000000\n\
_0824F4FC: .4byte 0x3F023DE1\n\
_0824F500: .4byte 0x0DFDF709\n\
_0824F504: .4byte 0x3F49EFE0\n\
_0824F508: .4byte 0x7501B288\n\
_0824F50C: .4byte 0xBFA48228\n\
_0824F510: .4byte 0xB5688F3B\n\
_0824F514: .4byte 0x3FC9C155\n\
_0824F518: .4byte 0x0E884455\n\
_0824F51C: .4byte 0xBFD4D612\n\
_0824F520: .4byte 0x03EB6F7D\n\
_0824F524: .4byte 0x3FC55555\n\
_0824F528: .4byte 0x55555555\n\
_0824F52C: .4byte 0x3FB3B8C5\n\
_0824F530: .4byte 0xB12E9282\n\
_0824F534: .4byte 0xBFE6066C\n\
_0824F538: .4byte 0x1B8D0159\n\
_0824F53C: .4byte 0x40002AE5\n\
_0824F540: .4byte 0x9C598AC8\n\
_0824F544: .4byte 0xC0033A27\n\
_0824F548: .4byte 0x1C8A2D4B\n\
_0824F54C: .4byte 0x3C91A626\n\
_0824F550: .4byte 0x33145C07\n\
_0824F554: .4byte 0x400921FB\n\
_0824F558: .4byte 0x54442D18\n\
 .syntax divided\n");
}
