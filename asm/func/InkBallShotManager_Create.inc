	push {r4, lr}
	ldr r0, _082034F8 @ =0x03000218
	ldr r0, [r0]
	cmp r0, #0
	bne _08203506
	movs r1, #0x86
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08203504
	ldr r1, _082034FC @ =InkBallShotManager_Update
	ldr r2, _08203500 @ =InkBallShotManager_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl InkBallShotManager_Init
	cmp r0, #0
	bge _08203504
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08203506
	.align 2, 0
_082034F8: .4byte 0x03000218
_082034FC: .4byte InkBallShotManager_Update
_08203500: .4byte InkBallShotManager_Destroy
_08203504:
	adds r0, r4, #0
_08203506:
	pop {r4}
	pop {r1}
	bx r1
