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
	beq _082280A4
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _082280A0 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _082280A6
	.align 2, 0
_082280A0: .4byte 0x00000F14
_082280A4:
	movs r0, #0
_082280A6:
	cmp r0, #0
	beq _082280E0
	ldr r3, _08228124 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #5
	strb r0, [r1]
	ldr r1, _08228128 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _0822812C @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _08228130 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_082239fc
_082280E0:
	ldr r2, _08228134 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _082280F0
	adds r0, r6, #0
	bl _call_via_r1
_082280F0:
	ldr r0, _08228138 @ =0x00000D9C
	adds r3, r6, r0
	ldr r2, _0822813C @ =0x00000E38
	adds r1, r6, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _0822819A
	ldr r2, _08228140 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _08228148
	cmp r2, #1
	bge _08228170
	cmp r2, #0
	beq _08228150
	ldr r0, _08228144 @ =0x00000E3A
	adds r1, r6, r0
	b _08228190
	.align 2, 0
_08228124: .4byte 0x00000F15
_08228128: .4byte 0x00000DE4
_0822812C: .4byte 0x00000E34
_08228130: .4byte 0x00000DF4
_08228134: .4byte 0x00000F4C
_08228138: .4byte 0x00000D9C
_0822813C: .4byte 0x00000E38
_08228140: .4byte 0x00000DEC
_08228144: .4byte 0x00000E3A
_08228148:
	ldr r0, _08228164 @ =0x00000E3A
	adds r1, r6, r0
	cmp r2, #3
	bne _08228190
_08228150:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228168
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _0822818E
	.align 2, 0
_08228164: .4byte 0x00000E3A
_08228168:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _0822818E
_08228170:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228188
	ldr r2, _08228184 @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
	b _0822818E
	.align 2, 0
_08228184: .4byte 0x00000E3A
_08228188:
	ldr r0, _082281D0 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #8
_0822818E:
	strb r0, [r1]
_08228190:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_0822819A:
	ldr r2, _082281D4 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _082281D8 @ =0x00000DE4
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
	beq _082281DC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _082281E4
	.align 2, 0
_082281D0: .4byte 0x00000E3A
_082281D4: .4byte 0x00000D9C
_082281D8: .4byte 0x00000DE4
_082281DC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082281E4:
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
	beq _08228208
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08228210
_08228208:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08228210:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08228248 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0822828E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08228252
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0822824C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08228268
	.align 2, 0
_08228248: .4byte 0x0000FFFF
_0822824C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08228266
_08228252:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08228266
	strh r1, [r4, #8]
	movs r2, #1
	b _08228268
_08228266:
	movs r2, #0
_08228268:
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
	bne _08228290
	movs r0, #1
	strb r0, [r4, #7]
	b _08228290
_0822828E:
	movs r2, #0
_08228290:
	ldr r3, _082282A0 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082282A0: .4byte 0x00000F14
