	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0xee
	ldrh r0, [r2]
	cmp r0, #0
	beq _080A4794
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r1, [r4]
	lsls r0, r1, #8
	subs r0, r0, r1
	ldrh r1, [r2]
	bl Div
	ldr r2, _080A4768 @ =gSineTable
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080A476C
	asrs r1, r0, #0xc
	b _080A4772
	.align 2, 0
_080A4768: .4byte gSineTable
_080A476C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A4772:
	adds r0, r5, #0
	adds r0, #0xde
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xee
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A4794
	movs r0, #0
	strh r0, [r4]
_080A4794:
	adds r0, r5, #0
	adds r0, #0xf0
	adds r1, r5, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A47C6
	adds r1, r5, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A47CC @ =FUN_080a47d0
	adds r0, r5, #0
	bl Entity1E98_SetUpdateCallback
_080A47C6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A47CC: .4byte FUN_080a47d0
