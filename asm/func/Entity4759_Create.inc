	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4590
	ldr r1, _080A4588 @ =Entity4759_Update
	ldr r2, _080A458C @ =Entity4759_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity4759_Init
	cmp r0, #0
	bge _080A4590
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A4592
	.align 2, 0
_080A4588: .4byte Entity4759_Update
_080A458C: .4byte Entity4759_Destroy
_080A4590:
	adds r0, r4, #0
_080A4592:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
