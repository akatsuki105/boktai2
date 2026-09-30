	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0x9c
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r6, #0
	movs r5, #4
_0801E3E0:
	ldrh r0, [r2]
	cmp r0, #1
	beq _0801E3F4
	cmp r0, #1
	ble _0801E43E
	cmp r0, #2
	beq _0801E414
	cmp r0, #3
	beq _0801E428
	b _0801E43E
_0801E3F4:
	ldrh r0, [r2, #2]
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, #4
	movs r4, #0
	strh r1, [r3, #0x20]
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801E43E
	movs r0, #4
	strh r0, [r3, #0x20]
	movs r0, #2
	strh r0, [r2]
	strh r4, [r2, #2]
	b _0801E43E
_0801E414:
	ldrh r0, [r2, #2]
	cmp r0, #0x3f
	bls _0801E43E
	movs r0, #3
	strh r0, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	b _0801E43A
_0801E428:
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801E43E
	strh r6, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	ldr r1, _0801E454 @ =0xFFFFFDFF
	ands r0, r1
	movs r1, #1
_0801E43A:
	orrs r0, r1
	str r0, [r3, #8]
_0801E43E:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	subs r5, #1
	adds r2, #4
	adds r3, #0x60
	cmp r5, #0
	bge _0801E3E0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E454: .4byte 0xFFFFFDFF
