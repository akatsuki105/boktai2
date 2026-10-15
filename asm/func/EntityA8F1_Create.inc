	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A3AE0
	ldr r1, _080A3AD8 @ =EntityA8F1_Update
	ldr r2, _080A3ADC @ =EntityA8F1_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityA8F1_Init
	cmp r0, #0
	bge _080A3AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A3AE2
	.align 2, 0
_080A3AD8: .4byte EntityA8F1_Update
_080A3ADC: .4byte EntityA8F1_Destroy
_080A3AE0:
	adds r0, r4, #0
_080A3AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
