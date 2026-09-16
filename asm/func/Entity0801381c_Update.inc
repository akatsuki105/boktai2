	push {r4, lr}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	beq _080137E2
_080137D4:
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r4, [r4, #0x3c]
	cmp r4, #0
	bne _080137D4
_080137E2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
