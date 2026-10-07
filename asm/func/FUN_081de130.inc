	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE182
	ldr r0, _081DE1F4 @ =0x030044D0
	movs r3, #0
	str r3, [r0]
	movs r2, #4
	ldr r1, _081DE1F8 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x55
	strb r3, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0x80
	lsls r0, r0, #7
	strh r0, [r1]
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	movs r2, #0xb6
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	movs r0, #1
	bl Sound_FadeOutBGM
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
_081DE182:
	adds r4, r5, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #0
	bne _081DE1D2
	bl TextBox_IsOpen
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE1D2
	movs r0, #1
	strb r0, [r4]
	movs r0, #5
	bl FUN_0809c08c
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #2
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r2, _081DE1FC @ =0x03003E78
	ldr r0, _081DE200 @ =0xFFFFF1FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	bl Video_ResetFrameState
_081DE1D2:
	ldr r1, _081DE204 @ =nop_0822e738
	ldr r2, _081DE208 @ =nop_0822b09c
	ldr r3, _081DE20C @ =FUN_0822f584
	movs r0, #0
	bl Video_SetDrawPasses
	ldr r0, [r5, #0x34]
	cmp r0, #0x1d
	bhi _081DE1EA
	ldr r1, _081DE210 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081DE1EA:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DE1F4: .4byte 0x030044D0
_081DE1F8: .4byte 0x030044BC
_081DE1FC: .4byte 0x03003E78
_081DE200: .4byte 0xFFFFF1FF
_081DE204: .4byte nop_0822e738
_081DE208: .4byte nop_0822b09c
_081DE20C: .4byte FUN_0822f584
_081DE210: .4byte 0x030047B8
