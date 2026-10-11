	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E1FD6
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl MessageWindow_ShowLine
	movs r0, #1
	bl MessageWindow_SetInstant
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E1FD6:
	adds r1, r5, #0
	adds r1, #0x62
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E1FE6
	adds r0, #1
	strh r0, [r1]
	b _081E1FF0
_081E1FE6:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x64]
	orrs r0, r1
	str r0, [r5, #0x64]
_081E1FF0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
