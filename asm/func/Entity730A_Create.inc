	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #3
	movs r1, #0x58
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08022A04
	ldr r1, _080229FC @ =Entity730A_Update
	ldr r2, _08022A00 @ =Entity730A_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity730A_Init
	cmp r0, #0
	bge _08022A04
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08022A06
	.align 2, 0
_080229FC: .4byte Entity730A_Update
_08022A00: .4byte Entity730A_Destroy
_08022A04:
	adds r0, r4, #0
_08022A06:
	pop {r4, r5}
	pop {r1}
	bx r1
