	push {lr}
	adds r2, r0, #0
	ldr r1, [r2]
	ldr r0, [r2, #4]
	cmp r1, #0
	beq _08238166
	str r0, [r1, #4]
_08238166:
	cmp r0, #0
	beq _0823816C
	str r1, [r0]
_0823816C:
	movs r0, #0
	str r0, [r2]
	str r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0
