	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E049C @ =0x000003E9
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E0466
	adds r0, r6, #0
	bl Entity501B_HideSprites
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r3, #0xf8
	lsls r3, r3, #2
	adds r4, r6, r3
	ldr r0, [r4]
	bl TextPanel_Hide
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #6
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	bl FUN_081df908
	strb r5, [r7]
_081E0466:
	ldr r0, _081E04A0 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081E0474
	ldrb r1, [r0, #0x1c]
_081E0474:
	cmp r1, #0x16
	bne _081E0494
	ldr r1, _081E04A4 @ =FUN_081e04a8
	movs r2, #4
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r6, r3
	str r1, [r0]
	ldr r0, _081E049C @ =0x000003E9
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
_081E0494:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E049C: .4byte 0x000003E9
_081E04A0: .4byte 0x03002C68
_081E04A4: .4byte FUN_081e04a8
