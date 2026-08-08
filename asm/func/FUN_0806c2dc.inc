	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806C2F8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806C2F8:
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C354
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C35C
_0806C354:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C35C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C380
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C388
_0806C380:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C388:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C3C0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C3F8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C3C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C3B8
	ldrb r0, [r4, #5]
_0806C3B8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C3D4
	.align 2, 0
_0806C3C0: .4byte 0x0000FFFF
_0806C3C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C3D4
	strh r1, [r4, #8]
_0806C3D4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C3F8
	movs r0, #1
	strb r0, [r4, #7]
_0806C3F8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
