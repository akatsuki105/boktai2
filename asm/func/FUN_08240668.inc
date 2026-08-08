	push {lr}
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0824067C
	bl fetch_082316e4
	bl FUN_08240630
_0824067C:
	pop {r0}
	bx r0
