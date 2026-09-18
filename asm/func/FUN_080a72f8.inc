	push {lr}
	adds r2, r0, #0
	ldr r0, _080A731C @ =0x00000346
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A7316
	ldr r0, _080A7320 @ =0x00000341
	adds r1, r2, r0
	movs r0, #8
	strb r0, [r1]
_080A7316:
	pop {r0}
	bx r0
	.align 2, 0
_080A731C: .4byte 0x00000346
_080A7320: .4byte 0x00000341
