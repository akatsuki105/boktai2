	push {lr}
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0824067C
	bl Script_GetValue
	bl FUN_08240630
_0824067C:
	pop {r0}
	bx r0
