	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803969C
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0803969E
_0803969C:
	movs r0, #0
_0803969E:
	cmp r0, #0
	beq _080396AA
	movs r0, #2
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
_080396AA:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080396D2
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080396D2
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080396D2
	adds r0, r4, #0
	bl FUN_08038b88
_080396D2:
	ldr r0, _080396FC @ =0x0000018B
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080396EC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080396EC
	ldr r0, _08039700 @ =0x000002CF
	bl PlaySound_082406e0
_080396EC:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080396FC: .4byte 0x0000018B
_08039700: .4byte 0x000002CF
