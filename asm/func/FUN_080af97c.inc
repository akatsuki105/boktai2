	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, _080AF9A4 @ =0x0000068A
	adds r0, r7, r1
	movs r2, #0x10
	strh r2, [r0]
	ldr r0, _080AF9A8 @ =0x0000067A
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AF9AC
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080af374
	b _080AFA0A
	.align 2, 0
_080AF9A4: .4byte 0x0000068A
_080AF9A8: .4byte 0x0000067A
_080AF9AC:
	ldrh r4, [r1]
	subs r4, r2, r4
	adds r6, r4, #1
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r5, r7, r1
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	ldr r0, _080AFA10 @ =0x0000061A
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	ldr r2, _080AFA14 @ =0x00000672
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	ldr r0, _080AFA18 @ =0x0000061C
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	ldr r2, _080AFA1C @ =0x00000674
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
_080AFA0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFA10: .4byte 0x0000061A
_080AFA14: .4byte 0x00000672
_080AFA18: .4byte 0x0000061C
_080AFA1C: .4byte 0x00000674
