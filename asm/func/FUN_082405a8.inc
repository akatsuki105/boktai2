	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _082405BC
	bl fetch_082316e4
	bl FUN_08240568
_082405BC:
	pop {r0}
	bx r0
