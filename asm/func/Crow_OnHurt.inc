	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081428E8
	b _08142FB6
_081428E8:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081428F6
	b _08142FB6
_081428F6:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x40
	add r0, r8
	mov sb, r0
	cmp r2, #0
	beq _0814290C
	b _08142F8E
_0814290C:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08142938
	ldr r3, _08142934 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08142924
	b _08142F8E
_08142924:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _08142F8E
	.align 2, 0
_08142934: .4byte 0x0000048C
_08142938:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08142948
	b _08142F8E
_08142948:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08142956
	b _08142C60
_08142956:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _08142966
	b _08142F8E
_08142966:
	ldr r2, _081429F8 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0814297A
	b _08142F8E
_0814297A:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08142988
	b _08142F8E
_08142988:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _081429A0
	b _08142AE8
_081429A0:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _08142A08
	ands r3, r1
	cmp r3, #0
	beq _08142A08
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081429C8
	rsbs r1, r1, #0
_081429C8:
	cmp r1, #0x20
	bgt _08142A08
	ldrh r0, [r7, #0x3c]
	ldr r3, _081429FC @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _08142A00 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08142A04 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08142F8E
	.align 2, 0
_081429F8: .4byte 0x0000A007
_081429FC: .4byte 0x000004BE
_08142A00: .4byte 0x0000048C
_08142A04: .4byte 0x0000044E
_08142A08:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _08142A30 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08142A38
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142A34 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A30: .4byte 0x0000048A
_08142A34: .4byte 0x03002BE0
_08142A38:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08142A54
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142A50 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A50: .4byte 0x03002BE0
_08142A54:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08142A70
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08142A6C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A6C: .4byte 0x03002BE0
_08142A70:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08142A8C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142A88 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A88: .4byte 0x03002BE0
_08142A8C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08142A9E
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08142AA6
_08142A9E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08142AA8
_08142AA6:
	movs r3, #1
_08142AA8:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _08142AC8
	b _08142C1C
_08142AC8:
	movs r1, #2
	ldr r3, _08142ADC @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142AE0
	movs r0, #1
	b _08142AE2
	.align 2, 0
_08142ADC: .4byte 0x00000474
_08142AE0:
	movs r0, #0
_08142AE2:
	cmp r0, #0
	bne _08142BC2
	b _08142BD8
_08142AE8:
	mov r3, r8
	strh r2, [r3, #0x3e]
	ldr r1, _08142B10 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08142B18
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142B14 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B10: .4byte 0x0000048A
_08142B14: .4byte 0x03002BE0
_08142B18:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08142B34
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142B30 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B30: .4byte 0x03002BE0
_08142B34:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08142B50
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08142B4C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B4C: .4byte 0x03002BE0
_08142B50:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08142B6C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142B68 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B68: .4byte 0x03002BE0
_08142B6C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08142B7E
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08142B86
_08142B7E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08142B88
_08142B86:
	movs r3, #1
_08142B88:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _08142C1C
	movs r1, #2
	ldr r3, _08142BB8 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142BBC
	movs r0, #1
	b _08142BBE
	.align 2, 0
_08142BB8: .4byte 0x00000474
_08142BBC:
	movs r0, #0
_08142BBE:
	cmp r0, #0
	beq _08142BD8
_08142BC2:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142BD4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08142BE4
	.align 2, 0
_08142BD4: .4byte 0x03002BE0
_08142BD8:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08142C1C
_08142BE4:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08142C1C:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08142C48
	ldr r0, _08142C58 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08142C48
	strh r1, [r2]
_08142C48:
	ldr r0, _08142C5C @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	add r1, r8
	mov sb, r1
	b _08142F8E
	.align 2, 0
_08142C58: .4byte 0x0000024E
_08142C5C: .4byte 0x0000048C
_08142C60:
	ldr r0, _08142C74 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08142C78
	movs r0, #1
	b _08142C7A
	.align 2, 0
_08142C74: .4byte 0x030047A4
_08142C78:
	movs r0, #0
_08142C7A:
	cmp r0, #0
	beq _08142C88
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _08142C90
_08142C88:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
_08142C90:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08142CC8 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08142CCC @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08142CBE
	cmp r2, #0x17
	bne _08142CD0
_08142CBE:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _08142CF0
	.align 2, 0
_08142CC8: .4byte 0x0000048C
_08142CCC: .4byte 0x000001DF
_08142CD0:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08142CBE
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _08142D20 @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08142CF0
	movs r1, #0
_08142CF0:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08142D2E
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _08142D24
	asrs r0, r0, #1
	b _08142D2A
	.align 2, 0
_08142D20: .4byte 0x00000187
_08142D24:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08142D2A:
	mov r3, sb
	strh r0, [r3]
_08142D2E:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08142D4C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08142D48 @ =0x000001DD
	adds r1, r6, r4
	b _08142DC0
	.align 2, 0
_08142D48: .4byte 0x000001DD
_08142D4C:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldrh r1, [r7, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08142DAC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08142DAC
	ldr r2, _08142D9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08142DA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08142DA4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08142DA8 @ =0x000001DD
	adds r1, r6, r4
	b _08142DC0
	.align 2, 0
_08142D9C: .4byte 0x030046B8
_08142DA0: .4byte 0x000003FF
_08142DA4: .4byte 0x0203B400
_08142DA8: .4byte 0x000001DD
_08142DAC:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08142DE0 @ =0x000001DD
	adds r1, r6, r3
_08142DC0:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08142DE8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142DE4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142DE0: .4byte 0x000001DD
_08142DE4: .4byte 0x03002BE0
_08142DE8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08142E04
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08142E00 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142E00: .4byte 0x03002BE0
_08142E04:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08142E20
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142E1C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142E1C: .4byte 0x03002BE0
_08142E20:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08142E3C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142E38 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142E38: .4byte 0x03002BE0
_08142E3C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08142E4E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08142E56
_08142E4E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08142E58
_08142E56:
	movs r3, #1
_08142E58:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _08142E88 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _08142EF0
	movs r1, #2
	ldr r2, _08142E8C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142E90
	movs r0, #1
	b _08142E92
	.align 2, 0
_08142E88: .4byte 0x0000049C
_08142E8C: .4byte 0x00000474
_08142E90:
	movs r0, #0
_08142E92:
	cmp r0, #0
	beq _08142EAC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142EA8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08142EB8
	.align 2, 0
_08142EA8: .4byte 0x03002BE0
_08142EAC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08142EF0
_08142EB8:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08142EF0:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08142F24
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08142F24
	ldr r3, _08142F3C @ =0x0000024E
	adds r2, r6, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08142F24
	strh r1, [r2]
_08142F24:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08142F40 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08142F44 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142F48
	movs r0, #1
	b _08142F4A
	.align 2, 0
_08142F3C: .4byte 0x0000024E
_08142F40: .4byte 0x030046A0
_08142F44: .4byte 0x00000934
_08142F48:
	movs r0, #0
_08142F4A:
	ldr r1, _08142FC8 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08142F64
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_08142F64:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	strh r0, [r4]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r7, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08142F8E:
	ldr r2, _08142FCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08142FD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08142FD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	ldrh r2, [r3]
	movs r1, #0xf
	ands r0, r1
	subs r2, r2, r0
	cmp r2, #0x14
	bge _08142FB2
	movs r2, #0x14
_08142FB2:
	mov r4, sb
	strh r2, [r4]
_08142FB6:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08142FC8: .4byte 0x0000048A
_08142FCC: .4byte 0x030046B8
_08142FD0: .4byte 0x000003FF
_08142FD4: .4byte 0x0203B400
