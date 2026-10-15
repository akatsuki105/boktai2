	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #0x16
	cmp r1, r0
	bge _080A2CDA
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A2CDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2CF2
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2D0E
_080A2CF2:
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r1, _080A2D14 @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
_080A2D0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D14: .4byte FUN_080a2e20
