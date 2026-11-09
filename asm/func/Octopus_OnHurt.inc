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
	beq _08184602
	b _08184C88
_08184602:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0818462C
	ldr r3, _08184628 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818461A
	b _08184C88
_0818461A:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08184C88
	.align 2, 0
_08184628: .4byte 0x0000048C
_0818462C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0818463C
	b _08184C88
_0818463C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0818464C
	b _08184958
_0818464C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0818465E
	b _08184C88
_0818465E:
	ldr r2, _081846F0 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08184672
	b _08184C88
_08184672:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08184680
	b _08184C88
_08184680:
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
	bne _08184698
	b _081847E0
_08184698:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08184700
	ands r3, r1
	cmp r3, #0
	beq _08184700
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081846BE
	rsbs r1, r1, #0
_081846BE:
	cmp r1, #0x20
	bgt _08184700
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081846F4 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081846F8 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081846FC @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08184C88
	.align 2, 0
_081846F0: .4byte 0x0000A007
_081846F4: .4byte 0x000004BE
_081846F8: .4byte 0x0000048C
_081846FC: .4byte 0x0000044E
_08184700:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08184728 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08184730
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0818472C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184728: .4byte 0x0000048A
_0818472C: .4byte 0x03002BE0
_08184730:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0818474C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08184748 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184748: .4byte 0x03002BE0
_0818474C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08184768
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08184764 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184764: .4byte 0x03002BE0
_08184768:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08184784
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08184780 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0818479E
	.align 2, 0
_08184780: .4byte 0x03002BE0
_08184784:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08184796
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0818479E
_08184796:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081847A0
_0818479E:
	movs r3, #1
_081847A0:
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
	ldr r5, _081847D4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081847C2
	b _08184918
_081847C2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081847D8
	movs r0, #1
	b _081847DA
	.align 2, 0
_081847D4: .4byte 0x0000049C
_081847D8:
	movs r0, #0
_081847DA:
	cmp r0, #0
	bne _081848BE
	b _081848D4
_081847E0:
	strh r2, [r7, #0x3e]
	ldr r1, _08184808 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08184810
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0818480C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184808: .4byte 0x0000048A
_0818480C: .4byte 0x03002BE0
_08184810:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0818482C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08184828 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184828: .4byte 0x03002BE0
_0818482C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08184848
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08184844 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184844: .4byte 0x03002BE0
_08184848:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08184864
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08184860 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0818487E
	.align 2, 0
_08184860: .4byte 0x03002BE0
_08184864:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08184876
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0818487E
_08184876:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08184880
_0818487E:
	movs r3, #1
_08184880:
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
	ldr r5, _081848B4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08184918
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081848B8
	movs r0, #1
	b _081848BA
	.align 2, 0
_081848B4: .4byte 0x0000049C
_081848B8:
	movs r0, #0
_081848BA:
	cmp r0, #0
	beq _081848D4
_081848BE:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081848D0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081848E0
	.align 2, 0
_081848D0: .4byte 0x03002BE0
_081848D4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08184918
_081848E0:
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
_08184918:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08184944
	ldr r5, _08184950 @ =0x0000024E
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
	bls _08184944
	strh r1, [r2]
_08184944:
	ldr r5, _08184954 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08184C88
	.align 2, 0
_08184950: .4byte 0x0000024E
_08184954: .4byte 0x0000048C
_08184958:
	ldr r0, _0818496C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08184970
	movs r0, #1
	b _08184972
	.align 2, 0
_0818496C: .4byte 0x030047A4
_08184970:
	movs r0, #0
_08184972:
	cmp r0, #0
	beq _08184980
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08184988
_08184980:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08184988:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081849C0 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081849C4 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081849B6
	cmp r2, #0x17
	bne _081849C8
_081849B6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081849EA
	.align 2, 0
_081849C0: .4byte 0x0000048C
_081849C4: .4byte 0x000001DF
_081849C8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081849B6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08184A18 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081849EA
	movs r1, #0
_081849EA:
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
	beq _08184A26
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08184A1C
	asrs r0, r0, #1
	b _08184A22
	.align 2, 0
_08184A18: .4byte 0x00000187
_08184A1C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08184A22:
	mov r2, sb
	strh r0, [r2]
_08184A26:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08184A44
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08184A40 @ =0x000001DD
	adds r1, r6, r4
	b _08184AB8
	.align 2, 0
_08184A40: .4byte 0x000001DD
_08184A44:
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
	bne _08184AA4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08184AA4
	ldr r2, _08184A94 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08184A98 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08184A9C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08184AA0 @ =0x000001DD
	adds r1, r6, r4
	b _08184AB8
	.align 2, 0
_08184A94: .4byte 0x030046B8
_08184A98: .4byte 0x000003FF
_08184A9C: .4byte 0x0203B400
_08184AA0: .4byte 0x000001DD
_08184AA4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08184AD8 @ =0x000001DD
	adds r1, r6, r3
_08184AB8:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08184AE0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08184ADC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184AD8: .4byte 0x000001DD
_08184ADC: .4byte 0x03002BE0
_08184AE0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08184AFC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08184AF8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184AF8: .4byte 0x03002BE0
_08184AFC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08184B18
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08184B14 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184B14: .4byte 0x03002BE0
_08184B18:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08184B34
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08184B30 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08184B4E
	.align 2, 0
_08184B30: .4byte 0x03002BE0
_08184B34:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08184B46
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08184B4E
_08184B46:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08184B50
_08184B4E:
	movs r3, #1
_08184B50:
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
	ldr r5, _08184B84 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08184BEC
	movs r1, #2
	ldr r2, _08184B88 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08184B8C
	movs r0, #1
	b _08184B8E
	.align 2, 0
_08184B84: .4byte 0x0000049C
_08184B88: .4byte 0x00000474
_08184B8C:
	movs r0, #0
_08184B8E:
	cmp r0, #0
	beq _08184BA8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08184BA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08184BB4
	.align 2, 0
_08184BA4: .4byte 0x03002BE0
_08184BA8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08184BEC
_08184BB4:
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
_08184BEC:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08184C20
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08184C20
	ldr r0, _08184C38 @ =0x0000024E
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
	bls _08184C20
	strh r1, [r2]
_08184C20:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08184C3C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08184C40 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08184C44
	movs r0, #1
	b _08184C46
	.align 2, 0
_08184C38: .4byte 0x0000024E
_08184C3C: .4byte 0x030046A0
_08184C40: .4byte 0x00000934
_08184C44:
	movs r0, #0
_08184C46:
	ldr r1, _08184C98 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08184C5E
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_08184C5E:
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
_08184C88:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08184C98: .4byte 0x0000048A
