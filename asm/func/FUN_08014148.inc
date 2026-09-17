	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	adds r7, r1, #0
	ldr r0, _080141B0 @ =0x085AA850
	adds r0, #0x9c
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #4]
	ldrb r2, [r7, #1]
	cmp r0, r2
	blt _08014170
	b _08014412
_08014170:
	ldr r0, _080141B4 @ =0x030046B8
	mov r8, r0
	adds r4, r7, #4
	movs r1, #0x14
	adds r1, r1, r7
	mov sb, r1
	ldr r2, _080141B8 @ =0xFFFFFF00
	mov sl, r2
_08014180:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08014188
	b _080143FE
_08014188:
	ldrh r0, [r4, #0x28]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080141AC
	cmp r1, #0
	blt _080141AC
	ldr r0, _080141BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080141AC
	ldr r0, _080141C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080141C8
_080141AC:
	ldr r0, _080141C4 @ =0x0000FFFF
	b _080141D6
	.align 2, 0
_080141B0: .4byte 0x085AA850
_080141B4: .4byte 0x030046B8
_080141B8: .4byte 0xFFFFFF00
_080141BC: .4byte 0x030046A8
_080141C0: .4byte 0x030046AC
_080141C4: .4byte 0x0000FFFF
_080141C8:
	ldr r0, _080141E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080141D6:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bhi _080141EC
	ldr r0, [sp]
	ldr r3, [r0, #0x1c]
	b _080141F0
	.align 2, 0
_080141E8: .4byte 0x030046A4
_080141EC:
	ldr r1, [sp]
	ldr r3, [r1, #0x20]
_080141F0:
	ldrh r0, [r4, #8]
	ldrh r2, [r4, #0x28]
	adds r0, r0, r2
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0xc]
	ldrh r1, [r4, #0x2c]
	adds r0, r0, r1
	strh r0, [r4, #0x2c]
	ldrh r1, [r4, #0xa]
	ldrh r2, [r4, #6]
	adds r0, r1, r2
	strh r0, [r4, #6]
	subs r1, #1
	strh r1, [r4, #0xa]
	ldr r0, _08014228 @ =0x0000FFFF
	cmp r5, r0
	bne _08014214
	b _08014390
_08014214:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x10]
	bl FUN_08234224
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _0801422C
	adds r0, #4
	b _08014238
	.align 2, 0
_08014228: .4byte 0x0000FFFF
_0801422C:
	ldr r0, _0801428C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08014238:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r6, r1, #8
	movs r1, #6
	ldrsh r0, [r4, r1]
	cmp r0, r6
	blt _0801424A
	b _08014366
_0801424A:
	ldrh r2, [r4, #4]
	cmp r5, r2
	beq _08014326
	ldrh r0, [r4, #4]
	subs r0, r5, r0
	cmp r0, #0
	bge _0801425A
	rsbs r0, r0, #0
_0801425A:
	cmp r0, #1
	bne _080142C6
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08014290 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08014294 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #8
	ldrsh r2, [r4, r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _08014298
	asrs r0, r0, #6
	b _0801429E
	.align 2, 0
_0801428C: .4byte 0x030046A4
_08014290: .4byte 0x000003FF
_08014294: .4byte 0x0203B400
_08014298:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0801429E:
	rsbs r0, r0, #0
	strh r0, [r4, #8]
	ldrh r0, [r4, #4]
	subs r0, r5, r0
	cmp r0, #0
	bge _080142BA
	ldrh r0, [r4, #0x28]
	mov r1, sl
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r0, [r4, #0x28]
	b _08014328
_080142BA:
	ldrh r0, [r4, #0x28]
	mov r1, sl
	ands r0, r1
	subs r0, #1
	strh r0, [r4, #0x28]
	b _08014328
_080142C6:
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080142F0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080142F4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _080142F8
	asrs r0, r0, #6
	b _080142FE
	.align 2, 0
_080142F0: .4byte 0x000003FF
_080142F4: .4byte 0x0203B400
_080142F8:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080142FE:
	rsbs r0, r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #4]
	subs r0, r5, r0
	cmp r0, #0
	bge _0801431A
	ldrh r0, [r4, #0x2c]
	mov r1, sl
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r0, [r4, #0x2c]
	b _08014328
_0801431A:
	ldrh r0, [r4, #0x2c]
	mov r1, sl
	ands r0, r1
	subs r0, #1
	strh r0, [r4, #0x2c]
	b _08014328
_08014326:
	strh r6, [r4, #6]
_08014328:
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08014354 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08014358 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	movs r0, #3
	ands r1, r0
	adds r1, #0x37
	adds r0, r2, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _0801435C
	asrs r0, r0, #6
	b _08014362
	.align 2, 0
_08014354: .4byte 0x000003FF
_08014358: .4byte 0x0203B400
_0801435C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08014362:
	rsbs r0, r0, #0
	strh r0, [r4, #0xa]
_08014366:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x10]
	bl FUN_08234224
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _0801437A
	adds r0, #4
	b _08014386
_0801437A:
	ldr r0, _080143B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08014386:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08014392
_08014390:
	ldr r6, _080143BC @ =0x0000FFFF
_08014392:
	strh r5, [r4, #4]
	ldr r1, [sp]
	ldr r0, [r1, #0x18]
	movs r2, #1
	ands r0, r2
	ldr r1, [sp, #4]
	ands r1, r2
	cmp r0, r1
	bne _080143C0
	ldr r0, _080143BC @ =0x0000FFFF
	cmp r6, r0
	beq _080143C0
	strh r6, [r4, #0x2a]
	ldrh r0, [r3, #4]
	ldr r2, [sp, #0xc]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	movs r0, #3
	b _080143D6
	.align 2, 0
_080143B8: .4byte 0x030046A4
_080143BC: .4byte 0x0000FFFF
_080143C0:
	ldrh r0, [r4, #6]
	strh r0, [r4, #0x2a]
	ldr r1, _080143F4 @ =0x085AA850
	ldrb r0, [r7, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrb r0, [r7, #3]
_080143D6:
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #2]
	adds r1, r0, #1
	strb r1, [r4, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #3]
	cmp r0, r1
	blo _080143F8
	movs r0, #0
	strb r0, [r4]
	mov r0, sb
	bl FUN_0822dabc
	b _080143FE
	.align 2, 0
_080143F4: .4byte 0x085AA850
_080143F8:
	ldr r2, [sp, #8]
	adds r2, #1
	str r2, [sp, #8]
_080143FE:
	adds r4, #0x38
	movs r0, #0x38
	add sb, r0
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	ldrb r2, [r7, #1]
	cmp r1, r2
	bge _08014412
	b _08014180
_08014412:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _0801441A
	strb r0, [r7]
_0801441A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
