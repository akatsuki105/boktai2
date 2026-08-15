	push {lr}
	ldr r0, _0822B0C0 @ =0x00009B1B
	ldr r1, _0822B0C4 @ =0x0000C5E9
	bl GetFile
	ldr r2, _0822B0C8 @ =0x03003580
	ldrh r1, [r0]
	strh r1, [r2]
	ldr r1, _0822B0CC @ =0x03003584
	adds r0, #4
	str r0, [r1]
	movs r1, #8
	bl FUN_0822d014
	pop {r0}
	bx r0
	.align 2, 0
_0822B0C0: .4byte 0x00009B1B
_0822B0C4: .4byte 0x0000C5E9
_0822B0C8: .4byte 0x03003580
_0822B0CC: .4byte 0x03003584
