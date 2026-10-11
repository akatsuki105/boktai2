	push {r4, lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A032C
	ldr r4, _080A0328 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x2c]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x2c]
	ldr r0, [r4]
	ldrh r1, [r0, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	b _080A034C
	.align 2, 0
_080A0328: .4byte 0x03002BE0
_080A032C:
	ldr r4, _080A0358 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x30]
	ldr r0, [r4]
	ldrh r1, [r0, #0x30]
	movs r2, #0x84
	lsls r2, r2, #1
_080A034C:
	adds r0, r0, r2
	strh r1, [r0]
_080A0350:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0358: .4byte 0x03002BE0
