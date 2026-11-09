	push {r4, lr}
	adds r4, r0, #0
	bl Marquee_Clear
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl LinkBattleLobby_HideSprites
	movs r0, #2
	bl FUN_081df95c
	ldr r0, _081DC328 @ =0x000003DA
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC322
	movs r1, #0
	bl VM_ExecByID
	adds r0, r4, #0
	bl KillEntity
_081DC322:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC328: .4byte 0x000003DA
