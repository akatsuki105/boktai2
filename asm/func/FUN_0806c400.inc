	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806C424
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
	ldr r2, _0806C464 @ =0x00000385
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0806C424:
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	ldr r3, _0806C464 @ =0x00000385
	adds r4, r5, r3
	ldrb r0, [r4]
	adds r6, r0, #0
	cmp r6, #0
	beq _0806C43C
	b _0806C5CC
_0806C43C:
	adds r0, r5, #0
	bl FUN_08067068
	adds r3, r0, #0
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0806C500
	cmp r3, #4
	ble _0806C470
	movs r0, #8
	subs r0, r0, r3
	asrs r0, r0, #1
	ldr r4, _0806C468 @ =0x000002E6
	adds r1, r5, r4
	strb r0, [r1]
	ldr r1, _0806C46C @ =0x000002E7
	adds r0, r5, r1
	strb r2, [r0]
	b _0806C47E
	.align 2, 0
_0806C464: .4byte 0x00000385
_0806C468: .4byte 0x000002E6
_0806C46C: .4byte 0x000002E7
_0806C470:
	asrs r0, r3, #1
	ldr r2, _0806C4AC @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r4, _0806C4B0 @ =0x000002E7
	adds r0, r5, r4
	strb r6, [r0]
_0806C47E:
	ldr r2, _0806C4B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806C4B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806C4BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	cmp r1, #5
	bgt _0806C4C4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _0806C4C0 @ =0x00000385
	adds r1, r5, r3
	movs r0, #9
	strb r0, [r1]
	b _0806C5D0
	.align 2, 0
_0806C4AC: .4byte 0x000002E6
_0806C4B0: .4byte 0x000002E7
_0806C4B4: .4byte 0x030046B8
_0806C4B8: .4byte 0x000003FF
_0806C4BC: .4byte 0x0203B400
_0806C4C0: .4byte 0x00000385
_0806C4C4:
	cmp r1, #6
	bgt _0806C4E0
	adds r0, r3, #7
	movs r1, #7
	ands r0, r1
	movs r4, #0xba
	lsls r4, r4, #2
	adds r1, r5, r4
	strb r0, [r1]
	ldr r0, _0806C4DC @ =0x00000385
	adds r1, r5, r0
	b _0806C4F4
	.align 2, 0
_0806C4DC: .4byte 0x00000385
_0806C4E0:
	adds r0, r3, #0
	adds r0, #9
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806C4FC @ =0x00000385
	adds r1, r5, r3
_0806C4F4:
	movs r0, #3
	strb r0, [r1]
	b _0806C5D0
	.align 2, 0
_0806C4FC: .4byte 0x00000385
_0806C500:
	ldr r2, _0806C528 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806C52C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806C530 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	cmp r1, #5
	bgt _0806C534
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r3, [r0]
	movs r0, #9
	b _0806C54E
	.align 2, 0
_0806C528: .4byte 0x030046B8
_0806C52C: .4byte 0x000003FF
_0806C530: .4byte 0x0203B400
_0806C534:
	cmp r1, #6
	bgt _0806C53C
	adds r0, r3, #7
	b _0806C540
_0806C53C:
	adds r0, r3, #0
	adds r0, #9
_0806C540:
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #3
_0806C54E:
	strb r0, [r4]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r3, r5, r4
	ldrb r1, [r3]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0806C58C
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806C584 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806C588 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r1, [r3]
	ands r0, r4
	lsls r0, r0, #1
	adds r0, #7
	adds r3, r1, r0
	movs r0, #7
	ands r3, r0
	b _0806C58E
	.align 2, 0
_0806C584: .4byte 0x000003FF
_0806C588: .4byte 0x0203B400
_0806C58C:
	ldrb r3, [r3]
_0806C58E:
	cmp r3, #4
	ble _0806C5B0
	movs r0, #8
	subs r0, r0, r3
	asrs r0, r0, #1
	ldr r2, _0806C5A8 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806C5AC @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0806C5D0
	.align 2, 0
_0806C5A8: .4byte 0x000002E6
_0806C5AC: .4byte 0x000002E7
_0806C5B0:
	asrs r1, r3, #1
	ldr r4, _0806C5C4 @ =0x000002E6
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0806C5C8 @ =0x000002E7
	adds r0, r5, r1
	strb r2, [r0]
	b _0806C5D0
	.align 2, 0
_0806C5C4: .4byte 0x000002E6
_0806C5C8: .4byte 0x000002E7
_0806C5CC:
	subs r0, #1
	strb r0, [r4]
_0806C5D0:
	adds r0, r5, #0
	movs r1, #9
	bl FUN_08060aa4
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C62A
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C632
_0806C62A:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C632:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C656
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C65E
_0806C656:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C65E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806C694 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C6CC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C698
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C68E
	ldrb r0, [r4, #5]
_0806C68E:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C6A8
	.align 2, 0
_0806C694: .4byte 0x0000FFFF
_0806C698:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C6A8
	strh r1, [r4, #8]
_0806C6A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C6CC
	movs r0, #1
	strb r0, [r4, #7]
_0806C6CC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
