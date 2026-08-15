	push {r4, lr}
	sub sp, #8
	adds r4, r1, #0
	mov r1, sp
	bl Script_LookupById
	add r1, sp, #4
	bl VM_ReadContainerLength
	ldr r2, [sp]
	adds r1, r4, #0
	bl Script_Exec
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
