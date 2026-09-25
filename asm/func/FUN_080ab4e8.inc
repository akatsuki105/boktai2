	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r2, r0, #1
	strh r2, [r3, #0x2c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bls _080AB50C
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r1, r3, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080AB53A
_080AB50C:
	ldrh r0, [r3, #0x38]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x3a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x3c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _080AB53A
	adds r0, r3, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl FUN_0822dafc
_080AB53A:
	pop {r4}
	pop {r0}
	bx r0
