	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	subs r1, #0xcc
	ldr r3, _08192F84 @ =0x00000F2C
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08192F88
	movs r0, #1
	b _08192F8A
	.align 2, 0
_08192F84: .4byte 0x00000F2C
_08192F88:
	movs r0, #0
_08192F8A:
	cmp r0, #0
	beq _08192FB8
	movs r4, #0
	ldr r0, _08192FB4 @ =0x0000075B
	adds r5, r2, r0
_08192F94:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08192FA4
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08192db0
_08192FA4:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, #1
	cmp r4, #5
	ble _08192F94
	b _08192FDA
	.align 2, 0
_08192FB4: .4byte 0x0000075B
_08192FB8:
	movs r4, #0
	ldr r3, _08192FE0 @ =0x0000075B
	adds r5, r2, r3
_08192FBE:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08192FCE
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #2
	bl FUN_08192db0
_08192FCE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	ble _08192FBE
_08192FDA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08192FE0: .4byte 0x0000075B
