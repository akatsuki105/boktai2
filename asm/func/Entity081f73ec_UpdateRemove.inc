	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081F635C @ =0x000006EA
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F6354
	adds r0, r4, #0
	bl Entity081f73ec_RemoveSprites
	adds r0, r4, #0
	bl Entity081f73ec_UnregisterHurtboxes
	ldr r0, _081F6360 @ =0x000006E7
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r5, #0x38]
	bics r0, r1
	str r0, [r5, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	ldr r0, _081F6364 @ =0x000006E6
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
_081F6354:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F635C: .4byte 0x000006EA
_081F6360: .4byte 0x000006E7
_081F6364: .4byte 0x000006E6
