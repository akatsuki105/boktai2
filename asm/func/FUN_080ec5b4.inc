	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080ec518
	adds r4, r0, #0
	cmp r4, #0
	bne _080EC5E8
	bl FUN_080ec4ec
	adds r4, r0, #0
	cmp r4, #0
	beq _080EC5E8
	bl FUN_080ef840
	cmp r0, #0
	beq _080EC5E8
	strh r6, [r4]
	strh r5, [r4, #2]
	adds r0, #0x30
	ldrb r0, [r0]
	strh r0, [r4, #4]
_080EC5E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
