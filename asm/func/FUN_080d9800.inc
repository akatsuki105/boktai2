	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080D984C @ =0x0300015C
	ldr r3, [r0]
	cmp r3, #0
	beq _080D98C8
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x5c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strh r0, [r5, #0x10]
	ldr r0, [r4]
	cmp r0, #0
	beq _080D98C8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, [r4, #0x4c]
	cmp r0, #3
	bgt _080D9850
	ldrh r0, [r4, #0x30]
	adds r0, #0x14
	strh r0, [r4, #0x30]
	ldr r2, [r4]
	ldrh r1, [r4, #0x28]
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	strh r0, [r5, #0x1e]
	b _080D98A6
	.align 2, 0
_080D984C: .4byte 0x0300015C
_080D9850:
	cmp r0, #9
	bgt _080D987C
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, [r4]
	ldrh r1, [r4, #0x28]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r4, #0
	bl FUN_080d8864
	b _080D98A6
_080D987C:
	ldr r0, [r4]
	movs r2, #2
	ldrsh r1, [r0, r2]
	ldrh r0, [r4, #0x28]
	adds r1, r1, r0
	ldrh r0, [r4, #0x30]
	adds r1, r1, r0
	ldr r2, _080D98D0 @ =0x085B0A08
	adds r3, r4, #0
	adds r3, #0x35
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	ldrb r0, [r3]
	adds r0, #4
	strb r0, [r3]
_080D98A6:
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x1e]
	ldrh r2, [r5, #0x1e]
	adds r0, r0, r2
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldr r0, [r4, #0x4c]
	cmp r0, #9
	bgt _080D98C8
	adds r0, #1
	str r0, [r4, #0x4c]
_080D98C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D98D0: .4byte 0x085B0A08
