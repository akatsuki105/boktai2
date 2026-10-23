	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080B7930 @ =0x00001429
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B793C
	ldr r2, _080B7934 @ =0x0000142B
	adds r1, r5, r2
	adds r2, #0x2d
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B7938 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r6, [r0, r2]
	b _080B7940
	.align 2, 0
_080B7930: .4byte 0x00001429
_080B7934: .4byte 0x0000142B
_080B7938: .4byte 0x030046A0
_080B793C:
	movs r6, #1
	rsbs r6, r6, #0
_080B7940:
	cmp r6, #0
	bge _080B795C
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl MessageWindow_Close
	bl FUN_08049e5c
	b _080B79C6
_080B795C:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B79CC @ =0x00000F18
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	movs r2, #0xcf
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080B79D0 @ =0x000013FC
	adds r5, r5, r2
	ldr r0, [r5]
	bl MessageWindow_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl MessageWindow_SetRect
	ldr r0, _080B79D4 @ =0x08DAA7B0
	lsls r4, r6, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl Marquee_SetVarValue
	ldrb r1, [r4, #2]
	movs r0, #1
	bl Marquee_SetVarValue
	movs r0, #1
	bl MessageWindow_SetInstant
	adds r0, r6, #0
	bl MessageWindow_ShowLine
	ldr r0, [r5]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r6
	bl Textbox_LookupString
	bl FUN_08049e30
_080B79C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B79CC: .4byte 0x00000F18
_080B79D0: .4byte 0x000013FC
_080B79D4: .4byte 0x08DAA7B0
