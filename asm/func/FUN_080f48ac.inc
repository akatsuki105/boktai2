	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r2, [sp]
	ldr r6, [r0, #0x38]
	cmp r1, #0
	beq _080F48CC
	cmp r1, #1
	bne _080F48C8
	bl FUN_080f5104
_080F48C8:
	bl _080F51E0
_080F48CC:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r5, r1, #0
	cmp r7, #0
	beq _080F48E6
	b _080F506C
_080F48E6:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r1, #6]
	movs r2, #4
	movs r3, #0
	mov sb, r3
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r6, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	ldr r2, _080F497C @ =0x080F46A5
	movs r1, #0x1f
	ldr r3, _080F4980 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	mov sl, r3
	mov r3, sl
	strb r3, [r0]
	ldr r3, _080F4984 @ =0x0000046B
	adds r0, r6, r3
	mov r3, sb
	strb r3, [r0]
	ldr r0, _080F4988 @ =0x00000553
	adds r3, r6, r0
	strb r1, [r3]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r7, [r0]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _080F498C @ =0x00000469
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _080F4990 @ =0x00000484
	adds r0, r6, r2
	str r7, [r0]
	adds r1, #2
	adds r0, r6, r1
	mov r2, sl
	strb r2, [r0]
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #8
	orrs r0, r1
	mov r1, sb
	orrs r0, r1
	strh r0, [r5]
	str r3, [sp, #0x10]
	cmp r0, #0
	bne _080F4998
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F4994 @ =0xFFFFDFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F506C
	.align 2, 0
_080F497C: .4byte 0x080F46A5
_080F4980: .4byte 0x0000046D
_080F4984: .4byte 0x0000046B
_080F4988: .4byte 0x00000553
_080F498C: .4byte 0x00000469
_080F4990: .4byte 0x00000484
_080F4994: .4byte 0xFFFFDFFF
_080F4998:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080F4A38
	movs r0, #0x80
	lsls r0, r0, #5
	mov r8, r0
	ldrh r0, [r5]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _080F49CC
	movs r2, #0x97
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r5]
	mov r3, r8
	bics r0, r3
	strh r0, [r5]
	str r7, [r4]
_080F49CC:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F4A0A
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F4A28 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F4A2C @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r3, #0xa2
	adds r0, r6, r3
	strh r7, [r0]
	subs r1, #0x1a
	adds r0, r6, r1
	strh r7, [r0]
_080F4A0A:
	movs r0, #0x40
	strh r0, [r5]
	ldr r2, _080F4A30 @ =0x0000048C
	adds r0, r6, r2
	mov r3, sb
	strb r3, [r0]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r0, _080F4A34 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080F506C
	.align 2, 0
_080F4A28: .4byte 0xFEFFFFFF
_080F4A2C: .4byte 0xFFFFFDFF
_080F4A30: .4byte 0x0000048C
_080F4A34: .4byte 0xFFFFF67F
_080F4A38:
	movs r7, #0x80
	lsls r7, r7, #6
	ldrh r0, [r5]
	mov r8, r0
	mov r2, r8
	adds r0, r2, #0
	ands r0, r7
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080F4B18
	ldr r1, _080F4AEC @ =0x00000482
	adds r7, r6, r1
	mov r2, sl
	strh r2, [r7]
	ldr r3, _080F4AF0 @ =0x00000222
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _080F4AF4 @ =0x0000024E
	adds r0, r6, r1
	strh r4, [r0]
	ldr r0, _080F4AF8 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	subs r3, #0xaa
	adds r2, r6, r3
	ldr r1, _080F4AFC @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _080F4AAE
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F4B00 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F4B04 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r3, #0xa6
	adds r0, r6, r3
	strh r4, [r0]
	subs r1, #0x1a
	adds r0, r6, r1
	strh r4, [r0]
_080F4AAE:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r5]
	bics r0, r2
	strh r0, [r5]
	ldr r3, _080F4B08 @ =0x00000542
	adds r1, r6, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F4B0C @ =0xFBFFFFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080F4B10 @ =0xFFFFFAFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	mov r1, sl
	strh r1, [r7]
	ldr r0, _080F4B14 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080F4E54
	.align 2, 0
_080F4AEC: .4byte 0x00000482
_080F4AF0: .4byte 0x00000222
_080F4AF4: .4byte 0x0000024E
_080F4AF8: .4byte 0xFFFFFC7F
_080F4AFC: .4byte 0xF3FFFFFF
_080F4B00: .4byte 0xFEFFFFFF
_080F4B04: .4byte 0xFFFFFDFF
_080F4B08: .4byte 0x00000542
_080F4B0C: .4byte 0xFBFFFFFF
_080F4B10: .4byte 0xFFFFFAFF
_080F4B14: .4byte 0xFFFFF67F
_080F4B18:
	adds r0, r2, #0
	movs r1, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080F4C00
	ldr r2, _080F4BD0 @ =0x00000482
	adds r4, r6, r2
	mov r0, sl
	strh r0, [r4]
	ldr r1, _080F4BD4 @ =0x00000222
	adds r0, r6, r1
	strh r3, [r0]
	ldr r2, _080F4BD8 @ =0x0000024E
	adds r0, r6, r2
	strh r3, [r0]
	ldr r0, _080F4BDC @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F4BE0 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _080F4B88
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _080F4BE4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F4BE8 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r6, r2
	mov r1, sb
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r3, [r0]
	ldr r1, _080F4BEC @ =0x00000202
	adds r0, r6, r1
	strh r3, [r0]
_080F4B88:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r5]
	bics r0, r2
	strh r0, [r5]
	ldr r3, _080F4BF0 @ =0x00000542
	adds r1, r6, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F4BF4 @ =0xFBFFFFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080F4BF8 @ =0xFFFFDAFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	mov r1, sl
	strh r1, [r4]
	ldr r0, _080F4BFC @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r7
	str r0, [r2]
	b _080F4E54
	.align 2, 0
_080F4BD0: .4byte 0x00000482
_080F4BD4: .4byte 0x00000222
_080F4BD8: .4byte 0x0000024E
_080F4BDC: .4byte 0xFFFFFC7F
_080F4BE0: .4byte 0xF3FFFFFF
_080F4BE4: .4byte 0xFEFFFFFF
_080F4BE8: .4byte 0xFFFFFDFF
_080F4BEC: .4byte 0x00000202
_080F4BF0: .4byte 0x00000542
_080F4BF4: .4byte 0xFBFFFFFF
_080F4BF8: .4byte 0xFFFFDAFF
_080F4BFC: .4byte 0xFFFFF67F
_080F4C00:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080F4CD0
	ldr r3, _080F4CA4 @ =0x00000482
	adds r0, r6, r3
	mov r7, sl
	strh r7, [r0]
	ldr r1, _080F4CA8 @ =0x00000222
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _080F4CAC @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	ldr r0, _080F4CB0 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F4CB4 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _080F4C6A
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, _080F4CB8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F4CBC @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r3, #0xa6
	adds r0, r6, r3
	strh r4, [r0]
	adds r7, #0x86
	adds r0, r6, r7
	strh r4, [r0]
_080F4C6A:
	movs r2, #0x80
	lsls r2, r2, #3
	ldrh r0, [r5]
	bics r0, r2
	strh r0, [r5]
	ldr r0, _080F4CC0 @ =0x00000542
	adds r1, r6, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F4CC4 @ =0xFBFFFFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080F4CC8 @ =0xFFFFDAFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r1, r6, r7
	ldrh r0, [r1]
	orrs r2, r0
	mov r0, sb
	orrs r2, r0
	ldr r0, _080F4CCC @ =0xFFFFF67F
	ands r2, r0
	strh r2, [r1]
	b _080F4E54
	.align 2, 0
_080F4CA4: .4byte 0x00000482
_080F4CA8: .4byte 0x00000222
_080F4CAC: .4byte 0x0000024E
_080F4CB0: .4byte 0xFFFFFC7F
_080F4CB4: .4byte 0xF3FFFFFF
_080F4CB8: .4byte 0xFEFFFFFF
_080F4CBC: .4byte 0xFFFFFDFF
_080F4CC0: .4byte 0x00000542
_080F4CC4: .4byte 0xFBFFFFFF
_080F4CC8: .4byte 0xFFFFDAFF
_080F4CCC: .4byte 0xFFFFF67F
_080F4CD0:
	adds r0, r2, #0
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq _080F4D14
	ldr r0, _080F4D0C @ =0xFFFFDAFF
	mov r2, r8
	ands r0, r2
	strh r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	mov r7, sb
	orrs r0, r7
	ldr r1, _080F4D10 @ =0xFFFFF67F
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	b _080F4E54
	.align 2, 0
_080F4D0C: .4byte 0xFFFFDAFF
_080F4D10: .4byte 0xFFFFF67F
_080F4D14:
	movs r0, #0x10
	ands r2, r0
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r1, r1, r6
	mov r8, r1
	cmp r2, #0
	bne _080F4D26
	b _080F4E54
_080F4D26:
	ldr r1, _080F4F2C @ =0xFFFEBE3F
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r3, _080F4F30 @ =0x0000021E
	adds r3, r6, r3
	str r3, [sp, #4]
	strh r7, [r3]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r7, [r0]
	ldr r2, _080F4F34 @ =0x00000202
	adds r2, r6, r2
	str r2, [sp, #8]
	strh r7, [r2]
	ldr r0, _080F4F38 @ =0x00000482
	adds r3, r6, r0
	mov r1, sl
	strh r1, [r3]
	ldr r2, _080F4F3C @ =0x00000222
	adds r0, r6, r2
	strh r7, [r0]
	ldr r1, _080F4F40 @ =0x0000024E
	adds r0, r6, r1
	strh r7, [r0]
	ldr r0, _080F4F44 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r1, _080F4F48 @ =0xF3FFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F4DA0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F4F4C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F4F50 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	ldr r0, [sp, #4]
	strh r7, [r0]
	ldr r1, [sp, #8]
	strh r7, [r1]
_080F4DA0:
	ldrh r1, [r5]
	ldr r0, _080F4F54 @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r5]
	ldr r2, _080F4F58 @ =0x00000542
	adds r2, r2, r6
	mov sl, r2
	movs r1, #1
	rsbs r1, r1, #0
	mov r0, sp
	strb r1, [r0, #0xc]
	movs r0, #0xff
	strb r0, [r2]
	ldr r0, _080F4F5C @ =0xFFFFDAFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r7, [r0]
	movs r0, #6
	strh r0, [r3]
	ldrh r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #5
	ands r0, r3
	cmp r0, #0
	beq _080F4DF2
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #5
	bics r0, r1
	strh r0, [r5]
	str r7, [r4]
_080F4DF2:
	mov r2, r8
	ldr r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #0xe
	ands r0, r3
	cmp r0, #0
	beq _080F4E28
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _080F4F4C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F4F50 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, [sp, #4]
	strh r7, [r3]
	ldr r0, [sp, #8]
	strh r7, [r0]
_080F4E28:
	ldrh r1, [r5]
	ldr r0, _080F4F54 @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r5]
	mov r1, sl
	ldrb r0, [r1]
	mov r2, sp
	ldrb r2, [r2, #0xc]
	orrs r0, r2
	strb r0, [r1]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r0, r1
	mov r7, sb
	orrs r0, r7
	ldr r1, _080F4F60 @ =0xFFFFF67F
	ands r0, r1
	strh r0, [r2]
_080F4E54:
	ldr r0, _080F4F64 @ =0x0000803E
	ldrh r1, [r5]
	ands r0, r1
	cmp r0, #0
	bne _080F4E60
	b _080F4F8A
_080F4E60:
	ldr r0, _080F4F68 @ =0xFFFFFDFE
	ands r0, r1
	movs r1, #0
	mov sl, r1
	strh r0, [r5]
	ldr r0, _080F4F6C @ =0xF7FFBFFF
	mov r3, r8
	ldr r2, [r3]
	ands r2, r0
	str r2, [r3]
	movs r1, #0x20
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	bne _080F4E86
	movs r0, #0x81
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
_080F4E86:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r7, r6, r0
	ldr r0, _080F4F70 @ =0xFFEFFFFB
	ldr r1, [r7]
	ands r1, r0
	str r1, [r7]
	movs r1, #0x80
	lsls r1, r1, #5
	mov sb, r1
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _080F4EBA
	movs r2, #0x97
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r5]
	mov r3, sb
	bics r0, r3
	strh r0, [r5]
	mov r0, sl
	str r0, [r4]
_080F4EBA:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F4EF0
	ldr r1, _080F4F4C @ =0xFEFFFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r0, _080F4F50 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r3, #0x87
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r7, #0
	strb r7, [r0]
	ldr r1, _080F4F30 @ =0x0000021E
	adds r0, r6, r1
	mov r2, sl
	strh r2, [r0]
	subs r3, #0x1a
	adds r0, r6, r3
	strh r2, [r0]
_080F4EF0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r5]
	bics r0, r1
	strh r0, [r5]
	ldr r7, _080F4F58 @ =0x00000542
	adds r2, r6, r7
	movs r0, #0xff
	strb r0, [r2]
	adds r0, #0x83
	adds r2, r6, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	ldr r1, _080F4F74 @ =0x0000048C
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	movs r1, #0x10
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _080F4F7C
	ldr r1, _080F4F78 @ =0xFFFFDFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	b _080F4F94
	.align 2, 0
_080F4F2C: .4byte 0xFFFEBE3F
_080F4F30: .4byte 0x0000021E
_080F4F34: .4byte 0x00000202
_080F4F38: .4byte 0x00000482
_080F4F3C: .4byte 0x00000222
_080F4F40: .4byte 0x0000024E
_080F4F44: .4byte 0xFFFFFC7F
_080F4F48: .4byte 0xF3FFFFFF
_080F4F4C: .4byte 0xFEFFFFFF
_080F4F50: .4byte 0xFFFFFDFF
_080F4F54: .4byte 0xFFFFFBFF
_080F4F58: .4byte 0x00000542
_080F4F5C: .4byte 0xFFFFDAFF
_080F4F60: .4byte 0xFFFFF67F
_080F4F64: .4byte 0x0000803E
_080F4F68: .4byte 0xFFFFFDFE
_080F4F6C: .4byte 0xF7FFBFFF
_080F4F70: .4byte 0xFFEFFFFB
_080F4F74: .4byte 0x0000048C
_080F4F78: .4byte 0xFFFFDFFF
_080F4F7C:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r7, r8
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	b _080F4F94
_080F4F8A:
	ldr r1, _080F4FE0 @ =0xFFFFDFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_080F4F94:
	movs r4, #0x80
	lsls r4, r4, #3
	ldrh r0, [r5]
	ands r0, r4
	cmp r0, #0
	beq _080F4FC4
	ldr r3, _080F4FE4 @ =0x00000542
	adds r1, r6, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080F4FBA
	ldr r7, [sp, #0x10]
	ldrb r3, [r7]
	cmp r3, #0x1b
	beq _080F4FC4
	cmp r3, #2
	beq _080F4FC4
_080F4FBA:
	movs r0, #0xff
	strb r0, [r1]
	ldrh r0, [r5]
	bics r0, r4
	strh r0, [r5]
_080F4FC4:
	movs r0, #0x80
	ldrh r3, [r5]
	adds r2, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080F4FFC
	ldr r1, _080F4FE8 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080F4FF0
	ldr r2, _080F4FEC @ =0x00000482
	adds r1, r6, r2
	b _080F502E
	.align 2, 0
_080F4FE0: .4byte 0xFFFFDFFF
_080F4FE4: .4byte 0x00000542
_080F4FE8: .4byte 0x000001DF
_080F4FEC: .4byte 0x00000482
_080F4FF0:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080F502A
	b _080F5038
_080F4FFC:
	movs r1, #0x90
	lsls r1, r1, #5
	ands r1, r2
	cmp r1, #0
	beq _080F5048
	ldr r1, _080F5018 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080F5020
	ldr r2, _080F501C @ =0x00000482
	adds r1, r6, r2
	b _080F502E
	.align 2, 0
_080F5018: .4byte 0x000001DF
_080F501C: .4byte 0x00000482
_080F5020:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080F5038
_080F502A:
	ldr r3, _080F5034 @ =0x00000482
	adds r1, r6, r3
_080F502E:
	movs r0, #2
	strh r0, [r1]
	b _080F506C
	.align 2, 0
_080F5034: .4byte 0x00000482
_080F5038:
	ldr r7, _080F5044 @ =0x00000482
	adds r1, r6, r7
	movs r0, #3
	strh r0, [r1]
	b _080F506C
	.align 2, 0
_080F5044: .4byte 0x00000482
_080F5048:
	ldr r0, _080F50B8 @ =0xFFFFFBFF
	ands r0, r3
	movs r2, #0
	strh r0, [r5]
	ldr r3, _080F50BC @ =0x00000222
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _080F50C0 @ =0x00000542
	adds r1, r6, r7
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _080F50C4 @ =0x00000541
	adds r0, r6, r3
	strb r2, [r0]
_080F506C:
	movs r7, #0x8c
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r1, #0
	movs r2, #0
	strh r2, [r0]
	ldr r0, [sp]
	cmp r0, #0
	beq _080F50D0
	ldr r1, _080F50C8 @ =0x0000048A
	adds r0, r6, r1
	mov r3, sp
	ldrh r3, [r3]
	strh r3, [r0]
	ldr r7, _080F50CC @ =0x0000048C
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #3
	adds r0, r6, r3
	str r1, [r0]
	adds r7, #0x10
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r0, #0x20
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080F51E0
	.align 2, 0
_080F50B8: .4byte 0xFFFFFBFF
_080F50BC: .4byte 0x00000222
_080F50C0: .4byte 0x00000542
_080F50C4: .4byte 0x00000541
_080F50C8: .4byte 0x0000048A
_080F50CC: .4byte 0x0000048C
_080F50D0:
	ldr r7, _080F50F8 @ =0x0000048A
	adds r0, r6, r7
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r0]
	ldr r3, _080F50FC @ =0x0000048C
	adds r0, r6, r3
	strb r1, [r0]
	adds r7, #0x16
	adds r0, r6, r7
	ldr r1, [sp]
	str r1, [r0]
	ldr r2, _080F5100 @ =0x0000049C
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #0xc
	adds r0, r6, r3
	str r1, [r0]
	b _080F51E0
	.align 2, 0
_080F50F8: .4byte 0x0000048A
_080F50FC: .4byte 0x0000048C
_080F5100: .4byte 0x0000049C
