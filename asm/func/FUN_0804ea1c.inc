	push {lr}
	bl TextPanelManager_DestroyAll
	bl MosaicFader_Stop
	ldr r2, _0804EA54 @ =0x03003E78
	ldr r0, _0804EA58 @ =0xFFFFF9FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	bl Video_ResetFrameState
	ldr r1, _0804EA5C @ =nop_0822e738
	ldr r2, _0804EA60 @ =nop_0822b09c
	ldr r3, _0804EA64 @ =FUN_0822f584
	movs r0, #0
	bl Video_SetDrawPasses
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl ClearBGTilemapBuffer
	pop {r0}
	bx r0
	.align 2, 0
_0804EA54: .4byte 0x03003E78
_0804EA58: .4byte 0xFFFFF9FF
_0804EA5C: .4byte nop_0822e738
_0804EA60: .4byte nop_0822b09c
_0804EA64: .4byte FUN_0822f584
