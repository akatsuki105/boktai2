	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	cmp r6, #1
	beq _08063590
	cmp r6, #1
	bgt _0806358A
	cmp r6, #0
	beq _08063610
	b _0806361A
_0806358A:
	cmp r6, #2
	beq _080635CC
	b _0806361A
_08063590:
	ldr r1, _080635C0 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080635AA
	ldr r2, _080635C4 @ =0x000004C5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _08063610
	adds r0, r5, #0
	bl FUN_08063220
_080635AA:
	ldr r1, _080635C8 @ =0x0000043E
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _08063610
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _08063610
	.align 2, 0
_080635C0: .4byte 0x000004C7
_080635C4: .4byte 0x000004C5
_080635C8: .4byte 0x0000043E
_080635CC:
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08063610
	ldr r4, _08063620 @ =0x03002B64
	ldr r2, _08063624 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x41
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08063628 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	bl Mod
	ldr r1, _0806362C @ =0x00000456
	adds r2, r5, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, #1
	adds r1, r1, r0
	movs r0, #7
	ands r1, r0
	strh r1, [r4]
	strb r1, [r2]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08063610:
	lsls r1, r6, #1
	ldr r2, _08063630 @ =0x0000043C
	adds r0, r5, r2
	adds r0, r0, r1
	strh r7, [r0]
_0806361A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063620: .4byte 0x03002B64
_08063624: .4byte 0x030046B8
_08063628: .4byte 0x0203B400
_0806362C: .4byte 0x00000456
_08063630: .4byte 0x0000043C
