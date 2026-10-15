	push {r4, r5, lr}
	movs r2, #0
	ldr r3, _081E3FDC @ =0x00001598
	adds r1, r0, r3
	ldrb r5, [r1]
	cmp r2, r5
	bge _081E3FD6
	movs r4, #2
	rsbs r4, r4, #0
	adds r3, r1, #0
	movs r5, #0x87
	lsls r5, r5, #4
	adds r1, r0, r5
_081E3FC6:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x60
	adds r2, #1
	ldrb r0, [r3]
	cmp r2, r0
	blt _081E3FC6
_081E3FD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E3FDC: .4byte 0x00001598
