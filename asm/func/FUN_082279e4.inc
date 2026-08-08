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
	beq _08227A14
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08227A10 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _08227A16
	.align 2, 0
_08227A10: .4byte 0x00000F14
_08227A14:
	movs r0, #0
_08227A16:
	cmp r0, #0
	beq _08227A50
	ldr r3, _08227A94 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #2
	strb r0, [r1]
	ldr r1, _08227A98 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _08227A9C @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _08227AA0 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_082239fc
_08227A50:
	ldr r2, _08227AA4 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08227A60
	adds r0, r6, #0
	bl _call_via_r1
_08227A60:
	ldr r0, _08227AA8 @ =0x00000D9C
	adds r3, r6, r0
	ldr r2, _08227AAC @ =0x00000E38
	adds r1, r6, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08227B0A
	ldr r2, _08227AB0 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _08227AB8
	cmp r2, #1
	bge _08227AE0
	cmp r2, #0
	beq _08227AC0
	ldr r0, _08227AB4 @ =0x00000E3A
	adds r1, r6, r0
	b _08227B00
	.align 2, 0
_08227A94: .4byte 0x00000F15
_08227A98: .4byte 0x00000DE4
_08227A9C: .4byte 0x00000E34
_08227AA0: .4byte 0x00000DF4
_08227AA4: .4byte 0x00000F4C
_08227AA8: .4byte 0x00000D9C
_08227AAC: .4byte 0x00000E38
_08227AB0: .4byte 0x00000DEC
_08227AB4: .4byte 0x00000E3A
_08227AB8:
	ldr r0, _08227AD4 @ =0x00000E3A
	adds r1, r6, r0
	cmp r2, #3
	bne _08227B00
_08227AC0:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08227AD8
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08227AFE
	.align 2, 0
_08227AD4: .4byte 0x00000E3A
_08227AD8:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08227AFE
_08227AE0:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08227AF8
	ldr r2, _08227AF4 @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
	b _08227AFE
	.align 2, 0
_08227AF4: .4byte 0x00000E3A
_08227AF8:
	ldr r0, _08227B40 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #8
_08227AFE:
	strb r0, [r1]
_08227B00:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08227B0A:
	ldr r2, _08227B44 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _08227B48 @ =0x00000DE4
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
	beq _08227B4C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08227B54
	.align 2, 0
_08227B40: .4byte 0x00000E3A
_08227B44: .4byte 0x00000D9C
_08227B48: .4byte 0x00000DE4
_08227B4C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08227B54:
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
	beq _08227B78
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08227B80
_08227B78:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08227B80:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08227BB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08227BFE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08227BC2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08227BBC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08227BD8
	.align 2, 0
_08227BB8: .4byte 0x0000FFFF
_08227BBC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08227BD6
_08227BC2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08227BD6
	strh r1, [r4, #8]
	movs r2, #1
	b _08227BD8
_08227BD6:
	movs r2, #0
_08227BD8:
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
	bne _08227C00
	movs r0, #1
	strb r0, [r4, #7]
	b _08227C00
_08227BFE:
	movs r2, #0
_08227C00:
	ldr r3, _08227C10 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08227C10: .4byte 0x00000F14
