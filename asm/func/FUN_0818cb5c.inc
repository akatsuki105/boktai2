	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818CB88 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818CB8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818CB8E
	.align 2, 0
_0818CB88: .4byte 0x0000046C
_0818CB8C:
	movs r0, #0
_0818CB8E:
	cmp r0, #0
	beq _0818CBE6
	movs r4, #0x20
	ldr r3, _0818CBC8 @ =0x00000474
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0818CBCC @ =0x00000F2C
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0818CBD0 @ =0x00000ECA
	add r0, r8
	strh r3, [r0]
	ldr r0, _0818CBD4 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ands r0, r4
	cmp r0, #0
	beq _0818CBD8
	movs r0, #1
	b _0818CBDA
	.align 2, 0
_0818CBC8: .4byte 0x00000474
_0818CBCC: .4byte 0x00000F2C
_0818CBD0: .4byte 0x00000ECA
_0818CBD4: .4byte 0xFFFF7FFF
_0818CBD8:
	movs r0, #0
_0818CBDA:
	cmp r0, #0
	beq _0818CBE6
	movs r0, #0xda
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0818CBE6:
	ldrh r2, [r6, #0xa]
	movs r5, #0xa
	ldrsh r1, [r6, r5]
	ldr r0, _0818CC4C @ =0xFFFFF800
	cmp r1, r0
	ble _0818CC70
	adds r0, r2, #0
	subs r0, #0x80
	strh r0, [r6, #0xa]
	ldr r0, [r6, #0x44]
	ldr r0, [r0]
	cmp r0, #0
	bne _0818CC76
	movs r7, #0xa
	ldrsh r0, [r6, r7]
	ldr r1, _0818CC50 @ =0x00000472
	adds r2, r6, r1
	ldrh r3, [r2]
	cmp r0, r3
	bge _0818CC76
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	ldr r2, _0818CC54 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r2, [r6, #5]
	mov r0, sp
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x20
	ldr r0, _0818CC58 @ =0x00000F2C
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818CC5C
	movs r0, #1
	b _0818CC5E
	.align 2, 0
_0818CC4C: .4byte 0xFFFFF800
_0818CC50: .4byte 0x00000472
_0818CC54: .4byte 0x0000FFFF
_0818CC58: .4byte 0x00000F2C
_0818CC5C:
	movs r0, #0
_0818CC5E:
	cmp r0, #0
	bne _0818CC76
	ldr r0, _0818CC6C @ =0x000001DF
	bl PlaySound_082406e0
	b _0818CC76
	.align 2, 0
_0818CC6C: .4byte 0x000001DF
_0818CC70:
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r6, #0xa]
_0818CC76:
	ldr r5, _0818CC90 @ =0x00000484
	adds r0, r6, r5
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _0818CC94
	adds r0, r6, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #0
	bl FUN_0818fdd8
	b _0818CCA0
	.align 2, 0
_0818CC90: .4byte 0x00000484
_0818CC94:
	ldr r3, _0818CD60 @ =0x0000A410
	adds r0, r6, #0
	movs r1, #0xc
	movs r2, #6
	bl FUN_0818fdd8
_0818CCA0:
	movs r5, #0
	ldr r1, _0818CD64 @ =0x00000F36
	add r1, r8
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r5, r0
	bge _0818CD28
	add r3, sp, #8
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #0x14]
	ldr r2, _0818CD68 @ =0x00000472
	adds r2, r6, r2
	str r2, [sp, #0x10]
	mov sl, r1
	mov r4, r8
	mov ip, r5
	movs r7, #0x92
	lsls r7, r7, #1
	mov sb, r7
_0818CCC8:
	mov r2, ip
	add r2, r8
	ldr r0, _0818CD6C @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldr r7, [sp, #0x14]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _0818CD18
	ldr r0, _0818CD70 @ =0x00000676
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r7, [sp, #0x10]
	ldrh r1, [r7]
	cmp r0, r1
	bge _0818CD18
	strh r1, [r2]
_0818CD18:
	add r4, sb
	add ip, sb
	adds r5, #1
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r5, r0
	blt _0818CCC8
_0818CD28:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xa
	bl FUN_08191774
	mov r0, r8
	bl FUN_0818f008
	cmp r0, #0
	blt _0818CD3E
	b _0818CF98
_0818CD3E:
	ldr r0, _0818CD74 @ =0x000003E5
	bl sound_08240740
	ldr r2, _0818CD78 @ =0x00000F2C
	add r2, r8
	ldr r1, _0818CD7C @ =0xFFFF7FFF
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	beq _0818CD80
	movs r0, #1
	b _0818CD82
	.align 2, 0
_0818CD60: .4byte 0x0000A410
_0818CD64: .4byte 0x00000F36
_0818CD68: .4byte 0x00000472
_0818CD6C: .4byte 0x00000674
_0818CD70: .4byte 0x00000676
_0818CD74: .4byte 0x000003E5
_0818CD78: .4byte 0x00000F2C
_0818CD7C: .4byte 0xFFFF7FFF
_0818CD80:
	movs r0, #0
_0818CD82:
	cmp r0, #0
	beq _0818CDC4
	ldr r3, _0818CDBC @ =0x00000484
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0xa0
	bgt _0818CD92
	b _0818CF98
_0818CD92:
	movs r2, #0x13
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	movs r1, #0
	strb r1, [r0]
	ldr r7, _0818CDC0 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	subs r3, #0x1a
	adds r0, r6, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r1, [r0]
	adds r7, #3
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	b _0818CF98
	.align 2, 0
_0818CDBC: .4byte 0x00000484
_0818CDC0: .4byte 0x00000469
_0818CDC4:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818CDD6
	movs r0, #1
	b _0818CDD8
_0818CDD6:
	movs r0, #0
_0818CDD8:
	adds r4, r0, #0
	cmp r4, #0
	bne _0818CDE0
	b _0818CEE0
_0818CDE0:
	ldr r7, _0818CDF4 @ =0x00000E41
	add r7, r8
	ldrb r0, [r7]
	mov sb, r0
	cmp r0, #0
	beq _0818CDF8
	subs r0, #1
	strb r0, [r7]
	b _0818CFA2
	.align 2, 0
_0818CDF4: .4byte 0x00000E41
_0818CDF8:
	ldr r3, _0818CEA4 @ =0x00000472
	adds r4, r6, r3
	ldr r5, _0818CEA8 @ =0xFFFFFF00
	adds r0, r5, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r6, #0xa]
	adds r5, r6, #0
	adds r5, #8
	mov r0, r8
	adds r1, r5, #0
	bl FUN_0819014c
	ldrh r0, [r4]
	strh r0, [r6, #0xa]
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r3, #0
	strb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0818CEAC @ =0x0000046A
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _0818CEB0 @ =0x00000484
	adds r0, r6, r1
	mov r2, sb
	str r2, [r0]
	adds r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0818CEB4 @ =0x00000474
	adds r2, r6, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldrb r2, [r6, #5]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r2, #0xe4
	lsls r2, r2, #4
	add r2, r8
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r0, _0818CEB8 @ =0x00000E42
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r7]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r5, _0818CEBC @ =0x00000546
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0818CEC4
	ldrb r0, [r2]
	cmp r0, #4
	bhi _0818CE94
	b _0818CFA2
_0818CE94:
	movs r7, #0
	strb r7, [r2]
	ldr r0, _0818CEC0 @ =0xFFFFFBFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818CFA2
	.align 2, 0
_0818CEA4: .4byte 0x00000472
_0818CEA8: .4byte 0xFFFFFF00
_0818CEAC: .4byte 0x0000046A
_0818CEB0: .4byte 0x00000484
_0818CEB4: .4byte 0x00000474
_0818CEB8: .4byte 0x00000E42
_0818CEBC: .4byte 0x00000546
_0818CEC0: .4byte 0xFFFFFBFF
_0818CEC4:
	ldrb r0, [r2]
	cmp r0, #2
	bls _0818CFA2
	movs r3, #0
	strb r3, [r2]
	ldr r0, _0818CEDC @ =0xFFFFFBFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _0818CFA2
	.align 2, 0
_0818CEDC: .4byte 0xFFFFFBFF
_0818CEE0:
	ldr r7, _0818CF2C @ =0x00000484
	adds r0, r6, r7
	movs r1, #0xd5
	lsls r1, r1, #4
	add r1, r8
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	ble _0818CF98
	ldr r2, _0818CF30 @ =0x00000D4E
	add r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _0818CF38
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	ldr r5, _0818CF34 @ =0x00000469
	adds r0, r6, r5
	strb r4, [r0]
	subs r7, #0x1a
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0818CF2C @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	adds r3, #4
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _0818CFA2
	.align 2, 0
_0818CF2C: .4byte 0x00000484
_0818CF30: .4byte 0x00000D4E
_0818CF34: .4byte 0x00000469
_0818CF38:
	movs r1, #0x16
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r4, [r0]
	ldr r7, _0818CF84 @ =0x00000469
	adds r0, r6, r7
	strb r4, [r0]
	ldr r2, _0818CF88 @ =0x0000046A
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _0818CF8C @ =0x00000484
	adds r0, r6, r3
	str r4, [r0]
	adds r5, #4
	adds r0, r6, r5
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818CF90 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r7, #4
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0818CF94 @ =0x0000046B
	adds r0, r6, r1
	strb r4, [r0]
	adds r5, #0xe7
	adds r0, r6, r5
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	b _0818CFA2
	.align 2, 0
_0818CF84: .4byte 0x00000469
_0818CF88: .4byte 0x0000046A
_0818CF8C: .4byte 0x00000484
_0818CF90: .4byte Enemy_ClearStateBegun
_0818CF94: .4byte 0x0000046B
_0818CF98:
	ldr r2, _0818CFB4 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818CFA2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818CFB4: .4byte 0x00000484
