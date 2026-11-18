	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r4, #0
	bl FUN_080fa77c
	movs r0, #0x4a
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r6, r4, r1
	ldrh r5, [r6]
	ands r5, r0
	cmp r5, #0
	bne _081C49D0
	adds r0, r4, #0
	bl FUN_080f9f20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C49D0
	movs r1, #0x10
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C49D0
	adds r0, r4, #0
	bl Enemy_RouteToNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C4986
	adds r0, r4, #0
	bl Enemy_PickPathNodeAwayFromPlayer
_081C4986:
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r6, _081C4A04 @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r5, [r0]
	ldr r1, _081C4A08 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C4A0C @ =FUN_081c1790
	movs r2, #0x13
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C4A10 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_081C49D0:
	adds r0, r7, #0
	bl FUN_081c1e84
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r6, #0xd8
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C4A14 @ =0x000006C2
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _081C4A18 @ =0x000006C4
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C4A04: .4byte 0x00000469
_081C4A08: .4byte 0x0000046C
_081C4A0C: .4byte FUN_081c1790
_081C4A10: .4byte 0x0000046B
_081C4A14: .4byte 0x000006C2
_081C4A18: .4byte 0x000006C4
