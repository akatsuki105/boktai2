	push {lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _0823D378 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r2, [r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0823D378: .4byte gSystemSaveData
