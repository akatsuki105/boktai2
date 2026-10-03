	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D740 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804D71A
	b _0804D850
_0804D71A:
	cmp r3, #0x41
	bne _0804D720
	b _0804D850
_0804D720:
	cmp r3, #0x41
	bgt _0804D744
	cmp r3, #0x30
	beq _0804D7A0
	cmp r3, #0x30
	bgt _0804D72E
	b _0804D850
_0804D72E:
	cmp r3, #0x32
	beq _0804D78C
	cmp r3, #0x32
	blt _0804D776
	cmp r3, #0x33
	beq _0804D7A0
	cmp r3, #0x40
	beq _0804D7E4
	b _0804D850
	.align 2, 0
_0804D740: .4byte 0x03002B58
_0804D744:
	cmp r3, #0x50
	bne _0804D74A
	b _0804D84A
_0804D74A:
	cmp r3, #0x50
	bgt _0804D75E
	cmp r3, #0x43
	bne _0804D754
	b _0804D850
_0804D754:
	cmp r3, #0x43
	blt _0804D818
	cmp r3, #0x44
	beq _0804D820
	b _0804D850
_0804D75E:
	cmp r3, #0xf1
	beq _0804D832
	cmp r3, #0xf1
	bgt _0804D76C
	cmp r3, #0xf0
	beq _0804D832
	b _0804D850
_0804D76C:
	cmp r1, #0xf2
	beq _0804D832
	cmp r1, #0xff
	beq _0804D832
	b _0804D850
_0804D776:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D788 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D850
	.align 2, 0
_0804D788: .4byte 0x03004740
_0804D78C:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D79C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D850
	.align 2, 0
_0804D79C: .4byte 0x03004740
_0804D7A0:
	adds r3, r4, #0
	adds r3, #0x25
	ldr r2, _0804D7DC @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r6, #0
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xe9
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r2, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D7E0 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D850
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r6, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r6, [r4, #0x44]
	b _0804D808
	.align 2, 0
_0804D7DC: .4byte 0x03004740
_0804D7E0: .4byte 0x00000137
_0804D7E4:
	ldr r0, _0804D810 @ =0x03004740
	ldrb r1, [r0, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D814 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D850
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1d
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
_0804D808:
	adds r0, r4, #0
	adds r0, #0x32
	strb r5, [r0]
	b _0804D850
	.align 2, 0
_0804D810: .4byte 0x03004740
_0804D814: .4byte 0x00000137
_0804D818:
	adds r0, r4, #0
	bl FUN_0804ba64
	b _0804D850
_0804D820:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804D84E
_0804D832:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804D84A
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804D84A:
	ldr r1, _0804D858 @ =0x030000DC
	movs r0, #0
_0804D84E:
	strb r0, [r1]
_0804D850:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D858: .4byte 0x030000DC
