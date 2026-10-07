	push {r4, lr}
	ldr r1, _080815E8 @ =0x0000094A
	adds r3, r0, r1
	movs r2, #0
	movs r1, #0x27
	strh r1, [r3]
	ldr r4, _080815EC @ =0x0000094C
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, #0x95
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0xff
	strb r1, [r2]
	adds r2, r0, #0
	adds r2, #0xc2
	adds r1, #0x22
	strh r1, [r2]
	adds r2, #0xe
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r0, r4
	str r1, [r2]
	ldrh r1, [r3]
	bl FUN_080813d0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080815E8: .4byte 0x0000094A
_080815EC: .4byte 0x0000094C
