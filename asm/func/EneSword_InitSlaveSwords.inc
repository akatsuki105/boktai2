	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r2, _0819A61C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _0819A620 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819A6D4
	bl VM_GetPC
	cmp r0, #0
	beq _0819A624
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A626
	.align 2, 0
_0819A61C: .4byte 0xFFFF0000
_0819A620: .4byte 0x0000FFFF
_0819A624:
	movs r1, #0
_0819A626:
	ldr r2, _0819A63C @ =0x00000C84
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A640
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A642
	.align 2, 0
_0819A63C: .4byte 0x00000C84
_0819A640:
	movs r1, #0
_0819A642:
	ldr r3, _0819A658 @ =0x00000C86
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A65C
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A65E
	.align 2, 0
_0819A658: .4byte 0x00000C86
_0819A65C:
	movs r1, #0
_0819A65E:
	ldr r2, _0819A674 @ =0x00000C88
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A678
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A67A
	.align 2, 0
_0819A674: .4byte 0x00000C88
_0819A678:
	movs r1, #0
_0819A67A:
	ldr r3, _0819A690 @ =0x00000C8A
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A694
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A696
	.align 2, 0
_0819A690: .4byte 0x00000C8A
_0819A694:
	movs r1, #0
_0819A696:
	ldr r2, _0819A6AC @ =0x00000CEA
	adds r0, r6, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A6B0
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A6B2
	.align 2, 0
_0819A6AC: .4byte 0x00000CEA
_0819A6B0:
	movs r1, #0
_0819A6B2:
	ldr r3, _0819A6C8 @ =0x00000C8C
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A6CC
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A6CE
	.align 2, 0
_0819A6C8: .4byte 0x00000C8C
_0819A6CC:
	movs r1, #0
_0819A6CE:
	ldr r2, _0819A6F0 @ =0x00000C8E
	adds r0, r6, r2
	strh r1, [r0]
_0819A6D4:
	movs r0, #0x43
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819A750
	bl VM_GetPC
	cmp r0, #0
	beq _0819A6F4
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A6F6
	.align 2, 0
_0819A6F0: .4byte 0x00000C8E
_0819A6F4:
	movs r1, #0
_0819A6F6:
	movs r3, #0xc9
	lsls r3, r3, #4
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A70E
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A710
_0819A70E:
	movs r1, #0
_0819A710:
	ldr r2, _0819A728 @ =0x00000C92
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A72C
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A72E
	.align 2, 0
_0819A728: .4byte 0x00000C92
_0819A72C:
	movs r1, #0
_0819A72E:
	ldr r3, _0819A744 @ =0x00000C94
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A748
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A74A
	.align 2, 0
_0819A744: .4byte 0x00000C94
_0819A748:
	movs r1, #0
_0819A74A:
	ldr r2, _0819A764 @ =0x00000C96
	adds r0, r6, r2
	strh r1, [r0]
_0819A750:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819A76C
	bl VM_GetValue
	ldr r3, _0819A768 @ =0x00000C9C
	adds r1, r6, r3
	b _0819A772
	.align 2, 0
_0819A764: .4byte 0x00000C96
_0819A768: .4byte 0x00000C9C
_0819A76C:
	ldr r0, _0819A8F8 @ =0x00000C9C
	adds r1, r6, r0
	movs r0, #4
_0819A772:
	strb r0, [r1]
	movs r1, #0
	str r1, [sp, #0x1c]
	mov sb, r1
	ldr r2, _0819A8FC @ =0x000004EC
	adds r2, r2, r6
	mov r8, r2
	ldr r3, _0819A900 @ =0x0000049C
	adds r7, r6, r3
	ldr r0, _0819A904 @ =0x00000564
	adds r4, r6, r0
	ldr r1, _0819A908 @ =0x00000454
	adds r1, r6, r1
	str r1, [sp, #0x28]
	ldr r2, _0819A90C @ =0x0000053C
	adds r5, r6, r2
	subs r3, #0x1c
	adds r3, r6, r3
	str r3, [sp, #0x2c]
	mov sl, r1
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x20]
	mov r1, sp
	adds r1, #0x14
	str r1, [sp, #0x24]
_0819A7A6:
	mov r2, sb
	strh r2, [r5]
	strh r2, [r5, #2]
	strh r2, [r5, #4]
	strh r2, [r5, #8]
	movs r3, #1
	strh r3, [r5, #0xa]
	strh r2, [r5, #0xc]
	movs r0, #0
	strb r0, [r4, #1]
	strh r2, [r5, #0x1a]
	strb r0, [r4, #2]
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	strh r2, [r4, #0xe]
	strh r2, [r4, #0x10]
	mov r1, sb
	str r1, [r4, #0x50]
	ldr r0, [sp, #0x2c]
	ldr r1, _0819A910 @ =0x00005292
	bl Video_GetAuxSprite
	mov r0, sl
	ldr r1, [sp, #0x2c]
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	ldr r2, [sp, #0x28]
	str r0, [r2]
	ldr r0, [r2, #0xc]
	ldr r3, _0819A914 @ =0x00000CC6
	adds r1, r6, r3
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	mov r0, sp
	ldrb r0, [r0, #0x1c]
	strb r0, [r4]
	movs r1, #0
	strb r1, [r4, #6]
	strb r1, [r4, #7]
	ldrb r1, [r4, #1]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #1]
	str r6, [r4, #0x48]
	movs r0, #0x14
	str r0, [r4, #0x68]
	mov r2, sb
	str r2, [r4, #0x6c]
	movs r3, #0x10
	str r3, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	ldr r2, _0819A918 @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	ldr r1, _0819A91C @ =EneSword_OnSlaveSwordHit
	mov r2, sl
	bl Hitbox_SetHandler
	adds r0, r7, #0
	bl Hitbox_Register
	movs r2, #0xc9
	lsls r2, r2, #4
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, #2
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r3, _0819A920 @ =0x00000C94
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	ldr r3, _0819A924 @ =0x00000C96
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #0x80
	lsls r3, r3, #3
	bl Hitbox_SetAttack
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	movs r2, #0x10
	str r2, [sp]
	ldr r3, [sp, #0x20]
	str r3, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	mov r0, r8
	movs r1, #0
	ldr r2, _0819A928 @ =0x00005009
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0819A92C @ =0x00000C86
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0819A930 @ =0x00000C8C
	adds r0, r6, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	str r2, [sp, #0x30]
	ldr r2, _0819A934 @ =0x00000C8E
	adds r0, r6, r2
	movs r2, #0
	ldrsh r3, [r0, r2]
	mov ip, r3
	mov r0, r8
	ldr r2, [sp, #0x30]
	bl Hitbox_SetPowerAndAttributes
	mov r0, r8
	ldr r1, _0819A938 @ =EneSword_OnSlaveSwordHurt
	mov r2, sl
	bl Hitbox_SetHandler
	mov r0, r8
	bl Hitbox_Register
	mov r3, r8
	ldrh r0, [r3, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r3, #6]
	movs r2, #0xc6
	lsls r2, r2, #1
	add r8, r2
	adds r7, r7, r2
	adds r4, r4, r2
	ldr r3, [sp, #0x28]
	adds r3, r3, r2
	str r3, [sp, #0x28]
	adds r5, r5, r2
	ldr r0, [sp, #0x2c]
	adds r0, r0, r2
	str r0, [sp, #0x2c]
	add sl, r2
	ldr r1, [sp, #0x1c]
	adds r1, #1
	str r1, [sp, #0x1c]
	cmp r1, #3
	bgt _0819A8E8
	b _0819A7A6
_0819A8E8:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819A8F8: .4byte 0x00000C9C
_0819A8FC: .4byte 0x000004EC
_0819A900: .4byte 0x0000049C
_0819A904: .4byte 0x00000564
_0819A908: .4byte 0x00000454
_0819A90C: .4byte 0x0000053C
_0819A910: .4byte 0x00005292
_0819A914: .4byte 0x00000CC6
_0819A918: .4byte 0x00002001
_0819A91C: .4byte EneSword_OnSlaveSwordHit
_0819A920: .4byte 0x00000C94
_0819A924: .4byte 0x00000C96
_0819A928: .4byte 0x00005009
_0819A92C: .4byte 0x00000C86
_0819A930: .4byte 0x00000C8C
_0819A934: .4byte 0x00000C8E
_0819A938: .4byte EneSword_OnSlaveSwordHurt
