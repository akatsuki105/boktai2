	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0824073C
	bl fetch_082316e4
	bl PlaySound_08240718
_0824073C:
	pop {r0}
	bx r0
