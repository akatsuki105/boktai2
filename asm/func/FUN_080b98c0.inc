	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	blt _080B98F0
	ldr r0, [r4, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x28]
	adds r0, r3, #0
	bl FUN_080b98b0
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	b _080B98F8
_080B98F0:
	ldr r0, [r4, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x28]
_080B98F8:
	cmp r5, #0
	blt _080B9924
	adds r2, r4, #0
	adds r2, #0x88
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b98b0
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x80
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	b _080B9930
_080B9924:
	adds r0, r4, #0
	adds r0, #0x88
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B9930:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
