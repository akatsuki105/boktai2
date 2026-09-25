	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080da9c4
FUN_080da9c4: @ 0x080DA9C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	cmp r5, #0
	beq _080DA9F2
	cmp r6, #0x7f
	bne _080DAA6C
	cmp r4, #0
	bne _080DA9F6
_080DA9F2:
	movs r0, #0
	b _080DAB8C
_080DA9F6:
	cmp r2, #5
	bls _080DA9FC
	b _080DAB8C
_080DA9FC:
	lsls r0, r2, #2
	ldr r1, _080DAA08 @ =_080DAA0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAA08: .4byte _080DAA0C
_080DAA0C: @ jump table
	.4byte _080DAA24 @ case 0
	.4byte _080DAA30 @ case 1
	.4byte _080DAA48 @ case 2
	.4byte _080DAA3C @ case 3
	.4byte _080DAA54 @ case 4
	.4byte _080DAA60 @ case 5
_080DAA24:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d99d4
	b _080DAB8C
_080DAA30:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080d99d4
	b _080DAB8C
_080DAA3C:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080d9a9c
	b _080DAB8C
_080DAA48:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080d99d4
	b _080DAB8C
_080DAA54:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080d99d4
	b _080DAB8C
_080DAA60:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080d99d4
	b _080DAB8C
_080DAA6C:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #1
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #2
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #4
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #5
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #3
	bl FUN_080d9a9c
	movs r2, #4
	ldrh r1, [r5, #2]
	ands r1, r2
	movs r3, #0
	cmp r1, #0
	beq _080DAAB6
	movs r3, #0xff
_080DAAB6:
	mov r1, r8
	cmp r1, #5
	bhi _080DAB8C
	lsls r0, r1, #2
	ldr r1, _080DAAC8 @ =_080DAACC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAAC8: .4byte _080DAACC
_080DAACC: @ jump table
	.4byte _080DAAE4 @ case 0
	.4byte _080DAAFE @ case 1
	.4byte _080DAB26 @ case 2
	.4byte _080DAB3A @ case 3
	.4byte _080DAB5E @ case 4
	.4byte _080DAB76 @ case 5
_080DAAE4:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r7, [sp]
	str r3, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_080d9b3c
	b _080DAB8C
_080DAAFE:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r7, [sp]
	str r3, [sp, #4]
	ldr r3, [sp, #0x38]
	str r3, [sp, #8]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_080d9cec
	b _080DAB8C
_080DAB26:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r3, [sp]
	str r5, [sp, #4]
	movs r0, #1
	adds r3, r7, #0
	bl FUN_080d9f5c
	b _080DAB8C
_080DAB3A:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r3, [sp]
	ldr r6, [sp, #0x38]
	str r6, [sp, #4]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #7
	adds r3, r7, #0
	bl FUN_080da698
	b _080DAB8C
_080DAB5E:
	adds r0, r5, #0
	adds r0, #8
	ldrh r1, [r5]
	str r3, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r5, [sp, #8]
	ldr r2, [sp, #0x44]
	adds r3, r7, #0
	bl FUN_080da358
	b _080DAB8C
_080DAB76:
	adds r0, r5, #0
	adds r0, #8
	ldrh r1, [r5]
	str r3, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r5, [sp, #8]
	ldr r2, [sp, #0x44]
	adds r3, r7, #0
	bl FUN_080da4f8
_080DAB8C:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dab9c
FUN_080dab9c: @ 0x080DAB9C
	push {lr}
	adds r1, r0, #0
	ldr r0, _080DABE0 @ =0x03000160
	ldr r2, [r0]
	cmp r1, #0
	blt _080DABDA
	movs r0, #0xa4
	muls r0, r1, r0
	adds r0, #0x3c
	adds r3, r2, r0
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DABDA
	movs r1, #0x3e
	ldrsh r0, [r3, r1]
	cmp r0, #2
	beq _080DABDA
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080DABDA:
	pop {r0}
	bx r0
	.align 2, 0
_080DABE0: .4byte 0x03000160

	thumb_func_start FUN_080dabe4
FUN_080dabe4: @ 0x080DABE4
	push {lr}
	adds r1, r0, #0
	ldr r0, _080DAC1C @ =0x03000160
	ldr r2, [r0]
	cmp r1, #0
	blt _080DAC16
	movs r0, #0xa4
	muls r0, r1, r0
	adds r0, #0x3c
	adds r2, r2, r0
	adds r0, r2, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DAC16
	movs r1, #0x3e
	ldrsh r0, [r2, r1]
	cmp r0, #2
	beq _080DAC16
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080DAC16:
	pop {r0}
	bx r0
	.align 2, 0
_080DAC1C: .4byte 0x03000160

	thumb_func_start FUN_080dac20
FUN_080dac20: @ 0x080DAC20
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dac24
FUN_080dac24: @ 0x080DAC24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	adds r6, r7, #0
	adds r6, #0x44
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bgt _080DAC4A
	movs r0, #0x14
	strh r0, [r6]
	adds r2, r7, #0
	adds r2, #0x40
	ldrh r1, [r2]
	subs r0, #0x19
	ands r0, r1
	strh r0, [r2]
	b _080DAC94
_080DAC4A:
	cmp r0, #0xa
	ble _080DAC8E
	ldr r0, _080DACA0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080DACA4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080DACA8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_080DAC8E:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
_080DAC94:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DACA0: .4byte 0x0203B400
_080DACA4: .4byte 0x030046B8
_080DACA8: .4byte 0x000003FF

	thumb_func_start FUN_080dacac
FUN_080dacac: @ 0x080DACAC
	adds r3, r2, #0
	adds r3, #0x40
	ldrh r1, [r3]
	movs r0, #2
	orrs r0, r1
	strh r0, [r3]
	adds r2, #0x52
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	bx lr

	thumb_func_start FUN_080dacc4
FUN_080dacc4: @ 0x080DACC4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r2, _080DAD3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x40
	orrs r0, r1
	ldr r5, _080DAD40 @ =0x0000FFFF
	ands r0, r5
	movs r4, #0x80
	lsls r4, r4, #0x10
	orrs r0, r4
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ands r0, r5
	orrs r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r4, r6, #0
	adds r4, #0x4c
	ldr r2, _080DAD44 @ =0x00004001
	str r3, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r6, #0
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DAD48 @ =FUN_080dacac
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAD3C: .4byte 0xFFFF0000
_080DAD40: .4byte 0x0000FFFF
_080DAD44: .4byte 0x00004001
_080DAD48: .4byte FUN_080dacac

	thumb_func_start FUN_080dad4c
FUN_080dad4c: @ 0x080DAD4C
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_080DAD54:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _080DAD66
	movs r0, #1
	b _080DAD68
_080DAD66:
	movs r0, #0
_080DAD68:
	cmp r0, #0
	bne _080DAD84
	movs r0, #0xa4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0x42
	strh r2, [r1]
	b _080DAD8C
_080DAD84:
	adds r2, #1
	cmp r2, #7
	ble _080DAD54
	movs r0, #0
_080DAD8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dad94
FUN_080dad94: @ 0x080DAD94
	push {lr}
	adds r3, r0, #0
	ldr r0, _080DADD0 @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _080DADE6
	cmp r0, #0
	beq _080DADE6
	cmp r0, #4
	beq _080DADE6
	ldr r0, _080DADD4 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _080DADD8 @ =0x00000934
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080DADE6
	adds r0, r3, #0
	adds r0, #0x46
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080DADDC
	movs r0, #1
	b _080DADDE
	.align 2, 0
_080DADD0: .4byte 0x030047E0
_080DADD4: .4byte 0x030046A0
_080DADD8: .4byte 0x00000934
_080DADDC:
	movs r0, #0
_080DADDE:
	cmp r0, #0
	beq _080DADE6
	movs r0, #1
	b _080DADE8
_080DADE6:
	movs r0, #0
_080DADE8:
	pop {r1}
	bx r1

	thumb_func_start FUN_080dadec
FUN_080dadec: @ 0x080DADEC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0x3c
	movs r4, #0
	movs r5, #0
	movs r2, #0
_080DADFA:
	movs r1, #1
	lsls r1, r2
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DAE0A
	movs r0, #1
	b _080DAE0C
_080DAE0A:
	movs r0, #0
_080DAE0C:
	cmp r0, #0
	beq _080DAE2E
	movs r0, #0xa4
	muls r0, r2, r0
	adds r0, r0, r6
	adds r0, #0x40
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DAE24
	movs r4, #1
_080DAE24:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DAE2E
	movs r5, #1
_080DAE2E:
	adds r2, #1
	cmp r2, #7
	ble _080DADFA
	cmp r4, #0
	bne _080DAE44
	ldr r0, _080DAE58 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080DAE5C @ =0x000003FF
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
_080DAE44:
	cmp r5, #0
	bne _080DAE50
	movs r0, #1
	rsbs r0, r0, #0
	bl FUN_0808689c
_080DAE50:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAE58: .4byte 0x03002BE0
_080DAE5C: .4byte 0x000003FF

	thumb_func_start FUN_080dae60
FUN_080dae60: @ 0x080DAE60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r5, r4, #0
	adds r5, #0x40
	ldrh r1, [r5]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	beq _080DAF3E
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r2, [r0]
	ldr r0, _080DAEAC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, r2
	bge _080DAEB4
	ldr r3, _080DAEB0 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r6, r1, r0
	b _080DAEB6
	.align 2, 0
_080DAEAC: .4byte 0x03002BE0
_080DAEB0: .4byte 0xFFFFFF00
_080DAEB4:
	subs r6, r1, r2
_080DAEB6:
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x40
	mov r8, r0
	cmp r1, r6
	beq _080DAED6
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _080DAED6
	ldrh r1, [r5]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5]
_080DAED6:
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DAEE4
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DAEE4:
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080DAF14
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #0x3c
	strh r0, [r1]
	mov r0, sb
	adds r1, r4, #0
	bl FUN_080dac24
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0807a524
	mov r0, r8
	strh r6, [r0]
	ldrh r1, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5]
_080DAF14:
	cmp r6, #9
	bgt _080DAF24
	ldrh r1, [r5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DAF24
	b _080DB020
_080DAF24:
	movs r0, #0
	strh r0, [r4, #0x3c]
	movs r0, #2
	strh r0, [r4, #0x3e]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r1, [r5]
	movs r0, #0x13
	rsbs r0, r0, #0
	b _080DB01A
_080DAF3E:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DAF88
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _080DAF54
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DAF54:
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080DAF70
	mov r0, sb
	adds r1, r4, #0
	bl FUN_080dac24
	ldrh r1, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5]
_080DAF70:
	ldrh r1, [r5]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080DB020
	strh r6, [r4, #0x3c]
	strh r2, [r4, #0x3e]
	ldrh r1, [r5]
	movs r0, #3
	rsbs r0, r0, #0
	b _080DB01A
_080DAF88:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, _080DAF9C @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080DAFA0
	movs r0, #1
	b _080DAFA2
	.align 2, 0
_080DAF9C: .4byte 0x03002BE0
_080DAFA0:
	movs r0, #0
_080DAFA2:
	adds r5, r4, #0
	adds r5, #0x40
	cmp r0, #0
	bne _080DAFD0
	ldrh r1, [r5]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080DAFC4
	ldr r0, _080DAFE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080DAFE4 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bgt _080DAFD0
_080DAFC4:
	adds r0, r4, #0
	bl FUN_080dad94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DAFE8
_080DAFD0:
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DAFF6
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	b _080DAFF6
	.align 2, 0
_080DAFE0: .4byte 0x030046A0
_080DAFE4: .4byte 0x00000942
_080DAFE8:
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _080DAFF6
	adds r0, r7, #0
	movs r1, #0
	bl Video_RemoveAuxSpriteFromDrawList
_080DAFF6:
	ldrh r1, [r5]
	movs r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080DB020
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DB010
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DB010:
	movs r0, #0
	strh r0, [r4, #0x3c]
	strh r6, [r4, #0x3e]
	ldrh r1, [r5]
	subs r0, #3
_080DB01A:
	ands r0, r1
	strh r0, [r5]
	b _080DB034
_080DB020:
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	movs r0, #0x50
	ands r0, r1
	cmp r0, #0
	bne _080DB034
	adds r0, r4, #0
	bl FUN_080db0f8
_080DB034:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080db040
FUN_080db040: @ 0x080DB040
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	ldrb r0, [r5, #4]
	cmp r0, #0
	bne _080DB056
	adds r0, r5, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DB056:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0x12
	bne _080DB06C
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #0x51
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
_080DB06C:
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	movs r2, #2
	cmp r0, #0x3c
	bgt _080DB07E
	movs r2, #0
	cmp r0, #0x28
	ble _080DB07E
	movs r2, #1
_080DB07E:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	ldr r1, _080DB0A4 @ =0x085AD310
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _080DB0AC
	ldr r1, [r7]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080DB0A8
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _080DB0AA
	.align 2, 0
_080DB0A4: .4byte 0x085AD310
_080DB0A8:
	orrs r1, r2
_080DB0AA:
	str r1, [r7]
_080DB0AC:
	ldrh r1, [r5, #0x3c]
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	cmp r0, #0x5a
	ble _080DB0EC
	adds r6, r5, #0
	adds r6, #0x42
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4, #0x38]
	bics r0, r1
	str r0, [r4, #0x38]
	movs r4, #0
	strh r4, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x4c
	bl Hitbox_Unregister
	adds r0, r7, #0
	movs r1, #0
	bl Video_RemoveAuxSpriteFromDrawList
	ldr r0, _080DB0E8 @ =0x0000FFFF
	strh r0, [r6]
	adds r0, r5, #0
	adds r0, #0x40
	strh r4, [r0]
	b _080DB0F0
	.align 2, 0
_080DB0E8: .4byte 0x0000FFFF
_080DB0EC:
	adds r0, r1, #1
	strh r0, [r5, #0x3c]
_080DB0F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db0f8
FUN_080db0f8: @ 0x080DB0F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _080DB174 @ =0x03002BE0
	mov sb, r0
	ldr r5, [r0]
	cmp r5, #0
	bne _080DB110
	b _080DB24C
_080DB110:
	add r2, sp, #4
	adds r3, r6, #0
	adds r3, #0x9c
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r1, [r5, #0x2c]
	ldrh r0, [r3]
	subs r1, r1, r0
	mov ip, r1
	mov r1, ip
	strh r1, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r2, #4]
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r7, r2, #0
	mov r8, r3
	cmp r0, #0
	bge _080DB144
	rsbs r0, r0, #0
_080DB144:
	cmp r0, #0x1f
	bgt _080DB1CA
	mov r0, ip
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe0
	bhi _080DB1CA
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa0
	bgt _080DB1CA
	movs r0, #0x3a
	rsbs r0, r0, #0
	cmp r1, r0
	blt _080DB1CA
	ldr r0, _080DB178 @ =0x000003FF
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080DB17C
	movs r0, #0
	b _080DB1C6
	.align 2, 0
_080DB174: .4byte 0x03002BE0
_080DB178: .4byte 0x000003FF
_080DB17C:
	adds r0, r6, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	strb r0, [r4]
	adds r2, r6, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x48
	strh r1, [r0]
	movs r1, #6
	mov r0, sp
	strh r1, [r0]
	movs r0, #2
	movs r1, #1
	mov r2, sp
	bl FUN_080ec7e8
	ldr r0, _080DB25C @ =0x00000115
	bl PlaySound_082406e0
	movs r0, #1
_080DB1C6:
	cmp r0, #0
	bne _080DB24C
_080DB1CA:
	adds r0, r7, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _080DB24C
	bl FUN_08086850
	cmp r0, #0
	beq _080DB24C
	ldrh r0, [r7]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	add r1, sp, #4
	strh r0, [r1]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r1, [r7, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	movs r4, #2
	ldrsh r0, [r7, r4]
	cmp r0, #0
	bge _080DB202
	rsbs r0, r0, #0
_080DB202:
	cmp r0, #0x1f
	bgt _080DB24C
	ldrh r0, [r7]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe0
	bhi _080DB24C
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa0
	bgt _080DB24C
	movs r0, #0x3a
	rsbs r0, r0, #0
	cmp r1, r0
	blt _080DB24C
	bl FUN_08086878
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080DB24C
	adds r0, r6, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_0808689c
	adds r2, r6, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080DB25C @ =0x00000115
	bl PlaySound_082406e0
_080DB24C:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DB25C: .4byte 0x00000115

	thumb_func_start FUN_080db260
FUN_080db260: @ 0x080DB260
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _080DB284
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _080DB28A
_080DB284:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_080DB28A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db290
FUN_080db290: @ 0x080DB290
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov sb, r1
	bl FUN_080dad4c
	adds r7, r0, #0
	cmp r7, #0
	bne _080DB2B0
	movs r0, #1
	rsbs r0, r0, #0
	b _080DB42C
_080DB2B0:
	movs r5, #0
	movs r0, #1
	strh r0, [r7, #0x3e]
	movs r1, #5
	add r1, sp
	mov r8, r1
	mov r0, sb
	add r1, sp, #4
	mov r2, r8
	bl FUN_080db260
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	adds r0, r4, #0
	bl GetMapAreaAt
	movs r1, #0x46
	adds r1, r1, r7
	mov sl, r1
	strh r0, [r1]
	movs r2, #0x40
	adds r2, r2, r7
	mov sb, r2
	strh r5, [r2]
	adds r0, r7, #0
	adds r0, #0x48
	strh r5, [r0]
	str r7, [sp, #8]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Setup
	subs r4, #0x70
	ldr r1, [r6, #0x34]
	mov r2, r8
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	mov r8, sl
	mov r6, sb
	cmp r2, r0
	beq _080DB34A
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DB352
_080DB34A:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB352:
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
	beq _080DB378
	ldr r2, [sp, #8]
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080DB384
_080DB378:
	ldr r1, [sp, #8]
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp, #8]
_080DB384:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DB3BC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DB3F4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB3C0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DB3B4
	ldrb r0, [r4, #5]
_080DB3B4:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DB3D0
	.align 2, 0
_080DB3BC: .4byte 0x0000FFFF
_080DB3C0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DB3D0
	strh r1, [r4, #8]
_080DB3D0:
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
	bne _080DB3F4
	movs r0, #1
	strb r0, [r4, #7]
_080DB3F4:
	ldr r1, [sp, #8]
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp, #8]
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #7]
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_0809dfec
	cmp r0, #0
	beq _080DB41A
	ldrh r1, [r6]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r6]
_080DB41A:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dacc4
	adds r0, r7, #0
	adds r0, #0x42
	movs r2, #0
	ldrsh r0, [r0, r2]
_080DB42C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity080db520_Update
Entity080db520_Update: @ 0x080DB43C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _080DB48E
	movs r5, #0
	ldr r7, _080DB460 @ =0x085AD314
_080DB44E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB464
	movs r0, #1
	b _080DB466
	.align 2, 0
_080DB460: .4byte 0x085AD314
_080DB464:
	movs r0, #0
_080DB466:
	cmp r0, #0
	beq _080DB482
	movs r0, #0xa4
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, r1, r6
	movs r2, #0x3e
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
_080DB482:
	adds r5, #1
	cmp r5, #7
	ble _080DB44E
	adds r0, r4, #0
	bl FUN_080dadec
_080DB48E:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080db520_Destroy
Entity080db520_Destroy: @ 0x080DB498
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_080DB49E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB4AE
	movs r0, #1
	b _080DB4B0
_080DB4AE:
	movs r0, #0
_080DB4B0:
	cmp r0, #0
	beq _080DB4D0
	movs r0, #0xa4
	muls r0, r5, r0
	adds r0, #0x3c
	adds r4, r6, r0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080DB4C8
	adds r0, r4, #0
	bl AuxSprite_Remove
_080DB4C8:
	adds r0, r4, #0
	adds r0, #0x4c
	bl Hitbox_Unregister
_080DB4D0:
	adds r5, #1
	cmp r5, #7
	ble _080DB49E
	ldr r1, _080DB4E4 @ =0x03000160
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080DB4E4: .4byte 0x03000160

	thumb_func_start Entity080db520_Init
Entity080db520_Init: @ 0x080DB4E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DB510 @ =0x00001C1B
	bl Video_GetAuxSprite
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _080DB514 @ =0x0000922E
	ldr r1, _080DB518 @ =0x00003DC2
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DB51C @ =0x03000160
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DB510: .4byte 0x00001C1B
_080DB514: .4byte 0x0000922E
_080DB518: .4byte 0x00003DC2
_080DB51C: .4byte 0x03000160

	thumb_func_start Entity080db520_Create
Entity080db520_Create: @ 0x080DB520
	push {r4, lr}
	ldr r0, _080DB554 @ =0x03000160
	ldr r0, [r0]
	cmp r0, #0
	bne _080DB566
	ldr r1, _080DB558 @ =0x0000055C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DB564
	ldr r1, _080DB55C @ =Entity080db520_Update
	ldr r2, _080DB560 @ =Entity080db520_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080db520_Init
	cmp r0, #0
	bge _080DB564
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DB566
	.align 2, 0
_080DB554: .4byte 0x03000160
_080DB558: .4byte 0x0000055C
_080DB55C: .4byte Entity080db520_Update
_080DB560: .4byte Entity080db520_Destroy
_080DB564:
	adds r0, r4, #0
_080DB566:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080db56c
FUN_080db56c: @ 0x080DB56C
	ldr r1, _080DB574 @ =0x03000160
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DB574: .4byte 0x03000160

	thumb_func_start FUN_080db578
FUN_080db578: @ 0x080DB578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080DB5C4 @ =0x03000160
	ldr r6, [r0]
	cmp r6, #0
	bne _080DB598
	bl Entity080db520_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _080DB598
	b _080DB770
_080DB598:
	adds r0, r6, #0
	bl FUN_080dad4c
	adds r7, r0, #0
	cmp r7, #0
	bne _080DB5A6
	b _080DB770
_080DB5A6:
	movs r0, #1
	strh r0, [r7, #0x3e]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _080DB602
	bl VM_GetPC
	cmp r0, #0
	beq _080DB5C8
	bl Script_GetValue
	b _080DB5CA
	.align 2, 0
_080DB5C4: .4byte 0x03000160
_080DB5C8:
	movs r0, #0
_080DB5CA:
	adds r4, r7, #0
	adds r4, #0x9c
	strh r0, [r4]
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _080DB5E0
	bl Script_GetValue
	b _080DB5E2
_080DB5E0:
	movs r0, #0
_080DB5E2:
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _080DB5F8
	bl Script_GetValue
	adds r1, r0, #0
	b _080DB5FA
_080DB5F8:
	movs r1, #0
_080DB5FA:
	adds r0, r7, #0
	adds r0, #0xa0
	strh r1, [r0]
	b _080DB614
_080DB602:
	adds r1, r7, #0
	adds r1, #0x9c
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9e
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r5, r1, #0
_080DB614:
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	bl GetMapAreaAt
	movs r1, #0x46
	adds r1, r1, r7
	mov r8, r1
	movs r1, #0
	mov r2, r8
	strh r0, [r2]
	movs r0, #0x40
	adds r0, r0, r7
	mov sl, r0
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x48
	strh r1, [r0]
	mov sb, r7
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Setup
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r6, #0x34]
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r6, sl
	cmp r2, r0
	beq _080DB698
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DB6A0
_080DB698:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB6A0:
	str r0, [r7]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB6C6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080DB6D0
_080DB6C6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DB6D0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080DB708 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _080DB740
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB70C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080DB702
	ldrb r0, [r5, #5]
_080DB702:
	subs r0, #1
	strh r0, [r5, #8]
	b _080DB71C
	.align 2, 0
_080DB708: .4byte 0x0000FFFF
_080DB70C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080DB71C
	strh r1, [r5, #8]
_080DB71C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB740
	movs r0, #1
	strb r0, [r5, #7]
_080DB740:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #7]
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_0809dfec
	cmp r0, #0
	beq _080DB766
	ldrh r1, [r6]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r6]
_080DB766:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dacc4
_080DB770:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080db780
FUN_080db780: @ 0x080DB780
	push {r4, r5, r6, lr}
	ldr r0, _080DB79C @ =0x03000160
	ldr r5, [r0]
	cmp r5, #0
	beq _080DB7DE
	movs r4, #0
_080DB78C:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB7A0
	movs r0, #1
	b _080DB7A2
	.align 2, 0
_080DB79C: .4byte 0x03000160
_080DB7A0:
	movs r0, #0
_080DB7A2:
	cmp r0, #0
	beq _080DB7D8
	movs r0, #0xa4
	muls r0, r4, r0
	adds r0, #0x3c
	adds r3, r5, r0
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DB7D8
	movs r1, #0x3e
	ldrsh r0, [r3, r1]
	cmp r0, #2
	beq _080DB7D8
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
_080DB7D8:
	adds r4, #1
	cmp r4, #7
	ble _080DB78C
_080DB7DE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
