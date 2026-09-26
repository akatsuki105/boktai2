	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r1, r0, #1
	movs r3, #0
	strh r1, [r5, #0x2c]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AB2B6
	ldr r0, [r5]
	movs r2, #1
	orrs r0, r2
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x18
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	movs r1, #1
	movs r2, #0
	bl FUN_080ddcc8
	b _080AB398
_080AB2B6:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080AB316
	ldr r2, _080AB2E8 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0x2a
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r6, r2, #0
	adds r4, r3, #0
	cmp r0, #0
	blt _080AB2EC
	asrs r1, r0, #0xc
	b _080AB2F2
	.align 2, 0
_080AB2E8: .4byte 0x085B0A08
_080AB2EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB2F2:
	ldr r2, [r5, #0x34]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r5, #0x1a]
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r2, #0
	cmp r0, #0
	bge _080AB384
	b _080AB38C
_080AB316:
	ldrh r0, [r5, #0x2c]
	movs r2, #0xc
	subs r2, r2, r0
	adds r1, r2, #1
	adds r4, r5, #0
	adds r4, #0x2a
	adds r0, r5, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	ldrb r3, [r4]
	adds r0, r0, r3
	strb r0, [r4]
	ldrh r0, [r5, #0x32]
	muls r0, r2, r0
	bl Div
	strh r0, [r5, #0x32]
	ldrh r3, [r5, #0x32]
	ldr r2, _080AB358 @ =0x085B0A08
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB35C
	asrs r3, r0, #0xc
	b _080AB362
	.align 2, 0
_080AB358: .4byte 0x085B0A08
_080AB35C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AB362:
	ldr r2, [r5, #0x34]
	ldrh r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r5, #0x1a]
	ldrh r3, [r5, #0x32]
	ldr r1, _080AB388 @ =0x085B0A08
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r1, r2, #0
	cmp r0, #0
	blt _080AB38C
_080AB384:
	asrs r2, r0, #0xc
	b _080AB392
	.align 2, 0
_080AB388: .4byte 0x085B0A08
_080AB38C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AB392:
	ldrh r0, [r1, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
_080AB398:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
