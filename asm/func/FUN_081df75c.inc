	push {r4, lr}
	sub sp, #8
	bl VM_GetValue
	bl FUN_081df720
	adds r4, r0, #0
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
