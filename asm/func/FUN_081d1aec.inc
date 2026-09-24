	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x58
	ldr r0, _081D1B0C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D1B10
	movs r0, #1
	b _081D1B12
	.align 2, 0
_081D1B0C: .4byte 0x030046A0
_081D1B10:
	movs r0, #0
_081D1B12:
	cmp r0, #0
	bne _081D1B22
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	b _081D1B2E
_081D1B22:
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
_081D1B2E:
	pop {r1}
	bx r1
	.align 2, 0
