	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817066A
	b _08170D34
_0817066A:
	ldr r0, [r4]
	movs r1, #0x20
	ldr r2, _08170680 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170684
	movs r0, #1
	b _08170686
	.align 2, 0
_08170680: .4byte 0x00001008
_08170684:
	movs r0, #0
_08170686:
	cmp r0, #0
	beq _0817068C
	b _08170D34
_0817068C:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0817069C
	b _08170D20
_0817069C:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081706C4
	ldr r4, _081706C0 @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081706B4
	b _08170D20
_081706B4:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08170D20
	.align 2, 0
_081706C0: .4byte 0x0000048C
_081706C4:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081706D4
	b _08170D20
_081706D4:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081706E4
	b _081709F0
_081706E4:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081706F6
	b _08170D20
_081706F6:
	ldr r2, _08170788 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0817070A
	b _08170D20
_0817070A:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08170718
	b _08170D20
_08170718:
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
	bne _08170730
	b _08170878
_08170730:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08170798
	ands r3, r1
	cmp r3, #0
	beq _08170798
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08170756
	rsbs r1, r1, #0
_08170756:
	cmp r1, #0x20
	bgt _08170798
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0817078C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08170790 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08170794 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08170D20
	.align 2, 0
_08170788: .4byte 0x0000A007
_0817078C: .4byte 0x000004BE
_08170790: .4byte 0x0000048C
_08170794: .4byte 0x0000044E
_08170798:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081707C0 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081707C8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081707C4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_081707C0: .4byte 0x0000048A
_081707C4: .4byte 0x03002BE0
_081707C8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081707E4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081707E0 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_081707E0: .4byte 0x03002BE0
_081707E4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08170800
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081707FC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_081707FC: .4byte 0x03002BE0
_08170800:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817081C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08170818 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08170836
	.align 2, 0
_08170818: .4byte 0x03002BE0
_0817081C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817082E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08170836
_0817082E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08170838
_08170836:
	movs r3, #1
_08170838:
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
	ldr r5, _0817086C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0817085A
	b _081709B0
_0817085A:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170870
	movs r0, #1
	b _08170872
	.align 2, 0
_0817086C: .4byte 0x0000049C
_08170870:
	movs r0, #0
_08170872:
	cmp r0, #0
	bne _08170956
	b _0817096C
_08170878:
	strh r2, [r7, #0x3e]
	ldr r1, _081708A0 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081708A8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081708A4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708A0: .4byte 0x0000048A
_081708A4: .4byte 0x03002BE0
_081708A8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081708C4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081708C0 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708C0: .4byte 0x03002BE0
_081708C4:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081708E0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081708DC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708DC: .4byte 0x03002BE0
_081708E0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081708FC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081708F8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08170916
	.align 2, 0
_081708F8: .4byte 0x03002BE0
_081708FC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817090E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08170916
_0817090E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08170918
_08170916:
	movs r3, #1
_08170918:
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
	ldr r5, _0817094C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081709B0
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170950
	movs r0, #1
	b _08170952
	.align 2, 0
_0817094C: .4byte 0x0000049C
_08170950:
	movs r0, #0
_08170952:
	cmp r0, #0
	beq _0817096C
_08170956:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08170968 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08170978
	.align 2, 0
_08170968: .4byte 0x03002BE0
_0817096C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081709B0
_08170978:
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
_081709B0:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081709DC
	ldr r5, _081709E8 @ =0x0000024E
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
	bls _081709DC
	strh r1, [r2]
_081709DC:
	ldr r5, _081709EC @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08170D20
	.align 2, 0
_081709E8: .4byte 0x0000024E
_081709EC: .4byte 0x0000048C
_081709F0:
	ldr r0, _08170A04 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08170A08
	movs r0, #1
	b _08170A0A
	.align 2, 0
_08170A04: .4byte 0x030047A4
_08170A08:
	movs r0, #0
_08170A0A:
	cmp r0, #0
	beq _08170A18
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08170A20
_08170A18:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08170A20:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08170A58 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08170A5C @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08170A4E
	cmp r2, #0x17
	bne _08170A60
_08170A4E:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08170A82
	.align 2, 0
_08170A58: .4byte 0x0000048C
_08170A5C: .4byte 0x000001DF
_08170A60:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08170A4E
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08170AB0 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08170A82
	movs r1, #0
_08170A82:
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
	beq _08170ABE
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08170AB4
	asrs r0, r0, #1
	b _08170ABA
	.align 2, 0
_08170AB0: .4byte 0x00000187
_08170AB4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08170ABA:
	mov r2, sb
	strh r0, [r2]
_08170ABE:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08170ADC
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08170AD8 @ =0x000001DD
	adds r1, r6, r4
	b _08170B50
	.align 2, 0
_08170AD8: .4byte 0x000001DD
_08170ADC:
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
	bne _08170B3C
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08170B3C
	ldr r2, _08170B2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08170B30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08170B34 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08170B38 @ =0x000001DD
	adds r1, r6, r4
	b _08170B50
	.align 2, 0
_08170B2C: .4byte 0x030046B8
_08170B30: .4byte 0x000003FF
_08170B34: .4byte 0x0203B400
_08170B38: .4byte 0x000001DD
_08170B3C:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08170B70 @ =0x000001DD
	adds r1, r6, r3
_08170B50:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08170B78
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08170B74 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170B70: .4byte 0x000001DD
_08170B74: .4byte 0x03002BE0
_08170B78:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08170B94
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08170B90 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170B90: .4byte 0x03002BE0
_08170B94:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08170BB0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08170BAC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170BAC: .4byte 0x03002BE0
_08170BB0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08170BCC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08170BC8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08170BE6
	.align 2, 0
_08170BC8: .4byte 0x03002BE0
_08170BCC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08170BDE
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08170BE6
_08170BDE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08170BE8
_08170BE6:
	movs r3, #1
_08170BE8:
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
	ldr r5, _08170C1C @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08170C84
	movs r1, #2
	ldr r2, _08170C20 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170C24
	movs r0, #1
	b _08170C26
	.align 2, 0
_08170C1C: .4byte 0x0000049C
_08170C20: .4byte 0x00000474
_08170C24:
	movs r0, #0
_08170C26:
	cmp r0, #0
	beq _08170C40
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08170C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08170C4C
	.align 2, 0
_08170C3C: .4byte 0x03002BE0
_08170C40:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08170C84
_08170C4C:
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
_08170C84:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08170CB8
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08170CB8
	ldr r0, _08170CD0 @ =0x0000024E
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
	bls _08170CB8
	strh r1, [r2]
_08170CB8:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08170CD4 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08170CD8 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08170CDC
	movs r0, #1
	b _08170CDE
	.align 2, 0
_08170CD0: .4byte 0x0000024E
_08170CD4: .4byte 0x030046A0
_08170CD8: .4byte 0x00000934
_08170CDC:
	movs r0, #0
_08170CDE:
	ldr r1, _08170D44 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08170CF6
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_08170CF6:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
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
_08170D20:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r2, _08170D48 @ =0x00001008
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
_08170D34:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08170D44: .4byte 0x0000048A
_08170D48: .4byte 0x00001008
