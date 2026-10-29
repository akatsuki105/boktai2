	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080AD1D8 @ =0x0000066C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AD1E4
	strh r5, [r4, #0x18]
	ldr r1, _080AD1DC @ =Entity5292_Update
	ldr r2, _080AD1E0 @ =Entity5292_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity5292_Init
	cmp r0, #0
	bge _080AD1E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AD1E6
	.align 2, 0
_080AD1D8: .4byte 0x0000066C
_080AD1DC: .4byte Entity5292_Update
_080AD1E0: .4byte Entity5292_Destroy
_080AD1E4:
	adds r0, r4, #0
_080AD1E6:
	pop {r4, r5}
	pop {r1}
	bx r1
