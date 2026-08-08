	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	cmp r6, #0
	bne _0807C800
	ldr r0, _0807C7F4 @ =0x000004A9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r0, _0807C7F8 @ =0x000002E6
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0807C7FC @ =0x0000037D
	adds r0, r5, r1
	strb r6, [r0]
	b _0807C856
	.align 2, 0
_0807C7F4: .4byte 0x000004A9
_0807C7F8: .4byte 0x000002E6
_0807C7FC: .4byte 0x0000037D
_0807C800:
	cmp r6, #1
	bne _0807C814
	ldr r0, _0807C810 @ =0x000004A9
	adds r1, r5, r0
	movs r4, #0
	movs r0, #5
	strb r0, [r1]
	b _0807C840
	.align 2, 0
_0807C810: .4byte 0x000004A9
_0807C814:
	cmp r6, #2
	bne _0807C834
	ldr r0, _0807C82C @ =0x000004A7
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0807C830 @ =0x0000037D
	adds r1, r5, r0
	movs r0, #5
	strb r0, [r1]
	b _0807C856
	.align 2, 0
_0807C82C: .4byte 0x000004A7
_0807C830: .4byte 0x0000037D
_0807C834:
	cmp r6, #3
	bne _0807C874
	ldr r1, _0807C87C @ =0x000004A9
	adds r0, r5, r1
	movs r4, #0
	strb r6, [r0]
_0807C840:
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r0, _0807C880 @ =0x000002E6
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0807C884 @ =0x0000037D
	adds r0, r5, r1
	strb r4, [r0]
_0807C856:
	adds r0, r5, #0
	bl FUN_0807b7a4
	ldr r1, _0807C884 @ =0x0000037D
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, #0
	movs r1, #7
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, _0807C888 @ =FUN_08074a40
	str r0, [r1]
_0807C874:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C87C: .4byte 0x000004A9
_0807C880: .4byte 0x000002E6
_0807C884: .4byte 0x0000037D
_0807C888: .4byte FUN_08074a40
