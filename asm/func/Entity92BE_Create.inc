	push {r4, lr}
	movs r0, #9
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A70FC
	ldr r1, _080A70F4 @ =Entity92BE_Update
	ldr r2, _080A70F8 @ =Entity92BE_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity92BE_Init
	cmp r0, #0
	beq _080A70FC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A70FE
	.align 2, 0
_080A70F4: .4byte Entity92BE_Update
_080A70F8: .4byte Entity92BE_Destroy
_080A70FC:
	adds r0, r4, #0
_080A70FE:
	pop {r4}
	pop {r1}
	bx r1
