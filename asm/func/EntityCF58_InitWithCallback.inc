	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r5, [sp, #0x10]
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa0
	str r3, [r0]
	adds r0, #4
	str r5, [r0]
	subs r0, #0xb
	strb r2, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6110
	ldr r1, _080A617C @ =0x0300014C
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A617C: .4byte 0x0300014C
