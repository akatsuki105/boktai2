	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E0B0C
	bl VM_GetPC_Proxy
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E0B26
_081E0B0C:
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E0B2C
	bl VM_GetPC_Proxy
	movs r3, #0xf6
	lsls r3, r3, #2
	adds r1, r4, r3
	str r0, [r1]
	cmp r0, #0
	bne _081E0B2C
_081E0B26:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E0BB6
_081E0B2C:
	movs r0, #7
	bl MainMenu_SetHudMode
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl Entity501B_InitBg
	adds r0, r4, #0
	bl Entity501B_InitTextPanels
	adds r0, r4, #0
	bl Entity501B_InitSprites
	adds r0, r4, #0
	bl Entity501B_InitSpritePos
	ldr r0, _081E0BC0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _081E0BC4 @ =0x00000912
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	movs r1, #1
	bl Entity501B_SetNumber
	adds r0, r4, #0
	bl Entity501B_InitAuxSprite
	adds r0, r4, #0
	bl Entity501B_LoadScore
	ldr r1, _081E0BC8 @ =Entity501B_StateSpin
	movs r2, #0
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081E0BCC @ =0x000003E9
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E0BD0 @ =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl StartBgObjPlttFade
	movs r0, #1
_081E0BB6:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E0BC0: .4byte 0x030046A0
_081E0BC4: .4byte 0x00000912
_081E0BC8: .4byte Entity501B_StateSpin
_081E0BCC: .4byte 0x000003E9
_081E0BD0: .4byte 0x0000FFFF
