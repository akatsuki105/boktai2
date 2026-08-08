	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F6E8A
_080F6E84:
	movs r0, #0
	bl FUN_080f83ee
_080F6E8A:
	ldr r3, _080F6E9C @ =0x0000048C
	adds r0, r6, r3
	ldrb r1, [r0]
	str r0, [sp, #0x48]
	cmp r1, #0
	bne _080F6EA0
	movs r0, #0
	b _080F6EA2
	.align 2, 0
_080F6E9C: .4byte 0x0000048C
_080F6EA0:
	movs r0, #1
_080F6EA2:
	cmp r0, #0
	beq _080F6EAA
	bl FUN_080f79e8
_080F6EAA:
	ldr r4, _080F6F00 @ =0x0000046F
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _080F6EB6
	b _080F72C4
_080F6EB6:
	movs r2, #2
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _080F6ECA
	b _080F72C4
_080F6ECA:
	movs r2, #8
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r1, r6, r7
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x34]
	cmp r0, #0
	beq _080F6EDE
	b _080F72C4
_080F6EDE:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	str r0, [sp, #0x30]
	cmp r1, #0
	beq _080F6EEE
	b _080F72C4
_080F6EEE:
	ldr r0, _080F6F04 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F6F08
	movs r0, #1
	b _080F6F0A
	.align 2, 0
_080F6F00: .4byte 0x0000046F
_080F6F04: .4byte 0x030047A4
_080F6F08:
	movs r0, #0
_080F6F0A:
	cmp r0, #0
	beq _080F6F22
	adds r4, r6, #0
	adds r4, #8
	movs r2, #0x95
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r1, [r5]
	adds r0, r4, #0
	bl FUN_0809eb94
	b _080F6F34
_080F6F22:
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x95
	lsls r3, r3, #2
	adds r5, r6, r3
	ldrh r1, [r5]
	adds r0, r4, #0
	bl FUN_0809e0d4
_080F6F34:
	adds r7, r0, #0
	str r4, [sp, #0x44]
	mov sl, r5
	cmp r7, #0
	bne _080F6F40
	b _080F72C4
_080F6F40:
	ldr r1, _080F6FDC @ =0xFFFEBE3F
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r5, _080F6FE0 @ =0x0000021E
	adds r0, r6, r5
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _080F6FE4 @ =0x00000202
	adds r0, r6, r3
	strh r1, [r0]
	ldr r5, _080F6FE8 @ =0x0203B400
	ldr r4, _080F6FEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r2, _080F6FF0 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #0x3f
	ands r1, r3
	subs r1, #0x10
	str r1, [sp, #0x1c]
	adds r0, #1
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #0x10
	str r0, [sp, #0x20]
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r1, r6, r4
	strh r7, [r1]
	ldr r5, _080F6FF4 @ =0x0000048A
	adds r4, r6, r5
	strh r7, [r4]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r3, r6, r0
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r1, r0
	adds r7, r4, #0
	str r2, [sp, #0x38]
	mov sb, r3
	cmp r1, #0
	beq _080F6FC2
	b _080F7106
_080F6FC2:
	ldr r1, _080F6FF8 @ =0x0000047C
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _080F6FFC @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F7000
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080F700C
	.align 2, 0
_080F6FDC: .4byte 0xFFFEBE3F
_080F6FE0: .4byte 0x0000021E
_080F6FE4: .4byte 0x00000202
_080F6FE8: .4byte 0x0203B400
_080F6FEC: .4byte 0x030046B8
_080F6FF0: .4byte 0x000003FF
_080F6FF4: .4byte 0x0000048A
_080F6FF8: .4byte 0x0000047C
_080F6FFC: .4byte 0x0000025D
_080F7000:
	ldr r2, [r6, #0x44]
	ldr r0, _080F7034 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080F700C:
	ldr r3, _080F7038 @ =0x00000492
	adds r1, r6, r3
	movs r0, #8
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	mov r4, r8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080F703C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F7040
	movs r0, #1
	b _080F7042
	.align 2, 0
_080F7034: .4byte 0x03003584
_080F7038: .4byte 0x00000492
_080F703C: .4byte 0x030047A4
_080F7040:
	movs r0, #0
_080F7042:
	cmp r0, #0
	beq _080F70B0
	movs r5, #0x94
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080F70B0
	cmp r2, #0
	beq _080F70B0
	ldr r0, _080F7068 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080F706C
	movs r0, #1
	rsbs r0, r0, #0
	b _080F7070
	.align 2, 0
_080F7068: .4byte 0x03002C68
_080F706C:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_080F7070:
	cmp r0, #1
	beq _080F7092
	cmp r0, #1
	bgt _080F707E
	cmp r0, #0
	beq _080F7088
	b _080F70B0
_080F707E:
	cmp r0, #2
	beq _080F709C
	cmp r0, #3
	beq _080F70A6
	b _080F70B0
_080F7088:
	ldr r0, [r1]
	cmp r0, #1
	beq _080F70B0
	movs r0, #0
	b _080F70B2
_080F7092:
	ldr r0, [r1]
	cmp r0, #2
	beq _080F70B0
	movs r0, #0
	b _080F70B2
_080F709C:
	ldr r0, [r1]
	cmp r0, #4
	beq _080F70B0
	movs r0, #0
	b _080F70B2
_080F70A6:
	ldr r0, [r1]
	cmp r0, #8
	beq _080F70B0
	movs r0, #0
	b _080F70B2
_080F70B0:
	movs r0, #1
_080F70B2:
	cmp r0, #0
	beq _080F7106
	ldrh r0, [r6]
	ldr r3, [sp, #0x38]
	movs r4, #0
	ldrsh r1, [r3, r4]
	mov r5, sl
	ldrh r2, [r5]
	ldr r4, _080F717C @ =0x0000025A
	adds r3, r6, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r5, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _080F7180 @ =0x05000002
	bl CpuSet
	ldrh r0, [r7]
	cmp r0, #0
	bne _080F70F2
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080F7106
_080F70F2:
	adds r0, r6, #0
	adds r0, #0xd8
	ldrh r1, [r7]
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	ldr r3, [sp, #0x44]
	bl FUN_0805fe7c
_080F7106:
	adds r0, r6, #0
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	bl FUN_080e5098
	movs r0, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r1, [r4]
	movs r5, #0
	movs r7, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r0, #0x26
	ldr r3, [sp, #0x30]
	strh r0, [r3]
	ldr r0, _080F7184 @ =0x0000049C
	adds r1, r6, r0
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r1]
	mov r1, sb
	str r7, [r1]
	adds r0, r6, #0
	bl FUN_080e64e4
	ldr r0, _080F7188 @ =0xFFFFDFFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r2, _080F718C @ =0x000004BE
	adds r0, r6, r2
	strh r7, [r0]
	ldr r3, [sp, #0x38]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bgt _080F724C
	ldr r2, [sp, #0x30]
	strh r7, [r2]
	ldr r3, _080F7190 @ =0x0000025D
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F7194
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F71A2
	.align 2, 0
_080F717C: .4byte 0x0000025A
_080F7180: .4byte 0x05000002
_080F7184: .4byte 0x0000049C
_080F7188: .4byte 0xFFFFDFFF
_080F718C: .4byte 0x000004BE
_080F7190: .4byte 0x0000025D
_080F7194:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F71A2:
	movs r4, #0xba
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r1, #0x11
	ldr r5, _080F7210 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _080F7214 @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _080F7218 @ =0x00000469
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _080F721C @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _080F7220 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	adds r7, #0x37
	adds r1, r6, r7
	movs r0, #0x20
	str r0, [r1]
	ldr r0, _080F7224 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F7228
	movs r0, #1
	b _080F722A
	.align 2, 0
_080F7210: .4byte 0x0000046D
_080F7214: .4byte 0x0000046B
_080F7218: .4byte 0x00000469
_080F721C: .4byte 0x0000046A
_080F7220: .4byte 0x00000484
_080F7224: .4byte 0x030047A4
_080F7228:
	movs r0, #0
_080F722A:
	cmp r0, #0
	bne _080F72A0
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x34]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080F72A0
	ldr r0, _080F7248 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl FUN_080ec5b4
	b _080F72A0
	.align 2, 0
_080F7248: .4byte 0x03002B28
_080F724C:
	movs r0, #0x20
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r3, _080F72B0 @ =0x000005CC
	adds r0, r6, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r4, _080F72B4 @ =0x0000046D
	adds r0, r6, r4
	movs r3, #1
	strb r3, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r5, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r7, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _080F72B8 @ =0x00000469
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _080F72BC @ =0x0000046A
	adds r0, r6, r2
	strb r5, [r0]
	adds r4, #0x1c
	adds r0, r6, r4
	str r7, [r0]
	ldr r5, _080F72C0 @ =0x0000046C
	adds r0, r6, r5
	strb r3, [r0]
_080F72A0:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r7, r8
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #1
	b _080F72C6
	.align 2, 0
_080F72B0: .4byte 0x000005CC
_080F72B4: .4byte 0x0000046D
_080F72B8: .4byte 0x00000469
_080F72BC: .4byte 0x0000046A
_080F72C0: .4byte 0x0000046C
_080F72C4:
	movs r0, #0
_080F72C6:
	cmp r0, #0
	bne _080F72CC
	b _080F6E84
_080F72CC:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	ldr r1, _080F733C @ =0xFFFEBE3F
	ands r0, r1
	str r0, [r2]
	ldr r3, _080F7340 @ =0x0000021E
	adds r4, r6, r3
	movs r5, #0
	mov sb, r5
	movs r5, #0
	strh r5, [r4]
	movs r7, #0x88
	lsls r7, r7, #2
	adds r7, r6, r7
	str r7, [sp, #0x24]
	strh r5, [r7]
	ldr r0, _080F7344 @ =0x00000202
	adds r3, r6, r0
	strh r5, [r3]
	movs r1, #0x80
	lsls r1, r1, #5
	mov sl, r1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r1, r6, r7
	ldrh r0, [r1]
	mov r7, sl
	ands r0, r7
	adds r7, r1, #0
	mov r8, r2
	str r4, [sp, #0x40]
	str r3, [sp, #0x3c]
	cmp r0, #0
	beq _080F732A
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	mov r1, sl
	bics r0, r1
	strh r0, [r7]
	str r5, [r4]
_080F732A:
	ldrh r0, [r7]
	cmp r0, #0
	bne _080F734C
	ldr r1, _080F7348 @ =0xFFFFDFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F79CC
	.align 2, 0
_080F733C: .4byte 0xFFFEBE3F
_080F7340: .4byte 0x0000021E
_080F7344: .4byte 0x00000202
_080F7348: .4byte 0xFFFFDFFF
_080F734C:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080F73D8
	ldrh r0, [r7]
	mov r3, sl
	ands r0, r3
	cmp r0, #0
	beq _080F737A
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	mov r1, sl
	bics r0, r1
	strh r0, [r7]
	str r5, [r4]
_080F737A:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F73B0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F73CC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F73D0 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r0, r6, r4
	mov r1, sb
	strb r1, [r0]
	ldr r2, [sp, #0x40]
	strh r5, [r2]
	ldr r3, [sp, #0x3c]
	strh r5, [r3]
_080F73B0:
	movs r0, #0x40
	strh r0, [r7]
	mov r5, sb
	ldr r4, [sp, #0x48]
	strb r5, [r4]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r0, _080F73D4 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080F79CC
	.align 2, 0
_080F73CC: .4byte 0xFEFFFFFF
_080F73D0: .4byte 0xFFFFFDFF
_080F73D4: .4byte 0xFFFFF67F
_080F73D8:
	movs r0, #0x80
	lsls r0, r0, #6
	mov ip, r0
	ldrh r2, [r7]
	adds r1, r2, #0
	adds r0, r1, #0
	mov r3, ip
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080F74B4
	ldr r0, _080F7488 @ =0x00000482
	adds r5, r6, r0
	movs r1, #1
	mov sl, r1
	mov r2, sl
	strh r2, [r5]
	ldr r3, _080F748C @ =0x00000222
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _080F7490 @ =0x0000024E
	adds r0, r6, r1
	strh r4, [r0]
	ldr r0, _080F7494 @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7498 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F744A
	subs r3, #0xa6
	adds r2, r6, r3
	ldr r1, _080F749C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F74A0 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, [sp, #0x40]
	strh r4, [r3]
	ldr r0, [sp, #0x3c]
	strh r4, [r0]
_080F744A:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r7]
	bics r0, r2
	strh r0, [r7]
	ldr r3, _080F74A4 @ =0x00000542
	adds r1, r6, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F74A8 @ =0xFBFFFFFF
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _080F74AC @ =0xFFFFFAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	mov r1, sl
	strh r1, [r5]
	ldr r0, _080F74B0 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080F77A4
	.align 2, 0
_080F7488: .4byte 0x00000482
_080F748C: .4byte 0x00000222
_080F7490: .4byte 0x0000024E
_080F7494: .4byte 0xFFFFFC7F
_080F7498: .4byte 0xF3FFFFFF
_080F749C: .4byte 0xFEFFFFFF
_080F74A0: .4byte 0xFFFFFDFF
_080F74A4: .4byte 0x00000542
_080F74A8: .4byte 0xFBFFFFFF
_080F74AC: .4byte 0xFFFFFAFF
_080F74B0: .4byte 0xFFFFF67F
_080F74B4:
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080F758C
	ldr r2, _080F7560 @ =0x00000482
	adds r4, r6, r2
	movs r5, #1
	strh r5, [r4]
	ldr r1, _080F7564 @ =0x00000222
	adds r0, r6, r1
	strh r3, [r0]
	ldr r2, _080F7568 @ =0x0000024E
	adds r0, r6, r2
	strh r3, [r0]
	ldr r0, _080F756C @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7570 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F7518
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F7574 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7578 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	ldr r0, [sp, #0x40]
	strh r3, [r0]
	ldr r1, [sp, #0x3c]
	strh r3, [r1]
_080F7518:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r7]
	bics r0, r2
	strh r0, [r7]
	ldr r3, _080F757C @ =0x00000542
	adds r1, r6, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F7580 @ =0xFBFFFFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080F7584 @ =0xFFFFDAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	strh r5, [r4]
	ldr r0, _080F7588 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	mov r1, r8
	ldr r0, [r1]
	mov r2, ip
	orrs r0, r2
	str r0, [r1]
	b _080F77A4
	.align 2, 0
_080F7560: .4byte 0x00000482
_080F7564: .4byte 0x00000222
_080F7568: .4byte 0x0000024E
_080F756C: .4byte 0xFFFFFC7F
_080F7570: .4byte 0xF3FFFFFF
_080F7574: .4byte 0xFEFFFFFF
_080F7578: .4byte 0xFFFFFDFF
_080F757C: .4byte 0x00000542
_080F7580: .4byte 0xFBFFFFFF
_080F7584: .4byte 0xFFFFDAFF
_080F7588: .4byte 0xFFFFF67F
_080F758C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F7650
	ldr r3, _080F7624 @ =0x00000482
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	ldr r5, _080F7628 @ =0x00000222
	adds r0, r6, r5
	strh r4, [r0]
	ldr r1, _080F762C @ =0x0000024E
	adds r0, r6, r1
	strh r4, [r0]
	ldr r0, _080F7630 @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7634 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F75EA
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F7638 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F763C @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	subs r5, #6
	adds r0, r6, r5
	mov r1, sb
	strb r1, [r0]
	ldr r2, [sp, #0x40]
	strh r4, [r2]
	ldr r3, [sp, #0x3c]
	strh r4, [r3]
_080F75EA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r7]
	bics r0, r2
	strh r0, [r7]
	ldr r4, _080F7640 @ =0x00000542
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F7644 @ =0xFBFFFFFF
	mov r5, r8
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r0, _080F7648 @ =0xFFFFDAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	orrs r2, r0
	mov r3, sb
	orrs r2, r3
	ldr r0, _080F764C @ =0xFFFFF67F
	ands r2, r0
	strh r2, [r1]
	b _080F77A4
	.align 2, 0
_080F7624: .4byte 0x00000482
_080F7628: .4byte 0x00000222
_080F762C: .4byte 0x0000024E
_080F7630: .4byte 0xFFFFFC7F
_080F7634: .4byte 0xF3FFFFFF
_080F7638: .4byte 0xFEFFFFFF
_080F763C: .4byte 0xFFFFFDFF
_080F7640: .4byte 0x00000542
_080F7644: .4byte 0xFBFFFFFF
_080F7648: .4byte 0xFFFFDAFF
_080F764C: .4byte 0xFFFFF67F
_080F7650:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080F767C
	ldr r0, _080F7678 @ =0xFFFFDAFF
	ands r0, r2
	strh r0, [r7]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	mov r5, sb
	orrs r0, r5
	b _080F779E
	.align 2, 0
_080F7678: .4byte 0xFFFFDAFF
_080F767C:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _080F7686
	b _080F77A4
_080F7686:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080F787C @ =0xFFFEBE3F
	ands r0, r2
	str r0, [r1]
	ldr r3, [sp, #0x40]
	strh r5, [r3]
	ldr r4, [sp, #0x24]
	strh r5, [r4]
	ldr r0, [sp, #0x3c]
	strh r5, [r0]
	ldr r1, _080F7880 @ =0x00000482
	adds r3, r6, r1
	movs r0, #1
	strh r0, [r3]
	ldr r2, _080F7884 @ =0x00000222
	adds r0, r6, r2
	strh r5, [r0]
	ldr r4, _080F7888 @ =0x0000024E
	adds r0, r6, r4
	strh r5, [r0]
	ldr r0, _080F788C @ =0xFFFFFC7F
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F7890 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #0xe
	ands r0, r4
	cmp r0, #0
	beq _080F76F4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F7894 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7898 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	ldr r4, [sp, #0x40]
	strh r5, [r4]
	ldr r0, [sp, #0x3c]
	strh r5, [r0]
_080F76F4:
	ldrh r1, [r7]
	ldr r0, _080F789C @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r7]
	ldr r1, _080F78A0 @ =0x00000542
	adds r1, r1, r6
	mov sb, r1
	movs r2, #1
	rsbs r2, r2, #0
	add r4, sp, #0x28
	strb r2, [r4]
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _080F78A4 @ =0xFFFFDAFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r0, #6
	strh r0, [r3]
	ldrh r0, [r7]
	mov r2, sl
	ands r0, r2
	cmp r0, #0
	beq _080F7742
	movs r3, #0x97
	lsls r3, r3, #3
	adds r4, r6, r3
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	mov r1, sl
	bics r0, r1
	strh r0, [r7]
	str r5, [r4]
_080F7742:
	mov r2, r8
	ldr r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #0xe
	ands r0, r3
	cmp r0, #0
	beq _080F7778
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r6, r4
	ldr r1, _080F7894 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F7898 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, [sp, #0x40]
	strh r5, [r3]
	ldr r4, [sp, #0x3c]
	strh r5, [r4]
_080F7778:
	ldrh r1, [r7]
	ldr r0, _080F789C @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r7]
	mov r5, sb
	ldrb r0, [r5]
	add r1, sp, #0x28
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r5]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r0, r1
	movs r4, #0
	orrs r0, r4
_080F779E:
	ldr r1, _080F78A8 @ =0xFFFFF67F
	ands r0, r1
	strh r0, [r2]
_080F77A4:
	ldr r0, _080F78AC @ =0x0000803E
	ldrh r1, [r7]
	ands r0, r1
	cmp r0, #0
	bne _080F77B0
	b _080F78CE
_080F77B0:
	ldr r0, _080F78B0 @ =0xFFFFFDFE
	ands r0, r1
	movs r5, #0
	mov sl, r5
	strh r0, [r7]
	ldr r0, _080F78B4 @ =0xF7FFBFFF
	mov r1, r8
	ldr r2, [r1]
	ands r2, r0
	str r2, [r1]
	movs r1, #0x20
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	bne _080F77D8
	movs r0, #0x81
	rsbs r0, r0, #0
	ands r2, r0
	mov r3, r8
	str r2, [r3]
_080F77D8:
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r5, r6, r4
	ldr r0, _080F78B8 @ =0xFFEFFFFB
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #5
	mov sb, r0
	ldrh r0, [r7]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _080F780E
	movs r2, #0x97
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r7]
	mov r3, sb
	bics r0, r3
	strh r0, [r7]
	mov r0, sl
	str r0, [r4]
_080F780E:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F7840
	ldr r1, _080F7894 @ =0xFEFFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r0, _080F7898 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r3, #0x87
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r4, #0
	strb r4, [r0]
	mov r0, sl
	ldr r5, [sp, #0x40]
	strh r0, [r5]
	ldr r1, [sp, #0x3c]
	strh r0, [r1]
_080F7840:
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r7]
	bics r0, r1
	strh r0, [r7]
	ldr r3, _080F78A0 @ =0x00000542
	adds r2, r6, r3
	movs r0, #0xff
	strb r0, [r2]
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	movs r0, #0
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	movs r1, #0x10
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080F78C0
	ldr r1, _080F78BC @ =0xFFFFDFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F78D8
	.align 2, 0
_080F787C: .4byte 0xFFFEBE3F
_080F7880: .4byte 0x00000482
_080F7884: .4byte 0x00000222
_080F7888: .4byte 0x0000024E
_080F788C: .4byte 0xFFFFFC7F
_080F7890: .4byte 0xF3FFFFFF
_080F7894: .4byte 0xFEFFFFFF
_080F7898: .4byte 0xFFFFFDFF
_080F789C: .4byte 0xFFFFFBFF
_080F78A0: .4byte 0x00000542
_080F78A4: .4byte 0xFFFFDAFF
_080F78A8: .4byte 0xFFFFF67F
_080F78AC: .4byte 0x0000803E
_080F78B0: .4byte 0xFFFFFDFE
_080F78B4: .4byte 0xF7FFBFFF
_080F78B8: .4byte 0xFFEFFFFB
_080F78BC: .4byte 0xFFFFDFFF
_080F78C0:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, r8
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	b _080F78D8
_080F78CE:
	ldr r1, _080F7928 @ =0xFFFFDFFF
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080F78D8:
	movs r3, #0x80
	lsls r3, r3, #3
	ldrh r0, [r7]
	ands r0, r3
	cmp r0, #0
	beq _080F790A
	ldr r5, _080F792C @ =0x00000542
	adds r1, r6, r5
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080F7900
	ldr r4, _080F7930 @ =0x00000553
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080F790A
	cmp r0, #2
	beq _080F790A
_080F7900:
	movs r0, #0xff
	strb r0, [r1]
	ldrh r0, [r7]
	bics r0, r3
	strh r0, [r7]
_080F790A:
	movs r0, #0x80
	ldrh r3, [r7]
	adds r2, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080F795C
	ldr r5, _080F7934 @ =0x000001DF
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080F793C
	ldr r7, _080F7938 @ =0x00000482
	adds r1, r6, r7
	b _080F798E
	.align 2, 0
_080F7928: .4byte 0xFFFFDFFF
_080F792C: .4byte 0x00000542
_080F7930: .4byte 0x00000553
_080F7934: .4byte 0x000001DF
_080F7938: .4byte 0x00000482
_080F793C:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080F7950
	ldr r0, _080F794C @ =0x00000482
	adds r1, r6, r0
	b _080F798E
	.align 2, 0
_080F794C: .4byte 0x00000482
_080F7950:
	ldr r2, _080F7958 @ =0x00000482
	adds r1, r6, r2
	b _080F799C
	.align 2, 0
_080F7958: .4byte 0x00000482
_080F795C:
	movs r1, #0x90
	lsls r1, r1, #5
	ands r1, r2
	cmp r1, #0
	beq _080F79A8
	ldr r3, _080F7978 @ =0x000001DF
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080F7980
	ldr r4, _080F797C @ =0x00000482
	adds r1, r6, r4
	b _080F798E
	.align 2, 0
_080F7978: .4byte 0x000001DF
_080F797C: .4byte 0x00000482
_080F7980:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080F7998
	ldr r5, _080F7994 @ =0x00000482
	adds r1, r6, r5
_080F798E:
	movs r0, #2
	strh r0, [r1]
	b _080F79CC
	.align 2, 0
_080F7994: .4byte 0x00000482
_080F7998:
	ldr r7, _080F79A4 @ =0x00000482
	adds r1, r6, r7
_080F799C:
	movs r0, #3
	strh r0, [r1]
	b _080F79CC
	.align 2, 0
_080F79A4: .4byte 0x00000482
_080F79A8:
	ldr r0, _080F79D8 @ =0xFFFFFBFF
	ands r0, r3
	movs r2, #0
	strh r0, [r7]
	ldr r3, _080F79DC @ =0x00000222
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, _080F79E0 @ =0x00000542
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	movs r5, #0xa8
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r2, [r0]
	ldr r7, _080F79E4 @ =0x00000541
	adds r0, r6, r7
	strb r2, [r0]
_080F79CC:
	adds r0, r6, #0
	bl FUN_080f6e34
	bl FUN_080f83ec
	.align 2, 0
_080F79D8: .4byte 0xFFFFFBFF
_080F79DC: .4byte 0x00000222
_080F79E0: .4byte 0x00000542
_080F79E4: .4byte 0x00000541
