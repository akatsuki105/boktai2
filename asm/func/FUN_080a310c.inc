	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3130 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A312A
	ldr r1, _080A3134 @ =FUN_080a3138
	adds r0, r2, #0
	bl FUN_080a2a14
_080A312A:
	pop {r0}
	bx r0
	.align 2, 0
_080A3130: .4byte 0x00000382
_080A3134: .4byte FUN_080a3138
