	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080C1B74 @ =0x0000021E
	adds r6, r7, r0
	ldrh r0, [r6]
	cmp r0, #0x1d
	bhi _080C1B7C
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C1B78 @ =0x0000FFE2
	b _080C1CDE
	.align 2, 0
_080C1B74: .4byte 0x0000021E
_080C1B78: .4byte 0x0000FFE2
_080C1B7C:
	cmp r0, #0x2c
	bhi _080C1BA4
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	ldrh r0, [r6]
	lsls r0, r0, #1
	subs r0, #0x5a
	adds r3, r7, #0
	adds r3, #0xba
	strh r0, [r3]
	b _080C1CE0
_080C1BA4:
	cmp r0, #0x31
	bhi _080C1BF4
	ldr r0, _080C1BE8 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1BEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1BF0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r2, [r6]
	movs r1, #0x2d
	subs r1, r1, r2
	b _080C1C34
	.align 2, 0
_080C1BE8: .4byte 0x0203B400
_080C1BEC: .4byte 0x030046B8
_080C1BF0: .4byte 0x000003FF
_080C1BF4:
	cmp r0, #0x36
	bhi _080C1C50
	ldr r0, _080C1C44 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C48 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C4C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x37
_080C1C34:
	lsls r1, r1, #1
	adds r1, r1, r0
	subs r1, #2
	adds r3, r7, #0
	adds r3, #0xba
	strh r1, [r3]
	b _080C1D56
	.align 2, 0
_080C1C44: .4byte 0x0203B400
_080C1C48: .4byte 0x030046B8
_080C1C4C: .4byte 0x000003FF
_080C1C50:
	cmp r0, #0x3b
	bhi _080C1C9C
	ldr r0, _080C1C90 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C94 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C98 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	subs r0, #2
	b _080C1CDA
	.align 2, 0
_080C1C90: .4byte 0x0203B400
_080C1C94: .4byte 0x030046B8
_080C1C98: .4byte 0x000003FF
_080C1C9C:
	cmp r0, #0x4f
	bhi _080C1CFC
	ldr r0, _080C1CF0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1CF4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1CF8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r0, #0x3b
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	subs r0, #1
_080C1CDA:
	adds r1, r7, #0
	adds r1, #0xba
_080C1CDE:
	strh r0, [r1]
_080C1CE0:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080C1D56
	.align 2, 0
_080C1CF0: .4byte 0x0203B400
_080C1CF4: .4byte 0x030046B8
_080C1CF8: .4byte 0x000003FF
_080C1CFC:
	cmp r0, #0x59
	bhi _080C1D10
	adds r0, r7, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	b _080C1D56
_080C1D10:
	ldrh r0, [r6]
	movs r1, #0x2d
	bl Div
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C1D3C
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _080C1D56
_080C1D3C:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080C1D56:
	ldr r0, _080C1D6C @ =0x0000021E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1D6C: .4byte 0x0000021E
