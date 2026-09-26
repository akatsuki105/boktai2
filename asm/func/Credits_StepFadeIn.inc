	push {r4, lr}
	adds r4, r0, #0
	bl Credits_TakeStepChanged
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804A680
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl Credits_ApplyLineRect
	ldrb r0, [r4, #0x1a]
	bl TextBox_ShowLine
_0804A680:
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0xb4
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A6A8
	ldr r1, _0804A6A4 @ =0x03004040
	movs r0, #0x40
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl Credits_SetStep
	b _0804A6B2
	.align 2, 0
_0804A6A4: .4byte 0x03004040
_0804A6A8:
	lsls r0, r0, #6
	bl Div
	ldr r1, _0804A6B8 @ =0x03004040
	str r0, [r1]
_0804A6B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6B8: .4byte 0x03004040
