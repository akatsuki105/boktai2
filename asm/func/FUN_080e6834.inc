	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r2, _080E68BC @ =0x0000046E
	adds r0, r5, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _080E68C0 @ =0x00000554
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, r1
	bgt _080E68B4
	movs r7, #0xab
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r2, [r0]
	movs r1, #0xe
	subs r3, #0xe7
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	subs r7, #0xed
	adds r0, r5, r7
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	ldrb r2, [r0]
	subs r7, #0x26
	adds r0, r5, r7
	ldrb r3, [r0]
	subs r7, #0xea
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _080E68C4 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _080E68C8 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _080E68CC @ =0x00000484
	adds r0, r5, r3
	str r6, [r0]
	adds r7, #4
	adds r0, r5, r7
	strb r4, [r0]
	ldr r1, _080E68D0 @ =0x08251F60
	ldr r2, _080E68D4 @ =0x00000912
	adds r0, r5, #0
	bl FUN_080e6768
_080E68B4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E68BC: .4byte 0x0000046E
_080E68C0: .4byte 0x00000554
_080E68C4: .4byte 0x00000469
_080E68C8: .4byte 0x0000046A
_080E68CC: .4byte 0x00000484
_080E68D0: .4byte 0x08251F60
_080E68D4: .4byte 0x00000912
