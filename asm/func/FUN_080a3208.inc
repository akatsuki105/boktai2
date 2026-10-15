	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A326C @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _080A3222
	ldr r0, _080A3270 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	bl FUN_0807c36c
_080A3222:
	ldrh r2, [r5]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A324A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A324A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a25c8
_080A324A:
	ldr r0, _080A326C @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080A3264
	ldr r1, _080A3274 @ =FUN_080a3278
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3264:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A326C: .4byte 0x00000382
_080A3270: .4byte 0x03002BE0
_080A3274: .4byte FUN_080a3278
