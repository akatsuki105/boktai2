	push {r4, lr}
	ldr r4, _081DC6CC @ =0x030001A8
	ldr r0, [r4]
	cmp r0, #0
	beq _081DC6C4
	bl LinkBattleLobby_HideSprites
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl Marquee_Clear
	ldr r0, [r4]
	bl KillEntity
_081DC6C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC6CC: .4byte 0x030001A8
