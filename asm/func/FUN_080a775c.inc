	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_080a73e4
	ldr r1, _080A77E0 @ =0x00000341
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _080A77F8
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #3
	bl FUN_0809c08c
	movs r0, #1
	movs r1, #0xd
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	movs r1, #0xce
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrb r0, [r5]
	lsls r0, r0, #1
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, #0
	bl FUN_08047c40
	ldr r0, _080A77E4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r4, [r4]
	cmp r1, r4
	blt _080A77E8
	movs r0, #0
	bl FUN_08047a28
	b _080A77EE
	.align 2, 0
_080A77E0: .4byte 0x00000341
_080A77E4: .4byte 0x030046A0
_080A77E8:
	movs r0, #1
	bl FUN_08047a28
_080A77EE:
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
_080A77F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
