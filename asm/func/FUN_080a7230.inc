	push {lr}
	adds r1, r0, #0
	ldr r0, _080A7258 @ =0x00000346
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080A7252
	ldr r3, _080A725C @ =0x00000341
	adds r0, r1, r3
	movs r1, #6
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
_080A7252:
	pop {r0}
	bx r0
	.align 2, 0
_080A7258: .4byte 0x00000346
_080A725C: .4byte 0x00000341
