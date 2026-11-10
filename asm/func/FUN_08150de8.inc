	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	ldr r0, _08150E08 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08150E0E
	.align 2, 0
_08150E08: .4byte 0x0000046C
_08150E0C:
	movs r0, #0
_08150E0E:
	cmp r0, #0
	beq _08150E5C
	ldr r1, _08150FA0 @ =0x000005A4
	adds r0, r7, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08150FA4 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08150FA8 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _08150FAC @ =0x00000553
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _08150FB0 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08150E5C:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08150E72
	b _081514E0
_08150E72:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _08150E84
	b _081514E0
_08150E84:
	ldr r0, _08150FB4 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0x14
	bgt _08150E90
	b _081514DC
_08150E90:
	ldr r1, _08150FB8 @ =0x00000222
	adds r1, r7, r1
	str r1, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r1]
	ands r0, r1
	movs r4, #0
	ldr r2, [sp, #8]
	strh r0, [r2]
	ldr r1, _08150FBC @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r3, _08150FA4 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	movs r5, #1
	strb r5, [r3]
	ldr r6, _08150FA8 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r4, [r6]
	ldr r2, _08150FAC @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1c]
	mov r0, r8
	strh r0, [r6]
	ldr r1, _08150FC0 @ =0x00000543
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r6, _08150FC4 @ =0x00000554
	adds r0, r7, r6
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08150FC8 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08150FCC @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _08150FB4 @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _08150FD0 @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x3c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x38]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x68]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x6c]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x4c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x50]
	mov r0, ip
	str r0, [sp, #0x2c]
	mov r3, sl
	str r3, [sp, #0x30]
	mov r0, sb
	str r0, [sp, #0x34]
	str r6, [sp, #0x48]
	adds r6, r4, #0
	mov r8, r2
	cmp r5, #0
	blt _08150F9C
	cmp r1, #0
	blt _08150F9C
	ldr r0, _08150FD4 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08150F9C
	ldr r0, _08150FD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150FDC
_08150F9C:
	movs r5, #0
	b _08150FEA
	.align 2, 0
_08150FA0: .4byte 0x000005A4
_08150FA4: .4byte 0x0000046D
_08150FA8: .4byte 0x0000046B
_08150FAC: .4byte 0x00000553
_08150FB0: .4byte 0xFFFFFDFF
_08150FB4: .4byte 0x00000484
_08150FB8: .4byte 0x00000222
_08150FBC: .4byte Enemy_WaitPendingState
_08150FC0: .4byte 0x00000543
_08150FC4: .4byte 0x00000554
_08150FC8: .4byte 0x00000551
_08150FCC: .4byte 0x00000552
_08150FD0: .4byte 0x0000046C
_08150FD4: .4byte 0x030046A8
_08150FD8: .4byte 0x030046AC
_08150FDC:
	ldr r0, _08150FFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_08150FEA:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08151000
	adds r0, #4
	b _0815100C
	.align 2, 0
_08150FFC: .4byte 0x030046A4
_08151000:
	ldr r0, _08151020 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815100C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08151024
	cmp r2, #2
	beq _0815102A
	b _08151030
	.align 2, 0
_08151020: .4byte 0x030046A4
_08151024:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _0815102E
_0815102A:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_0815102E:
	subs r1, r1, r0
_08151030:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _08151048 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815104C
	movs r0, #1
	b _0815104E
	.align 2, 0
_08151048: .4byte 0x030047A4
_0815104C:
	movs r0, #0
_0815104E:
	cmp r0, #0
	beq _0815108C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _0815106E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815106A
	adds r2, r0, #0
_0815106A:
	cmp r2, #0
	bge _08151078
_0815106E:
	ldr r6, _08151074 @ =0x000005C4
	adds r0, r7, r6
	b _081514C8
	.align 2, 0
_08151074: .4byte 0x000005C4
_08151078:
	ldr r1, _08151088 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081510D4
	.align 2, 0
_08151088: .4byte 0x03002BE0
_0815108C:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081510B8
	cmp r1, #0
	blt _081510B8
	ldr r0, _081510BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081510B8
	ldr r0, _081510C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081510C4
_081510B8:
	movs r5, #0
	b _081510D2
	.align 2, 0
_081510BC: .4byte 0x030046A8
_081510C0: .4byte 0x030046AC
_081510C4:
	ldr r0, _08151168 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081510D2:
	movs r2, #0
_081510D4:
	ldr r3, _0815116C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081510F4
	ldr r1, _08151170 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081510F4
	b _0815140C
_081510F4:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0815110E
	b _081514E0
_0815110E:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x50]
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08151174
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x40]
	strb r2, [r6]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r6, [sp, #0x68]
	strb r0, [r6]
	ldr r0, [sp, #0x6c]
	str r1, [r0]
	ldr r1, [sp, #0x4c]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r6, [sp, #0x30]
	strb r5, [r6]
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	ldr r4, [sp, #0x48]
	str r3, [r4]
	ldr r5, [sp, #0x3c]
	strb r2, [r5]
	b _081512C2
	.align 2, 0
_08151168: .4byte 0x030046A4
_0815116C: .4byte 0x00000256
_08151170: .4byte 0x03002BE0
_08151174:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x40]
	strb r0, [r3]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r4, [sp, #0x6c]
	str r1, [r4]
	ldr r1, [sp, #0x4c]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x2c]
	strb r5, [r3]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r1, [sp, #0x48]
	str r2, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081511D8
	cmp r1, #0
	blt _081511D8
	ldr r0, _081511DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081511D8
	ldr r0, _081511E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081511E4
_081511D8:
	movs r5, #0
	b _081511F2
	.align 2, 0
_081511DC: .4byte 0x030046A8
_081511E0: .4byte 0x030046AC
_081511E4:
	ldr r0, _08151204 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081511F2:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08151208
	adds r0, #4
	b _08151214
	.align 2, 0
_08151204: .4byte 0x030046A4
_08151208:
	ldr r0, _08151228 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08151214:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815122C
	cmp r2, #2
	beq _08151230
	b _08151234
	.align 2, 0
_08151228: .4byte 0x030046A4
_0815122C:
	ldrb r0, [r4, #4]
	b _08151232
_08151230:
	ldrb r0, [r4]
_08151232:
	subs r1, r1, r0
_08151234:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815125C
	cmp r1, #0
	blt _0815125C
	ldr r0, _08151260 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815125C
	ldr r0, _08151264 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08151268
_0815125C:
	movs r5, #0
	b _08151276
	.align 2, 0
_08151260: .4byte 0x030046A8
_08151264: .4byte 0x030046AC
_08151268:
	ldr r0, _08151288 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08151276:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815128C
	adds r0, #4
	b _08151298
	.align 2, 0
_08151288: .4byte 0x030046A4
_0815128C:
	ldr r0, _081512AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08151298:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081512B0
	cmp r3, #2
	beq _081512B4
	b _081512B8
	.align 2, 0
_081512AC: .4byte 0x030046A4
_081512B0:
	ldrb r0, [r4, #4]
	b _081512B6
_081512B4:
	ldrb r0, [r4]
_081512B6:
	subs r2, r2, r0
_081512B8:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081512C2:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081512EC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _081513D0
	movs r1, #4
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081512F0
	movs r0, #1
	b _081512F2
	.align 2, 0
_081512EC: .4byte 0x00000482
_081512F0:
	movs r0, #0
_081512F2:
	ldr r3, _081513E0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _081513D0
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081513E4 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081513E8 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x5c]
	ldr r1, _081513EC @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x60]
	ldr r2, _081513F0 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r4, _081513F4 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x54]
	ldr r5, _081513F8 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _081513FC @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r6, _08151400 @ =0x0203B400
	ldr r1, _08151404 @ =0x030046B8
	ldr r2, _08151408 @ =0x000003FF
	movs r5, #3
	mov r4, r8
_08151342:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _08151360
	adds r3, #1
	cmp r3, #3
	ble _08151342
	mov r0, r8
_08151360:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x68]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x64]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x54]
	strb r4, [r2]
	ldr r4, [sp, #0x28]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x38]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r5, [sp, #0x6c]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x4c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r5, [sp, #0x30]
	strb r1, [r5]
	ldr r6, [sp, #0x34]
	strb r2, [r6]
	ldr r0, [sp, #0x48]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x58]
	strb r0, [r3]
_081513D0:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	b _081514E0
	.align 2, 0
_081513E0: .4byte 0x00000482
_081513E4: .4byte 0x0000054F
_081513E8: .4byte 0x0000054C
_081513EC: .4byte 0x0000054D
_081513F0: .4byte 0x0000054E
_081513F4: .4byte 0x00000541
_081513F8: .4byte 0x000005BC
_081513FC: .4byte 0x00000542
_08151400: .4byte 0x0203B400
_08151404: .4byte 0x030046B8
_08151408: .4byte 0x000003FF
_0815140C:
	mov sb, sp
	ldr r6, _08151448 @ =0x030046A4
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
	beq _0815144C
	adds r0, #4
	b _08151456
	.align 2, 0
_08151448: .4byte 0x030046A4
_0815144C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08151456:
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
	ldr r6, _0815148C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08151490
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081514B6
	.align 2, 0
_0815148C: .4byte 0x000004A4
_08151490:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081514B0
	cmp r0, #2
	beq _081514AC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081514AC:
	movs r0, #1
	b _081514C0
_081514B0:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081514B6:
	ldr r1, _081514D4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081514C0:
	cmp r0, #0
	bne _081514E0
	ldr r3, _081514D8 @ =0x000005C4
	adds r0, r7, r3
_081514C8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081514E0
	.align 2, 0
_081514D4: .4byte 0xFFFFFDFF
_081514D8: .4byte 0x000005C4
_081514DC:
	adds r0, #1
	str r0, [r1]
_081514E0:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
