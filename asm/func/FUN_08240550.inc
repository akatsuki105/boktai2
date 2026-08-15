	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _08240564
	bl Script_GetValue
	bl FUN_082404fc
_08240564:
	pop {r0}
	bx r0
