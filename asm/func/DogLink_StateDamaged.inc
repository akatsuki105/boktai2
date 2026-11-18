	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _081CD644 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CD648
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CD64A
	.align 2, 0
_081CD644: .4byte 0x0000046D
_081CD648:
	movs r0, #0
_081CD64A:
	cmp r0, #0
	beq _081CD6A8
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081CD660
	asrs r1, r0, #2
	b _081CD666
_081CD660:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081CD666:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _081CD680
	asrs r1, r0, #2
	b _081CD686
_081CD680:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081CD686:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081CD6D8 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_081CD6A8:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081CD6DC
	asrs r0, r0, #2
	b _081CD6E2
	.align 2, 0
_081CD6D8: .4byte 0xFFFFFEFF
_081CD6DC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081CD6E2:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081CD702
	asrs r0, r0, #2
	b _081CD708
_081CD702:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081CD708:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081CD712
	movs r3, #0xc8
	b _081CD71C
_081CD712:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081CD71C
	adds r3, r0, #0
_081CD71C:
	cmp r2, #0xc8
	ble _081CD724
	movs r2, #0xc8
	b _081CD72E
_081CD724:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081CD72E
	adds r2, r0, #0
_081CD72E:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081CD752
	cmp r2, #0
	bne _081CD752
	movs r0, #1
	b _081CD754
_081CD752:
	movs r0, #0
_081CD754:
	cmp r0, #0
	bne _081CD75C
	bl _081CE634
_081CD75C:
	ldr r6, _081CD7A8 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CD76A
	bl _081CE634
_081CD76A:
	ldr r0, _081CD7AC @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	strh r3, [r2]
	ldr r4, _081CD7B0 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x9c]
	cmp r0, #0
	beq _081CD7B4
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081CE644
	.align 2, 0
_081CD7A8: .4byte 0x0000046E
_081CD7AC: .4byte 0x0000046B
_081CD7B0: .4byte 0x0000049C
_081CD7B4:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081CD7C4
	b _081CDEEC
_081CD7C4:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CD7E0
	bl _081CE644
_081CD7E0:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081CD81C
	cmp r1, #0
	blt _081CD81C
	ldr r0, _081CD820 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CD81C
	ldr r0, _081CD824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD828
_081CD81C:
	movs r4, #0
	b _081CD836
	.align 2, 0
_081CD820: .4byte 0x030046A8
_081CD824: .4byte 0x030046AC
_081CD828:
	ldr r0, _081CD848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CD836:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CD84C
	adds r0, #4
	b _081CD858
	.align 2, 0
_081CD848: .4byte 0x030046A4
_081CD84C:
	ldr r0, _081CD86C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CD858:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CD870
	cmp r2, #2
	beq _081CD874
	b _081CD878
	.align 2, 0
_081CD86C: .4byte 0x030046A4
_081CD870:
	ldrb r0, [r5, #4]
	b _081CD876
_081CD874:
	ldrb r0, [r5]
_081CD876:
	subs r1, r1, r0
_081CD878:
	strh r1, [r5, #2]
	ldr r0, _081CD88C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CD890
	movs r0, #1
	b _081CD892
	.align 2, 0
_081CD88C: .4byte 0x030047A4
_081CD890:
	movs r0, #0
_081CD892:
	cmp r0, #0
	beq _081CD8D0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081CD8B2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CD8AE
	adds r2, r0, #0
_081CD8AE:
	cmp r2, #0
	bge _081CD8BC
_081CD8B2:
	ldr r2, _081CD8B8 @ =0x000005C4
	adds r0, r7, r2
	b _081CDDE8
	.align 2, 0
_081CD8B8: .4byte 0x000005C4
_081CD8BC:
	ldr r1, _081CD8CC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CD918
	.align 2, 0
_081CD8CC: .4byte 0x03002BE0
_081CD8D0:
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
	blt _081CD8FC
	cmp r1, #0
	blt _081CD8FC
	ldr r0, _081CD900 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CD8FC
	ldr r0, _081CD904 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD908
_081CD8FC:
	movs r5, #0
	b _081CD916
	.align 2, 0
_081CD900: .4byte 0x030046A8
_081CD904: .4byte 0x030046AC
_081CD908:
	ldr r0, _081CD950 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CD916:
	movs r2, #0
_081CD918:
	ldr r4, _081CD954 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CD938
	ldr r1, _081CD958 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CD938
	b _081CDD28
_081CD938:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x9c]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	cmp r0, #0
	beq _081CD95C
	movs r0, #0
	b _081CDDFE
	.align 2, 0
_081CD950: .4byte 0x030046A4
_081CD954: .4byte 0x00000256
_081CD958: .4byte 0x03002BE0
_081CD95C:
	ldr r6, _081CDA00 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x9c]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _081CDA14
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081CDA04 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x14]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _081CDA08 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x18]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov r8, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x10]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _081CDA0C @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081CDA10 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x10]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xb0]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081CDBE6
	.align 2, 0
_081CDA00: .4byte 0x00000222
_081CDA04: .4byte 0x0000046D
_081CDA08: .4byte 0x0000046B
_081CDA0C: .4byte 0x00000469
_081CDA10: .4byte 0x00000484
_081CDA14:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081CDAD8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _081CDADC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081CDAE0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081CDAE4 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081CDAE8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081CDAEC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _081CDAD2
	cmp r1, #0
	blt _081CDAD2
	ldr r0, _081CDAF0 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081CDAD2
	ldr r0, _081CDAF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CDAF8
_081CDAD2:
	movs r4, #0
	b _081CDB08
	.align 2, 0
_081CDAD8: .4byte 0x0000046D
_081CDADC: .4byte 0x0000046B
_081CDAE0: .4byte 0x00000553
_081CDAE4: .4byte 0x00000469
_081CDAE8: .4byte 0x00000484
_081CDAEC: .4byte 0x0000046C
_081CDAF0: .4byte 0x030046A8
_081CDAF4: .4byte 0x030046AC
_081CDAF8:
	ldr r0, _081CDB18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081CDB08:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CDB1C
	adds r0, #4
	b _081CDB28
	.align 2, 0
_081CDB18: .4byte 0x030046A4
_081CDB1C:
	ldr r0, _081CDB3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CDB28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CDB40
	cmp r2, #2
	beq _081CDB46
	b _081CDB4C
	.align 2, 0
_081CDB3C: .4byte 0x030046A4
_081CDB40:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _081CDB4A
_081CDB46:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_081CDB4A:
	subs r1, r1, r0
_081CDB4C:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CDB78
	cmp r1, #0
	blt _081CDB78
	ldr r0, _081CDB7C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CDB78
	ldr r0, _081CDB80 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CDB84
_081CDB78:
	movs r4, #0
	b _081CDB92
	.align 2, 0
_081CDB7C: .4byte 0x030046A8
_081CDB80: .4byte 0x030046AC
_081CDB84:
	ldr r0, _081CDBA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CDB92:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CDBAC
	adds r0, #4
	b _081CDBB8
	.align 2, 0
_081CDBA8: .4byte 0x030046A4
_081CDBAC:
	ldr r0, _081CDBCC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CDBB8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CDBD0
	cmp r3, #2
	beq _081CDBD4
	b _081CDBD8
	.align 2, 0
_081CDBCC: .4byte 0x030046A4
_081CDBD0:
	ldrb r0, [r5, #4]
	b _081CDBD6
_081CDBD4:
	ldrb r0, [r5]
_081CDBD6:
	subs r2, r2, r0
_081CDBD8:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CDBE6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CDC10 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081CDCF0
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CDC14
	movs r0, #1
	b _081CDC16
	.align 2, 0
_081CDC10: .4byte 0x00000482
_081CDC14:
	movs r0, #0
_081CDC16:
	ldr r1, _081CDD00 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081CDCF0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081CDD04 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CDD08 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CDD0C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CDD10 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081CDD14 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081CDD18 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CDD1C @ =0x030046B8
	adds r2, r4, #0
_081CDC5E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CDD20 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CDD24 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CDC82
	adds r3, #1
	cmp r3, #3
	ble _081CDC5E
	adds r0, r4, #0
_081CDC82:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081CDCF0:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081CDDFE
	.align 2, 0
_081CDD00: .4byte 0x00000482
_081CDD04: .4byte 0x0000054F
_081CDD08: .4byte 0x0000054C
_081CDD0C: .4byte 0x0000054E
_081CDD10: .4byte 0x00000541
_081CDD14: .4byte 0x000005BC
_081CDD18: .4byte 0x00000542
_081CDD1C: .4byte 0x030046B8
_081CDD20: .4byte 0x000003FF
_081CDD24: .4byte 0x0203B400
_081CDD28:
	mov sb, sp
	ldr r6, _081CDD64 @ =0x030046A4
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
	beq _081CDD68
	adds r0, #4
	b _081CDD72
	.align 2, 0
_081CDD64: .4byte 0x030046A4
_081CDD68:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CDD72:
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
	ldr r6, _081CDDAC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CDDB4
	ldr r0, _081CDDB0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CDDDE
	.align 2, 0
_081CDDAC: .4byte 0x000004A4
_081CDDB0: .4byte 0xFFFFFDFF
_081CDDB4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CDDD4
	cmp r0, #2
	beq _081CDDD0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CDDD0:
	movs r0, #1
	b _081CDDE0
_081CDDD4:
	ldr r0, _081CDDF4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CDDDE:
	movs r0, #0
_081CDDE0:
	cmp r0, #0
	bne _081CDDFC
	ldr r4, _081CDDF8 @ =0x000005C4
	adds r0, r7, r4
_081CDDE8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CDDFE
	.align 2, 0
_081CDDF4: .4byte 0xFFFFFDFF
_081CDDF8: .4byte 0x000005C4
_081CDDFC:
	movs r0, #1
_081CDDFE:
	cmp r0, #0
	bne _081CDE6E
	ldr r5, _081CDE34 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CDE3C
	ldr r0, _081CDE38 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CDE66
	.align 2, 0
_081CDE34: .4byte 0x000004A4
_081CDE38: .4byte 0xFFFFFDFF
_081CDE3C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CDE5C
	cmp r0, #2
	beq _081CDE58
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CDE58:
	movs r0, #1
	b _081CDE68
_081CDE5C:
	ldr r0, _081CDED0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CDE66:
	movs r0, #0
_081CDE68:
	cmp r0, #0
	bne _081CDE6E
	b _081CE5AC
_081CDE6E:
	movs r0, #4
	ldr r5, _081CDED4 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081CDED8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081CDEDC @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081CDEE0 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081CDEE4 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081CDEE8 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _081CE644
	.align 2, 0
_081CDED0: .4byte 0xFFFFFDFF
_081CDED4: .4byte 0x00000222
_081CDED8: .4byte 0x0000046D
_081CDEDC: .4byte 0x0000046B
_081CDEE0: .4byte 0x00000469
_081CDEE4: .4byte 0x0000046A
_081CDEE8: .4byte 0x0000046C
_081CDEEC:
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDEFA
	b _081CE644
_081CDEFA:
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r5
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
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081CDF4A
	cmp r1, #0
	blt _081CDF4A
	ldr r0, _081CDF50 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CDF4A
	ldr r0, _081CDF54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CDF58
_081CDF4A:
	movs r4, #0
	b _081CDF66
	.align 2, 0
_081CDF50: .4byte 0x030046A8
_081CDF54: .4byte 0x030046AC
_081CDF58:
	ldr r0, _081CDF78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CDF66:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CDF7C
	adds r0, #4
	b _081CDF88
	.align 2, 0
_081CDF78: .4byte 0x030046A4
_081CDF7C:
	ldr r0, _081CDF9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CDF88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CDFA0
	cmp r2, #2
	beq _081CDFA4
	b _081CDFA8
	.align 2, 0
_081CDF9C: .4byte 0x030046A4
_081CDFA0:
	ldrb r0, [r5, #4]
	b _081CDFA6
_081CDFA4:
	ldrb r0, [r5]
_081CDFA6:
	subs r1, r1, r0
_081CDFA8:
	strh r1, [r5, #2]
	ldr r0, _081CDFBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CDFC0
	movs r0, #1
	b _081CDFC2
	.align 2, 0
_081CDFBC: .4byte 0x030047A4
_081CDFC0:
	movs r0, #0
_081CDFC2:
	cmp r0, #0
	beq _081CE000
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081CDFE2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CDFDE
	adds r2, r0, #0
_081CDFDE:
	cmp r2, #0
	bge _081CDFEC
_081CDFE2:
	ldr r1, _081CDFE8 @ =0x000005C4
	adds r0, r7, r1
	b _081CE528
	.align 2, 0
_081CDFE8: .4byte 0x000005C4
_081CDFEC:
	ldr r1, _081CDFFC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CE048
	.align 2, 0
_081CDFFC: .4byte 0x03002BE0
_081CE000:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CE02C
	cmp r1, #0
	blt _081CE02C
	ldr r0, _081CE030 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CE02C
	ldr r0, _081CE034 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE038
_081CE02C:
	movs r5, #0
	b _081CE046
	.align 2, 0
_081CE030: .4byte 0x030046A8
_081CE034: .4byte 0x030046AC
_081CE038:
	ldr r0, _081CE080 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CE046:
	movs r2, #0
_081CE048:
	ldr r3, _081CE084 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CE068
	ldr r1, _081CE088 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CE068
	b _081CE464
_081CE068:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _081CE08C
	movs r0, #0
	b _081CE53E
	.align 2, 0
_081CE080: .4byte 0x030046A4
_081CE084: .4byte 0x00000256
_081CE088: .4byte 0x03002BE0
_081CE08C:
	ldr r5, _081CE130 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x9c]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xac]
	cmp r0, #0
	beq _081CE150
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081CE134 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081CE138 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081CE13C @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x50]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081CE140 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081CE144 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081CE148 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _081CE14C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081CE322
	.align 2, 0
_081CE130: .4byte 0x00000222
_081CE134: .4byte 0x0000046D
_081CE138: .4byte 0x0000046B
_081CE13C: .4byte 0x00000553
_081CE140: .4byte 0x00000469
_081CE144: .4byte 0x0000046A
_081CE148: .4byte 0x00000484
_081CE14C: .4byte 0x0000046C
_081CE150:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081CE214 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _081CE218 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081CE21C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _081CE220 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081CE224 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081CE228 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _081CE210
	cmp r1, #0
	blt _081CE210
	ldr r0, _081CE22C @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081CE210
	ldr r0, _081CE230 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE234
_081CE210:
	movs r4, #0
	b _081CE244
	.align 2, 0
_081CE214: .4byte 0x0000046D
_081CE218: .4byte 0x0000046B
_081CE21C: .4byte 0x00000553
_081CE220: .4byte 0x00000469
_081CE224: .4byte 0x0000046A
_081CE228: .4byte 0x00000484
_081CE22C: .4byte 0x030046A8
_081CE230: .4byte 0x030046AC
_081CE234:
	ldr r0, _081CE254 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081CE244:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CE258
	adds r0, #4
	b _081CE264
	.align 2, 0
_081CE254: .4byte 0x030046A4
_081CE258:
	ldr r0, _081CE278 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CE264:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CE27C
	cmp r2, #2
	beq _081CE282
	b _081CE288
	.align 2, 0
_081CE278: .4byte 0x030046A4
_081CE27C:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _081CE286
_081CE282:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_081CE286:
	subs r1, r1, r0
_081CE288:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CE2B4
	cmp r1, #0
	blt _081CE2B4
	ldr r0, _081CE2B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CE2B4
	ldr r0, _081CE2BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE2C0
_081CE2B4:
	movs r4, #0
	b _081CE2CE
	.align 2, 0
_081CE2B8: .4byte 0x030046A8
_081CE2BC: .4byte 0x030046AC
_081CE2C0:
	ldr r0, _081CE2E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CE2CE:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CE2E8
	adds r0, #4
	b _081CE2F4
	.align 2, 0
_081CE2E4: .4byte 0x030046A4
_081CE2E8:
	ldr r0, _081CE308 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CE2F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CE30C
	cmp r3, #2
	beq _081CE310
	b _081CE314
	.align 2, 0
_081CE308: .4byte 0x030046A4
_081CE30C:
	ldrb r0, [r5, #4]
	b _081CE312
_081CE310:
	ldrb r0, [r5]
_081CE312:
	subs r2, r2, r0
_081CE314:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CE322:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CE34C @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081CE42C
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CE350
	movs r0, #1
	b _081CE352
	.align 2, 0
_081CE34C: .4byte 0x00000482
_081CE350:
	movs r0, #0
_081CE352:
	ldr r1, _081CE43C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081CE42C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081CE440 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CE444 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CE448 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CE44C @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081CE450 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081CE454 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CE458 @ =0x030046B8
	adds r2, r4, #0
_081CE39A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CE45C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CE460 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CE3BE
	adds r3, #1
	cmp r3, #3
	ble _081CE39A
	adds r0, r4, #0
_081CE3BE:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081CE42C:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081CE53E
	.align 2, 0
_081CE43C: .4byte 0x00000482
_081CE440: .4byte 0x0000054F
_081CE444: .4byte 0x0000054C
_081CE448: .4byte 0x0000054E
_081CE44C: .4byte 0x00000541
_081CE450: .4byte 0x000005BC
_081CE454: .4byte 0x00000542
_081CE458: .4byte 0x030046B8
_081CE45C: .4byte 0x000003FF
_081CE460: .4byte 0x0203B400
_081CE464:
	add r6, sp, #8
	ldr r0, _081CE4A4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081CE4A8
	adds r0, #4
	b _081CE4B4
	.align 2, 0
_081CE4A4: .4byte 0x030046A4
_081CE4A8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CE4B4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081CE4EC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CE4F4
	ldr r0, _081CE4F0 @ =0xFFFFFDFF
	ldr r6, [sp, #0x9c]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081CE51E
	.align 2, 0
_081CE4EC: .4byte 0x000004A4
_081CE4F0: .4byte 0xFFFFFDFF
_081CE4F4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CE514
	cmp r0, #2
	beq _081CE510
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CE510:
	movs r0, #1
	b _081CE520
_081CE514:
	ldr r0, _081CE534 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081CE51E:
	movs r0, #0
_081CE520:
	cmp r0, #0
	bne _081CE53C
	ldr r3, _081CE538 @ =0x000005C4
	adds r0, r7, r3
_081CE528:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CE53E
	.align 2, 0
_081CE534: .4byte 0xFFFFFDFF
_081CE538: .4byte 0x000005C4
_081CE53C:
	movs r0, #1
_081CE53E:
	cmp r0, #0
	bne _081CE5C4
	ldr r4, _081CE574 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CE57C
	ldr r0, _081CE578 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CE5A6
	.align 2, 0
_081CE574: .4byte 0x000004A4
_081CE578: .4byte 0xFFFFFDFF
_081CE57C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CE59C
	cmp r0, #2
	beq _081CE598
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CE598:
	movs r0, #1
	b _081CE5A8
_081CE59C:
	ldr r0, _081CE5BC @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CE5A6:
	movs r0, #0
_081CE5A8:
	cmp r0, #0
	bne _081CE5C4
_081CE5AC:
	ldr r4, _081CE5C0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081CE644
	.align 2, 0
_081CE5BC: .4byte 0xFFFFFDFF
_081CE5C0: .4byte 0x000005C4
_081CE5C4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081CE620 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081CE624 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081CE628 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081CE62C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081CE630 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #4
	strh r0, [r1]
	b _081CE644
	.align 2, 0
_081CE620: .4byte 0x0000046D
_081CE624: .4byte 0x0000046B
_081CE628: .4byte 0x00000469
_081CE62C: .4byte 0x0000046A
_081CE630: .4byte 0x00000484

_081CE634:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081CE644:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
