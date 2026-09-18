	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08005d78
FUN_08005d78: @ 0x08005D78
	ldr r1, _08005D80 @ =0x0300002C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08005D80: .4byte 0x0300002C

	thumb_func_start FUN_08005d84
FUN_08005d84: @ 0x08005D84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r4, r0, #0
	adds r7, r2, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r6, #0
	beq _08005DB4
	movs r1, #4
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08005DB4
	adds r2, r1, #0
	movs r3, #0xc
	ldr r1, _08005DBC @ =0x03002BC0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r3
	adds r5, r2, #0
	cmp r0, #0
	beq _08005DC0
_08005DB4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08005E24
	.align 2, 0
_08005DBC: .4byte 0x03002BC0
_08005DC0:
	ldrb r0, [r4, #5]
	cmp r0, #1
	bne _08005DD6
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
	adds r0, #0x40
	b _08005DE2
_08005DD6:
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
_08005DE2:
	str r0, [sp, #4]
	movs r2, #4
	ldrsh r0, [r1, r2]
	str r0, [sp, #8]
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x10]
	add r2, sp, #0x28
	adds r4, #0x38
	add r3, sp, #0x14
	movs r1, #2
_08005DFE:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005DFE
	str r5, [sp, #0x20]
	str r7, [sp, #0x24]
	ldr r1, _08005E2C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	str r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	bl Script_ExecById
_08005E24:
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005E2C: .4byte 0xFFFF0000

	thumb_func_start FUN_08005e30
FUN_08005e30: @ 0x08005E30
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r1, #4
	ldr r3, _08005E58 @ =0x0300002C
	ldr r0, [r3]
	ldr r0, [r0, #0x28]
	str r0, [r1]
	cmp r0, #0
	beq _08005E4E
	adds r0, #0xb4
	str r2, [r0]
_08005E4E:
	ldr r0, [r3]
	str r2, [r0, #0x28]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08005E58: .4byte 0x0300002C

	thumb_func_start FUN_08005e5c
FUN_08005e5c: @ 0x08005E5C
	push {lr}
	adds r1, r0, #0
	adds r1, #0xb4
	ldr r1, [r1]
	adds r0, #0xb8
	ldr r2, [r0]
	cmp r1, #0
	beq _08005E74
	adds r0, r1, #0
	adds r0, #0xb8
	str r2, [r0]
	b _08005E7A
_08005E74:
	ldr r0, _08005E8C @ =0x0300002C
	ldr r0, [r0]
	str r2, [r0, #0x28]
_08005E7A:
	cmp r2, #0
	beq _08005E84
	adds r0, r2, #0
	adds r0, #0xb4
	str r1, [r0]
_08005E84:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08005E8C: .4byte 0x0300002C

	thumb_func_start FUN_08005e90
FUN_08005e90: @ 0x08005E90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08005e5c
	adds r0, r4, #0
	adds r0, #0x48
	bl AuxShadow_Remove
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _08005EAA
	bl Free
_08005EAA:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _08005EB4
	bl Free
_08005EB4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _08005EC4
	bl FUN_0822dabc
	ldr r0, [r4, #0x1c]
	bl Free
_08005EC4:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _08005ED4
	bl FUN_0822a4e0
	ldr r0, [r4, #0x20]
	bl Free
_08005ED4:
	adds r0, r4, #0
	bl Free
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005ee4
FUN_08005ee4: @ 0x08005EE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	beq _08005F42
	subs r0, #1
	strb r0, [r7, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08005F06
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x10]
	strh r0, [r1]
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x12]
	strh r0, [r1, #4]
	b _08005F42
_08005F06:
	ldr r6, _08005F48 @ =0x0203B400
	ldr r3, _08005F4C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _08005F50 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r4, [r7, #0x2c]
	movs r2, #0xf
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	subs r0, #4
	strh r0, [r4]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ldr r2, [r7, #0x2c]
	movs r1, #7
	ands r0, r1
	ldrh r7, [r7, #0x12]
	adds r0, r0, r7
	subs r0, #4
	strh r0, [r2, #4]
_08005F42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005F48: .4byte 0x0203B400
_08005F4C: .4byte 0x030046B8
_08005F50: .4byte 0x000003FF

	thumb_func_start FUN_08005f54
FUN_08005f54: @ 0x08005F54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov sl, r0
	adds r5, r1, #0
	add r7, sp, #0x10
	ldr r3, [r5, #0x2c]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r6, r1, #0x11
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x11
	subs r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F84
	asrs r1, r1, #8
	b _08005F8A
_08005F84:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005F8A:
	strh r1, [r7]
	adds r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F9C
	asrs r1, r1, #8
	b _08005FA2
_08005F9C:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005FA2:
	adds r4, r1, #0
	movs r1, #2
	ldrsh r2, [r3, r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	cmp r1, #0
	blt _08005FB6
	asrs r2, r1, #8
	b _08005FBC
_08005FB6:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r2, r1, #0
_08005FBC:
	subs r1, r4, r2
	strh r1, [r7, #2]
	adds r1, r4, r2
	strh r1, [r7, #4]
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	beq _08005FE2
	subs r1, #1
	strb r1, [r5, #0xd]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08005FE2
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
_08005FE2:
	movs r2, #1
	str r2, [sp, #0x20]
	movs r6, #0
	mov r8, r6
	mov r7, sl
	adds r7, #0x2c
	str r7, [sp, #0x24]
	add r1, sp, #0x10
	mov sb, r1
_08005FF4:
	mov r2, r8
	lsls r3, r2, #2
	ldr r6, [sp, #0x24]
	adds r1, r6, r3
	ldr r6, [r1]
	cmp r6, #0
	bne _08006004
	b _08006170
_08006004:
	movs r1, #0xc
	ldr r2, _080060F4 @ =0x03002BC0
	adds r2, r3, r2
	ldr r2, [r2]
	ands r2, r1
	cmp r2, #0
	beq _08006014
	b _08006170
_08006014:
	ldr r3, [r5, #0x2c]
	mov r7, r8
	lsls r1, r7, #3
	mov r2, sl
	adds r4, r1, r2
	adds r4, #0x3c
	mov r7, sb
	movs r1, #2
	ldrsh r2, [r7, r1]
	movs r7, #2
	ldrsh r1, [r4, r7]
	subs r2, r2, r1
	mov ip, r2
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r7, #0x2e
	ldrsh r1, [r6, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _0800603E
	rsbs r1, r1, #0
_0800603E:
	cmp r1, #0x7f
	bgt _08006068
	mov r1, sb
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r7, #0
	ldrsh r1, [r4, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _08006054
	rsbs r1, r1, #0
_08006054:
	cmp r1, #0xe
	bgt _08006068
	movs r1, #0x18
	rsbs r1, r1, #0
	cmp ip, r1
	blt _08006068
	movs r1, #1
	mov r2, ip
	cmp r2, #4
	ble _0800606A
_08006068:
	movs r1, #0
_0800606A:
	cmp r1, #0
	bne _08006070
	b _08006170
_08006070:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080060F8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _080060FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006100
	movs r6, #0
	ldrsh r0, [r5, r6]
	movs r7, #2
	ldrsh r1, [r5, r7]
	bl CheckEmptySlotExist
	adds r1, r0, #0
	cmp r1, #0
	bne _08006100
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0800616C
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	bne _0800616C
	movs r2, #0
	ldrsh r1, [r5, r2]
	cmp r1, #3
	bgt _080060DE
	adds r0, r1, #0
	movs r7, #2
	ldrsh r1, [r5, r7]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #1
	mov r3, r8
	bl FUN_080177b4
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080060DE:
	movs r1, #0x24
	strb r1, [r5, #0xd]
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
	b _0800616C
	.align 2, 0
_080060F4: .4byte 0x03002BC0
_080060F8: .4byte 0x0000FFFF
_080060FC: .4byte 0x030047A4
_08006100:
	mov r0, r8
	strb r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #3
	bgt _08006124
	movs r6, #2
	ldrsh r1, [r5, r6]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #0
	mov r3, r8
	bl FUN_080177b4
_08006124:
	ldr r6, _08006168 @ =0x030047A4
	ldr r0, [r6]
	movs r4, #0x80
	lsls r4, r4, #4
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
	ldr r0, [r6]
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r2, #2
	ldrsh r1, [r5, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006156
_08006154:
	movs r2, #1
_08006156:
	ldrh r1, [r5, #0x34]
	adds r0, r5, #0
	bl FUN_08005d84
	ldrb r2, [r5, #6]
	movs r1, #1
	orrs r1, r2
	strb r1, [r5, #6]
	b _0800617C
	.align 2, 0
_08006168: .4byte 0x030047A4
_0800616C:
	movs r6, #0
	str r6, [sp, #0x20]
_08006170:
	movs r7, #1
	add r8, r7
	mov r1, r8
	cmp r1, #3
	bgt _0800617C
	b _08005FF4
_0800617C:
	add r2, sp, #0x20
	ldrb r2, [r2]
	strb r2, [r5, #0xe]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08006194
FUN_08006194: @ 0x08006194
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08006254 @ =0x0300002C
	ldr r6, [r0]
	cmp r6, #0
	bne _080061AA
	b _080062C2
_080061AA:
	ldrb r0, [r7, #4]
	mov r8, r0
	ldr r4, [r6, #0x28]
	cmp r4, #0
	bne _080061B6
	b _080062C2
_080061B6:
	movs r1, #0
	mov sb, r1
_080061BA:
	ldrb r1, [r4, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0800624C
	ldrh r1, [r4, #4]
	ldr r0, _08006258 @ =0x000001FF
	cmp r1, r0
	bne _0800624C
	adds r3, r7, #0
	adds r3, #8
	ldr r2, [r4, #0x2c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #8
	ldrsh r0, [r7, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061E2
	rsbs r1, r1, #0
_080061E2:
	cmp r1, #0x5f
	bgt _08006210
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r5, #2
	ldrsh r0, [r3, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061F6
	rsbs r1, r1, #0
_080061F6:
	cmp r1, #0x7f
	bgt _08006210
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0800620A
	rsbs r1, r1, #0
_0800620A:
	movs r0, #1
	cmp r1, #0x5f
	ble _08006212
_08006210:
	movs r0, #0
_08006212:
	cmp r0, #0
	beq _0800624C
	ldr r1, _0800625C @ =0x03002BE0
	mov r5, r8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08006260
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08006260
	ldrb r0, [r4, #0x15]
	cmp r0, #1
	bne _08006260
	adds r5, r6, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	bne _0800624C
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xf
	strb r0, [r5]
_0800624C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r4, [r0]
	b _080062BC
	.align 2, 0
_08006254: .4byte 0x0300002C
_08006258: .4byte 0x000001FF
_0800625C: .4byte 0x03002BE0
_08006260:
	mov r2, r8
	strb r2, [r4, #4]
	ldr r0, _080062B0 @ =0x0000010F
	bl PlaySound_0824078c
	ldr r0, _080062B4 @ =FUN_0800676c
	str r0, [r4, #0x44]
	mov r5, sb
	str r5, [r4, #0x18]
	strb r5, [r4, #9]
	ldr r0, [r4, #0x28]
	ldr r1, [r6, #0x1c]
	str r5, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _080062B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080062A2
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _080062A4
_080062A2:
	movs r2, #1
_080062A4:
	ldrh r1, [r4, #0x30]
	adds r0, r4, #0
	bl FUN_08005d84
	movs r0, #1
	b _080062C4
	.align 2, 0
_080062B0: .4byte 0x0000010F
_080062B4: .4byte FUN_0800676c
_080062B8: .4byte 0x030047A4
_080062BC:
	cmp r4, #0
	beq _080062C2
	b _080061BA
_080062C2:
	movs r0, #0
_080062C4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080062d4
FUN_080062d4: @ 0x080062D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	ldr r0, [r5, #0x2c]
	movs r1, #2
	ldrsh r7, [r0, r1]
	adds r6, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800630A
	cmp r1, #0
	blt _0800630A
	ldr r0, _08006310 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800630A
	ldr r0, _08006314 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08006318
_0800630A:
	movs r4, #0
	b _08006326
	.align 2, 0
_08006310: .4byte 0x030046A8
_08006314: .4byte 0x030046AC
_08006318:
	ldr r0, _08006338 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08006326:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800633C
	adds r0, #4
	b _08006348
	.align 2, 0
_08006338: .4byte 0x030046A4
_0800633C:
	ldr r0, _0800635C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08006348:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08006360
	cmp r3, #2
	beq _08006364
	b _08006368
	.align 2, 0
_0800635C: .4byte 0x030046A4
_08006360:
	ldrb r0, [r6, #4]
	b _08006366
_08006364:
	ldrb r0, [r6]
_08006366:
	subs r2, r2, r0
_08006368:
	subs r0, r7, r2
	cmp r0, #0
	ble _0800638E
	ldr r2, [r5, #0x2c]
	adds r1, r0, #0
	cmp r1, #0x20
	ble _08006378
	movs r1, #0x20
_08006378:
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08005f54
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	b _0800639C
_0800638E:
	ldr r1, [r5, #0x2c]
	adds r0, r2, #1
	movs r2, #0
	strh r0, [r1, #2]
	ldr r0, _080063A8 @ =FUN_080063ac
	str r0, [r5, #0x44]
	str r2, [r5, #0x18]
_0800639C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080063A8: .4byte FUN_080063ac

	thumb_func_start FUN_080063ac
FUN_080063ac: @ 0x080063AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r6, [r4, #0x2c]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080063D8
	cmp r1, #0
	blt _080063D8
	ldr r0, _080063DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080063D8
	ldr r0, _080063E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080063E4
_080063D8:
	movs r5, #0
	b _080063F2
	.align 2, 0
_080063DC: .4byte 0x030046A8
_080063E0: .4byte 0x030046AC
_080063E4:
	ldr r0, _08006404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080063F2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08006408
	adds r0, #4
	b _08006414
	.align 2, 0
_08006404: .4byte 0x030046A4
_08006408:
	ldr r0, _08006428 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08006414:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0800642C
	cmp r3, #2
	beq _08006430
	b _08006434
	.align 2, 0
_08006428: .4byte 0x030046A4
_0800642C:
	ldrb r0, [r6, #4]
	b _08006432
_08006430:
	ldrb r0, [r6]
_08006432:
	subs r2, r2, r0
_08006434:
	ldr r0, [r4, #0x18]
	cmp r0, #2
	bhi _08006442
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _0800646A
_08006442:
	cmp r0, #5
	bls _08006464
	ldr r0, _08006460 @ =FUN_080065a4
	str r0, [r4, #0x44]
	movs r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x2c]
	adds r0, r2, #1
	strh r0, [r1, #2]
	adds r0, r4, #0
	adds r0, #0x48
	bl AuxShadow_Hide
	b _08006480
	.align 2, 0
_08006460: .4byte FUN_080065a4
_08006464:
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_0800646A:
	strh r0, [r1, #2]
	adds r0, r4, #0
	bl FUN_08005ee4
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08005f54
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_08006480:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006488
FUN_08006488: @ 0x08006488
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080064BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080064C4
_080064BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080064C4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080064E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080064F0
_080064E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080064F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006528 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006560
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800652C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006520
	ldrb r0, [r4, #5]
_08006520:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800653C
	.align 2, 0
_08006528: .4byte 0x0000FFFF
_0800652C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800653C
	strh r1, [r4, #8]
_0800653C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006560
	movs r0, #1
	strb r0, [r4, #7]
_08006560:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006570
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006570:
	ldr r0, [r7, #0x18]
	cmp r0, #3
	bhi _0800657E
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _08006596
_0800657E:
	cmp r0, #7
	bls _08006590
	ldr r0, _0800658C @ =FUN_08006678
	str r0, [r7, #0x44]
	movs r0, #0
	b _0800659C
	.align 2, 0
_0800658C: .4byte FUN_08006678
_08006590:
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_08006596:
	strh r0, [r1, #2]
	ldr r0, [r7, #0x18]
	adds r0, #1
_0800659C:
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080065a4
FUN_080065a4: @ 0x080065A4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r2, [r4, #8]
	cmp r2, #0
	bne _080065C8
	ldr r1, [r4, #0x18]
	ldr r0, _080065C0 @ =0x00000383
	cmp r1, r0
	bls _080065C8
	ldr r0, _080065C4 @ =FUN_08006640
	str r0, [r4, #0x44]
	str r2, [r4, #0x18]
	b _08006636
	.align 2, 0
_080065C0: .4byte 0x00000383
_080065C4: .4byte FUN_08006640
_080065C8:
	ldr r0, [r4, #0x18]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _08006622
	ldr r0, [r4, #0x2c]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080065F8
	cmp r1, #0
	blt _080065F8
	ldr r0, _080065FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080065F8
	ldr r0, _08006600 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08006604
_080065F8:
	movs r0, #0
	b _08006612
	.align 2, 0
_080065FC: .4byte 0x030046A8
_08006600: .4byte 0x030046AC
_08006604:
	ldr r0, _0800663C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08006612:
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08006622
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r4, #0x18]
_08006622:
	adds r0, r4, #0
	bl FUN_08005ee4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08005f54
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_08006636:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800663C: .4byte 0x030046A4

	thumb_func_start FUN_08006640
FUN_08006640: @ 0x08006640
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0x2d
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006662
	ldrb r1, [r4, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #6]
	b _0800666A
_08006662:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08005f54
_0800666A:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006678
FUN_08006678: @ 0x08006678
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080066AC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080066B4
_080066AC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080066B4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080066D8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080066E0
_080066D8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080066E0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006718 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006750
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800671C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006710
	ldrb r0, [r4, #5]
_08006710:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800672C
	.align 2, 0
_08006718: .4byte 0x0000FFFF
_0800671C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800672C
	strh r1, [r4, #8]
_0800672C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006750
	movs r0, #1
	strb r0, [r4, #7]
_08006750:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006760
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006760:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800676c
FUN_0800676c: @ 0x0800676C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r1, #0
	ldr r5, [r6, #0x20]
	ldr r4, [r6, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080067A2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080067AA
_080067A2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080067AA:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080067CE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080067D6
_080067CE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080067D6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006810 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006856
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800681A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006814
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006830
	.align 2, 0
_08006810: .4byte 0x0000FFFF
_08006814:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800682E
_0800681A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800682E
	strh r1, [r4, #8]
	movs r3, #1
	b _08006830
_0800682E:
	movs r3, #0
_08006830:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _08006858
	movs r0, #1
	strb r0, [r4, #7]
	b _08006858
_08006856:
	movs r3, #0
_08006858:
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08006868
	ldr r0, [r6, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006868:
	cmp r3, #0
	beq _08006920
	ldr r0, [r6, #0x2c]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080068CC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, _080068D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl CheckEmptySlotExist
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068C6
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #1
	bl FUN_080177b4
_080068C6:
	ldr r0, _080068D4 @ =FUN_08006a80
	b _080068FC
	.align 2, 0
_080068CC: .4byte 0x0000FFFF
_080068D0: .4byte 0x030047A4
_080068D4: .4byte FUN_08006a80
_080068D8:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068FA
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #0
	bl FUN_080177b4
_080068FA:
	ldr r0, _08006918 @ =FUN_08006930
_080068FC:
	str r0, [r6, #0x44]
	movs r2, #0
	str r2, [r6, #0x18]
	ldr r0, [r6, #0x28]
	ldr r1, _0800691C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	str r2, [sp]
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _08006926
	.align 2, 0
_08006918: .4byte FUN_08006930
_0800691C: .4byte 0x0300002C
_08006920:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
_08006926:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006930
FUN_08006930: @ 0x08006930
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006964
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0800696C
_08006964:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800696C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006990
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006998
_08006990:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006998:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080069D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006A08
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080069D4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080069C8
	ldrb r0, [r4, #5]
_080069C8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080069E4
	.align 2, 0
_080069D0: .4byte 0x0000FFFF
_080069D4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080069E4
	strh r1, [r4, #8]
_080069E4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006A08
	movs r0, #1
	strb r0, [r4, #7]
_08006A08:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006A18
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006A18:
	ldr r1, [r7, #0x18]
	cmp r1, #8
	bne _08006A58
	ldr r0, _08006A54 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006A34
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08006A34:
	ldrh r4, [r7, #0x34]
	movs r1, #0
	ldrsh r0, [r7, r1]
	movs r2, #2
	ldrsh r1, [r7, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006A4A
	movs r2, #1
_08006A4A:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08005d84
	b _08006A74
	.align 2, 0
_08006A54: .4byte 0x030047A4
_08006A58:
	cmp r1, #8
	bls _08006A74
	ldr r0, [r7, #0x20]
	movs r2, #0x1e
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006A74
	ldrb r1, [r7, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #6]
_08006A74:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08006a80
FUN_08006a80: @ 0x08006A80
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006AB6
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006ABE
_08006AB6:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006ABE:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006AE2
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006AEA
_08006AE2:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006AEA:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006B20 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006B58
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006B24
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006B1A
	ldrb r0, [r4, #5]
_08006B1A:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006B34
	.align 2, 0
_08006B20: .4byte 0x0000FFFF
_08006B24:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006B34
	strh r1, [r4, #8]
_08006B34:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006B58
	movs r0, #1
	strb r0, [r4, #7]
_08006B58:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006B68
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006B68:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1f
	bls _08006B8A
	ldr r0, _08006B98 @ =FUN_08006ba0
	str r0, [r7, #0x44]
	movs r0, #0
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x28]
	ldr r1, _08006B9C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
_08006B8A:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006B98: .4byte FUN_08006ba0
_08006B9C: .4byte 0x0300002C

	thumb_func_start FUN_08006ba0
FUN_08006ba0: @ 0x08006BA0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006BD8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006BE0
_08006BD8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006BE0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006C04
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006C0C
_08006C04:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006C0C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006C44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08006C8A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006C4E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006C48
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006C64
	.align 2, 0
_08006C44: .4byte 0x0000FFFF
_08006C48:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006C62
_08006C4E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006C62
	strh r1, [r4, #8]
	movs r3, #1
	b _08006C64
_08006C62:
	movs r3, #0
_08006C64:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006C8C
	movs r0, #1
	strb r0, [r4, #7]
	b _08006C8C
_08006C8A:
	movs r3, #0
_08006C8C:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006C9C
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006C9C:
	cmp r3, #0
	beq _08006CC0
	ldr r0, _08006CBC @ =FUN_08006678
	str r0, [r7, #0x44]
	movs r2, #0
	str r2, [r7, #0x18]
	movs r0, #0xff
	strb r0, [r7, #4]
	ldr r0, [r7, #0x28]
	mov r3, ip
	ldr r1, [r3, #0x1c]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	b _08006CC6
	.align 2, 0
_08006CBC: .4byte FUN_08006678
_08006CC0:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
_08006CC6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0800704c_Update
Entity0800704c_Update: @ 0x08006CD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	movs r6, #0
	ldr r0, _08006D20 @ =0x03002BE0
	mov r8, r0
_08006CE2:
	lsls r1, r6, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	mov r0, sl
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _08006D64
	lsls r0, r6, #3
	mov r7, sl
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r2, #0
	adds r5, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D24
	asrs r0, r0, #8
	b _08006D2A
	.align 2, 0
_08006D20: .4byte 0x03002BE0
_08006D24:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D2A:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D3C
	asrs r0, r0, #8
	b _08006D42
_08006D3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D42:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08006D56
	asrs r1, r0, #8
	b _08006D5C
_08006D56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08006D5C:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_08006D64:
	adds r6, #1
	cmp r6, #3
	ble _08006CE2
	mov r1, sl
	ldr r3, [r1, #0x28]
	movs r2, #0x24
	add r2, sl
	mov sb, r2
	cmp r3, #0
	bne _08006D7A
	b _08006F3C
_08006D7A:
	movs r5, #1
	movs r6, #2
	rsbs r6, r6, #0
_08006D80:
	adds r0, r3, #0
	adds r0, #0xb8
	ldr r0, [r0]
	mov r8, r0
	ldrb r1, [r3, #6]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08006D9A
	adds r0, r3, #0
	bl FUN_08005e90
	b _08006F34
_08006D9A:
	ldrh r0, [r3, #0x16]
	cmp r0, #0
	beq _08006DC4
	ldr r0, _08006DB8 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0x92
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r1, [r3, #0x16]
	cmp r0, r1
	bne _08006DBC
	movs r0, #1
	b _08006DBE
	.align 2, 0
_08006DB8: .4byte 0x030046A0
_08006DBC:
	movs r0, #0
_08006DBE:
	cmp r0, #0
	bne _08006DC4
	b _08006F12
_08006DC4:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006DD0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
_08006DD0:
	ldr r1, [r3, #0x20]
	adds r4, r1, #0
	cmp r1, #0
	bne _08006DDA
	b _08006F2A
_08006DDA:
	ldrb r0, [r3, #9]
	cmp r0, #0
	bne _08006DE2
	b _08006F0C
_08006DE2:
	ldr r0, _08006DFC @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _08006E00
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0
	strb r0, [r3, #0xb]
_08006DF4:
	strb r0, [r3, #0xc]
_08006DF6:
	strb r5, [r3, #0xa]
	b _08006F2A
	.align 2, 0
_08006DFC: .4byte 0x03002B48
_08006E00:
	ldr r0, _08006E34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08006E48
	ldr r0, _08006E38 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _08006E44
	ldr r2, _08006E3C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08006E2E
	ldr r7, _08006E40 @ =0x00000442
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E2E
	movs r2, #1
_08006E2E:
	adds r0, r2, #0
	b _08006E70
	.align 2, 0
_08006E34: .4byte 0x030047A4
_08006E38: .4byte 0x03002BE0
_08006E3C: .4byte 0x00000446
_08006E40: .4byte 0x00000442
_08006E44:
	movs r0, #0
	b _08006E70
_08006E48:
	ldr r0, _08006E9C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _08006E74
	ldr r0, _08006EA0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08006E6E
	ldr r0, _08006EA4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E6E
	movs r1, #1
_08006E6E:
	adds r0, r1, #0
_08006E70:
	cmp r0, #0
	beq _08006ED8
_08006E74:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	beq _08006E7E
	movs r0, #0x1f
	strb r0, [r3, #0xb]
_08006E7E:
	ldrb r1, [r3, #0xb]
	adds r2, r1, #0
	cmp r2, #0
	beq _08006EB0
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EA8
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ED2
	.align 2, 0
_08006E9C: .4byte 0x030046A0
_08006EA0: .4byte 0x03002B8C
_08006EA4: .4byte 0x03002B60
_08006EA8:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ED2
_08006EB0:
	ldrb r0, [r3, #0xc]
	cmp r0, #0x2f
	bhi _08006EBE
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ECC
_08006EBE:
	cmp r0, #0x47
	bhi _08006ECA
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ECC
_08006ECA:
	strb r2, [r3, #0xc]
_08006ECC:
	ldrb r0, [r3, #0xc]
	adds r0, #1
	strb r0, [r3, #0xc]
_08006ED2:
	movs r0, #0
	strb r0, [r3, #0xa]
	b _08006F2A
_08006ED8:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	bne _08006EE2
	movs r0, #0x2f
	strb r0, [r3, #0xb]
_08006EE2:
	ldrb r1, [r3, #0xb]
	cmp r1, #0
	beq _08006F04
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EFA
	ldr r0, [r4]
	orrs r0, r5
	b _08006EFE
_08006EFA:
	ldr r0, [r4]
	ands r0, r6
_08006EFE:
	str r0, [r4]
	movs r0, #0
	b _08006DF4
_08006F04:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006DF6
_08006F0C:
	ldr r0, [r1]
	ands r0, r6
	b _08006F28
_08006F12:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006F1E
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_08006F1E:
	ldr r1, [r3, #0x20]
	cmp r1, #0
	beq _08006F2A
	ldr r0, [r1]
	orrs r0, r5
_08006F28:
	str r0, [r1]
_08006F2A:
	ldr r2, [r3, #0x44]
	mov r0, sl
	adds r1, r3, #0
	bl _call_via_r2
_08006F34:
	mov r3, r8
	cmp r3, #0
	beq _08006F3C
	b _08006D80
_08006F3C:
	mov r7, sb
	ldrb r0, [r7]
	cmp r0, #0
	beq _08006F48
	subs r0, #1
	strb r0, [r7]
_08006F48:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0800704c_Destroy
Entity0800704c_Destroy: @ 0x08006F58
	push {r4, lr}
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _08006F72
_08006F60:
	adds r0, r1, #0
	adds r0, #0xb8
	ldr r4, [r0]
	adds r0, r1, #0
	bl FUN_08005e90
	adds r1, r4, #0
	cmp r1, #0
	bne _08006F60
_08006F72:
	ldr r1, _08006F80 @ =0x0300002C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08006F80: .4byte 0x0300002C

	thumb_func_start Entity0800704c_Init
Entity0800704c_Init: @ 0x08006F84
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08006FE4 @ =0x0300002C
	str r5, [r0]
	ldr r0, _08006FE8 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x18]
	movs r4, #0
	ldr r0, _08006FEC @ =0x00003876
	strh r0, [r5, #0x20]
	ldr r0, _08006FF0 @ =0x0000922E
	ldr r1, _08006FF4 @ =0x00009AF2
	bl GetFile
	str r0, [r5, #0x1c]
	str r4, [r5, #0x28]
	movs r7, #0
_08006FA8:
	ldr r0, _08006FF8 @ =0x03002BE0
	lsls r1, r7, #2
	adds r0, r1, r0
	ldr r2, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _0800703C
	lsls r0, r7, #3
	adds r3, r0, r5
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006FFC
	asrs r0, r0, #8
	b _08007002
	.align 2, 0
_08006FE4: .4byte 0x0300002C
_08006FE8: .4byte 0x00001C1A
_08006FEC: .4byte 0x00003876
_08006FF0: .4byte 0x0000922E
_08006FF4: .4byte 0x00009AF2
_08006FF8: .4byte 0x03002BE0
_08006FFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08007002:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08007014
	asrs r0, r0, #8
	b _0800701A
_08007014:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800701A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800702E
	asrs r1, r0, #8
	b _08007034
_0800702E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08007034:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_0800703C:
	adds r7, #1
	cmp r7, #3
	ble _08006FA8
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity0800704c_Create
Entity0800704c_Create: @ 0x0800704C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x5c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08007084
	ldr r1, _0800707C @ =Entity0800704c_Update
	ldr r2, _08007080 @ =Entity0800704c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0800704c_Init
	cmp r0, #0
	bge _08007084
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08007086
	.align 2, 0
_0800707C: .4byte Entity0800704c_Update
_08007080: .4byte Entity0800704c_Destroy
_08007084:
	adds r0, r4, #0
_08007086:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800708c
FUN_0800708c: @ 0x0800708C
	push {lr}
	ldr r0, _080070A4 @ =0x0300002C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800709E
	movs r0, #0
	movs r1, #0
	bl Entity0800704c_Create
_0800709E:
	pop {r1}
	bx r1
	.align 2, 0
_080070A4: .4byte 0x0300002C
