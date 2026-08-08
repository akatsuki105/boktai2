	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	movs r5, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r5
	movs r3, #2
	rsbs r3, r3, #0
	ands r3, r1
	str r3, [r2]
	cmp r0, #0
	beq _08220A1A
	movs r0, #0x80
	lsls r0, r0, #1
	ands r3, r0
	cmp r3, #0
	bne _08220A08
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0, #8]
_08220A08:
	str r5, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
_08220A1A:
	movs r3, #0xaf
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08220A3A
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08220A3A:
	movs r0, #0x80
	lsls r0, r0, #0xa
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _08220A5E
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_08220A5E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
