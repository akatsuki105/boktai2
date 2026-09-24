	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D5D84
	b _081D5E88
_081D5D84:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0
	movs r2, #0
	strh r2, [r0]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	strb r3, [r4]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081D5DE0 @ =0x05000002
	bl CpuSet
	movs r0, #0x29
	strh r0, [r4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x94
	strh r0, [r1]
	movs r0, #0
	ldrsh r3, [r4, r0]
	ldr r2, _081D5DE4 @ =0x085B0A08
	ldrb r0, [r5, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D5DE8
	asrs r0, r0, #0xc
	b _081D5DEE
	.align 2, 0
_081D5DE0: .4byte 0x05000002
_081D5DE4: .4byte 0x085B0A08
_081D5DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5DEE:
	adds r6, r0, #0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	ldr r1, _081D5E14 @ =0x085B0A08
	ldrb r2, [r5, #6]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r7, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _081D5E18
	asrs r0, r0, #0xc
	b _081D5E1E
	.align 2, 0
_081D5E14: .4byte 0x085B0A08
_081D5E18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5E1E:
	adds r6, r6, r0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D5E3E
	asrs r0, r0, #0xc
	b _081D5E42
_081D5E3E:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D5E42:
	adds r3, r0, #0
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D5E68
	asrs r2, r0, #0xc
	b _081D5E6E
_081D5E68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D5E6E:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, r0, r6
	strh r0, [r5, #0x1c]
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r1, r5, r4
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_081D5E88:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5F36
	adds r0, r5, #0
	bl FUN_081d6cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D5F36
	ldr r2, _081D5F24 @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081D5F36
	ldr r0, _081D5F28 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _081D5EC6
	ldr r0, _081D5F2C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D5EC6
	movs r1, #1
_081D5EC6:
	cmp r1, #0
	bne _081D5F36
	ldr r0, [r2]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D5F36
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _081D5F36
	subs r4, #0x10
	adds r1, r5, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _081D5F36
	movs r0, #4
	strh r0, [r1]
	adds r4, #0x24
	adds r1, r5, r4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081D5F30
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #3
	strh r1, [r0]
	movs r2, #0xab
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081D5F48
	.align 2, 0
_081D5F24: .4byte 0x03002BE0
_081D5F28: .4byte 0x03002B8C
_081D5F2C: .4byte 0x03002B60
_081D5F30:
	ldr r0, _081D5F50 @ =0x000003C9
	bl PlaySound_082406e0
_081D5F36:
	adds r0, r5, #0
	bl FUN_081d5f54
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D5F48:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D5F50: .4byte 0x000003C9
