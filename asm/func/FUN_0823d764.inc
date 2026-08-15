	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x50
	bl FUN_08230f94
	adds r1, r0, #0
	ldr r2, [r4, #0x50]
	subs r1, #1
	cmp r0, #0
	ble _0823D78E
	ldr r0, [r2, #4]
	ldrh r2, [r0]
	ldr r3, _0823D7B0 @ =0x0000FFFF
_0823D782:
	cmp r2, r3
	beq _0823D7C2
	adds r0, r1, #0
	subs r1, #1
	cmp r0, #0
	bgt _0823D782
_0823D78E:
	ldr r0, [r4, #0x28]
	subs r0, #1
	str r0, [r4, #0x28]
	cmp r0, #0
	bgt _0823D7CC
	ldrh r1, [r4, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0823D7B4
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x1c
	bl Script_ExecById
	b _0823D7BE
	.align 2, 0
_0823D7B0: .4byte 0x0000FFFF
_0823D7B4:
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x1c
	bl Script_ExecByPointer
_0823D7BE:
	cmp r0, #0
	bne _0823D7CA
_0823D7C2:
	adds r0, r4, #0
	bl KillEntity
	b _0823D7CC
_0823D7CA:
	str r0, [r4, #0x28]
_0823D7CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
