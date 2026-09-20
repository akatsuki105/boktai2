	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bfa50
FUN_080bfa50: @ 0x080BFA50
	ldr r1, _080BFA58 @ =0x03000158
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080BFA58: .4byte 0x03000158

	thumb_func_start FUN_080bfa5c
FUN_080bfa5c: @ 0x080BFA5C
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BFA70 @ =0x000005B6
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BFA70: .4byte 0x000005B6

	thumb_func_start FUN_080bfa74
FUN_080bfa74: @ 0x080BFA74
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _080BFAA0 @ =0x03002BE0
	adds r4, r5, #0
	ldr r3, _080BFAA4 @ =0x0000040C
	movs r2, #0
_080BFA80:
	ldr r0, [r4]
	adds r0, r0, r3
	adds r0, r0, r1
	strb r2, [r0]
	adds r1, #1
	cmp r1, #0x1f
	ble _080BFA80
	ldr r0, [r5]
	ldr r1, _080BFAA8 @ =0x0000042E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFAA0: .4byte 0x03002BE0
_080BFAA4: .4byte 0x0000040C
_080BFAA8: .4byte 0x0000042E

	thumb_func_start FUN_080bfaac
FUN_080bfaac: @ 0x080BFAAC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, _080BFB24 @ =0x03002BE0
	ldr r1, [r6]
	movs r4, #1
	str r4, [r1, #0x1c]
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, _080BFB28 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r6]
	movs r7, #0
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r6]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, _080BFB2C @ =0x000002E6
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	bl FUN_080bfa74
	ldr r0, [r6]
	ldr r1, _080BFB30 @ =0x0000042C
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r5, r5, r0
	ldrh r0, [r5]
	cmp r0, #1
	beq _080BFB48
	cmp r0, #1
	bgt _080BFB34
	cmp r0, #0
	beq _080BFB3E
	b _080BFB6E
	.align 2, 0
_080BFB24: .4byte 0x03002BE0
_080BFB28: .4byte 0x0000037D
_080BFB2C: .4byte 0x000002E6
_080BFB30: .4byte 0x0000042C
_080BFB34:
	cmp r0, #2
	beq _080BFB58
	cmp r0, #3
	beq _080BFB62
	b _080BFB6E
_080BFB3E:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x20
	b _080BFB6A
_080BFB48:
	ldr r0, [r6]
	ldr r1, _080BFB54 @ =0x0000042C
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x40
	b _080BFB6A
	.align 2, 0
_080BFB54: .4byte 0x0000042C
_080BFB58:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x10
	b _080BFB6A
_080BFB62:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x80
_080BFB6A:
	orrs r1, r2
	strh r1, [r0]
_080BFB6E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bfb74
FUN_080bfb74: @ 0x080BFB74
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xb4
	ldrh r0, [r3]
	lsrs r0, r0, #3
	adds r1, r2, #0
	adds r1, #0x6c
	strh r0, [r1, #0x10]
	adds r0, r2, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080BFB9E
	movs r0, #0
	strh r0, [r3]
_080BFB9E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfba4
FUN_080bfba4: @ 0x080BFBA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x86
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080BFBC6
	adds r1, r0, #0
	movs r0, #0x80
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bgt _080BFBC8
_080BFBC6:
	movs r1, #1
_080BFBC8:
	adds r2, r4, #0
	adds r2, #0x68
	ldrh r0, [r2]
	adds r1, r0, r1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080BFBE0
	adds r0, r1, #0
	subs r0, #0xc
	strh r0, [r2]
_080BFBE0:
	ldrh r0, [r2]
	lsrs r0, r0, #2
	strh r0, [r4, #0x30]
	ldr r1, _080BFC0C @ =0x0000057C
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080BFC3C
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFC10 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080BFC18
	ldr r0, _080BFC14 @ =0x0000023A
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC08: .4byte 0x03002BE0
_080BFC0C: .4byte 0x0000057C
_080BFC10: .4byte 0x0000042E
_080BFC14: .4byte 0x0000023A
_080BFC18:
	cmp r0, #3
	bhi _080BFC28
	ldr r0, _080BFC24 @ =0x0000023B
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC24: .4byte 0x0000023B
_080BFC28:
	cmp r0, #5
	bhi _080BFC36
	movs r0, #0x8f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080BFC3C
_080BFC36:
	ldr r0, _080BFC58 @ =0x0000023D
	bl PlaySound_082406e0
_080BFC3C:
	ldr r0, _080BFC5C @ =0x0000057C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080BFC52
	movs r0, #0
	strh r0, [r1]
_080BFC52:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFC58: .4byte 0x0000023D
_080BFC5C: .4byte 0x0000057C

	thumb_func_start FUN_080bfc60
FUN_080bfc60: @ 0x080BFC60
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080BFCE0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	mov r6, sp
	movs r3, #0xfe
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #3
_080BFCB8:
	ldm r6!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BFCB8
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFCE0: .4byte 0x030046A0

	thumb_func_start FUN_080bfce4
FUN_080bfce4: @ 0x080BFCE4
	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFCF2:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFCF2
	pop {r0}
	bx r0

	thumb_func_start FUN_080bfd04
FUN_080bfd04: @ 0x080BFD04
	push {lr}
	movs r3, #1
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFD10:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFD10
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfd24
FUN_080bfd24: @ 0x080BFD24
	push {lr}
	adds r1, r0, #0
	ldr r0, _080BFD44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFD48 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #3
	bls _080BFD4C
	movs r0, #0xb1
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	b _080BFD54
	.align 2, 0
_080BFD44: .4byte 0x03002BE0
_080BFD48: .4byte 0x0000042E
_080BFD4C:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #0
_080BFD54:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfd5c
FUN_080bfd5c: @ 0x080BFD5C
	push {lr}
	adds r2, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080BFD78 @ =0x0000058E
	adds r1, r2, r3
	ldrh r3, [r0]
	ldrh r1, [r1]
	cmp r3, r1
	bls _080BFD7C
	movs r0, #0xa
	b _080BFDA6
	.align 2, 0
_080BFD78: .4byte 0x0000058E
_080BFD7C:
	ldr r1, _080BFD8C @ =0x0000058C
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bls _080BFD90
	movs r0, #5
	b _080BFDA6
	.align 2, 0
_080BFD8C: .4byte 0x0000058C
_080BFD90:
	ldr r1, _080BFDA0 @ =0x0000058A
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bhi _080BFDA4
	movs r0, #1
	b _080BFDA6
	.align 2, 0
_080BFDA0: .4byte 0x0000058A
_080BFDA4:
	movs r0, #2
_080BFDA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bfdac
FUN_080bfdac: @ 0x080BFDAC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r1, [r0]
	cmp r1, #1
	bne _080BFDE0
	movs r2, #0x30
	movs r1, #5
	ldr r4, _080BFDDC @ =0x0000034A
	adds r0, r3, r4
_080BFDC4:
	strh r2, [r0]
	subs r0, #0x2c
	subs r1, #1
	cmp r1, #0
	bge _080BFDC4
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #4
	strh r0, [r1]
	b _080BFE40
	.align 2, 0
_080BFDDC: .4byte 0x0000034A
_080BFDE0:
	cmp r1, #2
	bne _080BFDEE
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
	b _080BFE08
_080BFDEE:
	cmp r1, #5
	bne _080BFDFC
	movs r4, #0x9f
	lsls r4, r4, #2
	adds r0, r3, r4
	strh r1, [r0, #0x10]
	b _080BFE0A
_080BFDFC:
	cmp r1, #0xa
	bne _080BFE0A
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
_080BFE08:
	strh r0, [r1, #0x10]
_080BFE0A:
	movs r7, #2
	rsbs r7, r7, #0
	adds r2, r3, #0
	movs r4, #0x94
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r4, r3, #0
	adds r4, #0xdc
	ldr r6, _080BFE48 @ =0x0000026E
	movs r5, #0x38
_080BFE1E:
	ldr r0, [r1]
	ands r0, r7
	str r0, [r1]
	adds r0, r2, r6
	strh r5, [r0]
	adds r2, #0x2c
	adds r1, #0x2c
	cmp r2, r4
	ble _080BFE1E
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0xa
	strh r1, [r0]
	ldr r0, _080BFE4C @ =0x0000028B
	bl PlaySound_082406e0
_080BFE40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFE48: .4byte 0x0000026E
_080BFE4C: .4byte 0x0000028B

	thumb_func_start FUN_080bfe50
FUN_080bfe50: @ 0x080BFE50
	push {r4, r5, lr}
	adds r1, r0, #0
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrh r3, [r4]
	adds r2, r3, #0
	cmp r2, #0
	beq _080BFEEC
	movs r5, #0xb2
	lsls r5, r5, #3
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #1
	bne _080BFEAC
	subs r0, r3, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080BFE92
	movs r2, #1
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r3, #5
_080BFE82:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE82
	b _080BFEEC
_080BFE92:
	ldr r5, _080BFEA8 @ =0x0000026E
	adds r1, r1, r5
	movs r3, #5
_080BFE98:
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE98
	b _080BFEEC
	.align 2, 0
_080BFEA8: .4byte 0x0000026E
_080BFEAC:
	cmp r2, #3
	bls _080BFECC
	ldr r0, _080BFEC8 @ =0x0000026E
	adds r2, r1, r0
	movs r3, #5
_080BFEB6:
	ldrh r0, [r2]
	subs r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFEB6
	b _080BFEE0
	.align 2, 0
_080BFEC8: .4byte 0x0000026E
_080BFECC:
	ldr r5, _080BFEF4 @ =0x0000026E
	adds r2, r1, r5
	movs r3, #5
_080BFED2:
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFED2
_080BFEE0:
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_080BFEEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFEF4: .4byte 0x0000026E

	thumb_func_start FUN_080bfef8
FUN_080bfef8: @ 0x080BFEF8
	push {lr}
	movs r3, #1
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #5
_080BFF04:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF04
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bff18
FUN_080bff18: @ 0x080BFF18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BFF44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080BFF48 @ =0x0000042E
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #7
	ble _080BFF2C
	movs r2, #7
_080BFF2C:
	movs r1, #0
	cmp r1, r2
	bge _080BFF56
	movs r4, #1
	movs r3, #2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r5, r6
_080BFF3C:
	cmp r1, #3
	bgt _080BFF4C
	strh r4, [r0, #0x10]
	b _080BFF4E
	.align 2, 0
_080BFF44: .4byte 0x03002BE0
_080BFF48: .4byte 0x0000042E
_080BFF4C:
	strh r3, [r0, #0x10]
_080BFF4E:
	adds r0, #0x2c
	adds r1, #1
	cmp r1, r2
	blt _080BFF3C
_080BFF56:
	cmp r1, #6
	bgt _080BFF72
	movs r2, #0
	movs r0, #0x2c
	muls r0, r1, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r5
_080BFF68:
	strh r2, [r0, #0x10]
	adds r0, #0x2c
	adds r1, #1
	cmp r1, #6
	ble _080BFF68
_080BFF72:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bff78
FUN_080bff78: @ 0x080BFF78
	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFF86:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF86
	pop {r0}
	bx r0

	thumb_func_start FUN_080bff98
FUN_080bff98: @ 0x080BFF98
	push {lr}
	movs r3, #1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFFA4:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFFA4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bffb8
FUN_080bffb8: @ 0x080BFFB8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfce4
	adds r0, r4, #0
	bl FUN_080bff78
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bffcc
FUN_080bffcc: @ 0x080BFFCC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfd04
	adds r0, r4, #0
	bl FUN_080bfef8
	adds r0, r4, #0
	bl FUN_080bff98
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bffe8
FUN_080bffe8: @ 0x080BFFE8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfaac
	adds r0, r4, #0
	bl FUN_080bffb8
	ldr r0, _080C000C @ =0x0000057A
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _080C0010 @ =FUN_080c0248
	adds r0, r4, #0
	bl FUN_080bfa5c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C000C: .4byte 0x0000057A
_080C0010: .4byte FUN_080c0248

	thumb_func_start FUN_080c0014
FUN_080c0014: @ 0x080C0014
	push {r4, lr}
	sub sp, #0xc
	adds r2, r0, #0
	ldr r1, _080C004C @ =0x000005AC
	adds r0, r2, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080C0044
	ldr r1, _080C0050 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r4, sp
	str r4, [r1, #4]
	ldr r4, _080C0054 @ =0x0000057E
	adds r0, r2, r4
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r3, #0
	bl Script_ExecById
_080C0044:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C004C: .4byte 0x000005AC
_080C0050: .4byte 0xFFFF0000
_080C0054: .4byte 0x0000057E

	thumb_func_start FUN_080c0058
FUN_080c0058: @ 0x080C0058
	push {lr}
	sub sp, #0xc
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C0080
	ldr r1, _080C0088 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080C0080:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080C0088: .4byte 0xFFFF0000

	thumb_func_start FUN_080c008c
FUN_080c008c: @ 0x080C008C
	push {r4, lr}
	ldr r0, _080C00C8 @ =0x03000158
	ldr r3, [r0]
	cmp r3, #0
	beq _080C00C2
	ldr r2, _080C00CC @ =FUN_080bffe8
	movs r0, #0
	movs r1, #0
	bl FUN_080a6180
	ldr r4, _080C00D0 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0807b910
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
_080C00C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C00C8: .4byte 0x03000158
_080C00CC: .4byte FUN_080bffe8
_080C00D0: .4byte 0x03002BE0

	thumb_func_start FUN_080c00d4
FUN_080c00d4: @ 0x080C00D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080C00EC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C00F0 @ =0x0000042E
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C00F4
	movs r7, #0
	b _080C0106
	.align 2, 0
_080C00EC: .4byte 0x03002BE0
_080C00F0: .4byte 0x0000042E
_080C00F4:
	cmp r1, #3
	bhi _080C00FC
	movs r7, #1
	b _080C0106
_080C00FC:
	ldrh r0, [r0]
	subs r7, r0, #2
	subs r0, #3
	muls r0, r7, r0
	asrs r7, r0, #1
_080C0106:
	adds r0, r4, #0
	bl FUN_080bfd5c
	adds r5, r0, #0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r6, r4, r2
	ldrh r0, [r6]
	cmp r0, r5
	beq _080C0146
	ldr r3, _080C0190 @ =0x000005A4
	adds r0, r4, r3
	ldr r2, [r0]
	cmp r2, #0
	beq _080C013E
	ldr r1, _080C0194 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r5, [sp]
	adds r0, r2, #0
	bl Script_ExecById
_080C013E:
	strh r5, [r6]
	adds r0, r4, #0
	bl FUN_080bfdac
_080C0146:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r4, r2
	muls r0, r7, r0
	ldrh r3, [r1]
	adds r2, r0, r3
	strh r2, [r1]
	ldr r0, _080C0198 @ =0x000005B2
	adds r5, r4, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r3, [r5]
	cmp r0, r3
	blo _080C019C
	movs r4, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080C018C
	adds r3, r1, #0
	adds r2, r5, #0
_080C0178:
	adds r4, #1
	ldrh r0, [r3]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080C0178
_080C018C:
	adds r0, r4, #0
	b _080C019E
	.align 2, 0
_080C0190: .4byte 0x000005A4
_080C0194: .4byte 0xFFFF0000
_080C0198: .4byte 0x000005B2
_080C019C:
	movs r0, #0
_080C019E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c01a8
FUN_080c01a8: @ 0x080C01A8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c01ac
FUN_080c01ac: @ 0x080C01AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _080C0218 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	str r4, [r0]
	bl FUN_080bfa74
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Sound_SetBGMTempo
	movs r0, #8
	bl FUN_0823bca8
	adds r0, r7, #0
	bl FUN_080bffcc
	ldr r2, _080C021C @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #2
	str r1, [r0, #0x1c]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r2]
	adds r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	cmp r6, #0
	bne _080C0224
	ldr r2, _080C0220 @ =FUN_080c0014
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
	b _080C0230
	.align 2, 0
_080C0218: .4byte 0x030046A0
_080C021C: .4byte 0x03002BE0
_080C0220: .4byte FUN_080c0014
_080C0224:
	ldr r2, _080C0240 @ =FUN_080c0058
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
_080C0230:
	ldr r1, _080C0244 @ =FUN_080c01a8
	adds r0, r7, #0
	bl FUN_080bfa5c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0240: .4byte FUN_080c0058
_080C0244: .4byte FUN_080c01a8

	thumb_func_start FUN_080c0248
FUN_080c0248: @ 0x080C0248
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r4, _080C0294 @ =0x03002BE0
	ldr r3, [r4]
	ldr r0, _080C0298 @ =0x0000037D
	adds r5, r3, r0
	ldrb r2, [r5]
	cmp r2, #0
	beq _080C025E
	b _080C03F0
_080C025E:
	ldr r2, _080C029C @ =0x00000594
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080bfba4
	movs r5, #0
	ldr r2, [r4]
	ldr r1, _080C02A0 @ =0x0000042E
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r1, #3
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2, #0x2c]
	ldr r1, [r4]
	movs r4, #0x2c
	ldrsh r2, [r1, r4]
	ldr r0, _080C02A4 @ =0x0000037F
	cmp r2, r0
	bgt _080C02A8
	adds r0, #1
	strh r0, [r1, #0x2c]
	b _080C02B2
	.align 2, 0
_080C0294: .4byte 0x03002BE0
_080C0298: .4byte 0x0000037D
_080C029C: .4byte 0x00000594
_080C02A0: .4byte 0x0000042E
_080C02A4: .4byte 0x0000037F
_080C02A8:
	ldr r0, _080C030C @ =0x000003FF
	cmp r2, r0
	ble _080C02B2
	strh r0, [r1, #0x2c]
	movs r5, #1
_080C02B2:
	cmp r5, #0
	beq _080C032C
	ldr r0, _080C0310 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0314 @ =0x0000037D
	adds r0, r0, r1
	movs r5, #0
	movs r4, #1
	strb r4, [r0]
	ldr r2, _080C0318 @ =0x0000057E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080C031C @ =0x0000023A
	bl sound_08240740
	ldr r0, _080C0320 @ =0x0000023B
	bl sound_08240740
	movs r0, #0x8f
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _080C0324 @ =0x0000023D
	bl sound_08240740
	ldr r1, _080C0328 @ =0x0000057C
	adds r0, r6, r1
	strh r5, [r0]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r6, r4
	strh r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Sound_SetBGMTempo
	bl FUN_080bfa74
	b _080C03C8
	.align 2, 0
_080C030C: .4byte 0x000003FF
_080C0310: .4byte 0x03002BE0
_080C0314: .4byte 0x0000037D
_080C0318: .4byte 0x0000057E
_080C031C: .4byte 0x0000023A
_080C0320: .4byte 0x0000023B
_080C0324: .4byte 0x0000023D
_080C0328: .4byte 0x0000057C
_080C032C:
	adds r0, r6, #0
	bl FUN_080bfd24
	adds r0, r6, #0
	bl FUN_080c00d4
	adds r4, r0, #0
	ldr r0, _080C036C @ =0x0000059C
	adds r1, r6, r0
	ldr r0, [r1]
	adds r3, r0, r4
	str r3, [r1]
	ldr r0, _080C0370 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, r4
	bge _080C0378
	str r5, [r1]
	ldr r4, _080C0374 @ =0x0000057A
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C03C8
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C036C: .4byte 0x0000059C
_080C0370: .4byte 0x030046A0
_080C0374: .4byte 0x0000057A
_080C0378:
	ldr r1, _080C03A0 @ =0x00000594
	adds r0, r6, r1
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blt _080C03A4
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r3, r0
	blt _080C03A4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C03A0: .4byte 0x00000594
_080C03A4:
	ldr r0, _080C03E4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080C03E8 @ =0x0000042E
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	bl Sound_SetBGMTempo
	ldr r0, _080C03EC @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, r0, r4
	str r0, [r1]
_080C03C8:
	adds r0, r6, #0
	bl FUN_080bfc60
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #1
	bls _080C04AE
	lsls r0, r0, #2
	bl FUN_0823b9cc
	b _080C04AE
	.align 2, 0
_080C03E4: .4byte 0x03002BE0
_080C03E8: .4byte 0x0000042E
_080C03EC: .4byte 0x030046A0
_080C03F0:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r1, _080C0418 @ =0xFFFFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _080C0420
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C041C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #5
	movs r2, #4
	b _080C0472
	.align 2, 0
_080C0418: .4byte 0xFFFFFF00
_080C041C: .4byte 0x00001FFF
_080C0420:
	cmp r2, #3
	bne _080C048C
	ldr r2, _080C047C @ =0x0000037E
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r3, #0
	movs r2, #4
	strb r2, [r5]
	ldr r0, [r4]
	ldr r1, _080C047C @ =0x0000037E
	adds r0, r0, r1
	strh r3, [r0]
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r4]
	ldr r1, _080C0480 @ =0x000002E6
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r4, _080C0484 @ =0x000002E7
	adds r0, r0, r4
	strb r1, [r0]
	str r2, [sp]
	ldr r0, _080C0488 @ =0x00001FFF
	str r0, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	movs r1, #5
_080C0472:
	movs r3, #4
	bl FUN_0823ce68
	b _080C04AE
	.align 2, 0
_080C047C: .4byte 0x0000037E
_080C0480: .4byte 0x000002E6
_080C0484: .4byte 0x000002E7
_080C0488: .4byte 0x00001FFF
_080C048C:
	cmp r2, #4
	bne _080C04AE
	ldr r1, _080C04D0 @ =0x0000037E
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r0, #0
	strb r0, [r5]
	ldr r1, [r4]
	ldr r2, _080C04D0 @ =0x0000037E
	adds r1, r1, r2
	strh r0, [r1]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r1, r6, r4
	strh r0, [r1]
_080C04AE:
	adds r0, r6, #0
	bl FUN_080bff18
	adds r0, r6, #0
	bl FUN_080bfe50
	ldr r0, _080C04D4 @ =0x0000057A
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C04C8
	subs r0, #1
	strh r0, [r1]
_080C04C8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C04D0: .4byte 0x0000037E
_080C04D4: .4byte 0x0000057A

	thumb_func_start FUN_080c04d8
FUN_080c04d8: @ 0x080C04D8
	push {lr}
	ldr r0, _080C04FC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0500 @ =0x0000042E
	adds r3, r0, r1
	ldrh r0, [r3]
	cmp r0, #3
	bhi _080C050C
	ldr r1, _080C0504 @ =0x04000050
	movs r0, #0xee
	strh r0, [r1]
	ldr r2, _080C0508 @ =0x04000054
	ldrh r1, [r3]
	movs r0, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	strh r0, [r2]
	b _080C051A
	.align 2, 0
_080C04FC: .4byte 0x03002BE0
_080C0500: .4byte 0x0000042E
_080C0504: .4byte 0x04000050
_080C0508: .4byte 0x04000054
_080C050C:
	ldr r1, _080C0524 @ =0x04000050
	movs r0, #0xae
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r3]
	subs r0, #4
	strh r0, [r1]
_080C051A:
	ldr r1, _080C0528 @ =0x04000052
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080C0524: .4byte 0x04000050
_080C0528: .4byte 0x04000052

	thumb_func_start EntityB3D1_Update
EntityB3D1_Update: @ 0x080C052C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080bfb74
	adds r0, r4, #0
	bl FUN_080c04d8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB3D1_Destroy
EntityB3D1_Destroy: @ 0x080C0554
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x20
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0x6c
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xb8
	bl AuxSprite_Remove
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r4, #4
_080C0576:
	adds r0, r5, #0
	bl MainSprite_Remove
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080C0576
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #6
_080C058C:
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _080C058C
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r4, #5
_080C05A2:
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _080C05A2
	movs r0, #0
	ldr r1, _080C05C4 @ =0x03000158
	str r0, [r1]
	ldr r0, _080C05C8 @ =0x0000023E
	bl sound_08240740
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C05C4: .4byte 0x03000158
_080C05C8: .4byte 0x0000023E

	thumb_func_start FUN_080c05cc
FUN_080c05cc: @ 0x080C05CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C06C8 @ =0x0000CB05
	ldr r1, _080C06CC @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	movs r0, #0xde
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r2, r4, #0
	adds r0, r1, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	ldr r2, _080C06D0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _080C06D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r2, #0
	movs r6, #0xe6
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x28
	movs r3, #0x30
	bl MainSprite_Add
	ldr r2, _080C06D8 @ =0x000003D2
	adds r0, r7, r2
	ldr r2, _080C06DC @ =0x000002A7
	strh r2, [r0]
	movs r5, #0xf8
	lsls r5, r5, #2
	adds r3, r7, r5
	ldr r0, _080C06E0 @ =0x03003584
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r6, #0
	mov sl, r6
	adds r5, r1, #0
	movs r0, #0x60
	mov r8, r0
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r4, r7, r1
	mov sb, r2
_080C0670:
	movs r0, #1
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r2, #0x1e
	movs r3, #0x30
	bl MainSprite_Add
	mov r0, sb
	strh r0, [r4, #0x3a]
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r2, r7, r1
	add r2, r8
	ldr r0, _080C06E0 @ =0x03003584
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	movs r2, #0x60
	add r8, r2
	adds r4, #0x60
	adds r6, #1
	cmp r6, #3
	ble _080C0670
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C06C8: .4byte 0x0000CB05
_080C06CC: .4byte 0x0000B343
_080C06D0: .4byte 0xFFFF0000
_080C06D4: .4byte 0x0000FFFF
_080C06D8: .4byte 0x000003D2
_080C06DC: .4byte 0x000002A7
_080C06E0: .4byte 0x03003584

	thumb_func_start FUN_080c06e4
FUN_080c06e4: @ 0x080C06E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r2, _080C0730 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0x84
	orrs r0, r1
	ldr r1, _080C0734 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xe
	adds r4, r0, #0
	orrs r4, r1
	ands r5, r2
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080C0738 @ =0x0000A8E7
	bl Video_GetAuxSprite
	movs r7, #0
	movs r6, #0x94
	lsls r6, r6, #2
	add r6, r8
_080C0718:
	adds r0, r6, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x11
	bl AuxSprite_Add
	cmp r7, #1
	bgt _080C073C
	adds r0, r7, #3
	b _080C073E
	.align 2, 0
_080C0730: .4byte 0xFFFF0000
_080C0734: .4byte 0x0000FFFF
_080C0738: .4byte 0x0000A8E7
_080C073C:
	adds r0, r7, #5
_080C073E:
	strh r0, [r6, #0x10]
	str r4, [r6, #0x1c]
	str r5, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r1, r4, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C076C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r6, #0x2c
	adds r7, #1
	cmp r7, #5
	ble _080C0718
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C076C: .4byte 0xFFFF0000

	thumb_func_start FUN_080c0770
FUN_080c0770: @ 0x080C0770
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r2, _080C0800 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r5
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C0804 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ands r6, r2
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, _080C0808 @ =0x0000A8E7
	bl Video_GetAuxSprite
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
_080C07A6:
	movs r0, #0x2c
	adds r4, r3, #0
	muls r4, r0, r4
	mov r1, r8
	adds r0, r4, r1
	adds r0, r7, r0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0x10
	str r3, [sp]
	bl AuxSprite_Add
	adds r0, r4, r7
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x10]
	adds r1, r7, r4
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r1, r2
	str r5, [r0]
	str r6, [r0, #4]
	ldr r0, _080C080C @ =0x00000107
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C0800 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldr r3, [sp]
	adds r3, #1
	cmp r3, #6
	ble _080C07A6
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0800: .4byte 0xFFFF0000
_080C0804: .4byte 0x0000FFFF
_080C0808: .4byte 0x0000A8E7
_080C080C: .4byte 0x00000107

	thumb_func_start EntityB3D1_Init
EntityB3D1_Init: @ 0x080C0810
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080C0832
	bl Script_GetValue
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080C083A
_080C0832:
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
_080C083A:
	adds r5, r7, #0
	adds r5, #0x4c
	ldr r0, _080C08C0 @ =0x0000C046
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0x20
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r7, #0x3c]
	strh r6, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x40
	ldr r0, _080C08C4 @ =0x0000052C
	strh r0, [r1]
	adds r5, #0x4c
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r4, #0x4c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r6, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0x88
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0x8c
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x4e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C08E0
	bl Script_GetValue
	cmp r0, #3
	beq _080C08D0
	cmp r0, #3
	ble _080C08E0
	cmp r0, #4
	beq _080C08C8
	cmp r0, #0xa
	beq _080C08D8
	b _080C08E0
	.align 2, 0
_080C08C0: .4byte 0x0000C046
_080C08C4: .4byte 0x0000052C
_080C08C8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #1
	b _080C08E6
_080C08D0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #4
	b _080C08E6
_080C08D8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #3
	b _080C08E6
_080C08E0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #2
_080C08E6:
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0xe4
	ldr r1, _080C095C @ =0x0000C046
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0xb8
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0xd4
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0xd8
	ldr r2, _080C0960 @ =0xFFFFFD00
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080c05cc
	adds r0, r7, #0
	bl FUN_080bfc60
	ldr r1, _080C0964 @ =FUN_080c01a8
	adds r0, r7, #0
	bl FUN_080bfa5c
	adds r0, r7, #0
	bl FUN_080c0770
	adds r0, r7, #0
	bl FUN_080c06e4
	adds r0, r7, #0
	bl FUN_080bffcc
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C096C
	bl Script_GetValue
	ldr r2, _080C0968 @ =0x000005B2
	adds r1, r7, r2
	b _080C0974
	.align 2, 0
_080C095C: .4byte 0x0000C046
_080C0960: .4byte 0xFFFFFD00
_080C0964: .4byte FUN_080c01a8
_080C0968: .4byte 0x000005B2
_080C096C:
	ldr r0, _080C09A0 @ =0x000005B2
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
_080C0974:
	strh r0, [r1]
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C09B0
	bl Script_GetValue
	ldr r2, _080C09A4 @ =0x0000058A
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080C09A8 @ =0x0000058C
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080C09AC @ =0x0000058E
	adds r1, r7, r2
	b _080C09C8
	.align 2, 0
_080C09A0: .4byte 0x000005B2
_080C09A4: .4byte 0x0000058A
_080C09A8: .4byte 0x0000058C
_080C09AC: .4byte 0x0000058E
_080C09B0:
	ldr r0, _080C09E4 @ =0x0000058A
	adds r1, r7, r0
	movs r0, #0xb4
	strh r0, [r1]
	ldr r2, _080C09E8 @ =0x0000058C
	adds r1, r7, r2
	adds r0, #0x78
	strh r0, [r1]
	ldr r0, _080C09EC @ =0x0000058E
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #2
_080C09C8:
	strh r0, [r1]
	movs r0, #0x62
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080C09F4
	bl Script_GetValue
	ldr r2, _080C09F0 @ =0x000005A4
	adds r1, r7, r2
	str r0, [r1]
	b _080C09FA
	.align 2, 0
_080C09E4: .4byte 0x0000058A
_080C09E8: .4byte 0x0000058C
_080C09EC: .4byte 0x0000058E
_080C09F0: .4byte 0x000005A4
_080C09F4:
	ldr r2, _080C0A7C @ =0x000005A4
	adds r0, r7, r2
	str r1, [r0]
_080C09FA:
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r5, [r0]
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C0A22
	bl Script_GetValue
	ldr r2, _080C0A80 @ =0x000005AC
	adds r1, r7, r2
	str r0, [r1]
_080C0A22:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C0A50
	bl Script_GetValue
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
_080C0A50:
	ldr r0, _080C0A84 @ =0x00000594
	adds r4, r7, r0
	str r5, [r4]
	ldr r1, _080C0A88 @ =0x0000059C
	adds r0, r7, r1
	str r5, [r0]
	ldr r0, _080C0A8C @ =0x0000023E
	bl PlaySound_082406e0
	ldr r2, _080C0A90 @ =0x0000057E
	adds r0, r7, r2
	strh r5, [r0]
	str r5, [r4]
	ldr r0, _080C0A94 @ =0x03000158
	str r7, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0A7C: .4byte 0x000005A4
_080C0A80: .4byte 0x000005AC
_080C0A84: .4byte 0x00000594
_080C0A88: .4byte 0x0000059C
_080C0A8C: .4byte 0x0000023E
_080C0A90: .4byte 0x0000057E
_080C0A94: .4byte 0x03000158

	thumb_func_start EntityB3D1_Create
EntityB3D1_Create: @ 0x080C0A98
	push {r4, lr}
	ldr r0, _080C0ACC @ =0x03000158
	ldr r0, [r0]
	cmp r0, #0
	bne _080C0ADE
	ldr r1, _080C0AD0 @ =0x000005BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0ADC
	ldr r1, _080C0AD4 @ =EntityB3D1_Update
	ldr r2, _080C0AD8 @ =EntityB3D1_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB3D1_Init
	cmp r0, #0
	bge _080C0ADC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0ADE
	.align 2, 0
_080C0ACC: .4byte 0x03000158
_080C0AD0: .4byte 0x000005BC
_080C0AD4: .4byte EntityB3D1_Update
_080C0AD8: .4byte EntityB3D1_Destroy
_080C0ADC:
	adds r0, r4, #0
_080C0ADE:
	pop {r4}
	pop {r1}
	bx r1
