	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0
	ldr r0, _082349A4 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #0xc]
	ldrb r0, [r0]
	cmp r2, r0
	bge _082349B0
	adds r3, r0, #0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
_0823499A:
	ldr r0, [r1]
	cmp r0, r4
	bne _082349A8
	adds r0, r1, #0
	b _082349B2
	.align 2, 0
_082349A4: .4byte 0x030046A4
_082349A8:
	adds r1, #0x2c
	adds r2, #1
	cmp r2, r3
	blt _0823499A
_082349B0:
	movs r0, #0
_082349B2:
	pop {r4}
	pop {r1}
	bx r1
