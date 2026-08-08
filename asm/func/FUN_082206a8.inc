	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #1
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r5, r4, r1
	ldr r1, [r5]
	ands r0, r1
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	cmp r0, #0
	beq _082206D8
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_082206D8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r2, r4, #0
	adds r2, #0x98
	ldr r0, [r2]
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _082206FC
	cmp r2, #0x63
	beq _08220734
	b _08220750
_082206FC:
	movs r3, #2
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r6, _08220730 @ =0x000002D9
	adds r0, r4, r6
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08220750
	movs r1, #0x63
	adds r6, #0xc7
	adds r0, r4, r6
	str r1, [r0]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	str r2, [r0]
	ldr r0, [r5]
	orrs r0, r3
	str r0, [r5]
	b _08220750
	.align 2, 0
_08220730: .4byte 0x000002D9
_08220734:
	ldr r1, [r5]
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0xe
	ble _08220750
	movs r0, #0x10
	orrs r1, r0
	str r1, [r5]
_08220750:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
