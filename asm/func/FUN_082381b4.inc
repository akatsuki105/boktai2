	push {lr}
	ldr r1, [r0, #4]
	ldr r0, [r1, #4]
	cmp r0, #0
	beq _082381C2
	adds r0, r1, #0
	b _082381C4
_082381C2:
	movs r0, #0
_082381C4:
	pop {r1}
	bx r1
