	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da370
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_081da5d0
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F36
	movs r1, #0
	bl VM_ExecByID
	adds r0, r4, #0
	bl KillEntity
_081D9F36:
	pop {r4}
	pop {r0}
	bx r0
