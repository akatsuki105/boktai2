	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CC90
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_powerDownRFU
_0804CC90:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
