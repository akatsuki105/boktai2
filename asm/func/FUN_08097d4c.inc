	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _08097D94 @ =0x000015C4
	adds r6, r5, r0
	ldr r1, _08097D98 @ =0x000015CC
	adds r4, r5, r1
_08097D5A:
	ldr r1, _08097D9C @ =0x00003FF0
	adds r0, r5, r1
	adds r2, r0, r7
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08097DA0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r6, #0
	movs r1, #1
	bl MainSprite_SetPltt
	b _08097DA8
	.align 2, 0
_08097D94: .4byte 0x000015C4
_08097D98: .4byte 0x000015CC
_08097D9C: .4byte 0x00003FF0
_08097DA0:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_08097DA8:
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _08097D5A
	movs r7, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08097E06
	ldr r0, _08097E2C @ =0x00001EE4
	adds r4, r5, r0
	movs r6, #0xf6
	lsls r6, r6, #4
_08097DC8:
	movs r0, #0x64
	muls r0, r7, r0
	adds r0, r5, r0
	ldr r1, _08097E30 @ =0x00000C09
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r5, #0
	bl FUN_08097d20
	adds r1, r0, #0
	ldr r0, _08097E34 @ =0x00000F6C
	adds r3, r5, r0
	adds r3, r3, r6
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	adds r0, r4, #0
	bl FUN_08097ca0
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #1
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08097DC8
_08097E06:
	cmp r7, #3
	bgt _08097E26
	movs r2, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08097E38 @ =0x00001ECC
	adds r0, r0, r1
	adds r1, r0, r5
_08097E18:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	adds r7, #1
	cmp r7, #3
	ble _08097E18
_08097E26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097E2C: .4byte 0x00001EE4
_08097E30: .4byte 0x00000C09
_08097E34: .4byte 0x00000F6C
_08097E38: .4byte 0x00001ECC
