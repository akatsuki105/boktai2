	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _08195CC8 @ =0x00000CA2
	adds r4, r3, r1
	ldrb r2, [r4]
	movs r5, #0x1f
	adds r1, r5, #0
	ands r1, r2
	ldr r6, _08195CCC @ =0x00000C34
	adds r2, r3, r6
	strb r1, [r2]
	ldrh r1, [r4]
	lsrs r1, r1, #5
	ands r1, r5
	adds r6, #1
	adds r2, r3, r6
	strb r1, [r2]
	ldrh r1, [r4]
	lsrs r1, r1, #0xa
	ands r1, r5
	ldr r2, _08195CD0 @ =0x00000C36
	adds r3, r3, r2
	strb r1, [r3]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195CC8: .4byte 0x00000CA2
_08195CCC: .4byte 0x00000C34
_08195CD0: .4byte 0x00000C36
