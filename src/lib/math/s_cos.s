.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start fdlibm_cos
fdlibm_cos: @ 0x0824EBC8
	push {r4, lr}
	sub sp, #0x14
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r1, _0824EBE8 @ =0x7FFFFFFF
	ands r1, r2
	ldr r0, _0824EBEC @ =0x3FE921FB
	cmp r1, r0
	bgt _0824EBF8
	adds r1, r3, #0
	adds r0, r2, #0
	ldr r2, _0824EBF0 @ =0x00000000
	ldr r3, _0824EBF4 @ =0x00000000
	bl __kernel_cos
	b _0824EC74
	.align 2, 0
_0824EBE8: .4byte 0x7FFFFFFF
_0824EBEC: .4byte 0x3FE921FB
_0824EBF0: .4byte 0x00000000
_0824EBF4: .4byte 0x00000000
_0824EBF8:
	ldr r0, _0824EC08 @ =0x7FEFFFFF
	cmp r1, r0
	ble _0824EC0C
	adds r1, r3, #0
	adds r0, r2, #0
	bl __subdf3
	b _0824EC74
	.align 2, 0
_0824EC08: .4byte 0x7FEFFFFF
_0824EC0C:
	adds r1, r3, #0
	adds r0, r2, #0
	add r2, sp, #4
	bl __ieee754_rem_pio2
	adds r4, r0, #0
	movs r0, #3
	ands r4, r0
	cmp r4, #1
	beq _0824EC3E
	cmp r4, #1
	bgt _0824EC2A
	cmp r4, #0
	beq _0824EC30
	b _0824EC64
_0824EC2A:
	cmp r4, #2
	beq _0824EC52
	b _0824EC64
_0824EC30:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl __kernel_cos
	b _0824EC74
_0824EC3E:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	str r4, [sp]
	bl __kernel_sin
	bl __negdf2
	b _0824EC74
_0824EC52:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl __kernel_cos
	bl __negdf2
	b _0824EC74
_0824EC64:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	movs r4, #1
	str r4, [sp]
	bl __kernel_sin
_0824EC74:
	add sp, #0x14
	pop {r4, pc}
