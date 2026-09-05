	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0824062C
	bl Script_GetValue
	bl FUN_082405c0
_0824062C:
	pop {r0}
	bx r0
