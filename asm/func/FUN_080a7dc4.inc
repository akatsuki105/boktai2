	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	bl FUN_080a7b80
	adds r0, r7, #0
	adds r0, #0x20
	bl FUN_08236400
	ldr r0, _080A7E28 @ =0x00000206
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080A7DF2
	b _080A7F2A
_080A7DF2:
	adds r0, r7, #0
	adds r0, #0x8a
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r5, r7, #0
	adds r5, #0x18
	ldrh r0, [r7, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A7E22
	cmp r1, #0
	blt _080A7E22
	ldr r0, _080A7E2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A7E22
	ldr r0, _080A7E30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A7E34
_080A7E22:
	movs r4, #0
	b _080A7E42
	.align 2, 0
_080A7E28: .4byte 0x00000206
_080A7E2C: .4byte 0x030046A8
_080A7E30: .4byte 0x030046AC
_080A7E34:
	ldr r0, _080A7E54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A7E42:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A7E58
	adds r0, #4
	b _080A7E64
	.align 2, 0
_080A7E54: .4byte 0x030046A4
_080A7E58:
	ldr r0, _080A7E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A7E64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A7E7C
	cmp r2, #2
	beq _080A7E80
	b _080A7E84
	.align 2, 0
_080A7E78: .4byte 0x030046A4
_080A7E7C:
	ldrb r0, [r5, #4]
	b _080A7E82
_080A7E80:
	ldrb r0, [r5]
_080A7E82:
	subs r1, r1, r0
_080A7E84:
	cmp r6, r1
	bls _080A7F24
	ldr r6, _080A7F3C @ =0x0203B400
	ldr r0, _080A7F40 @ =0x030046B8
	mov sl, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _080A7F44 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080A7F48 @ =0xFFFF0000
	ldr r3, [sp, #0xc]
	ands r3, r5
	orrs r3, r0
	str r3, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	ldr r0, _080A7F4C @ =0x0000FFFF
	mov r8, r0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	mov r1, sl
	str r2, [r1]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r0, [r2]
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r5
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x88
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #4
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
_080A7F24:
	adds r0, r7, #0
	bl KillEntity
_080A7F2A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7F3C: .4byte 0x0203B400
_080A7F40: .4byte 0x030046B8
_080A7F44: .4byte 0x000003FF
_080A7F48: .4byte 0xFFFF0000
_080A7F4C: .4byte 0x0000FFFF
