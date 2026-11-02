	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _081E0794 @ =0x000003E9
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E06EA
	b _081E07EA
_081E06EA:
	adds r0, r5, #0
	bl Entity501B_HideTextPanels
	adds r0, r5, #0
	bl Entity501B_HideSprites
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r7, #0
	str r7, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r4, _081E0798 @ =0x030046A0
	ldr r0, [r4]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r1, [r2]
	ldr r0, [r6]
	adds r1, r1, r0
	ldr r0, _081E079C @ =0x0000270F
	cmp r1, r0
	ble _081E0730
	adds r1, r0, #0
_081E0730:
	str r1, [r2]
	ldr r0, [r4]
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bge _081E073E
	str r7, [r1]
_081E073E:
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r2, #0xd
	movs r3, #2
	bl Entity501B_DrawBgNumber
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #8
	str r1, [sp]
	movs r1, #1
	movs r2, #0xb
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r6]
	cmp r0, #0
	bne _081E07A0
	ldr r0, [r4]
	movs r1, #4
	bl TextPanel_SetMessage
	b _081E07B6
	.align 2, 0
_081E0794: .4byte 0x000003E9
_081E0798: .4byte 0x030046A0
_081E079C: .4byte 0x0000270F
_081E07A0:
	cmp r0, #0
	ble _081E07AE
	ldr r0, [r4]
	movs r1, #2
	bl TextPanel_SetMessage
	b _081E07B6
_081E07AE:
	ldr r0, [r4]
	movs r1, #3
	bl TextPanel_SetMessage
_081E07B6:
	movs r0, #0xf8
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	cmp r2, #0
	bge _081E07CC
	rsbs r2, r2, #0
_081E07CC:
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0804a3e4
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r3, _081E07FC @ =0x000003EA
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E0800 @ =0x000003E9
	adds r0, r5, r1
	strb r2, [r0]
_081E07EA:
	ldr r2, _081E07FC @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #9
	bhi _081E0804
	adds r0, #1
	strh r0, [r1]
	b _081E0832
	.align 2, 0
_081E07FC: .4byte 0x000003EA
_081E0800: .4byte 0x000003E9
_081E0804:
	ldr r0, _081E083C @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0840 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E0832
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _081E0844 @ =FUN_081e03d8
	movs r2, #3
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _081E0848 @ =0x000003E9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
_081E0832:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E083C: .4byte 0x030044E0
_081E0840: .4byte 0x0000030F
_081E0844: .4byte FUN_081e03d8
_081E0848: .4byte 0x000003E9
