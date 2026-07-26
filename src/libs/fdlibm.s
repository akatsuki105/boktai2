	.include "asm/macros.inc"

	.syntax unified

	.text

@ pret/agbcc/math にない fdlibm の関数

	thumb_func_start fdlibm_atan
fdlibm_atan: @ 0x0824E854
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	mov sb, r0
	ldr r4, _0824E890 @ =0x7FFFFFFF
	ands r4, r0
	ldr r0, _0824E894 @ =0x440FFFFF
	cmp r4, r0
	ble _0824E8DC
	ldr r0, [sp, #4]
	ldr r1, _0824E898 @ =0x7FF00000
	cmp r4, r1
	bgt _0824E880
	cmp r4, r1
	bne _0824E89C
	cmp r0, #0
	beq _0824E89C
_0824E880:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	b _0824EBB6
	.align 2, 0
_0824E890: .4byte 0x7FFFFFFF
_0824E894: .4byte 0x440FFFFF
_0824E898: .4byte 0x7FF00000
_0824E89C:
	mov r2, sb
	cmp r2, #0
	ble _0824E8BC
	ldr r0, _0824E8B4 @ =0x085A8BA8
	ldr r2, _0824E8B8 @ =0x085A8BC8
	ldr r1, [r0, #0x1c]
	ldr r0, [r0, #0x18]
	ldr r3, [r2, #0x1c]
	ldr r2, [r2, #0x18]
	bl __adddf3
	b _0824EBB6
	.align 2, 0
_0824E8B4: .4byte 0x085A8BA8
_0824E8B8: .4byte 0x085A8BC8
_0824E8BC:
	ldr r0, _0824E8D4 @ =0x085A8BA8
	ldr r1, [r0, #0x1c]
	ldr r0, [r0, #0x18]
	bl __negdf2
	ldr r2, _0824E8D8 @ =0x085A8BC8
	ldr r3, [r2, #0x1c]
	ldr r2, [r2, #0x18]
	bl __subdf3
	b _0824EBB6
	.align 2, 0
_0824E8D4: .4byte 0x085A8BA8
_0824E8D8: .4byte 0x085A8BC8
_0824E8DC:
	ldr r0, _0824E908 @ =0x3FDBFFFF
	cmp r4, r0
	bgt _0824E928
	ldr r0, _0824E90C @ =0x3E1FFFFF
	cmp r4, r0
	bgt _0824E920
	ldr r2, _0824E910 @ =0x7E37E43C
	ldr r3, _0824E914 @ =0x8800759C
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __adddf3
	ldr r2, _0824E918 @ =0x3FF00000
	ldr r3, _0824E91C @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	ble _0824E920
	ldr r0, [sp]
	ldr r1, [sp, #4]
	b _0824EBB6
	.align 2, 0
_0824E908: .4byte 0x3FDBFFFF
_0824E90C: .4byte 0x3E1FFFFF
_0824E910: .4byte 0x7E37E43C
_0824E914: .4byte 0x8800759C
_0824E918: .4byte 0x3FF00000
_0824E91C: .4byte 0x00000000
_0824E920:
	movs r0, #1
	rsbs r0, r0, #0
	mov r8, r0
	b _0824EA28
_0824E928:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl fdlibm_fp_fabs
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _0824E974 @ =0x3FF2FFFF
	cmp r4, r0
	bgt _0824E9C4
	ldr r0, _0824E978 @ =0x3FE5FFFF
	cmp r4, r0
	bgt _0824E98C
	movs r2, #0
	mov r8, r2
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	ldr r2, _0824E97C @ =0x3FF00000
	ldr r3, _0824E980 @ =0x00000000
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0824E984 @ =0x40000000
	ldr r3, _0824E988 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	b _0824EA20
	.align 2, 0
_0824E974: .4byte 0x3FF2FFFF
_0824E978: .4byte 0x3FE5FFFF
_0824E97C: .4byte 0x3FF00000
_0824E980: .4byte 0x00000000
_0824E984: .4byte 0x40000000
_0824E988: .4byte 0x00000000
_0824E98C:
	movs r0, #1
	mov r8, r0
	ldr r5, _0824E9C0 @ =0x00000000
	ldr r4, _0824E9BC @ =0x3FF00000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	b _0824EA20
	.align 2, 0
_0824E9BC: .4byte 0x3FF00000
_0824E9C0: .4byte 0x00000000
_0824E9C4:
	ldr r0, _0824EA00 @ =0x40037FFF
	cmp r4, r0
	bgt _0824EA14
	movs r2, #2
	mov r8, r2
	ldr r4, _0824EA04 @ =0x3FF80000
	ldr r5, _0824EA08 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	ldr r2, _0824EA0C @ =0x3FF00000
	ldr r3, _0824EA10 @ =0x00000000
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	b _0824EA20
	.align 2, 0
_0824EA00: .4byte 0x40037FFF
_0824EA04: .4byte 0x3FF80000
_0824EA08: .4byte 0x00000000
_0824EA0C: .4byte 0x3FF00000
_0824EA10: .4byte 0x00000000
_0824EA14:
	movs r0, #3
	mov r8, r0
	ldr r1, _0824EB68 @ =0x00000000
	ldr r0, _0824EB64 @ =0xBFF00000
	ldr r2, [sp]
	ldr r3, [sp, #4]
_0824EA20:
	bl __divdf3
	str r0, [sp]
	str r1, [sp, #4]
_0824EA28:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r6, _0824EB6C @ =0x085A8BE8
	ldr r2, [r6, #0x50]
	ldr r3, [r6, #0x54]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x40]
	ldr r1, [r6, #0x44]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x30]
	ldr r1, [r6, #0x34]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl __muldf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r6, #0x48]
	ldr r3, [r6, #0x4c]
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x38]
	ldr r1, [r6, #0x3c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	mov r0, r8
	cmp r0, #0
	bge _0824EB70
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __subdf3
	b _0824EBB6
	.align 2, 0
_0824EB64: .4byte 0xBFF00000
_0824EB68: .4byte 0x00000000
_0824EB6C: .4byte 0x085A8BE8
_0824EB70:
	ldr r5, _0824EBC0 @ =0x085A8BA8
	mov r0, r8
	lsls r4, r0, #3
	adds r5, r4, r5
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0824EBC4 @ =0x085A8BC8
	adds r4, r4, r2
	ldr r2, [r4]
	ldr r3, [r4, #4]
	bl __subdf3
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	bl __subdf3
	mov r2, sb
	cmp r2, #0
	bge _0824EBB6
	bl __negdf2
_0824EBB6:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0824EBC0: .4byte 0x085A8BA8
_0824EBC4: .4byte 0x085A8BC8

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

	thumb_func_start fdlibm_fp_fabs
fdlibm_fp_fabs: @ 0x0824EC78
	push {r4, lr}
	adds r4, r1, #0
	adds r3, r0, #0
	ldr r2, _0824EC8C @ =0x7FFFFFFF
	adds r0, r3, #0
	ands r0, r2
	adds r4, r1, #0
	adds r3, r0, #0
	pop {r4, pc}
	.align 2, 0
_0824EC8C: .4byte 0x7FFFFFFF

	thumb_func_start fdlibm_sin
fdlibm_sin: @ 0x0824EC90
	push {r4, lr}
	sub sp, #0x14
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r1, _0824ECB4 @ =0x7FFFFFFF
	ands r1, r2
	ldr r0, _0824ECB8 @ =0x3FE921FB
	cmp r1, r0
	bgt _0824ECC4
	movs r0, #0
	str r0, [sp]
	adds r1, r3, #0
	adds r0, r2, #0
	ldr r2, _0824ECBC @ =0x00000000
	ldr r3, _0824ECC0 @ =0x00000000
	bl __kernel_sin
	b _0824ED3E
	.align 2, 0
_0824ECB4: .4byte 0x7FFFFFFF
_0824ECB8: .4byte 0x3FE921FB
_0824ECBC: .4byte 0x00000000
_0824ECC0: .4byte 0x00000000
_0824ECC4:
	ldr r0, _0824ECD4 @ =0x7FEFFFFF
	cmp r1, r0
	ble _0824ECD8
	adds r1, r3, #0
	adds r0, r2, #0
	bl __subdf3
	b _0824ED3E
	.align 2, 0
_0824ECD4: .4byte 0x7FEFFFFF
_0824ECD8:
	adds r1, r3, #0
	adds r0, r2, #0
	add r2, sp, #4
	bl __ieee754_rem_pio2
	adds r1, r0, #0
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _0824ED0E
	cmp r1, #1
	bgt _0824ECF6
	cmp r1, #0
	beq _0824ECFC
	b _0824ED2E
_0824ECF6:
	cmp r1, #2
	beq _0824ED1C
	b _0824ED2E
_0824ECFC:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	movs r4, #1
	str r4, [sp]
	bl __kernel_sin
	b _0824ED3E
_0824ED0E:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl __kernel_cos
	b _0824ED3E
_0824ED1C:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	movs r4, #1
	str r4, [sp]
	bl __kernel_sin
	b _0824ED3A
_0824ED2E:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl __kernel_cos
_0824ED3A:
	bl __negdf2
_0824ED3E:
	add sp, #0x14
	pop {r4, pc}
	.align 2, 0

	thumb_func_start fdlibm_tan
fdlibm_tan: @ 0x0824ED44
	push {r4, r5, lr}
	sub sp, #0x14
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r1, _0824ED68 @ =0x7FFFFFFF
	ands r1, r2
	ldr r0, _0824ED6C @ =0x3FE921FB
	cmp r1, r0
	bgt _0824ED78
	movs r0, #1
	str r0, [sp]
	adds r1, r3, #0
	adds r0, r2, #0
	ldr r2, _0824ED70 @ =0x00000000
	ldr r3, _0824ED74 @ =0x00000000
	bl __kernel_tan
	b _0824EDB0
	.align 2, 0
_0824ED68: .4byte 0x7FFFFFFF
_0824ED6C: .4byte 0x3FE921FB
_0824ED70: .4byte 0x00000000
_0824ED74: .4byte 0x00000000
_0824ED78:
	ldr r0, _0824EDA4 @ =0x7FEFFFFF
	cmp r1, r0
	bgt _0824EDA8
	adds r1, r3, #0
	adds r0, r2, #0
	add r2, sp, #4
	bl __ieee754_rem_pio2
	ldr r4, [sp, #4]
	ldr r5, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #1
	subs r1, r1, r0
	str r1, [sp]
	adds r1, r5, #0
	adds r0, r4, #0
	bl __kernel_tan
	b _0824EDB0
	.align 2, 0
_0824EDA4: .4byte 0x7FEFFFFF
_0824EDA8:
	adds r1, r3, #0
	adds r0, r2, #0
	bl __subdf3
_0824EDB0:
	add sp, #0x14
	pop {r4, r5, pc}

	thumb_func_start fdlibm_acos
fdlibm_acos: @ 0x0824EDB4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r1, #0
	adds r4, r0, #0
	bl __ieee754_acos
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0824EE44 @ =0x085A90B8
	ldr r0, [r0]
	mov sb, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp sb, r0
	beq _0824EE5C
	adds r1, r5, #0
	adds r0, r4, #0
	bl isnan
	mov r8, r0
	cmp r0, #0
	bne _0824EE5C
	adds r1, r5, #0
	adds r0, r4, #0
	bl fdlibm_fp_fabs
	ldr r2, _0824EE48 @ =0x3FF00000
	ldr r3, _0824EE4C @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	ble _0824EE5C
	movs r0, #1
	str r0, [sp]
	ldr r0, _0824EE50 @ =0x085A8C50
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #0x20]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	ldr r0, _0824EE54 @ =0x00000000
	ldr r1, _0824EE58 @ =0x00000000
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	mov r0, sb
	cmp r0, #2
	beq _0824EE26
	mov r0, sp
	bl FUN_082513fc
	cmp r0, #0
	bne _0824EE2E
_0824EE26:
	bl __errno
	movs r1, #0x21
	str r1, [r0]
_0824EE2E:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0824EE3C
	bl __errno
	ldr r1, [sp, #0x20]
	str r1, [r0]
_0824EE3C:
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	b _0824EE60
	.align 2, 0
_0824EE44: .4byte 0x085A90B8
_0824EE48: .4byte 0x3FF00000
_0824EE4C: .4byte 0x00000000
_0824EE50: .4byte 0x085A8C50
_0824EE54: .4byte 0x00000000
_0824EE58: .4byte 0x00000000
_0824EE5C:
	adds r1, r7, #0
	adds r0, r6, #0
_0824EE60:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start fdlibm_asin
fdlibm_asin: @ 0x0824EE6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r1, #0
	adds r4, r0, #0
	bl __ieee754_asin
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0824EEFC @ =0x085A90B8
	ldr r0, [r0]
	mov sb, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp sb, r0
	beq _0824EF14
	adds r1, r5, #0
	adds r0, r4, #0
	bl isnan
	mov r8, r0
	cmp r0, #0
	bne _0824EF14
	adds r1, r5, #0
	adds r0, r4, #0
	bl fdlibm_fp_fabs
	ldr r2, _0824EF00 @ =0x3FF00000
	ldr r3, _0824EF04 @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	ble _0824EF14
	movs r0, #1
	str r0, [sp]
	ldr r0, _0824EF08 @ =0x085A8C58
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #0x20]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	ldr r0, _0824EF0C @ =0x00000000
	ldr r1, _0824EF10 @ =0x00000000
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	mov r0, sb
	cmp r0, #2
	beq _0824EEDE
	mov r0, sp
	bl FUN_082513fc
	cmp r0, #0
	bne _0824EEE6
_0824EEDE:
	bl __errno
	movs r1, #0x21
	str r1, [r0]
_0824EEE6:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0824EEF4
	bl __errno
	ldr r1, [sp, #0x20]
	str r1, [r0]
_0824EEF4:
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	b _0824EF18
	.align 2, 0
_0824EEFC: .4byte 0x085A90B8
_0824EF00: .4byte 0x3FF00000
_0824EF04: .4byte 0x00000000
_0824EF08: .4byte 0x085A8C58
_0824EF0C: .4byte 0x00000000
_0824EF10: .4byte 0x00000000
_0824EF14:
	adds r1, r7, #0
	adds r0, r6, #0
_0824EF18:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start fdlibm_fmod
fdlibm_fmod: @ 0x0824EF24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r7, r1, #0
	adds r6, r0, #0
	adds r5, r3, #0
	adds r4, r2, #0
	bl __ieee754_fmod
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldr r0, _0824EF94 @ =0x085A90B8
	ldr r0, [r0]
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq _0824EFE8
	adds r1, r5, #0
	adds r0, r4, #0
	bl isnan
	cmp r0, #0
	bne _0824EFE8
	adds r1, r7, #0
	adds r0, r6, #0
	bl isnan
	cmp r0, #0
	bne _0824EFE8
	ldr r2, _0824EF98 @ =0x00000000
	ldr r3, _0824EF9C @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	bl __eqdf2
	adds r1, r0, #0
	cmp r1, #0
	bne _0824EFE8
	movs r0, #1
	str r0, [sp]
	ldr r0, _0824EFA0 @ =0x085A8C60
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r7, [sp, #0xc]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r1, [sp, #0x20]
	mov r0, r8
	cmp r0, #0
	bne _0824EFA4
	str r6, [sp, #0x18]
	str r7, [sp, #0x1c]
	b _0824EFAC
	.align 2, 0
_0824EF94: .4byte 0x085A90B8
_0824EF98: .4byte 0x00000000
_0824EF9C: .4byte 0x00000000
_0824EFA0: .4byte 0x085A8C60
_0824EFA4:
	ldr r1, _0824EFE0 @ =0xFFFFFFFF
	ldr r0, _0824EFDC @ =0x7FFFFFFF
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
_0824EFAC:
	ldr r0, _0824EFE4 @ =0x085A90B8
	ldr r0, [r0]
	cmp r0, #2
	beq _0824EFBE
	mov r0, sp
	bl FUN_082513fc
	cmp r0, #0
	bne _0824EFC6
_0824EFBE:
	bl __errno
	movs r1, #0x21
	str r1, [r0]
_0824EFC6:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0824EFD4
	bl __errno
	ldr r1, [sp, #0x20]
	str r1, [r0]
_0824EFD4:
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	b _0824EFEC
	.align 2, 0
_0824EFDC: .4byte 0x7FFFFFFF
_0824EFE0: .4byte 0xFFFFFFFF
_0824EFE4: .4byte 0x085A90B8
_0824EFE8:
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
_0824EFEC:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}

	thumb_func_start __ieee754_acos
__ieee754_acos: @ 0x0824EFF4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp]
	str r1, [sp, #4]
	adds r2, r1, #0
	adds r1, r0, #0
	ldr r3, _0824F020 @ =0x7FFFFFFF
	ands r3, r1
	ldr r0, _0824F024 @ =0x3FEFFFFF
	cmp r3, r0
	ble _0824F05A
	ldr r4, _0824F028 @ =0xC0100000
	adds r0, r3, r4
	ldr r3, [sp, #4]
	orrs r0, r3
	cmp r0, #0
	bne _0824F044
	cmp r1, #0
	ble _0824F034
	ldr r0, _0824F02C @ =0x00000000
	ldr r1, _0824F030 @ =0x00000000
	b _0824F4E8
	.align 2, 0
_0824F020: .4byte 0x7FFFFFFF
_0824F024: .4byte 0x3FEFFFFF
_0824F028: .4byte 0xC0100000
_0824F02C: .4byte 0x00000000
_0824F030: .4byte 0x00000000
_0824F034:
	ldr r1, _0824F040 @ =0x54442D18
	ldr r0, _0824F03C @ =0x400921FB
	b _0824F4E8
	.align 2, 0
_0824F03C: .4byte 0x400921FB
_0824F040: .4byte 0x54442D18
_0824F044:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __divdf3
	b _0824F4E8
_0824F05A:
	ldr r0, _0824F070 @ =0x3FDFFFFF
	cmp r3, r0
	ble _0824F062
	b _0824F1F8
_0824F062:
	ldr r0, _0824F074 @ =0x3C600000
	cmp r3, r0
	bgt _0824F080
	ldr r0, _0824F078 @ =0x3FF921FB
	ldr r1, _0824F07C @ =0x54442D18
	b _0824F4E8
	.align 2, 0
_0824F070: .4byte 0x3FDFFFFF
_0824F074: .4byte 0x3C600000
_0824F078: .4byte 0x3FF921FB
_0824F07C: .4byte 0x54442D18
_0824F080:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r3, _0824F194 @ =0x0DFDF709
	ldr r2, _0824F190 @ =0x3F023DE1
	bl __muldf3
	ldr r2, _0824F198 @ =0x3F49EFE0
	ldr r3, _0824F19C @ =0x7501B288
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1A0 @ =0xBFA48228
	ldr r3, _0824F1A4 @ =0xB5688F3B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1A8 @ =0x3FC9C155
	ldr r3, _0824F1AC @ =0x0E884455
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1B0 @ =0xBFD4D612
	ldr r3, _0824F1B4 @ =0x03EB6F7D
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1B8 @ =0x3FC55555
	ldr r3, _0824F1BC @ =0x55555555
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _0824F1C0 @ =0x3FB3B8C5
	ldr r3, _0824F1C4 @ =0xB12E9282
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1C8 @ =0xBFE6066C
	ldr r3, _0824F1CC @ =0x1B8D0159
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1D0 @ =0x40002AE5
	ldr r3, _0824F1D4 @ =0x9C598AC8
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1D8 @ =0xC0033A27
	ldr r3, _0824F1DC @ =0x1C8A2D4B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F1E0 @ =0x3FF00000
	ldr r3, _0824F1E4 @ =0x00000000
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __divdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0824F1E8 @ =0x3C91A626
	ldr r1, _0824F1EC @ =0x33145C07
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0824F1F0 @ =0x3FF921FB
	ldr r1, _0824F1F4 @ =0x54442D18
	b _0824F4E4
	.align 2, 0
_0824F190: .4byte 0x3F023DE1
_0824F194: .4byte 0x0DFDF709
_0824F198: .4byte 0x3F49EFE0
_0824F19C: .4byte 0x7501B288
_0824F1A0: .4byte 0xBFA48228
_0824F1A4: .4byte 0xB5688F3B
_0824F1A8: .4byte 0x3FC9C155
_0824F1AC: .4byte 0x0E884455
_0824F1B0: .4byte 0xBFD4D612
_0824F1B4: .4byte 0x03EB6F7D
_0824F1B8: .4byte 0x3FC55555
_0824F1BC: .4byte 0x55555555
_0824F1C0: .4byte 0x3FB3B8C5
_0824F1C4: .4byte 0xB12E9282
_0824F1C8: .4byte 0xBFE6066C
_0824F1CC: .4byte 0x1B8D0159
_0824F1D0: .4byte 0x40002AE5
_0824F1D4: .4byte 0x9C598AC8
_0824F1D8: .4byte 0xC0033A27
_0824F1DC: .4byte 0x1C8A2D4B
_0824F1E0: .4byte 0x3FF00000
_0824F1E4: .4byte 0x00000000
_0824F1E8: .4byte 0x3C91A626
_0824F1EC: .4byte 0x33145C07
_0824F1F0: .4byte 0x3FF921FB
_0824F1F4: .4byte 0x54442D18
_0824F1F8:
	cmp r1, #0
	bge _0824F1FE
	b _0824F3BC
_0824F1FE:
	ldr r7, _0824F360 @ =0x00000000
	ldr r6, _0824F35C @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __subdf3
	ldr r2, _0824F364 @ =0x3FE00000
	ldr r3, _0824F368 @ =0x00000000
	bl __muldf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	bl fdlibm_sqrt
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r1, #0
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __divdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0824F36C @ =0x3F023DE1
	ldr r3, _0824F370 @ =0x0DFDF709
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F374 @ =0x3F49EFE0
	ldr r3, _0824F378 @ =0x7501B288
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F37C @ =0xBFA48228
	ldr r3, _0824F380 @ =0xB5688F3B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F384 @ =0x3FC9C155
	ldr r3, _0824F388 @ =0x0E884455
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F38C @ =0xBFD4D612
	ldr r3, _0824F390 @ =0x03EB6F7D
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F394 @ =0x3FC55555
	ldr r3, _0824F398 @ =0x55555555
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _0824F39C @ =0x3FB3B8C5
	ldr r3, _0824F3A0 @ =0xB12E9282
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F3A4 @ =0xBFE6066C
	ldr r3, _0824F3A8 @ =0x1B8D0159
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F3AC @ =0x40002AE5
	ldr r3, _0824F3B0 @ =0x9C598AC8
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F3B4 @ =0xC0033A27
	ldr r3, _0824F3B8 @ =0x1C8A2D4B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	adds r3, r7, #0
	adds r2, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __divdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __muldf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	b _0824F4E8
	.align 2, 0
_0824F35C: .4byte 0x3FF00000
_0824F360: .4byte 0x00000000
_0824F364: .4byte 0x3FE00000
_0824F368: .4byte 0x00000000
_0824F36C: .4byte 0x3F023DE1
_0824F370: .4byte 0x0DFDF709
_0824F374: .4byte 0x3F49EFE0
_0824F378: .4byte 0x7501B288
_0824F37C: .4byte 0xBFA48228
_0824F380: .4byte 0xB5688F3B
_0824F384: .4byte 0x3FC9C155
_0824F388: .4byte 0x0E884455
_0824F38C: .4byte 0xBFD4D612
_0824F390: .4byte 0x03EB6F7D
_0824F394: .4byte 0x3FC55555
_0824F398: .4byte 0x55555555
_0824F39C: .4byte 0x3FB3B8C5
_0824F3A0: .4byte 0xB12E9282
_0824F3A4: .4byte 0xBFE6066C
_0824F3A8: .4byte 0x1B8D0159
_0824F3AC: .4byte 0x40002AE5
_0824F3B0: .4byte 0x9C598AC8
_0824F3B4: .4byte 0xC0033A27
_0824F3B8: .4byte 0x1C8A2D4B
_0824F3BC:
	ldr r5, _0824F4F0 @ =0x00000000
	ldr r4, _0824F4EC @ =0x3FF00000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	ldr r2, _0824F4F4 @ =0x3FE00000
	ldr r3, _0824F4F8 @ =0x00000000
	bl __muldf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0824F4FC @ =0x3F023DE1
	ldr r3, _0824F500 @ =0x0DFDF709
	bl __muldf3
	ldr r2, _0824F504 @ =0x3F49EFE0
	ldr r3, _0824F508 @ =0x7501B288
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F50C @ =0xBFA48228
	ldr r3, _0824F510 @ =0xB5688F3B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F514 @ =0x3FC9C155
	ldr r3, _0824F518 @ =0x0E884455
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F51C @ =0xBFD4D612
	ldr r3, _0824F520 @ =0x03EB6F7D
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F524 @ =0x3FC55555
	ldr r3, _0824F528 @ =0x55555555
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _0824F52C @ =0x3FB3B8C5
	ldr r3, _0824F530 @ =0xB12E9282
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F534 @ =0xBFE6066C
	ldr r3, _0824F538 @ =0x1B8D0159
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F53C @ =0x40002AE5
	ldr r3, _0824F540 @ =0x9C598AC8
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F544 @ =0xC0033A27
	ldr r3, _0824F548 @ =0x1C8A2D4B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl fdlibm_sqrt
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __divdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __muldf3
	ldr r2, _0824F54C @ =0x3C91A626
	ldr r3, _0824F550 @ =0x33145C07
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0824F554 @ =0x400921FB
	ldr r1, _0824F558 @ =0x54442D18
_0824F4E4:
	bl __subdf3
_0824F4E8:
	add sp, #0x28
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0824F4EC: .4byte 0x3FF00000
_0824F4F0: .4byte 0x00000000
_0824F4F4: .4byte 0x3FE00000
_0824F4F8: .4byte 0x00000000
_0824F4FC: .4byte 0x3F023DE1
_0824F500: .4byte 0x0DFDF709
_0824F504: .4byte 0x3F49EFE0
_0824F508: .4byte 0x7501B288
_0824F50C: .4byte 0xBFA48228
_0824F510: .4byte 0xB5688F3B
_0824F514: .4byte 0x3FC9C155
_0824F518: .4byte 0x0E884455
_0824F51C: .4byte 0xBFD4D612
_0824F520: .4byte 0x03EB6F7D
_0824F524: .4byte 0x3FC55555
_0824F528: .4byte 0x55555555
_0824F52C: .4byte 0x3FB3B8C5
_0824F530: .4byte 0xB12E9282
_0824F534: .4byte 0xBFE6066C
_0824F538: .4byte 0x1B8D0159
_0824F53C: .4byte 0x40002AE5
_0824F540: .4byte 0x9C598AC8
_0824F544: .4byte 0xC0033A27
_0824F548: .4byte 0x1C8A2D4B
_0824F54C: .4byte 0x3C91A626
_0824F550: .4byte 0x33145C07
_0824F554: .4byte 0x400921FB
_0824F558: .4byte 0x54442D18

	thumb_func_start __ieee754_asin
__ieee754_asin: @ 0x0824F55C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x30
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	mov sb, r0
	ldr r1, _0824F5B0 @ =0x7FFFFFFF
	ands r0, r1
	mov r8, r0
	ldr r0, _0824F5B4 @ =0x3FEFFFFF
	cmp r8, r0
	ble _0824F5E2
	ldr r0, _0824F5B8 @ =0xC0100000
	add r0, r8
	ldr r1, [sp, #4]
	orrs r0, r1
	cmp r0, #0
	bne _0824F5CC
	ldr r2, _0824F5BC @ =0x3FF921FB
	ldr r3, _0824F5C0 @ =0x54442D18
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0824F5C4 @ =0x3C91A626
	ldr r3, _0824F5C8 @ =0x33145C07
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	b _0824FA28
	.align 2, 0
_0824F5B0: .4byte 0x7FFFFFFF
_0824F5B4: .4byte 0x3FEFFFFF
_0824F5B8: .4byte 0xC0100000
_0824F5BC: .4byte 0x3FF921FB
_0824F5C0: .4byte 0x54442D18
_0824F5C4: .4byte 0x3C91A626
_0824F5C8: .4byte 0x33145C07
_0824F5CC:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __divdf3
	b _0824FA28
_0824F5E2:
	ldr r0, _0824F610 @ =0x3FDFFFFF
	cmp r8, r0
	ble _0824F5EA
	b _0824F784
_0824F5EA:
	ldr r0, _0824F614 @ =0x3E3FFFFF
	cmp r8, r0
	bgt _0824F628
	ldr r2, _0824F618 @ =0x7E37E43C
	ldr r3, _0824F61C @ =0x8800759C
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __adddf3
	ldr r2, _0824F620 @ =0x3FF00000
	ldr r3, _0824F624 @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	ble _0824F638
	ldr r0, [sp]
	ldr r1, [sp, #4]
	b _0824FA28
	.align 2, 0
_0824F610: .4byte 0x3FDFFFFF
_0824F614: .4byte 0x3E3FFFFF
_0824F618: .4byte 0x7E37E43C
_0824F61C: .4byte 0x8800759C
_0824F620: .4byte 0x3FF00000
_0824F624: .4byte 0x00000000
_0824F628:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
_0824F638:
	ldr r3, _0824F730 @ =0x0DFDF709
	ldr r2, _0824F72C @ =0x3F023DE1
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F734 @ =0x3F49EFE0
	ldr r3, _0824F738 @ =0x7501B288
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F73C @ =0xBFA48228
	ldr r3, _0824F740 @ =0xB5688F3B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F744 @ =0x3FC9C155
	ldr r3, _0824F748 @ =0x0E884455
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F74C @ =0xBFD4D612
	ldr r3, _0824F750 @ =0x03EB6F7D
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F754 @ =0x3FC55555
	ldr r3, _0824F758 @ =0x55555555
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _0824F75C @ =0x3FB3B8C5
	ldr r3, _0824F760 @ =0xB12E9282
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F764 @ =0xBFE6066C
	ldr r3, _0824F768 @ =0x1B8D0159
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F76C @ =0x40002AE5
	ldr r3, _0824F770 @ =0x9C598AC8
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F774 @ =0xC0033A27
	ldr r3, _0824F778 @ =0x1C8A2D4B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F77C @ =0x3FF00000
	ldr r3, _0824F780 @ =0x00000000
	bl __adddf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __divdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __adddf3
	b _0824FA28
	.align 2, 0
_0824F72C: .4byte 0x3F023DE1
_0824F730: .4byte 0x0DFDF709
_0824F734: .4byte 0x3F49EFE0
_0824F738: .4byte 0x7501B288
_0824F73C: .4byte 0xBFA48228
_0824F740: .4byte 0xB5688F3B
_0824F744: .4byte 0x3FC9C155
_0824F748: .4byte 0x0E884455
_0824F74C: .4byte 0xBFD4D612
_0824F750: .4byte 0x03EB6F7D
_0824F754: .4byte 0x3FC55555
_0824F758: .4byte 0x55555555
_0824F75C: .4byte 0x3FB3B8C5
_0824F760: .4byte 0xB12E9282
_0824F764: .4byte 0xBFE6066C
_0824F768: .4byte 0x1B8D0159
_0824F76C: .4byte 0x40002AE5
_0824F770: .4byte 0x9C598AC8
_0824F774: .4byte 0xC0033A27
_0824F778: .4byte 0x1C8A2D4B
_0824F77C: .4byte 0x3FF00000
_0824F780: .4byte 0x00000000
_0824F784:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl fdlibm_fp_fabs
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r5, _0824F8C8 @ =0x00000000
	ldr r4, _0824F8C4 @ =0x3FF00000
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0824F8CC @ =0x3FE00000
	ldr r3, _0824F8D0 @ =0x00000000
	bl __muldf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0824F8D4 @ =0x3F023DE1
	ldr r3, _0824F8D8 @ =0x0DFDF709
	bl __muldf3
	ldr r2, _0824F8DC @ =0x3F49EFE0
	ldr r3, _0824F8E0 @ =0x7501B288
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F8E4 @ =0xBFA48228
	ldr r3, _0824F8E8 @ =0xB5688F3B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F8EC @ =0x3FC9C155
	ldr r3, _0824F8F0 @ =0x0E884455
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F8F4 @ =0xBFD4D612
	ldr r3, _0824F8F8 @ =0x03EB6F7D
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F8FC @ =0x3FC55555
	ldr r3, _0824F900 @ =0x55555555
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _0824F904 @ =0x3FB3B8C5
	ldr r3, _0824F908 @ =0xB12E9282
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F90C @ =0xBFE6066C
	ldr r3, _0824F910 @ =0x1B8D0159
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F914 @ =0x40002AE5
	ldr r3, _0824F918 @ =0x9C598AC8
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	ldr r2, _0824F91C @ =0xC0033A27
	ldr r3, _0824F920 @ =0x1C8A2D4B
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl fdlibm_sqrt
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _0824F924 @ =0x3FEF3332
	cmp r8, r0
	ble _0824F938
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __divdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	ldr r2, _0824F928 @ =0x3C91A626
	ldr r3, _0824F92C @ =0x33145C07
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0824F930 @ =0x3FF921FB
	ldr r1, _0824F934 @ =0x54442D18
	b _0824F9FA
	.align 2, 0
_0824F8C4: .4byte 0x3FF00000
_0824F8C8: .4byte 0x00000000
_0824F8CC: .4byte 0x3FE00000
_0824F8D0: .4byte 0x00000000
_0824F8D4: .4byte 0x3F023DE1
_0824F8D8: .4byte 0x0DFDF709
_0824F8DC: .4byte 0x3F49EFE0
_0824F8E0: .4byte 0x7501B288
_0824F8E4: .4byte 0xBFA48228
_0824F8E8: .4byte 0xB5688F3B
_0824F8EC: .4byte 0x3FC9C155
_0824F8F0: .4byte 0x0E884455
_0824F8F4: .4byte 0xBFD4D612
_0824F8F8: .4byte 0x03EB6F7D
_0824F8FC: .4byte 0x3FC55555
_0824F900: .4byte 0x55555555
_0824F904: .4byte 0x3FB3B8C5
_0824F908: .4byte 0xB12E9282
_0824F90C: .4byte 0xBFE6066C
_0824F910: .4byte 0x1B8D0159
_0824F914: .4byte 0x40002AE5
_0824F918: .4byte 0x9C598AC8
_0824F91C: .4byte 0xC0033A27
_0824F920: .4byte 0x1C8A2D4B
_0824F924: .4byte 0x3FEF3332
_0824F928: .4byte 0x3C91A626
_0824F92C: .4byte 0x33145C07
_0824F930: .4byte 0x3FF921FB
_0824F934: .4byte 0x54442D18
_0824F938:
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	movs r1, #0
	adds r7, r1, #0
	adds r6, r0, #0
	adds r3, r7, #0
	adds r2, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __divdf3
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __divdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r1, _0824FA18 @ =0x33145C07
	ldr r0, _0824FA14 @ =0x3C91A626
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r7, #0
	adds r2, r6, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r4, _0824FA1C @ =0x3FE921FB
	ldr r5, _0824FA20 @ =0x54442D18
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
_0824F9FA:
	bl __subdf3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, sb
	cmp r0, #0
	bgt _0824FA24
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __negdf2
	b _0824FA28
	.align 2, 0
_0824FA14: .4byte 0x3C91A626
_0824FA18: .4byte 0x33145C07
_0824FA1C: .4byte 0x3FE921FB
_0824FA20: .4byte 0x54442D18
_0824FA24:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
_0824FA28:
	add sp, #0x30
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start __ieee754_fmod
__ieee754_fmod: @ 0x0824FA34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r5, r1, #0
	adds r4, r0, #0
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	adds r6, r0, #0
	adds r7, r1, #0
	adds r1, r3, #0
	adds r0, r2, #0
	mov ip, r1
	movs r2, #0x80
	lsls r2, r2, #0x18
	mov sb, r2
	ands r2, r6
	mov sb, r2
	eors r6, r2
	ldr r2, _0824FA98 @ =0x7FFFFFFF
	mov r8, r2
	ands r2, r0
	mov r8, r2
	mov r0, r8
	orrs r0, r1
	cmp r0, #0
	beq _0824FA80
	ldr r0, _0824FA9C @ =0x7FEFFFFF
	cmp r6, r0
	bgt _0824FA80
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	orrs r0, r2
	ldr r1, _0824FAA0 @ =0x7FF00000
	cmp r0, r1
	bls _0824FAA4
_0824FA80:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __divdf3
	b _0824FCC2
	.align 2, 0
_0824FA98: .4byte 0x7FFFFFFF
_0824FA9C: .4byte 0x7FEFFFFF
_0824FAA0: .4byte 0x7FF00000
_0824FAA4:
	cmp r6, r8
	bgt _0824FABA
	cmp r6, r8
	bge _0824FAAE
	b _0824FCBE
_0824FAAE:
	cmp r7, ip
	bhs _0824FAB4
	b _0824FCBE
_0824FAB4:
	cmp r7, ip
	bne _0824FABA
	b _0824FC92
_0824FABA:
	ldr r0, _0824FAD8 @ =0x000FFFFF
	cmp r6, r0
	bgt _0824FAF8
	cmp r6, #0
	bne _0824FAE0
	ldr r3, _0824FADC @ =0xFFFFFBED
	adds r0, r7, #0
	cmp r7, #0
	ble _0824FAFE
_0824FACC:
	subs r3, #1
	lsls r0, r0, #1
	cmp r0, #0
	bgt _0824FACC
	b _0824FAFE
	.align 2, 0
_0824FAD8: .4byte 0x000FFFFF
_0824FADC: .4byte 0xFFFFFBED
_0824FAE0:
	ldr r3, _0824FAF4 @ =0xFFFFFC02
	lsls r0, r6, #0xb
	cmp r0, #0
	ble _0824FAFE
_0824FAE8:
	subs r3, #1
	lsls r0, r0, #1
	cmp r0, #0
	bgt _0824FAE8
	b _0824FAFE
	.align 2, 0
_0824FAF4: .4byte 0xFFFFFC02
_0824FAF8:
	asrs r0, r6, #0x14
	ldr r1, _0824FB1C @ =0xFFFFFC01
	adds r3, r0, r1
_0824FAFE:
	ldr r0, _0824FB20 @ =0x000FFFFF
	cmp r8, r0
	bgt _0824FB40
	mov r2, r8
	cmp r2, #0
	bne _0824FB28
	ldr r4, _0824FB24 @ =0xFFFFFBED
	mov r0, ip
	cmp r0, #0
	ble _0824FB48
_0824FB12:
	subs r4, #1
	lsls r0, r0, #1
	cmp r0, #0
	bgt _0824FB12
	b _0824FB48
	.align 2, 0
_0824FB1C: .4byte 0xFFFFFC01
_0824FB20: .4byte 0x000FFFFF
_0824FB24: .4byte 0xFFFFFBED
_0824FB28:
	ldr r4, _0824FB3C @ =0xFFFFFC02
	mov r1, r8
	lsls r0, r1, #0xb
	cmp r0, #0
	ble _0824FB48
_0824FB32:
	subs r4, #1
	lsls r0, r0, #1
	cmp r0, #0
	bgt _0824FB32
	b _0824FB48
	.align 2, 0
_0824FB3C: .4byte 0xFFFFFC02
_0824FB40:
	mov r2, r8
	asrs r0, r2, #0x14
	ldr r1, _0824FB58 @ =0xFFFFFC01
	adds r4, r0, r1
_0824FB48:
	ldr r0, _0824FB5C @ =0xFFFFFC02
	cmp r3, r0
	blt _0824FB64
	ldr r0, _0824FB60 @ =0x000FFFFF
	ands r6, r0
	adds r0, #1
	orrs r6, r0
	b _0824FB84
	.align 2, 0
_0824FB58: .4byte 0xFFFFFC01
_0824FB5C: .4byte 0xFFFFFC02
_0824FB60: .4byte 0x000FFFFF
_0824FB64:
	subs r2, r0, r3
	cmp r2, #0x1f
	bgt _0824FB7A
	lsls r6, r2
	movs r1, #0x20
	subs r1, r1, r2
	adds r0, r7, #0
	lsrs r0, r1
	orrs r6, r0
	lsls r7, r2
	b _0824FB84
_0824FB7A:
	adds r0, r2, #0
	subs r0, #0x20
	adds r6, r7, #0
	lsls r6, r0
	movs r7, #0
_0824FB84:
	ldr r0, _0824FB98 @ =0xFFFFFC02
	cmp r4, r0
	blt _0824FBA0
	ldr r0, _0824FB9C @ =0x000FFFFF
	mov r2, r8
	ands r2, r0
	adds r0, #1
	orrs r2, r0
	mov r8, r2
	b _0824FBD0
	.align 2, 0
_0824FB98: .4byte 0xFFFFFC02
_0824FB9C: .4byte 0x000FFFFF
_0824FBA0:
	subs r2, r0, r4
	cmp r2, #0x1f
	bgt _0824FBC2
	mov r0, r8
	lsls r0, r2
	mov r8, r0
	movs r1, #0x20
	subs r1, r1, r2
	mov r0, ip
	lsrs r0, r1
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	mov r0, ip
	lsls r0, r2
	mov ip, r0
	b _0824FBD0
_0824FBC2:
	adds r0, r2, #0
	subs r0, #0x20
	mov r1, ip
	lsls r1, r0
	mov r8, r1
	movs r2, #0
	mov ip, r2
_0824FBD0:
	subs r2, r3, r4
	b _0824FC00
_0824FBD4:
	mov r0, r8
	subs r1, r6, r0
	mov r0, ip
	subs r3, r7, r0
	cmp r7, ip
	bhs _0824FBE2
	subs r1, #1
_0824FBE2:
	cmp r1, #0
	bge _0824FBF0
	lsls r1, r6, #1
	lsrs r0, r7, #0x1f
	adds r6, r1, r0
	lsls r7, r7, #1
	b _0824FC00
_0824FBF0:
	adds r0, r1, #0
	orrs r0, r3
	cmp r0, #0
	beq _0824FC92
	lsls r1, r1, #1
	lsrs r0, r3, #0x1f
	adds r6, r1, r0
	lsls r7, r3, #1
_0824FC00:
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bne _0824FBD4
	mov r2, r8
	subs r1, r6, r2
	mov r0, ip
	subs r3, r7, r0
	cmp r7, ip
	bhs _0824FC16
	subs r1, #1
_0824FC16:
	cmp r1, #0
	blt _0824FC1E
	adds r6, r1, #0
	adds r7, r3, #0
_0824FC1E:
	adds r0, r6, #0
	orrs r0, r7
	cmp r0, #0
	beq _0824FC92
	ldr r2, _0824FC5C @ =0x000FFFFF
	cmp r6, r2
	bgt _0824FC3A
_0824FC2C:
	lsls r1, r6, #1
	lsrs r0, r7, #0x1f
	adds r6, r1, r0
	lsls r7, r7, #1
	subs r4, #1
	cmp r6, r2
	ble _0824FC2C
_0824FC3A:
	ldr r0, _0824FC60 @ =0xFFFFFC02
	cmp r4, r0
	blt _0824FC6C
	ldr r0, _0824FC64 @ =0xFFF00000
	adds r6, r6, r0
	ldr r1, _0824FC68 @ =0x000003FF
	adds r0, r4, r1
	lsls r0, r0, #0x14
	orrs r6, r0
	mov r2, sb
	orrs r2, r6
	str r2, [sp]
	str r7, [sp, #4]
	ldr r4, [sp]
	ldr r5, [sp, #4]
	b _0824FCBE
	.align 2, 0
_0824FC5C: .4byte 0x000FFFFF
_0824FC60: .4byte 0xFFFFFC02
_0824FC64: .4byte 0xFFF00000
_0824FC68: .4byte 0x000003FF
_0824FC6C:
	subs r2, r0, r4
	cmp r2, #0x14
	bgt _0824FC82
	lsrs r7, r2
	movs r1, #0x20
	subs r1, r1, r2
	adds r0, r6, #0
	lsls r0, r1
	orrs r7, r0
	asrs r6, r2
	b _0824FCB2
_0824FC82:
	cmp r2, #0x1f
	bgt _0824FCA8
	movs r0, #0x20
	subs r0, r0, r2
	lsls r6, r0
	lsrs r7, r2
	orrs r7, r6
	b _0824FCB0
_0824FC92:
	ldr r0, _0824FCA4 @ =0x085A8D58
	mov r2, sb
	lsrs r1, r2, #0x1f
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	b _0824FCC2
	.align 2, 0
_0824FCA4: .4byte 0x085A8D58
_0824FCA8:
	adds r0, r2, #0
	subs r0, #0x20
	adds r7, r6, #0
	asrs r7, r0
_0824FCB0:
	mov r6, sb
_0824FCB2:
	mov r0, sb
	orrs r0, r6
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	ldr r4, [sp, #8]
	ldr r5, [sp, #0xc]
_0824FCBE:
	adds r1, r5, #0
	adds r0, r4, #0
_0824FCC2:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}

	thumb_func_start __ieee754_rem_pio2
__ieee754_rem_pio2: @ 0x0824FCCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r5, r1, #0
	adds r4, r0, #0
	mov r8, r2
	adds r2, r5, #0
	adds r1, r4, #0
	str r1, [sp, #0x38]
	ldr r0, _0824FD08 @ =0x7FFFFFFF
	adds r3, r1, #0
	ands r3, r0
	mov sb, r3
	ldr r0, _0824FD0C @ =0x3FE921FB
	cmp sb, r0
	bgt _0824FD18
	mov r0, r8
	str r4, [r0]
	str r5, [r0, #4]
	ldr r0, _0824FD10 @ =0x00000000
	ldr r1, _0824FD14 @ =0x00000000
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	movs r0, #0
	b _08250124
	.align 2, 0
_0824FD08: .4byte 0x7FFFFFFF
_0824FD0C: .4byte 0x3FE921FB
_0824FD10: .4byte 0x00000000
_0824FD14: .4byte 0x00000000
_0824FD18:
	ldr r0, _0824FD44 @ =0x4002D97B
	cmp sb, r0
	ble _0824FD20
	b _0824FE34
_0824FD20:
	cmp r1, #0
	ble _0824FDAC
	ldr r2, _0824FD48 @ =0x3FF921FB
	ldr r3, _0824FD4C @ =0x54400000
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0824FD50 @ =0x3FF921FB
	cmp sb, r0
	beq _0824FD5C
	ldr r4, _0824FD54 @ =0x3DD0B461
	ldr r5, _0824FD58 @ =0x1A626331
	adds r1, r7, #0
	adds r0, r6, #0
	b _0824FD70
	.align 2, 0
_0824FD44: .4byte 0x4002D97B
_0824FD48: .4byte 0x3FF921FB
_0824FD4C: .4byte 0x54400000
_0824FD50: .4byte 0x3FF921FB
_0824FD54: .4byte 0x3DD0B461
_0824FD58: .4byte 0x1A626331
_0824FD5C:
	ldr r3, _0824FDA0 @ =0x1A600000
	ldr r2, _0824FD9C @ =0x3DD0B461
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0824FDA4 @ =0x3BA3198A
	ldr r5, _0824FDA8 @ =0x2E037073
_0824FD70:
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	mov r0, r8
	str r2, [r0]
	str r3, [r0, #4]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	movs r0, #1
	b _08250124
	.align 2, 0
_0824FD9C: .4byte 0x3DD0B461
_0824FDA0: .4byte 0x1A600000
_0824FDA4: .4byte 0x3BA3198A
_0824FDA8: .4byte 0x2E037073
_0824FDAC:
	ldr r3, _0824FDD0 @ =0x54400000
	ldr r2, _0824FDCC @ =0x3FF921FB
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0824FDD4 @ =0x3FF921FB
	cmp sb, r0
	beq _0824FDE0
	ldr r4, _0824FDD8 @ =0x3DD0B461
	ldr r5, _0824FDDC @ =0x1A626331
	adds r1, r7, #0
	adds r0, r6, #0
	b _0824FDF4
	.align 2, 0
_0824FDCC: .4byte 0x3FF921FB
_0824FDD0: .4byte 0x54400000
_0824FDD4: .4byte 0x3FF921FB
_0824FDD8: .4byte 0x3DD0B461
_0824FDDC: .4byte 0x1A626331
_0824FDE0:
	ldr r3, _0824FE28 @ =0x1A600000
	ldr r2, _0824FE24 @ =0x3DD0B461
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0824FE2C @ =0x3BA3198A
	ldr r5, _0824FE30 @ =0x2E037073
_0824FDF4:
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	mov r0, r8
	str r2, [r0]
	str r3, [r0, #4]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	b _08250124
	.align 2, 0
_0824FE24: .4byte 0x3DD0B461
_0824FE28: .4byte 0x1A600000
_0824FE2C: .4byte 0x3BA3198A
_0824FE30: .4byte 0x2E037073
_0824FE34:
	ldr r0, _0824FFF0 @ =0x413921FB
	cmp sb, r0
	ble _0824FE3C
	b _08250040
_0824FE3C:
	adds r1, r5, #0
	adds r0, r4, #0
	bl fdlibm_fp_fabs
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0824FFF4 @ =0x3FE45F30
	ldr r3, _0824FFF8 @ =0x6DC9C883
	bl __muldf3
	ldr r2, _0824FFFC @ =0x3FE00000
	ldr r3, _08250000 @ =0x00000000
	bl __adddf3
	bl __fixdfsi
	mov sl, r0
	bl __floatsidf
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldr r2, _08250004 @ =0x3FF921FB
	ldr r3, _08250008 @ =0x54400000
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r2, _0825000C @ =0x3DD0B461
	ldr r3, _08250010 @ =0x1A626331
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __muldf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	mov r3, sl
	cmp r3, #0x1f
	bgt _0824FEA6
	ldr r0, _08250014 @ =0x085A8E70
	mov r1, sl
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	cmp sb, r0
	beq _0824FEA6
	b _0824FF9E
_0824FEA6:
	mov r3, sb
	asrs r3, r3, #0x14
	mov sb, r3
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	mov r2, r8
	str r0, [r2]
	str r1, [r2, #4]
	lsrs r0, r0, #0x14
	ldr r3, _08250018 @ =0x000007FF
	ands r0, r3
	mov r1, sb
	subs r4, r1, r0
	cmp r4, #0x10
	bgt _0824FECE
	b _0824FFB0
_0824FECE:
	ldr r6, [sp, #0x28]
	ldr r7, [sp, #0x2c]
	ldr r2, _0825001C @ =0x3DD0B461
	ldr r3, _08250020 @ =0x1A600000
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __muldf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r2, _08250024 @ =0x3BA3198A
	ldr r3, _08250028 @ =0x2E037073
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl __subdf3
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	mov r2, r8
	str r0, [r2]
	str r1, [r2, #4]
	lsrs r0, r0, #0x14
	ldr r3, _08250018 @ =0x000007FF
	ands r0, r3
	mov r1, sb
	subs r4, r1, r0
	cmp r4, #0x31
	ble _0824FFB0
	ldr r6, [sp, #0x28]
	ldr r7, [sp, #0x2c]
	ldr r2, _0825002C @ =0x3BA3198A
	ldr r3, _08250030 @ =0x2E000000
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __muldf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r2, _08250034 @ =0x397B839A
	ldr r3, _08250038 @ =0x252049C1
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl __subdf3
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
_0824FF9E:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	mov r2, r8
	str r0, [r2]
	str r1, [r2, #4]
_0824FFB0:
	mov r3, r8
	ldr r6, [r3]
	ldr r7, [r3, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __subdf3
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	mov r0, r8
	str r4, [r0, #8]
	str r5, [r0, #0xc]
	ldr r1, [sp, #0x38]
	cmp r1, #0
	bge _0825003C
	adds r1, r7, #0
	adds r0, r6, #0
	bl __negdf2
	mov r2, r8
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r0, r4, #0
	b _08250116
	.align 2, 0
_0824FFF0: .4byte 0x413921FB
_0824FFF4: .4byte 0x3FE45F30
_0824FFF8: .4byte 0x6DC9C883
_0824FFFC: .4byte 0x3FE00000
_08250000: .4byte 0x00000000
_08250004: .4byte 0x3FF921FB
_08250008: .4byte 0x54400000
_0825000C: .4byte 0x3DD0B461
_08250010: .4byte 0x1A626331
_08250014: .4byte 0x085A8E70
_08250018: .4byte 0x000007FF
_0825001C: .4byte 0x3DD0B461
_08250020: .4byte 0x1A600000
_08250024: .4byte 0x3BA3198A
_08250028: .4byte 0x2E037073
_0825002C: .4byte 0x3BA3198A
_08250030: .4byte 0x2E000000
_08250034: .4byte 0x397B839A
_08250038: .4byte 0x252049C1
_0825003C:
	mov r0, sl
	b _08250124
_08250040:
	ldr r0, _08250064 @ =0x7FEFFFFF
	cmp sb, r0
	ble _08250068
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	movs r0, #0
	b _08250124
	.align 2, 0
_08250064: .4byte 0x7FEFFFFF
_08250068:
	adds r1, r5, #0
	mov r3, sb
	asrs r2, r3, #0x14
	ldr r3, _082500BC @ =0xFFFFFBEA
	adds r3, r3, r2
	mov sl, r3
	lsls r2, r3, #0x14
	mov r3, sb
	subs r0, r3, r2
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _082500C0 @ =0x085A8D68
	mov sb, r0
	add r5, sp, #8
	movs r4, #1
_08250086:
	adds r1, r7, #0
	adds r0, r6, #0
	bl __fixdfsi
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	stm r5!, {r2, r3}
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	ldr r2, _082500C4 @ =0x41700000
	ldr r3, _082500C8 @ =0x00000000
	bl __muldf3
	adds r7, r1, #0
	adds r6, r0, #0
	subs r4, #1
	cmp r4, #0
	bge _08250086
	str r6, [sp, #0x18]
	str r7, [sp, #0x1c]
	movs r5, #3
	b _082500CE
	.align 2, 0
_082500BC: .4byte 0xFFFFFBEA
_082500C0: .4byte 0x085A8D68
_082500C4: .4byte 0x41700000
_082500C8: .4byte 0x00000000
_082500CC:
	adds r5, r4, #0
_082500CE:
	subs r4, r5, #1
	lsls r0, r4, #3
	add r0, sp
	adds r0, #8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r3, _08250134 @ =0x00000000
	ldr r2, _08250130 @ =0x00000000
	bl __eqdf2
	cmp r0, #0
	beq _082500CC
	movs r0, #2
	str r0, [sp]
	mov r1, sb
	str r1, [sp, #4]
	add r0, sp, #8
	mov r1, r8
	mov r2, sl
	adds r3, r5, #0
	bl __kernel_rem_pio2
	mov sl, r0
	ldr r2, [sp, #0x38]
	cmp r2, #0
	bge _08250124
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	bl __negdf2
	mov r2, r8
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
_08250116:
	bl __negdf2
	mov r3, r8
	str r0, [r3, #8]
	str r1, [r3, #0xc]
	mov r1, sl
	rsbs r0, r1, #0
_08250124:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08250130: .4byte 0x00000000
_08250134: .4byte 0x00000000

	thumb_func_start fdlibm_sqrt
fdlibm_sqrt: @ 0x08250138
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r1, #0
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0x18
	mov sl, r0
	adds r3, r6, #0
	adds r2, r5, #0
	adds r4, r2, #0
	adds r7, r3, #0
	ldr r1, _08250174 @ =0x7FF00000
	adds r0, r4, #0
	ands r0, r1
	cmp r0, r1
	bne _08250178
	adds r1, r6, #0
	adds r0, r5, #0
	bl __muldf3
	adds r3, r6, #0
	adds r2, r5, #0
	bl __adddf3
	b _0825032C
	.align 2, 0
_08250174: .4byte 0x7FF00000
_08250178:
	cmp r2, #0
	bgt _082501A8
	adds r0, r4, #0
	mov r1, sl
	bics r0, r1
	orrs r0, r7
	cmp r0, #0
	bne _0825018E
	adds r1, r6, #0
	adds r0, r5, #0
	b _0825032C
_0825018E:
	cmp r2, #0
	bge _082501A8
	adds r1, r6, #0
	adds r0, r5, #0
	adds r3, r6, #0
	adds r2, r5, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __divdf3
	b _0825032C
_082501A8:
	asrs r5, r4, #0x14
	cmp r5, #0
	bne _082501E8
	cmp r4, #0
	bne _082501BE
_082501B2:
	subs r5, #0x15
	lsrs r0, r7, #0xb
	orrs r4, r0
	lsls r7, r7, #0x15
	cmp r4, #0
	beq _082501B2
_082501BE:
	movs r2, #0
	movs r1, #0x80
	lsls r1, r1, #0xd
	adds r0, r4, #0
	ands r0, r1
	adds r3, r5, #1
	cmp r0, #0
	bne _082501DA
_082501CE:
	lsls r4, r4, #1
	adds r2, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _082501CE
_082501DA:
	subs r5, r3, r2
	movs r1, #0x20
	subs r1, r1, r2
	adds r0, r7, #0
	lsrs r0, r1
	orrs r4, r0
	lsls r7, r2
_082501E8:
	ldr r0, _082502C8 @ =0xFFFFFC01
	adds r5, r5, r0
	ldr r0, _082502CC @ =0x000FFFFF
	ands r4, r0
	adds r0, #1
	orrs r4, r0
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _0825020A
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	adds r4, r4, r0
	lsls r7, r7, #1
_0825020A:
	asrs r5, r5, #1
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	adds r4, r4, r0
	lsls r7, r7, #1
	movs r0, #0
	mov ip, r0
	movs r6, #0
	mov r8, r6
	mov sb, r6
	movs r3, #0x80
	lsls r3, r3, #0xe
_08250228:
	adds r1, r6, r3
	cmp r1, r4
	bgt _08250234
	adds r6, r1, r3
	subs r4, r4, r1
	add sb, r3
_08250234:
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	adds r4, r4, r0
	lsls r7, r7, #1
	lsrs r3, r3, #1
	cmp r3, #0
	bne _08250228
	mov r3, sl
	lsls r5, r5, #0x14
	str r5, [sp, #8]
	cmp r1, #0
	beq _0825029C
_08250252:
	mov r5, ip
	adds r2, r5, r3
	adds r1, r6, #0
	cmp r1, r4
	blt _08250264
	cmp r1, r4
	bne _08250288
	cmp r2, r7
	bhi _08250288
_08250264:
	adds r0, r2, r3
	mov ip, r0
	adds r0, r2, #0
	mov r5, sl
	ands r0, r5
	cmp r0, sl
	bne _0825027C
	mov r0, ip
	ands r0, r5
	cmp r0, #0
	bne _0825027C
	adds r6, r1, #1
_0825027C:
	subs r4, r4, r1
	cmp r7, r2
	bhs _08250284
	subs r4, #1
_08250284:
	subs r7, r7, r2
	add r8, r3
_08250288:
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	adds r4, r4, r0
	lsls r7, r7, #1
	lsrs r3, r3, #1
	cmp r3, #0
	bne _08250252
_0825029C:
	orrs r4, r7
	cmp r4, #0
	beq _08250302
	ldr r4, _082502D0 @ =0x3FF00000
	ldr r5, _082502D4 @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __gedf2
	cmp r0, #0
	blt _08250302
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	bne _082502D8
	movs r5, #0
	mov r8, r5
	movs r0, #1
	add sb, r0
	b _08250302
	.align 2, 0
_082502C8: .4byte 0xFFFFFC01
_082502CC: .4byte 0x000FFFFF
_082502D0: .4byte 0x3FF00000
_082502D4: .4byte 0x00000000
_082502D8:
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __gtdf2
	cmp r0, #0
	ble _082502FA
	movs r0, #2
	rsbs r0, r0, #0
	cmp r8, r0
	bne _082502F4
	movs r1, #1
	add sb, r1
_082502F4:
	movs r5, #2
	add r8, r5
	b _08250302
_082502FA:
	movs r0, #1
	mov r1, r8
	ands r0, r1
	add r8, r0
_08250302:
	mov r5, sb
	asrs r0, r5, #1
	ldr r1, _08250338 @ =0x3FE00000
	adds r4, r0, r1
	mov r5, r8
	lsrs r7, r5, #1
	movs r0, #1
	mov r1, sb
	ands r1, r0
	cmp r1, #0
	beq _0825031C
	mov r5, sl
	orrs r7, r5
_0825031C:
	ldr r0, [sp, #8]
	adds r4, r4, r0
	str r4, [sp]
	str r7, [sp, #4]
	ldr r4, [sp]
	ldr r5, [sp, #4]
	adds r1, r5, #0
	adds r0, r4, #0
_0825032C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08250338: .4byte 0x3FE00000

	thumb_func_start __kernel_cos
__kernel_cos: @ 0x0825033C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _0825036C @ =0x7FFFFFFF
	ldr r1, [sp]
	ands r1, r0
	mov r8, r1
	ldr r0, _08250370 @ =0x3E3FFFFF
	cmp r8, r0
	bgt _0825037C
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __fixdfsi
	cmp r0, #0
	bne _0825037C
	ldr r0, _08250374 @ =0x3FF00000
	ldr r1, _08250378 @ =0x00000000
	b _0825051A
	.align 2, 0
_0825036C: .4byte 0x7FFFFFFF
_08250370: .4byte 0x3E3FFFFF
_08250374: .4byte 0x3FF00000
_08250378: .4byte 0x00000000
_0825037C:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _08250454 @ =0xBE8838D4
	ldr r2, _08250450 @ =0xBDA8FAE9
	bl __muldf3
	ldr r2, _08250458 @ =0x3E21EE9E
	ldr r3, _0825045C @ =0xBDB4B1C4
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _08250460 @ =0xBE927E4F
	ldr r3, _08250464 @ =0x809C52AD
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _08250468 @ =0x3EFA01A0
	ldr r3, _0825046C @ =0x19CB1590
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _08250470 @ =0xBF56C16C
	ldr r3, _08250474 @ =0x16C15177
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _08250478 @ =0x3FA55555
	ldr r3, _0825047C @ =0x5555554C
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, _08250480 @ =0x3FD33332
	cmp r8, r0
	bgt _08250494
	ldr r2, _08250484 @ =0x3FE00000
	ldr r3, _08250488 @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0825048C @ =0x3FF00000
	ldr r1, _08250490 @ =0x00000000
	b _08250516
	.align 2, 0
_08250450: .4byte 0xBDA8FAE9
_08250454: .4byte 0xBE8838D4
_08250458: .4byte 0x3E21EE9E
_0825045C: .4byte 0xBDB4B1C4
_08250460: .4byte 0xBE927E4F
_08250464: .4byte 0x809C52AD
_08250468: .4byte 0x3EFA01A0
_0825046C: .4byte 0x19CB1590
_08250470: .4byte 0xBF56C16C
_08250474: .4byte 0x16C15177
_08250478: .4byte 0x3FA55555
_0825047C: .4byte 0x5555554C
_08250480: .4byte 0x3FD33332
_08250484: .4byte 0x3FE00000
_08250488: .4byte 0x00000000
_0825048C: .4byte 0x3FF00000
_08250490: .4byte 0x00000000
_08250494:
	ldr r0, _082504A0 @ =0x3FE90000
	cmp r8, r0
	ble _082504AC
	ldr r6, _082504A4 @ =0x3FD20000
	ldr r7, _082504A8 @ =0x00000000
	b _082504B2
	.align 2, 0
_082504A0: .4byte 0x3FE90000
_082504A4: .4byte 0x3FD20000
_082504A8: .4byte 0x00000000
_082504AC:
	ldr r6, _08250524 @ =0xFFE00000
	add r6, r8
	movs r7, #0
_082504B2:
	ldr r2, _08250528 @ =0x3FE00000
	ldr r3, _0825052C @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r7, #0
	adds r2, r6, #0
	bl __subdf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, _08250530 @ =0x3FF00000
	ldr r1, _08250534 @ =0x00000000
	adds r3, r7, #0
	adds r2, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
_08250516:
	bl __subdf3
_0825051A:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08250524: .4byte 0xFFE00000
_08250528: .4byte 0x3FE00000
_0825052C: .4byte 0x00000000
_08250530: .4byte 0x3FF00000
_08250534: .4byte 0x00000000

	thumb_func_start __kernel_rem_pio2
__kernel_rem_pio2: @ 0x08250538
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _082505A4 @ =0xFFFFFD9C
	add sp, r4
	str r0, [sp, #0x230]
	str r1, [sp, #0x234]
	adds r4, r2, #0
	ldr r1, _082505A8 @ =0x085A8F88
	ldr r2, [sp, #0x284]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x23c]
	str r0, [sp, #0x240]
	subs r3, #1
	mov sl, r3
	subs r0, r4, #3
	movs r1, #0x18
	bl __divsi3
	str r0, [sp, #0x238]
	cmp r0, #0
	bge _08250570
	movs r3, #0
	str r3, [sp, #0x238]
_08250570:
	ldr r1, [sp, #0x238]
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r4, r4, r0
	str r4, [sp, #0x248]
	ldr r0, [sp, #0x238]
	mov r1, sl
	subs r4, r0, r1
	ldr r1, [sp, #0x23c]
	add r1, sl
	cmp r1, #0
	blt _082505C0
	lsls r0, r4, #2
	ldr r2, [sp, #0x288]
	adds r5, r0, r2
	add r7, sp, #0x50
	adds r6, r1, #1
_08250596:
	cmp r4, #0
	blt _082505AC
	ldr r0, [r5]
	bl __floatsidf
	b _082505B0
	.align 2, 0
_082505A4: .4byte 0xFFFFFD9C
_082505A8: .4byte 0x085A8F88
_082505AC:
	ldr r1, _08250710 @ =0x00000000
	ldr r0, _0825070C @ =0x00000000
_082505B0:
	str r0, [r7]
	str r1, [r7, #4]
	adds r7, #8
	subs r6, #1
	adds r5, #4
	adds r4, #1
	cmp r6, #0
	bne _08250596
_082505C0:
	movs r6, #0
	ldr r3, [sp, #0x240]
	cmp r6, r3
	bgt _08250620
_082505C8:
	movs r4, #0
	ldr r1, _08250710 @ =0x00000000
	ldr r0, _0825070C @ =0x00000000
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	lsls r1, r6, #3
	mov r8, r1
	adds r2, r6, #1
	mov sb, r2
	cmp r4, sl
	bgt _0825060C
	add r5, sp, #0x50
	ldr r7, [sp, #0x230]
_082505E2:
	mov r3, sl
	adds r2, r3, r6
	subs r2, r2, r4
	lsls r2, r2, #3
	adds r2, r5, r2
	ldm r7!, {r0, r1}
	ldr r3, [r2, #4]
	ldr r2, [r2]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	adds r4, #1
	cmp r4, sl
	ble _082505E2
_0825060C:
	add r0, sp, #0x190
	add r0, r8
	ldr r1, [sp, #0x258]
	ldr r2, [sp, #0x25c]
	str r1, [r0]
	str r2, [r0, #4]
	mov r6, sb
	ldr r2, [sp, #0x240]
	cmp r6, r2
	ble _082505C8
_08250620:
	ldr r3, [sp, #0x240]
	mov sb, r3
_08250624:
	mov r4, sb
	add r0, sp, #0x190
	lsls r1, r4, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [sp, #0x250]
	str r3, [sp, #0x254]
	cmp r4, #0
	ble _08250688
	mov r6, sp
	add r0, sp, #0x188
	adds r5, r0, r1
_0825063E:
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	ldr r2, _08250714 @ =0x3E700000
	ldr r3, _08250718 @ =0x00000000
	bl __muldf3
	bl __fixdfsi
	bl __floatsidf
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	ldr r2, _0825071C @ =0x41700000
	ldr r3, _08250720 @ =0x00000000
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __subdf3
	bl __fixdfsi
	stm r6!, {r0}
	subs r4, #1
	ldr r0, [r5]
	ldr r1, [r5, #4]
	ldr r2, [sp, #0x258]
	ldr r3, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
	subs r5, #8
	cmp r4, #0
	bgt _0825063E
_08250688:
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	ldr r2, [sp, #0x248]
	bl scalbn
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
	ldr r2, _08250724 @ =0x3FC00000
	ldr r3, _08250728 @ =0x00000000
	bl __muldf3
	bl fdlibm_floor
	ldr r2, _0825072C @ =0x40200000
	ldr r3, _08250730 @ =0x00000000
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __subdf3
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
	bl __fixdfsi
	str r0, [sp, #0x244]
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __subdf3
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
	movs r3, #0
	str r3, [sp, #0x24c]
	ldr r0, [sp, #0x248]
	cmp r0, #0
	ble _08250734
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #2
	mov r1, sp
	adds r2, r1, r0
	movs r0, #0x18
	ldr r3, [sp, #0x248]
	subs r0, r0, r3
	ldr r1, [r2]
	adds r6, r1, #0
	asrs r6, r0
	ldr r3, [sp, #0x244]
	adds r3, r3, r6
	str r3, [sp, #0x244]
	lsls r6, r0
	subs r1, r1, r6
	str r1, [r2]
	movs r0, #0x17
	ldr r2, [sp, #0x248]
	subs r0, r0, r2
	asrs r1, r0
	str r1, [sp, #0x24c]
	b _0825075C
	.align 2, 0
_0825070C: .4byte 0x00000000
_08250710: .4byte 0x00000000
_08250714: .4byte 0x3E700000
_08250718: .4byte 0x00000000
_0825071C: .4byte 0x41700000
_08250720: .4byte 0x00000000
_08250724: .4byte 0x3FC00000
_08250728: .4byte 0x00000000
_0825072C: .4byte 0x40200000
_08250730: .4byte 0x00000000
_08250734:
	ldr r3, [sp, #0x248]
	cmp r3, #0
	bne _08250748
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	asrs r0, r0, #0x17
	b _0825075A
_08250748:
	ldr r3, _08250790 @ =0x00000000
	ldr r2, _0825078C @ =0x3FE00000
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __gedf2
	cmp r0, #0
	blt _0825075C
	movs r0, #2
_0825075A:
	str r0, [sp, #0x24c]
_0825075C:
	ldr r1, [sp, #0x24c]
	cmp r1, #0
	ble _08250812
	ldr r2, [sp, #0x244]
	adds r2, #1
	str r2, [sp, #0x244]
	movs r7, #0
	mov r3, sb
	cmp r3, #0
	ble _082507A4
	movs r3, #0x80
	lsls r3, r3, #0x11
	ldr r2, _08250794 @ =0x00FFFFFF
	mov r1, sp
	mov r6, sb
_0825077A:
	ldr r4, [r1]
	cmp r7, #0
	bne _08250798
	cmp r4, #0
	beq _0825079C
	movs r7, #1
	subs r0, r3, r4
	b _0825079A
	.align 2, 0
_0825078C: .4byte 0x3FE00000
_08250790: .4byte 0x00000000
_08250794: .4byte 0x00FFFFFF
_08250798:
	subs r0, r2, r4
_0825079A:
	str r0, [r1]
_0825079C:
	adds r1, #4
	subs r6, #1
	cmp r6, #0
	bne _0825077A
_082507A4:
	ldr r0, [sp, #0x248]
	cmp r0, #0
	ble _082507DA
	cmp r0, #1
	beq _082507B4
	cmp r0, #2
	beq _082507C8
	b _082507DA
_082507B4:
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #2
	mov r1, sp
	adds r2, r1, r0
	ldr r0, [r2]
	ldr r1, _082507C4 @ =0x007FFFFF
	b _082507D6
	.align 2, 0
_082507C4: .4byte 0x007FFFFF
_082507C8:
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #2
	mov r3, sp
	adds r2, r3, r0
	ldr r0, [r2]
	ldr r1, _082508F0 @ =0x003FFFFF
_082507D6:
	ands r0, r1
	str r0, [r2]
_082507DA:
	ldr r0, [sp, #0x24c]
	cmp r0, #2
	bne _08250812
	ldr r4, _082508F4 @ =0x3FF00000
	ldr r5, _082508F8 @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x250]
	ldr r3, [sp, #0x254]
	bl __subdf3
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
	cmp r7, #0
	beq _08250812
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x248]
	bl scalbn
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __subdf3
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
_08250812:
	ldr r2, _082508FC @ =0x00000000
	ldr r3, _08250900 @ =0x00000000
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __eqdf2
	cmp r0, #0
	bne _08250904
	movs r4, #0
	mov r6, sb
	subs r6, #1
	ldr r1, [sp, #0x240]
	cmp r6, r1
	blt _08250842
	lsls r0, r6, #2
	mov r2, sp
	adds r1, r0, r2
_08250834:
	ldr r0, [r1]
	orrs r4, r0
	subs r1, #4
	subs r6, #1
	ldr r3, [sp, #0x240]
	cmp r6, r3
	bge _08250834
_08250842:
	cmp r4, #0
	bne _08250904
	movs r4, #1
	ldr r0, [sp, #0x240]
	subs r0, #1
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	mov r1, sb
	adds r1, #1
	cmp r0, #0
	bne _0825086C
	ldr r2, [sp, #0x240]
	lsls r0, r2, #2
	add r0, sp
	subs r2, r0, #4
_08250862:
	subs r2, #4
	adds r4, #1
	ldr r0, [r2]
	cmp r0, #0
	beq _08250862
_0825086C:
	adds r6, r1, #0
	mov r3, sb
	adds r7, r3, r4
	cmp r6, r7
	bgt _082508EC
	mov r0, sp
	adds r0, #0x50
	str r0, [sp, #0x260]
_0825087C:
	mov r1, sl
	adds r0, r1, r6
	lsls r0, r0, #3
	ldr r2, [sp, #0x260]
	adds r4, r2, r0
	ldr r3, [sp, #0x238]
	adds r0, r3, r6
	lsls r0, r0, #2
	ldr r1, [sp, #0x288]
	adds r0, r0, r1
	ldr r0, [r0]
	bl __floatsidf
	str r0, [r4]
	str r1, [r4, #4]
	ldr r2, _082508FC @ =0x00000000
	ldr r3, _08250900 @ =0x00000000
	str r2, [sp, #0x258]
	str r3, [sp, #0x25c]
	lsls r3, r6, #3
	mov r8, r3
	adds r6, #1
	mov sb, r6
	mov r0, sl
	cmp r0, #0
	blt _082508DA
	adds r6, r4, #0
	ldr r5, [sp, #0x230]
	mov r4, sl
	adds r4, #1
_082508B8:
	ldm r5!, {r0, r1}
	ldr r2, [r6]
	ldr r3, [r6, #4]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	subs r6, #8
	subs r4, #1
	cmp r4, #0
	bne _082508B8
_082508DA:
	add r0, sp, #0x190
	add r0, r8
	ldr r1, [sp, #0x258]
	ldr r2, [sp, #0x25c]
	str r1, [r0]
	str r2, [r0, #4]
	mov r6, sb
	cmp r6, r7
	ble _0825087C
_082508EC:
	mov sb, r7
	b _08250624
	.align 2, 0
_082508F0: .4byte 0x003FFFFF
_082508F4: .4byte 0x3FF00000
_082508F8: .4byte 0x00000000
_082508FC: .4byte 0x00000000
_08250900: .4byte 0x00000000
_08250904:
	ldr r3, _08250948 @ =0x00000000
	ldr r2, _08250944 @ =0x00000000
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __eqdf2
	cmp r0, #0
	bne _0825094C
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	ldr r3, [sp, #0x248]
	subs r3, #0x18
	str r3, [sp, #0x248]
	mov r1, sb
	lsls r0, r1, #2
	mov r2, sp
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, #0
	bne _082509E6
_0825092E:
	subs r1, #4
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	ldr r0, [sp, #0x248]
	subs r0, #0x18
	str r0, [sp, #0x248]
	ldr r0, [r1]
	cmp r0, #0
	beq _0825092E
	b _082509E6
	.align 2, 0
_08250944: .4byte 0x00000000
_08250948: .4byte 0x00000000
_0825094C:
	ldr r1, [sp, #0x248]
	rsbs r2, r1, #0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl scalbn
	str r0, [sp, #0x250]
	str r1, [sp, #0x254]
	ldr r6, _082509C8 @ =0x00000000
	ldr r5, _082509C4 @ =0x41700000
	adds r3, r6, #0
	adds r2, r5, #0
	bl __gedf2
	cmp r0, #0
	blt _082509D4
	ldr r2, _082509CC @ =0x3E700000
	ldr r3, _082509D0 @ =0x00000000
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __muldf3
	bl __fixdfsi
	bl __floatsidf
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	mov r2, sb
	lsls r0, r2, #2
	mov r3, sp
	adds r4, r3, r0
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	adds r3, r6, #0
	adds r2, r5, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
	bl __subdf3
	bl __fixdfsi
	str r0, [r4]
	movs r0, #1
	add sb, r0
	ldr r1, [sp, #0x248]
	adds r1, #0x18
	str r1, [sp, #0x248]
	mov r2, sb
	lsls r0, r2, #2
	mov r3, sp
	adds r4, r3, r0
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	b _082509E0
	.align 2, 0
_082509C4: .4byte 0x41700000
_082509C8: .4byte 0x00000000
_082509CC: .4byte 0x3E700000
_082509D0: .4byte 0x00000000
_082509D4:
	mov r1, sb
	lsls r0, r1, #2
	mov r2, sp
	adds r4, r2, r0
	ldr r0, [sp, #0x250]
	ldr r1, [sp, #0x254]
_082509E0:
	bl __fixdfsi
	str r0, [r4]
_082509E6:
	ldr r1, _08250AB0 @ =0x00000000
	ldr r0, _08250AAC @ =0x3FF00000
	ldr r2, [sp, #0x248]
	bl scalbn
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	mov r6, sb
	cmp r6, #0
	blt _08250A36
	lsls r0, r6, #2
	mov r3, sp
	adds r5, r0, r3
	add r1, sp, #0x190
	lsls r0, r6, #3
	adds r4, r1, r0
_08250A06:
	ldr r0, [r5]
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __muldf3
	str r0, [r4]
	str r1, [r4, #4]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	ldr r2, _08250AB4 @ =0x3E700000
	ldr r3, _08250AB8 @ =0x00000000
	bl __muldf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	subs r5, #4
	subs r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08250A06
_08250A36:
	mov r6, sb
	cmp r6, #0
	blt _08250A9A
_08250A3C:
	ldr r0, _08250ABC @ =0x00000000
	ldr r1, _08250AC0 @ =0x00000000
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	movs r4, #0
	subs r1, r6, #1
	mov sl, r1
	mov r2, sb
	subs r5, r2, r6
	add r3, sp, #0xf0
	mov r8, r3
	ldr r0, [sp, #0x23c]
	cmp r4, r0
	bgt _08250A88
	cmp r4, r5
	bgt _08250A88
	lsls r1, r6, #3
	add r0, sp, #0x190
	adds r6, r1, r0
	ldr r7, _08250AC4 @ =0x085A8F98
_08250A64:
	ldm r7!, {r0, r1}
	ldm r6!, {r2, r3}
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	adds r4, #1
	ldr r1, [sp, #0x23c]
	cmp r4, r1
	bgt _08250A88
	cmp r4, r5
	ble _08250A64
_08250A88:
	lsls r0, r5, #3
	add r0, r8
	ldr r2, [sp, #0x258]
	ldr r3, [sp, #0x25c]
	str r2, [r0]
	str r3, [r0, #4]
	mov r6, sl
	cmp r6, #0
	bge _08250A3C
_08250A9A:
	ldr r3, [sp, #0x284]
	cmp r3, #2
	bgt _08250AC8
	cmp r3, #1
	bge _08250B28
	cmp r3, #0
	beq _08250AD2
	b _08250CFA
	.align 2, 0
_08250AAC: .4byte 0x3FF00000
_08250AB0: .4byte 0x00000000
_08250AB4: .4byte 0x3E700000
_08250AB8: .4byte 0x00000000
_08250ABC: .4byte 0x00000000
_08250AC0: .4byte 0x00000000
_08250AC4: .4byte 0x085A8F98
_08250AC8:
	ldr r0, [sp, #0x284]
	cmp r0, #3
	bne _08250AD0
	b _08250BD0
_08250AD0:
	b _08250CFA
_08250AD2:
	ldr r2, _08250B24 @ =0x00000000
	ldr r1, _08250B20 @ =0x00000000
	str r1, [sp, #0x258]
	str r2, [sp, #0x25c]
	mov r6, sb
	cmp r6, #0
	blt _08250AFE
	add r1, sp, #0xf0
	lsls r0, r6, #3
	adds r4, r1, r0
_08250AE6:
	ldr r2, [r4]
	ldr r3, [r4, #4]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	subs r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08250AE6
_08250AFE:
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	ldr r2, [sp, #0x234]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, [sp, #0x24c]
	cmp r3, #0
	bne _08250B10
	b _08250CFA
_08250B10:
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __negdf2
	ldr r2, [sp, #0x234]
	str r0, [r2]
	str r1, [r2, #4]
	b _08250CFA
	.align 2, 0
_08250B20: .4byte 0x00000000
_08250B24: .4byte 0x00000000
_08250B28:
	ldr r1, _08250BCC @ =0x00000000
	ldr r0, _08250BC8 @ =0x00000000
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	mov r6, sb
	add r1, sp, #0xf0
	mov r8, r1
	cmp r6, #0
	blt _08250B56
	lsls r0, r6, #3
	adds r4, r0, r1
_08250B3E:
	ldr r2, [r4]
	ldr r3, [r4, #4]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	subs r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08250B3E
_08250B56:
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	ldr r2, [sp, #0x234]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, [sp, #0x24c]
	cmp r3, #0
	beq _08250B74
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __negdf2
	ldr r2, [sp, #0x234]
	str r0, [r2]
	str r1, [r2, #4]
_08250B74:
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r2, [sp, #0x258]
	ldr r3, [sp, #0x25c]
	bl __subdf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	mov r0, sb
	cmp r0, #0
	ble _08250BA6
	mov r4, r8
	adds r4, #8
	mov r6, sb
_08250B92:
	ldm r4!, {r2, r3}
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	subs r6, #1
	cmp r6, #0
	bne _08250B92
_08250BA6:
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	ldr r2, [sp, #0x234]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	ldr r3, [sp, #0x24c]
	cmp r3, #0
	bne _08250BB8
	b _08250CFA
_08250BB8:
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __negdf2
	ldr r2, [sp, #0x234]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	b _08250CFA
	.align 2, 0
_08250BC8: .4byte 0x00000000
_08250BCC: .4byte 0x00000000
_08250BD0:
	mov r6, sb
	add r3, sp, #0xf0
	mov r8, r3
	cmp r6, #0
	ble _08250C20
	lsls r0, r6, #3
	subs r0, #8
	adds r7, r0, r3
_08250BE0:
	subs r6, #1
	ldr r4, [r7]
	ldr r5, [r7, #4]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x258]
	ldr r3, [sp, #0x25c]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	bl __adddf3
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	str r0, [r7]
	str r1, [r7, #4]
	subs r7, #8
	cmp r6, #0
	bgt _08250BE0
_08250C20:
	mov r6, sb
	cmp r6, #1
	ble _08250C6E
	lsls r0, r6, #3
	subs r0, #8
	mov r1, r8
	adds r7, r0, r1
_08250C2E:
	subs r6, #1
	ldr r4, [r7]
	ldr r5, [r7, #4]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x258]
	ldr r3, [sp, #0x25c]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	bl __adddf3
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	ldr r2, [sp, #0x258]
	ldr r3, [sp, #0x25c]
	str r2, [r7]
	str r3, [r7, #4]
	subs r7, #8
	cmp r6, #1
	bgt _08250C2E
_08250C6E:
	ldr r1, _08250CC8 @ =0x00000000
	ldr r0, _08250CC4 @ =0x00000000
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	mov r6, sb
	cmp r6, #1
	ble _08250C9A
	lsls r0, r6, #3
	mov r1, r8
	adds r4, r0, r1
_08250C82:
	ldr r2, [r4]
	ldr r3, [r4, #4]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __adddf3
	str r0, [sp, #0x258]
	str r1, [sp, #0x25c]
	subs r4, #8
	subs r6, #1
	cmp r6, #1
	bgt _08250C82
_08250C9A:
	ldr r2, [sp, #0x24c]
	cmp r2, #0
	bne _08250CCC
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r2, [sp, #0x234]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	ldr r3, [sp, #0x234]
	str r0, [r3, #8]
	str r1, [r3, #0xc]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	ldr r2, [sp, #0x234]
	str r0, [r2, #0x10]
	str r1, [r2, #0x14]
	b _08250CFA
	.align 2, 0
_08250CC4: .4byte 0x00000000
_08250CC8: .4byte 0x00000000
_08250CCC:
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	bl __negdf2
	ldr r2, [sp, #0x234]
	str r0, [r2]
	str r1, [r2, #4]
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	bl __negdf2
	ldr r2, [sp, #0x234]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	ldr r0, [sp, #0x258]
	ldr r1, [sp, #0x25c]
	bl __negdf2
	ldr r3, [sp, #0x234]
	str r0, [r3, #0x10]
	str r1, [r3, #0x14]
_08250CFA:
	movs r0, #7
	ldr r1, [sp, #0x244]
	ands r0, r1
	movs r3, #0x99
	lsls r3, r3, #2
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}

	thumb_func_start __kernel_sin
__kernel_sin: @ 0x08250D10
	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _08250D3C @ =0x7FFFFFFF
	ldr r1, [sp]
	ands r0, r1
	ldr r1, _08250D40 @ =0x3E3FFFFF
	cmp r0, r1
	bgt _08250D44
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __fixdfsi
	cmp r0, #0
	bne _08250D44
	ldr r0, [sp]
	ldr r1, [sp, #4]
	b _08250E84
	.align 2, 0
_08250D3C: .4byte 0x7FFFFFFF
_08250D40: .4byte 0x3E3FFFFF
_08250D44:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __muldf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _08250E24 @ =0x5ACFD57C
	ldr r2, _08250E20 @ =0x3DE5D93A
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	ldr r2, _08250E28 @ =0xBE5AE5E6
	ldr r3, _08250E2C @ =0x8A2B9CEB
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	ldr r2, _08250E30 @ =0x3EC71DE3
	ldr r3, _08250E34 @ =0x57B1FE7D
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	ldr r2, _08250E38 @ =0xBF2A01A0
	ldr r3, _08250E3C @ =0x19C161D5
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	ldr r2, _08250E40 @ =0x3F811111
	ldr r3, _08250E44 @ =0x1110F8A6
	bl __adddf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq _08250E58
	ldr r2, _08250E48 @ =0x3FE00000
	ldr r3, _08250E4C @ =0x00000000
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _08250E50 @ =0xBFC55555
	ldr r3, _08250E54 @ =0x55555549
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __subdf3
	b _08250E84
	.align 2, 0
_08250E20: .4byte 0x3DE5D93A
_08250E24: .4byte 0x5ACFD57C
_08250E28: .4byte 0xBE5AE5E6
_08250E2C: .4byte 0x8A2B9CEB
_08250E30: .4byte 0x3EC71DE3
_08250E34: .4byte 0x57B1FE7D
_08250E38: .4byte 0xBF2A01A0
_08250E3C: .4byte 0x19C161D5
_08250E40: .4byte 0x3F811111
_08250E44: .4byte 0x1110F8A6
_08250E48: .4byte 0x3FE00000
_08250E4C: .4byte 0x00000000
_08250E50: .4byte 0xBFC55555
_08250E54: .4byte 0x55555549
_08250E58:
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	bl __muldf3
	ldr r3, _08250E8C @ =0x55555549
	ldr r2, _08250E88 @ =0xBFC55555
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __adddf3
_08250E84:
	add sp, #0x20
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08250E88: .4byte 0xBFC55555
_08250E8C: .4byte 0x55555549

	thumb_func_start __kernel_tan
__kernel_tan: @ 0x08250E90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x40
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, [sp]
	mov r8, r0
	ldr r5, _08250EE0 @ =0x7FFFFFFF
	ands r5, r0
	ldr r0, _08250EE4 @ =0x3E2FFFFF
	cmp r5, r0
	bgt _08250F12
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __fixdfsi
	cmp r0, #0
	bne _08250F12
	ldr r1, [sp, #4]
	orrs r5, r1
	ldr r0, [sp, #0x58]
	adds r0, #1
	orrs r5, r0
	cmp r5, #0
	bne _08250EF0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl fdlibm_fp_fabs
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _08250EE8 @ =0x3FF00000
	ldr r1, _08250EEC @ =0x00000000
	bl __divdf3
	b _08251248
	.align 2, 0
_08250EE0: .4byte 0x7FFFFFFF
_08250EE4: .4byte 0x3E2FFFFF
_08250EE8: .4byte 0x3FF00000
_08250EEC: .4byte 0x00000000
_08250EF0:
	ldr r0, [sp, #0x58]
	cmp r0, #1
	beq _08250F0C
	ldr r1, _08250F08 @ =0x00000000
	ldr r0, _08250F04 @ =0xBFF00000
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __divdf3
	b _08251248
	.align 2, 0
_08250F04: .4byte 0xBFF00000
_08250F08: .4byte 0x00000000
_08250F0C:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	b _08251248
_08250F12:
	ldr r0, _0825118C @ =0x3FE59427
	cmp r5, r0
	ble _08250F6E
	mov r1, r8
	cmp r1, #0
	bge _08250F36
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __negdf2
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __negdf2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
_08250F36:
	ldr r0, _08251190 @ =0x3FE921FB
	ldr r1, _08251194 @ =0x54442D18
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __subdf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, _08251198 @ =0x3C81A626
	ldr r1, _0825119C @ =0x33145C07
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __adddf3
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _082511A0 @ =0x00000000
	ldr r1, _082511A4 @ =0x00000000
	str r0, [sp, #8]
	str r1, [sp, #0xc]
_08250F6E:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	adds r3, r1, #0
	adds r2, r0, #0
	bl __muldf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _082511A8 @ =0x085A9048
	ldr r2, [r4, #0x58]
	ldr r3, [r4, #0x5c]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x4c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	bl __adddf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [r4, #0x60]
	ldr r3, [r4, #0x64]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x40]
	ldr r1, [r4, #0x44]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x30]
	ldr r1, [r4, #0x34]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl __muldf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __muldf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl __adddf3
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	bl __adddf3
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0825118C @ =0x3FE59427
	cmp r5, r0
	ble _082511AC
	ldr r0, [sp, #0x58]
	bl __floatsidf
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	mov r0, r8
	asrs r1, r0, #0x1e
	movs r0, #2
	ands r1, r0
	movs r0, #1
	subs r0, r0, r1
	bl __floatsidf
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r7, #0
	adds r2, r6, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __divdf3
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __muldf3
	b _08251248
	.align 2, 0
_0825118C: .4byte 0x3FE59427
_08251190: .4byte 0x3FE921FB
_08251194: .4byte 0x54442D18
_08251198: .4byte 0x3C81A626
_0825119C: .4byte 0x33145C07
_082511A0: .4byte 0x00000000
_082511A4: .4byte 0x00000000
_082511A8: .4byte 0x085A9048
_082511AC:
	ldr r1, [sp, #0x58]
	cmp r1, #1
	beq _08251244
	adds r1, r7, #0
	adds r0, r6, #0
	movs r1, #0
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	bl __subdf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, _08251238 @ =0x00000000
	ldr r0, _08251234 @ =0xBFF00000
	adds r3, r7, #0
	adds r2, r6, #0
	bl __divdf3
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	adds r5, r1, #0
	adds r4, r0, #0
	movs r5, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	bl __muldf3
	ldr r2, _0825123C @ =0x3FF00000
	ldr r3, _08251240 @ =0x00000000
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	b _08251248
	.align 2, 0
_08251234: .4byte 0xBFF00000
_08251238: .4byte 0x00000000
_0825123C: .4byte 0x3FF00000
_08251240: .4byte 0x00000000
_08251244:
	adds r1, r7, #0
	adds r0, r6, #0
_08251248:
	add sp, #0x40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}

	thumb_func_start fdlibm_floor
fdlibm_floor: @ 0x08251250
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r4, r0, #0
	adds r7, r5, #0
	adds r6, r4, #0
	mov r8, r6
	mov sl, r7
	lsls r0, r6, #1
	lsrs r0, r0, #0x15
	ldr r1, _082512A0 @ =0xFFFFFC01
	adds r1, r1, r0
	mov sb, r1
	cmp r1, #0x13
	bgt _08251334
	cmp r1, #0
	bge _082512D8
	ldr r2, _082512A4 @ =0x7E37E43C
	ldr r3, _082512A8 @ =0x8800759C
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	ldr r2, _082512AC @ =0x00000000
	ldr r3, _082512B0 @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	bgt _08251294
	b _082513BE
_08251294:
	cmp r6, #0
	blt _082512B4
	movs r0, #0
	mov sl, r0
	mov r8, r0
	b _082513BE
	.align 2, 0
_082512A0: .4byte 0xFFFFFC01
_082512A4: .4byte 0x7E37E43C
_082512A8: .4byte 0x8800759C
_082512AC: .4byte 0x00000000
_082512B0: .4byte 0x00000000
_082512B4:
	ldr r0, _082512D0 @ =0x7FFFFFFF
	mov r1, r8
	ands r0, r1
	mov r1, sl
	orrs r0, r1
	cmp r0, #0
	bne _082512C4
	b _082513BE
_082512C4:
	ldr r0, _082512D4 @ =0xBFF00000
	mov r8, r0
	movs r1, #0
	mov sl, r1
	b _082513BE
	.align 2, 0
_082512D0: .4byte 0x7FFFFFFF
_082512D4: .4byte 0xBFF00000
_082512D8:
	ldr r0, _08251320 @ =0x000FFFFF
	mov r1, sb
	asrs r0, r1
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp]
	ands r0, r1
	mov r1, sl
	orrs r0, r1
	cmp r0, #0
	beq _082513CA
	ldr r2, _08251324 @ =0x7E37E43C
	ldr r3, _08251328 @ =0x8800759C
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	ldr r2, _0825132C @ =0x00000000
	ldr r3, _08251330 @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	ble _082513BE
	cmp r6, #0
	bge _08251314
	movs r0, #0x80
	lsls r0, r0, #0xd
	mov r1, sb
	asrs r0, r1
	add r8, r0
_08251314:
	mov r0, r8
	ldr r1, [sp]
	bics r0, r1
	mov r8, r0
	movs r0, #0
	b _082513BC
	.align 2, 0
_08251320: .4byte 0x000FFFFF
_08251324: .4byte 0x7E37E43C
_08251328: .4byte 0x8800759C
_0825132C: .4byte 0x00000000
_08251330: .4byte 0x00000000
_08251334:
	mov r1, sb
	cmp r1, #0x33
	ble _08251350
	movs r0, #0x80
	lsls r0, r0, #3
	cmp sb, r0
	bne _082513CA
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	b _082513CE
_08251350:
	ldr r1, _0825138C @ =0xFFFFFBED
	adds r0, r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	lsrs r1, r0
	str r1, [sp]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _082513CA
	ldr r2, _08251390 @ =0x7E37E43C
	ldr r3, _08251394 @ =0x8800759C
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	ldr r2, _08251398 @ =0x00000000
	ldr r3, _0825139C @ =0x00000000
	bl __gtdf2
	cmp r0, #0
	ble _082513BE
	cmp r6, #0
	bge _082513B6
	mov r0, sb
	cmp r0, #0x14
	bne _082513A0
	movs r1, #1
	add r8, r1
	b _082513B6
	.align 2, 0
_0825138C: .4byte 0xFFFFFBED
_08251390: .4byte 0x7E37E43C
_08251394: .4byte 0x8800759C
_08251398: .4byte 0x00000000
_0825139C: .4byte 0x00000000
_082513A0:
	movs r1, #0x34
	mov r0, sb
	subs r1, r1, r0
	movs r0, #1
	lsls r0, r1
	add r0, sl
	cmp r0, sl
	bhs _082513B4
	movs r1, #1
	add r8, r1
_082513B4:
	mov sl, r0
_082513B6:
	mov r0, sl
	ldr r1, [sp]
	bics r0, r1
_082513BC:
	mov sl, r0
_082513BE:
	mov r0, r8
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	ldr r4, [sp, #4]
	ldr r5, [sp, #8]
_082513CA:
	adds r1, r5, #0
	adds r0, r4, #0
_082513CE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

