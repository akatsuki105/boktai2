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
	beq _0811664A
	b _08116CD0
_0811664A:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08116674
	ldr r3, _08116670 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08116662
	b _08116CD0
_08116662:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08116CD0
	.align 2, 0
_08116670: .4byte 0x0000048C
_08116674:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08116684
	b _08116CD0
_08116684:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08116694
	b _081169A0
_08116694:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081166A6
	b _08116CD0
_081166A6:
	ldr r2, _08116738 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081166BA
	b _08116CD0
_081166BA:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081166C8
	b _08116CD0
_081166C8:
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
	bne _081166E0
	b _08116828
_081166E0:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08116748
	ands r3, r1
	cmp r3, #0
	beq _08116748
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08116706
	rsbs r1, r1, #0
_08116706:
	cmp r1, #0x20
	bgt _08116748
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0811673C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08116740 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08116744 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08116CD0
	.align 2, 0
_08116738: .4byte 0x0000A007
_0811673C: .4byte 0x000004BE
_08116740: .4byte 0x0000048C
_08116744: .4byte 0x0000044E
_08116748:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08116770 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08116778
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116774 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_08116770: .4byte 0x0000048A
_08116774: .4byte 0x03002BE0
_08116778:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08116794
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08116790 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_08116790: .4byte 0x03002BE0
_08116794:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081167B0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081167AC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_081167AC: .4byte 0x03002BE0
_081167B0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081167CC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081167C8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_081167C8: .4byte 0x03002BE0
_081167CC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081167DE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081167E6
_081167DE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081167E8
_081167E6:
	movs r3, #1
_081167E8:
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
	ldr r5, _0811681C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0811680A
	b _08116960
_0811680A:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116820
	movs r0, #1
	b _08116822
	.align 2, 0
_0811681C: .4byte 0x0000049C
_08116820:
	movs r0, #0
_08116822:
	cmp r0, #0
	bne _08116906
	b _0811691C
_08116828:
	strh r2, [r7, #0x3e]
	ldr r1, _08116850 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08116858
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116854 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_08116850: .4byte 0x0000048A
_08116854: .4byte 0x03002BE0
_08116858:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08116874
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08116870 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_08116870: .4byte 0x03002BE0
_08116874:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08116890
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0811688C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_0811688C: .4byte 0x03002BE0
_08116890:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081168AC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081168A8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_081168A8: .4byte 0x03002BE0
_081168AC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081168BE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081168C6
_081168BE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081168C8
_081168C6:
	movs r3, #1
_081168C8:
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
	ldr r5, _081168FC @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08116960
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116900
	movs r0, #1
	b _08116902
	.align 2, 0
_081168FC: .4byte 0x0000049C
_08116900:
	movs r0, #0
_08116902:
	cmp r0, #0
	beq _0811691C
_08116906:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116918 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08116928
	.align 2, 0
_08116918: .4byte 0x03002BE0
_0811691C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08116960
_08116928:
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
_08116960:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0811698C
	ldr r5, _08116998 @ =0x0000024E
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
	bls _0811698C
	strh r1, [r2]
_0811698C:
	ldr r5, _0811699C @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08116CD0
	.align 2, 0
_08116998: .4byte 0x0000024E
_0811699C: .4byte 0x0000048C
_081169A0:
	ldr r0, _081169B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081169B8
	movs r0, #1
	b _081169BA
	.align 2, 0
_081169B4: .4byte 0x030047A4
_081169B8:
	movs r0, #0
_081169BA:
	cmp r0, #0
	beq _081169C8
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081169D0
_081169C8:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081169D0:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08116A08 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08116A0C @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081169FE
	cmp r2, #0x17
	bne _08116A10
_081169FE:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08116A32
	.align 2, 0
_08116A08: .4byte 0x0000048C
_08116A0C: .4byte 0x000001DF
_08116A10:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081169FE
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08116A60 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08116A32
	movs r1, #0
_08116A32:
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
	beq _08116A6E
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08116A64
	asrs r0, r0, #1
	b _08116A6A
	.align 2, 0
_08116A60: .4byte 0x00000187
_08116A64:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08116A6A:
	mov r2, sb
	strh r0, [r2]
_08116A6E:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08116A8C
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08116A88 @ =0x000001DD
	adds r1, r6, r4
	b _08116B00
	.align 2, 0
_08116A88: .4byte 0x000001DD
_08116A8C:
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
	bne _08116AEC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08116AEC
	ldr r2, _08116ADC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08116AE0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08116AE4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08116AE8 @ =0x000001DD
	adds r1, r6, r4
	b _08116B00
	.align 2, 0
_08116ADC: .4byte 0x030046B8
_08116AE0: .4byte 0x000003FF
_08116AE4: .4byte 0x0203B400
_08116AE8: .4byte 0x000001DD
_08116AEC:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08116B20 @ =0x000001DD
	adds r1, r6, r3
_08116B00:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08116B28
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08116B24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B20: .4byte 0x000001DD
_08116B24: .4byte 0x03002BE0
_08116B28:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08116B44
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08116B40 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B40: .4byte 0x03002BE0
_08116B44:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08116B60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116B5C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B5C: .4byte 0x03002BE0
_08116B60:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08116B7C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08116B78 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B78: .4byte 0x03002BE0
_08116B7C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08116B8E
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08116B96
_08116B8E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08116B98
_08116B96:
	movs r3, #1
_08116B98:
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
	ldr r5, _08116BCC @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08116C34
	movs r1, #2
	ldr r2, _08116BD0 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116BD4
	movs r0, #1
	b _08116BD6
	.align 2, 0
_08116BCC: .4byte 0x0000049C
_08116BD0: .4byte 0x00000474
_08116BD4:
	movs r0, #0
_08116BD6:
	cmp r0, #0
	beq _08116BF0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116BEC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08116BFC
	.align 2, 0
_08116BEC: .4byte 0x03002BE0
_08116BF0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08116C34
_08116BFC:
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
_08116C34:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08116C68
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08116C68
	ldr r0, _08116C80 @ =0x0000024E
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
	bls _08116C68
	strh r1, [r2]
_08116C68:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08116C84 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08116C88 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116C8C
	movs r0, #1
	b _08116C8E
	.align 2, 0
_08116C80: .4byte 0x0000024E
_08116C84: .4byte 0x030046A0
_08116C88: .4byte 0x00000934
_08116C8C:
	movs r0, #0
_08116C8E:
	ldr r1, _08116CE0 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08116CA6
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_08116CA6:
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
_08116CD0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08116CE0: .4byte 0x0000048A
