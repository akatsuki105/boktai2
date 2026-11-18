	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	ldr r2, _081C0888 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C088C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C088E
	.align 2, 0
_081C0888: .4byte 0x0000046C
_081C088C:
	movs r0, #0
_081C088E:
	cmp r0, #0
	beq _081C08D8
	ldr r4, _081C0960 @ =GolemLink_StateDash
	movs r3, #0x28
	ldr r0, _081C0964 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C0968 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081C0968 @ =0x0000046B
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r4, _081C096C @ =0x000006B6
	adds r1, r7, r4
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
_081C08D8:
	ldr r0, _081C0970 @ =0x00000484
	adds r2, r6, r0
	ldr r1, [r2]
	cmp r1, #0x1e
	bgt _081C08EC
	ldr r3, _081C0968 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C0984
_081C08EC:
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081C090E
	movs r7, #0xea
	lsls r7, r7, #1
	adds r1, r6, r7
	str r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_081C090E:
	ldr r2, _081C0974 @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r3, _081C0964 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0968 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0978 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081C097C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0980 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081C0970 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081C0988
	.align 2, 0
_081C0960: .4byte GolemLink_StateDash
_081C0964: .4byte 0x0000046D
_081C0968: .4byte 0x0000046B
_081C096C: .4byte 0x000006B6
_081C0970: .4byte 0x00000484
_081C0974: .4byte GolemLink_StateUncurl
_081C0978: .4byte 0x00000553
_081C097C: .4byte 0x00000469
_081C0980: .4byte 0x0000046A
_081C0984:
	adds r0, r1, #1
	str r0, [r2]
_081C0988:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
