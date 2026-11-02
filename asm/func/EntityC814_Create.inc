	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xdc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CB7AC
	ldr r1, _080CB7A4 @ =EntityC814_Update
	ldr r2, _080CB7A8 @ =EntityC814_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityC814_Init
	cmp r0, #0
	bge _080CB7AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CB7AE
	.align 2, 0
_080CB7A4: .4byte EntityC814_Update
_080CB7A8: .4byte EntityC814_Destroy
_080CB7AC:
	adds r0, r4, #0
_080CB7AE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
