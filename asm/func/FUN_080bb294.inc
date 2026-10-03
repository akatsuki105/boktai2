	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080BB2BC @ =0x00001409
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB2C4
	adds r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	ldr r1, _080BB2C0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r7, [r0, r1]
	b _080BB2E8
	.align 2, 0
_080BB2BC: .4byte 0x00001409
_080BB2C0: .4byte 0x030046A0
_080BB2C4:
	cmp r0, #7
	bhi _080BB2E4
	ldr r1, _080BB2DC @ =0x0000140B
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r6, r0
	ldr r1, _080BB2E0 @ =0x000012F4
	adds r0, r0, r1
	movs r7, #0
	ldrsb r7, [r0, r7]
	b _080BB2E8
	.align 2, 0
_080BB2DC: .4byte 0x0000140B
_080BB2E0: .4byte 0x000012F4
_080BB2E4:
	movs r7, #1
	rsbs r7, r7, #0
_080BB2E8:
	cmp r7, #0
	bge _080BB304
	movs r1, #0xce
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _080BB36E
_080BB304:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BB37C @ =0x00000CD8
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x38
	movs r2, #0xcf
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _080BB380 @ =0x000012E8
	adds r5, r6, r0
	ldr r0, [r5]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r0, _080BB384 @ =0x08DAA7B0
	lsls r4, r7, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	movs r0, #1
	bl TextBox_SetInstant
	adds r0, r7, #0
	bl TextBox_ShowLine
	ldr r0, [r5]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080BB36E:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080ba0f0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB37C: .4byte 0x00000CD8
_080BB380: .4byte 0x000012E8
_080BB384: .4byte 0x08DAA7B0
