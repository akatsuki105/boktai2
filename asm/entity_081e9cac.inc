	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081e908c
FUN_081e908c: @ 0x081E908C
	adds r0, #0xf0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e9094
FUN_081e9094: @ 0x081E9094
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _081E9110 @ =0x030001B4
	ldr r7, [r0]
	cmp r7, #0
	bne _081E90A8
	b _081E91C6
_081E90A8:
	mov r0, r8
	cmp r0, #0
	bne _081E90B0
	b _081E91C6
_081E90B0:
	mov r4, r8
	adds r4, #0x90
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, r8
	ldrb r0, [r1, #2]
	mov r5, sp
	adds r5, #5
	add r1, sp, #4
	adds r2, r5, #0
	bl FUN_081e978c
	mov r6, r8
	adds r6, #0xcc
	ldr r1, [r7, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl AuxAnim_RestartAnim
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9114
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081E911C
	.align 2, 0
_081E9110: .4byte 0x030001B4
_081E9114:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E911C:
	str r0, [r4]
	ldrb r0, [r6, #4]
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
	beq _081E9140
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081E9148
_081E9140:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9148:
	str r0, [r4]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081E9180 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081E91B8
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9184
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081E9178
	ldrb r0, [r6, #5]
_081E9178:
	subs r0, #1
	strh r0, [r6, #8]
	b _081E9194
	.align 2, 0
_081E9180: .4byte 0x0000FFFF
_081E9184:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081E9194
	strh r1, [r6, #8]
_081E9194:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E91B8
	movs r0, #1
	strb r0, [r6, #7]
_081E91B8:
	mov r0, r8
	adds r0, #0xe8
	movs r1, #0
	strh r1, [r0]
	movs r0, #2
	mov r1, r8
	strb r0, [r1]
_081E91C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e91d4
FUN_081e91d4: @ 0x081E91D4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E91F8 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E91F2
	cmp r5, #0
	beq _081E91F2
	adds r0, r5, #0
	adds r0, #0xe4
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #0
	bge _081E91FC
_081E91F2:
	movs r0, #0
	b _081E924C
	.align 2, 0
_081E91F8: .4byte 0x030001B4
_081E91FC:
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E9210
	movs r0, #1
	b _081E9212
_081E9210:
	movs r0, #0
_081E9212:
	cmp r0, #0
	beq _081E924A
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E924A
	adds r0, r5, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x90
	bl AuxSprite_Remove
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r7]
	adds r1, r5, #0
	adds r1, #0xe8
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
	b _081E924C
_081E924A:
	adds r0, r5, #0
_081E924C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9254
FUN_081e9254: @ 0x081E9254
	push {r4, r5, r6, r7, lr}
	ldr r0, _081E9278 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E92C4
	ldr r0, [r6, #0x38]
	cmp r0, #0
	beq _081E92C4
	movs r7, #0
_081E9266:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E927C
	movs r0, #1
	b _081E927E
	.align 2, 0
_081E9278: .4byte 0x030001B4
_081E927C:
	movs r0, #0
_081E927E:
	cmp r0, #0
	beq _081E92BE
	movs r0, #0xf4
	muls r0, r7, r0
	adds r0, #0x3c
	adds r5, r6, r0
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E92BE
	adds r0, r5, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x90
	bl AuxSprite_Remove
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
_081E92BE:
	adds r7, #1
	cmp r7, #0xb
	ble _081E9266
_081E92C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e92cc
FUN_081e92cc: @ 0x081E92CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _081E9380 @ =0x030001B4
	ldr r0, [r0]
	mov sb, r0
	adds r5, r6, #0
	adds r5, #0xbc
	adds r7, r6, #0
	adds r7, #0x64
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081E932A
	ldrh r1, [r6, #0xc]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	ldrh r0, [r6, #0xe]
	ldrh r3, [r6, #6]
	adds r0, r0, r3
	strh r0, [r6, #6]
	ldrh r0, [r6, #0x10]
	ldrh r2, [r6, #8]
	adds r0, r0, r2
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x80
	strh r1, [r0]
	ldrh r0, [r6, #6]
	adds r1, r6, #0
	adds r1, #0x82
	strh r0, [r1]
	ldrh r1, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x84
	strh r1, [r0]
_081E932A:
	adds r0, r6, #0
	bl FUN_081e97cc
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	mov r3, sb
	ldr r1, [r3, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9384
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E938C
	.align 2, 0
_081E9380: .4byte 0x030001B4
_081E9384:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E938C:
	str r0, [r6, #0x64]
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
	beq _081E93B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E93B8
_081E93B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E93B8:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E93F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _081E9428
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E93F4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E93E8
	ldrb r0, [r5, #5]
_081E93E8:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9404
	.align 2, 0
_081E93F0: .4byte 0x0000FFFF
_081E93F4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9404
	strh r1, [r5, #8]
_081E9404:
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
	bne _081E9428
	movs r0, #1
	strb r0, [r5, #7]
_081E9428:
	adds r0, r6, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r1, #1
	bne _081E9438
	b _081E953E
_081E9438:
	adds r7, r6, #0
	adds r7, #0x90
	adds r4, r6, #0
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	mov ip, r7
	cmp r1, r0
	beq _081E9474
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _081E9480
_081E9474:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081E9480:
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
	beq _081E94A2
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E94AA
_081E94A2:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E94AA:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E94E4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E952A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E94EE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E94E8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9504
	.align 2, 0
_081E94E4: .4byte 0x0000FFFF
_081E94E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9502
_081E94EE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9502
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9504
_081E9502:
	movs r2, #0
_081E9504:
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
	bne _081E952C
	movs r0, #1
	strb r0, [r4, #7]
	b _081E952C
_081E952A:
	movs r2, #0
_081E952C:
	cmp r2, #0
	beq _081E953E
	mov r3, ip
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r0, r8
	strh r1, [r0]
_081E953E:
	adds r5, r6, #0
	adds r5, #0xec
	ldrh r0, [r5]
	cmp r0, #0
	beq _081E955E
	adds r4, r6, #0
	adds r4, #0x14
	adds r1, r6, #0
	adds r1, #0xdc
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081E955E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	adds r0, r6, #0
	bl FUN_081e9d04
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9596
	adds r1, r6, #0
	adds r1, #0xf0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081E9582
	subs r0, r2, #1
	b _081E958C
_081E9582:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
_081E958C:
	strh r0, [r1]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_081e8f2c
_081E9596:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e95a4
FUN_081e95a4: @ 0x081E95A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081E9648 @ =0x030001B4
	ldr r0, [r0]
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xe6
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E95F0
	ldrb r0, [r5, #2]
	mov r2, sp
	adds r2, #5
	add r1, sp, #4
	bl FUN_081e978c
	adds r0, r5, #0
	adds r0, #0xbc
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #3
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r2, r5, #0
	adds r2, #0x80
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	strh r4, [r6]
_081E95F0:
	adds r1, r5, #0
	adds r1, #0x80
	ldrh r0, [r5, #0xc]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0xe]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0x10]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r7, r5, #0
	adds r7, #0x64
	adds r4, r5, #0
	adds r4, #0xbc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E964C
	ldr r0, [r5, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9654
	.align 2, 0
_081E9648: .4byte 0x030001B4
_081E964C:
	ldr r0, [r5, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9654:
	str r0, [r5, #0x64]
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
	beq _081E9678
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E9680
_081E9678:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9680:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E96B8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E96FE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E96C2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E96BC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E96D8
	.align 2, 0
_081E96B8: .4byte 0x0000FFFF
_081E96BC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E96D6
_081E96C2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E96D6
	strh r1, [r4, #8]
	movs r2, #1
	b _081E96D8
_081E96D6:
	movs r2, #0
_081E96D8:
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
	bne _081E9700
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9700
_081E96FE:
	movs r2, #0
_081E9700:
	cmp r2, #0
	beq _081E9736
	mov r0, ip
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x90
	bl AuxSprite_Remove
	adds r4, r5, #0
	adds r4, #0xe4
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	movs r1, #0xf4
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5]
_081E9736:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e9744
FUN_081e9744: @ 0x081E9744
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081E974C:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081E975E
	movs r0, #1
	b _081E9760
_081E975E:
	movs r0, #0
_081E9760:
	cmp r0, #0
	bne _081E977C
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0xe4
	strb r2, [r1]
	b _081E9784
_081E977C:
	adds r2, #1
	cmp r2, #0xb
	ble _081E974C
	movs r0, #0
_081E9784:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e978c
FUN_081e978c: @ 0x081E978C
	push {lr}
	adds r3, r0, #0
	asrs r0, r3, #5
	adds r3, r0, #3
	movs r0, #7
	ands r3, r0
	cmp r3, #6
	beq _081E97B4
	cmp r3, #6
	bgt _081E97A6
	cmp r3, #5
	beq _081E97AC
	b _081E97C2
_081E97A6:
	cmp r3, #7
	beq _081E97BC
	b _081E97C2
_081E97AC:
	movs r0, #3
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97B4:
	movs r0, #2
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97BC:
	movs r0, #1
	strb r0, [r1]
	b _081E97C6
_081E97C2:
	strb r3, [r1]
	movs r0, #0
_081E97C6:
	strb r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_081e97cc
FUN_081e97cc: @ 0x081E97CC
	push {lr}
	mov ip, r0
	mov r3, ip
	adds r3, #0xdc
	mov r2, ip
	adds r2, #0x80
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	mov r1, ip
	ldrb r0, [r1, #2]
	lsrs r0, r0, #5
	cmp r0, #7
	bhi _081E98E4
	lsls r0, r0, #2
	ldr r1, _081E97FC @ =_081E9800
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E97FC: .4byte _081E9800
_081E9800: @ jump table
	.4byte _081E9820 @ case 0
	.4byte _081E983E @ case 1
	.4byte _081E985C @ case 2
	.4byte _081E987A @ case 3
	.4byte _081E9886 @ case 4
	.4byte _081E9892 @ case 5
	.4byte _081E989A @ case 6
	.4byte _081E98B8 @ case 7
_081E9820:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x40
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E983E:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E985C:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E987A:
	ldrh r0, [r2]
	subs r0, #0x60
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	b _081E98C8
_081E9886:
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x20
	b _081E98C8
_081E9892:
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r3]
	b _081E98C4
_081E989A:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	b _081E98E2
_081E98B8:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r3, #2]
_081E98C4:
	ldrh r0, [r2, #4]
	subs r0, #0x60
_081E98C8:
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	strh r0, [r1]
	ldrh r0, [r2, #4]
	subs r0, #0x10
	adds r1, #2
_081E98E2:
	strh r0, [r1]
_081E98E4:
	pop {r0}
	bx r0

	thumb_func_start FUN_081e98e8
FUN_081e98e8: @ 0x081E98E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	add r3, sp, #0x14
	ldr r2, _081E9914 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E9918
	asrs r1, r0, #0xc
	b _081E991E
	.align 2, 0
_081E9914: .4byte 0x085B0A08
_081E9918:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E991E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E993A
	asrs r0, r0, #0xc
	b _081E9940
_081E993A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E9940:
	strh r0, [r3, #4]
	ldr r0, _081E9968 @ =0x00000309
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #0
	add r2, sp, #0x14
	adds r3, r4, #0
	bl FUN_081e996c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081E9968: .4byte 0x00000309

	thumb_func_start FUN_081e996c
FUN_081e996c: @ 0x081E996C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	mov r8, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, _081E9998 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E999C
	bl Entity081e9cac_Create
	mov sb, r0
	cmp r0, #0
	bne _081E999E
_081E9992:
	movs r0, #0
	b _081E9B7C
	.align 2, 0
_081E9998: .4byte 0x030001B4
_081E999C:
	mov sb, r0
_081E999E:
	mov r0, sb
	bl FUN_081e9744
	adds r6, r0, #0
	cmp r6, #0
	beq _081E9992
	adds r7, r6, #0
	adds r7, #0x64
	adds r5, r6, #0
	adds r5, #0x90
	mov r4, sb
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r6, #0x64]
	movs r1, #1
	mov sl, r1
	orrs r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r1, r6, #0
	adds r1, #0xec
	movs r0, #0
	strh r0, [r1]
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r0, r8
	cmp r0, #0
	beq _081E9A0C
	ldrh r0, [r0]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r2, #4]
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
_081E9A0C:
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xff
	strb r0, [r6, #1]
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0xea
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	adds r1, #6
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r6, #4]
	str r1, [r6, #8]
	adds r2, r6, #0
	adds r2, #0xac
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r5]
	mov r1, sl
	orrs r0, r1
	str r0, [r5]
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	adds r5, r6, #0
	adds r5, #0xbc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	adds r0, r6, #0
	adds r0, #0xcc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl AuxAnim_RestartAnim
	mov r8, r7
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081E9AB4
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9ABC
_081E9AB4:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9ABC:
	str r0, [r6, #0x64]
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
	beq _081E9AE2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081E9AEC
_081E9AE2:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9AEC:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E9B24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081E9B5C
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9B28
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E9B1E
	ldrb r0, [r5, #5]
_081E9B1E:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9B38
	.align 2, 0
_081E9B24: .4byte 0x0000FFFF
_081E9B28:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9B38
	strh r1, [r5, #8]
_081E9B38:
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
	bne _081E9B5C
	movs r0, #1
	strb r0, [r5, #7]
_081E9B5C:
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	ldr r3, [sp, #0x40]
	bl FUN_081e8e7c
	adds r0, r6, #0
	bl FUN_081e97cc
	movs r0, #1
	strb r0, [r6]
	strb r0, [r7, #7]
	adds r1, r6, #0
	adds r1, #0x97
	strb r0, [r1]
	adds r0, r6, #0
_081E9B7C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081e9cac_Update
Entity081e9cac_Update: @ 0x081E9B8C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	mov r2, sp
	ldr r1, _081E9BC8 @ =0x082523E8
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	ldr r1, _081E9BCC @ =0x030047A4
	ldr r2, _081E9BD0 @ =0x030047A0
	ldr r1, [r1]
	ldr r2, [r2]
	orrs r1, r2
	ands r1, r3
	cmp r1, #0
	bne _081E9BC4
	movs r2, #4
	ldr r1, _081E9BD4 @ =0x03002BC0
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	bne _081E9BC4
	ldr r1, [r6, #0x38]
	cmp r1, #0
	bne _081E9BD8
_081E9BC4:
	movs r0, #0
	b _081E9C1C
	.align 2, 0
_081E9BC8: .4byte 0x082523E8
_081E9BCC: .4byte 0x030047A4
_081E9BD0: .4byte 0x030047A0
_081E9BD4: .4byte 0x03002BC0
_081E9BD8:
	movs r5, #0
_081E9BDA:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9BEA
	movs r1, #1
	b _081E9BEC
_081E9BEA:
	movs r1, #0
_081E9BEC:
	cmp r1, #0
	beq _081E9C16
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	ldrb r1, [r4]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r1, [r4, #0x1a]
	ldr r3, _081E9C24 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r4, #0x1a]
_081E9C16:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9BDA
_081E9C1C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C24: .4byte 0x0000FFFB

	thumb_func_start Entity081e9cac_Destroy
Entity081e9cac_Destroy: @ 0x081E9C28
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081E9C2E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9C3E
	movs r1, #1
	b _081E9C40
_081E9C3E:
	movs r1, #0
_081E9C40:
	cmp r1, #0
	beq _081E9C5E
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r4, #0x90
	adds r0, r4, #0
	bl AuxSprite_Remove
_081E9C5E:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9C2E
	ldr r2, _081E9C70 @ =0x030001B4
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C70: .4byte 0x030001B4

	thumb_func_start Entity081e9cac_Init
Entity081e9cac_Init: @ 0x081E9C74
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	ldr r1, _081E9C9C @ =0x00002D41
	bl Video_GetAuxSprite
	ldr r0, _081E9CA0 @ =0x0000922E
	ldr r1, _081E9CA4 @ =0x0000D6C8
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x18]
	ldr r1, _081E9CA8 @ =0x030001B4
	str r4, [r1]
	movs r1, #0
	str r1, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C9C: .4byte 0x00002D41
_081E9CA0: .4byte 0x0000922E
_081E9CA4: .4byte 0x0000D6C8
_081E9CA8: .4byte 0x030001B4

	thumb_func_start Entity081e9cac_Create
Entity081e9cac_Create: @ 0x081E9CAC
	push {r4, lr}
	ldr r0, _081E9CE0 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E9CF2
	ldr r1, _081E9CE4 @ =0x00000BAC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E9CF0
	ldr r1, _081E9CE8 @ =Entity081e9cac_Update
	ldr r2, _081E9CEC @ =Entity081e9cac_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081e9cac_Init
	cmp r0, #0
	bge _081E9CF0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E9CF2
	.align 2, 0
_081E9CE0: .4byte 0x030001B4
_081E9CE4: .4byte 0x00000BAC
_081E9CE8: .4byte Entity081e9cac_Update
_081E9CEC: .4byte Entity081e9cac_Destroy
_081E9CF0:
	adds r0, r4, #0
_081E9CF2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e9cf8
FUN_081e9cf8: @ 0x081E9CF8
	ldr r1, _081E9D00 @ =0x030001B4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E9D00: .4byte 0x030001B4

	thumb_func_start FUN_081e9d04
FUN_081e9d04: @ 0x081E9D04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081E9D1C
	adds r0, r6, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #4
	bls _081E9DAC
_081E9D1C:
	adds r0, r6, #0
	adds r0, #0x82
	movs r1, #0
	ldrsh r7, [r0, r1]
	adds r5, r6, #0
	adds r5, #0xdc
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E9D4C
	cmp r1, #0
	blt _081E9D4C
	ldr r0, _081E9D50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E9D4C
	ldr r0, _081E9D54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E9D58
_081E9D4C:
	movs r4, #0
	b _081E9D66
	.align 2, 0
_081E9D50: .4byte 0x030046A8
_081E9D54: .4byte 0x030046AC
_081E9D58:
	ldr r0, _081E9D78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E9D66:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E9D7C
	adds r0, #4
	b _081E9D88
	.align 2, 0
_081E9D78: .4byte 0x030046A4
_081E9D7C:
	ldr r0, _081E9D9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E9D88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E9DA0
	cmp r2, #2
	beq _081E9DA4
	b _081E9DA8
	.align 2, 0
_081E9D9C: .4byte 0x030046A4
_081E9DA0:
	ldrb r0, [r5, #4]
	b _081E9DA6
_081E9DA4:
	ldrb r0, [r5]
_081E9DA6:
	subs r1, r1, r0
_081E9DA8:
	cmp r7, r1
	blo _081E9DB0
_081E9DAC:
	movs r0, #0
	b _081E9DBC
_081E9DB0:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
_081E9DBC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9dc4
FUN_081e9dc4: @ 0x081E9DC4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e9dc8
FUN_081e9dc8: @ 0x081E9DC8
	push {r4, r5, r6, r7, lr}
	mov ip, r1
	movs r2, #0xb
	ldrsb r2, [r1, r2]
	movs r1, #0x2c
	muls r1, r2, r1
	adds r1, #0x1c
	adds r6, r0, r1
	mov r3, ip
	ldr r1, [r3]
	ldr r2, [r3, #4]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	ldr r5, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r5, r1
	str r5, [r6]
	movs r1, #0xb
	ldrsb r1, [r3, r1]
	lsls r1, r1, #4
	adds r4, r1, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _081E9E24
	movs r0, #4
	orrs r5, r0
	b _081E9E2A
_081E9E24:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
_081E9E2A:
	str r5, [r6]
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
	beq _081E9E4E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E9E56
_081E9E4E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9E56:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E9E90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E9ED6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9E9A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9E94
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9EB0
	.align 2, 0
_081E9E90: .4byte 0x0000FFFF
_081E9E94:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9EAE
_081E9E9A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9EAE
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9EB0
_081E9EAE:
	movs r2, #0
_081E9EB0:
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
	bne _081E9ED8
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9ED8
_081E9ED6:
	movs r2, #0
_081E9ED8:
	cmp r2, #0
	beq _081E9EE2
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0xa]
_081E9EE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e9ee8
FUN_081e9ee8: @ 0x081E9EE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r4, r0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r5, #0xa]
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0xb]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e9f28
FUN_081e9f28: @ 0x081E9F28
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_081E9F38:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E9F48
	movs r0, #1
	b _081E9F4A
_081E9F48:
	movs r0, #0
_081E9F4A:
	cmp r0, #0
	bne _081E9F64
	movs r0, #0x87
	lsls r0, r0, #2
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0xb]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _081E9F70
_081E9F64:
	movs r0, #0xc
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _081E9F38
	movs r0, #0
_081E9F70:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
