	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	ldr r0, _08047954 @ =0x030000C4
	ldr r7, [r0]
	cmp r7, #0
	beq _0804794A
	cmp r1, #0
	beq _0804794A
	adds r6, r7, #0
	adds r6, #0x18
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r4, #0
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl TextBox_GetLine
	str r0, [r6, #0x1c]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #1
	strh r5, [r0]
	subs r2, #0x12
	adds r0, r7, r2
	strh r4, [r0]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_0804794A:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047954: .4byte 0x030000C4
