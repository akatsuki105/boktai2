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
	bgt _08064BCC
	movs r1, #8
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08064BCC
	ldr r0, _08064BC8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _08064BD4
	.align 2, 0
_08064BC8: .4byte 0x030046A0
_08064BCC:
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
_08064BD4:
	cmp r0, r2
	bge _08064BDC
	movs r0, #0
	b _08064BDE
_08064BDC:
	movs r0, #1
_08064BDE:
	pop {r4}
	pop {r1}
	bx r1
