	push {lr}
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5EA0
	movs r1, #0
	bl VM_ExecByID
_080A5EA0:
	pop {r0}
	bx r0
