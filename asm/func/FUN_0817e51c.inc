	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	ldr r1, _0817E54C @ =0x000007B2
	adds r0, r4, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0817E580
	movs r2, #0x80
	lsls r2, r2, #0xa
	ldr r0, _0817E550 @ =0x00000898
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0817E554
	movs r0, #1
	b _0817E556
	.align 2, 0
_0817E54C: .4byte 0x000007B2
_0817E550: .4byte 0x00000898
_0817E554:
	movs r0, #0
_0817E556:
	cmp r0, #0
	beq _0817E568
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0817E5C2
_0817E568:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817E578
	movs r0, #1
	b _0817E57A
_0817E578:
	movs r0, #0
_0817E57A:
	cmp r0, #0
	beq _0817E5C4
	b _0817E5B8
_0817E580:
	cmp r1, #0x13
	bhi _0817E59C
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0817E5B8
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0817E5C2
_0817E59C:
	cmp r1, #0x1d
	bhi _0817E5C4
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0817E5B8
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0817E5C2
_0817E5B8:
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
_0817E5C2:
	str r1, [r0, #8]
_0817E5C4:
	ldr r0, _0817E5D8 @ =0x000007B2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0817E5D2
	subs r0, #1
	strh r0, [r1]
_0817E5D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817E5D8: .4byte 0x000007B2
