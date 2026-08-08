	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08228948
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08228944 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _0822894A
	.align 2, 0
_08228944: .4byte 0x00000F14
_08228948:
	movs r0, #0
_0822894A:
	cmp r0, #0
	beq _08228984
	ldr r3, _082289C8 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #9
	strb r0, [r1]
	ldr r1, _082289CC @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _082289D0 @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #9
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _082289D4 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_082239fc
_08228984:
	ldr r2, _082289D8 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08228994
	adds r0, r6, #0
	bl _call_via_r1
_08228994:
	ldr r0, _082289DC @ =0x00000D9C
	adds r3, r6, r0
	ldr r2, _082289E0 @ =0x00000E38
	adds r1, r6, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08228A3E
	ldr r2, _082289E4 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _082289EC
	cmp r2, #1
	bge _08228A14
	cmp r2, #0
	beq _082289F4
	ldr r0, _082289E8 @ =0x00000E3A
	adds r1, r6, r0
	b _08228A34
	.align 2, 0
_082289C8: .4byte 0x00000F15
_082289CC: .4byte 0x00000DE4
_082289D0: .4byte 0x00000E34
_082289D4: .4byte 0x00000DF4
_082289D8: .4byte 0x00000F4C
_082289DC: .4byte 0x00000D9C
_082289E0: .4byte 0x00000E38
_082289E4: .4byte 0x00000DEC
_082289E8: .4byte 0x00000E3A
_082289EC:
	ldr r0, _08228A08 @ =0x00000E3A
	adds r1, r6, r0
	cmp r2, #3
	bne _08228A34
_082289F4:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228A0C
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08228A32
	.align 2, 0
_08228A08: .4byte 0x00000E3A
_08228A0C:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08228A32
_08228A14:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228A2C
	ldr r2, _08228A28 @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
	b _08228A32
	.align 2, 0
_08228A28: .4byte 0x00000E3A
_08228A2C:
	ldr r0, _08228A74 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #8
_08228A32:
	strb r0, [r1]
_08228A34:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08228A3E:
	ldr r2, _08228A78 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _08228A7C @ =0x00000DE4
	adds r4, r6, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08228A80
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08228A88
	.align 2, 0
_08228A74: .4byte 0x00000E3A
_08228A78: .4byte 0x00000D9C
_08228A7C: .4byte 0x00000DE4
_08228A80:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08228A88:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08228AAC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08228AB4
_08228AAC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08228AB4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08228AEC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08228B32
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08228AF6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08228AF0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08228B0C
	.align 2, 0
_08228AEC: .4byte 0x0000FFFF
_08228AF0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08228B0A
_08228AF6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08228B0A
	strh r1, [r4, #8]
	movs r2, #1
	b _08228B0C
_08228B0A:
	movs r2, #0
_08228B0C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08228B34
	movs r0, #1
	strb r0, [r4, #7]
	b _08228B34
_08228B32:
	movs r2, #0
_08228B34:
	ldr r3, _08228B44 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08228B44: .4byte 0x00000F14
