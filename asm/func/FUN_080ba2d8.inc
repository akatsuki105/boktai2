	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080BA2FC @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA304
	ldr r2, _080BA300 @ =0x0000140B
	adds r4, r5, r2
	ldrb r0, [r4]
	bl GetNormalItemID
	adds r6, r0, #0
	ldrb r0, [r4]
	bl item_08092034
	adds r3, r0, #0
	b _080BA33A
	.align 2, 0
_080BA2FC: .4byte 0x00001409
_080BA300: .4byte 0x0000140B
_080BA304:
	cmp r0, #7
	bhi _080BA334
	ldr r1, _080BA328 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BA32C @ =0x000012E4
	adds r0, r0, r2
	movs r6, #0
	ldrsb r6, [r0, r6]
	ldr r1, _080BA330 @ =0x08DAA8D8
	lsls r0, r6, #4
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	movs r3, #0xd0
	cmp r0, #0
	bne _080BA33A
	b _080BA338
	.align 2, 0
_080BA328: .4byte 0x0000140B
_080BA32C: .4byte 0x000012E4
_080BA330: .4byte 0x08DAA8D8
_080BA334:
	movs r6, #1
	rsbs r6, r6, #0
_080BA338:
	movs r3, #0xcf
_080BA33A:
	cmp r6, #0
	bge _080BA356
	movs r1, #0xce
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _080BA408
_080BA356:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BA3C0 @ =0x00000CD8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080BA3C4 @ =0x000012E4
	adds r4, r5, r2
	ldr r0, [r4]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	movs r0, #1
	bl TextBox_SetInstant
	adds r0, r6, #0
	bl TextBox_ShowLine
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, _080BA3C8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080BA3DE
	cmp r6, #1
	bne _080BA3CC
	adds r0, r1, #0
	adds r0, #0xea
	b _080BA3D4
	.align 2, 0
_080BA3C0: .4byte 0x00000CD8
_080BA3C4: .4byte 0x000012E4
_080BA3C8: .4byte 0x030046A0
_080BA3CC:
	cmp r6, #0xd
	bne _080BA3DE
	adds r0, r1, #0
	adds r0, #0xa9
_080BA3D4:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080BA408
_080BA3DE:
	ldr r0, _080BA3F8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080BA3F4
	cmp r0, #5
	bne _080BA3FC
_080BA3F4:
	adds r1, #0x4e
	b _080BA3FE
	.align 2, 0
_080BA3F8: .4byte 0x030046A0
_080BA3FC:
	adds r1, #0x9c
_080BA3FE:
	adds r0, r1, r6
	bl Textbox_LookupString
	bl FUN_08049e30
_080BA408:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
