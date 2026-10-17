	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f9654
FUN_081f9654: @ 0x081F9654
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f9658
FUN_081f9658: @ 0x081F9658
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
	ldr r2, _081F96E4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _081F96E8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _081F96EC @ =0x00002401
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
	ldr r1, _081F96F0 @ =FUN_081f9654
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
_081F96E4: .4byte 0xFFFF0000
_081F96E8: .4byte 0x0000FFFF
_081F96EC: .4byte 0x00002401
_081F96F0: .4byte FUN_081f9654

	thumb_func_start FUN_081f96f4
FUN_081f96f4: @ 0x081F96F4
	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x3c
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f9714
FUN_081f9714: @ 0x081F9714
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081F971C:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081F972E
	movs r0, #1
	b _081F9730
_081F972E:
	movs r0, #0
_081F9730:
	cmp r0, #0
	bne _081F974C
	movs r0, #0x9c
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0x93
	strb r2, [r1]
	b _081F9754
_081F974C:
	adds r2, #1
	cmp r2, #7
	ble _081F971C
	movs r0, #0
_081F9754:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f975c
FUN_081f975c: @ 0x081F975C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081F97A8 @ =0x0203B400
	ldr r3, _081F97AC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F97B0 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	mov r4, sp
	adds r6, r0, #0
	subs r6, #0x20
	ldr r1, _081F97B4 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F97B8
	asrs r2, r0, #0xc
	b _081F97BE
	.align 2, 0
_081F97A8: .4byte 0x0203B400
_081F97AC: .4byte 0x030046B8
_081F97B0: .4byte 0x000003FF
_081F97B4: .4byte gSineTable
_081F97B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F97BE:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F97D6
	asrs r0, r0, #0xc
	b _081F97DC
_081F97D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F97DC:
	strh r0, [r4, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F980C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081F9810 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, ip
	movs r2, #0x1e
	movs r3, #3
	bl FUN_081ee07c
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F980C: .4byte 0x000003FF
_081F9810: .4byte 0x0203B400

	thumb_func_start FUN_081f9814
FUN_081f9814: @ 0x081F9814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x40
	mov r8, r0
	ldr r4, _081F9864 @ =0x0203B400
	ldr r3, _081F9868 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F986C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r6, sp, #0x38
	adds r4, r0, #4
	ldr r1, _081F9870 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _081F9874
	asrs r2, r0, #0xc
	b _081F987A
	.align 2, 0
_081F9864: .4byte 0x0203B400
_081F9868: .4byte 0x030046B8
_081F986C: .4byte 0x000003FF
_081F9870: .4byte gSineTable
_081F9874:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F987A:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F9892
	asrs r0, r0, #0xc
	b _081F9898
_081F9892:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F9898:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r5, _081F9910 @ =0x0203B400
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _081F9914 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #0xc
	add r2, sp, #0x38
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _081F9918 @ =0x00001C1A
	ldr r3, _081F991C @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	movs r0, #1
	str r0, [sp, #0x24]
	ldr r0, _081F9920 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	mov r0, r8
	add r1, sp, #0x38
	bl FUN_081f22c0
	add sp, #0x40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F9910: .4byte 0x0203B400
_081F9914: .4byte 0x000003FF
_081F9918: .4byte 0x00001C1A
_081F991C: .4byte 0x0000D1B8
_081F9920: .4byte 0x00200004

	thumb_func_start FUN_081f9924
FUN_081f9924: @ 0x081F9924
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f9928
FUN_081f9928: @ 0x081F9928
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0x9b
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F9942
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r6]
_081F9942:
	adds r5, r4, #0
	adds r5, #0x98
	ldrh r0, [r5]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081F995A
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_081f975c
_081F995A:
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r1, [r5]
	ldrh r0, [r0]
	cmp r1, r0
	bls _081F9974
	adds r0, r4, #0
	adds r0, #0x92
	movs r1, #2
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
	b _081F9978
_081F9974:
	adds r0, r1, #1
	strh r0, [r5]
_081F9978:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f9980
FUN_081f9980: @ 0x081F9980
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x9b
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F99AA
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0x98
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081F9A0C @ =0x00000145
	bl PlaySound_082406e0
	strb r4, [r6]
_081F99AA:
	ldrh r0, [r5, #0x34]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r5, #0
	adds r4, #0x98
	cmp r0, #2
	bhi _081F99D4
	adds r0, r5, #0
	bl FUN_081f96f4
	ldrh r0, [r4]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081F99D4
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_081f9814
_081F99D4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
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
	beq _081F9A10
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F9A18
	.align 2, 0
_081F9A0C: .4byte 0x00000145
_081F9A10:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F9A18:
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
	beq _081F9A3C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F9A44
_081F9A3C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F9A44:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F9A7C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F9AC2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F9A86
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F9A80
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F9A9C
	.align 2, 0
_081F9A7C: .4byte 0x0000FFFF
_081F9A80:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F9A9A
_081F9A86:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F9A9A
	strh r1, [r4, #8]
	movs r2, #1
	b _081F9A9C
_081F9A9A:
	movs r2, #0
_081F9A9C:
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
	bne _081F9AC4
	movs r0, #1
	strb r0, [r4, #7]
	b _081F9AC4
_081F9AC2:
	movs r2, #0
_081F9AC4:
	cmp r2, #0
	beq _081F9AD6
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #3
	strb r0, [r1]
	adds r1, #9
	movs r0, #1
	strb r0, [r1]
_081F9AD6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f9adc
FUN_081f9adc: @ 0x081F9ADC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x9b
	ldrb r0, [r7]
	cmp r0, #0
	beq _081F9B18
	adds r1, #0x98
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r2, r5, #0
	adds r2, #0x93
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	bics r0, r1
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x92
	strb r4, [r0]
	strb r4, [r7]
_081F9B18:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f9b20
FUN_081f9b20: @ 0x081F9B20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r0
	adds r4, r1, #0
	mov sl, r2
	str r3, [sp, #0x10]
	ldr r0, _081F9B64 @ =0x03000210
	ldr r6, [r0]
	cmp r6, #0
	bne _081F9B46
	bl Entity081f9cb8_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081F9BE0
_081F9B46:
	adds r0, r6, #0
	bl FUN_081f9714
	adds r7, r0, #0
	cmp r7, #0
	beq _081F9BE0
	adds r0, #0x94
	strh r4, [r0]
	lsls r0, r4, #0x10
	cmp r0, #0
	bne _081F9B68
	adds r1, r7, #0
	adds r1, #0x92
	movs r0, #2
	b _081F9B6E
	.align 2, 0
_081F9B64: .4byte 0x03000210
_081F9B68:
	adds r1, r7, #0
	adds r1, #0x92
	movs r0, #1
_081F9B6E:
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x90
	movs r5, #0
	strh r5, [r0]
	adds r0, #0xb
	movs r1, #1
	mov sb, r1
	mov r2, sb
	strb r2, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, _081F9BF0 @ =0x0000922E
	ldr r1, _081F9BF4 @ =0x0000121B
	bl GetFile
	adds r4, r7, #0
	adds r4, #0x8c
	str r0, [r4]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r7, #0
	adds r0, #0x2c
	ldr r1, [r4]
	str r5, [sp]
	movs r2, #6
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #0xc]
	movs r1, #0xd9
	bl Video_SetAuxSpritePltt
	movs r0, #2
	strb r0, [r7, #7]
	ldr r0, [r7]
	mov r1, sb
	orrs r0, r1
	str r0, [r7]
	ldr r0, [sp, #0x38]
	str r0, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x34]
	bl FUN_081f9658
_081F9BE0:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F9BF0: .4byte 0x0000922E
_081F9BF4: .4byte 0x0000121B

	thumb_func_start Entity081f9cb8_Update
Entity081f9cb8_Update: @ 0x081F9BF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _081F9C46
	movs r4, #0
	ldr r7, _081F9C1C @ =0x085AE5E0
_081F9C0A:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F9C20
	movs r0, #1
	b _081F9C22
	.align 2, 0
_081F9C1C: .4byte 0x085AE5E0
_081F9C20:
	movs r0, #0
_081F9C22:
	cmp r0, #0
	beq _081F9C40
	movs r0, #0x9c
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0x92
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F9C40:
	adds r4, #1
	cmp r4, #7
	ble _081F9C0A
_081F9C46:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f9cb8_Destroy
Entity081f9cb8_Destroy: @ 0x081F9C50
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F9C56:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F9C66
	movs r0, #1
	b _081F9C68
_081F9C66:
	movs r0, #0
_081F9C68:
	cmp r0, #0
	beq _081F9C78
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F9C78:
	adds r4, #1
	cmp r4, #7
	ble _081F9C56
	ldr r1, _081F9C8C @ =0x03000210
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F9C8C: .4byte 0x03000210

	thumb_func_start Entity081f9cb8_Init
Entity081f9cb8_Init: @ 0x081F9C90
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F9CB0 @ =0x0000F422
	bl Video_GetAuxSprite
	ldr r0, _081F9CB4 @ =0x03000210
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F9CB0: .4byte 0x0000F422
_081F9CB4: .4byte 0x03000210

	thumb_func_start Entity081f9cb8_Create
Entity081f9cb8_Create: @ 0x081F9CB8
	push {r4, lr}
	ldr r0, _081F9CEC @ =0x03000210
	ldr r0, [r0]
	cmp r0, #0
	bne _081F9CFE
	ldr r1, _081F9CF0 @ =0x0000051C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F9CFC
	ldr r1, _081F9CF4 @ =Entity081f9cb8_Update
	ldr r2, _081F9CF8 @ =Entity081f9cb8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f9cb8_Init
	cmp r0, #0
	bge _081F9CFC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F9CFE
	.align 2, 0
_081F9CEC: .4byte 0x03000210
_081F9CF0: .4byte 0x0000051C
_081F9CF4: .4byte Entity081f9cb8_Update
_081F9CF8: .4byte Entity081f9cb8_Destroy
_081F9CFC:
	adds r0, r4, #0
_081F9CFE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f9d04
FUN_081f9d04: @ 0x081F9D04
	ldr r1, _081F9D0C @ =0x03000210
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F9D0C: .4byte 0x03000210

	thumb_func_start FUN_081f9d10
FUN_081f9d10: @ 0x081F9D10
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081F9D20 @ =0x03000210
	ldr r5, [r0]
	cmp r5, #0
	bne _081F9D28
	b _081F9D76
	.align 2, 0
_081F9D20: .4byte 0x03000210
_081F9D24:
	movs r0, #1
	b _081F9D78
_081F9D28:
	movs r3, #0
_081F9D2A:
	movs r0, #0x9c
	muls r0, r3, r0
	adds r2, r5, r0
	adds r0, r2, #0
	adds r0, #0xce
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _081F9D70
	adds r0, r2, #0
	adds r0, #0x58
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bne _081F9D70
	adds r0, r2, #0
	adds r0, #0x5a
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #2
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bne _081F9D70
	adds r0, r2, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r6, #4
	ldrsh r0, [r4, r6]
	cmp r1, r0
	beq _081F9D24
_081F9D70:
	adds r3, #1
	cmp r3, #7
	ble _081F9D2A
_081F9D76:
	movs r0, #0
_081F9D78:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f9d80
FUN_081f9d80: @ 0x081F9D80
	push {r4, lr}
	ldr r0, _081F9DB0 @ =0x03000210
	ldr r0, [r0]
	cmp r0, #0
	beq _081F9DA8
	movs r4, #3
	movs r3, #1
	adds r0, #0xce
	movs r2, #7
_081F9D92:
	ldrb r1, [r0]
	cmp r1, #3
	beq _081F9DA0
	cmp r1, #0
	beq _081F9DA0
	strb r4, [r0]
	strb r3, [r0, #9]
_081F9DA0:
	adds r0, #0x9c
	subs r2, #1
	cmp r2, #0
	bge _081F9D92
_081F9DA8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081F9DB0: .4byte 0x03000210
