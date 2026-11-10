	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	str r0, [sp, #0x10]
	movs r1, #2
	ldr r2, _0815D6F0 @ =0x00000222
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815D6F4
	movs r0, #1
	b _0815D6F6
	.align 2, 0
_0815D6F0: .4byte 0x00000222
_0815D6F4:
	movs r0, #0
_0815D6F6:
	cmp r0, #0
	beq _0815D6FE
	bl _0815E834
_0815D6FE:
	movs r2, #1
	ldr r3, [sp, #0x10]
	ldr r4, _0815D714 @ =0x00000222
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x7c]
	cmp r0, #0
	beq _0815D718
	movs r0, #1
	b _0815D71A
	.align 2, 0
_0815D714: .4byte 0x00000222
_0815D718:
	movs r0, #0
_0815D71A:
	cmp r0, #0
	bne _0815D722
	bl _0815E834
_0815D722:
	ldr r5, [sp, #0x10]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r7, #0xa
	ldrsh r1, [r5, r7]
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0815D73A
	b _0815DD88
_0815D73A:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r5, r4
	ldr r5, [r3]
	ldr r2, [sp, #0x10]
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
	str r3, [sp, #0x5c]
	str r2, [sp, #0x38]
	cmp r4, #0
	blt _0815D776
	cmp r1, #0
	blt _0815D776
	ldr r0, _0815D77C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0815D776
	ldr r0, _0815D780 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815D784
_0815D776:
	movs r4, #0
	b _0815D792
	.align 2, 0
_0815D77C: .4byte 0x030046A8
_0815D780: .4byte 0x030046AC
_0815D784:
	ldr r0, _0815D7A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815D792:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815D7A8
	adds r0, #4
	b _0815D7B4
	.align 2, 0
_0815D7A4: .4byte 0x030046A4
_0815D7A8:
	ldr r0, _0815D7C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D7B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815D7CC
	cmp r2, #2
	beq _0815D7D0
	b _0815D7D4
	.align 2, 0
_0815D7C8: .4byte 0x030046A4
_0815D7CC:
	ldrb r0, [r5, #4]
	b _0815D7D2
_0815D7D0:
	ldrb r0, [r5]
_0815D7D2:
	subs r1, r1, r0
_0815D7D4:
	strh r1, [r5, #2]
	ldr r0, _0815D7E8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815D7EC
	movs r0, #1
	b _0815D7EE
	.align 2, 0
_0815D7E8: .4byte 0x030047A4
_0815D7EC:
	movs r0, #0
_0815D7EE:
	cmp r0, #0
	beq _0815D838
	ldr r5, [sp, #0x10]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0815D810
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815D80C
	adds r2, r0, #0
_0815D80C:
	cmp r2, #0
	bge _0815D824
_0815D810:
	ldr r7, [sp, #0x10]
	ldr r1, _0815D820 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0815DD70
	.align 2, 0
_0815D820: .4byte 0x000005C4
_0815D824:
	ldr r1, _0815D834 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815D884
	.align 2, 0
_0815D834: .4byte 0x03002BE0
_0815D838:
	ldr r2, [sp, #0x10]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815D866
	cmp r1, #0
	blt _0815D866
	ldr r0, _0815D86C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815D866
	ldr r0, _0815D870 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815D874
_0815D866:
	movs r5, #0
	b _0815D882
	.align 2, 0
_0815D86C: .4byte 0x030046A8
_0815D870: .4byte 0x030046AC
_0815D874:
	ldr r0, _0815D968 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815D882:
	movs r2, #0
_0815D884:
	ldr r4, [sp, #0x10]
	ldr r6, _0815D96C @ =0x00000256
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815D8A6
	ldr r1, _0815D970 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815D8A6
	b _0815DCA8
_0815D8A6:
	movs r0, #0x80
	lsls r0, r0, #3
	ldr r7, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	str r2, [sp, #0x60]
	cmp r7, #0
	beq _0815D8C2
	b _0815DD70
_0815D8C2:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0x7c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x60]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0815D988
	ldr r4, [sp, #0x10]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0815D974 @ =0x0000046D
	adds r4, r4, r6
	mov ip, r4
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r4]
	ldr r4, [sp, #0x10]
	ldr r5, _0815D978 @ =0x0000046B
	adds r4, r4, r5
	mov sl, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, [sp, #0x10]
	ldr r3, _0815D97C @ =0x00000553
	adds r2, r2, r3
	mov r8, r2
	strb r0, [r2]
	movs r5, #0xaf
	lsls r5, r5, #3
	ldr r4, [sp, #0x10]
	adds r5, r4, r5
	str r5, [sp, #0x88]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r4, r6
	strh r7, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, [sp, #0x10]
	adds r1, #1
	adds r3, r6, r1
	strb r2, [r3]
	adds r1, #1
	adds r2, r6, r1
	strb r0, [r2]
	ldr r0, _0815D980 @ =0x00000484
	adds r1, r6, r0
	str r7, [r1]
	ldr r7, _0815D984 @ =0x0000046C
	adds r0, r6, r7
	mov r6, sb
	strb r6, [r0]
	mov r7, ip
	str r7, [sp, #0x50]
	mov r6, sl
	str r6, [sp, #0x48]
	mov r7, r8
	str r7, [sp, #0x70]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0x78]
	str r5, [sp, #0x74]
	str r4, [sp, #0x3c]
	str r3, [sp, #0x40]
	str r2, [sp, #0x44]
	str r1, [sp, #0x58]
	str r0, [sp, #0x4c]
	b _0815DB58
	.align 2, 0
_0815D968: .4byte 0x030046A4
_0815D96C: .4byte 0x00000256
_0815D970: .4byte 0x03002BE0
_0815D974: .4byte 0x0000046D
_0815D978: .4byte 0x0000046B
_0815D97C: .4byte 0x00000553
_0815D980: .4byte 0x00000484
_0815D984: .4byte 0x0000046C
_0815D988:
	ldr r7, [sp, #0x10]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0815DA4C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	adds r4, r7, #0
	ldr r5, _0815DA50 @ =0x0000046B
	adds r4, r4, r5
	mov ip, r4
	movs r6, #0
	strb r6, [r4]
	ldr r3, _0815DA54 @ =0x00000553
	adds r7, r7, r3
	mov sl, r7
	strb r0, [r7]
	ldr r4, [sp, #0x10]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r4, r4, r5
	mov sb, r4
	str r1, [r4]
	ldr r6, [sp, #0x10]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r6, r6, r7
	mov r8, r6
	strh r2, [r6]
	movs r1, #5
	ldr r3, [sp, #0x10]
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r6, r3, r4
	movs r5, #0
	strb r5, [r6]
	ldr r7, _0815DA58 @ =0x00000469
	adds r5, r3, r7
	movs r3, #0
	strb r3, [r5]
	ldr r7, [sp, #0x10]
	ldr r3, _0815DA5C @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r1, _0815DA60 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	subs r1, #0x18
	adds r2, r7, r1
	strb r0, [r2]
	ldr r7, [sp, #0x5c]
	ldr r7, [r7]
	str r7, [sp, #0x1c]
	ldr r1, [sp, #0x38]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r7]
	ldr r7, [sp, #0x38]
	ldr r0, [r7, #8]
	ldrh r0, [r0, #2]
	ldr r7, [sp, #0x1c]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	asrs r7, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x50]
	mov r0, ip
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x70]
	mov r0, sb
	str r0, [sp, #0x78]
	mov r0, r8
	str r0, [sp, #0x74]
	str r6, [sp, #0x3c]
	str r5, [sp, #0x40]
	str r4, [sp, #0x44]
	str r3, [sp, #0x58]
	str r2, [sp, #0x4c]
	cmp r7, #0
	blt _0815DA48
	cmp r1, #0
	blt _0815DA48
	ldr r0, _0815DA64 @ =0x030046A8
	ldr r0, [r0]
	cmp r7, r0
	bhs _0815DA48
	ldr r0, _0815DA68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815DA6C
_0815DA48:
	movs r7, #0
	b _0815DA7A
	.align 2, 0
_0815DA4C: .4byte 0x0000046D
_0815DA50: .4byte 0x0000046B
_0815DA54: .4byte 0x00000553
_0815DA58: .4byte 0x00000469
_0815DA5C: .4byte 0x0000046A
_0815DA60: .4byte 0x00000484
_0815DA64: .4byte 0x030046A8
_0815DA68: .4byte 0x030046AC
_0815DA6C:
	ldr r0, _0815DA8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r7
_0815DA7A:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815DA90
	adds r0, #4
	b _0815DA9C
	.align 2, 0
_0815DA8C: .4byte 0x030046A4
_0815DA90:
	ldr r0, _0815DAB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815DA9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815DAB4
	cmp r2, #2
	beq _0815DABA
	b _0815DAC0
	.align 2, 0
_0815DAB0: .4byte 0x030046A4
_0815DAB4:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _0815DABE
_0815DABA:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_0815DABE:
	subs r1, r1, r0
_0815DAC0:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815DAEC
	cmp r1, #0
	blt _0815DAEC
	ldr r0, _0815DAF0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815DAEC
	ldr r0, _0815DAF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815DAF8
_0815DAEC:
	movs r7, #0
	b _0815DB06
	.align 2, 0
_0815DAF0: .4byte 0x030046A8
_0815DAF4: .4byte 0x030046AC
_0815DAF8:
	ldr r0, _0815DB1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_0815DB06:
	ldr r6, [sp, #0x5c]
	ldr r4, [r6]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815DB20
	adds r0, #4
	b _0815DB2C
	.align 2, 0
_0815DB1C: .4byte 0x030046A4
_0815DB20:
	ldr r0, _0815DB40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815DB2C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815DB44
	cmp r3, #2
	beq _0815DB48
	b _0815DB4C
	.align 2, 0
_0815DB40: .4byte 0x030046A4
_0815DB44:
	ldrb r0, [r4, #4]
	b _0815DB4A
_0815DB48:
	ldrb r0, [r4]
_0815DB4A:
	subs r2, r2, r0
_0815DB4C:
	ldr r7, [sp, #0x5c]
	ldr r0, [r7]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r7]
	strh r1, [r0, #6]
_0815DB58:
	ldr r0, [sp, #0x10]
	ldrb r0, [r0, #5]
	str r0, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	ldr r4, [sp, #0x20]
	ldr r5, _0815DB88 @ =0x00000482
	ldr r3, [sp, #0x10]
	adds r5, r3, r5
	str r5, [sp, #0x54]
	cmp r0, #0
	beq _0815DB78
	b _0815DC78
_0815DB78:
	movs r1, #4
	ldr r6, [sp, #0x7c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815DB8C
	movs r0, #1
	b _0815DB8E
	.align 2, 0
_0815DB88: .4byte 0x00000482
_0815DB8C:
	movs r0, #0
_0815DB8E:
	ldr r1, _0815DC88 @ =0x00000482
	ldr r7, [sp, #0x10]
	adds r1, r7, r1
	str r1, [sp, #0x54]
	cmp r0, #0
	bne _0815DC78
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x88]
	adds r5, r7, #0
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r5, r5, r6
	mov r8, r5
	ldr r0, _0815DC8C @ =0x0000054F
	adds r7, r7, r0
	mov sb, r7
	ldr r1, [sp, #0x10]
	ldr r2, _0815DC90 @ =0x0000054C
	adds r1, r1, r2
	mov sl, r1
	ldr r5, [sp, #0x10]
	adds r6, #5
	adds r5, r5, r6
	mov ip, r5
	subs r0, #1
	ldr r7, [sp, #0x10]
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _0815DC94 @ =0x00000541
	adds r1, r7, r1
	str r1, [sp, #0x64]
	adds r2, #0x70
	adds r2, r7, r2
	str r2, [sp, #0x80]
	ldr r5, _0815DC98 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r1, _0815DC9C @ =0x030046B8
	ldr r5, _0815DCA0 @ =0x000003FF
	movs r2, #3
	str r4, [sp, #0x8c]
_0815DBE6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0815DCA4 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	ldr r7, [sp, #0x8c]
	cmp r0, r7
	bne _0815DC08
	adds r3, #1
	cmp r3, #3
	ble _0815DBE6
	adds r0, r4, #0
_0815DC08:
	movs r3, #0
	ldr r1, [sp, #0x88]
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	mov r4, r8
	str r0, [r4]
	ldr r5, [sp, #0x70]
	ldrb r0, [r5]
	mov r6, sb
	strb r0, [r6]
	ldr r7, [sp, #0x3c]
	ldrb r0, [r7]
	mov r1, sl
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	mov r4, ip
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0x6c]
	strb r0, [r6]
	add r7, sp, #0x20
	ldrb r0, [r7]
	ldr r7, [sp, #0x64]
	strb r0, [r7]
	ldr r0, [sp, #0x80]
	ldr r2, [r0]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x50]
	strb r1, [r4]
	ldr r5, [sp, #0x48]
	strb r3, [r5]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r7, [sp, #0x78]
	str r2, [r7]
	movs r2, #0
	ldr r0, [sp, #0x74]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r2, [r6]
	ldr r7, [sp, #0x58]
	str r3, [r7]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x68]
	strb r0, [r1]
_0815DC78:
	ldr r0, [sp, #0x10]
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	b _0815DD70
	.align 2, 0
_0815DC88: .4byte 0x00000482
_0815DC8C: .4byte 0x0000054F
_0815DC90: .4byte 0x0000054C
_0815DC94: .4byte 0x00000541
_0815DC98: .4byte 0x00000542
_0815DC9C: .4byte 0x030046B8
_0815DCA0: .4byte 0x000003FF
_0815DCA4: .4byte 0x0203B400
_0815DCA8:
	mov r8, sp
	ldr r6, _0815DCE4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815DCE8
	adds r0, #4
	b _0815DCF2
	.align 2, 0
_0815DCE4: .4byte 0x030046A4
_0815DCE8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815DCF2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r2, [sp, #0x10]
	ldr r3, _0815DD28 @ =0x000004A4
	adds r0, r2, r3
	ldr r4, [r0]
	adds r5, r2, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815DD2C
	ldr r4, [sp, #0x10]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	b _0815DD54
	.align 2, 0
_0815DD28: .4byte 0x000004A4
_0815DD2C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815DD4C
	cmp r0, #2
	beq _0815DD48
	ldr r0, [sp, #0x10]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815DD48:
	movs r0, #1
	b _0815DD5E
_0815DD4C:
	ldr r6, [sp, #0x10]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_0815DD54:
	ldr r1, _0815DD80 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815DD5E:
	cmp r0, #0
	bne _0815DD70
	ldr r1, [sp, #0x10]
	ldr r2, _0815DD84 @ =0x000005C4
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	bl _call_via_r1
_0815DD70:
	movs r0, #2
	ldr r3, [sp, #0x7c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #1
	bl _0815E836
	.align 2, 0
_0815DD80: .4byte 0xFFFFFDFF
_0815DD84: .4byte 0x000005C4
_0815DD88:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4, #5]
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bne _0815DD9A
	b _0815E044
_0815DD9A:
	cmp r1, #1
	bgt _0815DDA4
	cmp r1, #0
	beq _0815DDB0
	b _0815E2B8
_0815DDA4:
	cmp r1, #2
	beq _0815DDB0
	cmp r1, #3
	bne _0815DDAE
	b _0815E044
_0815DDAE:
	b _0815E2B8
_0815DDB0:
	ldr r5, [sp, #0x10]
	ldr r6, _0815DDE4 @ =0x00000256
	adds r4, r5, r6
	ldrh r1, [r4]
	ldr r5, _0815DDE8 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r0, r1, r0
	mov r8, r0
	adds r7, r1, #0
	ldr r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	str r4, [sp, #0x84]
	cmp r0, #0
	beq _0815DDEC
	adds r0, #4
	b _0815DDF6
	.align 2, 0
_0815DDE4: .4byte 0x00000256
_0815DDE8: .4byte 0x030046A4
_0815DDEC:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815DDF6:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	ldr r2, _0815DE20 @ =0x030046A4
	mov sl, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x24]
	cmp r7, r8
	bge _0815DE8C
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DE2C
	.align 2, 0
_0815DE20: .4byte 0x030046A4
_0815DE24:
	cmp r5, r8
	beq _0815DE88
	adds r5, #1
	adds r6, #1
_0815DE2C:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815DE4C
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DE24
_0815DE4C:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r7, r0
	b _0815DE6A
_0815DE5A:
	cmp r5, r8
	beq _0815DE88
	ldr r0, _0815DE84 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815DE6A:
	ldr r0, [sp, #0x24]
	cmp r0, r5
	ble _0815DEEE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DE5A
	b _0815DEEE
	.align 2, 0
_0815DE84: .4byte 0x030046A4
_0815DE88:
	movs r0, #1
	b _0815DEF0
_0815DE8C:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DEA0
_0815DE98:
	cmp r5, r8
	beq _0815DE88
	subs r5, #1
	subs r6, #1
_0815DEA0:
	cmp r6, #0
	blt _0815DEB6
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DE98
_0815DEB6:
	ldr r0, _0815DEC4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r7, r0
	b _0815DED8
	.align 2, 0
_0815DEC4: .4byte 0x030046A4
_0815DEC8:
	cmp r5, r8
	beq _0815DE88
	ldr r0, _0815DEFC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815DED8:
	cmp r5, #0
	blt _0815DEEE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DEC8
_0815DEEE:
	movs r0, #0
_0815DEF0:
	cmp r0, #0
	beq _0815DF00
	movs r3, #3
	str r3, [sp, #0x14]
	b _0815E2C6
	.align 2, 0
_0815DEFC: .4byte 0x030046A4
_0815DF00:
	ldr r4, [sp, #0x84]
	ldrh r1, [r4]
	ldr r5, _0815DF2C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r0, r0, r1
	mov r8, r0
	adds r4, r1, #0
	ldr r7, [sp, #0x10]
	movs r0, #0xa
	ldrsh r7, [r7, r0]
	mov sb, r7
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815DF30
	adds r0, #4
	b _0815DF3A
	.align 2, 0
_0815DF2C: .4byte 0x030046A4
_0815DF30:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815DF3A:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, _0815DF64 @ =0x030046A4
	mov sl, r1
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	str r5, [sp, #0x28]
	cmp r4, r8
	bge _0815DFD0
	adds r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DF70
	.align 2, 0
_0815DF64: .4byte 0x030046A4
_0815DF68:
	cmp r5, r8
	beq _0815DFCC
	adds r5, #1
	adds r6, #1
_0815DF70:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815DF90
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DF68
_0815DF90:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _0815DFAE
_0815DF9E:
	cmp r5, r8
	beq _0815DFCC
	ldr r0, _0815DFC8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815DFAE:
	ldr r0, [sp, #0x28]
	cmp r0, r5
	ble _0815E032
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DF9E
	b _0815E032
	.align 2, 0
_0815DFC8: .4byte 0x030046A4
_0815DFCC:
	movs r0, #1
	b _0815E034
_0815DFD0:
	subs r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DFE4
_0815DFDC:
	cmp r5, r8
	beq _0815DFCC
	subs r5, #1
	subs r6, #1
_0815DFE4:
	cmp r6, #0
	blt _0815DFFA
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DFDC
_0815DFFA:
	ldr r0, _0815E008 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0815E01C
	.align 2, 0
_0815E008: .4byte 0x030046A4
_0815E00C:
	cmp r5, r8
	beq _0815DFCC
	ldr r0, _0815E040 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815E01C:
	cmp r5, #0
	blt _0815E032
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E00C
_0815E032:
	movs r0, #0
_0815E034:
	cmp r0, #0
	bne _0815E03A
	b _0815E2B8
_0815E03A:
	movs r3, #1
	str r3, [sp, #0x14]
	b _0815E2C6
	.align 2, 0
_0815E040: .4byte 0x030046A4
_0815E044:
	ldr r5, [sp, #0x10]
	ldr r6, _0815E06C @ =0x00000256
	adds r4, r5, r6
	ldrh r0, [r4]
	adds r7, r0, #1
	mov r8, r7
	adds r7, r0, #0
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	str r4, [sp, #0x84]
	cmp r0, #0
	beq _0815E070
	adds r0, #4
	b _0815E07C
	.align 2, 0
_0815E06C: .4byte 0x00000256
_0815E070:
	ldr r2, _0815E0A8 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E07C:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	ldr r2, _0815E0A8 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x2c]
	cmp r7, r8
	bge _0815E114
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, _0815E0A8 @ =0x030046A4
	mov sl, r0
	b _0815E0B4
	.align 2, 0
_0815E0A8: .4byte 0x030046A4
_0815E0AC:
	cmp r5, r8
	beq _0815E110
	adds r5, #1
	adds r6, #1
_0815E0B4:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815E0D4
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E0AC
_0815E0D4:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r7, r0
	b _0815E0F2
_0815E0E2:
	cmp r5, r8
	beq _0815E110
	ldr r0, _0815E10C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815E0F2:
	ldr r0, [sp, #0x2c]
	cmp r0, r5
	ble _0815E176
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E0E2
	b _0815E176
	.align 2, 0
_0815E10C: .4byte 0x030046A4
_0815E110:
	movs r0, #1
	b _0815E178
_0815E114:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815E128
_0815E120:
	cmp r5, r8
	beq _0815E110
	subs r5, #1
	subs r6, #1
_0815E128:
	cmp r6, #0
	blt _0815E13E
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E120
_0815E13E:
	ldr r0, _0815E14C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r7, r0
	b _0815E160
	.align 2, 0
_0815E14C: .4byte 0x030046A4
_0815E150:
	cmp r5, r8
	beq _0815E110
	ldr r0, _0815E184 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815E160:
	cmp r5, #0
	blt _0815E176
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E150
_0815E176:
	movs r0, #0
_0815E178:
	cmp r0, #0
	beq _0815E188
	movs r3, #0
	str r3, [sp, #0x14]
	b _0815E2C6
	.align 2, 0
_0815E184: .4byte 0x030046A4
_0815E188:
	ldr r4, [sp, #0x84]
	ldrh r0, [r4]
	subs r5, r0, #1
	mov r8, r5
	adds r4, r0, #0
	ldr r6, [sp, #0x10]
	movs r7, #0xa
	ldrsh r6, [r6, r7]
	mov sb, r6
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E1A8
	adds r0, #4
	b _0815E1B4
_0815E1A8:
	ldr r2, _0815E1E0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E1B4:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, _0815E1E0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	str r5, [sp, #0x30]
	cmp r4, r8
	bge _0815E24C
	adds r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, _0815E1E0 @ =0x030046A4
	mov sl, r0
	b _0815E1EC
	.align 2, 0
_0815E1E0: .4byte 0x030046A4
_0815E1E4:
	cmp r5, r8
	beq _0815E248
	adds r5, #1
	adds r6, #1
_0815E1EC:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815E20C
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E1E4
_0815E20C:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _0815E22A
_0815E21A:
	cmp r5, r8
	beq _0815E248
	ldr r0, _0815E244 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815E22A:
	ldr r0, [sp, #0x30]
	cmp r0, r5
	ble _0815E2AE
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E21A
	b _0815E2AE
	.align 2, 0
_0815E244: .4byte 0x030046A4
_0815E248:
	movs r0, #1
	b _0815E2B0
_0815E24C:
	subs r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815E260
_0815E258:
	cmp r5, r8
	beq _0815E248
	subs r5, #1
	subs r6, #1
_0815E260:
	cmp r6, #0
	blt _0815E276
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E258
_0815E276:
	ldr r0, _0815E284 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0815E298
	.align 2, 0
_0815E284: .4byte 0x030046A4
_0815E288:
	cmp r5, r8
	beq _0815E248
	ldr r0, _0815E2E0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815E298:
	cmp r5, #0
	blt _0815E2AE
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E288
_0815E2AE:
	movs r0, #0
_0815E2B0:
	movs r3, #2
	str r3, [sp, #0x14]
	cmp r0, #0
	bne _0815E2BE
_0815E2B8:
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #0x14]
_0815E2BE:
	ldr r5, [sp, #0x14]
	cmp r5, #0
	bge _0815E2C6
	b _0815E834
_0815E2C6:
	ldr r6, [sp, #0x10]
	ldr r7, _0815E2E4 @ =0x00000256
	adds r0, r6, r7
	ldrh r0, [r0]
	mov r8, r0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E2E8
	adds r0, #4
	b _0815E2F6
	.align 2, 0
_0815E2E0: .4byte 0x030046A4
_0815E2E4: .4byte 0x00000256
_0815E2E8:
	ldr r2, _0815E324 @ =0x030046A4
	ldr r1, [r2]
	mov r3, r8
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E2F6:
	ldrb r0, [r0]
	movs r4, #0xf
	mov sb, r4
	mov r5, sb
	ands r5, r0
	mov sb, r5
	ldr r6, _0815E324 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r3, [sp, #0x14]
	cmp r3, #1
	beq _0815E3C0
	cmp r3, #1
	bgt _0815E328
	cmp r3, #0
	beq _0815E338
	b _0815E55E
	.align 2, 0
_0815E324: .4byte 0x030046A4
_0815E328:
	ldr r4, [sp, #0x14]
	cmp r4, #2
	bne _0815E330
	b _0815E440
_0815E330:
	cmp r4, #3
	bne _0815E336
	b _0815E4E4
_0815E336:
	b _0815E55E
_0815E338:
	mov r4, r8
	adds r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r6, _0815E36C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	cmp r5, r0
	blt _0815E354
	b _0815E55E
_0815E354:
	adds r7, r6, #0
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0815E35C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E370
	adds r0, #4
	b _0815E376
	.align 2, 0
_0815E36C: .4byte 0x030046A4
_0815E370:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E376:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E3A0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E390
	adds r0, #4
	b _0815E396
_0815E390:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E396:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E3A4
_0815E3A0:
	movs r0, #0
	b _0815E3A6
_0815E3A4:
	movs r0, #1
_0815E3A6:
	cmp r0, #0
	bne _0815E3AC
	b _0815E4B6
_0815E3AC:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0815E35C
	b _0815E55E
_0815E3C0:
	mov r2, r8
	adds r4, r2, r1
	cmp r5, r4
	bgt _0815E3CA
	b _0815E55E
_0815E3CA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E3DA
	adds r0, #4
	b _0815E3E6
_0815E3DA:
	ldr r0, _0815E400 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E3E6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E41A
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E404
	adds r0, #4
	b _0815E410
	.align 2, 0
_0815E400: .4byte 0x030046A4
_0815E404:
	ldr r2, _0815E420 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E410:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E424
_0815E41A:
	movs r0, #0
	b _0815E426
	.align 2, 0
_0815E420: .4byte 0x030046A4
_0815E424:
	movs r0, #1
_0815E426:
	cmp r0, #0
	beq _0815E4BA
	ldr r3, _0815E43C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r4, r4, r0
	cmp r5, r4
	bgt _0815E3CA
	b _0815E55E
	.align 2, 0
_0815E43C: .4byte 0x030046A4
_0815E440:
	mov r4, r8
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	bge _0815E452
	b _0815E55E
_0815E452:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
	ldr r7, _0815E46C @ =0x030046A4
_0815E45A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E470
	adds r0, #4
	b _0815E476
	.align 2, 0
_0815E46C: .4byte 0x030046A4
_0815E470:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E476:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E4A0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E490
	adds r0, #4
	b _0815E496
_0815E490:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E496:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E4A4
_0815E4A0:
	movs r0, #0
	b _0815E4A6
_0815E4A4:
	movs r0, #1
_0815E4A6:
	cmp r0, #0
	beq _0815E4CC
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _0815E45A
	b _0815E55E
_0815E4B6:
	subs r5, r4, #1
	b _0815E560
_0815E4BA:
	ldr r7, _0815E4C8 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0815E560
	.align 2, 0
_0815E4C8: .4byte 0x030046A4
_0815E4CC:
	adds r5, r4, #1
	b _0815E560
_0815E4D0:
	ldr r2, _0815E4E0 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r5, r4, r0
	b _0815E560
	.align 2, 0
_0815E4E0: .4byte 0x030046A4
_0815E4E4:
	mov r5, r8
	subs r4, r5, r1
	cmp r4, #0
	blt _0815E55E
_0815E4EC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E4FC
	adds r0, #4
	b _0815E508
_0815E4FC:
	ldr r0, _0815E524 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E508:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E53E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E528
	adds r0, #4
	b _0815E534
	.align 2, 0
_0815E524: .4byte 0x030046A4
_0815E528:
	ldr r2, _0815E544 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E534:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E548
_0815E53E:
	movs r0, #0
	b _0815E54A
	.align 2, 0
_0815E544: .4byte 0x030046A4
_0815E548:
	movs r0, #1
_0815E54A:
	cmp r0, #0
	beq _0815E4D0
	ldr r6, _0815E5A4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r4, r4, r0
	cmp r4, #0
	bge _0815E4EC
_0815E55E:
	mov r5, r8
_0815E560:
	cmp r5, #0
	bne _0815E566
	b _0815E834
_0815E566:
	ldr r1, [sp, #0x10]
	ldr r2, _0815E5A8 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r5, r0
	bne _0815E574
	b _0815E834
_0815E574:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r3, [sp, #0x10]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x60]
	adds r3, #8
	str r3, [sp, #0x34]
	add r7, sp, #8
	cmp r0, #0
	beq _0815E592
	b _0815E6DE
_0815E592:
	movs r1, #4
	ldr r6, [sp, #0x7c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815E5AC
	movs r0, #1
	b _0815E5AE
	.align 2, 0
_0815E5A4: .4byte 0x030046A4
_0815E5A8: .4byte 0x00000256
_0815E5AC:
	movs r0, #0
_0815E5AE:
	ldr r7, [sp, #0x10]
	adds r7, #8
	str r7, [sp, #0x34]
	add r7, sp, #8
	cmp r0, #0
	beq _0815E5BC
	b _0815E6DE
_0815E5BC:
	movs r2, #0
	ldr r1, _0815E71C @ =0x0000046D
	ldr r0, [sp, #0x10]
	adds r1, r0, r1
	str r1, [sp, #0x50]
	ldr r3, _0815E720 @ =0x0000046B
	adds r3, r0, r3
	str r3, [sp, #0x48]
	ldr r4, _0815E724 @ =0x00000553
	adds r4, r0, r4
	str r4, [sp, #0x70]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r0, r6
	str r6, [sp, #0x78]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r0, r1
	str r1, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r0, r3
	str r3, [sp, #0x3c]
	ldr r4, _0815E728 @ =0x00000469
	adds r4, r0, r4
	str r4, [sp, #0x40]
	ldr r6, _0815E72C @ =0x0000046A
	adds r6, r0, r6
	str r6, [sp, #0x44]
	ldr r1, _0815E730 @ =0x00000484
	adds r1, r0, r1
	str r1, [sp, #0x58]
	ldr r3, _0815E734 @ =0x0000046C
	adds r3, r0, r3
	str r3, [sp, #0x4c]
	ldrb r4, [r0, #5]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r6, r0, r6
	str r6, [sp, #0x88]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r8, r0
	ldr r3, [sp, #0x10]
	ldr r6, _0815E738 @ =0x0000054F
	adds r3, r3, r6
	mov sb, r3
	ldr r0, [sp, #0x10]
	adds r1, #4
	adds r0, r0, r1
	mov sl, r0
	ldr r3, [sp, #0x10]
	subs r6, #2
	adds r3, r3, r6
	mov ip, r3
	adds r1, #2
	ldr r0, [sp, #0x10]
	adds r1, r0, r1
	str r1, [sp, #0x6c]
	ldr r3, _0815E73C @ =0x00000541
	adds r3, r0, r3
	str r3, [sp, #0x64]
	adds r6, #0x6f
	adds r6, r0, r6
	str r6, [sp, #0x80]
	ldr r1, _0815E740 @ =0x00000542
	adds r1, r0, r1
	str r1, [sp, #0x68]
	ldr r1, _0815E744 @ =0x030046B8
	adds r3, r4, #0
_0815E64A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0815E748 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0815E74C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r3
	bne _0815E66E
	adds r2, #1
	cmp r2, #3
	ble _0815E64A
	adds r0, r4, #0
_0815E66E:
	movs r3, #0
	ldr r1, [sp, #0x88]
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	mov r4, r8
	str r0, [r4]
	ldr r6, [sp, #0x70]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x3c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r6, [sp, #0x40]
	ldrb r0, [r6]
	mov r1, ip
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldrb r0, [r2]
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
	mov r6, sp
	ldrb r0, [r6, #0x14]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	ldr r1, [sp, #0x80]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x50]
	strb r1, [r4]
	ldr r6, [sp, #0x48]
	strb r3, [r6]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x78]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x74]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r6, [sp, #0x40]
	strb r1, [r6]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	ldr r2, [sp, #0x58]
	str r3, [r2]
	ldr r3, [sp, #0x4c]
	strb r1, [r3]
	movs r0, #2
	ldr r4, [sp, #0x68]
	strb r0, [r4]
_0815E6DE:
	mov r8, r7
	ldr r6, _0815E750 @ =0x030046A4
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
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815E754
	adds r0, #4
	b _0815E760
	.align 2, 0
_0815E71C: .4byte 0x0000046D
_0815E720: .4byte 0x0000046B
_0815E724: .4byte 0x00000553
_0815E728: .4byte 0x00000469
_0815E72C: .4byte 0x0000046A
_0815E730: .4byte 0x00000484
_0815E734: .4byte 0x0000046C
_0815E738: .4byte 0x0000054F
_0815E73C: .4byte 0x00000541
_0815E740: .4byte 0x00000542
_0815E744: .4byte 0x030046B8
_0815E748: .4byte 0x000003FF
_0815E74C: .4byte 0x0203B400
_0815E750: .4byte 0x030046A4
_0815E754:
	ldr r4, _0815E798 @ =0x030046A4
	ldr r0, [r4]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815E760:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r5, r8
	strh r0, [r5, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	ldr r6, [sp, #0x10]
	ldrh r0, [r6, #0xa]
	strh r0, [r7, #2]
	ldr r1, _0815E79C @ =0x000004A4
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	adds r2, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815E7A4
	ldr r0, _0815E7A0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x60]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0815E7CE
	.align 2, 0
_0815E798: .4byte 0x030046A4
_0815E79C: .4byte 0x000004A4
_0815E7A0: .4byte 0xFFFFFDFF
_0815E7A4:
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	adds r2, r7, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815E7C4
	cmp r0, #2
	beq _0815E7C0
	ldr r0, [sp, #0x10]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815E7C0:
	movs r0, #1
	b _0815E7D0
_0815E7C4:
	ldr r0, _0815E7E4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x60]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0815E7CE:
	movs r0, #0
_0815E7D0:
	adds r4, r0, #0
	cmp r4, #0
	beq _0815E7E8
	movs r0, #2
	ldr r5, [sp, #0x7c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r0, #1
	b _0815E836
	.align 2, 0
_0815E7E4: .4byte 0xFFFFFDFF
_0815E7E8:
	ldr r1, _0815E848 @ =Enemy_ClearStateBegun
	ldr r5, [sp, #0x10]
	ldr r6, _0815E84C @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _0815E850 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _0815E854 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0815E858 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _0815E85C @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0815E860 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0815E864 @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
_0815E834:
	movs r0, #0
_0815E836:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0815E848: .4byte Enemy_ClearStateBegun
_0815E84C: .4byte 0x0000046D
_0815E850: .4byte 0x0000046B
_0815E854: .4byte 0x00000553
_0815E858: .4byte 0x00000469
_0815E85C: .4byte 0x0000046A
_0815E860: .4byte 0x00000484
_0815E864: .4byte 0x0000046C
