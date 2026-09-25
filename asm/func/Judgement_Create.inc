	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A9EC4
	ldr r1, _080A9EBC @ =Judgement_Update
	ldr r2, _080A9EC0 @ =Judgement_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Judgement_Init
	cmp r0, #0
	bge _080A9EC4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A9EC6
	.align 2, 0
_080A9EBC: .4byte Judgement_Update
_080A9EC0: .4byte Judgement_Destroy
_080A9EC4:
	adds r0, r4, #0
_080A9EC6:
	pop {r4, r5}
	pop {r1}
	bx r1
