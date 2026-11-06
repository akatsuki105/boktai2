	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r2, r4, #0
	adds r2, #0x97
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r5, #0x38]
	bics r0, r1
	str r0, [r5, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r4, #0x96
	movs r0, #0
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
