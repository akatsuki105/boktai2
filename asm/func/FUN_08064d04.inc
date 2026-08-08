	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08064D40 @ =0x00000283
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08064D48
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bgt _08064D48
	adds r0, r4, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064D48
	ldr r1, _08064D44 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08064D48
	movs r0, #0
	ldrsb r0, [r5, r0]
	b _08064D4C
	.align 2, 0
_08064D40: .4byte 0x00000283
_08064D44: .4byte 0x00000A75
_08064D48:
	movs r0, #1
	rsbs r0, r0, #0
_08064D4C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
