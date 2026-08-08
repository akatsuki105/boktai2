	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _08070B58 @ =0x000009C8
	adds r5, r4, r0
	ldr r1, _08070B5C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08070B60 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0806f900
	adds r7, r0, #0
	adds r0, r4, #0
	bl FUN_0806f960
	adds r6, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08070B6C
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x1d
	strh r0, [r1]
	ldr r0, _08070B64 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #7
	strh r0, [r1]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _08070B68 @ =0x00000A86
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r6, r0
	b _08070BCA
	.align 2, 0
_08070B58: .4byte 0x000009C8
_08070B5C: .4byte 0x00000A68
_08070B60: .4byte 0x00000A6A
_08070B64: .4byte 0x00000A88
_08070B68: .4byte 0x00000A86
_08070B6C:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08070BA8
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x1d
	strh r0, [r1]
	ldr r2, _08070BA0 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #7
	strh r0, [r1]
	ldr r0, _08070BA4 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #4
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #6
	b _08070BC8
	.align 2, 0
_08070BA0: .4byte 0x00000A88
_08070BA4: .4byte 0x00000A84
_08070BA8:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x13
	strh r0, [r1]
	ldr r2, _08070C24 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #0xb
	strh r0, [r1]
	ldr r0, _08070C28 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #9
_08070BC8:
	strh r0, [r1]
_08070BCA:
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08070BE4
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r6, r0
	adds r0, r4, #0
	bl FUN_08064be4
_08070BE4:
	adds r0, r5, #0
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r6, [sp]
	adds r1, #2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r3, #4
	bl FUN_082364f8
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x8a
	movs r2, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc2
	movs r1, #0
	strh r2, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070C24: .4byte 0x00000A88
_08070C28: .4byte 0x00000A84
