	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f337c
FUN_081f337c: @ 0x081F337C
	push {lr}
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F3390
	movs r1, #0
	bl VM_ExecByID
_081F3390:
	pop {r0}
	bx r0

	thumb_func_start FUN_081f3394
FUN_081f3394: @ 0x081F3394
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f3398
FUN_081f3398: @ 0x081F3398
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F33C2
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r7, #0x18]
	movs r2, #4
	str r2, [sp]
	movs r2, #0x17
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #0
	strb r0, [r4]
_081F33C2:
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _081F33F2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F33FA
_081F33F2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F33FA:
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
	beq _081F341E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F3426
_081F341E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F3426:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F3460 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F34A6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F346A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F3464
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F3480
	.align 2, 0
_081F3460: .4byte 0x0000FFFF
_081F3464:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F347E
_081F346A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F347E
	strh r1, [r4, #8]
	movs r2, #1
	b _081F3480
_081F347E:
	movs r2, #0
_081F3480:
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
	bne _081F34A8
	movs r0, #1
	strb r0, [r4, #7]
	b _081F34A8
_081F34A6:
	movs r2, #0
_081F34A8:
	cmp r2, #0
	beq _081F34F6
	ldr r0, _081F3500 @ =0x00000153
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x1c]
	bics r0, r1
	str r0, [r7, #0x1c]
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r6, #0
	strb r6, [r0]
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _081F34D4
	adds r0, r5, #0
	bl AuxSprite_Remove
_081F34D4:
	ldr r2, _081F3504 @ =0x0000015B
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _081F34EA
	adds r0, r5, #0
	adds r0, #0x64
	bl AuxShadow_Remove
_081F34EA:
	movs r0, #0xff
	strb r0, [r4]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
_081F34F6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F3500: .4byte 0x00000153
_081F3504: .4byte 0x0000015B

	thumb_func_start FUN_081f3508
FUN_081f3508: @ 0x081F3508
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F35F4
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r6, #0xb7
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r1, #0
	movs r0, #0x14
	strh r0, [r2]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081F3588 @ =0x0203B400
	ldr r1, _081F358C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081F3590 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	subs r6, #0x15
	adds r3, r5, r6
	strb r0, [r3]
	ldrb r3, [r3]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0xff
	ldrb r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r6, r5, r1
	adds r4, r0, #0
	adds r4, #0x40
	ldr r1, _081F3594 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F3598
	asrs r2, r0, #0xc
	b _081F359E
	.align 2, 0
_081F3588: .4byte 0x0203B400
_081F358C: .4byte 0x030046B8
_081F3590: .4byte 0x000003FF
_081F3594: .4byte 0x085B0A08
_081F3598:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F359E:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F35B6
	asrs r0, r0, #0xc
	b _081F35BC
_081F35B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F35BC:
	movs r4, #0
	movs r3, #0
	strh r0, [r6, #4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r2, r5, #0
	adds r2, #0x1c
	ldrh r0, [r1]
	ldrh r6, [r5, #0x1c]
	adds r0, r0, r6
	strh r0, [r1]
	ldrh r0, [r1, #2]
	ldrh r6, [r2, #2]
	adds r0, r0, r6
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	movs r2, #0xab
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r4, [r0]
_081F35F4:
	movs r6, #0xb7
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _081F3660
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r2, #0x1c
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r6, #0
	ldrsh r1, [r4, r6]
	bl Div
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0xd2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x1e
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r6, #0
	ldrsh r1, [r4, r6]
	bl Div
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r6, #0x20
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl Div
	ldrh r1, [r5, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_081F3660:
	movs r6, #0xac
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081F375C
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _081F369C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F36A4
_081F369C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F36A4:
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
	beq _081F36C8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F36D0
_081F36C8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F36D0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F3708 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081F374E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F3712
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F370C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F3728
	.align 2, 0
_081F3708: .4byte 0x0000FFFF
_081F370C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F3726
_081F3712:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F3726
	strh r1, [r4, #8]
	movs r2, #1
	b _081F3728
_081F3726:
	movs r2, #0
_081F3728:
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
	bne _081F3750
	movs r0, #1
	strb r0, [r4, #7]
	b _081F3750
_081F374E:
	movs r2, #0
_081F3750:
	movs r6, #0xac
	lsls r6, r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	cmp r2, #0
	beq _081F3796
_081F375C:
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081F3796
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xa9
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _081F379C @ =0x00000157
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r6, #0x1e
	adds r1, r5, r6
	strb r0, [r1]
	subs r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_081F3796:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F379C: .4byte 0x00000157

	thumb_func_start FUN_081f37a0
FUN_081f37a0: @ 0x081F37A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp, #0x2c]
	adds r4, r0, #0
	adds r4, #0x58
	ldr r0, _081F3880 @ =0x0203B400
	mov sb, r0
	ldr r7, _081F3884 @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _081F3888 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r2, [r4, #2]
	cmp r1, r2
	bne _081F37EA
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_081F37EA:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl Map_GetPathNodes
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	ldr r0, _081F388C @ =0x03002BE0
	add r2, sp, #4
	ldr r3, [r0]
	adds r5, r3, #0
	adds r5, #0x2c
	ldr r4, [sp, #0x2c]
	adds r4, #0x1c
	ldr r1, [sp, #0x2c]
	ldrh r0, [r1, #0x1c]
	ldrh r1, [r3, #0x2c]
	subs r0, r0, r1
	movs r6, #0
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r4, [sp, #0x2c]
	adds r4, #0xd0
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r4]
	str r1, [r4, #4]
	ldr r2, [sp, #0x2c]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r6, [r0]
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	lsls r1, r0, #1
	add r1, sb
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0xff
	ldrb r0, [r0]
	add r3, sp, #0xc
	adds r5, r1, #0
	adds r6, r0, #0
	subs r6, #0x80
	ldr r1, _081F3890 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	str r4, [sp, #0x44]
	adds r4, r3, #0
	cmp r0, #0
	blt _081F3894
	asrs r1, r0, #0xc
	b _081F389A
	.align 2, 0
_081F3880: .4byte 0x0203B400
_081F3884: .4byte 0x030046B8
_081F3888: .4byte 0x000003FF
_081F388C: .4byte 0x03002BE0
_081F3890: .4byte 0x085B0A08
_081F3894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F389A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081F38B4 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F38B8
	asrs r0, r0, #0xc
	b _081F38BE
	.align 2, 0
_081F38B4: .4byte 0x085B0A08
_081F38B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F38BE:
	movs r2, #0
	strh r0, [r3, #4]
	ldrh r0, [r4]
	ldr r3, [sp, #0x44]
	ldrh r3, [r3]
	adds r0, r0, r3
	ldr r5, [sp, #0x44]
	strh r0, [r5]
	ldr r1, [sp, #0x2c]
	adds r1, #0xd4
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r3, [sp, #0x2c]
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #0x20]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _081F3988 @ =0x0000FFFF
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r3, #0
	adds r0, #0xd2
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc
	bl Div
	str r0, [sp, #0x30]
	ldr r5, [sp, #0x2c]
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	str r0, [sp, #0x34]
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #7
	str r0, [sp, #0x38]
	movs r0, #0
	mov r5, sp
	adds r5, #0x1c
	str r5, [sp, #0x40]
	add r7, sp, #0x24
	mov sl, r7
	add r1, sp, #0x14
	mov sb, r1
	ldr r2, [sp, #0x44]
	str r2, [sp, #0x3c]
_081F3932:
	adds r4, r0, #1
	lsls r0, r0, #3
	ldr r3, [sp, #0x2c]
	adds r3, r3, r0
	mov r8, r3
	movs r5, #0xd8
	add r8, r5
	ldr r7, [sp, #0x30]
	adds r5, r7, #0
	muls r5, r4, r5
	ldr r0, [sp, #0x3c]
	ldrh r1, [r0]
	add r0, sp, #0x14
	ldrh r0, [r0]
	subs r1, r1, r0
	add r0, sp, #0x1c
	strh r1, [r0]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	mov r3, sp
	strh r0, [r3, #0x1e]
	ldr r7, [sp, #0x3c]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #0x20]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	mov r1, sl
	ldr r2, _081F398C @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _081F3990
	asrs r0, r0, #0xa
	b _081F3996
	.align 2, 0
_081F3988: .4byte 0x0000FFFF
_081F398C: .4byte 0x05000002
_081F3990:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081F3996:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _081F39A4
	asrs r1, r0, #0xa
	b _081F39AA
_081F39A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F39AA:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	ldr r5, [sp, #0x38]
	adds r4, r0, #0
	muls r4, r5, r4
	subs r1, r1, r3
	str r1, [sp, #0x48]
	subs r0, r2, r6
	adds r0, #1
	mov r7, sl
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	ldr r7, [sp, #0x34]
	adds r5, r0, #0
	muls r5, r7, r5
	subs r1, r6, r2
	ldr r3, [sp, #0x40]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r5, r0
	adds r0, r0, r4
	ldr r1, [sp, #0x48]
	adds r0, r0, r1
	cmp r0, #0
	blt _081F39EA
	asrs r1, r0, #0xa
	b _081F39F0
_081F39EA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F39F0:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	mov r5, r8
	strh r0, [r5]
	subs r3, r2, r6
	adds r1, r3, #1
	mov r7, sl
	movs r5, #2
	ldrsh r0, [r7, r5]
	muls r0, r1, r0
	ldr r7, [sp, #0x34]
	adds r5, r0, #0
	muls r5, r7, r5
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0x40]
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x4c]
	muls r0, r1, r0
	adds r0, r5, r0
	adds r0, r0, r4
	ldr r5, [sp, #0x48]
	adds r0, r0, r5
	cmp r0, #0
	blt _081F3A2C
	asrs r1, r0, #0xa
	b _081F3A32
_081F3A2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F3A32:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, sl
	movs r5, #4
	ldrsh r0, [r3, r5]
	muls r0, r1, r0
	ldr r7, [sp, #0x34]
	adds r5, r0, #0
	muls r5, r7, r5
	adds r1, r2, r6
	ldr r2, [sp, #0x40]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r5, r0
	adds r0, r0, r4
	ldr r5, [sp, #0x48]
	adds r0, r0, r5
	cmp r0, #0
	blt _081F3A66
	asrs r1, r0, #0xa
	b _081F3A6C
_081F3A66:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F3A6C:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	mov r0, ip
	cmp r0, #0xb
	bgt _081F3A7E
	b _081F3932
_081F3A7E:
	ldr r3, [sp, #0x2c]
	movs r5, #0x9c
	lsls r5, r5, #1
	adds r2, r3, r5
	ldr r7, [sp, #0x44]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f3aa0
FUN_081f3aa0: @ 0x081F3AA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r0, #0
	adds r6, r1, #0
	mov sb, r6
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	mov sl, r1
	movs r3, #0xab
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F3B94
	ldr r1, [r2, #0x18]
	mov r0, sl
	str r0, [sp]
	mov r0, r8
	movs r2, #0xe
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	ldr r2, _081F3B2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F3B30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081F3B34 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xad
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r4, [r1]
	movs r5, #0x18
	ldr r2, _081F3B38 @ =0x085B0A08
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
	blt _081F3B3C
	asrs r1, r0, #0xc
	b _081F3B42
	.align 2, 0
_081F3B2C: .4byte 0x030046B8
_081F3B30: .4byte 0x000003FF
_081F3B34: .4byte 0x0203B400
_081F3B38: .4byte 0x085B0A08
_081F3B3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F3B42:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081F3B5C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F3B60
	asrs r0, r0, #0xc
	b _081F3B66
	.align 2, 0
_081F3B5C: .4byte 0x085B0A08
_081F3B60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F3B66:
	movs r2, #0
	movs r1, #0
	strh r0, [r3, #4]
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r3, r6, r0
	movs r0, #0x8c
	lsls r0, r0, #3
	strh r0, [r3]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r3, #8
	adds r0, r6, r3
	strb r2, [r0]
	adds r0, r6, #0
	bl FUN_081f37a0
_081F3B94:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r1, [r0]
	add r4, sp, #4
	adds r3, r6, #0
	adds r3, #0x1c
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r1, #0xd8
	ldrh r0, [r1]
	ldrh r2, [r6, #0x1c]
	subs r0, r0, r2
	adds r2, r4, #0
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _081F3C70
	adds r0, r4, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0
	ble _081F3C70
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _081F3BF6
	asrs r1, r0, #6
	b _081F3BFC
_081F3BF6:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_081F3BFC:
	adds r7, r1, #0
	cmp r7, #1
	bge _081F3C04
	movs r7, #1
_081F3C04:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xd8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r2, #0x1c
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r7, #0
	bl Div
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r5, r6, r3
	strh r0, [r5]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xdc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x20
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r7, #0
	bl Div
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r5]
	ldrh r2, [r6, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	ldrh r0, [r1]
	ldrh r3, [r6, #0x20]
	adds r0, r0, r3
	strh r0, [r6, #0x20]
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	b _081F3CD6
_081F3C70:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _081F3CBA
	adds r0, r6, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r6, #0x20]
	adds r0, r6, #0
	bl FUN_081f37a0
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x8c
	lsls r0, r0, #3
	strh r0, [r1]
	strb r4, [r5]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	mov sl, r0
	b _081F3CD6
_081F3CBA:
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xd8
	ldrh r0, [r0]
	strh r0, [r6, #0x1c]
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xdc
	ldrh r0, [r0]
	strh r0, [r6, #0x20]
_081F3CD6:
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _081F3CFC @ =0x085B0A08
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _081F3D00
	asrs r1, r0, #8
	b _081F3D06
	.align 2, 0
_081F3CFC: .4byte 0x085B0A08
_081F3D00:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081F3D06:
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r0, r0, r1
	mov r3, sb
	strh r0, [r3, #0x1e]
	ldrh r1, [r3, #0x1c]
	subs r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r3, #0x20]
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r1]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	mov r2, sb
	strh r0, [r2, #0x10]
	mov r3, r8
	ldrb r0, [r3, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F3D6A
	mov r1, sb
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	b _081F3D76
_081F3D6A:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F3D76:
	mov r1, r8
	ldrb r0, [r1, #4]
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
	beq _081F3D9E
	mov r2, sb
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	str r0, [r2]
	b _081F3DAA
_081F3D9E:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F3DAA:
	mov r1, r8
	ldrh r0, [r1, #0xe]
	adds r0, #1
	strh r0, [r1, #0xe]
	ldr r3, _081F3DE4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #7]
	cmp r0, r1
	blo _081F3E28
	movs r0, #0
	mov r3, r8
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F3DF0
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F3DE8
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	b _081F3E02
	.align 2, 0
_081F3DE4: .4byte 0x0000FFFF
_081F3DE8:
	subs r0, #1
	mov r1, r8
	strh r0, [r1, #8]
	b _081F3E02
_081F3DF0:
	mov r3, r8
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F3E02
	strh r1, [r3, #8]
_081F3E02:
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F3E28
	movs r0, #1
	strb r0, [r3, #7]
_081F3E28:
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F3E3A
	subs r0, #1
	strh r0, [r1]
	b _081F3E54
_081F3E3A:
	mov r1, sl
	cmp r1, #0
	beq _081F3E54
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
_081F3E54:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f3e64
FUN_081f3e64: @ 0x081F3E64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r2, r0, #0
	adds r6, r1, #0
	mov r8, r6
	adds r5, r6, #0
	adds r5, #0x48
	movs r0, #0xab
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081F3EA6
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #0xe
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r7]
	movs r2, #0xad
	lsls r2, r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_081F3EA6:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x48]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _081F3ED2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F3EDA
_081F3ED2:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F3EDA:
	str r0, [r6]
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
	beq _081F3F00
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F3F0A
_081F3F00:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F3F0A:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F3F44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F3F8A
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F3F4E
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F3F48
	ldrb r0, [r5, #5]
	subs r0, #1
	strh r0, [r5, #8]
	movs r2, #1
	b _081F3F64
	.align 2, 0
_081F3F44: .4byte 0x0000FFFF
_081F3F48:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F3F62
_081F3F4E:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F3F62
	strh r1, [r5, #8]
	movs r2, #1
	b _081F3F64
_081F3F62:
	movs r2, #0
_081F3F64:
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
	bne _081F3F8C
	movs r0, #1
	strb r0, [r5, #7]
	b _081F3F8C
_081F3F8A:
	movs r2, #0
_081F3F8C:
	adds r3, r2, #0
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _081F3FDA
	ldr r2, _081F3FB8 @ =0x085B0A08
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081F3FBC
	asrs r1, r0, #0xc
	b _081F3FC2
	.align 2, 0
_081F3FB8: .4byte 0x085B0A08
_081F3FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F3FC2:
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x1e]
	adds r2, #0x10
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_081F3FDA:
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081F3FEC
	adds r0, #1
	strh r0, [r1]
	b _081F4004
_081F3FEC:
	cmp r3, #0
	beq _081F4004
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #4
	strb r0, [r1]
	movs r0, #0xab
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_081F4004:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f4010
FUN_081f4010: @ 0x081F4010
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r2, r0, #0
	adds r7, r1, #0
	mov sb, r7
	adds r6, r7, #0
	adds r6, #0x48
	movs r0, #0xab
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081F404C
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0xe
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r5]
_081F404C:
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r3, r3, r7
	mov ip, r3
	ldrh r0, [r3]
	cmp r0, #9
	bhi _081F40A6
	ldr r4, _081F4134 @ =0x0203B400
	mov r8, r4
	ldr r3, _081F4138 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _081F413C @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r0, #0x30
	movs r5, #0x3f
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, #0x30
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r7, #0x20]
_081F40A6:
	mov r3, ip
	ldrh r0, [r3]
	cmp r0, #4
	bne _081F4108
	ldr r0, [r7, #0xc]
	movs r1, #0xfe
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	ldr r4, _081F4140 @ =0xFFFFFEAC
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _081F4144 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _081F4148 @ =0x0000015D
	adds r0, r7, r2
	ldrb r2, [r0]
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r4, #0x14
	adds r0, r7, r4
	ldrh r0, [r0]
	str r0, [sp, #8]
	add r0, sp, #0xc
	bl FUN_081f08ec
	adds r0, r7, #0
	bl FUN_081f337c
_081F4108:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x48]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F414C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F4154
	.align 2, 0
_081F4134: .4byte 0x0203B400
_081F4138: .4byte 0x030046B8
_081F413C: .4byte 0x000003FF
_081F4140: .4byte 0xFFFFFEAC
_081F4144: .4byte 0x0000FFFF
_081F4148: .4byte 0x0000015D
_081F414C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F4154:
	str r0, [r7]
	ldrb r0, [r6, #4]
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
	beq _081F417E
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	b _081F418A
_081F417E:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F418A:
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r4, _081F41C0 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081F4206
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F41CA
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081F41C4
	ldrb r0, [r6, #5]
	subs r0, #1
	strh r0, [r6, #8]
	movs r2, #1
	b _081F41E0
	.align 2, 0
_081F41C0: .4byte 0x0000FFFF
_081F41C4:
	subs r0, #1
	strh r0, [r6, #8]
	b _081F41DE
_081F41CA:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081F41DE
	strh r1, [r6, #8]
	movs r2, #1
	b _081F41E0
_081F41DE:
	movs r2, #0
_081F41E0:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r1, [r4]
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
	bne _081F4208
	movs r0, #1
	strb r0, [r6, #7]
	b _081F4208
_081F4206:
	movs r2, #0
_081F4208:
	cmp r2, #0
	beq _081F4248
	movs r3, #0xb4
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	mov r1, sb
	ldr r0, [r1, #0xc]
	movs r1, #0xfb
	bl Video_SetAuxSpritePltt
	ldrh r0, [r4]
	cmp r0, #0
	beq _081F4232
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #2
	b _081F423A
_081F4232:
	movs r3, #0xa9
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #5
_081F423A:
	strb r0, [r1]
	movs r4, #0xab
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	b _081F4254
_081F4248:
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F4254:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f4264
FUN_081f4264: @ 0x081F4264
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
	ldr r0, _081F4284 @ =0x00000173
	adds r6, r2, r0
	adds r4, r2, #0
	adds r4, #0x20
_081F4274:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F4288
	movs r0, #1
	b _081F428A
	.align 2, 0
_081F4284: .4byte 0x00000173
_081F4288:
	movs r0, #0
_081F428A:
	cmp r0, #0
	bne _081F42A6
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x1c]
	adds r0, r4, #0
	movs r1, #0xba
	lsls r1, r1, #1
	bl ClearMemory
	strb r5, [r6]
	adds r0, r4, #0
	b _081F42B6
_081F42A6:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081F4274
	movs r0, #0
_081F42B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f42bc
FUN_081f42bc: @ 0x081F42BC
	push {lr}
	bl FUN_081f4264
	cmp r0, #0
	bne _081F42C8
	movs r0, #0
_081F42C8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081f42cc
FUN_081f42cc: @ 0x081F42CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	mov sb, r2
	adds r5, r3, #0
	ldr r0, _081F4424 @ =0x030001F4
	ldr r6, [r0]
	cmp r6, #0
	bne _081F42F2
	bl Entity081f4554_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F42F2
	b _081F4412
_081F42F2:
	adds r0, r6, #0
	bl FUN_081f42bc
	adds r4, r0, #0
	cmp r4, #0
	bne _081F4300
	b _081F4412
_081F4300:
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	mov r8, r2
	movs r7, #1
	strb r7, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r4, r3
	mov r1, r8
	strh r1, [r0]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #0x18
	adds r0, r4, r3
	strh r5, [r0]
	ldr r0, _081F4428 @ =0x0000015F
	adds r1, r4, r0
	ldr r0, [sp, #0x4c]
	strb r0, [r1]
	adds r2, #0x10
	adds r1, r4, r2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	subs r3, #0xb
	adds r1, r4, r3
	ldr r0, [sp, #0x40]
	strb r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [sp, #0x44]
	str r0, [r1]
	subs r2, #6
	adds r1, r4, r2
	ldr r0, [sp, #0x48]
	strb r0, [r1]
	adds r3, #0xd
	adds r0, r4, r3
	mov r1, sb
	strh r1, [r0]
	subs r2, #8
	adds r0, r4, r2
	strb r7, [r0]
	adds r3, #6
	adds r1, r4, r3
	ldr r0, [sp, #0x50]
	strh r0, [r1]
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [sp, #0x54]
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0x60
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xe0
	lsls r2, r2, #4
	str r2, [sp, #8]
	str r7, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r7, [sp, #0x14]
	mov r2, r8
	str r2, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	ldr r3, _081F442C @ =0x0000015B
	adds r1, r4, r3
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xd0
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xd2
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r1, _081F4430 @ =0x0000D45E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	beq _081F4412
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r4]
	orrs r0, r7
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x48
	ldr r1, [r6, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #0x17
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4, #0xc]
	movs r1, #0xfb
	bl Video_SetAuxSpritePltt
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	strb r7, [r4, #7]
_081F4412:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F4424: .4byte 0x030001F4
_081F4428: .4byte 0x0000015F
_081F442C: .4byte 0x0000015B
_081F4430: .4byte 0x0000D45E

	thumb_func_start Entity081f4554_Update
Entity081f4554_Update: @ 0x081F4434
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x20
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	beq _081F44B8
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F4484 @ =0x030047A4
	ldr r1, _081F4488 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F44B8
	movs r1, #4
	ldr r0, _081F448C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081F44B8
	movs r7, #0
	ldr r0, _081F4490 @ =0x085AE560
	mov r8, r0
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r5, r6, r0
	adds r4, r3, #0
_081F4474:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F4494
	movs r0, #1
	b _081F4496
	.align 2, 0
_081F4484: .4byte 0x030047A4
_081F4488: .4byte 0x030047A0
_081F448C: .4byte 0x03002BC0
_081F4490: .4byte 0x085AE560
_081F4494:
	movs r0, #0
_081F4496:
	cmp r0, #0
	beq _081F44AA
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081F44AA:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, #1
	cmp r7, #3
	ble _081F4474
_081F44B8:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081f4554_Destroy
Entity081f4554_Destroy: @ 0x081F44C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x20
_081F44CE:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F44DE
	movs r0, #1
	b _081F44E0
_081F44DE:
	movs r0, #0
_081F44E0:
	cmp r0, #0
	beq _081F4506
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081F44F0
	adds r0, r4, #0
	bl AuxSprite_Remove
_081F44F0:
	ldr r1, _081F4520 @ =0x0000015B
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _081F4506
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxShadow_Remove
_081F4506:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081F44CE
	movs r1, #0
	ldr r0, _081F4524 @ =0x030001F4
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081F4520: .4byte 0x0000015B
_081F4524: .4byte 0x030001F4

	thumb_func_start Entity081f4554_Init
Entity081f4554_Init: @ 0x081F4528
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081F4548 @ =0x0000922E
	ldr r1, _081F454C @ =0x00001DC3
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	ldr r0, _081F4550 @ =0x030001F4
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F4548: .4byte 0x0000922E
_081F454C: .4byte 0x00001DC3
_081F4550: .4byte 0x030001F4

	thumb_func_start Entity081f4554_Create
Entity081f4554_Create: @ 0x081F4554
	push {r4, lr}
	ldr r0, _081F458C @ =0x030001F4
	ldr r0, [r0]
	cmp r0, #0
	bne _081F459A
	movs r1, #0xbe
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F4598
	ldr r1, _081F4590 @ =Entity081f4554_Update
	ldr r2, _081F4594 @ =Entity081f4554_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f4554_Init
	cmp r0, #0
	bge _081F4598
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F459A
	.align 2, 0
_081F458C: .4byte 0x030001F4
_081F4590: .4byte Entity081f4554_Update
_081F4594: .4byte Entity081f4554_Destroy
_081F4598:
	adds r0, r4, #0
_081F459A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f45a0
FUN_081f45a0: @ 0x081F45A0
	ldr r1, _081F45A8 @ =0x030001F4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F45A8: .4byte 0x030001F4

	thumb_func_start FUN_081f45ac
FUN_081f45ac: @ 0x081F45AC
	push {r4, r5, r6, lr}
	ldr r0, _081F45DC @ =0x030001F4
	ldr r4, [r0]
	cmp r4, #0
	bne _081F45C0
	bl Entity081f4554_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _081F4606
_081F45C0:
	movs r3, #0
	movs r5, #1
	adds r2, r4, #0
	adds r2, #0x20
	movs r6, #0xba
	lsls r6, r6, #1
_081F45CC:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F45E0
	movs r0, #1
	b _081F45E2
	.align 2, 0
_081F45DC: .4byte 0x030001F4
_081F45E0:
	movs r0, #0
_081F45E2:
	cmp r0, #0
	beq _081F45FE
	movs r0, #0xa9
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #5
	beq _081F45FE
	movs r0, #5
	strb r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r2, r1
	strb r5, [r0]
_081F45FE:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #3
	ble _081F45CC
_081F4606:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f460c
FUN_081f460c: @ 0x081F460C
	push {lr}
	ldr r0, _081F4620 @ =0x030001F4
	ldr r0, [r0]
	cmp r0, #0
	bne _081F4628
	bl Entity081f4554_Create
	cmp r0, #0
	bne _081F4628
	b _081F4648
	.align 2, 0
_081F4620: .4byte 0x030001F4
_081F4624:
	movs r0, #0
	b _081F464A
_081F4628:
	movs r1, #0
	movs r3, #1
	ldr r2, [r0, #0x1c]
_081F462E:
	adds r0, r3, #0
	lsls r0, r1
	ands r0, r2
	cmp r0, #0
	beq _081F463C
	movs r0, #1
	b _081F463E
_081F463C:
	movs r0, #0
_081F463E:
	cmp r0, #0
	beq _081F4624
	adds r1, #1
	cmp r1, #3
	ble _081F462E
_081F4648:
	movs r0, #1
_081F464A:
	pop {r1}
	bx r1
	.align 2, 0
