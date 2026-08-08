	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r4, #0
_0821DEAA:
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _0821DEE8 @ =0x00000814
	adds r0, r0, r1
	adds r2, r6, r0
	adds r3, r2, #0
	adds r3, #0x60
	ldrb r0, [r3]
	cmp r0, #0
	beq _0821DEDA
	adds r1, r2, #0
	adds r1, #0x61
	ldrb r0, [r1]
	subs r0, #1
	movs r5, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0821DEDA
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	strb r5, [r3]
_0821DEDA:
	adds r4, #1
	cmp r4, #7
	ble _0821DEAA
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821DEE8: .4byte 0x00000814
