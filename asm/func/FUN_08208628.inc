	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820864A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_0820864A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082086D0
	ldrb r1, [r4, #0x1b]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r2, [r0]
	subs r1, r1, r2
	adds r3, r1, #0
	adds r5, r0, #0
	cmp r1, #0
	bge _08208674
	rsbs r3, r1, #0
_08208674:
	cmp r3, #8
	bgt _0820867C
	adds r0, r2, r1
	b _0820868E
_0820867C:
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x7f
	ble _0820868A
	adds r0, r2, #0
	subs r0, #8
	b _0820868E
_0820868A:
	adds r0, r2, #0
	adds r0, #8
_0820868E:
	strb r0, [r5]
	ldrb r2, [r5]
	strb r2, [r5]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
	ldrb r0, [r5]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _082086D0
	movs r0, #1
	strb r0, [r4, #7]
_082086D0:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
