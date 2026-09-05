	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _082405BC
	bl Script_GetValue
	bl FUN_08240568
_082405BC:
	pop {r0}
	bx r0
