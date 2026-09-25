	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x93
	lsls r1, r1, #5
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0820EB30
	ldr r1, _0820EB28 @ =EnemyDexMenu_Update
	ldr r2, _0820EB2C @ =EnemyDexMenu_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EnemyDexMenu_Init
	cmp r0, #0
	bge _0820EB30
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0820EB32
	.align 2, 0
_0820EB28: .4byte EnemyDexMenu_Update
_0820EB2C: .4byte EnemyDexMenu_Destroy
_0820EB30:
	adds r0, r4, #0
_0820EB32:
	pop {r4, r5}
	pop {r1}
	bx r1
