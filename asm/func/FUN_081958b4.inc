	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _081958E4 @ =0x00000CA2
	adds r5, r3, r1
	ldrh r1, [r5]
	lsrs r1, r1, #5
	movs r4, #0x1f
	ands r1, r4
	ldr r6, _081958E8 @ =0x00000C35
	adds r2, r3, r6
	strb r1, [r2]
	ldrh r1, [r5]
	lsrs r1, r1, #0xa
	ands r1, r4
	ldr r4, _081958EC @ =0x00000C36
	adds r2, r3, r4
	strb r1, [r2]
	adds r6, #0x2b
	adds r3, r3, r6
	ldr r1, _081958F0 @ =FUN_081958f4
	str r1, [r3]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081958E4: .4byte 0x00000CA2
_081958E8: .4byte 0x00000C35
_081958EC: .4byte 0x00000C36
_081958F0: .4byte FUN_081958f4
