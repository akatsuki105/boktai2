	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081A7988 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A798C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A798E
	.align 2, 0
_081A7988: .4byte 0x0000046D
_081A798C:
	movs r0, #0
_081A798E:
	cmp r0, #0
	beq _081A799A
	ldr r3, _081A79B0 @ =0x00000C45
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
_081A799A:
	ldr r1, _081A79B0 @ =0x00000C45
	adds r0, r7, r1
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081A79B4
	ldrb r3, [r6, #5]
	b _081A79BE
	.align 2, 0
_081A79B0: .4byte 0x00000C45
_081A79B4:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_081A79BE:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _081A79E0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A79E4
	asrs r1, r0, #0xc
	b _081A79EA
	.align 2, 0
_081A79E0: .4byte gSineTable
_081A79E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A79EA:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A7A02
	asrs r2, r0, #0xc
	b _081A7A08
_081A7A02:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A7A08:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r3, _081A7A4C @ =0x00000C45
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #4]
	mov r8, r0
	ldr r1, _081A7A50 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _081A7A2C
	b _081A7BCC
_081A7A2C:
	movs r3, #0xd0
	mov sl, r3
_081A7A30:
	mov r1, sl
	mov r0, r8
	muls r0, r1, r0
	adds r0, r0, r7
	movs r1, #2
	ldr r2, _081A7A54 @ =0x00000705
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A7A58
	movs r0, #1
	b _081A7A5A
	.align 2, 0
_081A7A4C: .4byte 0x00000C45
_081A7A50: .4byte 0x00000CAA
_081A7A54: .4byte 0x00000705
_081A7A58:
	movs r0, #0
_081A7A5A:
	movs r3, #1
	add r3, r8
	mov sb, r3
	cmp r0, #0
	bne _081A7A66
	b _081A7BBC
_081A7A66:
	mov r1, sl
	mov r0, r8
	muls r0, r1, r0
	adds r0, r0, r7
	movs r1, #5
	ldr r2, _081A7A80 @ =0x00000705
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A7A84
	movs r0, #1
	b _081A7A86
	.align 2, 0
_081A7A80: .4byte 0x00000705
_081A7A84:
	movs r0, #0
_081A7A86:
	adds r5, r0, #0
	movs r3, #1
	add r3, r8
	mov sb, r3
	cmp r5, #0
	beq _081A7A94
	b _081A7BBC
_081A7A94:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sb
	bl Div
	mov r2, sl
	mov r1, r8
	muls r1, r2, r1
	adds r4, r7, r1
	ldr r3, _081A7AE0 @ =0x0000071C
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, _081A7AE4 @ =0x0000071E
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0x14
	ldrsh r0, [r6, r2]
	mov r1, sb
	bl Div
	movs r3, #0xe4
	lsls r3, r3, #3
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _081A7AEC
	cmp r0, #1
	beq _081A7B40
	ldrh r1, [r6, #8]
	ldr r2, _081A7AE8 @ =0x00000674
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	subs r3, #0xa8
	adds r0, r4, r3
	strh r1, [r0]
	b _081A7BB6
	.align 2, 0
_081A7AE0: .4byte 0x0000071C
_081A7AE4: .4byte 0x0000071E
_081A7AE8: .4byte 0x00000674
_081A7AEC:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081A7B0C @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _081A7B0C @ =gSineTable
	cmp r0, #0
	blt _081A7B10
	asrs r3, r0, #0xc
	b _081A7B16
	.align 2, 0
_081A7B0C: .4byte gSineTable
_081A7B10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081A7B16:
	mov r0, sl
	mov r1, r8
	muls r1, r0, r1
	adds r1, r7, r1
	ldrh r0, [r6, #8]
	subs r0, r0, r3
	ldr r3, _081A7B3C @ =0x00000674
	adds r1, r1, r3
	strh r0, [r1]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _081A7B94
	b _081A7B9C
	.align 2, 0
_081A7B3C: .4byte 0x00000674
_081A7B40:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _081A7B64 @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _081A7B68
	asrs r3, r0, #0xc
	b _081A7B6E
	.align 2, 0
_081A7B64: .4byte gSineTable
_081A7B68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081A7B6E:
	mov r0, sl
	mov r1, r8
	muls r1, r0, r1
	adds r1, r7, r1
	ldrh r0, [r6, #8]
	subs r0, r0, r3
	ldr r3, _081A7B98 @ =0x00000674
	adds r1, r1, r3
	strh r0, [r1]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081A7B9C
_081A7B94:
	asrs r2, r0, #0xc
	b _081A7BA2
	.align 2, 0
_081A7B98: .4byte 0x00000674
_081A7B9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A7BA2:
	mov r3, sl
	mov r1, r8
	muls r1, r3, r1
	adds r1, r7, r1
	ldrh r0, [r6, #0xc]
	subs r0, r0, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r1, r1, r2
	strh r0, [r1]
_081A7BB6:
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_081A7BBC:
	mov r8, sb
	ldr r1, _081A7C18 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	bge _081A7BCC
	b _081A7A30
_081A7BCC:
	ldr r3, _081A7C1C @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	movs r2, #0xc
	bl Salamander_PullSegments
	ldr r3, [sp]
	cmp r3, #0x3c
	ble _081A7C08
	ldr r4, _081A7C20 @ =Salamander_StatePounce
	movs r3, #0x23
	ldr r0, _081A7C24 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A7C28 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_081A7C08:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A7C18: .4byte 0x00000CAA
_081A7C1C: .4byte 0x0000FFFF
_081A7C20: .4byte Salamander_StatePounce
_081A7C24: .4byte 0x0000046D
_081A7C28: .4byte 0x0000046B
