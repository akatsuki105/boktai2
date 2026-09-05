	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001A46
	ldr r0, [r4, #0x30]
	b _08001A48
_08001A46:
	ldr r0, [r4, #0x24]
_08001A48:
	ldr r1, [r4, #0x2c]
	ldr r2, _08001A60 @ =0x04000068
	bl CpuSet
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001A60: .4byte 0x04000068
