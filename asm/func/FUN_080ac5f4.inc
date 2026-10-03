	push {lr}
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080AC608
	bl VM_GetValue
	bl FUN_080ac5b4
_080AC608:
	pop {r0}
	bx r0
