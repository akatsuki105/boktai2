	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	adds r5, r0, #0
	bl FUN_08234f6c
	movs r2, #0xbf
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
	ldr r1, _0821C040 @ =0x00000BF4
	adds r0, r4, r1
	strb r6, [r0]
	ldrb r0, [r5]
	adds r2, #5
	adds r4, r4, r2
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821C040: .4byte 0x00000BF4
