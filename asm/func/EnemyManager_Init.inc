	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [r4, #0x24]
	movs r0, #0
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x32]
	adds r1, r4, #0
	adds r1, #0x30
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080ec614
	ldr r1, _080EEAAC @ =0x03002C5C
	str r4, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080EEAAC: .4byte 0x03002C5C
