	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081C09B0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C09B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C09B6
	.align 2, 0
_081C09B0: .4byte 0x0000046C
_081C09B4:
	movs r0, #0
_081C09B6:
	cmp r0, #0
	beq _081C09FC
	ldr r4, _081C0A7C @ =GolemLink_StateStopAtTile
	movs r3, #0x29
	ldr r0, _081C0A80 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C0A84 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081C0A84 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C09FC:
	adds r0, r5, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081C0A9E
	ldr r1, _081C0A84 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C0A94
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r6, r3
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl GolemLink_RouteTo
	ldr r2, _081C0A88 @ =GolemLink_StateRoll
	movs r1, #0x22
	ldr r3, _081C0A80 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081C0A84 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C0A8C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081C0A90 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	b _081C0A9E
	.align 2, 0
_081C0A7C: .4byte GolemLink_StateStopAtTile
_081C0A80: .4byte 0x0000046D
_081C0A84: .4byte 0x0000046B
_081C0A88: .4byte GolemLink_StateRoll
_081C0A8C: .4byte 0x00000469
_081C0A90: .4byte 0x0000046A
_081C0A94:
	ldr r2, _081C0AA4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081C0A9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C0AA4: .4byte 0x00000484
