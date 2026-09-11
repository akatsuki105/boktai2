	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xf8
	ldr r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0821B0BA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0821B0BA:
	ldr r0, [r3]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0821B0D0
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0821B0D0:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
