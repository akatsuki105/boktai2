	push {lr}
	adds r1, r0, #0
	movs r0, #0
	str r0, [r1, #0x1c]
	ldr r2, _08004CA4 @ =0x03000024
	ldr r0, [r2]
	ldr r0, [r0, #0x18]
	str r0, [r1, #0x20]
	cmp r0, #0
	beq _08004C9A
	str r1, [r0, #0x1c]
_08004C9A:
	ldr r0, [r2]
	str r1, [r0, #0x18]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08004CA4: .4byte 0x03000024
