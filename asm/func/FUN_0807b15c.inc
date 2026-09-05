	push {lr}
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807B170
	bl Script_GetValue
	bl FUN_0807a798
_0807B170:
	pop {r0}
	bx r0
