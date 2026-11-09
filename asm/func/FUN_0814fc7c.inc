	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _0814FDE0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814FC98
	movs r0, #0
	strb r0, [r1]
_0814FC98:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814FCB0
	bl _081504D8
_0814FCB0:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0814FCC2
	bl _081504D8
_0814FCC2:
	ldr r2, _0814FDE4 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0814FCD0
	bl _081504D4
_0814FCD0:
	ldr r3, _0814FDE8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _0814FDEC @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _0814FDF0 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _0814FDE4 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _0814FDE0 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _0814FDF4 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _0814FDF8 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _0814FDFC @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _0814FE00 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x44]
	ldr r0, [sp, #8]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x3c]
	mov r0, sl
	str r0, [sp, #0x50]
	mov r0, sb
	str r0, [sp, #0x48]
	mov r0, r8
	str r0, [sp, #0x40]
	str r5, [sp, #0x24]
	str r4, [sp, #0x2c]
	str r3, [sp, #0x28]
	mov sl, r2
	cmp r1, #0
	bne _0814FD6E
	b _08150308
_0814FD6E:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0814FE04 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0814FDDA
	cmp r1, #0
	blt _0814FDDA
	ldr r0, _0814FE08 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814FDDA
	ldr r0, _0814FE0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814FE10
_0814FDDA:
	movs r4, #0
	b _0814FE1E
	.align 2, 0
_0814FDE0: .4byte 0x0000046C
_0814FDE4: .4byte 0x00000484
_0814FDE8: .4byte 0x000001DF
_0814FDEC: .4byte 0x00000469
_0814FDF0: .4byte 0x0000046A
_0814FDF4: .4byte Enemy_WaitPendingState
_0814FDF8: .4byte 0x0000046D
_0814FDFC: .4byte 0x0000046B
_0814FE00: .4byte 0x00000553
_0814FE04: .4byte 0x00000551
_0814FE08: .4byte 0x030046A8
_0814FE0C: .4byte 0x030046AC
_0814FE10:
	ldr r0, _0814FE30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814FE1E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814FE34
	adds r0, #4
	b _0814FE40
	.align 2, 0
_0814FE30: .4byte 0x030046A4
_0814FE34:
	ldr r0, _0814FE54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814FE40:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814FE58
	cmp r2, #2
	beq _0814FE5C
	b _0814FE60
	.align 2, 0
_0814FE54: .4byte 0x030046A4
_0814FE58:
	ldrb r0, [r5, #4]
	b _0814FE5E
_0814FE5C:
	ldrb r0, [r5]
_0814FE5E:
	subs r1, r1, r0
_0814FE60:
	strh r1, [r5, #2]
	ldr r0, _0814FE74 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814FE78
	movs r0, #1
	b _0814FE7A
	.align 2, 0
_0814FE74: .4byte 0x030047A4
_0814FE78:
	movs r0, #0
_0814FE7A:
	cmp r0, #0
	beq _0814FEB8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0814FE9A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814FE96
	adds r2, r0, #0
_0814FE96:
	cmp r2, #0
	bge _0814FEA4
_0814FE9A:
	ldr r2, _0814FEA0 @ =0x000005C4
	adds r0, r7, r2
	b _081502F6
	.align 2, 0
_0814FEA0: .4byte 0x000005C4
_0814FEA4:
	ldr r1, _0814FEB4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814FF00
	.align 2, 0
_0814FEB4: .4byte 0x03002BE0
_0814FEB8:
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
	blt _0814FEE4
	cmp r1, #0
	blt _0814FEE4
	ldr r0, _0814FEE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814FEE4
	ldr r0, _0814FEEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814FEF0
_0814FEE4:
	movs r5, #0
	b _0814FEFE
	.align 2, 0
_0814FEE8: .4byte 0x030046A8
_0814FEEC: .4byte 0x030046AC
_0814FEF0:
	ldr r0, _0814FF90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814FEFE:
	movs r2, #0
_0814FF00:
	ldr r4, _0814FF94 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814FF20
	ldr r1, _0814FF98 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814FF20
	b _08150234
_0814FF20:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0814FF34
	b _081504D8
_0814FF34:
	ldr r0, _0814FF9C @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0814FFA0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x48]
	strb r2, [r3]
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r3, [sp, #0x24]
	strb r0, [r3]
	ldr r0, [sp, #0x2c]
	str r1, [r0]
	ldr r1, [sp, #0x28]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r1, [sp, #0x38]
	strb r5, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	ldr r5, [sp, #0x50]
	str r4, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081500EE
	.align 2, 0
_0814FF90: .4byte 0x030046A4
_0814FF94: .4byte 0x00000256
_0814FF98: .4byte 0x03002BE0
_0814FF9C: .4byte 0x00000222
_0814FFA0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	strb r5, [r4]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	str r1, [r4]
	ldr r1, [sp, #0x28]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x34]
	strb r5, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r5, [sp, #0x3c]
	strb r1, [r5]
	ldr r1, [sp, #0x50]
	str r3, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08150004
	cmp r1, #0
	blt _08150004
	ldr r0, _08150008 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08150004
	ldr r0, _0815000C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150010
_08150004:
	movs r4, #0
	b _0815001E
	.align 2, 0
_08150008: .4byte 0x030046A8
_0815000C: .4byte 0x030046AC
_08150010:
	ldr r0, _08150030 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815001E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08150034
	adds r0, #4
	b _08150040
	.align 2, 0
_08150030: .4byte 0x030046A4
_08150034:
	ldr r0, _08150054 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08150040:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08150058
	cmp r2, #2
	beq _0815005C
	b _08150060
	.align 2, 0
_08150054: .4byte 0x030046A4
_08150058:
	ldrb r0, [r5, #4]
	b _0815005E
_0815005C:
	ldrb r0, [r5]
_0815005E:
	subs r1, r1, r0
_08150060:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08150088
	cmp r1, #0
	blt _08150088
	ldr r0, _0815008C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08150088
	ldr r0, _08150090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150094
_08150088:
	movs r4, #0
	b _081500A2
	.align 2, 0
_0815008C: .4byte 0x030046A8
_08150090: .4byte 0x030046AC
_08150094:
	ldr r0, _081500B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081500A2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081500B8
	adds r0, #4
	b _081500C4
	.align 2, 0
_081500B4: .4byte 0x030046A4
_081500B8:
	ldr r0, _081500D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081500C4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081500DC
	cmp r3, #2
	beq _081500E0
	b _081500E4
	.align 2, 0
_081500D8: .4byte 0x030046A4
_081500DC:
	ldrb r0, [r5, #4]
	b _081500E2
_081500E0:
	ldrb r0, [r5]
_081500E2:
	subs r2, r2, r0
_081500E4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081500EE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	cmp r0, #0
	bne _081501F8
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08150118
	movs r0, #1
	b _0815011A
_08150118:
	movs r0, #0
_0815011A:
	ldr r3, _08150208 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	cmp r0, #0
	bne _081501F8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _0815020C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08150210 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x18]
	ldr r2, _08150214 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	ldr r4, _08150218 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x20]
	ldr r5, _0815021C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r0, _08150220 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _08150224 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r6, _08150228 @ =0x0203B400
	ldr r1, _0815022C @ =0x030046B8
	ldr r5, _08150230 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0815016A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _08150188
	adds r3, #1
	cmp r3, #3
	ble _0815016A
	mov r0, r8
_08150188:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x24]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x54]
	strb r1, [r0]
	ldr r4, [sp, #0x30]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r0, [r5]
	ldr r0, [sp, #0x2c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r2, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x58]
	strb r0, [r1]
_081501F8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x4c]
	strh r0, [r2]
	b _081504D8
	.align 2, 0
_08150208: .4byte 0x00000482
_0815020C: .4byte 0x0000054F
_08150210: .4byte 0x0000054C
_08150214: .4byte 0x0000054D
_08150218: .4byte 0x0000054E
_0815021C: .4byte 0x00000541
_08150220: .4byte 0x000005BC
_08150224: .4byte 0x00000542
_08150228: .4byte 0x0203B400
_0815022C: .4byte 0x030046B8
_08150230: .4byte 0x000003FF
_08150234:
	mov sb, sp
	ldr r6, _08150270 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _08150274
	adds r0, #4
	b _0815027E
	.align 2, 0
_08150270: .4byte 0x030046A4
_08150274:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815027E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081502B8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081502C0
	ldr r0, _081502BC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081502EA
	.align 2, 0
_081502B8: .4byte 0x000004A4
_081502BC: .4byte 0xFFFFFDFF
_081502C0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081502E0
	cmp r0, #2
	beq _081502DC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081502DC:
	movs r0, #1
	b _081502EC
_081502E0:
	ldr r0, _08150300 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081502EA:
	movs r0, #0
_081502EC:
	cmp r0, #0
	beq _081502F2
	b _081504D8
_081502F2:
	ldr r4, _08150304 @ =0x000005C4
	adds r0, r7, r4
_081502F6:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081504D8
	.align 2, 0
_08150300: .4byte 0xFFFFFDFF
_08150304: .4byte 0x000005C4
_08150308:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0815031A
	b _08150496
_0815031A:
	ldr r3, _08150380 @ =FUN_0814c28c
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _08150384 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08150388 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815037A
	cmp r1, #0
	blt _0815037A
	ldr r0, _0815038C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815037A
	ldr r0, _08150390 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150394
_0815037A:
	movs r4, #0
	b _081503A2
	.align 2, 0
_08150380: .4byte FUN_0814c28c
_08150384: .4byte 0x00000554
_08150388: .4byte 0x00000551
_0815038C: .4byte 0x030046A8
_08150390: .4byte 0x030046AC
_08150394:
	ldr r0, _081503B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081503A2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081503B8
	adds r0, #4
	b _081503C4
	.align 2, 0
_081503B4: .4byte 0x030046A4
_081503B8:
	ldr r0, _081503D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081503C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081503DC
	cmp r2, #2
	beq _081503E0
	b _081503E4
	.align 2, 0
_081503D8: .4byte 0x030046A4
_081503DC:
	ldrb r0, [r5, #4]
	b _081503E2
_081503E0:
	ldrb r0, [r5]
_081503E2:
	subs r1, r1, r0
_081503E4:
	strh r1, [r5, #2]
	ldr r2, _08150414 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815041C
	ldr r0, _08150418 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _08150446
	.align 2, 0
_08150414: .4byte 0x000004A4
_08150418: .4byte 0xFFFFFDFF
_0815041C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815043C
	cmp r0, #2
	beq _08150438
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08150438:
	movs r0, #1
	b _08150448
_0815043C:
	ldr r0, _08150480 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_08150446:
	movs r0, #0
_08150448:
	adds r3, r0, #0
	cmp r3, #0
	bne _08150488
	ldr r0, _08150484 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x48]
	strb r2, [r1]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x2c]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r1, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081504D8
	.align 2, 0
_08150480: .4byte 0xFFFFFDFF
_08150484: .4byte Enemy_ClearStateBegun
_08150488:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081504D8
_08150496:
	ldr r3, _081504CC @ =FUN_0814c28c
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081504D0 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _081504D8
	.align 2, 0
_081504CC: .4byte FUN_0814c28c
_081504D0: .4byte 0x00000551

_081504D4:
	adds r0, #1
	str r0, [r1]
_081504D8:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
