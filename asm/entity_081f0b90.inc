	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f02f0
FUN_081f02f0: @ 0x081F02F0
	push {lr}
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F0304
	movs r1, #0
	bl VM_ExecByID
_081F0304:
	pop {r0}
	bx r0

	thumb_func_start FUN_081f0308
FUN_081f0308: @ 0x081F0308
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f030c
FUN_081f030c: @ 0x081F030C
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
	ldr r2, _081F0390 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _081F0394 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
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
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _081F0398 @ =0x00002001
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
	ldr r1, _081F039C @ =FUN_081f0308
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F0390: .4byte 0xFFFF0000
_081F0394: .4byte 0x0000FFFF
_081F0398: .4byte 0x00002001
_081F039C: .4byte FUN_081f0308

	thumb_func_start FUN_081f03a0
FUN_081f03a0: @ 0x081F03A0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f03a4
FUN_081f03a4: @ 0x081F03A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	mov r8, r1
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F04B4
	movs r7, #0
	movs r0, #0xf8
	add r0, r8
	mov sb, r0
	add r5, sp, #4
	mov r4, r8
	mov r6, r8
	adds r6, #0xb0
_081F03D0:
	ldr r0, [r4]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	lsls r3, r7, #6
	ldr r2, _081F0404 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _081F0408
	asrs r1, r0, #0xc
	b _081F040E
	.align 2, 0
_081F0404: .4byte 0x085B0A08
_081F0408:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F040E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r2, _081F0430 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _081F0434
	asrs r2, r0, #0xc
	b _081F043A
	.align 2, 0
_081F0430: .4byte 0x085B0A08
_081F0434:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F043A:
	strh r2, [r5, #4]
	ldrh r0, [r4, #0x1c]
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #2]
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	ldrh r0, [r4, #0x20]
	adds r0, r2, r0
	strh r0, [r4, #0x20]
	cmp r7, #1
	beq _081F046A
	cmp r7, #1
	bgt _081F0460
	cmp r7, #0
	beq _081F0466
	b _081F0476
_081F0460:
	cmp r7, #2
	beq _081F0470
	b _081F0476
_081F0466:
	movs r2, #2
	b _081F0478
_081F046A:
	movs r2, #2
	movs r0, #1
	b _081F047A
_081F0470:
	movs r2, #0
	movs r0, #1
	b _081F047A
_081F0476:
	movs r2, #0
_081F0478:
	movs r0, #0
_081F047A:
	mov r3, sl
	ldr r1, [r3, #0x34]
	orrs r2, r0
	str r2, [sp]
	adds r0, r6, #0
	movs r2, #0x10
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r4, #0x2c
	adds r6, #0x10
	adds r7, #1
	cmp r7, #3
	ble _081F03D0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	strb r2, [r0]
_081F04B4:
	movs r7, #0
	movs r4, #0xf8
	add r4, r8
	mov sb, r4
	movs r0, #1
	mov ip, r0
	movs r1, #2
	mov sl, r1
	mov r3, r8
	adds r3, #0xb0
_081F04C8:
	movs r0, #0x2c
	adds r4, r7, #0
	muls r4, r0, r4
	add r4, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r3, #4]
	mov r2, ip
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, ip
	ands r0, r1
	cmp r2, r0
	beq _081F04FC
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F0504
_081F04FC:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F0504:
	str r0, [r4]
	ldrb r0, [r3, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081F0528
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F0530
_081F0528:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F0530:
	str r0, [r4]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _081F0568 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _081F05AE
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F0572
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F056C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r6, #1
	b _081F0588
	.align 2, 0
_081F0568: .4byte 0x0000FFFF
_081F056C:
	subs r0, #1
	strh r0, [r3, #8]
	b _081F0586
_081F0572:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F0586
	strh r1, [r3, #8]
	movs r6, #1
	b _081F0588
_081F0586:
	movs r6, #0
_081F0588:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081F05B0
	mov r4, ip
	strb r4, [r3, #7]
	b _081F05B0
_081F05AE:
	movs r6, #0
_081F05B0:
	adds r3, #0x10
	adds r7, #1
	cmp r7, #3
	ble _081F04C8
	movs r4, #0x80
	lsls r4, r4, #1
	add r4, r8
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	cmp r6, #0
	beq _081F05E8
	movs r1, #0xa9
	lsls r1, r1, #1
	add r1, r8
	movs r0, #3
	strb r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _081F05F4
_081F05E8:
	movs r1, #0xac
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F05F4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f0604
FUN_081f0604: @ 0x081F0604
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F066E
	subs r1, #7
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	movs r0, #0xa9
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
_081F0636:
	movs r0, #0x2c
	muls r0, r4, r0
	adds r1, r5, r0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F0648
	adds r0, r1, #0
	bl AuxSprite_Remove
_081F0648:
	adds r4, #1
	cmp r4, #3
	ble _081F0636
	ldr r0, _081F0674 @ =0x00000153
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0x51
	adds r1, r5, r0
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081f02f0
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r4, [r0]
_081F066E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081F0674: .4byte 0x00000153

	thumb_func_start FUN_081f0678
FUN_081f0678: @ 0x081F0678
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r1
	movs r4, #0xad
	lsls r4, r4, #1
	add r4, r8
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F069C
	ldr r0, _081F06F4 @ =0x000003B1
	bl PlaySound_082406e0
	movs r0, #0
	strb r0, [r4]
_081F069C:
	movs r0, #0
	mov ip, r0
	mov r1, r8
	adds r1, #0xf0
	str r1, [sp]
	movs r2, #1
	mov sl, r2
	mov r4, r8
	adds r4, #0xb0
	ldr r3, _081F06F8 @ =0x030047C8
	mov sb, r3
_081F06B2:
	movs r0, #0x2c
	mov r6, ip
	muls r6, r0, r6
	adds r0, r6, #0
	mov r1, r8
	adds r7, r1, r0
	ldr r3, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r3, r0
	str r3, [r7]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r6, sl
	ands r0, r6
	cmp r2, r0
	beq _081F06FC
	movs r0, #4
	orrs r3, r0
	b _081F0702
	.align 2, 0
_081F06F4: .4byte 0x000003B1
_081F06F8: .4byte 0x030047C8
_081F06FC:
	movs r0, #5
	rsbs r0, r0, #0
	ands r3, r0
_081F0702:
	str r3, [r7]
	ldrb r0, [r4, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _081F0726
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F072E
_081F0726:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F072E:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081F0764 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081F079C
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F0768
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F075E
	ldrb r0, [r4, #5]
_081F075E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F0778
	.align 2, 0
_081F0764: .4byte 0x0000FFFF
_081F0768:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F0778
	strh r1, [r4, #8]
_081F0778:
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
	bne _081F079C
	mov r3, sl
	strb r3, [r4, #7]
_081F079C:
	adds r5, r7, #0
	adds r5, #0x1c
	ldr r6, [sp]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F07BE
	asrs r0, r0, #8
	b _081F07C4
_081F07BE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F07C4:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F07D6
	asrs r0, r0, #8
	b _081F07DC
_081F07D6:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F07DC:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081F07F0
	asrs r0, r0, #8
	b _081F07F6
_081F07F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F07F6:
	subs r2, r3, r0
	strh r2, [r5, #2]
	adds r3, r3, r0
	strh r3, [r5, #4]
	ldrh r0, [r5]
	mov r6, sb
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r5, #4]
	mov r1, ip
	lsls r0, r1, #5
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	adds r4, #0x10
	movs r3, #1
	add ip, r3
	mov r6, ip
	cmp r6, #2
	bgt _081F0830
	b _081F06B2
_081F0830:
	movs r5, #0xac
	lsls r5, r5, #1
	add r5, r8
	ldrh r0, [r5]
	cmp r0, #4
	bls _081F0852
	movs r1, #0xa9
	lsls r1, r1, #1
	add r1, r8
	movs r0, #2
	strb r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _081F0870
_081F0852:
	movs r4, #0x80
	lsls r4, r4, #1
	add r4, r8
	mov r1, r8
	adds r1, #0xf8
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_081F0870:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f0880
FUN_081f0880: @ 0x081F0880
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
	movs r7, #0xae
	lsls r7, r7, #1
	ldr r0, _081F08A4 @ =0x0000018F
	adds r6, r2, r0
	adds r4, r2, #0
	adds r4, #0x3c
_081F0894:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F08A8
	movs r0, #1
	b _081F08AA
	.align 2, 0
_081F08A4: .4byte 0x0000018F
_081F08A8:
	movs r0, #0
_081F08AA:
	cmp r0, #0
	bne _081F08C4
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x38]
	adds r0, r4, #0
	adds r1, r7, #0
	bl ClearMemory
	strb r5, [r6]
	adds r0, r4, #0
	b _081F08D4
_081F08C4:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081F0894
	movs r0, #0
_081F08D4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f08dc
FUN_081f08dc: @ 0x081F08DC
	push {lr}
	bl FUN_081f0880
	cmp r0, #0
	bne _081F08E8
	movs r0, #0
_081F08E8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081f08ec
FUN_081f08ec: @ 0x081F08EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sl, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, _081F0994 @ =0x030001E4
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _081F0916
	bl Entity081f0b90_Create
	mov r8, r0
	cmp r0, #0
	bne _081F0916
	b _081F0A8A
_081F0916:
	mov r0, r8
	bl FUN_081f08dc
	adds r7, r0, #0
	cmp r7, #0
	bne _081F0924
	b _081F0A8A
_081F0924:
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	adds r3, #8
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0xf0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	adds r2, r7, #0
	adds r2, #0xf8
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0xfa
	ldr r3, _081F0998 @ =0xFFFFFD00
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	add r5, sp, #4
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F099C
	asrs r0, r0, #8
	b _081F09A2
	.align 2, 0
_081F0994: .4byte 0x030001E4
_081F0998: .4byte 0xFFFFFD00
_081F099C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F09A2:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F09B4
	asrs r0, r0, #8
	b _081F09BA
_081F09B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F09BA:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r6, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081F09CE
	asrs r0, r0, #8
	b _081F09D4
_081F09CE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F09D4:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _081F0A9C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	movs r6, #0
	mov r5, r8
	adds r5, #0x18
_081F09F8:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, r7, r4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r4]
	movs r1, #0x11
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
	strb r0, [r4, #7]
	adds r6, #1
	cmp r6, #3
	ble _081F09F8
	movs r6, #0
	ldr r0, _081F0AA0 @ =0x030046B8
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0xb0
_081F0A26:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, r7, r4
	mov r2, r8
	ldr r1, [r2, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0xf
	movs r3, #0
	bl AuxAnim_SetAnim
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F0AA4 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _081F0AA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	strh r0, [r5, #8]
	ldr r0, [r4, #0xc]
	movs r1, #0xfa
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	lsls r0, r6, #5
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	adds r5, #0x10
	adds r6, #1
	cmp r6, #2
	ble _081F0A26
	ldr r0, [sp, #0x34]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl FUN_081f030c
_081F0A8A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F0A9C: .4byte 0x030047C8
_081F0AA0: .4byte 0x030046B8
_081F0AA4: .4byte 0x000003FF
_081F0AA8: .4byte 0x0203B400

	thumb_func_start Entity081f0b90_Update
Entity081f0b90_Update: @ 0x081F0AAC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	movs r4, #0
	ldr r7, _081F0AC8 @ =0x085AE518
_081F0AB8:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0ACC
	movs r0, #1
	b _081F0ACE
	.align 2, 0
_081F0AC8: .4byte 0x085AE518
_081F0ACC:
	movs r0, #0
_081F0ACE:
	cmp r0, #0
	beq _081F0AF0
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F0AF0:
	adds r4, #1
	cmp r4, #3
	ble _081F0AB8
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f0b90_Destroy
Entity081f0b90_Destroy: @ 0x081F0B00
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r2, #0
_081F0B06:
	movs r1, #1
	lsls r1, r2
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0B16
	movs r0, #1
	b _081F0B18
_081F0B16:
	movs r0, #0
_081F0B18:
	adds r6, r2, #1
	cmp r0, #0
	beq _081F0B42
	movs r0, #0xae
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, #0x3c
	adds r5, r7, r0
	movs r4, #0
_081F0B2A:
	movs r0, #0x2c
	muls r0, r4, r0
	adds r1, r5, r0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F0B3C
	adds r0, r1, #0
	bl AuxSprite_Remove
_081F0B3C:
	adds r4, #1
	cmp r4, #3
	ble _081F0B2A
_081F0B42:
	adds r2, r6, #0
	cmp r2, #3
	ble _081F0B06
	ldr r1, _081F0B54 @ =0x030001E4
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F0B54: .4byte 0x030001E4

	thumb_func_start Entity081f0b90_Init
Entity081f0b90_Init: @ 0x081F0B58
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081F0B80 @ =0x0000D45E
	bl Video_GetAuxSprite
	ldr r0, _081F0B84 @ =0x0000922E
	ldr r1, _081F0B88 @ =0x00001DC3
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _081F0B8C @ =0x030001E4
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F0B80: .4byte 0x0000D45E
_081F0B84: .4byte 0x0000922E
_081F0B88: .4byte 0x00001DC3
_081F0B8C: .4byte 0x030001E4

	thumb_func_start Entity081f0b90_Create
Entity081f0b90_Create: @ 0x081F0B90
	push {r4, lr}
	ldr r0, _081F0BC4 @ =0x030001E4
	ldr r0, [r0]
	cmp r0, #0
	bne _081F0BD6
	ldr r1, _081F0BC8 @ =0x000005AC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F0BD4
	ldr r1, _081F0BCC @ =Entity081f0b90_Update
	ldr r2, _081F0BD0 @ =Entity081f0b90_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f0b90_Init
	cmp r0, #0
	bge _081F0BD4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F0BD6
	.align 2, 0
_081F0BC4: .4byte 0x030001E4
_081F0BC8: .4byte 0x000005AC
_081F0BCC: .4byte Entity081f0b90_Update
_081F0BD0: .4byte Entity081f0b90_Destroy
_081F0BD4:
	adds r0, r4, #0
_081F0BD6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f0bdc
FUN_081f0bdc: @ 0x081F0BDC
	ldr r1, _081F0BE4 @ =0x030001E4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F0BE4: .4byte 0x030001E4
