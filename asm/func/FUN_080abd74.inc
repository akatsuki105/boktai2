	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x2a
	ldrb r0, [r4]
	adds r2, r0, #1
	strb r2, [r4]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080ABD9C
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080ABE40
_080ABD9C:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080ABDB2
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r6, #0
	bl FUN_0822dafc
_080ABDB2:
	ldrb r0, [r4]
	movs r1, #0x2b
	adds r1, r1, r6
	mov ip, r1
	adds r1, r6, #0
	adds r1, #0x2e
	cmp r0, #3
	bls _080ABDD6
	mov r2, ip
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r4]
	cmp r0, #8
	bls _080ABDD6
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080ABDD6:
	adds r2, r6, #0
	adds r2, #0x2d
	ldrb r0, [r1]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r4, r6, #0
	adds r4, #0x2c
	ldrb r5, [r4]
	ldr r3, _080ABE04 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080ABE08
	asrs r5, r0, #0xc
	b _080ABE0E
	.align 2, 0
_080ABE04: .4byte 0x085B0A08
_080ABE08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r5, r0, #0
_080ABE0E:
	ldrh r0, [r6, #0x30]
	adds r0, r0, r5
	strh r0, [r6, #0x18]
	ldrb r1, [r4]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080ABE2A
	asrs r1, r0, #0xc
	b _080ABE30
_080ABE2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ABE30:
	ldrh r0, [r6, #0x34]
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	ldrh r0, [r6, #0x1a]
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
_080ABE40:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
