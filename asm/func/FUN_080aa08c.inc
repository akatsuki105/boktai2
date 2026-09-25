	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AA0AC
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080AA0DC
_080AA0AC:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x28]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080AA0DC
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
_080AA0DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
