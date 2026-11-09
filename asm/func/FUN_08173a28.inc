	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08173A40 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173A44
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173A46
	.align 2, 0
_08173A40: .4byte 0x0000046C
_08173A44:
	movs r0, #0
_08173A46:
	cmp r0, #0
	beq _08173AEC
	ldr r1, _08173A9C @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08173AA0 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08173AA4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08173AA8 @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r4, [r5, #5]
	ldr r2, _08173AAC @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08173AB0
	asrs r1, r0, #0xc
	b _08173AB6
	.align 2, 0
_08173A9C: .4byte 0x000005A4
_08173AA0: .4byte 0x0000046D
_08173AA4: .4byte 0x0000046B
_08173AA8: .4byte 0x00000553
_08173AAC: .4byte gSineTable
_08173AB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08173AB6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _08173AD0
	asrs r2, r0, #0xc
	b _08173AD6
_08173AD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173AD6:
	movs r0, #0
	strh r2, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_08173AEC:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08173B74
	adds r0, r5, #0
	bl FUN_08175898
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08173B64 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08173B68 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08173B6C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08173B70 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _08173B7E
	.align 2, 0
_08173B64: .4byte 0x0000046D
_08173B68: .4byte 0x0000046B
_08173B6C: .4byte 0x0000046A
_08173B70: .4byte 0x00000484
_08173B74:
	ldr r0, _08173B84 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08173B7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08173B84: .4byte 0x00000484
