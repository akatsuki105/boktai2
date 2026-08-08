	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080F65F8 @ =0x000001DF
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080e5718
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _080F65FC @ =0xFBFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _080F6600 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080F65F8: .4byte 0x000001DF
_080F65FC: .4byte 0xFBFFFFFF
_080F6600: .4byte 0xFEFFFFFF
