	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08240564
	bl Script_GetValue
	bl FUN_082404fc
_08240564:
	pop {r0}
	bx r0
