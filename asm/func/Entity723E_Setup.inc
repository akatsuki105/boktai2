	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl GetEntity723E
	adds r5, r0, #0
	cmp r5, #0
	bne _08052B5C
	b _08052EA4
_08052B5C:
	adds r0, r5, #0
	adds r0, #0x26
	movs r1, #0
	mov sb, r1
	strb r4, [r0]
	subs r0, #2
	strb r6, [r0]
	movs r0, #0x8b
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [sp, #0x3c]
	str r0, [r1]
	ldr r2, _08052C34 @ =0x03003E78
	ldr r0, _08052C38 @ =0xFFFFF3FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_080522d0
	ldr r1, _08052C3C @ =Particle_DrawListUnk13
	ldr r2, _08052C40 @ =AuxSprite_DrawListUnk13
	ldr r3, _08052C44 @ =FUN_0822f264
	movs r0, #0
	bl Video_SetDrawPasses
	movs r0, #1
	strb r0, [r5, #0x1c]
	strb r0, [r5, #0x1d]
	mov r1, sb
	str r1, [r5, #0x18]
	movs r4, #0xe1
	lsls r4, r4, #4
	adds r0, r7, #0
	adds r1, r4, #0
	bl Div
	strb r0, [r5, #0x1e]
	adds r0, r7, #0
	adds r1, r4, #0
	bl Mod
	adds r6, r0, #0
	movs r1, #0x3c
	bl Div
	strb r0, [r5, #0x1f]
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	movs r7, #0x64
	muls r0, r7, r0
	movs r1, #0x3c
	bl Div
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
	mov r0, r8
	adds r1, r4, #0
	bl Div
	adds r1, r5, #0
	adds r1, #0x21
	strb r0, [r1]
	mov r0, r8
	adds r1, r4, #0
	bl Mod
	adds r6, r0, #0
	movs r1, #0x3c
	bl Div
	adds r1, r5, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	muls r0, r7, r0
	movs r1, #0x3c
	bl Div
	adds r1, r5, #0
	adds r1, #0x23
	strb r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0x28]
	ldr r0, [sp, #0x38]
	strh r0, [r5, #0x2a]
	ldr r1, [sp, #0x34]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r1, _08052C48 @ =0x0000270F
	cmp r0, r1
	ble _08052C4C
	strh r1, [r5, #0x28]
	b _08052C54
	.align 2, 0
_08052C34: .4byte 0x03003E78
_08052C38: .4byte 0xFFFFF3FF
_08052C3C: .4byte Particle_DrawListUnk13
_08052C40: .4byte AuxSprite_DrawListUnk13
_08052C44: .4byte FUN_0822f264
_08052C48: .4byte 0x0000270F
_08052C4C:
	cmp r0, #0
	bge _08052C54
	mov r0, sb
	strh r0, [r5, #0x28]
_08052C54:
	movs r1, #0x2a
	ldrsh r0, [r5, r1]
	ldr r1, _08052C64 @ =0x0000270F
	cmp r0, r1
	ble _08052C68
	strh r1, [r5, #0x2a]
	b _08052C70
	.align 2, 0
_08052C64: .4byte 0x0000270F
_08052C68:
	cmp r0, #0
	bge _08052C70
	movs r0, #0
	strh r0, [r5, #0x2a]
_08052C70:
	adds r7, r5, #0
	adds r7, #0xd0
	movs r0, #0x30
	adds r0, r0, r5
	mov r8, r0
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa8
	str r1, [sp, #4]
	movs r0, #0x20
	mov sb, r0
	str r0, [sp, #8]
	movs r6, #8
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r7, r5, r1
	str r4, [sp]
	movs r0, #0xc0
	str r0, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0x94
	lsls r0, r0, #2
	adds r7, r5, r0
	str r4, [sp]
	movs r1, #0xd8
	str r1, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r7, r5, r1
	str r4, [sp]
	movs r0, #0xa8
	str r0, [sp, #4]
	movs r1, #0x38
	mov sl, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0xf4
	lsls r0, r0, #2
	adds r7, r5, r0
	str r4, [sp]
	movs r1, #0xc0
	str r1, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0x92
	lsls r1, r1, #3
	adds r7, r5, r1
	str r4, [sp]
	movs r0, #0xd8
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0xaa
	lsls r0, r0, #3
	adds r7, r5, r0
	str r4, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x60
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #4
	bl FUN_082376a4
	movs r1, #0xda
	lsls r1, r1, #3
	adds r7, r5, r1
	movs r0, #0x2a
	ldrsh r2, [r5, r0]
	ldr r0, _08052D74 @ =0x0000270F
	mov r3, r8
	cmp r2, r0
	ble _08052D78
	adds r2, r0, #0
	b _08052D7E
	.align 2, 0
_08052D74: .4byte 0x0000270F
_08052D78:
	cmp r2, #0
	bge _08052D7E
	movs r2, #0
_08052D7E:
	movs r1, #0
	str r1, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x88
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r7, #0
	adds r1, r3, #0
	movs r3, #4
	bl FUN_082376a4
	ldr r1, _08052E8C @ =0x000008B8
	adds r4, r5, r1
	movs r0, #0xa
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, _08052E90 @ =0x000008B4
	adds r6, r5, r1
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r1, _08052E94 @ =0x000008C8
	adds r2, r5, r1
	movs r1, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #3
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r0, _08052E98 @ =0x000008BC
	adds r4, r5, r0
	movs r0, #0xa
	movs r1, #7
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r1, _08052E9C @ =0x000008D8
	adds r2, r5, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #4
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r0, #0x8c
	lsls r0, r0, #4
	adds r4, r5, r0
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1c
	movs r3, #2
	bl TextPanel_Create
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0xb
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r1, _08052EA0 @ =0x000008C4
	adds r4, r5, r1
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #2
	bl TextPanel_Create
	str r0, [r4]
	cmp r0, #0
	blt _08052EA4
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0xc
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r0, #0x85
	lsls r0, r0, #4
	adds r7, r5, r0
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_SetPose
	movs r0, #0x18
	strh r0, [r7, #0x20]
	movs r0, #0x20
	strh r0, [r7, #0x22]
	movs r0, #0
	b _08052EA8
	.align 2, 0
_08052E8C: .4byte 0x000008B8
_08052E90: .4byte 0x000008B4
_08052E94: .4byte 0x000008C8
_08052E98: .4byte 0x000008BC
_08052E9C: .4byte 0x000008D8
_08052EA0: .4byte 0x000008C4
_08052EA4:
	movs r0, #1
	rsbs r0, r0, #0
_08052EA8:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
