	push {lr}
	movs r2, #0x96
	lsls r2, r2, #3
	adds r1, r0, r2
	ldr r2, [r1]
	cmp r2, #0
	beq _0807266A
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
_0807266A:
	pop {r0}
	bx r0
	.align 2, 0
