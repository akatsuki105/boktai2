	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080B5BC4 @ =0x00001429
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B5BCC
	ldr r2, _080B5BC8 @ =0x0000142B
	adds r5, r6, r2
	ldrb r0, [r5]
	adds r1, #0x2f
	adds r4, r6, r1
	adds r0, r4, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r7, r0, #0
	ldrb r0, [r5]
	adds r4, r4, r0
	ldrb r0, [r4]
	bl Item_GetRotStageIcon
	adds r3, r0, #0
	b _080B5BD2
	.align 2, 0
_080B5BC4: .4byte 0x00001429
_080B5BC8: .4byte 0x0000142B
_080B5BCC:
	movs r7, #1
	rsbs r7, r7, #0
	movs r3, #0xcf
_080B5BD2:
	cmp r7, #0
	bge _080B5BEE
	movs r2, #0xf2
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl MessageWindow_Close
	bl Marquee_Clear
	b _080B5CA4
_080B5BEE:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B5C5C @ =0x00000F18
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x38
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080B5C60 @ =0x000013F4
	adds r4, r6, r2
	ldr r0, [r4]
	bl MessageWindow_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl MessageWindow_SetRect
	movs r0, #1
	bl MessageWindow_SetInstant
	adds r0, r7, #0
	bl MessageWindow_ShowLine
	ldr r0, [r4]
	bl VM_ParseStringRef
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, _080B5C64 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080B5C7A
	cmp r7, #1
	bne _080B5C68
	adds r0, r1, #0
	adds r0, #0xea
	b _080B5C70
	.align 2, 0
_080B5C5C: .4byte 0x00000F18
_080B5C60: .4byte 0x000013F4
_080B5C64: .4byte 0x030046A0
_080B5C68:
	cmp r7, #0xd
	bne _080B5C7A
	adds r0, r1, #0
	adds r0, #0xa9
_080B5C70:
	bl GetStringByID
	bl Marquee_SetText
	b _080B5CA4
_080B5C7A:
	ldr r0, _080B5C94 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080B5C90
	cmp r0, #5
	bne _080B5C98
_080B5C90:
	adds r1, #0x4e
	b _080B5C9A
	.align 2, 0
_080B5C94: .4byte 0x030046A0
_080B5C98:
	adds r1, #0x9c
_080B5C9A:
	adds r0, r1, r7
	bl GetStringByID
	bl Marquee_SetText
_080B5CA4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
