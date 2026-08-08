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
	beq _08228B78
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08228B74 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _08228B7A
	.align 2, 0
_08228B74: .4byte 0x00000F14
_08228B78:
	movs r0, #0
_08228B7A:
	cmp r0, #0
	beq _08228BAE
	ldr r3, _08228BE4 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, _08228BE8 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _08228BEC @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #0xa
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08228BF0 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	ldr r0, _08228BF4 @ =0x0000011F
	bl PlaySound_082406e0
_08228BAE:
	ldr r2, _08228BF8 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _08228BE8 @ =0x00000DE4
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
	beq _08228BFC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08228C04
	.align 2, 0
_08228BE4: .4byte 0x00000F15
_08228BE8: .4byte 0x00000DE4
_08228BEC: .4byte 0x00000E34
_08228BF0: .4byte 0x00000DF4
_08228BF4: .4byte 0x0000011F
_08228BF8: .4byte 0x00000D9C
_08228BFC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08228C04:
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
	beq _08228C28
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08228C30
_08228C28:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08228C30:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08228C68 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08228CAE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08228C72
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08228C6C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08228C88
	.align 2, 0
_08228C68: .4byte 0x0000FFFF
_08228C6C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08228C86
_08228C72:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08228C86
	strh r1, [r4, #8]
	movs r2, #1
	b _08228C88
_08228C86:
	movs r2, #0
_08228C88:
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
	bne _08228CB0
	movs r0, #1
	strb r0, [r4, #7]
	b _08228CB0
_08228CAE:
	movs r2, #0
_08228CB0:
	ldr r3, _08228D64 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	cmp r2, #0
	beq _08228D5C
	ldr r1, _08228D68 @ =0x00000F32
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08228CC8
	bl FUN_080a6edc
_08228CC8:
	ldr r3, _08228D6C @ =0x00000D9C
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08228D70 @ =0x00000F16
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08228D74 @ =0x00000F18
	adds r3, r6, r1
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08228D28
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08228D28
	ldr r2, _08228D78 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _08228D7C @ =0x00000F42
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _08228D80 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08228D84 @ =0x00000F43
	adds r0, r6, r2
	strb r1, [r0]
_08228D28:
	movs r0, #1
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r7, #4
	ldr r4, _08228D88 @ =FUN_08224dd0
	movs r5, #1
	adds r1, r6, #0
	adds r1, #0xc4
	movs r3, #0xf
_08228D42:
	ldrb r2, [r1, #5]
	adds r0, r7, #0
	ands r0, r2
	cmp r0, #0
	beq _08228D54
	str r4, [r1]
	adds r0, r5, #0
	orrs r0, r2
	strb r0, [r1, #5]
_08228D54:
	adds r1, #0xd8
	subs r3, #1
	cmp r3, #0
	bge _08228D42
_08228D5C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08228D64: .4byte 0x00000F14
_08228D68: .4byte 0x00000F32
_08228D6C: .4byte 0x00000D9C
_08228D70: .4byte 0x00000F16
_08228D74: .4byte 0x00000F18
_08228D78: .4byte 0x00000DEC
_08228D7C: .4byte 0x00000F42
_08228D80: .4byte 0x00000DF2
_08228D84: .4byte 0x00000F43
_08228D88: .4byte FUN_08224dd0
