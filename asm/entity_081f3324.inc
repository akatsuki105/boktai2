	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f2714
FUN_081f2714: @ 0x081F2714
	push {lr}
	adds r3, r2, #0
	adds r3, #0xea
	ldrb r0, [r3]
	cmp r0, #1
	bne _081F2730
	adds r0, r2, #0
	adds r0, #0x88
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	movs r0, #2
	strb r0, [r3]
_081F2730:
	pop {r0}
	bx r0

	thumb_func_start FUN_081f2734
FUN_081f2734: @ 0x081F2734
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
	ldr r2, _081F27C0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081F27C4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
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
	adds r4, #0x98
	ldr r2, _081F27C8 @ =0x00002001
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
	ldr r1, _081F27CC @ =FUN_081f2714
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
_081F27C0: .4byte 0xFFFF0000
_081F27C4: .4byte 0x0000FFFF
_081F27C8: .4byte 0x00002001
_081F27CC: .4byte FUN_081f2714

	thumb_func_start FUN_081f27d0
FUN_081f27d0: @ 0x081F27D0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f27d4
FUN_081f27d4: @ 0x081F27D4
	push {r4, lr}
	sub sp, #0x18
	ldr r4, _081F2814 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	movs r3, #0xa0
	orrs r1, r3
	ldr r2, _081F2818 @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0x14]
	adds r0, #0x90
	movs r1, #0
	str r1, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081F2814: .4byte 0xFFFF0000
_081F2818: .4byte 0x0000FFFF

	thumb_func_start FUN_081f281c
FUN_081f281c: @ 0x081F281C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081F283A
	movs r2, #0
	cmp r0, #0x28
	ble _081F283A
	movs r2, #1
_081F283A:
	adds r4, r5, #0
	adds r4, #0xee
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _081F2868 @ =0x085AE548
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081F2876
	ldr r1, [r6]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081F286C
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	b _081F2876
	.align 2, 0
_081F2868: .4byte 0x085AE548
_081F286C:
	orrs r1, r2
	str r1, [r6]
	adds r0, r5, #0
	bl FUN_081f27d4
_081F2876:
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0x5a
	bgt _081F2888
	adds r0, r1, #1
	strh r0, [r4]
	movs r0, #0
	b _081F28B8
_081F2888:
	adds r0, r5, #0
	bl FUN_081f27d4
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r0, r5, #0
	adds r0, #0xeb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_081F28B8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f28c0
FUN_081f28c0: @ 0x081F28C0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r1, #0xf0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F28D2
	movs r0, #0
	strb r0, [r1]
_081F28D2:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _081F2902
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F290A
_081F2902:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F290A:
	str r0, [r6]
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
	beq _081F292E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081F2936
_081F292E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2936:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F296C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F29A4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2970
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2966
	ldrb r0, [r4, #5]
_081F2966:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2980
	.align 2, 0
_081F296C: .4byte 0x0000FFFF
_081F2970:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2980
	strh r1, [r4, #8]
_081F2980:
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
	bne _081F29A4
	movs r0, #1
	strb r0, [r4, #7]
_081F29A4:
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_081f281c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f29b4
FUN_081f29b4: @ 0x081F29B4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0xf0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F29F2
	adds r2, r5, #0
	adds r2, #0x90
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	movs r4, #0
	movs r2, #0
	strh r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #2
	strb r0, [r5, #7]
	strb r4, [r6]
_081F29F2:
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
	beq _081F2A22
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F2A2A
_081F2A22:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2A2A:
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
	beq _081F2A4E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F2A56
_081F2A4E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2A56:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F2A8C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F2AC4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2A90
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2A86
	ldrb r0, [r4, #5]
_081F2A86:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2AA0
	.align 2, 0
_081F2A8C: .4byte 0x0000FFFF
_081F2A90:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2AA0
	strh r1, [r4, #8]
_081F2AA0:
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
	bne _081F2AC4
	movs r0, #1
	strb r0, [r4, #7]
_081F2AC4:
	adds r4, r5, #0
	adds r4, #0x98
	adds r1, r5, #0
	adds r1, #0x90
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r1, r5, #0
	adds r1, #0xf1
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F2AE8
	subs r0, #1
	b _081F2AEE
_081F2AE8:
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #4
_081F2AEE:
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f2af8
FUN_081f2af8: @ 0x081F2AF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0x10]
	adds r7, r1, #0
	mov r8, r7
	adds r4, r7, #0
	adds r4, #0x2c
	adds r3, r7, #0
	adds r3, #0xf0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F2B2E
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r2, r7, #0
	adds r2, #0xee
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
_081F2B2E:
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
	beq _081F2B5A
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F2B62
_081F2B5A:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2B62:
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
	beq _081F2B8C
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _081F2B98
_081F2B8C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F2B98:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F2BCC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F2C04
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2BD0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2BC6
	ldrb r0, [r4, #5]
_081F2BC6:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2BE0
	.align 2, 0
_081F2BCC: .4byte 0x0000FFFF
_081F2BD0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2BE0
	strh r1, [r4, #8]
_081F2BE0:
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
	bne _081F2C04
	movs r0, #1
	strb r0, [r4, #7]
_081F2C04:
	mov r4, r8
	adds r4, #0x1c
	adds r5, r7, #0
	adds r5, #0x88
	mov r3, r8
	ldrh r0, [r3, #0x1c]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldrh r0, [r4, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r7, #0x44]
	str r1, [r7, #0x48]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r6, r7, #0
	adds r6, #0x8c
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl ArcTan2_8
	mov ip, r0
	mov r3, sp
	ldr r2, _081F2C60 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov sb, r4
	mov sl, r5
	cmp r0, #0
	blt _081F2C64
	asrs r1, r0, #0xc
	b _081F2C6A
	.align 2, 0
_081F2C60: .4byte 0x085B0A08
_081F2C64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F2C6A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081F2C8C @ =0x085B0A08
	movs r0, #0xff
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081F2C90
	asrs r0, r0, #0xc
	b _081F2C96
	.align 2, 0
_081F2C8C: .4byte 0x085B0A08
_081F2C90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F2C96:
	strh r0, [r3, #4]
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, r8
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	mov r1, sb
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	mov r3, sb
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r2, #1
	adds r1, r7, #0
	adds r1, #0xe8
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081F2CD0
	movs r0, #1
	b _081F2CD2
_081F2CD0:
	movs r0, #0
_081F2CD2:
	cmp r0, #0
	bne _081F2D1A
	add r4, sp, #8
	adds r3, r7, #0
	adds r3, #0x44
	adds r2, r7, #0
	adds r2, #0x80
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _081F2D50 @ =0x0000BD0F
	cmp r1, r0
	bgt _081F2D24
	ldrh r0, [r5]
	movs r1, #1
	orrs r0, r1
	strh r0, [r5]
_081F2D1A:
	adds r1, r7, #0
	adds r1, #0x8a
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
_081F2D24:
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F2D4C
	cmp r1, #0
	blt _081F2D4C
	ldr r0, _081F2D54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F2D4C
	ldr r0, _081F2D58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F2D5C
_081F2D4C:
	movs r4, #0
	b _081F2D6A
	.align 2, 0
_081F2D50: .4byte 0x0000BD0F
_081F2D54: .4byte 0x030046A8
_081F2D58: .4byte 0x030046AC
_081F2D5C:
	ldr r0, _081F2D7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F2D6A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F2D80
	adds r0, #4
	b _081F2D8C
	.align 2, 0
_081F2D7C: .4byte 0x030046A4
_081F2D80:
	ldr r0, _081F2DA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F2D8C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F2DA4
	cmp r2, #2
	beq _081F2DA8
	b _081F2DAC
	.align 2, 0
_081F2DA0: .4byte 0x030046A4
_081F2DA4:
	ldrb r0, [r5, #4]
	b _081F2DAA
_081F2DA8:
	ldrb r0, [r5]
_081F2DAA:
	subs r1, r1, r0
_081F2DAC:
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	adds r4, r7, #0
	adds r4, #0x98
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r1, r7, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	mov r0, r8
	ldrh r4, [r0, #0x1e]
	movs r2, #0x1e
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bgt _081F2E0A
	ldr r0, [r0]
	movs r1, #1
	orrs r0, r1
	mov r3, r8
	str r0, [r3]
	adds r0, r7, #0
	adds r0, #0xeb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r7, #0
	bl AuxSprite_Remove
	adds r1, r7, #0
	adds r1, #0xea
	movs r0, #0
	strb r0, [r1]
	b _081F2E58
_081F2E0A:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _081F2E58
	mov r1, r8
	ldrh r0, [r1, #0x1c]
	mov r2, sl
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x1c]
	adds r2, r7, #0
	adds r2, #0x8a
	ldrh r0, [r2]
	subs r0, r4, r0
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #0x20]
	ldrh r1, [r6]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x20]
	mov r0, sl
	strh r3, [r0]
	strh r3, [r2]
	strh r3, [r6]
	adds r1, r7, #0
	adds r1, #0xea
	movs r0, #3
	strb r0, [r1]
	adds r1, #6
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r7, #0x44]
	str r1, [r7, #0x48]
	movs r0, #0xf2
	bl PlaySound_082406e0
_081F2E58:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f2e68
FUN_081f2e68: @ 0x081F2E68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r3, r5, #0
	adds r3, #0xf0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F2E9C
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r5, #0
	adds r2, #0xee
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
_081F2E9C:
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
	beq _081F2EC8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F2ED0
_081F2EC8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2ED0:
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
	beq _081F2EF4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F2EFC
_081F2EF4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2EFC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F2F34 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F2F6C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2F38
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2F2C
	ldrb r0, [r4, #5]
_081F2F2C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2F48
	.align 2, 0
_081F2F34: .4byte 0x0000FFFF
_081F2F38:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2F48
	strh r1, [r4, #8]
_081F2F48:
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
	bne _081F2F6C
	movs r0, #1
	strb r0, [r4, #7]
_081F2F6C:
	adds r4, r5, #0
	adds r4, #0x8a
	ldrh r0, [r4]
	subs r0, #4
	strh r0, [r4]
	adds r2, r7, #0
	adds r2, #0x1c
	adds r3, r5, #0
	adds r3, #0x88
	ldrh r0, [r7, #0x1c]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r5, #0x44]
	str r1, [r5, #0x48]
	adds r6, r2, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r4
	mov r8, r3
	cmp r2, #0
	blt _081F2FC8
	cmp r1, #0
	blt _081F2FC8
	ldr r0, _081F2FCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F2FC8
	ldr r0, _081F2FD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F2FD4
_081F2FC8:
	movs r4, #0
	b _081F2FE2
	.align 2, 0
_081F2FCC: .4byte 0x030046A8
_081F2FD0: .4byte 0x030046AC
_081F2FD4:
	ldr r0, _081F2FF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F2FE2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F2FF8
	adds r0, #4
	b _081F3004
	.align 2, 0
_081F2FF4: .4byte 0x030046A4
_081F2FF8:
	ldr r0, _081F3018 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F3004:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F301C
	cmp r2, #2
	beq _081F3020
	b _081F3024
	.align 2, 0
_081F3018: .4byte 0x030046A4
_081F301C:
	ldrb r0, [r6, #4]
	b _081F3022
_081F3020:
	ldrb r0, [r6]
_081F3022:
	subs r1, r1, r0
_081F3024:
	lsls r0, r1, #0x10
	lsrs r3, r0, #0x10
	adds r1, r5, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	movs r0, #0x1e
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bgt _081F3068
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0xeb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	mov r2, sl
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #0
	strb r0, [r1]
	b _081F309C
_081F3068:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _081F309C
	strh r3, [r7, #0x1e]
	mov r0, r8
	strh r2, [r0]
	mov r1, sb
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0x8c
	strh r2, [r0]
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #3
	strb r0, [r1]
	adds r1, #6
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r5, #0x44]
	str r1, [r5, #0x48]
	movs r0, #0xf2
	bl PlaySound_082406e0
_081F309C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f30ac
FUN_081f30ac: @ 0x081F30AC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r7, #1
_081F30B4:
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F30C4
	movs r0, #1
	b _081F30C6
_081F30C4:
	movs r0, #0
_081F30C6:
	cmp r0, #0
	bne _081F30F0
	movs r0, #0xf4
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r5, r4
	adds r0, r4, #0
	movs r1, #0xf4
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	orrs r0, r1
	str r0, [r5, #0x38]
	adds r0, r4, #0
	adds r0, #0xeb
	strb r6, [r0]
	adds r0, r4, #0
	b _081F30F8
_081F30F0:
	adds r6, #1
	cmp r6, #0xb
	ble _081F30B4
	movs r0, #0
_081F30F8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f3100
FUN_081f3100: @ 0x081F3100
	push {lr}
	bl FUN_081f30ac
	cmp r0, #0
	bne _081F310C
	movs r0, #0
_081F310C:
	pop {r1}
	bx r1

	thumb_func_start FUN_081f3110
FUN_081f3110: @ 0x081F3110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r7, r1, #0
	mov sl, r2
	str r3, [sp, #0xc]
	ldr r0, _081F31E8 @ =0x030001F0
	ldr r6, [r0]
	cmp r6, #0
	bne _081F3138
	bl Entity081f3324_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F3138
	b _081F324C
_081F3138:
	adds r0, r6, #0
	bl FUN_081f3100
	adds r5, r0, #0
	cmp r5, #0
	bne _081F3146
	b _081F324C
_081F3146:
	adds r0, #0xea
	movs r4, #0
	movs r3, #1
	strb r3, [r0]
	subs r0, #2
	strh r4, [r0]
	adds r1, r5, #0
	adds r1, #0xf1
	ldr r0, [sp, #0x38]
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x80
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	adds r0, #0xf0
	strb r3, [r0]
	mov r8, r5
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r6, #0x34]
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5, #0xc]
	movs r1, #1
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	add r2, sp, #4
	adds r3, r5, #0
	adds r3, #0x1c
	ldrh r0, [r7]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r7, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _081F31EC @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x3c]
	muls r0, r2, r0
	cmp r0, #0
	blt _081F31F0
	asrs r1, r0, #0xc
	b _081F31F6
	.align 2, 0
_081F31E8: .4byte 0x030001F0
_081F31EC: .4byte 0x085B0A08
_081F31F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F31F6:
	adds r0, r5, #0
	adds r0, #0x88
	strh r1, [r0]
	ldr r1, _081F3218 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _081F321C
	asrs r2, r0, #0xc
	b _081F3222
	.align 2, 0
_081F3218: .4byte 0x085B0A08
_081F321C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F3222:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	strh r2, [r0]
	subs r0, #2
	strh r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #2
	strb r0, [r2, #7]
	ldr r0, [sp, #0x34]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sl
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x30]
	bl FUN_081f2734
_081F324C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity081f3324_Update
Entity081f3324_Update: @ 0x081F325C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	movs r4, #0
	ldr r7, _081F3278 @ =0x085AE54C
_081F3268:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F327C
	movs r0, #1
	b _081F327E
	.align 2, 0
_081F3278: .4byte 0x085AE54C
_081F327C:
	movs r0, #0
_081F327E:
	cmp r0, #0
	beq _081F329C
	movs r0, #0xf4
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0xea
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F329C:
	adds r4, #1
	cmp r4, #0xb
	ble _081F3268
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f3324_Destroy
Entity081f3324_Destroy: @ 0x081F32AC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F32B2:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F32C2
	movs r0, #1
	b _081F32C4
_081F32C2:
	movs r0, #0
_081F32C4:
	cmp r0, #0
	beq _081F32D4
	movs r0, #0xf4
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F32D4:
	adds r4, #1
	cmp r4, #0xb
	ble _081F32B2
	ldr r1, _081F32E8 @ =0x030001F0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F32E8: .4byte 0x030001F0

	thumb_func_start Entity081f3324_Init
Entity081f3324_Init: @ 0x081F32EC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081F3314 @ =0x0000A5B3
	bl Video_GetAuxSprite
	ldr r0, _081F3318 @ =0x0000922E
	ldr r1, _081F331C @ =0x00001752
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _081F3320 @ =0x030001F0
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F3314: .4byte 0x0000A5B3
_081F3318: .4byte 0x0000922E
_081F331C: .4byte 0x00001752
_081F3320: .4byte 0x030001F0

	thumb_func_start Entity081f3324_Create
Entity081f3324_Create: @ 0x081F3324
	push {r4, lr}
	ldr r0, _081F3358 @ =0x030001F0
	ldr r0, [r0]
	cmp r0, #0
	bne _081F336A
	ldr r1, _081F335C @ =0x00000BAC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F3368
	ldr r1, _081F3360 @ =Entity081f3324_Update
	ldr r2, _081F3364 @ =Entity081f3324_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f3324_Init
	cmp r0, #0
	bge _081F3368
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F336A
	.align 2, 0
_081F3358: .4byte 0x030001F0
_081F335C: .4byte 0x00000BAC
_081F3360: .4byte Entity081f3324_Update
_081F3364: .4byte Entity081f3324_Destroy
_081F3368:
	adds r0, r4, #0
_081F336A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f3370
FUN_081f3370: @ 0x081F3370
	ldr r1, _081F3378 @ =0x030001F0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F3378: .4byte 0x030001F0
