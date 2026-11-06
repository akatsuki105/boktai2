	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0813A42E
	b _0813AAB4
_0813A42E:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0813A458
	ldr r3, _0813A454 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813A446
	b _0813AAB4
_0813A446:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _0813AAB4
	.align 2, 0
_0813A454: .4byte 0x0000048C
_0813A458:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0813A468
	b _0813AAB4
_0813A468:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0813A478
	b _0813A784
_0813A478:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0813A48A
	b _0813AAB4
_0813A48A:
	ldr r2, _0813A51C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0813A49E
	b _0813AAB4
_0813A49E:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0813A4AC
	b _0813AAB4
_0813A4AC:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0813A4C4
	b _0813A60C
_0813A4C4:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0813A52C
	ands r3, r1
	cmp r3, #0
	beq _0813A52C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813A4EA
	rsbs r1, r1, #0
_0813A4EA:
	cmp r1, #0x20
	bgt _0813A52C
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0813A520 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _0813A524 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0813A528 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0813AAB4
	.align 2, 0
_0813A51C: .4byte 0x0000A007
_0813A520: .4byte 0x000004BE
_0813A524: .4byte 0x0000048C
_0813A528: .4byte 0x0000044E
_0813A52C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _0813A554 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813A55C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A558 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A554: .4byte 0x0000048A
_0813A558: .4byte 0x03002BE0
_0813A55C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813A578
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813A574 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A574: .4byte 0x03002BE0
_0813A578:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813A594
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813A590 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A590: .4byte 0x03002BE0
_0813A594:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813A5B0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813A5AC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A5AC: .4byte 0x03002BE0
_0813A5B0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813A5C2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813A5CA
_0813A5C2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813A5CC
_0813A5CA:
	movs r3, #1
_0813A5CC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _0813A600 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0813A5EE
	b _0813A744
_0813A5EE:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813A604
	movs r0, #1
	b _0813A606
	.align 2, 0
_0813A600: .4byte 0x0000049C
_0813A604:
	movs r0, #0
_0813A606:
	cmp r0, #0
	bne _0813A6EA
	b _0813A700
_0813A60C:
	strh r2, [r7, #0x3e]
	ldr r1, _0813A634 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0813A63C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A638 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A634: .4byte 0x0000048A
_0813A638: .4byte 0x03002BE0
_0813A63C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813A658
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813A654 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A654: .4byte 0x03002BE0
_0813A658:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0813A674
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813A670 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A670: .4byte 0x03002BE0
_0813A674:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813A690
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813A68C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A68C: .4byte 0x03002BE0
_0813A690:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813A6A2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813A6AA
_0813A6A2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813A6AC
_0813A6AA:
	movs r3, #1
_0813A6AC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _0813A6E0 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _0813A744
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813A6E4
	movs r0, #1
	b _0813A6E6
	.align 2, 0
_0813A6E0: .4byte 0x0000049C
_0813A6E4:
	movs r0, #0
_0813A6E6:
	cmp r0, #0
	beq _0813A700
_0813A6EA:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A6FC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813A70C
	.align 2, 0
_0813A6FC: .4byte 0x03002BE0
_0813A700:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813A744
_0813A70C:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0813A744:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813A770
	ldr r5, _0813A77C @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0813A770
	strh r1, [r2]
_0813A770:
	ldr r5, _0813A780 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0813AAB4
	.align 2, 0
_0813A77C: .4byte 0x0000024E
_0813A780: .4byte 0x0000048C
_0813A784:
	ldr r0, _0813A798 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813A79C
	movs r0, #1
	b _0813A79E
	.align 2, 0
_0813A798: .4byte 0x030047A4
_0813A79C:
	movs r0, #0
_0813A79E:
	cmp r0, #0
	beq _0813A7AC
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _0813A7B4
_0813A7AC:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_0813A7B4:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0813A7EC @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0813A7F0 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0813A7E2
	cmp r2, #0x17
	bne _0813A7F4
_0813A7E2:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0813A816
	.align 2, 0
_0813A7EC: .4byte 0x0000048C
_0813A7F0: .4byte 0x000001DF
_0813A7F4:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0813A7E2
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0813A844 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813A816
	movs r1, #0
_0813A816:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0813A852
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0813A848
	asrs r0, r0, #1
	b _0813A84E
	.align 2, 0
_0813A844: .4byte 0x00000187
_0813A848:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0813A84E:
	mov r2, sb
	strh r0, [r2]
_0813A852:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0813A870
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0813A86C @ =0x000001DD
	adds r1, r6, r4
	b _0813A8E4
	.align 2, 0
_0813A86C: .4byte 0x000001DD
_0813A870:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0813A8D0
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0813A8D0
	ldr r2, _0813A8C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813A8C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0813A8C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0813A8CC @ =0x000001DD
	adds r1, r6, r4
	b _0813A8E4
	.align 2, 0
_0813A8C0: .4byte 0x030046B8
_0813A8C4: .4byte 0x000003FF
_0813A8C8: .4byte 0x0203B400
_0813A8CC: .4byte 0x000001DD
_0813A8D0:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0813A904 @ =0x000001DD
	adds r1, r6, r3
_0813A8E4:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813A90C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813A908 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A904: .4byte 0x000001DD
_0813A908: .4byte 0x03002BE0
_0813A90C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813A928
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813A924 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A924: .4byte 0x03002BE0
_0813A928:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813A944
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A940 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A940: .4byte 0x03002BE0
_0813A944:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813A960
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813A95C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A95C: .4byte 0x03002BE0
_0813A960:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813A972
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0813A97A
_0813A972:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813A97C
_0813A97A:
	movs r3, #1
_0813A97C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0813A9B0 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0813AA18
	movs r1, #2
	ldr r2, _0813A9B4 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813A9B8
	movs r0, #1
	b _0813A9BA
	.align 2, 0
_0813A9B0: .4byte 0x0000049C
_0813A9B4: .4byte 0x00000474
_0813A9B8:
	movs r0, #0
_0813A9BA:
	cmp r0, #0
	beq _0813A9D4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A9D0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813A9E0
	.align 2, 0
_0813A9D0: .4byte 0x03002BE0
_0813A9D4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813AA18
_0813A9E0:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0813AA18:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0813AA4C
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0813AA4C
	ldr r0, _0813AA64 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0813AA4C
	strh r1, [r2]
_0813AA4C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0813AA68 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0813AA6C @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813AA70
	movs r0, #1
	b _0813AA72
	.align 2, 0
_0813AA64: .4byte 0x0000024E
_0813AA68: .4byte 0x030046A0
_0813AA6C: .4byte 0x00000934
_0813AA70:
	movs r0, #0
_0813AA72:
	ldr r1, _0813AAC4 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0813AA8A
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_0813AA8A:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813AAB4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813AAC4: .4byte 0x0000048A
