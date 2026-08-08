
#include "global.h"

// newlib/libm/s_fabs.c

// 0x0824EC78
NAKED f64 fdlibm_fp_fabs(f64 x) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r1, #0\n\
	adds r3, r0, #0\n\
	ldr r2, _0824EC8C @ =0x7FFFFFFF\n\
	adds r0, r3, #0\n\
	ands r0, r2\n\
	adds r4, r1, #0\n\
	adds r3, r0, #0\n\
	pop {r4, pc}\n\
	.align 2, 0\n\
_0824EC8C: .4byte 0x7FFFFFFF\n\
 .syntax divided\n");
}
