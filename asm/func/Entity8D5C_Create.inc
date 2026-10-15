	push {r4, lr}
	movs r0, #4
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080558B0
	ldr r1, _080558AC @ =Entity8D5C_Update
	movs r2, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8D5C_Init
	cmp r0, #0
	bge _080558B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080558B2
	.align 2, 0
_080558AC: .4byte Entity8D5C_Update
_080558B0:
	adds r0, r4, #0
_080558B2:
	pop {r4}
	pop {r1}
	bx r1
