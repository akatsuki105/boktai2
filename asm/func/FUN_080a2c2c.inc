	push {lr}
	adds r2, r0, #0
	ldr r0, _080A2C50 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A2C4A
	ldr r1, _080A2C54 @ =FUN_080a2c58
	adds r0, r2, #0
	bl FUN_080a2a14
_080A2C4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A2C50: .4byte 0x00000382
_080A2C54: .4byte FUN_080a2c58
