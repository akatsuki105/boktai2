	push {lr}
	ldr r2, [r1, #0x78]
	ldr r1, [r1, #0x7c]
	cmp r2, #0
	beq _080160BE
	str r1, [r2, #0x7c]
	b _080160C0
_080160BE:
	str r1, [r0, #0x1c]
_080160C0:
	cmp r1, #0
	beq _080160C6
	str r2, [r1, #0x78]
_080160C6:
	movs r0, #0
	pop {r1}
	bx r1
