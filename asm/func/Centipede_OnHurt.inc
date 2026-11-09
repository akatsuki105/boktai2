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
	cmp r0, #0
	beq _08132374
	b _08132A0E
_08132374:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08132384
	b _08132A08
_08132384:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081323AC
	ldr r3, _081323A8 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813239C
	b _08132A08
_0813239C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08132A08
	.align 2, 0
_081323A8: .4byte 0x0000048C
_081323AC:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081323BC
	b _08132A08
_081323BC:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081323CC
	b _081326D8
_081323CC:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081323DE
	b _08132A08
_081323DE:
	ldr r2, _08132470 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081323F2
	b _08132A08
_081323F2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08132400
	b _08132A08
_08132400:
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
	bne _08132418
	b _08132560
_08132418:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08132480
	ands r3, r1
	cmp r3, #0
	beq _08132480
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813243E
	rsbs r1, r1, #0
_0813243E:
	cmp r1, #0x20
	bgt _08132480
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08132474 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08132478 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0813247C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08132A08
	.align 2, 0
_08132470: .4byte 0x0000A007
_08132474: .4byte 0x000004BE
_08132478: .4byte 0x0000048C
_0813247C: .4byte 0x0000044E
_08132480:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081324A8 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081324B0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081324AC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_081324A8: .4byte 0x0000048A
_081324AC: .4byte 0x03002BE0
_081324B0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081324CC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081324C8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_081324C8: .4byte 0x03002BE0
_081324CC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081324E8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081324E4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_081324E4: .4byte 0x03002BE0
_081324E8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08132504
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08132500 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813251E
	.align 2, 0
_08132500: .4byte 0x03002BE0
_08132504:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08132516
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813251E
_08132516:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08132520
_0813251E:
	movs r3, #1
_08132520:
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
	ldr r5, _08132554 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08132542
	b _08132698
_08132542:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08132558
	movs r0, #1
	b _0813255A
	.align 2, 0
_08132554: .4byte 0x0000049C
_08132558:
	movs r0, #0
_0813255A:
	cmp r0, #0
	bne _0813263E
	b _08132654
_08132560:
	strh r2, [r7, #0x3e]
	ldr r1, _08132588 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08132590
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813258C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_08132588: .4byte 0x0000048A
_0813258C: .4byte 0x03002BE0
_08132590:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081325AC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081325A8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_081325A8: .4byte 0x03002BE0
_081325AC:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081325C8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081325C4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_081325C4: .4byte 0x03002BE0
_081325C8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081325E4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081325E0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081325FE
	.align 2, 0
_081325E0: .4byte 0x03002BE0
_081325E4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081325F6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081325FE
_081325F6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08132600
_081325FE:
	movs r3, #1
_08132600:
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
	ldr r5, _08132634 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08132698
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08132638
	movs r0, #1
	b _0813263A
	.align 2, 0
_08132634: .4byte 0x0000049C
_08132638:
	movs r0, #0
_0813263A:
	cmp r0, #0
	beq _08132654
_0813263E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08132650 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08132660
	.align 2, 0
_08132650: .4byte 0x03002BE0
_08132654:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08132698
_08132660:
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
_08132698:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081326C4
	ldr r5, _081326D0 @ =0x0000024E
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
	bls _081326C4
	strh r1, [r2]
_081326C4:
	ldr r5, _081326D4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08132A08
	.align 2, 0
_081326D0: .4byte 0x0000024E
_081326D4: .4byte 0x0000048C
_081326D8:
	ldr r0, _081326EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081326F0
	movs r0, #1
	b _081326F2
	.align 2, 0
_081326EC: .4byte 0x030047A4
_081326F0:
	movs r0, #0
_081326F2:
	cmp r0, #0
	beq _08132700
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08132708
_08132700:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08132708:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08132740 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08132744 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08132736
	cmp r2, #0x17
	bne _08132748
_08132736:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0813276A
	.align 2, 0
_08132740: .4byte 0x0000048C
_08132744: .4byte 0x000001DF
_08132748:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08132736
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08132798 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813276A
	movs r1, #0
_0813276A:
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
	beq _081327A6
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0813279C
	asrs r0, r0, #1
	b _081327A2
	.align 2, 0
_08132798: .4byte 0x00000187
_0813279C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081327A2:
	mov r2, sb
	strh r0, [r2]
_081327A6:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081327C4
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081327C0 @ =0x000001DD
	adds r1, r6, r4
	b _08132838
	.align 2, 0
_081327C0: .4byte 0x000001DD
_081327C4:
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
	bne _08132824
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08132824
	ldr r2, _08132814 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08132818 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0813281C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08132820 @ =0x000001DD
	adds r1, r6, r4
	b _08132838
	.align 2, 0
_08132814: .4byte 0x030046B8
_08132818: .4byte 0x000003FF
_0813281C: .4byte 0x0203B400
_08132820: .4byte 0x000001DD
_08132824:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08132858 @ =0x000001DD
	adds r1, r6, r3
_08132838:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08132860
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813285C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_08132858: .4byte 0x000001DD
_0813285C: .4byte 0x03002BE0
_08132860:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813287C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08132878 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_08132878: .4byte 0x03002BE0
_0813287C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08132898
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08132894 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_08132894: .4byte 0x03002BE0
_08132898:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081328B4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081328B0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081328CE
	.align 2, 0
_081328B0: .4byte 0x03002BE0
_081328B4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081328C6
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081328CE
_081328C6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081328D0
_081328CE:
	movs r3, #1
_081328D0:
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
	ldr r5, _08132904 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0813296C
	movs r1, #2
	ldr r2, _08132908 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813290C
	movs r0, #1
	b _0813290E
	.align 2, 0
_08132904: .4byte 0x0000049C
_08132908: .4byte 0x00000474
_0813290C:
	movs r0, #0
_0813290E:
	cmp r0, #0
	beq _08132928
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08132924 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08132934
	.align 2, 0
_08132924: .4byte 0x03002BE0
_08132928:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813296C
_08132934:
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
_0813296C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081329A0
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081329A0
	ldr r0, _081329B8 @ =0x0000024E
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
	bls _081329A0
	strh r1, [r2]
_081329A0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081329BC @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081329C0 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081329C4
	movs r0, #1
	b _081329C6
	.align 2, 0
_081329B8: .4byte 0x0000024E
_081329BC: .4byte 0x030046A0
_081329C0: .4byte 0x00000934
_081329C4:
	movs r0, #0
_081329C6:
	ldr r1, _08132A20 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081329DE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081329DE:
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
_08132A08:
	adds r0, r6, #0
	bl FUN_08137e98
_08132A0E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08132A20: .4byte 0x0000048A
