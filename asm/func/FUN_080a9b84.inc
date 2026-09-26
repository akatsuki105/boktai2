	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A9BA8
	bl FUN_082407e0
	movs r2, #4
	ldr r1, _080A9BA4 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A9BBC
	.align 2, 0
_080A9BA4: .4byte 0x030044BC
_080A9BA8:
	cmp r0, #1
	bne _080A9BBC
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
_080A9BBC:
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r6, r5, r2
	ldrh r0, [r6]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A9C00
	ldr r0, [r5, #0x24]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	adds r0, r5, #0
	bl FUN_080a962c
	movs r3, #0x9d
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080A9BFC @ =FUN_080a9ac8
	str r0, [r1]
	movs r0, #0
	strh r0, [r6]
	movs r0, #0xa1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080A9C82
	.align 2, 0
_080A9BFC: .4byte FUN_080a9ac8
_080A9C00:
	adds r1, #0x22
	adds r0, r5, #0
	adds r0, #0x51
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x2c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x84
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x10
	subs r2, r4, r2
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #0x10
	bl Div
	strh r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x7e
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x86
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r4, r4, r2
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0x10
	bl Div
	adds r4, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #7
	movs r1, #0x14
	bl Div
	ldr r2, _080A9C74 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9C78
	asrs r0, r0, #0xc
	b _080A9C7E
	.align 2, 0
_080A9C74: .4byte 0x085B0A08
_080A9C78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A9C7E:
	subs r0, r4, r0
	strh r0, [r5, #0x3e]
_080A9C82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
