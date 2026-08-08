	push {lr}
	ldr r2, [r0, #4]
	b _082381DA
_082381CE:
	ldrb r0, [r2, #8]
	cmp r0, r1
	bne _082381D8
	adds r0, r2, #0
	b _082381E2
_082381D8:
	ldr r2, [r2, #4]
_082381DA:
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _082381CE
	movs r0, #0
_082381E2:
	pop {r1}
	bx r1
	.align 2, 0
