	push {lr}
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809C240
	bl VM_GetValue
	bl FUN_0809c08c
_0809C240:
	pop {r0}
	bx r0
