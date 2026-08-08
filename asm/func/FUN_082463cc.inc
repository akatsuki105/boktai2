	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _082463EA
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0xd4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_082463EA:
	adds r0, r4, #0
	bl FUN_08245eac
	ldrh r0, [r4, #6]
	cmp r0, #0x1d
	bls _08246402
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08245e68
	b _08246406
_08246402:
	adds r0, #1
	strh r0, [r4, #6]
_08246406:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
