	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xf0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xf2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	blo _080B9B10
	ldr r0, [r3, #0x28]
	movs r2, #1
	orrs r0, r2
	str r0, [r3, #0x28]
	subs r1, #0x6a
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #1
	b _080B9B68
_080B9B10:
	ldrh r1, [r1]
	ldrh r0, [r2]
	subs r6, r1, r0
	adds r7, r6, #1
	adds r5, r3, #0
	adds r5, #0xe0
	adds r4, r3, #0
	adds r4, #0x28
	movs r0, #1
	mov r8, r0
_080B9B24:
	ldr r0, [r4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080B9B56
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	strh r0, [r4, #0x18]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	strh r0, [r4, #0x1a]
_080B9B56:
	adds r5, #8
	adds r4, #0x60
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _080B9B24
	movs r0, #0
_080B9B68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
