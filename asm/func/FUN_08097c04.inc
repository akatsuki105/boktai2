	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08097C38 @ =0x00003AEB
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08097C22
	ldr r2, _08097C3C @ =0x00003FF0
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	bge _08097C44
_08097C22:
	ldr r1, _08097C40 @ =0x0000204C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _08097C92
	.align 2, 0
_08097C38: .4byte 0x00003AEB
_08097C3C: .4byte 0x00003FF0
_08097C40: .4byte 0x0000204C
_08097C44:
	ldr r0, _08097C98 @ =0x0000204C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097C9C @ =0x00002044
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xcf
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r4, #0x4c]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl TextBox_ShowLine
	ldr r0, [r4, #0x4c]
	bl VM_ParseStringRef
	adds r0, #0x12
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_08097C92:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097C98: .4byte 0x0000204C
_08097C9C: .4byte 0x00002044
