	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0xc4
	ldr r1, _0801D3B8 @ =0x00001104
	adds r3, r0, r1
	movs r6, #0
	movs r5, #4
_0801D3A2:
	ldrh r0, [r2]
	cmp r0, #1
	beq _0801D3BC
	cmp r0, #1
	ble _0801D406
	cmp r0, #2
	beq _0801D3DC
	cmp r0, #3
	beq _0801D3F0
	b _0801D406
	.align 2, 0
_0801D3B8: .4byte 0x00001104
_0801D3BC:
	ldrh r0, [r2, #2]
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, #4
	movs r4, #0
	strh r1, [r3, #0x20]
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801D406
	movs r0, #4
	strh r0, [r3, #0x20]
	movs r0, #2
	strh r0, [r2]
	strh r4, [r2, #2]
	b _0801D406
_0801D3DC:
	ldrh r0, [r2, #2]
	cmp r0, #0x3f
	bls _0801D406
	movs r0, #3
	strh r0, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	b _0801D402
_0801D3F0:
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801D406
	strh r6, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	ldr r1, _0801D41C @ =0xFFFFFDFF
	ands r0, r1
	movs r1, #1
_0801D402:
	orrs r0, r1
	str r0, [r3, #8]
_0801D406:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	subs r5, #1
	adds r2, #4
	adds r3, #0x60
	cmp r5, #0
	bge _0801D3A2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D41C: .4byte 0xFFFFFDFF
