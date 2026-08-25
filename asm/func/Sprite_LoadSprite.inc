	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r1, [r5, #0xc]
	adds r4, r1, r0
	cmp r4, #0
	bne _0822F306
	movs r0, #1
	rsbs r0, r0, #0
	b _0822F35A
_0822F306:
	ldrh r0, [r4]
	movs r2, #0
	strh r0, [r3]
	ldrh r0, [r4, #4]
	strh r0, [r3, #0x28]
	ldrh r0, [r4, #6]
	strh r0, [r3, #0x2a]
	ldrh r0, [r4, #8]
	strh r0, [r3, #0x2c]
	ldrh r0, [r4, #0xa]
	strh r0, [r3, #0x2e]
	ldrh r0, [r4, #0xc]
	strh r0, [r3, #0x30]
	ldrh r0, [r4, #0xe]
	strh r0, [r3, #0x32]
	adds r0, r3, #0
	adds r0, #0x34
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r2, [r3, #0x36]
	ldr r0, [r3, #0x48]
	cmp r0, #0
	bne _0822F348
	ldrh r0, [r5]
	strh r0, [r3, #0x3a]
	ldr r0, _0822F360 @ =0x03003584
	ldrh r1, [r3, #0x3a]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3, #0x48]
_0822F348:
	ldrh r0, [r4, #2]
	strh r0, [r3, #0x38]
	ldr r0, [r5, #0x14]
	ldr r1, [r4, #0x10]
	adds r0, r0, r1
	str r0, [r3, #0x4c]
	ldr r0, [r5, #0x1c]
	str r0, [r3, #0x50]
	movs r0, #0
_0822F35A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0822F360: .4byte 0x03003584
