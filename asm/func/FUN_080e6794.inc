	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r2, _080E6814 @ =0x00000554
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, r1
	bgt _080E680E
	movs r3, #0xab
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r2, #0xe
	ldr r4, _080E6818 @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _080E681C @ =0x0000046B
	adds r0, r6, r7
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xaa
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrb r2, [r0]
	subs r4, #2
	adds r0, r6, r4
	ldrb r3, [r0]
	subs r7, #0x26
	adds r0, r6, r7
	ldrb r4, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _080E6820 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _080E6824 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _080E6828 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	ldr r1, _080E682C @ =0x08251F60
	ldr r2, _080E6830 @ =0x00000902
	adds r0, r6, #0
	bl FUN_080e6768
_080E680E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E6814: .4byte 0x00000554
_080E6818: .4byte 0x0000046D
_080E681C: .4byte 0x0000046B
_080E6820: .4byte 0x00000469
_080E6824: .4byte 0x0000046A
_080E6828: .4byte 0x00000484
_080E682C: .4byte 0x08251F60
_080E6830: .4byte 0x00000902
