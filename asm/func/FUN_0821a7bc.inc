	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0821A7E2
	bl Script_GetValue
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
_0821A7E2:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0821A7F8
	bl Script_GetValue
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
_0821A7F8:
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_0821a5d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0821a714
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
