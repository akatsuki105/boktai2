	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x74
	movs r1, #1
	bl VM_GetKeywordValue
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	bne _080367C6
	ldr r1, _080367B8 @ =0x0000105C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080367C4
	ldr r1, _080367BC @ =EntityBA4B_Update
	ldr r2, _080367C0 @ =EntityBA4B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityBA4B_Init
	cmp r0, #0
	bge _080367C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080367C6
	.align 2, 0
_080367B8: .4byte 0x0000105C
_080367BC: .4byte EntityBA4B_Update
_080367C0: .4byte EntityBA4B_Destroy
_080367C4:
	adds r0, r4, #0
_080367C6:
	pop {r4, r5}
	pop {r1}
	bx r1
