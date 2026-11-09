	push {r4, r5, lr}
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0xbc
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059EC0
	movs r0, #0
	strb r0, [r4, #1]
	ldrb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
	adds r2, r4, #0
	adds r2, #0x6c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08059EC0:
	ldrh r1, [r4, #8]
	cmp r1, #0x1f
	bhi _08059EFA
	movs r0, #7
	ands r0, r1
	cmp r0, #3
	bhi _08059ED2
	movs r0, #1
	b _08059ED4
_08059ED2:
	movs r0, #0
_08059ED4:
	strb r0, [r4, #4]
	ldrb r0, [r4]
	cmp r0, #1
	bhi _08059EFA
	ldr r2, [r4, #0x18]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0x1c
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #0x20
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
_08059EFA:
	ldrh r0, [r4, #8]
	cmp r0, #0x3f
	bls _08059F0E
	movs r0, #0
	strb r0, [r4, #4]
	movs r1, #3
	strb r1, [r4, #2]
	movs r1, #1
	strb r1, [r4, #1]
	strh r0, [r4, #8]
_08059F0E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
