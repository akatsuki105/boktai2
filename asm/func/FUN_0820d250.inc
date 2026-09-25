	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x26
	ldrb r0, [r4]
	bl FUN_0820d00c
	adds r6, r0, #0
	adds r0, r5, #0
	bl FUN_0820d21c
	ldr r0, [r5, #0x28]
	ldr r2, _0820D2A0 @ =0x00001110
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x28]
	movs r1, #2
	str r1, [sp]
	movs r1, #8
	movs r2, #3
	movs r3, #0x14
	bl TextPanel_SetRect
	ldrb r0, [r4]
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820D2A4
	ldr r0, [r5, #0x28]
	ldrb r1, [r4]
	bl TextPanel_SetMessage
	b _0820D2AC
	.align 2, 0
_0820D2A0: .4byte 0x00001110
_0820D2A4:
	ldr r0, [r5, #0x28]
	movs r1, #0x39
	bl TextPanel_SetMessage
_0820D2AC:
	ldr r0, [r5, #0x28]
	bl TextPanel_Start
	adds r0, r5, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #1
	beq _0820D314
	cmp r0, #1
	bgt _0820D2C6
	cmp r0, #0
	beq _0820D2D0
	b _0820D5E4
_0820D2C6:
	cmp r0, #2
	beq _0820D35C
	cmp r0, #3
	beq _0820D398
	b _0820D5E4
_0820D2D0:
	cmp r6, #0
	bne _0820D2D6
	b _0820D5E4
_0820D2D6:
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	bl FUN_0820cc8c
	adds r4, r0, #0
	ldr r0, [r5, #0x2c]
	ldr r3, _0820D310 @ =0x00001254
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x2c]
	movs r1, #4
	str r1, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5, #0x2c]
	adds r1, r4, #0
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x2c]
	bl TextPanel_Start
	b _0820D5E4
	.align 2, 0
_0820D310: .4byte 0x00001254
_0820D314:
	cmp r6, #0
	bne _0820D31A
	b _0820D5E4
_0820D31A:
	ldr r0, [r5, #0x30]
	ldr r2, _0820D354 @ =0x00001248
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x30]
	movs r1, #4
	str r1, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5, #0x30]
	adds r2, r5, #0
	adds r2, #0x26
	ldr r3, _0820D358 @ =0x00001114
	adds r1, r5, r3
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x30]
	bl TextPanel_Start
	b _0820D5E4
	.align 2, 0
_0820D354: .4byte 0x00001248
_0820D358: .4byte 0x00001114
_0820D35C:
	cmp r6, #0
	beq _0820D37C
	ldr r0, _0820D374 @ =0x0000110E
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _0820D378 @ =0x0000FFFE
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	b _0820D5E4
	.align 2, 0
_0820D374: .4byte 0x0000110E
_0820D378: .4byte 0x0000FFFE
_0820D37C:
	ldr r1, _0820D390 @ =0x0000110E
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _0820D394 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	bl FUN_08049e5c
	b _0820D5E4
	.align 2, 0
_0820D390: .4byte 0x0000110E
_0820D394: .4byte 0x0000FFFE
_0820D398:
	cmp r6, #0
	bne _0820D39E
	b _0820D5E4
_0820D39E:
	adds r4, r5, #0
	adds r4, #0x26
	ldrb r0, [r4]
	lsls r0, r0, #2
	ldr r2, _0820D404 @ =0x00001150
	adds r0, r0, r2
	adds r6, r5, r0
	movs r3, #0x10
	mov r8, r3
	ldr r0, [r5, #0x40]
	adds r2, #0xe8
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x40]
	movs r7, #2
	str r7, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #6
	bl TextPanel_SetRect
	ldr r0, [r5, #0x40]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x40]
	bl TextPanel_Start
	ldrb r0, [r6, #1]
	mov sb, r4
	cmp r0, #0xff
	bne _0820D40C
	ldr r0, [r5, #0x38]
	ldr r3, _0820D408 @ =0x0000123C
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl TextPanel_SetRect
	ldr r0, [r5, #0x38]
	movs r1, #0
	b _0820D490
	.align 2, 0
_0820D404: .4byte 0x00001150
_0820D408: .4byte 0x0000123C
_0820D40C:
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #0
	bl FUN_0820d04c
	cmp r0, #0
	beq _0820D4A0
	ldrb r0, [r6, #1]
	cmp r0, #0xfe
	bhi _0820D4C8
	ldrb r0, [r6]
	cmp r0, #1
	beq _0820D440
	cmp r0, #1
	bgt _0820D430
	cmp r0, #0
	beq _0820D436
	b _0820D4C8
_0820D430:
	cmp r0, #2
	beq _0820D472
	b _0820D4C8
_0820D436:
	ldr r0, [r5, #0x38]
	ldr r2, _0820D43C @ =0x00001234
	b _0820D476
	.align 2, 0
_0820D43C: .4byte 0x00001234
_0820D440:
	ldr r0, [r5, #0x38]
	movs r3, #0x92
	lsls r3, r3, #5
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl TextPanel_SetRect
	ldr r0, [r5, #0x38]
	ldrb r1, [r6, #1]
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x38]
	adds r2, r5, #0
	adds r2, #0x49
	movs r1, #0
	bl FUN_0804a40c
	b _0820D494
_0820D472:
	ldr r0, [r5, #0x38]
	ldr r2, _0820D49C @ =0x00001244
_0820D476:
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl TextPanel_SetRect
	ldr r0, [r5, #0x38]
	ldrb r1, [r6, #1]
_0820D490:
	bl TextPanel_SetMessage
_0820D494:
	ldr r0, [r5, #0x38]
	bl TextPanel_Start
	b _0820D4C8
	.align 2, 0
_0820D49C: .4byte 0x00001244
_0820D4A0:
	ldr r0, [r5, #0x38]
	ldr r3, _0820D51C @ =0x00001110
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl TextPanel_SetRect
	ldr r0, [r5, #0x38]
	movs r1, #0x39
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x38]
	bl TextPanel_Start
_0820D4C8:
	movs r0, #2
	add r8, r0
	ldr r0, [r5, #0x44]
	ldr r2, _0820D520 @ =0x00001238
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x44]
	movs r4, #2
	str r4, [sp]
	movs r1, #1
	mov r2, r8
	movs r3, #6
	bl TextPanel_SetRect
	ldr r0, [r5, #0x44]
	movs r1, #1
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x44]
	bl TextPanel_Start
	ldrb r0, [r6, #3]
	cmp r0, #0xff
	bne _0820D528
	ldr r0, [r5, #0x3c]
	ldr r3, _0820D524 @ =0x0000123C
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5, #0x3c]
	movs r1, #0
	b _0820D5AC
	.align 2, 0
_0820D51C: .4byte 0x00001110
_0820D520: .4byte 0x00001238
_0820D524: .4byte 0x0000123C
_0820D528:
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #1
	bl FUN_0820d04c
	cmp r0, #0
	beq _0820D5BC
	ldrb r0, [r6, #3]
	cmp r0, #0xfe
	bhi _0820D5E4
	ldrb r0, [r6, #2]
	cmp r0, #1
	beq _0820D55C
	cmp r0, #1
	bgt _0820D54C
	cmp r0, #0
	beq _0820D552
	b _0820D5E4
_0820D54C:
	cmp r0, #2
	beq _0820D58E
	b _0820D5E4
_0820D552:
	ldr r0, [r5, #0x3c]
	ldr r2, _0820D558 @ =0x00001234
	b _0820D592
	.align 2, 0
_0820D558: .4byte 0x00001234
_0820D55C:
	ldr r0, [r5, #0x3c]
	movs r3, #0x92
	lsls r3, r3, #5
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5, #0x3c]
	ldrb r1, [r6, #3]
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x3c]
	adds r2, r5, #0
	adds r2, #0x49
	movs r1, #0
	bl FUN_0804a40c
	b _0820D5B0
_0820D58E:
	ldr r0, [r5, #0x3c]
	ldr r2, _0820D5B8 @ =0x00001244
_0820D592:
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5, #0x3c]
	ldrb r1, [r6, #3]
_0820D5AC:
	bl TextPanel_SetMessage
_0820D5B0:
	ldr r0, [r5, #0x3c]
	bl TextPanel_Start
	b _0820D5E4
	.align 2, 0
_0820D5B8: .4byte 0x00001244
_0820D5BC:
	ldr r0, [r5, #0x3c]
	ldr r3, _0820D5F4 @ =0x00001110
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5, #0x3c]
	movs r1, #0x39
	bl TextPanel_SetMessage
	ldr r0, [r5, #0x3c]
	bl TextPanel_Start
_0820D5E4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820D5F4: .4byte 0x00001110
