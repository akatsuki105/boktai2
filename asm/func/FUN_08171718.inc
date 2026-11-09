	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08171740 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171744
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171746
	.align 2, 0
_08171740: .4byte 0x0000046D
_08171744:
	movs r0, #0
_08171746:
	cmp r0, #0
	beq _0817177C
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl Sandworm_GetAnimVariant
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_0817734c
	movs r0, #2
	ldr r7, _081717D4 @ =0x00001008
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0817177C:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	str r6, [sp]
	mov r0, sp
	ldr r2, _081717D8 @ =0x05000002
	bl CpuSet
	ldr r1, _081717DC @ =0x00001022
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _0817179C
	adds r2, #0x64
_0817179C:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r2
	blt _081717F0
	ldr r3, _081717E0 @ =FUN_081719b4
	movs r2, #0x26
	ldr r0, _081717E4 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081717E8 @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	ldr r7, _081717EC @ =0x00000553
	adds r0, r4, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r6, [r0]
	b _081719A0
	.align 2, 0
_081717D4: .4byte 0x00001008
_081717D8: .4byte 0x05000002
_081717DC: .4byte 0x00001022
_081717E0: .4byte FUN_081719b4
_081717E4: .4byte 0x0000046D
_081717E8: .4byte 0x0000046B
_081717EC: .4byte 0x00000553
_081717F0:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _08171804
	movs r6, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _0817180A
_08171804:
	movs r6, #2
	ldrh r0, [r1]
	adds r0, #0x28
_0817180A:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _08171830 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	cmp r0, #0
	blt _08171834
	asrs r1, r0, #0xc
	b _0817183A
	.align 2, 0
_08171830: .4byte gSineTable
_08171834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817183A:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08171852
	asrs r2, r0, #0xc
	b _08171858
_08171852:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171858:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldr r3, _081718A4 @ =0x00002EE0
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0xc
	bl FUN_08177d34
	movs r2, #0
	mov sb, r2
	mov ip, r2
	ldr r3, _081718A8 @ =0x00001012
	adds r0, r5, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp ip, r0
	blt _0817187E
	b _081719A0
_0817187E:
	ldr r3, _081718AC @ =gSineTable
	movs r6, #0
	ldr r0, _081718B0 @ =0x00000674
	adds r2, r5, r0
	movs r1, #0x92
	lsls r1, r1, #1
	mov r8, r1
_0817188C:
	adds r0, r6, r5
	movs r7, #2
	mov sl, r7
	ldr r1, _081718B4 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _081718B8
	movs r0, #1
	b _081718BA
	.align 2, 0
_081718A4: .4byte 0x00002EE0
_081718A8: .4byte 0x00001012
_081718AC: .4byte gSineTable
_081718B0: .4byte 0x00000674
_081718B4: .4byte 0x00000755
_081718B8:
	movs r0, #0
_081718BA:
	cmp r0, #0
	beq _0817198A
	adds r0, r6, r5
	movs r1, #5
	ldr r7, _081718D4 @ =0x00000755
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081718D8
	movs r0, #1
	b _081718DA
	.align 2, 0
_081718D4: .4byte 0x00000755
_081718D8:
	movs r0, #0
_081718DA:
	cmp r0, #0
	bne _0817198A
	mov r0, sb
	cmp r0, #0
	beq _081718F0
	cmp r0, #1
	beq _08171938
	ldrh r0, [r4, #8]
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	b _08171984
_081718F0:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov sl, r1
	movs r0, #0x36
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08171912
	asrs r1, r0, #0xc
	b _08171918
_08171912:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171918:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r7, [r0, r1]
	mov sl, r7
	movs r0, #0x36
	mov r7, sl
	muls r7, r0, r7
	adds r0, r7, #0
	cmp r0, #0
	bge _08171976
	b _0817197A
_08171938:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08171956
	asrs r1, r0, #0xc
	b _0817195C
_08171956:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817195C:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0817197A
_08171976:
	asrs r1, r0, #0xc
	b _08171980
_0817197A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171980:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
_08171984:
	strh r0, [r2, #4]
	movs r0, #1
	add sb, r0
_0817198A:
	add r6, r8
	add r2, r8
	movs r1, #1
	add ip, r1
	ldr r7, _081719B0 @ =0x00001012
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _081719A0
	b _0817188C
_081719A0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081719B0: .4byte 0x00001012
