	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A2514
	ldr r1, _080A250C @ =SolarCircle_Update
	ldr r2, _080A2510 @ =SolarCircle_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl SolarCircle_Init
	cmp r0, #0
	bge _080A2514
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A2516
	.align 2, 0
_080A250C: .4byte SolarCircle_Update
_080A2510: .4byte SolarCircle_Destroy
_080A2514:
	adds r0, r4, #0
_080A2516:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
