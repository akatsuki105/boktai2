	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	movs r6, #0
	ldr r0, _08006D20 @ =0x03002BE0
	mov r8, r0
_08006CE2:
	lsls r1, r6, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	mov r0, sl
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _08006D64
	lsls r0, r6, #3
	mov r7, sl
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r2, #0
	adds r5, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D24
	asrs r0, r0, #8
	b _08006D2A
	.align 2, 0
_08006D20: .4byte 0x03002BE0
_08006D24:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D2A:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D3C
	asrs r0, r0, #8
	b _08006D42
_08006D3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D42:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08006D56
	asrs r1, r0, #8
	b _08006D5C
_08006D56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08006D5C:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_08006D64:
	adds r6, #1
	cmp r6, #3
	ble _08006CE2
	mov r1, sl
	ldr r3, [r1, #0x28]
	movs r2, #0x24
	add r2, sl
	mov sb, r2
	cmp r3, #0
	bne _08006D7A
	b _08006F3C
_08006D7A:
	movs r5, #1
	movs r6, #2
	rsbs r6, r6, #0
_08006D80:
	adds r0, r3, #0
	adds r0, #0xb8
	ldr r0, [r0]
	mov r8, r0
	ldrb r1, [r3, #6]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08006D9A
	adds r0, r3, #0
	bl MapItem_Free
	b _08006F34
_08006D9A:
	ldrh r0, [r3, #0x16]
	cmp r0, #0
	beq _08006DC4
	ldr r0, _08006DB8 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0x92
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r1, [r3, #0x16]
	cmp r0, r1
	bne _08006DBC
	movs r0, #1
	b _08006DBE
	.align 2, 0
_08006DB8: .4byte 0x030046A0
_08006DBC:
	movs r0, #0
_08006DBE:
	cmp r0, #0
	bne _08006DC4
	b _08006F12
_08006DC4:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006DD0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
_08006DD0:
	ldr r1, [r3, #0x20]
	adds r4, r1, #0
	cmp r1, #0
	bne _08006DDA
	b _08006F2A
_08006DDA:
	ldrb r0, [r3, #9]
	cmp r0, #0
	bne _08006DE2
	b _08006F0C
_08006DE2:
	ldr r0, _08006DFC @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _08006E00
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0
	strb r0, [r3, #0xb]
_08006DF4:
	strb r0, [r3, #0xc]
_08006DF6:
	strb r5, [r3, #0xa]
	b _08006F2A
	.align 2, 0
_08006DFC: .4byte 0x03002B48
_08006E00:
	ldr r0, _08006E34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08006E48
	ldr r0, _08006E38 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _08006E44
	ldr r2, _08006E3C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08006E2E
	ldr r7, _08006E40 @ =0x00000442
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E2E
	movs r2, #1
_08006E2E:
	adds r0, r2, #0
	b _08006E70
	.align 2, 0
_08006E34: .4byte 0x030047A4
_08006E38: .4byte 0x03002BE0
_08006E3C: .4byte 0x00000446
_08006E40: .4byte 0x00000442
_08006E44:
	movs r0, #0
	b _08006E70
_08006E48:
	ldr r0, _08006E9C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _08006E74
	ldr r0, _08006EA0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08006E6E
	ldr r0, _08006EA4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E6E
	movs r1, #1
_08006E6E:
	adds r0, r1, #0
_08006E70:
	cmp r0, #0
	beq _08006ED8
_08006E74:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	beq _08006E7E
	movs r0, #0x1f
	strb r0, [r3, #0xb]
_08006E7E:
	ldrb r1, [r3, #0xb]
	adds r2, r1, #0
	cmp r2, #0
	beq _08006EB0
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EA8
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ED2
	.align 2, 0
_08006E9C: .4byte 0x030046A0
_08006EA0: .4byte 0x03002B8C
_08006EA4: .4byte 0x03002B60
_08006EA8:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ED2
_08006EB0:
	ldrb r0, [r3, #0xc]
	cmp r0, #0x2f
	bhi _08006EBE
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ECC
_08006EBE:
	cmp r0, #0x47
	bhi _08006ECA
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ECC
_08006ECA:
	strb r2, [r3, #0xc]
_08006ECC:
	ldrb r0, [r3, #0xc]
	adds r0, #1
	strb r0, [r3, #0xc]
_08006ED2:
	movs r0, #0
	strb r0, [r3, #0xa]
	b _08006F2A
_08006ED8:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	bne _08006EE2
	movs r0, #0x2f
	strb r0, [r3, #0xb]
_08006EE2:
	ldrb r1, [r3, #0xb]
	cmp r1, #0
	beq _08006F04
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EFA
	ldr r0, [r4]
	orrs r0, r5
	b _08006EFE
_08006EFA:
	ldr r0, [r4]
	ands r0, r6
_08006EFE:
	str r0, [r4]
	movs r0, #0
	b _08006DF4
_08006F04:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006DF6
_08006F0C:
	ldr r0, [r1]
	ands r0, r6
	b _08006F28
_08006F12:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006F1E
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_08006F1E:
	ldr r1, [r3, #0x20]
	cmp r1, #0
	beq _08006F2A
	ldr r0, [r1]
	orrs r0, r5
_08006F28:
	str r0, [r1]
_08006F2A:
	ldr r2, [r3, #0x44]
	mov r0, sl
	adds r1, r3, #0
	bl _call_via_r2
_08006F34:
	mov r3, r8
	cmp r3, #0
	beq _08006F3C
	b _08006D80
_08006F3C:
	mov r7, sb
	ldrb r0, [r7]
	cmp r0, #0
	beq _08006F48
	subs r0, #1
	strb r0, [r7]
_08006F48:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
