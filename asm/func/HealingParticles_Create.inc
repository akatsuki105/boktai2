	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x81
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A94B8
	ldr r1, _080A94B0 @ =HealingParticles_Update
	ldr r2, _080A94B4 @ =HealingParticles_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl HealingParticles_Init
	cmp r0, #0
	bge _080A94B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A94BA
	.align 2, 0
_080A94B0: .4byte HealingParticles_Update
_080A94B4: .4byte HealingParticles_Destroy
_080A94B8:
	adds r0, r4, #0
_080A94BA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
