	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x33
	ldrb r0, [r5]
	cmp r0, #0
	beq _08054C62
	ldr r0, [r4, #0x34]
	adds r2, r0, #1
	str r2, [r4, #0x34]
	cmp r2, #0x3b
	ble _08054BF4
	adds r0, r4, #0
	bl BlackPanther_HideScorePopup
	movs r0, #0
	str r0, [r4, #0x34]
	strb r0, [r5]
	b _08054C5C
_08054BF4:
	cmp r2, #9
	ble _08054C22
	cmp r2, #0x31
	ble _08054C0A
	movs r0, #3
	ands r2, r0
	movs r0, #1
	cmp r2, #1
	bgt _08054C1C
	movs r0, #0
	b _08054C1C
_08054C0A:
	cmp r2, #0x1d
	ble _08054C1A
	movs r1, #3
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _08054C1C
_08054C1A:
	movs r0, #1
_08054C1C:
	movs r5, #0
	movs r6, #0x88
	b _08054C2C
_08054C22:
	movs r0, #0xa
	subs r0, r0, r2
	lsls r5, r0, #3
	movs r6, #0x88
	movs r0, #1
_08054C2C:
	cmp r0, #0
	beq _08054C5C
	ldr r1, _08054C54 @ =0x000019C8
	adds r0, r4, r1
	ldr r2, _08054C58 @ =0x00001828
	adds r1, r4, r2
	ldr r2, [r4, #0x38]
	movs r3, #0x1e
	str r3, [sp]
	str r5, [sp, #4]
	subs r3, r6, #2
	str r3, [sp, #8]
	movs r3, #8
	str r3, [sp, #0xc]
	movs r3, #0
	str r3, [sp, #0x10]
	movs r3, #4
	bl MainSprite_SetNumber
	b _08054C62
	.align 2, 0
_08054C54: .4byte 0x000019C8
_08054C58: .4byte 0x00001828
_08054C5C:
	adds r0, r4, #0
	bl BlackPanther_HideScorePopup
_08054C62:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
