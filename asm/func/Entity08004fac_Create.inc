	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08004FE4
	ldr r1, _08004FDC @ =Entity08004fac_Update
	ldr r2, _08004FE0 @ =Entity08004fac_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity08004fac_Init
	cmp r0, #0
	bge _08004FE4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08004FE6
	.align 2, 0
_08004FDC: .4byte Entity08004fac_Update
_08004FE0: .4byte Entity08004fac_Destroy
_08004FE4:
	adds r0, r4, #0
_08004FE6:
	pop {r4, r5}
	pop {r1}
	bx r1
