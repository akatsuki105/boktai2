	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r3, r0, #0
	adds r5, r1, #0
	movs r1, #2
	ldrsh r0, [r2, r1]
	adds r0, #0xff
	mov sb, r0
	cmp r3, #1
	beq _080E3B6C
	cmp r3, #1
	bgt _080E3B20
	cmp r3, #0
	beq _080E3B2A
	b _080E3C70
_080E3B20:
	cmp r3, #2
	beq _080E3BAC
	cmp r3, #3
	beq _080E3C10
	b _080E3C70
_080E3B2A:
	adds r5, #1
	mov r8, sp
	ldr r6, _080E3B68 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _080E3BE6
	b _080E3BF0
	.align 2, 0
_080E3B68: .4byte 0x030046A4
_080E3B6C:
	ldr r6, _080E3BA8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r5, r5, r1
	mov r7, sp
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _080E3C4A
	b _080E3C54
	.align 2, 0
_080E3BA8: .4byte 0x030046A4
_080E3BAC:
	subs r5, #1
	mov r8, sp
	ldr r6, _080E3BEC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3BF0
_080E3BE6:
	adds r0, #4
	b _080E3BFA
	.align 2, 0
_080E3BEC: .4byte 0x030046A4
_080E3BF0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E3BFA:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r0, r8
	strh r1, [r0, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	mov r1, r8
	strh r0, [r1, #4]
	b _080E3C70
_080E3C10:
	ldr r6, _080E3C50 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r5, r5, r1
	mov r7, sp
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3C54
_080E3C4A:
	adds r0, #4
	b _080E3C5E
	.align 2, 0
_080E3C50: .4byte 0x030046A4
_080E3C54:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E3C5E:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
_080E3C70:
	mov r4, sp
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3C82
	adds r0, #4
	b _080E3C8E
_080E3C82:
	ldr r0, _080E3CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E3C8E:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E3CA8
	cmp r2, #2
	beq _080E3CAC
	b _080E3CB0
	.align 2, 0
_080E3CA4: .4byte 0x030046A4
_080E3CA8:
	ldrb r0, [r4, #4]
	b _080E3CAE
_080E3CAC:
	ldrb r0, [r4]
_080E3CAE:
	subs r1, r1, r0
_080E3CB0:
	cmp r1, sb
	bhi _080E3CB8
	movs r0, #1
	b _080E3CBA
_080E3CB8:
	movs r0, #0
_080E3CBA:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
