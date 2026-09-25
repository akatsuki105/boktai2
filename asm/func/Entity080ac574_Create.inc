	push {r4, lr}
	movs r1, #0x8c
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC5AC
	ldr r1, _080AC5A4 @ =Entity080ac574_Update
	ldr r2, _080AC5A8 @ =Entity080ac574_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080ac574_Init
	cmp r0, #0
	bge _080AC5AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AC5AE
	.align 2, 0
_080AC5A4: .4byte Entity080ac574_Update
_080AC5A8: .4byte Entity080ac574_Destroy
_080AC5AC:
	adds r0, r4, #0
_080AC5AE:
	pop {r4}
	pop {r1}
	bx r1
