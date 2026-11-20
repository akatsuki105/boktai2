	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #1
	ldr r1, _08199AD4 @ =0x00000111
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08199AD8
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _08199ADA
	.align 2, 0
_08199AD4: .4byte 0x00000111
_08199AD8:
	movs r0, #0
_08199ADA:
	cmp r0, #0
	bne _08199AE0
	b _08199BEA
_08199AE0:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r4, [r0]
	ldr r1, _08199C0C @ =0x00000C84
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0x81
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r3, _08199C10 @ =0x00000C9C
	adds r1, r4, r3
	ldrb r1, [r1]
	bl Div
	ldr r1, _08199C14 @ =0x00000C9D
	adds r2, r4, r1
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrb r1, [r1]
	muls r0, r1, r0
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r1, _08199C18 @ =0x00000181
	adds r1, r1, r7
	mov sb, r1
	strb r0, [r1]
	ldr r2, _08199C1C @ =gSineTable
	mov r8, r2
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0xc8
	muls r0, r5, r0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	bl Div
	ldr r1, _08199C20 @ =0x00000AFC
	adds r1, r1, r4
	mov sl, r1
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	strh r0, [r7, #0x1e]
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	adds r1, r6, #0
	bl Div
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r4, r4, r1
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0x80
	strb r0, [r7, #6]
	movs r0, #0x7f
	strb r0, [r7, #8]
	movs r3, #1
	strb r3, [r7, #9]
	ldr r2, _08199C24 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08199C28 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08199C2C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r3
	subs r3, #2
	adds r1, r3, #0
	cmp r0, #0
	beq _08199BAA
	movs r1, #1
_08199BAA:
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, sl
	str r1, [r0]
	adds r3, r7, #0
	adds r3, #0x9e
	ldrh r2, [r3]
	ldr r1, _08199C30 @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r2, r7, #0
	adds r2, #0x4e
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _08199C34 @ =EneSword_SlaveAppearBegin
	str r0, [r1]
_08199BEA:
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08199BFC
	adds r0, r7, #0
	bl _call_via_r1
_08199BFC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08199C0C: .4byte 0x00000C84
_08199C10: .4byte 0x00000C9C
_08199C14: .4byte 0x00000C9D
_08199C18: .4byte 0x00000181
_08199C1C: .4byte gSineTable
_08199C20: .4byte 0x00000AFC
_08199C24: .4byte 0x030046B8
_08199C28: .4byte 0x000003FF
_08199C2C: .4byte 0x0203B400
_08199C30: .4byte 0x0000FFFB
_08199C34: .4byte EneSword_SlaveAppearBegin
