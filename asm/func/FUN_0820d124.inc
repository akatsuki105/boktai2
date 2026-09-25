	push {lr}
	movs r0, #0x6b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820D134
	bl Script_GetValue
_0820D134:
	pop {r0}
	bx r0
