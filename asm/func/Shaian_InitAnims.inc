	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0x10
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0x12
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0x14
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0x16
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x17
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0x18
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x19
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0x1d
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x22
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0x26
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0x24
	movs r3, #0
	bl Enemy_SetAnimEntry
	pop {r4}
	pop {r0}
	bx r0
