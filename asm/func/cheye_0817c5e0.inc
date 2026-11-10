	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r1, _0817C680 @ =0x08252198
	ldr r2, _0817C684 @ =0x0000017F
	adds r0, r7, #0
	bl Enemy_ClearPendingState
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0x8a
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0817C6A4
	ldrb r1, [r7, #5]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl FUN_0817c094
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817C632
	b _0817CD94
_0817C632:
	ldr r2, _0817C688 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r5, _0817C68C @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0817C690 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r4, [r0]
	movs r2, #0xf
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0817C694 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0817C698 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0817C69C @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _0817C6A0 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	b _0817CD94
	.align 2, 0
_0817C680: .4byte 0x08252198
_0817C684: .4byte 0x0000017F
_0817C688: .4byte Enemy_ClearStateBegun
_0817C68C: .4byte 0x0000046D
_0817C690: .4byte 0x0000046B
_0817C694: .4byte 0x00000469
_0817C698: .4byte 0x0000046A
_0817C69C: .4byte 0x00000484
_0817C6A0: .4byte 0x0000046C
_0817C6A4:
	ldr r5, _0817C6F0 @ =0x000008A4
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r2, r0
	bhi _0817C6B0
	b _0817CD48
_0817C6B0:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x54]
	str r2, [sp, #0x5c]
	cmp r4, #0
	blt _0817C6EC
	cmp r1, #0
	blt _0817C6EC
	ldr r0, _0817C6F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0817C6EC
	ldr r0, _0817C6F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C6FC
_0817C6EC:
	movs r4, #0
	b _0817C70A
	.align 2, 0
_0817C6F0: .4byte 0x000008A4
_0817C6F4: .4byte 0x030046A8
_0817C6F8: .4byte 0x030046AC
_0817C6FC:
	ldr r0, _0817C71C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0817C70A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817C720
	adds r0, #4
	b _0817C72C
	.align 2, 0
_0817C71C: .4byte 0x030046A4
_0817C720:
	ldr r0, _0817C740 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817C72C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817C744
	cmp r2, #2
	beq _0817C748
	b _0817C74C
	.align 2, 0
_0817C740: .4byte 0x030046A4
_0817C744:
	ldrb r0, [r5, #4]
	b _0817C74A
_0817C748:
	ldrb r0, [r5]
_0817C74A:
	subs r1, r1, r0
_0817C74C:
	strh r1, [r5, #2]
	ldr r0, _0817C760 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817C764
	movs r0, #1
	b _0817C766
	.align 2, 0
_0817C760: .4byte 0x030047A4
_0817C764:
	movs r0, #0
_0817C766:
	cmp r0, #0
	beq _0817C7A4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0817C786
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0817C782
	adds r2, r0, #0
_0817C782:
	cmp r2, #0
	bge _0817C790
_0817C786:
	ldr r2, _0817C78C @ =0x000005C4
	adds r0, r7, r2
	b _0817CCC4
	.align 2, 0
_0817C78C: .4byte 0x000005C4
_0817C790:
	ldr r1, _0817C7A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0817C7EC
	.align 2, 0
_0817C7A0: .4byte 0x03002BE0
_0817C7A4:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817C7D0
	cmp r1, #0
	blt _0817C7D0
	ldr r0, _0817C7D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817C7D0
	ldr r0, _0817C7D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C7DC
_0817C7D0:
	movs r5, #0
	b _0817C7EA
	.align 2, 0
_0817C7D4: .4byte 0x030046A8
_0817C7D8: .4byte 0x030046AC
_0817C7DC:
	ldr r0, _0817C82C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0817C7EA:
	movs r2, #0
_0817C7EC:
	ldr r4, _0817C830 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0817C80C
	ldr r1, _0817C834 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0817C80C
	b _0817CC08
_0817C80C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x3c]
	cmp r1, #0
	beq _0817C838
	movs r0, #0
	b _0817CCDA
	.align 2, 0
_0817C82C: .4byte 0x030046A4
_0817C830: .4byte 0x00000256
_0817C834: .4byte 0x03002BE0
_0817C838:
	ldr r6, _0817C8D8 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x3c]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x60]
	cmp r6, #0
	beq _0817C8EC
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0817C8DC @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #8]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0817C8E0 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0xc]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0817C8E4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0817C8E8 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #8]
	str r6, [sp, #0x48]
	mov r6, r8
	str r6, [sp, #0x40]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x78]
	mov r6, sl
	str r6, [sp, #0x7c]
	str r5, [sp, #0x58]
	str r4, [sp, #0x30]
	str r3, [sp, #0x34]
	str r2, [sp, #0x38]
	str r1, [sp, #0x50]
	str r0, [sp, #0x44]
	b _0817CABE
	.align 2, 0
_0817C8D8: .4byte 0x00000222
_0817C8DC: .4byte 0x0000046D
_0817C8E0: .4byte 0x0000046B
_0817C8E4: .4byte 0x00000469
_0817C8E8: .4byte 0x00000484
_0817C8EC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0817C9B0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _0817C9B4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0817C9B8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x20]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x24]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0817C9BC @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0817C9C0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0817C9C4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x54]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x5c]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x5c]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x28]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x40]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x78]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x7c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x58]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x30]
	str r5, [sp, #0x34]
	str r4, [sp, #0x38]
	str r3, [sp, #0x50]
	str r2, [sp, #0x44]
	mov r0, ip
	cmp r0, #0
	blt _0817C9AA
	cmp r1, #0
	blt _0817C9AA
	ldr r0, _0817C9C8 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0817C9AA
	ldr r0, _0817C9CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817C9D0
_0817C9AA:
	movs r4, #0
	b _0817C9E0
	.align 2, 0
_0817C9B0: .4byte 0x0000046D
_0817C9B4: .4byte 0x0000046B
_0817C9B8: .4byte 0x00000553
_0817C9BC: .4byte 0x00000469
_0817C9C0: .4byte 0x00000484
_0817C9C4: .4byte 0x0000046C
_0817C9C8: .4byte 0x030046A8
_0817C9CC: .4byte 0x030046AC
_0817C9D0:
	ldr r0, _0817C9F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0817C9E0:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817C9F4
	adds r0, #4
	b _0817CA00
	.align 2, 0
_0817C9F0: .4byte 0x030046A4
_0817C9F4:
	ldr r0, _0817CA14 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817CA00:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817CA18
	cmp r2, #2
	beq _0817CA1E
	b _0817CA24
	.align 2, 0
_0817CA14: .4byte 0x030046A4
_0817CA18:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _0817CA22
_0817CA1E:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_0817CA22:
	subs r1, r1, r0
_0817CA24:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x54]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817CA50
	cmp r1, #0
	blt _0817CA50
	ldr r0, _0817CA54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817CA50
	ldr r0, _0817CA58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817CA5C
_0817CA50:
	movs r4, #0
	b _0817CA6A
	.align 2, 0
_0817CA54: .4byte 0x030046A8
_0817CA58: .4byte 0x030046AC
_0817CA5C:
	ldr r0, _0817CA80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0817CA6A:
	ldr r6, [sp, #0x54]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817CA84
	adds r0, #4
	b _0817CA90
	.align 2, 0
_0817CA80: .4byte 0x030046A4
_0817CA84:
	ldr r0, _0817CAA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817CA90:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817CAA8
	cmp r3, #2
	beq _0817CAAC
	b _0817CAB0
	.align 2, 0
_0817CAA4: .4byte 0x030046A4
_0817CAA8:
	ldrb r0, [r5, #4]
	b _0817CAAE
_0817CAAC:
	ldrb r0, [r5]
_0817CAAE:
	subs r2, r2, r0
_0817CAB0:
	ldr r1, [sp, #0x54]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x54]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0817CABE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x3c]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r5, _0817CAE8 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	cmp r0, #0
	bne _0817CBCC
	movs r1, #4
	ldr r6, [sp, #0x60]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0817CAEC
	movs r0, #1
	b _0817CAEE
	.align 2, 0
_0817CAE8: .4byte 0x00000482
_0817CAEC:
	movs r0, #0
_0817CAEE:
	ldr r1, _0817CBDC @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	cmp r0, #0
	bne _0817CBCC
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _0817CBE0 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _0817CBE4 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	ldr r0, _0817CBE8 @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x70]
	ldr r1, _0817CBEC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x74]
	ldr r2, _0817CBF0 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r4, _0817CBF4 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x80]
	ldr r5, _0817CBF8 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r6, _0817CBFC @ =0x0203B400
	ldr r1, _0817CC00 @ =0x030046B8
	ldr r5, _0817CC04 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0817CB3E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0817CB5C
	adds r3, #1
	cmp r3, #3
	ble _0817CB3E
	mov r0, r8
_0817CB5C:
	movs r3, #0
	mov r6, sb
	strb r0, [r6]
	ldr r1, [sp, #0x7c]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x78]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x30]
	ldrb r0, [r6]
	ldr r1, [sp, #0x6c]
	strb r0, [r1]
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r5, [sp, #0x38]
	ldrb r0, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x64]
	strb r1, [r0]
	ldr r1, [sp, #0x80]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x40]
	strb r3, [r5]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	ldr r0, [sp, #0x7c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x58]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x30]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	strb r1, [r6]
	ldr r0, [sp, #0x38]
	strb r2, [r0]
	ldr r2, [sp, #0x50]
	str r3, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x68]
	strb r0, [r4]
_0817CBCC:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x4c]
	strh r0, [r5]
	movs r0, #0
	b _0817CCDA
	.align 2, 0
_0817CBDC: .4byte 0x00000482
_0817CBE0: .4byte 0x0000054F
_0817CBE4: .4byte 0x0000054C
_0817CBE8: .4byte 0x0000054D
_0817CBEC: .4byte 0x0000054E
_0817CBF0: .4byte 0x00000541
_0817CBF4: .4byte 0x000005BC
_0817CBF8: .4byte 0x00000542
_0817CBFC: .4byte 0x0203B400
_0817CC00: .4byte 0x030046B8
_0817CC04: .4byte 0x000003FF
_0817CC08:
	mov sb, sp
	ldr r6, _0817CC44 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817CC48
	adds r0, #4
	b _0817CC52
	.align 2, 0
_0817CC44: .4byte 0x030046A4
_0817CC48:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817CC52:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0817CC88 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0817CC8C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0817CCB2
	.align 2, 0
_0817CC88: .4byte 0x000004A4
_0817CC8C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0817CCAC
	cmp r0, #2
	beq _0817CCA8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0817CCA8:
	movs r0, #1
	b _0817CCBC
_0817CCAC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0817CCB2:
	ldr r1, _0817CCD0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0817CCBC:
	cmp r0, #0
	bne _0817CCD8
	ldr r3, _0817CCD4 @ =0x000005C4
	adds r0, r7, r3
_0817CCC4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0817CCDA
	.align 2, 0
_0817CCD0: .4byte 0xFFFFFDFF
_0817CCD4: .4byte 0x000005C4
_0817CCD8:
	movs r0, #1
_0817CCDA:
	cmp r0, #0
	beq _0817CD94
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r5, _0817CD34 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0817CD38 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0817CD3C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0817CD40 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0817CD44 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0817CD94
	.align 2, 0
_0817CD34: .4byte 0x0000046D
_0817CD38: .4byte 0x0000046B
_0817CD3C: .4byte 0x00000469
_0817CD40: .4byte 0x0000046A
_0817CD44: .4byte 0x00000484
_0817CD48:
	movs r2, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	movs r3, #0
	strb r2, [r0]
	ldr r2, _0817CDA4 @ =0x00000469
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _0817CDA8 @ =0x0000046A
	adds r0, r7, r4
	strb r3, [r0]
	ldr r5, _0817CDAC @ =0x00000484
	adds r0, r7, r5
	str r3, [r0]
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r4, _0817CDB0 @ =FUN_0818069c
	movs r2, #0x27
	subs r5, #0x17
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #1
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _0817CDB4 @ =0x00000553
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
_0817CD94:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817CDA4: .4byte 0x00000469
_0817CDA8: .4byte 0x0000046A
_0817CDAC: .4byte 0x00000484
_0817CDB0: .4byte FUN_0818069c
_0817CDB4: .4byte 0x00000553
