	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sb, r0
	mov sl, r1
	mov r8, r2
	str r3, [sp, #0x1c]
	ldr r0, _080E0C74 @ =0x030046A4
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _080E0C48
	b _080E0EBE
_080E0C48:
	mov r2, sl
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sl
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	cmp r2, #0
	blt _080E0C70
	cmp r3, #0
	blt _080E0C70
	ldr r0, _080E0C78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E0C70
	ldr r0, _080E0C7C @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _080E0C80
_080E0C70:
	movs r7, #0
	b _080E0C8A
	.align 2, 0
_080E0C74: .4byte 0x030046A4
_080E0C78: .4byte 0x030046A8
_080E0C7C: .4byte 0x030046AC
_080E0C80:
	lsls r0, r3, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r7, r0, r2
_080E0C8A:
	mov r6, r8
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080E0CB0
	cmp r1, #0
	blt _080E0CB0
	ldr r0, _080E0CB4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E0CB0
	ldr r0, _080E0CB8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E0CBC
_080E0CB0:
	movs r0, #0
	b _080E0CC8
	.align 2, 0
_080E0CB4: .4byte 0x030046A8
_080E0CB8: .4byte 0x030046AC
_080E0CBC:
	ldr r0, [r4]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080E0CC8:
	str r0, [sp, #0x20]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E0CDA
	adds r0, #4
	b _080E0CE6
_080E0CDA:
	ldr r0, _080E0D10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E0CE6:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	str r1, [sp, #0x28]
	lsls r1, r1, #8
	mov r2, r8
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _080E0CFC
	b _080E0EBE
_080E0CFC:
	ldr r4, [sp, #0x20]
	cmp r7, r4
	bne _080E0D14
	mov r6, r8
	ldr r0, [r6]
	ldr r1, [r6, #4]
_080E0D08:
	mov r2, sb
	str r0, [r2]
	str r1, [r2, #4]
	b _080E0FA8
	.align 2, 0
_080E0D10: .4byte 0x030046A4
_080E0D14:
	mov r3, sp
	adds r3, #4
	str r3, [sp, #0x2c]
	ldr r5, _080E0D54 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r1, [r0, r6]
	adds r0, r7, #0
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #4
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E0D58
	adds r0, #4
	b _080E0D62
	.align 2, 0
_080E0D54: .4byte 0x030046A4
_080E0D58:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E0D62:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, [sp, #0x2c]
	strh r0, [r1, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	add r1, sp, #0xc
	add r3, sp, #4
	adds r0, r3, #0
	ldrh r0, [r0]
	mov r2, sl
	ldrh r5, [r2]
	subs r0, r0, r5
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r4, [r2, #2]
	mov ip, r4
	mov r6, ip
	subs r0, r0, r6
	strh r0, [r1, #2]
	ldrh r0, [r3, #4]
	ldrh r4, [r2, #4]
	subs r0, r0, r4
	strh r0, [r1, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r6, #4
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmn r2, r0
	beq _080E0DB4
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	b _080E0D08
_080E0DB4:
	mov r6, r8
	ldrh r0, [r6]
	subs r0, r0, r5
	add r1, sp, #4
	strh r0, [r1]
	ldrh r0, [r6, #2]
	mov r1, ip
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r6, #4]
	subs r0, r0, r4
	strh r0, [r3, #4]
	add r0, sp, #4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r4, #4
	ldrsh r1, [r3, r4]
	bl FUN_0823785c
	str r0, [sp, #0x24]
	add r2, sp, #0x14
	add r3, sp, #0x18
	str r0, [sp]
	adds r0, r7, #0
	ldr r1, [sp, #0x20]
	bl FUN_080e0588
	ldr r4, _080E0E50 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r1, [r0, r6]
	adds r0, r7, #0
	bl Mod
	subs r6, r0, #5
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	adds r4, r0, #0
	subs r4, #8
	ldr r3, [sp, #0x1c]
	cmp r3, #0
	bne _080E0E66
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _080E0E54
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r7, #0
	ldr r3, [sp, #0x28]
	bl FUN_080e0748
	adds r5, r0, #0
	mov sl, r5
	cmp r5, #0
	bge _080E0EC2
	ldr r0, [sp, #0x14]
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r7, #0
	ldr r3, [sp, #0x28]
	bl FUN_080e0884
_080E0E40:
	adds r5, r0, #0
	cmp r5, #0
	bge _080E0EC2
	mov r0, sb
	mov r1, r8
	adds r2, r5, #0
	mov r3, sl
	b _080E0EB2
	.align 2, 0
_080E0E50: .4byte 0x030046A4
_080E0E54:
	ldr r0, [sp, #0x14]
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r7, #0
	ldr r3, [sp, #0x28]
	bl FUN_080e0884
	b _080E0EA4
_080E0E66:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _080E0E94
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r7, #0
	ldr r3, [sp, #0x28]
	bl FUN_080e0884
	adds r5, r0, #0
	mov sl, r5
	cmp r5, #0
	bge _080E0EC2
	ldr r0, [sp, #0x18]
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r7, #0
	ldr r3, [sp, #0x28]
	bl FUN_080e0748
	b _080E0E40
_080E0E94:
	ldr r0, [sp, #0x18]
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r7, #0
	ldr r3, [sp, #0x28]
	bl FUN_080e0748
_080E0EA4:
	adds r5, r0, #0
	cmp r5, #0
	bge _080E0EC2
	mov r0, sb
	mov r1, r8
	adds r2, r5, #0
	adds r3, r5, #0
_080E0EB2:
	bl FUN_080e05f0
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _080E0FA8
_080E0EBE:
	movs r0, #0
	b _080E0FAA
_080E0EC2:
	ldr r4, [sp, #0x20]
	cmp r5, r4
	bne _080E0F4E
	ldr r0, [sp, #0x50]
	cmp r0, #1
	bne _080E0F40
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl FUN_080e09b8
	adds r5, r0, #0
	ldr r6, _080E0F14 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sb
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E0F18
	adds r0, #4
	b _080E0F22
	.align 2, 0
_080E0F14: .4byte 0x030046A4
_080E0F18:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E0F22:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	mov r2, r8
	str r0, [r2]
	str r1, [r2, #4]
	b _080E0FA8
_080E0F40:
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	mov r4, sb
	str r0, [r4]
	str r1, [r4, #4]
	b _080E0FA8
_080E0F4E:
	ldr r6, _080E0F88 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sb
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E0F8C
	adds r0, #4
	b _080E0F96
	.align 2, 0
_080E0F88: .4byte 0x030046A4
_080E0F8C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E0F96:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r2, sb
	strh r1, [r2, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r2, #4]
_080E0FA8:
	movs r0, #1
_080E0FAA:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
