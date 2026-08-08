	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #8]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	movs r1, #3
	ands r0, r1
	adds r4, r0, #2
	ands r4, r1
	movs r6, #0
	b _080E7B94
_080E7B8C:
	mov r0, sb
	cmp r0, #3
	ble _080E7B94
	b _080E7E68
_080E7B94:
	ldr r1, [sp, #8]
	ldr r2, _080E7BB0 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7BB8
	adds r0, #4
	ldr r7, _080E7BB4 @ =0x030046A4
	b _080E7BC8
	.align 2, 0
_080E7BB0: .4byte 0x00000256
_080E7BB4: .4byte 0x030046A4
_080E7BB8:
	ldr r2, _080E7C04 @ =0x030046A4
	ldr r1, [r2]
	ldr r3, [sp, #0xc]
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r7, r2, #0
_080E7BC8:
	ldrb r0, [r0]
	movs r1, #0xf
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	muls r3, r0, r3
	mov sl, r3
	cmp r4, #1
	beq _080E7CB2
	cmp r4, #1
	bgt _080E7C08
	cmp r4, #0
	beq _080E7C24
	adds r4, #1
	str r4, [sp, #0x10]
	adds r6, #1
	mov sb, r6
	ldr r0, [sp, #8]
	adds r0, #8
	str r0, [sp, #0x14]
	b _080E7E50
	.align 2, 0
_080E7C04: .4byte 0x030046A4
_080E7C08:
	cmp r4, #2
	bne _080E7C0E
	b _080E7D2E
_080E7C0E:
	cmp r4, #3
	bne _080E7C14
	b _080E7DD8
_080E7C14:
	adds r4, #1
	str r4, [sp, #0x10]
	adds r6, #1
	mov sb, r6
	ldr r1, [sp, #8]
	adds r1, #8
	str r1, [sp, #0x14]
	b _080E7E50
_080E7C24:
	ldr r4, [sp, #0xc]
	adds r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	movs r3, #1
	str r3, [sp, #0x10]
	adds r6, #1
	mov sb, r6
	ldr r1, [sp, #8]
	adds r1, #8
	str r1, [sp, #0x14]
	cmp r5, r0
	blt _080E7C4C
	b _080E7E50
_080E7C4C:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_080E7C52:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7C62
	adds r0, #4
	b _080E7C68
_080E7C62:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080E7C68:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E7C92
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7C82
	adds r0, #4
	b _080E7C88
_080E7C82:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080E7C88:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080E7C96
_080E7C92:
	movs r0, #0
	b _080E7C98
_080E7C96:
	movs r0, #1
_080E7C98:
	cmp r0, #0
	bne _080E7C9E
	b _080E7DAA
_080E7C9E:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r5, r0
	blt _080E7C52
	b _080E7E50
_080E7CB2:
	ldr r3, [sp, #0xc]
	adds r4, r3, r1
	movs r0, #2
	str r0, [sp, #0x10]
	adds r6, #1
	mov sb, r6
	ldr r1, [sp, #8]
	adds r1, #8
	str r1, [sp, #0x14]
	cmp sl, r4
	bgt _080E7CCA
	b _080E7E50
_080E7CCA:
	adds r5, r7, #0
_080E7CCC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7CDC
	adds r0, #4
	b _080E7CE6
_080E7CDC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E7CE6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E7D14
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7D00
	adds r0, #4
	b _080E7D0A
_080E7D00:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E7D0A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080E7D18
_080E7D14:
	movs r0, #0
	b _080E7D1A
_080E7D18:
	movs r0, #1
_080E7D1A:
	cmp r0, #0
	beq _080E7DAE
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	cmp sl, r4
	bgt _080E7CCC
	b _080E7E50
_080E7D2E:
	ldr r4, [sp, #0xc]
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	movs r3, #3
	str r3, [sp, #0x10]
	adds r6, #1
	mov sb, r6
	ldr r0, [sp, #8]
	adds r0, #8
	str r0, [sp, #0x14]
	cmp r5, #0
	bge _080E7D4E
	b _080E7E50
_080E7D4E:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_080E7D54:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7D64
	adds r0, #4
	b _080E7D6A
_080E7D64:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080E7D6A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E7D94
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7D84
	adds r0, #4
	b _080E7D8A
_080E7D84:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080E7D8A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080E7D98
_080E7D94:
	movs r0, #0
	b _080E7D9A
_080E7D98:
	movs r0, #1
_080E7D9A:
	cmp r0, #0
	beq _080E7DC0
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _080E7D54
	b _080E7E50
_080E7DAA:
	subs r5, r4, #1
	b _080E7E52
_080E7DAE:
	ldr r0, _080E7DBC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _080E7E52
	.align 2, 0
_080E7DBC: .4byte 0x030046A4
_080E7DC0:
	adds r5, r4, #1
	b _080E7E52
_080E7DC4:
	ldr r0, _080E7DD4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _080E7E52
	.align 2, 0
_080E7DD4: .4byte 0x030046A4
_080E7DD8:
	ldr r3, [sp, #0xc]
	subs r4, r3, r1
	movs r0, #4
	str r0, [sp, #0x10]
	adds r6, #1
	mov sb, r6
	ldr r1, [sp, #8]
	adds r1, #8
	str r1, [sp, #0x14]
	cmp r4, #0
	blt _080E7E50
	adds r5, r7, #0
_080E7DF0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7E00
	adds r0, #4
	b _080E7E0A
_080E7E00:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E7E0A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E7E38
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7E24
	adds r0, #4
	b _080E7E2E
_080E7E24:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E7E2E:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080E7E3C
_080E7E38:
	movs r0, #0
	b _080E7E3E
_080E7E3C:
	movs r0, #1
_080E7E3E:
	cmp r0, #0
	beq _080E7DC4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	cmp r4, #0
	bge _080E7DF0
_080E7E50:
	ldr r5, [sp, #0xc]
_080E7E52:
	movs r4, #3
	ldr r3, [sp, #0x10]
	ands r4, r3
	mov r6, sb
	ldr r1, [sp, #8]
	ldr r2, _080E7EA4 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r5, r0
	bne _080E7E68
	b _080E7B8C
_080E7E68:
	mov r8, sp
	ldr r6, _080E7EA8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
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
	beq _080E7EAC
	adds r0, #4
	b _080E7EB6
	.align 2, 0
_080E7EA4: .4byte 0x00000256
_080E7EA8: .4byte 0x030046A4
_080E7EAC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E7EB6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, r8
	strh r0, [r3, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r1, [sp, #8]
	ldr r2, _080E7EE8 @ =0x000004A4
	adds r0, r1, r2
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x14]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080E7EEC
	ldr r3, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r3, r1
	b _080E7F12
	.align 2, 0
_080E7EE8: .4byte 0x000004A4
_080E7EEC:
	adds r0, r4, #0
	ldr r1, [sp, #0x14]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080E7F0A
	cmp r0, #2
	beq _080E7F1A
	ldr r0, [sp, #8]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080E7F1A
_080E7F0A:
	ldr r2, [sp, #8]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
_080E7F12:
	ldr r1, _080E7F2C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080E7F1A:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E7F2C: .4byte 0xFFFFFDFF
