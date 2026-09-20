	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r0, #0x60
	mov sl, r0
	ldr r1, [sp]
	adds r1, #0x24
	mov r8, r1
	mov sb, r8
	movs r2, #0x1f
	str r2, [sp, #4]
_0801528E:
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #0
	bne _08015298
	b _08015444
_08015298:
	mov r5, sb
	mov r7, sl
	ldrh r0, [r3, #2]
	ldrh r1, [r3, #0xc]
	cmp r0, r1
	blo _080152F0
	movs r2, #6
	ldrsh r1, [r3, r2]
	ldrh r0, [r3, #0xe]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152B4
	asrs r0, r0, #8
	b _080152BA
_080152B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080152BA:
	strh r0, [r5, #6]
	movs r3, #0x10
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152CE
	asrs r0, r0, #0xc
	b _080152D4
_080152CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080152D4:
	strh r0, [r5, #0x18]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152E8
	asrs r0, r0, #0xc
	b _080152EE
_080152E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080152EE:
	strh r0, [r5, #0x1c]
_080152F0:
	ldrh r0, [r5, #2]
	ldrh r3, [r5, #8]
	cmp r0, r3
	blo _0801532A
	movs r0, #4
	ldrsh r1, [r5, r0]
	ldrh r0, [r5, #0xa]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015308
	asrs r0, r0, #8
	b _0801530E
_08015308:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801530E:
	strh r0, [r5, #4]
	movs r2, #0x12
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r0, [r5, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015322
	asrs r0, r0, #0xc
	b _08015328
_08015322:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015328:
	strh r0, [r5, #0x1a]
_0801532A:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0x1a]
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	ldr r0, [r7]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0801534C
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r7, #0x20]
_0801534C:
	adds r4, r5, #0
	adds r4, #0x68
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x68]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _0801537C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08015384
_0801537C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08015384:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080153A8
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080153B0
_080153A8:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080153B0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080153E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0801542E
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080153F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080153EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08015408
	.align 2, 0
_080153E8: .4byte 0x0000FFFF
_080153EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08015406
_080153F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08015406
	strh r1, [r4, #8]
	movs r2, #1
	b _08015408
_08015406:
	movs r2, #0
_08015408:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08015430
	movs r3, #1
	strb r3, [r4, #7]
	b _08015430
_0801542E:
	movs r2, #0
_08015430:
	cmp r2, #0
	beq _0801543E
	movs r0, #0
	strb r0, [r5]
	adds r0, r7, #0
	bl AuxSprite_Remove
_0801543E:
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
_08015444:
	movs r0, #0x78
	add sl, r0
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	subs r1, #1
	str r1, [sp, #4]
	cmp r1, #0
	blt _08015458
	b _0801528E
_08015458:
	ldr r2, [sp]
	ldr r0, [r2, #0x20]
	adds r0, #1
	str r0, [r2, #0x20]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
