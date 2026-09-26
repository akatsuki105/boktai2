	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _080DB48E
	movs r5, #0
	ldr r7, _080DB460 @ =0x085AD314
_080DB44E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB464
	movs r0, #1
	b _080DB466
	.align 2, 0
_080DB460: .4byte 0x085AD314
_080DB464:
	movs r0, #0
_080DB466:
	cmp r0, #0
	beq _080DB482
	movs r0, #0xa4
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, r1, r6
	movs r2, #0x3e
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
_080DB482:
	adds r5, #1
	cmp r5, #7
	ble _080DB44E
	adds r0, r4, #0
	bl FUN_080dadec
_080DB48E:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
