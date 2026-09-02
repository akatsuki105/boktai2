	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _08064B46
	movs r0, #0
	b _08064B8A
_08064B46:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_08064b00
	adds r2, r0, #0
	movs r3, #0x64
	movs r0, #0x80
	lsls r0, r0, #1
	movs r6, #0xde
	lsls r6, r6, #2
	adds r1, r5, r6
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08064B66
	movs r3, #0x50
_08064B66:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _08064B78
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08064B78
	subs r3, #0x14
_08064B78:
	cmp r3, #0x63
	bgt _08064B88
	adds r0, r2, #0
	muls r0, r3, r0
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
_08064B88:
	adds r0, r2, #0
_08064B8A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
