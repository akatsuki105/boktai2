	push {r4, r5, r6, lr}
	sub sp, #0x1c
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080E15D8 @ =0x030047A4
	ldr r1, _080E15DC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _080E1566
	b _080E16D2
_080E1566:
	ldr r0, _080E15E0 @ =0x03000180
	ldr r0, [r0]
	cmp r0, #0
	bne _080E1570
	b _080E16D2
_080E1570:
	bl FUN_080e138c
	adds r5, r0, #0
	cmp r5, #0
	bne _080E157C
	b _080E16D2
_080E157C:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080E1598
	bl Script_GetValue
	strh r0, [r5]
	bl Script_GetValue
	strh r0, [r5, #2]
	bl Script_GetValue
	strh r0, [r5, #4]
_080E1598:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080E15B4
	bl Script_GetValue
	strh r0, [r5, #8]
	bl Script_GetValue
	strh r0, [r5, #0xa]
	bl Script_GetValue
	strh r0, [r5, #0xc]
_080E15B4:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080E1602
	bl Script_GetValue
	strb r0, [r5, #0x19]
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	subs r3, r0, r4
	cmp r3, #0
	bne _080E15E4
	strh r3, [r5, #0x10]
	b _080E1602
	.align 2, 0
_080E15D8: .4byte 0x030047A4
_080E15DC: .4byte 0x030047A0
_080E15E0: .4byte 0x03000180
_080E15E4:
	ldr r2, _080E164C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080E1650 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080E1654 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
	adds r0, r4, r0
	strh r0, [r5, #0x10]
_080E1602:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x14]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #0x18]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0x12]
	strh r4, [r5, #0x16]
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _080E1634
	movs r0, #1
	strh r0, [r5, #0x16]
_080E1634:
	movs r3, #0x12
	ldrsh r2, [r5, r3]
	ldr r0, _080E1658 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080E165C
	adds r4, r2, #0
	b _080E1676
	.align 2, 0
_080E164C: .4byte 0x030046B8
_080E1650: .4byte 0x000003FF
_080E1654: .4byte 0x0203B400
_080E1658: .4byte 0x030047A4
_080E165C:
	ldr r0, _080E16DC @ =0x030046A0
	ldr r0, [r0]
	ldr r6, _080E16E0 @ =0x00000942
	adds r0, r0, r6
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa
	subs r0, r0, r1
	muls r0, r2, r0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
_080E1676:
	movs r6, #0x10
	ldrsh r2, [r5, r6]
	ldr r0, _080E16E4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080E16A2
	ldr r0, _080E16DC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080E16E0 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa
	subs r0, r0, r1
	muls r0, r2, r0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
_080E16A2:
	ldrh r1, [r5, #0x14]
	ldrb r3, [r5, #0x18]
	ldrb r0, [r5, #0x19]
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	movs r6, #8
	ldrsh r0, [r5, r6]
	str r0, [sp, #8]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #0xc]
	movs r6, #0xc
	ldrsh r0, [r5, r6]
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	ldrh r0, [r5, #0x16]
	str r0, [sp, #0x18]
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_081ead54
	str r0, [r5, #0x1c]
_080E16D2:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E16DC: .4byte 0x030046A0
_080E16E0: .4byte 0x00000942
_080E16E4: .4byte 0x030047A4
