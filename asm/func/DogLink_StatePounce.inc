	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081C9C88 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9C8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9C8E
	.align 2, 0
_081C9C88: .4byte 0x0000046D
_081C9C8C:
	movs r0, #0
_081C9C8E:
	cmp r0, #0
	bne _081C9C94
	b _081C9E1E
_081C9C94:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	mov r3, sp
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r2, r7, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	adds r4, r0, #0
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r2, r0, #6
	subs r1, r4, r2
	cmp r1, #0x80
	ble _081C9CEC
	ldr r0, _081C9CE8 @ =0xFFFFFF00
	b _081C9CF8
	.align 2, 0
_081C9CE8: .4byte 0xFFFFFF00
_081C9CEC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081C9CFA
	movs r0, #0x80
	lsls r0, r0, #1
_081C9CF8:
	adds r1, r1, r0
_081C9CFA:
	adds r0, r1, #0
	cmp r1, #0
	bge _081C9D02
	rsbs r0, r1, #0
_081C9D02:
	cmp r0, #0xf
	bgt _081C9D58
	mov r3, sp
	movs r6, #0x18
	ldr r2, _081C9D28 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9D2C
	asrs r1, r0, #0xc
	b _081C9D32
	.align 2, 0
_081C9D28: .4byte gSineTable
_081C9D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C9D32:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9D4E
	asrs r0, r0, #0xc
	b _081C9D54
_081C9D4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C9D54:
	strh r0, [r3, #4]
	b _081C9DF6
_081C9D58:
	cmp r1, #0
	ble _081C9DA4
	adds r3, r2, #0
	adds r3, #0x10
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _081C9D84 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9D88
	asrs r1, r0, #0xc
	b _081C9D8E
	.align 2, 0
_081C9D84: .4byte gSineTable
_081C9D88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C9D8E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	bge _081C9DEA
	b _081C9DEE
_081C9DA4:
	adds r3, r2, #0
	adds r3, #0xef
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _081C9DCC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9DD0
	asrs r1, r0, #0xc
	b _081C9DD6
	.align 2, 0
_081C9DCC: .4byte gSineTable
_081C9DD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C9DD6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9DEE
_081C9DEA:
	asrs r0, r0, #0xc
	b _081C9DF4
_081C9DEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C9DF4:
	strh r0, [r4, #4]
_081C9DF6:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081C9E1E:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	bl Hitbox_Register
	ldr r0, [r5, #0x18]
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081C9E74
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _081C9E46
	asrs r1, r0, #1
	b _081C9E4C
_081C9E46:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081C9E4C:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081C9E66
	asrs r1, r0, #1
	b _081C9E6C
_081C9E66:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081C9E6C:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_081C9E74:
	adds r0, r5, #0
	movs r1, #5
	bl Enemy_PlayAnim
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C9EC4
	ldr r4, _081C9ECC @ =FUN_081c9ed8
	movs r3, #0x23
	ldr r0, _081C9ED0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C9ED4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081C9EC4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C9ECC: .4byte FUN_081c9ed8
_081C9ED0: .4byte 0x0000046D
_081C9ED4: .4byte 0x0000046B
