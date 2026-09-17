	push {r4, lr}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	beq _08013B42
_08013B34:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r4, [r4, #0x68]
	cmp r4, #0
	bne _08013B34
_08013B42:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
