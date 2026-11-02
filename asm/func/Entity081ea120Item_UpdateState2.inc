	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r4, r0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r5, #0xa]
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0xb]
	pop {r4, r5}
	pop {r0}
	bx r0
