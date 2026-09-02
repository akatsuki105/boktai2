	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	str r1, [sp, #4]
	mov sl, r2
	mov r8, r3
	ldr r0, _08014760 @ =0x03000058
	ldr r1, [r0]
	cmp r1, #0
	bne _08014764
	movs r0, #0
	movs r1, #0
	bl Entity080146e0_Create
	adds r1, r0, #0
	cmp r1, #0
	bne _08014764
	movs r0, #1
	rsbs r0, r0, #0
	b _080149CA
	.align 2, 0
_08014760: .4byte 0x03000058
_08014764:
	ldr r0, [sp, #4]
	asrs r3, r0, #8
	movs r0, #0xff
	ldr r2, [sp, #4]
	ands r2, r0
	str r2, [sp, #4]
	ldr r4, [sp]
	cmp r4, #8
	ble _0801477A
	movs r0, #8
	str r0, [sp]
_0801477A:
	ldr r2, [sp, #4]
	cmp r2, #0x14
	bgt _08014786
	ldr r4, [r1, #0x1c]
	str r4, [sp, #8]
	b _0801478A
_08014786:
	ldr r0, [r1, #0x20]
	str r0, [sp, #8]
_0801478A:
	movs r2, #0
	adds r1, #0x24
	str r1, [sp, #0xc]
	adds r7, r1, #0
_08014792:
	ldrb r0, [r7]
	cmp r0, #0
	beq _0801479A
	b _080149B4
_0801479A:
	movs r0, #1
	strb r0, [r7]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r7, #2]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r7, #1]
	cmp r3, #0
	ble _080147B2
	subs r0, r3, #1
	b _080147B4
_080147B2:
	movs r0, #2
_080147B4:
	strb r0, [r7, #3]
	movs r6, #0
	ldr r4, [sp]
	cmp r6, r4
	blt _080147C0
	b _08014988
_080147C0:
	ldr r5, _08014820 @ =0x030046B8
	ldr r3, _08014824 @ =0x000003FF
	ldr r4, [sp, #0xc]
	adds r4, #4
	ldr r0, [sp, #0xc]
	adds r0, #0x14
	mov sb, r0
	ldr r6, [sp]
_080147D0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4]
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08014828 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x3c]
	ands r0, r2
	ldr r1, [sp, #0x38]
	adds r0, r1, r0
	strb r0, [r4, #3]
	mov r2, sl
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sl
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0801481C
	cmp r1, #0
	blt _0801481C
	ldr r0, _0801482C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0801481C
	ldr r0, _08014830 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08014838
_0801481C:
	ldr r0, _08014834 @ =0x0000FFFF
	b _08014846
	.align 2, 0
_08014820: .4byte 0x030046B8
_08014824: .4byte 0x000003FF
_08014828: .4byte 0x0203B400
_0801482C: .4byte 0x030046A8
_08014830: .4byte 0x030046AC
_08014834: .4byte 0x0000FFFF
_08014838:
	ldr r0, _08014884 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08014846:
	strh r0, [r4, #4]
	mov r2, sl
	ldrh r0, [r2, #2]
	strh r0, [r4, #6]
	ldr r1, [sp, #0x34]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0801488C
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08014888 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x34]
	movs r1, #0
	ldrsh r2, [r2, r1]
	mov ip, r2
	mov r1, ip
	str r3, [sp, #0x10]
	bl Mod
	mov r2, r8
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r4, #8]
	ldr r3, [sp, #0x10]
	b _08014892
	.align 2, 0
_08014884: .4byte 0x030046A4
_08014888: .4byte 0x0203B400
_0801488C:
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r4, #8]
_08014892:
	ldr r2, [sp, #0x34]
	movs r1, #2
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _080148CC
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _080148C8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	movs r2, #2
	ldrsh r1, [r1, r2]
	mov ip, r1
	str r3, [sp, #0x10]
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #2]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	ldr r3, [sp, #0x10]
	b _080148D2
	.align 2, 0
_080148C8: .4byte 0x0203B400
_080148CC:
	mov r1, r8
	ldrh r0, [r1, #2]
	strh r0, [r4, #0xa]
_080148D2:
	ldr r2, [sp, #0x34]
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _0801490C
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08014908 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	movs r2, #4
	ldrsh r1, [r1, r2]
	mov ip, r1
	str r3, [sp, #0x10]
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #4]
	adds r1, r1, r0
	strh r1, [r4, #0xc]
	ldr r3, [sp, #0x10]
	b _08014912
	.align 2, 0
_08014908: .4byte 0x0203B400
_0801490C:
	mov r1, r8
	ldrh r0, [r1, #4]
	strh r0, [r4, #0xc]
_08014912:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08014934 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #7
	bgt _08014938
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08014940
	.align 2, 0
_08014934: .4byte 0x0203B400
_08014938:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08014940:
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x10]
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r1, _080149B0 @ =0x085AA850
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [sp, #8]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrb r0, [r7, #3]
	strb r0, [r4, #0x1f]
	mov r0, sb
	movs r1, #0
	str r3, [sp, #0x10]
	bl FUN_0822da50
	adds r4, #0x38
	movs r0, #0x38
	add sb, r0
	subs r6, #1
	ldr r3, [sp, #0x10]
	cmp r6, #0
	beq _08014986
	b _080147D0
_08014986:
	ldr r6, [sp]
_08014988:
	cmp r6, #7
	bgt _080149C8
	movs r3, #0
	movs r2, #1
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r0, #4
	ldr r4, [sp, #0xc]
	adds r1, r0, r4
_0801499C:
	strb r3, [r1]
	ldr r0, [r1, #0x10]
	orrs r0, r2
	str r0, [r1, #0x10]
	adds r1, #0x38
	adds r6, #1
	cmp r6, #7
	ble _0801499C
	b _080149C8
	.align 2, 0
_080149B0: .4byte 0x085AA850
_080149B4:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r7, r7, r0
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, #1
	cmp r2, #5
	bgt _080149C8
	b _08014792
_080149C8:
	movs r0, #0
_080149CA:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
