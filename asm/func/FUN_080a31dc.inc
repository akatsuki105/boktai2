	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3200 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A31FA
	ldr r1, _080A3204 @ =FUN_080a3208
	adds r0, r2, #0
	bl FUN_080a2a14
_080A31FA:
	pop {r0}
	bx r0
	.align 2, 0
_080A3200: .4byte 0x00000382
_080A3204: .4byte FUN_080a3208
