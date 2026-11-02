	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _08148660 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	ldr r3, _08148664 @ =0x00000684
	adds r5, r4, r3
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08148668
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _0814868E
	.align 2, 0
_08148660: .4byte 0x000004A4
_08148664: .4byte 0x00000684
_08148668:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08148688
	cmp r0, #2
	beq _08148684
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08148684:
	movs r0, #1
	b _08148698
_08148688:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_0814868E:
	ldr r1, _081486A4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08148698:
	adds r2, r0, #0
	cmp r2, #0
	beq _081486A8
	movs r0, #1
	b _081486CE
	.align 2, 0
_081486A4: .4byte 0xFFFFFDFF
_081486A8:
	movs r1, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081486D4 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_081486CE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081486D4: .4byte 0x00000484
