	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x69
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r4, r0, #0
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity5DA5_SetState
	pop {r4, r5}
	pop {r1}
	bx r1
