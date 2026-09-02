	push {r4, lr}
	adds r4, r0, #0
	bl CalcMagicCost
	adds r2, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bgt _08064C2E
	movs r1, #8
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08064C2E
	ldr r0, _08064C24 @ =0x030046A0
	ldr r0, [r0]
	adds r3, #0x44
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, r2
	bge _08064C28
	movs r0, #0
	str r0, [r1]
	b _08064C42
	.align 2, 0
_08064C24: .4byte 0x030046A0
_08064C28:
	subs r0, r0, r2
	str r0, [r1]
	b _08064C42
_08064C2E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	bge _08064C3E
	movs r0, #0
	b _08064C40
_08064C3E:
	subs r0, r0, r2
_08064C40:
	strh r0, [r1]
_08064C42:
	pop {r4}
	pop {r0}
	bx r0
