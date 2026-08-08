	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r1, #0x20
	asrs r4, r1, #6
	movs r0, #3
	ands r4, r0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E09DC
	adds r0, #4
	b _080E09E8
_080E09DC:
	ldr r0, _080E0A08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E09E8:
	ldrb r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r3, sb
	ands r3, r0
	mov sb, r3
	adds r6, r5, #0
	movs r2, #0
	cmp r4, #1
	beq _080E0A8E
	cmp r4, #1
	bgt _080E0A0C
	cmp r4, #0
	beq _080E0A1E
	b _080E0C18
	.align 2, 0
_080E0A08: .4byte 0x030046A4
_080E0A0C:
	cmp r4, #2
	bne _080E0A12
	b _080E0B18
_080E0A12:
	cmp r4, #3
	bne _080E0A18
	b _080E0B86
_080E0A18:
	b _080E0C18
_080E0A1A:
	adds r0, r2, #0
	b _080E0C1A
_080E0A1E:
	ldr r0, _080E0A40 @ =0x030046A4
	mov r8, r0
	lsls r0, r5, #2
	adds r7, r0, #0
	adds r7, #0x10
_080E0A28:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0A44
	adds r0, #4
	b _080E0A4C
	.align 2, 0
_080E0A40: .4byte 0x030046A4
_080E0A44:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r7
_080E0A4C:
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0A66
	adds r0, #4
	b _080E0A6E
_080E0A66:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r7
_080E0A6E:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080E0A7A
	b _080E0BE6
_080E0A7A:
	cmp r5, sb
	beq _080E0A86
	cmp r2, #0
	bne _080E0A1A
	adds r2, r6, #0
	b _080E0A88
_080E0A86:
	adds r2, r4, #0
_080E0A88:
	adds r7, #4
	adds r6, #1
	b _080E0A28
_080E0A8E:
	ldr r5, _080E0AB0 @ =0x030046A4
_080E0A90:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0AB4
	adds r0, #4
	b _080E0ABE
	.align 2, 0
_080E0AB0: .4byte 0x030046A4
_080E0AB4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E0ABE:
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0AD8
	adds r0, #4
	b _080E0AE4
_080E0AD8:
	ldr r0, _080E0AFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E0AE4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080E0AF0
	b _080E0BE6
_080E0AF0:
	cmp r5, sb
	beq _080E0B00
	cmp r2, #0
	bne _080E0A1A
	adds r2, r6, #0
	b _080E0B02
	.align 2, 0
_080E0AFC: .4byte 0x030046A4
_080E0B00:
	adds r2, r4, #0
_080E0B02:
	ldr r1, _080E0B14 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r6, r6, r0
	adds r5, r1, #0
	b _080E0A90
	.align 2, 0
_080E0B14: .4byte 0x030046A4
_080E0B18:
	ldr r0, _080E0B38 @ =0x030046A4
	mov r8, r0
	lsls r0, r6, #2
	adds r7, r0, #0
	adds r7, #8
_080E0B22:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0B3C
	adds r0, #4
	b _080E0B44
	.align 2, 0
_080E0B38: .4byte 0x030046A4
_080E0B3C:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r7
_080E0B44:
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0B5E
	adds r0, #4
	b _080E0B66
_080E0B5E:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r7
_080E0B66:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080E0BE6
	cmp r5, sb
	beq _080E0B7E
	cmp r2, #0
	beq _080E0B7A
	b _080E0A1A
_080E0B7A:
	adds r2, r6, #0
	b _080E0B80
_080E0B7E:
	adds r2, r4, #0
_080E0B80:
	subs r7, #4
	subs r6, #1
	b _080E0B22
_080E0B86:
	ldr r5, _080E0BA8 @ =0x030046A4
_080E0B88:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0BAC
	adds r0, #4
	b _080E0BB6
	.align 2, 0
_080E0BA8: .4byte 0x030046A4
_080E0BAC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E0BB6:
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r0, r4, #0
	movs r1, #1
	str r2, [sp]
	bl FUN_08234224
	ldr r2, [sp]
	cmp r0, #0
	beq _080E0BD0
	adds r0, #4
	b _080E0BDC
_080E0BD0:
	ldr r0, _080E0BF0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E0BDC:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080E0BF4
_080E0BE6:
	cmp r2, #0
	beq _080E0BEC
	b _080E0A1A
_080E0BEC:
	adds r0, r6, #0
	b _080E0C1A
	.align 2, 0
_080E0BF0: .4byte 0x030046A4
_080E0BF4:
	cmp r5, sb
	beq _080E0C02
	cmp r2, #0
	beq _080E0BFE
	b _080E0A1A
_080E0BFE:
	adds r2, r6, #0
	b _080E0C04
_080E0C02:
	adds r2, r4, #0
_080E0C04:
	ldr r1, _080E0C14 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r6, r6, r0
	adds r5, r1, #0
	b _080E0B88
	.align 2, 0
_080E0C14: .4byte 0x030046A4
_080E0C18:
	adds r0, r5, #0
_080E0C1A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
