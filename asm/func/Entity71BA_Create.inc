	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A076C
	ldr r1, _080A0764 @ =Entity71BA_Update
	ldr r2, _080A0768 @ =Entity71BA_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity71BA_Init
	cmp r0, #0
	bge _080A076C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A076E
	.align 2, 0
_080A0764: .4byte Entity71BA_Update
_080A0768: .4byte Entity71BA_Destroy
_080A076C:
	adds r0, r4, #0
_080A076E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
