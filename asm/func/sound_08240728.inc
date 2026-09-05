	push {lr}
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0824073C
	bl Script_GetValue
	bl PlaySound_08240718
_0824073C:
	pop {r0}
	bx r0
