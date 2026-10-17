	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081da5d0
	bl FUN_081df974
	ldr r0, _081D9F88 @ =0x000002A2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F82
	movs r1, #0
	bl VM_ExecByID
	adds r0, r4, #0
	bl KillEntity
_081D9F82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D9F88: .4byte 0x000002A2
