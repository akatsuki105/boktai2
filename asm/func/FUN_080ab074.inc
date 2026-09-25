	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r2, r0, #1
	strh r2, [r5, #0x2c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080AB098
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080AB12E
_080AB098:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _080AB0AE
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r5, #0
	bl FUN_0822dafc
_080AB0AE:
	ldrh r2, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x2b
	cmp r2, #3
	bls _080AB0C8
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	cmp r2, #8
	bls _080AB0C8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080AB0C8:
	adds r2, r5, #0
	adds r2, #0x2a
	ldrb r0, [r1]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldrh r4, [r5, #0x30]
	ldr r3, _080AB0F4 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AB0F8
	asrs r4, r0, #0xc
	b _080AB0FE
	.align 2, 0
_080AB0F4: .4byte 0x085B0A08
_080AB0F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080AB0FE:
	ldrh r0, [r5, #0x38]
	adds r0, r0, r4
	strh r0, [r5, #0x18]
	ldrh r1, [r5, #0x30]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AB11A
	asrs r1, r0, #0xc
	b _080AB120
_080AB11A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB120:
	ldrh r0, [r5, #0x3c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x2e]
	ldrh r1, [r5, #0x1a]
	adds r0, r0, r1
	strh r0, [r5, #0x1a]
_080AB12E:
	pop {r4, r5}
	pop {r0}
	bx r0
