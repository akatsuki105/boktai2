	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	adds r4, r1, #0
	mov sl, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _08246392
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0xd4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r4, r0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r5, #0
	ldrsh r0, [r2, r5]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #9]
	movs r3, #0
	movs r0, #0x70
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x79
	adds r1, r1, r4
	mov ip, r1
	ldr r7, _082463AC @ =0x0203B400
	ldr r5, _082463B0 @ =0x030046B8
	ldr r6, _082463B4 @ =0x000003FF
_08246354:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r1, r8
	adds r2, r1, r3
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0xf0
	ldrb r1, [r4, #9]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	mov r0, ip
	adds r2, r0, r3
	movs r0, #0xf
	ands r1, r0
	adds r1, #0x18
	strb r1, [r2]
	adds r3, #1
	cmp r3, #8
	ble _08246354
_08246392:
	adds r0, r4, #0
	bl FUN_08245f2c
	ldrh r0, [r4, #6]
	cmp r0, #0x1d
	bls _082463B8
	mov r0, sb
	adds r1, r4, #0
	mov r2, sl
	bl FUN_08245e68
	b _082463BC
	.align 2, 0
_082463AC: .4byte 0x0203B400
_082463B0: .4byte 0x030046B8
_082463B4: .4byte 0x000003FF
_082463B8:
	adds r0, #1
	strh r0, [r4, #6]
_082463BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
