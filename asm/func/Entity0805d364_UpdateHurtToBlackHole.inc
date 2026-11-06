	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CA82
	movs r0, #0
	strb r0, [r4]
	ldr r2, _0805CA00 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CA04 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CA08 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r5, sp
	ldrb r6, [r0]
	ldr r1, _0805CA0C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	adds r2, r1, #0
	cmp r0, #0
	blt _0805CA10
	asrs r3, r0, #0xc
	b _0805CA16
	.align 2, 0
_0805CA00: .4byte 0x030046B8
_0805CA04: .4byte 0x000003FF
_0805CA08: .4byte 0x0203B400
_0805CA0C: .4byte gSineTable
_0805CA10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CA16:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CA30
	asrs r0, r0, #0xc
	b _0805CA36
_0805CA30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CA36:
	strh r0, [r5, #4]
	adds r2, r4, #0
	adds r2, #0x1c
	adds r3, r7, #0
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r7, #0x30]
	adds r0, r0, r5
	strh r0, [r4, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805CA82:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CA8E
	movs r0, #1
	strb r0, [r4, #1]
	b _0805CAC2
_0805CA8E:
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805CAC8 @ =0x00000FFF
	adds r5, r3, #0
	cmp r1, r0
	bhi _0805CACC
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
_0805CAC2:
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CB6E
	.align 2, 0
_0805CAC8: .4byte 0x00000FFF
_0805CACC:
	add r3, sp, #8
	ldrb r6, [r4, #6]
	movs r0, #0x18
	mov ip, r0
	ldr r2, _0805CAF8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov r8, r3
	cmp r0, #0
	blt _0805CAFC
	asrs r1, r0, #0xc
	b _0805CB02
	.align 2, 0
_0805CAF8: .4byte gSineTable
_0805CAFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CB02:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805CB1E
	asrs r0, r0, #0xc
	b _0805CB24
_0805CB1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CB24:
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r2, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #1
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r4, #4]
	cmp r0, #9
	bls _0805CB6A
	movs r0, #5
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805CB6C
_0805CB6A:
	adds r0, #1
_0805CB6C:
	strh r0, [r4, #4]
_0805CB6E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
