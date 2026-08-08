	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne _0823A7A8
	ldrb r0, [r4, #1]
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _0823A7A8
	movs r0, #1
	b _0823A7CC
_0823A7A8:
	ldrb r1, [r4, #2]
	lsls r1, r1, #4
	adds r1, #4
	adds r1, r4, r1
	ldr r2, _0823A7D4 @ =0x04000004
	adds r0, r3, #0
	bl CpuSet
	ldrb r1, [r4, #3]
	adds r1, #1
	movs r3, #0
	strb r1, [r4, #3]
	ldrb r1, [r4, #2]
	adds r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r4, #2]
	strb r3, [r4]
_0823A7CC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823A7D4: .4byte 0x04000004
