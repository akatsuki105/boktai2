	push {r4, lr}
	ldr r2, _081E4380 @ =0x00000E54
	adds r1, r0, r2
	ldr r3, _081E4384 @ =0x00000BC4
	adds r2, r0, r3
	movs r4, #2
	rsbs r4, r4, #0
	movs r3, #0xf
_081E4364:
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E4370
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_081E4370:
	adds r1, #0x60
	adds r2, #0x24
	subs r3, #1
	cmp r3, #0
	bge _081E4364
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4380: .4byte 0x00000E54
_081E4384: .4byte 0x00000BC4
