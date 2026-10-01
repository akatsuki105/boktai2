	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08202d24
FUN_08202d24: @ 0x08202D24
	adds r3, r0, #0
	adds r3, #0xfa
	movs r2, #0
	strb r1, [r3]
	adds r0, #0xfb
	strb r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08202d34
FUN_08202d34: @ 0x08202D34
	push {lr}
	adds r0, r2, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202D48
	adds r0, r2, #0
	movs r1, #1
	bl FUN_08202d24
_08202D48:
	pop {r0}
	bx r0

	thumb_func_start FUN_08202d4c
FUN_08202d4c: @ 0x08202D4C
	push {r4, lr}
	sub sp, #4
	adds r4, r2, #0
	adds r0, r4, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #0
	beq _08202D88
	adds r0, r4, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202D88
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #4
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015c90
	adds r0, r4, #0
	bl FUN_08202ff8
_08202D88:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08202d90
FUN_08202d90: @ 0x08202D90
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r2, _08202E08 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08202E0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _08202E10 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08202E14 @ =FUN_08202d4c
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08202E08: .4byte 0xFFFF0000
_08202E0C: .4byte 0x0000FFFF
_08202E10: .4byte 0x00004001
_08202E14: .4byte FUN_08202d4c

	thumb_func_start FUN_08202e18
FUN_08202e18: @ 0x08202E18
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _08202EA4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08202EA8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x8c
	ldr r2, _08202EAC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _08202EB0 @ =FUN_08202d34
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202EA4: .4byte 0xFFFF0000
_08202EA8: .4byte 0x0000FFFF
_08202EAC: .4byte 0x00002001
_08202EB0: .4byte FUN_08202d34

	thumb_func_start FUN_08202eb4
FUN_08202eb4: @ 0x08202EB4
	push {r4, lr}
	ldr r0, _08202EC8 @ =0x03000218
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #7
	bls _08202ED0
	b _08202EF4
	.align 2, 0
_08202EC8: .4byte 0x03000218
_08202ECC:
	adds r0, r1, #0
	b _08202EF6
_08202ED0:
	adds r1, #0x40
	movs r2, #0
	movs r4, #1
	movs r3, #0x82
	lsls r3, r3, #1
_08202EDA:
	adds r0, r1, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #0
	bne _08202EEC
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	bne _08202ECC
_08202EEC:
	adds r1, r1, r3
	adds r2, #1
	cmp r2, #7
	ble _08202EDA
_08202EF4:
	movs r0, #0
_08202EF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08202efc
FUN_08202efc: @ 0x08202EFC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _08202F4C @ =0x03000218
	ldr r5, [r0]
	bl FUN_08202eb4
	adds r4, r0, #0
	cmp r4, #0
	beq _08202FE8
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08202d24
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	cmp r7, #0
	bne _08202F54
	adds r1, r4, #0
	adds r1, #0xdc
	str r7, [sp, #4]
	add r0, sp, #4
	ldr r2, _08202F50 @ =0x05000002
	bl CpuSet
	b _08202F60
	.align 2, 0
_08202F4C: .4byte 0x03000218
_08202F50: .4byte 0x05000002
_08202F54:
	adds r2, r4, #0
	adds r2, #0xdc
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
_08202F60:
	cmp r6, #0
	bne _08202F84
	adds r1, r4, #0
	adds r1, #0xe4
	str r6, [sp, #4]
	add r0, sp, #4
	ldr r2, _08202F80 @ =0x05000002
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0xfe
	strb r6, [r0]
	subs r0, #2
	strh r6, [r0]
	b _08202FA0
	.align 2, 0
_08202F80: .4byte 0x05000002
_08202F84:
	adds r2, r4, #0
	adds r2, #0xe4
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r1, [r7]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xfe
	movs r0, #1
	strb r0, [r1]
_08202FA0:
	adds r1, r4, #0
	adds r1, #0xec
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, [sp, #0x2c]
	str r0, [sp]
	adds r0, r4, #0
	mov r1, sb
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl FUN_08202e18
	adds r1, r4, #0
	adds r1, #0xf0
	ldr r0, [sp, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x40]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x48]
	strh r0, [r1]
_08202FE8:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08202ff8
FUN_08202ff8: @ 0x08202FF8
	push {lr}
	adds r3, r0, #0
	ldr r0, _08203030 @ =0x03000218
	ldr r0, [r0]
	cmp r3, #0
	beq _0820302A
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xec
	strh r2, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r2, r3, #0
	adds r2, #0x3c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0820302A:
	pop {r0}
	bx r0
	.align 2, 0
_08203030: .4byte 0x03000218

	thumb_func_start FUN_08203034
FUN_08203034: @ 0x08203034
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0820312E
	adds r4, r7, #0
	adds r4, #0xdc
	adds r5, r7, #0
	adds r5, #0xe4
	movs r1, #0x1c
	adds r1, r1, r7
	mov sb, r1
	ldrh r0, [r5]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0xfc
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #4]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r5, [sp, #8]
	mov r5, r8
	cmp r6, #0
	bne _082030BC
	movs r1, #1
	rsbs r1, r1, #0
	b _082030F4
_082030BC:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #4]
_082030F4:
	ldrh r0, [r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r1, r0
	bgt _08203110
	ldr r3, [sp, #8]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #1
	str r0, [sp]
	b _08203150
_08203110:
	ldrh r0, [r4]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r4, #2]
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	mov r3, sb
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	b _08203150
_0820312E:
	adds r2, r7, #0
	adds r2, #0x1c
	adds r1, r7, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov sb, r2
_08203150:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08203180
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08203188
_08203180:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203188:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082031AC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _082031B4
_082031AC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082031B4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _082031EC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08203224
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082031F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082031E4
	ldrb r0, [r4, #5]
_082031E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203200
	.align 2, 0
_082031EC: .4byte 0x0000FFFF
_082031F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203200
	strh r1, [r4, #8]
_08203200:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08203224
	movs r0, #1
	strb r0, [r4, #7]
_08203224:
	adds r4, r7, #0
	adds r4, #0x8c
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	subs r4, #0x50
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r1, r7, #0
	adds r1, #0xee
	ldrh r0, [r1]
	cmp r0, #0
	beq _0820325A
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _08203262
_0820325A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_08203262:
	strh r0, [r4, #6]
	adds r1, r7, #0
	adds r1, #0xfb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	subs r1, #0xf
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08203282
	movs r3, #1
	str r3, [sp]
_08203282:
	ldr r0, [sp]
	cmp r0, #0
	beq _08203290
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08202d24
_08203290:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_082032a0
FUN_082032a0: @ 0x082032A0
	push {r4, lr}
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0xfb
	ldrb r0, [r3]
	cmp r0, #0
	bne _082032BE
	movs r0, #0x1e
	strh r0, [r4, #0x10]
	adds r2, r4, #0
	adds r2, #0x3c
	subs r0, #0x23
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_082032BE:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _082032D4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08202d24
_082032D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082032dc
FUN_082032dc: @ 0x082032DC
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xfb
	ldrb r0, [r3]
	cmp r0, #0
	bne _082032FC
	movs r0, #0x1f
	strh r0, [r5, #0x10]
	adds r2, r5, #0
	adds r2, #0x3c
	subs r0, #0x24
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_082032FC:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _08203340
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r5, #0
	adds r1, #0xf0
	ldrh r1, [r1]
	adds r2, r5, #0
	adds r2, #0xf2
	ldrh r2, [r2]
	adds r3, r5, #0
	adds r3, #0xf4
	ldrh r3, [r3]
	adds r4, r5, #0
	adds r4, #0xf6
	ldrh r4, [r4]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0xf8
	ldrh r4, [r4]
	str r4, [sp, #4]
	bl FUN_08203b1c
	movs r0, #0xf2
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08202ff8
_08203340:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start Entity082034c0_Update
Entity082034c0_Update: @ 0x08203348
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r7, #0
	ldr r0, _08203394 @ =0x085AE818
	mov r8, r0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r6, r0
_08203360:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0820337A
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bhi _08203388
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_0820337A:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #7
	ble _08203360
_08203388:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08203394: .4byte 0x085AE818

	thumb_func_start Entity082034c0_Destroy
Entity082034c0_Destroy: @ 0x08203398
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #7
_082033A0:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _082033AC
	adds r0, r4, #0
	bl AuxSprite_Remove
_082033AC:
	adds r0, r4, #0
	adds r0, #0x3c
	bl Hitbox_Unregister
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _082033A0
	ldr r1, _082033CC @ =0x03000218
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082033CC: .4byte 0x03000218

	thumb_func_start FUN_082033d0
FUN_082033d0: @ 0x082033D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08203474 @ =0x00002E78
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r1, _08203478 @ =0x00000236
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, _0820347C @ =0x0000922E
	ldr r1, _08203480 @ =0x000038E2
	bl GetFile
	str r0, [r7, #0x34]
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0x40
	movs r6, #0
	movs r0, #7
	mov r8, r0
_08203406:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, sb
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	bl FUN_08202d90
	str r6, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08202e18
	str r6, [sp, #4]
	add r0, sp, #4
	adds r4, r5, #0
	adds r4, #0xdc
	adds r1, r4, #0
	ldr r2, _08203484 @ =0x05000002
	bl CpuSet
	strh r6, [r4, #0x10]
	strh r6, [r4, #0x12]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r0, r8
	cmp r0, #0
	bge _08203406
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203474: .4byte 0x00002E78
_08203478: .4byte 0x00000236
_0820347C: .4byte 0x0000922E
_08203480: .4byte 0x000038E2
_08203484: .4byte 0x05000002

	thumb_func_start Entity082034c0_Init
Entity082034c0_Init: @ 0x08203488
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _082034B0 @ =0x00002E78
	bl Video_GetAuxSprite
	adds r0, r4, #0
	bl FUN_082033d0
	cmp r0, #0
	blt _082034B4
	movs r0, #0
	b _082034B8
	.align 2, 0
_082034B0: .4byte 0x00002E78
_082034B4:
	movs r0, #1
	rsbs r0, r0, #0
_082034B8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity082034c0_Create
Entity082034c0_Create: @ 0x082034C0
	push {r4, lr}
	ldr r0, _082034F8 @ =0x03000218
	ldr r0, [r0]
	cmp r0, #0
	bne _08203506
	movs r1, #0x86
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08203504
	ldr r1, _082034FC @ =Entity082034c0_Update
	ldr r2, _08203500 @ =Entity082034c0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity082034c0_Init
	cmp r0, #0
	bge _08203504
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08203506
	.align 2, 0
_082034F8: .4byte 0x03000218
_082034FC: .4byte Entity082034c0_Update
_08203500: .4byte Entity082034c0_Destroy
_08203504:
	adds r0, r4, #0
_08203506:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820350c
FUN_0820350c: @ 0x0820350C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r4, _08203548 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _0820352A
	bl Entity082034c0_Create
	str r0, [r4]
_0820352A:
	add r3, sp, #0x28
	ldr r2, _0820354C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08203550
	asrs r1, r0, #0xc
	b _08203556
	.align 2, 0
_08203548: .4byte 0x03000218
_0820354C: .4byte 0x085B0A08
_08203550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08203556:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08203572
	asrs r0, r0, #0xc
	b _08203578
_08203572:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08203578:
	strh r0, [r3, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x24]
	adds r0, r7, #0
	add r1, sp, #0x28
	movs r2, #0
	mov r3, r8
	bl FUN_08202efc
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082035bc
FUN_082035bc: @ 0x082035BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r4, _08203618 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _082035DA
	bl Entity082034c0_Create
	str r0, [r4]
_082035DA:
	str r5, [sp]
	ldr r0, [sp, #0x40]
	str r0, [sp, #4]
	ldr r0, [sp, #0x44]
	str r0, [sp, #8]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x24]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	mov r3, r8
	bl FUN_08202efc
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203618: .4byte 0x03000218

	thumb_func_start FUN_0820361c
FUN_0820361c: @ 0x0820361C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r4, _08203688 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _0820363A
	bl Entity082034c0_Create
	str r0, [r4]
_0820363A:
	add r2, sp, #0x28
	movs r1, #0
	adds r0, r2, #0
	strh r5, [r0]
	strh r1, [r2, #2]
	strh r1, [r2, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x24]
	adds r0, r6, #0
	adds r1, r2, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_08202efc
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203688: .4byte 0x03000218

	thumb_func_start FUN_0820368c
FUN_0820368c: @ 0x0820368C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08203690
FUN_08203690: @ 0x08203690
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _0820371C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08203720 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _08203724 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _08203728 @ =FUN_0820368c
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r5, #0x8c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820371C: .4byte 0xFFFF0000
_08203720: .4byte 0x0000FFFF
_08203724: .4byte 0x00002001
_08203728: .4byte FUN_0820368c

