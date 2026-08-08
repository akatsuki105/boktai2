	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r4, r2, #0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r5, #0
	blt _080E8B1A
	cmp r1, #0
	blt _080E8B1A
	ldr r0, _080E8B20 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _080E8B1A
	ldr r0, _080E8B24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E8B28
_080E8B1A:
	movs r0, #0
	b _080E8B36
	.align 2, 0
_080E8B20: .4byte 0x030046A8
_080E8B24: .4byte 0x030046AC
_080E8B28:
	ldr r0, _080E8B48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r5
_080E8B36:
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x38]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E8B4C
	adds r0, #4
	b _080E8B5A
	.align 2, 0
_080E8B48: .4byte 0x030046A4
_080E8B4C:
	ldr r0, _080E8B8C @ =0x030046A4
	ldr r1, [r0]
	ldr r2, [sp, #0x38]
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E8B5A:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	ldr r3, [sp, #0x30]
	adds r3, #8
	str r3, [sp, #0x3c]
	cmp r0, #0
	bne _080E8B94
	ldr r1, [sp, #0x30]
	ldr r2, _080E8B90 @ =0x000004A4
	adds r0, r1, r2
	ldr r0, [r0]
	adds r1, r3, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _080E8B94
	ldr r0, [r4]
	ldr r1, [r4, #4]
	ldr r3, [sp, #0x34]
	str r0, [r3]
	str r1, [r3, #4]
	b _080E8F08
	.align 2, 0
_080E8B8C: .4byte 0x030046A4
_080E8B90: .4byte 0x000004A4
_080E8B94:
	add r6, sp, #0x20
	ldr r5, [sp, #0x38]
	adds r5, #1
	ldr r7, _080E8BD8 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	adds r2, r5, #0
	cmp r0, #0
	beq _080E8BDC
	adds r0, #4
	b _080E8BE6
	.align 2, 0
_080E8BD8: .4byte 0x030046A4
_080E8BDC:
	ldr r0, [r7]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E8BE6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	add r5, sp, #0x28
	add r0, sp, #0x20
	ldrh r0, [r0]
	ldr r3, [sp, #0x30]
	ldrh r1, [r3, #8]
	subs r0, r0, r1
	strh r0, [r5]
	mov r1, sl
	ldrh r0, [r1, #2]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	mov r1, sl
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp]
	str r2, [sp, #4]
	ldr r7, _080E8C74 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	ldr r3, [sp, #0x38]
	adds r6, r3, r1
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r3, sl
	strh r4, [r3]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	mov r8, r5
	cmp r0, #0
	beq _080E8C78
	adds r0, #4
	b _080E8C82
	.align 2, 0
_080E8C74: .4byte 0x030046A4
_080E8C78:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E8C82:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sp
	strh r0, [r1, #0x22]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #0x24]
	add r0, sp, #0x20
	ldrh r0, [r0]
	ldr r3, [sp, #0x30]
	ldrh r1, [r3, #8]
	subs r0, r0, r1
	add r2, sp, #0x28
	strh r0, [r2]
	mov r1, sl
	ldrh r0, [r1, #2]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	mov r3, sl
	ldrh r0, [r3, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	str r1, [sp, #8]
	ldr r6, _080E8D24 @ =0x030046A4
	ldr r0, [r6]
	ldr r1, [r0, #4]
	movs r3, #4
	ldrsh r0, [r1, r3]
	ldr r2, [sp, #0x38]
	adds r0, r2, r0
	str r0, [sp, #0xc]
	mov sb, sl
	adds r5, r2, #0
	subs r5, #1
	movs r3, #4
	ldrsh r1, [r1, r3]
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
	mov r3, sl
	strh r4, [r3]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E8D28
	adds r0, #4
	b _080E8D32
	.align 2, 0
_080E8D24: .4byte 0x030046A4
_080E8D28:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E8D32:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	add r0, sp, #0x20
	ldrh r0, [r0]
	ldr r2, [sp, #0x30]
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	add r2, sp, #0x28
	strh r0, [r2]
	mov r3, sl
	ldrh r0, [r3, #2]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	mov r3, sl
	ldrh r0, [r3, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	str r1, [sp, #0x10]
	str r5, [sp, #0x14]
	ldr r6, _080E8DC8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	ldr r0, [sp, #0x38]
	subs r5, r0, r1
	mov sb, sl
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
	mov r3, sl
	strh r4, [r3]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E8DD8
	adds r0, #4
	b _080E8DE2
	.align 2, 0
_080E8DC8: .4byte 0x030046A4
_080E8DCC:
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	ldr r2, [sp, #0x34]
	str r0, [r2]
	str r1, [r2, #4]
	b _080E8F08
_080E8DD8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E8DE2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	add r0, sp, #0x20
	ldrh r0, [r0]
	ldr r2, [sp, #0x30]
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	add r2, sp, #0x28
	strh r0, [r2]
	mov r3, sl
	ldrh r0, [r3, #2]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	mov r3, sl
	ldrh r0, [r3, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	str r1, [sp, #0x18]
	ldr r0, _080E8E64 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x38]
	subs r0, r1, r0
	str r0, [sp, #0x1c]
	mov r0, sp
	movs r1, #4
	bl FUN_080e8aa0
	add r7, sp, #4
_080E8E50:
	ldr r4, [r7]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E8E68
	adds r0, #4
	b _080E8E74
	.align 2, 0
_080E8E64: .4byte 0x030046A4
_080E8E68:
	ldr r0, _080E8EBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E8E74:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _080E8EF4
	mov sb, sl
	ldr r5, [r7]
	ldr r6, _080E8EBC @ =0x030046A4
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
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x20
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E8EC0
	adds r0, #4
	b _080E8ECA
	.align 2, 0
_080E8EBC: .4byte 0x030046A4
_080E8EC0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E8ECA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r3, [sp, #0x30]
	ldr r1, _080E8F18 @ =0x000004A4
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x3c]
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	beq _080E8EF4
	b _080E8DCC
_080E8EF4:
	adds r7, #8
	add r0, sp, #0x1c
	cmp r7, r0
	ble _080E8E50
	movs r1, #0
	ldr r0, _080E8F1C @ =0x00007530
	ldr r2, [sp, #0x34]
	strh r0, [r2]
	strh r1, [r2, #2]
	strh r0, [r2, #4]
_080E8F08:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E8F18: .4byte 0x000004A4
_080E8F1C: .4byte 0x00007530
