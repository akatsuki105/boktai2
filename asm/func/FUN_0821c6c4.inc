	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r6, r4, #0
	adds r6, #0x98
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _0821C708
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	ldrh r1, [r7, #0x3e]
	movs r2, #0xfb
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [r5, #0x34]
	adds r0, r4, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r5, #0x38]
	adds r0, #4
	str r1, [r0]
_0821C708:
	movs r1, #1
	ldr r2, [r6]
	orrs r2, r1
	str r2, [r6]
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0821C720
	movs r0, #0x80
	lsls r0, r0, #0xe
	orrs r2, r0
	str r2, [r6]
_0821C720:
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0821C738
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_0821C738:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
