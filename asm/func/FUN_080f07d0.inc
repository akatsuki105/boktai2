	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F085E
	movs r3, #2
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _080F085E
	orrs r1, r3
	str r1, [r2]
	ldr r1, _080F0810 @ =0x0000025D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080F0814
	ldr r0, [r4, #0x44]
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	adds r3, r0, #0
	b _080F0824
	.align 2, 0
_080F0810: .4byte 0x0000025D
_080F0814:
	ldr r3, [r4, #0x44]
	adds r2, r3, #0
	adds r2, #0x20
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
_080F0824:
	movs r2, #1
	ldrb r0, [r5]
	cmp r0, #0
	bne _080F0834
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	b _080F083E
_080F0834:
	adds r1, r3, #0
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080F083E:
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080F0864 @ =0x0000044C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F085E
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
_080F085E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F0864: .4byte 0x0000044C
