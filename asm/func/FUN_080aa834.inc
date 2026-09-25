	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	ldr r0, _080AA874 @ =0x0000034A
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080AA87C
	ldr r0, [r5, #0x24]
	subs r1, #1
	ands r0, r1
	str r0, [r5, #0x24]
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080AA878 @ =0x080AA709
	str r0, [r1]
	movs r0, #0
	strh r0, [r6]
	movs r0, #0xa1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080AA8D2
	.align 2, 0
_080AA874: .4byte 0x0000034A
_080AA878: .4byte 0x080AA709
_080AA87C:
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, #0x20
	adds r1, r5, #0
	adds r1, #0x51
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x84
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #8
	subs r2, r4, r2
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #8
	bl Div
	strh r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x7e
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x86
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r4, r4, r2
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #8
	bl Div
	strh r0, [r5, #0x3e]
_080AA8D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
