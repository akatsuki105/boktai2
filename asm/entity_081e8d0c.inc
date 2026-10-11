	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081e85bc
FUN_081e85bc: @ 0x081E85BC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e85c0
FUN_081e85c0: @ 0x081E85C0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r2, _081E864C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081E8650 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x44
	ldr r2, _081E8654 @ =0x00002101
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, _081E8658 @ =0x00008020
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081E865C @ =FUN_081e85bc
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
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E864C: .4byte 0xFFFF0000
_081E8650: .4byte 0x0000FFFF
_081E8654: .4byte 0x00002101
_081E8658: .4byte 0x00008020
_081E865C: .4byte FUN_081e85bc

	thumb_func_start FUN_081e8660
FUN_081e8660: @ 0x081E8660
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e8664
FUN_081e8664: @ 0x081E8664
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r6, #0
	adds r0, r6, #0
	adds r0, #0x9c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081E8682
	movs r2, #0
	cmp r0, #0x28
	ble _081E8682
	movs r2, #1
_081E8682:
	adds r4, r6, #0
	adds r4, #0x9c
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _081E86AC @ =0x085AE44C
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081E86B4
	ldr r1, [r5]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081E86B0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081E86B2
	.align 2, 0
_081E86AC: .4byte 0x085AE44C
_081E86B0:
	orrs r1, r2
_081E86B2:
	str r1, [r5]
_081E86B4:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x5a
	ble _081E86DE
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r6, #0
	adds r0, #0x97
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r1, r6, #0
	adds r1, #0x96
	movs r0, #0
	strb r0, [r1]
_081E86DE:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e86ec
FUN_081e86ec: @ 0x081E86EC
	push {r4, r5, lr}
	adds r4, r1, #0
	bl FUN_081e8664
	adds r5, r4, #0
	adds r5, #0x44
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8710
FUN_081e8710: @ 0x081E8710
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r7, #0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0x20
	adds r0, r7, #0
	adds r0, #0x94
	movs r2, #0
	ldrsh r0, [r0, r2]
	ands r0, r1
	cmp r0, #0
	beq _081E8744
	movs r0, #1
	b _081E8746
_081E8744:
	movs r0, #0
_081E8746:
	cmp r0, #0
	bne _081E874E
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_081E874E:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _081E877A
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081E8782
_081E877A:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8782:
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
	beq _081E87A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E87AE
_081E87A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E87AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081E87E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E882E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E87F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E87EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E8808
	.align 2, 0
_081E87E8: .4byte 0x0000FFFF
_081E87EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E8806
_081E87F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E8806
	strh r1, [r4, #8]
	movs r2, #1
	b _081E8808
_081E8806:
	movs r2, #0
_081E8808:
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
	bne _081E8830
	movs r0, #1
	strb r0, [r4, #7]
	b _081E8830
_081E882E:
	movs r2, #0
_081E8830:
	cmp r2, #0
	beq _081E886A
	adds r1, r7, #0
	adds r1, #0x9c
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r4, r7, #0
	adds r4, #0x97
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0
	mov r3, r8
	ldr r0, [r3, #0x38]
	bics r0, r1
	str r0, [r3, #0x38]
	adds r0, r7, #0
	adds r0, #0x96
	strb r2, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r4]
	b _081E8A2A
_081E886A:
	movs r2, #0x20
	adds r1, r7, #0
	adds r1, #0x94
	movs r3, #0
	ldrsh r0, [r1, r3]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081E8880
	movs r0, #1
	b _081E8882
_081E8880:
	movs r0, #0
_081E8882:
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _081E888E
	b _081E8A16
_081E888E:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r2, sp
	adds r3, r7, #0
	adds r3, #0x3c
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7, #0x3c]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r7, #0x3e]
	subs r0, #1
	strh r0, [r7, #0x3e]
	mov r5, r8
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E88E4
	cmp r1, #0
	blt _081E88E4
	ldr r0, _081E88E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E88E4
	ldr r0, _081E88EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E88F0
_081E88E4:
	movs r4, #0
	b _081E88FE
	.align 2, 0
_081E88E8: .4byte 0x030046A8
_081E88EC: .4byte 0x030046AC
_081E88F0:
	ldr r0, _081E8910 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E88FE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E8914
	adds r0, #4
	b _081E8920
	.align 2, 0
_081E8910: .4byte 0x030046A4
_081E8914:
	ldr r0, _081E8934 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E8920:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E8938
	cmp r2, #2
	beq _081E893C
	b _081E8940
	.align 2, 0
_081E8934: .4byte 0x030046A4
_081E8938:
	ldrb r0, [r5, #4]
	b _081E893E
_081E893C:
	ldrb r0, [r5]
_081E893E:
	subs r1, r1, r0
_081E8940:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E896E
	cmp r1, #0
	blt _081E896E
	ldr r0, _081E8974 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E896E
	ldr r0, _081E8978 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E897C
_081E896E:
	movs r4, #0
	b _081E898A
	.align 2, 0
_081E8974: .4byte 0x030046A8
_081E8978: .4byte 0x030046AC
_081E897C:
	ldr r0, _081E899C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E898A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E89A0
	adds r0, #4
	b _081E89AC
	.align 2, 0
_081E899C: .4byte 0x030046A4
_081E89A0:
	ldr r0, _081E89C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E89AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E89C4
	cmp r2, #2
	beq _081E89C8
	b _081E89CC
	.align 2, 0
_081E89C0: .4byte 0x030046A4
_081E89C4:
	ldrb r0, [r5, #4]
	b _081E89CA
_081E89C8:
	ldrb r0, [r5]
_081E89CA:
	subs r1, r1, r0
_081E89CC:
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r3, #0x1e
	ldrsh r1, [r6, r3]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _081E89EE
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _081E8A16
_081E89EE:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x3c]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	adds r3, r7, #0
	adds r3, #0x40
	ldrh r0, [r6, #0x20]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x20
	orrs r0, r1
	mov r1, sl
	strh r0, [r1]
	strh r2, [r7, #0x3c]
	strh r2, [r7, #0x3e]
	strh r2, [r3]
_081E8A16:
	adds r4, r7, #0
	adds r4, #0x44
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081E8A2A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e8a3c
FUN_081e8a3c: @ 0x081E8A3C
	push {r4, r5, r6, lr}
	mov ip, r0
	movs r2, #0
	movs r5, #1
	mov r3, ip
	adds r3, #0xd3
	mov r4, ip
	adds r4, #0x3c
_081E8A4C:
	adds r0, r5, #0
	lsls r0, r2
	mov r6, ip
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8A5E
	movs r0, #1
	b _081E8A60
_081E8A5E:
	movs r0, #0
_081E8A60:
	cmp r0, #0
	bne _081E8A74
	adds r0, r5, #0
	lsls r0, r2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #0x38]
	strb r2, [r3]
	adds r0, r4, #0
	b _081E8A80
_081E8A74:
	adds r3, #0xa0
	adds r4, #0xa0
	adds r2, #1
	cmp r2, #3
	ble _081E8A4C
	movs r0, #0
_081E8A80:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8a88
FUN_081e8a88: @ 0x081E8A88
	push {lr}
	bl FUN_081e8a3c
	cmp r0, #0
	bne _081E8A94
	movs r0, #0
_081E8A94:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8a98
FUN_081e8a98: @ 0x081E8A98
	push {lr}
	adds r1, r0, #0
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bgt _081E8AB0
	cmp r1, #1
	blt _081E8AB0
	movs r0, #1
	b _081E8AB2
_081E8AB0:
	movs r0, #0
_081E8AB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8ab8
FUN_081e8ab8: @ 0x081E8AB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r7, r1, #0
	mov sb, r2
	adds r5, r3, #0
	cmp r4, #0
	bne _081E8AD0
	b _081E8C42
_081E8AD0:
	bl FUN_081e8a88
	adds r6, r0, #0
	cmp r6, #0
	bne _081E8ADC
	b _081E8C42
_081E8ADC:
	adds r1, r6, #0
	adds r1, #0x98
	adds r0, r7, #0
	adds r0, #8
	str r0, [r1]
	subs r1, #2
	movs r0, #0
	mov r8, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x94
	mov r1, r8
	strh r1, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x2c]
	ldr r3, [sp, #0x30]
	bl FUN_081e85c0
	adds r5, r6, #0
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldrb r0, [r7, #5]
	bl FUN_081e8a98
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0x2c
	ldr r1, [r4, #0x34]
	str r0, [sp]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r2, sb
	ldrb r0, [r2, #4]
	cmp r0, #3
	bls _081E8B4C
	mov r3, r8
	strh r3, [r5, #0x3c]
	strh r3, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x40
	strh r3, [r0]
	b _081E8C38
_081E8B4C:
	mov r1, sb
	ldr r0, [r1, #0x38]
	add r2, sp, #4
	adds r4, r5, #0
	adds r4, #0x1c
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r2, r5, #0
	adds r2, #0x86
	strb r0, [r2]
	ldr r3, _081E8BA8 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081E8BAC
	asrs r0, r0, #0xc
	b _081E8BB2
	.align 2, 0
_081E8BA8: .4byte 0x085B0A08
_081E8BAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E8BB2:
	strh r0, [r6, #0x3c]
	ldr r1, _081E8BD0 @ =0x085B0A08
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081E8BD4
	asrs r0, r0, #0xc
	b _081E8BDA
	.align 2, 0
_081E8BD0: .4byte 0x085B0A08
_081E8BD4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E8BDA:
	adds r4, r6, #0
	adds r4, #0x40
	strh r0, [r4]
	movs r2, #0
	movs r7, #0
	movs r3, #0x3c
	ldrsh r0, [r6, r3]
	cmp r0, #0
	beq _081E8BFC
	add r0, sp, #4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x3c
	ldrsh r1, [r6, r2]
	bl Div
	adds r2, r0, #0
_081E8BFC:
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _081E8C18
	add r0, sp, #4
	movs r1, #4
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r4, r3]
	str r2, [sp, #0xc]
	bl Div
	adds r7, r0, #0
	ldr r2, [sp, #0xc]
_081E8C18:
	cmp r2, r7
	ble _081E8C28
	cmp r2, #0
	blt _081E8C24
	asrs r0, r2, #1
	b _081E8C36
_081E8C24:
	rsbs r0, r2, #0
	b _081E8C32
_081E8C28:
	cmp r7, #0
	blt _081E8C30
	asrs r0, r7, #1
	b _081E8C36
_081E8C30:
	rsbs r0, r7, #0
_081E8C32:
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081E8C36:
	strh r0, [r6, #0x3e]
_081E8C38:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
_081E8C42:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity081e8d0c_Update
Entity081e8d0c_Update: @ 0x081E8C50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _081E8C78 @ =0x085AE450
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0xd2
	adds r4, r6, #0
	adds r4, #0x3c
_081E8C66:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8C7C
	movs r0, #1
	b _081E8C7E
	.align 2, 0
_081E8C78: .4byte 0x085AE450
_081E8C7C:
	movs r0, #0
_081E8C7E:
	cmp r0, #0
	beq _081E8C92
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081E8C92:
	adds r5, #0xa0
	adds r4, #0xa0
	adds r7, #1
	cmp r7, #3
	ble _081E8C66
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081e8d0c_Destroy
Entity081e8d0c_Destroy: @ 0x081E8CA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x3c
_081E8CB2:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8CC2
	movs r0, #1
	b _081E8CC4
_081E8CC2:
	movs r0, #0
_081E8CC4:
	cmp r0, #0
	beq _081E8CCE
	adds r0, r4, #0
	bl AuxSprite_Remove
_081E8CCE:
	adds r4, #0xa0
	adds r5, #1
	cmp r5, #3
	ble _081E8CB2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081e8d0c_Init
Entity081e8d0c_Init: @ 0x081E8CE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081E8D00 @ =0x0000E74B
	bl Video_GetAuxSprite
	ldr r0, _081E8D04 @ =0x0000922E
	ldr r1, _081E8D08 @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E8D00: .4byte 0x0000E74B
_081E8D04: .4byte 0x0000922E
_081E8D08: .4byte 0x0000871C

	thumb_func_start Entity081e8d0c_Create
Entity081e8d0c_Create: @ 0x081E8D0C
	push {r4, lr}
	movs r1, #0xaf
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E8D44
	ldr r1, _081E8D3C @ =Entity081e8d0c_Update
	ldr r2, _081E8D40 @ =Entity081e8d0c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081e8d0c_Init
	cmp r0, #0
	bge _081E8D44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E8D46
	.align 2, 0
_081E8D3C: .4byte Entity081e8d0c_Update
_081E8D40: .4byte Entity081e8d0c_Destroy
_081E8D44:
	adds r0, r4, #0
_081E8D46:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8d4c
FUN_081e8d4c: @ 0x081E8D4C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	ldrh r1, [r5, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081E8D62
	b _081E8E72
_081E8D62:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _081E8D6E
	b _081E8E72
_081E8D6E:
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _081E8E2A
	ldrb r2, [r2, #2]
	ldr r0, [r5, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081E8DC4
	adds r2, #0x20
	movs r0, #0xff
	ands r2, r0
	cmp r2, #0
	blt _081E8D94
	asrs r0, r2, #6
	b _081E8D9A
_081E8D94:
	rsbs r0, r2, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8D9A:
	adds r2, r0, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081E8DB2
	asrs r0, r1, #6
	b _081E8DB8
_081E8DB2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8DB8:
	subs r0, r2, r0
	cmp r0, #0
	bge _081E8DC0
	rsbs r0, r0, #0
_081E8DC0:
	cmp r0, #2
	bne _081E8DC8
_081E8DC4:
	movs r0, #1
	b _081E8DCA
_081E8DC8:
	movs r0, #0
_081E8DCA:
	cmp r0, #0
	beq _081E8E72
	movs r0, #3
	strb r0, [r3]
	adds r1, r3, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	cmp r0, #0
	blt _081E8E14
	asrs r0, r0, #5
	b _081E8E1A
_081E8E14:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E1A:
	strh r0, [r6, #0x22]
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	b _081E8E72
_081E8E2A:
	movs r0, #3
	strb r0, [r3]
	adds r0, r3, #0
	adds r0, #0xe6
	strh r4, [r0]
	add r2, sp, #8
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	cmp r0, #0
	blt _081E8E6A
	asrs r0, r0, #5
	b _081E8E70
_081E8E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E70:
	strh r0, [r6, #0x22]
_081E8E72:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e8e7c
FUN_081e8e7c: @ 0x081E8E7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	adds r5, r7, #0
	adds r5, #0x14
	ldr r2, _081E8F14 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081E8F18 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0xea
	ldrh r1, [r0]
	ldr r2, _081E8F1C @ =0x00002301
	str r4, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, _081E8F20 @ =0x00004010
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x10
	bl Hitbox_SetAttack
	adds r1, r7, #0
	adds r1, #0x80
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081E8F24 @ =FUN_081e8d4c
	adds r0, r5, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldrb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0x56
	strb r1, [r0]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E8F14: .4byte 0xFFFF0000
_081E8F18: .4byte 0x0000FFFF
_081E8F1C: .4byte 0x00002301
_081E8F20: .4byte 0x00004010
_081E8F24: .4byte FUN_081e8d4c

	thumb_func_start FUN_081e8f28
FUN_081e8f28: @ 0x081E8F28
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e8f2c
FUN_081e8f2c: @ 0x081E8F2C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081E8F7A
	ldr r0, [r5, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #3
	strh r0, [r1]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	strb r0, [r5]
	ldrb r0, [r5, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r1, [r6, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #2
	bl AuxAnim_RestartAnim
_081E8F7A:
	adds r1, r5, #0
	adds r1, #0xee
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bgt _081E8F94
	ldr r0, [r5, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x64]
	b _081E8F98
_081E8F94:
	subs r0, r2, #1
	strh r0, [r1]
_081E8F98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8fa0
FUN_081e8fa0: @ 0x081E8FA0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	adds r5, r3, #0
	adds r4, r0, #0
	adds r4, #0xcc
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
	beq _081E8FE2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081E8FEA
_081E8FE2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8FEA:
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
	beq _081E900E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081E9016
_081E900E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9016:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E904C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E9084
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9050
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9046
	ldrb r0, [r4, #5]
_081E9046:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9060
	.align 2, 0
_081E904C: .4byte 0x0000FFFF
_081E9050:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9060
	strh r1, [r4, #8]
_081E9060:
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
	bne _081E9084
	movs r0, #1
	strb r0, [r4, #7]
_081E9084:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
