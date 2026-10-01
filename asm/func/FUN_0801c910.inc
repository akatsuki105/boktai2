	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0
	str r0, [r5, #0x50]
	movs r4, #0
_0801C91A:
	adds r0, r4, #0
	bl GetWeaponID
	subs r0, #1
	cmp r0, #0x38
	bhi _0801C93A
	adds r0, r4, #0
	bl GetWeaponKind
	cmp r0, #2
	bgt _0801C93A
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x50]
	orrs r0, r1
	str r0, [r5, #0x50]
_0801C93A:
	adds r4, #1
	cmp r4, #0xf
	ble _0801C91A
	movs r0, #0x3e
	adds r0, r0, r5
	mov ip, r0
	adds r3, r5, #0
	adds r3, #0x95
	ldr r0, _0801C9D4 @ =0x030046A0
	ldr r0, [r0]
	movs r6, #1
	adds r2, r0, #0
	adds r2, #0x60
	movs r4, #3
_0801C956:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _0801C968
	adds r1, r6, #0
	lsls r1, r0
	ldr r0, [r5, #0x50]
	bics r0, r1
	str r0, [r5, #0x50]
_0801C968:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0801C956
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	strb r0, [r3]
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801c114
	adds r0, r5, #0
	bl FUN_0801c300
	adds r0, r5, #0
	bl FUN_0801c3a8
	adds r0, r5, #0
	bl FUN_0801c518
	ldr r1, _0801C9D8 @ =0x00001308
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, _0801C9DC @ =0x0000EFDA
	bl TextBox_SetBgPltt
	ldr r1, _0801C9E0 @ =0x0000130C
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_0801bf88
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C9D4: .4byte 0x030046A0
_0801C9D8: .4byte 0x00001308
_0801C9DC: .4byte 0x0000EFDA
_0801C9E0: .4byte 0x0000130C
