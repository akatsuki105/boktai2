	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x88
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08211BA4
	ldr r1, _08211B9C @ =FUN_082117cc
	ldr r2, _08211BA0 @ =FUN_082119d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08211a5c
	cmp r0, #0
	bge _08211BA4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08211BA6
	.align 2, 0
_08211B9C: .4byte FUN_082117cc
_08211BA0: .4byte FUN_082119d0
_08211BA4:
	adds r0, r4, #0
_08211BA6:
	pop {r4, r5}
	pop {r1}
	bx r1
