	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08143A00 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143A04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143A06
	.align 2, 0
_08143A00: .4byte 0x0000046C
_08143A04:
	movs r0, #0
_08143A06:
	cmp r0, #0
	beq _08143A42
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	movs r3, #2
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _08143A9C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08143AA0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08143A42:
	ldr r0, _08143AA4 @ =0x0000065E
	add r0, r8
	ldrh r1, [r0]
	ldr r2, _08143AA8 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	blt _08143A54
	b _08143B64
_08143A54:
	ldr r0, _08143AAC @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r6, r0, #0
	ldrb r0, [r5, #5]
	subs r1, r6, r0
	cmp r1, #0x80
	ble _08143AB4
	ldr r0, _08143AB0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143AC2
	.align 2, 0
_08143A9C: .4byte 0x0000046D
_08143AA0: .4byte 0x0000046B
_08143AA4: .4byte 0x0000065E
_08143AA8: .4byte 0x00000484
_08143AAC: .4byte 0x03002BE0
_08143AB0: .4byte 0xFFFFFF00
_08143AB4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143AC2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143AC2:
	adds r0, r1, #0
	cmp r0, #0
	bge _08143ACA
	rsbs r0, r0, #0
_08143ACA:
	cmp r0, #0xb
	bgt _08143B0C
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, r8
	movs r3, #0
	strb r3, [r0]
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08143B04 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r3, [r0]
	ldr r3, _08143B08 @ =0x0000046C
	b _08143CA2
	.align 2, 0
_08143B04: .4byte 0x0000046A
_08143B08: .4byte 0x0000046C
_08143B0C:
	cmp r0, #0
	blt _08143B14
	asrs r0, r0, #2
	b _08143B1A
_08143B14:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08143B1A:
	adds r3, r0, #0
	cmp r0, #0
	bgt _08143B22
	movs r0, #4
_08143B22:
	adds r3, r0, #0
	cmp r3, #8
	ble _08143B2A
	movs r3, #8
_08143B2A:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, r8
	ldrb r0, [r2]
	cmp r0, #0x14
	bls _08143B50
	movs r1, #0
	strb r1, [r2]
	ldr r0, _08143B4C @ =0x00000661
	add r0, r8
	strb r1, [r0]
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	b _08143C8C
	.align 2, 0
_08143B4C: .4byte 0x00000661
_08143B50:
	adds r0, #1
	movs r1, #0
	strb r0, [r2]
	ldr r0, _08143B60 @ =0x00000661
	add r0, r8
	strb r1, [r0]
	b _08143CCE
	.align 2, 0
_08143B60: .4byte 0x00000661
_08143B64:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08143BCC @ =0x00007CFF
	cmp r1, r0
	bhi _08143B74
	b _08143C82
_08143B74:
	ldr r0, _08143BD0 @ =0x00000664
	add r0, r8
	ldr r0, [r0]
	cmp r0, r1
	bls _08143C18
	ldr r0, _08143BD4 @ =0x03002BE0
	mov r2, sp
	ldr r1, [r0]
	adds r4, r1, #0
	adds r4, #0x2c
	adds r3, r5, #0
	adds r3, #8
	ldrh r0, [r5, #8]
	ldrh r1, [r1, #0x2c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r6, r0, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _08143BDC
	ldr r0, _08143BD8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143BEA
	.align 2, 0
_08143BCC: .4byte 0x00007CFF
_08143BD0: .4byte 0x00000664
_08143BD4: .4byte 0x03002BE0
_08143BD8: .4byte 0xFFFFFF00
_08143BDC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143BEA
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143BEA:
	adds r0, r1, #0
	cmp r0, #0
	bge _08143BF2
	rsbs r0, r0, #0
_08143BF2:
	cmp r0, #0x3f
	bgt _08143BFA
	adds r6, #0x40
	b _08143BFC
_08143BFA:
	adds r6, #0xc0
_08143BFC:
	movs r0, #0xff
	ands r6, r0
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrb r0, [r0]
	movs r1, #8
	bl Div
	adds r3, r0, #0
	cmp r3, #0
	bgt _08143CC8
	movs r3, #2
	b _08143CC8
_08143C18:
	ldr r0, _08143C60 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r6, r0, #0
	ldrb r0, [r5, #5]
	subs r1, r6, r0
	cmp r1, #0x80
	ble _08143C68
	ldr r0, _08143C64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143C76
	.align 2, 0
_08143C60: .4byte 0x03002BE0
_08143C64: .4byte 0xFFFFFF00
_08143C68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143C76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143C76:
	adds r0, r1, #0
	cmp r0, #0
	bge _08143C7E
	rsbs r0, r0, #0
_08143C7E:
	cmp r0, #0x1f
	bgt _08143CB0
_08143C82:
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
_08143C8C:
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08143CAC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
_08143CA2:
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08143DBE
	.align 2, 0
_08143CAC: .4byte 0x00000484
_08143CB0:
	cmp r0, #0
	blt _08143CB8
	asrs r0, r0, #3
	b _08143CBE
_08143CB8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_08143CBE:
	adds r3, r0, #0
	cmp r0, #0
	bgt _08143CC6
	movs r0, #2
_08143CC6:
	adds r3, r0, #0
_08143CC8:
	cmp r3, #6
	ble _08143CCE
	movs r3, #6
_08143CCE:
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	add r7, sp, #8
	ldrb r4, [r5, #5]
	ldrb r0, [r0]
	mov ip, r0
	ldr r2, _08143D00 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	cmp r0, #0
	blt _08143D04
	asrs r1, r0, #0xc
	b _08143D0A
	.align 2, 0
_08143D00: .4byte gSineTable
_08143D04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08143D0A:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08143D26
	asrs r0, r0, #0xc
	b _08143D2C
_08143D26:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08143D2C:
	strh r0, [r7, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r0, _08143D50 @ =0x00000661
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08143DAA
	mov r2, sb
	subs r1, r6, r2
	cmp r1, #0x80
	ble _08143D58
	ldr r0, _08143D54 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143D66
	.align 2, 0
_08143D50: .4byte 0x00000661
_08143D54: .4byte 0xFFFFFF00
_08143D58:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143D66
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143D66:
	cmp r1, #0
	ble _08143D70
	ldrb r0, [r5, #5]
	adds r0, r0, r3
	b _08143D74
_08143D70:
	ldrb r0, [r5, #5]
	subs r0, r0, r3
_08143D74:
	strb r0, [r5, #5]
	ldr r2, [r5, #0x44]
	ldrb r1, [r5, #5]
	movs r0, #0x9f
	subs r0, r0, r1
	strb r0, [r2, #6]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08143D98
	ldr r1, _08143D94 @ =0x00000661
	add r1, r8
	movs r0, #4
	b _08143D9E
	.align 2, 0
_08143D94: .4byte 0x00000661
_08143D98:
	ldr r1, _08143DCC @ =0x00000661
	add r1, r8
	movs r0, #2
_08143D9E:
	strb r0, [r1]
	ldr r0, _08143DCC @ =0x00000661
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143DB4
_08143DAA:
	ldr r1, _08143DCC @ =0x00000661
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08143DB4:
	ldr r0, _08143DD0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08143DBE:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08143DCC: .4byte 0x00000661
_08143DD0: .4byte 0x00000484
