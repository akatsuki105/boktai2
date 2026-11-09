	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #0
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #2
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #4
	movs r3, #0
	bl Enemy_SetAnimEntry
	pop {r4}
	pop {r0}
	bx r0
