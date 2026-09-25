	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AC214
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x26]
	adds r2, r0, #0
	cmp r1, r2
	bhs _080AC1B8
	adds r1, r4, #0
	adds r1, #0x25
	ldr r0, [r4, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080AC1B8
	strh r2, [r4, #0x26]
_080AC1B8:
	ldrh r0, [r4, #0x26]
	adds r0, #1
	strh r0, [r4, #0x26]
	lsls r0, r0, #0x10
	lsls r1, r2, #0x10
	cmp r0, r1
	bhs _080AC20C
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080ac100
	ldr r0, [r4, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x48
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x4a
	ldrh r0, [r4, #0x1e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r4, #0x20]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r4, #0x26]
	ldrh r1, [r4, #0x28]
	cmp r0, r1
	bhs _080AC214
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080abe48
	b _080AC214
_080AC20C:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080ac13c
_080AC214:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
