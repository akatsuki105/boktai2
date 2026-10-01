	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_0800045c
	movs r0, #0
	mov r8, r0
	ldrb r1, [r6, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080006C4
	ldr r4, _0800060C @ =0x03003540
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08000614
	ldr r2, _08000610 @ =0x030047C8
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r7, #8
	ldrsh r0, [r4, r7]
	adds r3, r1, r0
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	adds r4, r1, r0
	b _08000620
	.align 2, 0
_0800060C: .4byte 0x03003540
_08000610: .4byte 0x030047C8
_08000614:
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x13
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x13
_08000620:
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08000632
	ldr r0, [r6, #0x50]
	subs r3, r3, r0
	ldr r0, [r6, #0x54]
	subs r4, r4, r0
_08000632:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08000642
	ldr r0, [r6, #0x58]
	adds r3, r3, r0
	ldr r0, [r6, #0x5c]
	adds r4, r4, r0
_08000642:
	adds r0, r6, #0
	adds r0, #0x76
	movs r7, #0
	ldrsh r1, [r0, r7]
	adds r5, r0, #0
	cmp r1, #0x80
	bne _08000658
	adds r7, r3, #0
	subs r7, #0x78
	adds r5, r4, #0
	b _08000692
_08000658:
	ldr r2, [r6, #0x68]
	subs r3, r3, r2
	ldr r1, [r6, #0x6c]
	subs r4, r4, r1
	movs r7, #0
	ldrsh r0, [r5, r7]
	muls r0, r3, r0
	cmp r0, #0
	blt _0800066E
	asrs r0, r0, #7
	b _08000674
_0800066E:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_08000674:
	adds r0, r0, r2
	adds r7, r0, #0
	subs r7, #0x78
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08000688
	asrs r0, r0, #7
	b _0800068E
_08000688:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_0800068E:
	adds r0, r0, r1
	adds r5, r0, #0
_08000692:
	subs r5, #0x5a
	adds r4, r5, #0
	adds r4, #0x5a
	adds r0, r7, #0
	subs r0, #8
	cmp r0, #0
	blt _080006A4
	asrs r1, r0, #3
	b _080006AA
_080006A4:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080006AA:
	adds r0, r4, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080006B6
	asrs r0, r0, #3
	b _080006BC
_080006B6:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080006BC:
	movs r3, #2
	rsbs r3, r3, #0
	mov r8, r3
	b _08000814
_080006C4:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08000710
	ldr r1, [r6, #0x38]
	ldr r0, [r6, #0x30]
	adds r1, r1, r0
	str r1, [r6, #0x38]
	ldr r0, [r6, #0x60]
	cmp r1, r0
	ble _080006DE
	subs r0, r1, r0
	b _080006E4
_080006DE:
	cmn r1, r0
	bge _080006E6
	adds r0, r1, r0
_080006E4:
	str r0, [r6, #0x38]
_080006E6:
	ldr r1, [r6, #0x3c]
	ldr r0, [r6, #0x34]
	adds r1, r1, r0
	str r1, [r6, #0x3c]
	ldr r0, [r6, #0x64]
	cmp r1, r0
	ble _080006F8
	subs r0, r1, r0
	b _080006FE
_080006F8:
	cmn r1, r0
	bge _08000700
	adds r0, r1, r0
_080006FE:
	str r0, [r6, #0x3c]
_08000700:
	ldr r0, [r6, #0x38]
	ldr r1, [r6, #0x28]
	adds r0, r0, r1
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x3c]
	ldr r1, [r6, #0x2c]
	adds r0, r0, r1
	b _0800076C
_08000710:
	movs r3, #0x70
	adds r3, r3, r6
	mov sb, r3
	ldrh r0, [r3]
	cmp r0, #1
	bne _0800076E
	adds r4, r6, #0
	adds r4, #0x74
	ldrh r1, [r4]
	adds r7, r6, #0
	adds r7, #0x72
	ldrh r3, [r7]
	subs r5, r1, r3
	ldr r0, [r6, #0x48]
	muls r0, r5, r0
	ldr r2, [r6, #0x40]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x4c]
	muls r0, r5, r0
	ldrh r2, [r7]
	ldr r1, [r6, #0x44]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r4]
	bl Div
	str r0, [r6, #0x24]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4]
	cmp r0, r4
	blo _0800076E
	mov r1, r8
	mov r0, sb
	strh r1, [r0]
	strh r1, [r7]
	ldr r0, [r6, #0x40]
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x44]
_0800076C:
	str r0, [r6, #0x24]
_0800076E:
	ldr r0, [r6, #0x20]
	cmp r0, #0
	blt _08000778
	asrs r0, r0, #7
	b _0800077E
_08000778:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_0800077E:
	adds r7, r0, #0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	blt _0800078A
	asrs r0, r0, #7
	b _08000790
_0800078A:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_08000790:
	adds r5, r0, #0
	ldrb r1, [r6, #0x1a]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080007E6
	ldr r0, [r6, #0x60]
	asrs r4, r0, #7
	ldr r0, [r6, #0x64]
	asrs r0, r0, #7
	mov r8, r0
	ldr r3, _080007F4 @ =0x030047C8
	movs r0, #0
	ldrsh r2, [r3, r0]
	mov ip, r2
	ldr r2, _080007F8 @ =0x03003540
	movs r0, #8
	ldrsh r1, [r2, r0]
	mov sb, r1
	mov r0, ip
	add r0, sb
	adds r7, r7, r0
	movs r1, #2
	ldrsh r0, [r3, r1]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r5, r5, r0
	cmp r4, #0
	beq _080007D6
	adds r0, r7, #0
	adds r1, r4, #0
	bl Mod
	adds r7, r0, #0
_080007D6:
	mov r0, r8
	cmp r0, #0
	beq _080007E6
	adds r0, r5, #0
	mov r1, r8
	bl Mod
	adds r5, r0, #0
_080007E6:
	adds r4, r5, #0
	cmp r7, #0
	bge _080007FC
	rsbs r0, r7, #0
	asrs r0, r0, #3
	mvns r1, r0
	b _080007FE
	.align 2, 0
_080007F4: .4byte 0x030047C8
_080007F8: .4byte 0x03003540
_080007FC:
	asrs r1, r7, #3
_080007FE:
	cmp r4, #0
	bge _0800080C
	rsbs r0, r4, #0
	asrs r0, r0, #3
	mvns r0, r0
	mov r8, r0
	b _08000810
_0800080C:
	asrs r4, r4, #3
	mov r8, r4
_08000810:
	movs r0, #2
	rsbs r0, r0, #0
_08000814:
	mov r2, r8
	ands r2, r0
	mov r8, r2
	ldrb r0, [r6, #0x1b]
	str r5, [sp]
	mov r2, r8
	adds r3, r7, #0
	bl Video_GenerateBGMap
	adds r4, r6, #0
	adds r4, #0x78
	ldrh r0, [r4]
	cmp r0, #1
	bne _08000872
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r6, #0
	adds r0, #0x88
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r3, r6, #0
	adds r3, #0x7e
	adds r0, r6, #0
	adds r0, #0x8a
	ldrh r2, [r0]
	ldrh r7, [r3]
	adds r2, r2, r7
	strh r2, [r3]
	ldrb r0, [r6, #0x1b]
	ldrh r1, [r1]
	lsrs r1, r1, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x18
	bl FUN_0822f178
	adds r1, r6, #0
	adds r1, #0x7a
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08000872
	strh r0, [r4]
_08000872:
	ldrb r1, [r6, #0x1a]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080008B6
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080008A4
	movs r0, #0x80
	lsls r0, r0, #0x11
	ldrb r2, [r6, #0x1b]
	lsls r0, r2
	lsrs r0, r0, #0x10
	ldr r2, _080008A0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080008B6
	.align 2, 0
_080008A0: .4byte 0x03003E78
_080008A4:
	movs r0, #0x80
	lsls r0, r0, #0x11
	ldrb r3, [r6, #0x1b]
	lsls r0, r3
	lsrs r0, r0, #0x10
	ldr r2, _080008D4 @ =0x03003E78
	ldrh r1, [r2]
	bics r1, r0
	strh r1, [r2]
_080008B6:
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080008D4: .4byte 0x03003E78
