	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08189980 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189984
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189986
	.align 2, 0
_08189980: .4byte 0x0000046D
_08189984:
	movs r0, #0
_08189986:
	cmp r0, #0
	beq _081899BE
	ldr r0, _081899F0 @ =0x00000E3C
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081899F4 @ =0x00000E3D
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081899F8 @ =0x00000D78
	adds r1, r6, r2
	movs r0, #0x40
	strh r0, [r1]
	movs r1, #0xd4
	lsls r1, r1, #1
	ldr r2, _081899FC @ =0x000001A3
	adds r0, r5, #0
	movs r3, #0x40
	bl FUN_08192fe4
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, _08189A00 @ =0x00000F2C
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081899BE:
	mov r2, r8
	cmp r2, #0x13
	bgt _08189A6C
	ldrb r0, [r5, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081899F0 @ =0x00000E3C
	adds r0, r6, r2
	mov r4, sp
	ldrb r7, [r0]
	ldr r2, _08189A04 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189A08
	asrs r1, r0, #0xc
	b _08189A0E
	.align 2, 0
_081899F0: .4byte 0x00000E3C
_081899F4: .4byte 0x00000E3D
_081899F8: .4byte 0x00000D78
_081899FC: .4byte 0x000001A3
_08189A00: .4byte 0x00000F2C
_08189A04: .4byte gSineTable
_08189A08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189A0E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189A26
	asrs r0, r0, #0xc
	b _08189A2C
_08189A26:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08189A2C:
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	strh r0, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	strh r0, [r5, #0xc]
	mov r0, r8
	movs r1, #5
	bl Mod
	cmp r0, #0
	beq _08189A50
	b _08189B56
_08189A50:
	ldr r1, _08189A68 @ =0x00000E3C
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #2
	strb r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #0xa
	strh r0, [r1]
	b _08189B56
	.align 2, 0
_08189A68: .4byte 0x00000E3C
_08189A6C:
	mov r0, r8
	cmp r0, #0x29
	bgt _08189A82
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08189B56
_08189A82:
	mov r2, r8
	cmp r2, #0x3f
	bgt _08189B56
	ldrb r3, [r5, #5]
	ldr r1, _08189AB0 @ =0x00000E3C
	adds r0, r6, r1
	mov r4, sp
	ldrb r7, [r0]
	ldr r2, _08189AB4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189AB8
	asrs r1, r0, #0xc
	b _08189ABE
	.align 2, 0
_08189AB0: .4byte 0x00000E3C
_08189AB4: .4byte gSineTable
_08189AB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189ABE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189AD6
	asrs r0, r0, #0xc
	b _08189ADC
_08189AD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08189ADC:
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	strh r0, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r1, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	ldr r1, _08189B10 @ =0x00000E3D
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08189B14
	asrs r2, r0, #0xc
	b _08189B1A
	.align 2, 0
_08189B10: .4byte 0x00000E3D
_08189B14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08189B1A:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r2, _08189B9C @ =0x00000E3D
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #0xa
	strb r0, [r1]
	mov r0, r8
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08189B46
	ldr r0, _08189BA0 @ =0x00000E3C
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08189B46:
	mov r1, r8
	cmp r1, #0x34
	bne _08189B56
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r0, r5, r2
	bl AuxShadow_Show
_08189B56:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_0818f17c
	ldr r1, _08189BA4 @ =0x00000D78
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08189B90
	ldr r3, _08189BA8 @ =FUN_08189bb4
	movs r2, #0x29
	ldr r0, _08189BAC @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08189BB0 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_08189B90:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08189B9C: .4byte 0x00000E3D
_08189BA0: .4byte 0x00000E3C
_08189BA4: .4byte 0x00000D78
_08189BA8: .4byte FUN_08189bb4
_08189BAC: .4byte 0x0000046D
_08189BB0: .4byte 0x0000046B
