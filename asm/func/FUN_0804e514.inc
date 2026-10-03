	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0804E548 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	beq _0804E550
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804E550
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r2, _0804E54C @ =0x04000003
	adds r0, r3, #0
	bl CpuSet
	ldrh r1, [r4, #0x22]
	movs r0, #1
	orrs r0, r1
	strh r0, [r4, #0x22]
	movs r0, #0
	b _0804E554
	.align 2, 0
_0804E548: .4byte 0x03002B58
_0804E54C: .4byte 0x04000003
_0804E550:
	movs r0, #1
	rsbs r0, r0, #0
_0804E554:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
