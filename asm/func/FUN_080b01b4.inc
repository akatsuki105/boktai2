	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B01E8 @ =0x0000067A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r4, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _080B01E0
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
_080B01E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B01E8: .4byte 0x0000067A
