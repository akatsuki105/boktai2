	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r1, _081066F4 @ =0x08251FE4
	ldr r2, _081066F8 @ =0x00000679
	adds r0, r7, #0
	bl Enemy_ClearPendingState
	ldr r2, _081066FC @ =0x00000757
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r5, #0
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r6, _08106700 @ =0x0000075C
	adds r1, r4, r6
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0810671C
	ldrb r1, [r7, #5]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl Skeleton_PickWalkDest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081066A4
	bl _08107444
_081066A4:
	ldr r2, _08106704 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08106708 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _0810670C @ =0x0000046B
	adds r0, r7, r4
	strb r5, [r0]
	ldr r6, _08106710 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #0xf
	subs r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08106714 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08106718 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r4, #4
	adds r0, r7, r4
	strb r3, [r0]
	bl _08107444
	.align 2, 0
_081066F4: .4byte 0x08251FE4
_081066F8: .4byte 0x00000679
_081066FC: .4byte 0x00000757
_08106700: .4byte 0x0000075C
_08106704: .4byte Enemy_ClearStateBegun
_08106708: .4byte 0x0000046D
_0810670C: .4byte 0x0000046B
_08106710: .4byte 0x00000553
_08106714: .4byte 0x0000046A
_08106718: .4byte 0x00000484
_0810671C:
	movs r5, #0xec
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r2, r0
	bhi _0810672A
	b _08106DB8
_0810672A:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _0810673E
	ldr r0, _08106780 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_0810673E:
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
	str r3, [sp, #0x9c]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _0810677A
	cmp r1, #0
	blt _0810677A
	ldr r0, _08106784 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0810677A
	ldr r0, _08106788 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810678C
_0810677A:
	movs r4, #0
	b _0810679A
	.align 2, 0
_08106780: .4byte 0x03002BE0
_08106784: .4byte 0x030046A8
_08106788: .4byte 0x030046AC
_0810678C:
	ldr r0, _081067AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0810679A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081067B0
	adds r0, #4
	b _081067BC
	.align 2, 0
_081067AC: .4byte 0x030046A4
_081067B0:
	ldr r0, _081067D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081067BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081067D4
	cmp r2, #2
	beq _081067D8
	b _081067DC
	.align 2, 0
_081067D0: .4byte 0x030046A4
_081067D4:
	ldrb r0, [r5, #4]
	b _081067DA
_081067D8:
	ldrb r0, [r5]
_081067DA:
	subs r1, r1, r0
_081067DC:
	strh r1, [r5, #2]
	ldr r0, _081067F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081067F4
	movs r0, #1
	b _081067F6
	.align 2, 0
_081067F0: .4byte 0x030047A4
_081067F4:
	movs r0, #0
_081067F6:
	cmp r0, #0
	beq _08106834
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08106816
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08106812
	adds r2, r0, #0
_08106812:
	cmp r2, #0
	bge _08106820
_08106816:
	ldr r2, _0810681C @ =0x000005C4
	adds r0, r7, r2
	b _08106D50
	.align 2, 0
_0810681C: .4byte 0x000005C4
_08106820:
	ldr r1, _08106830 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810687C
	.align 2, 0
_08106830: .4byte 0x03002BE0
_08106834:
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
	blt _08106860
	cmp r1, #0
	blt _08106860
	ldr r0, _08106864 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106860
	ldr r0, _08106868 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810686C
_08106860:
	movs r5, #0
	b _0810687A
	.align 2, 0
_08106864: .4byte 0x030046A8
_08106868: .4byte 0x030046AC
_0810686C:
	ldr r0, _081068BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810687A:
	movs r2, #0
_0810687C:
	ldr r4, _081068C0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810689C
	ldr r1, _081068C4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810689C
	b _08106C94
_0810689C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x10]
	str r2, [sp, #0x74]
	cmp r1, #0
	beq _081068C8
	movs r0, #0
	b _08106D66
	.align 2, 0
_081068BC: .4byte 0x030046A4
_081068C0: .4byte 0x00000256
_081068C4: .4byte 0x03002BE0
_081068C8:
	ldr r6, _0810696C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x74]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xa0]
	cmp r6, #0
	beq _08106980
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08106970 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x14]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08106974 @ =0x0000046B
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
	ldr r2, _08106978 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0810697C @ =0x00000484
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
	str r6, [sp, #0xac]
	mov r6, r8
	str r6, [sp, #0xb0]
	str r5, [sp, #0x94]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x98]
	str r0, [sp, #0x88]
	b _08106B52
	.align 2, 0
_0810696C: .4byte 0x00000222
_08106970: .4byte 0x0000046D
_08106974: .4byte 0x0000046B
_08106978: .4byte 0x00000469
_0810697C: .4byte 0x00000484
_08106980:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _08106A44 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _08106A48 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _08106A4C @ =0x00000553
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
	ldr r2, _08106A50 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08106A54 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08106A58 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x9c]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
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
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x98]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _08106A3E
	cmp r1, #0
	blt _08106A3E
	ldr r0, _08106A5C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _08106A3E
	ldr r0, _08106A60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106A64
_08106A3E:
	movs r4, #0
	b _08106A74
	.align 2, 0
_08106A44: .4byte 0x0000046D
_08106A48: .4byte 0x0000046B
_08106A4C: .4byte 0x00000553
_08106A50: .4byte 0x00000469
_08106A54: .4byte 0x00000484
_08106A58: .4byte 0x0000046C
_08106A5C: .4byte 0x030046A8
_08106A60: .4byte 0x030046AC
_08106A64:
	ldr r0, _08106A84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_08106A74:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08106A88
	adds r0, #4
	b _08106A94
	.align 2, 0
_08106A84: .4byte 0x030046A4
_08106A88:
	ldr r0, _08106AA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08106A94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08106AAC
	cmp r2, #2
	beq _08106AB2
	b _08106AB8
	.align 2, 0
_08106AA8: .4byte 0x030046A4
_08106AAC:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _08106AB6
_08106AB2:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_08106AB6:
	subs r1, r1, r0
_08106AB8:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x9c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08106AE4
	cmp r1, #0
	blt _08106AE4
	ldr r0, _08106AE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106AE4
	ldr r0, _08106AEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106AF0
_08106AE4:
	movs r4, #0
	b _08106AFE
	.align 2, 0
_08106AE8: .4byte 0x030046A8
_08106AEC: .4byte 0x030046AC
_08106AF0:
	ldr r0, _08106B14 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08106AFE:
	ldr r6, [sp, #0x9c]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08106B18
	adds r0, #4
	b _08106B24
	.align 2, 0
_08106B14: .4byte 0x030046A4
_08106B18:
	ldr r0, _08106B38 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08106B24:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08106B3C
	cmp r3, #2
	beq _08106B40
	b _08106B44
	.align 2, 0
_08106B38: .4byte 0x030046A4
_08106B3C:
	ldrb r0, [r5, #4]
	b _08106B42
_08106B40:
	ldrb r0, [r5]
_08106B42:
	subs r2, r2, r0
_08106B44:
	ldr r1, [sp, #0x9c]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x9c]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08106B52:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x74]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _08106B7C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x90]
	cmp r0, #0
	bne _08106C5C
	movs r1, #4
	ldr r2, [sp, #0xa0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08106B80
	movs r0, #1
	b _08106B82
	.align 2, 0
_08106B7C: .4byte 0x00000482
_08106B80:
	movs r0, #0
_08106B82:
	ldr r3, _08106C6C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x90]
	cmp r0, #0
	bne _08106C5C
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xbc]
	ldr r1, _08106C70 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08106C74 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08106C78 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa8]
	ldr r1, _08106C7C @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08106C80 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r6, _08106C84 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _08106C88 @ =0x030046B8
	adds r2, r5, #0
_08106BCA:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _08106C8C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08106C90 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _08106BEE
	adds r3, #1
	cmp r3, #3
	ble _08106BCA
	adds r0, r5, #0
_08106BEE:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xac]
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
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x94]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x98]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_08106C5C:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _08106D66
	.align 2, 0
_08106C6C: .4byte 0x00000482
_08106C70: .4byte 0x0000054F
_08106C74: .4byte 0x0000054C
_08106C78: .4byte 0x0000054E
_08106C7C: .4byte 0x00000541
_08106C80: .4byte 0x000005BC
_08106C84: .4byte 0x00000542
_08106C88: .4byte 0x030046B8
_08106C8C: .4byte 0x000003FF
_08106C90: .4byte 0x0203B400
_08106C94:
	mov sb, sp
	ldr r6, _08106CD0 @ =0x030046A4
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
	beq _08106CD4
	adds r0, #4
	b _08106CDE
	.align 2, 0
_08106CD0: .4byte 0x030046A4
_08106CD4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08106CDE:
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
	ldr r6, _08106D14 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08106D18
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _08106D3E
	.align 2, 0
_08106D14: .4byte 0x000004A4
_08106D18:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08106D38
	cmp r0, #2
	beq _08106D34
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08106D34:
	movs r0, #1
	b _08106D48
_08106D38:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_08106D3E:
	ldr r1, _08106D5C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08106D48:
	cmp r0, #0
	bne _08106D64
	ldr r3, _08106D60 @ =0x000005C4
	adds r0, r7, r3
_08106D50:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08106D66
	.align 2, 0
_08106D5C: .4byte 0xFFFFFDFF
_08106D60: .4byte 0x000005C4
_08106D64:
	movs r0, #1
_08106D66:
	cmp r0, #0
	bne _08106D6C
	b _08107444
_08106D6C:
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r5, _08106DAC @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08106DB0 @ =0x0000046B
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
	ldr r6, _08106DB4 @ =0x00000469
	b _0810742E
	.align 2, 0
_08106DAC: .4byte 0x0000046D
_08106DB0: .4byte 0x0000046B
_08106DB4: .4byte 0x00000469
_08106DB8:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _08106DCC
	ldr r0, _08106E0C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_08106DCC:
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
	str r3, [sp, #0x9c]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _08106E08
	cmp r1, #0
	blt _08106E08
	ldr r0, _08106E10 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08106E08
	ldr r0, _08106E14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106E18
_08106E08:
	movs r4, #0
	b _08106E26
	.align 2, 0
_08106E0C: .4byte 0x03002BE0
_08106E10: .4byte 0x030046A8
_08106E14: .4byte 0x030046AC
_08106E18:
	ldr r0, _08106E38 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08106E26:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08106E3C
	adds r0, #4
	b _08106E48
	.align 2, 0
_08106E38: .4byte 0x030046A4
_08106E3C:
	ldr r0, _08106E5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08106E48:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08106E60
	cmp r2, #2
	beq _08106E64
	b _08106E68
	.align 2, 0
_08106E5C: .4byte 0x030046A4
_08106E60:
	ldrb r0, [r5, #4]
	b _08106E66
_08106E64:
	ldrb r0, [r5]
_08106E66:
	subs r1, r1, r0
_08106E68:
	strh r1, [r5, #2]
	ldr r0, _08106E7C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08106E80
	movs r0, #1
	b _08106E82
	.align 2, 0
_08106E7C: .4byte 0x030047A4
_08106E80:
	movs r0, #0
_08106E82:
	cmp r0, #0
	beq _08106EB8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _08106E94
	b _081073D4
_08106E94:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08106EA0
	adds r2, r0, #0
_08106EA0:
	cmp r2, #0
	bge _08106EA6
	b _081073D4
_08106EA6:
	ldr r1, _08106EB4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08106F00
	.align 2, 0
_08106EB4: .4byte 0x03002BE0
_08106EB8:
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
	blt _08106EE4
	cmp r1, #0
	blt _08106EE4
	ldr r0, _08106EE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106EE4
	ldr r0, _08106EEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106EF0
_08106EE4:
	movs r5, #0
	b _08106EFE
	.align 2, 0
_08106EE8: .4byte 0x030046A8
_08106EEC: .4byte 0x030046AC
_08106EF0:
	ldr r0, _08106F40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08106EFE:
	movs r2, #0
_08106F00:
	ldr r4, _08106F44 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08106F20
	ldr r1, _08106F48 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08106F20
	b _08107318
_08106F20:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x40]
	str r2, [sp, #0x74]
	cmp r1, #0
	beq _08106F4C
	movs r0, #0
	b _081073EE
	.align 2, 0
_08106F40: .4byte 0x030046A4
_08106F44: .4byte 0x00000256
_08106F48: .4byte 0x03002BE0
_08106F4C:
	ldr r6, _08106FF0 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x74]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xa0]
	cmp r0, #0
	beq _08107004
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08106FF4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x44]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08106FF8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x48]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x50]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	add r0, sp, #0x40
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08106FFC @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _08107000 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x40]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xac]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb0]
	str r5, [sp, #0x94]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x98]
	str r0, [sp, #0x88]
	b _081071D6
	.align 2, 0
_08106FF0: .4byte 0x00000222
_08106FF4: .4byte 0x0000046D
_08106FF8: .4byte 0x0000046B
_08106FFC: .4byte 0x00000469
_08107000: .4byte 0x00000484
_08107004:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081070C8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _081070CC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081070D0 @ =0x00000553
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
	ldr r4, _081070D4 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081070D8 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081070DC @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x9c]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
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
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x98]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _081070C4
	cmp r1, #0
	blt _081070C4
	ldr r0, _081070E0 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081070C4
	ldr r0, _081070E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081070E8
_081070C4:
	movs r4, #0
	b _081070F8
	.align 2, 0
_081070C8: .4byte 0x0000046D
_081070CC: .4byte 0x0000046B
_081070D0: .4byte 0x00000553
_081070D4: .4byte 0x00000469
_081070D8: .4byte 0x0000046A
_081070DC: .4byte 0x00000484
_081070E0: .4byte 0x030046A8
_081070E4: .4byte 0x030046AC
_081070E8:
	ldr r0, _08107108 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081070F8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810710C
	adds r0, #4
	b _08107118
	.align 2, 0
_08107108: .4byte 0x030046A4
_0810710C:
	ldr r0, _0810712C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08107118:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08107130
	cmp r2, #2
	beq _08107136
	b _0810713C
	.align 2, 0
_0810712C: .4byte 0x030046A4
_08107130:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _0810713A
_08107136:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_0810713A:
	subs r1, r1, r0
_0810713C:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x9c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08107168
	cmp r1, #0
	blt _08107168
	ldr r0, _0810716C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08107168
	ldr r0, _08107170 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08107174
_08107168:
	movs r4, #0
	b _08107182
	.align 2, 0
_0810716C: .4byte 0x030046A8
_08107170: .4byte 0x030046AC
_08107174:
	ldr r0, _08107198 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08107182:
	ldr r6, [sp, #0x9c]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810719C
	adds r0, #4
	b _081071A8
	.align 2, 0
_08107198: .4byte 0x030046A4
_0810719C:
	ldr r0, _081071BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081071A8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081071C0
	cmp r3, #2
	beq _081071C4
	b _081071C8
	.align 2, 0
_081071BC: .4byte 0x030046A4
_081071C0:
	ldrb r0, [r5, #4]
	b _081071C6
_081071C4:
	ldrb r0, [r5]
_081071C6:
	subs r2, r2, r0
_081071C8:
	ldr r1, [sp, #0x9c]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x9c]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081071D6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x74]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _08107200 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x90]
	cmp r0, #0
	bne _081072E0
	movs r1, #4
	ldr r2, [sp, #0xa0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08107204
	movs r0, #1
	b _08107206
	.align 2, 0
_08107200: .4byte 0x00000482
_08107204:
	movs r0, #0
_08107206:
	ldr r3, _081072F0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x90]
	cmp r0, #0
	bne _081072E0
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xbc]
	ldr r1, _081072F4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081072F8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081072FC @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa8]
	ldr r1, _08107300 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08107304 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r6, _08107308 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _0810730C @ =0x030046B8
	adds r2, r5, #0
_0810724E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _08107310 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08107314 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _08107272
	adds r3, #1
	cmp r3, #3
	ble _0810724E
	adds r0, r5, #0
_08107272:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xac]
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
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x94]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x98]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081072E0:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081073EE
	.align 2, 0
_081072F0: .4byte 0x00000482
_081072F4: .4byte 0x0000054F
_081072F8: .4byte 0x0000054C
_081072FC: .4byte 0x0000054E
_08107300: .4byte 0x00000541
_08107304: .4byte 0x000005BC
_08107308: .4byte 0x00000542
_0810730C: .4byte 0x030046B8
_08107310: .4byte 0x000003FF
_08107314: .4byte 0x0203B400
_08107318:
	add r6, sp, #8
	ldr r0, _08107358 @ =0x030046A4
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
	beq _0810735C
	adds r0, #4
	b _08107368
	.align 2, 0
_08107358: .4byte 0x030046A4
_0810735C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08107368:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0810739C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081073A0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _081073C6
	.align 2, 0
_0810739C: .4byte 0x000004A4
_081073A0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081073C0
	cmp r0, #2
	beq _081073BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081073BC:
	movs r0, #1
	b _081073D0
_081073C0:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_081073C6:
	ldr r1, _081073E4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081073D0:
	cmp r0, #0
	bne _081073EC
_081073D4:
	ldr r2, _081073E8 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081073EE
	.align 2, 0
_081073E4: .4byte 0xFFFFFDFF
_081073E8: .4byte 0x000005C4
_081073EC:
	movs r0, #1
_081073EE:
	cmp r0, #0
	beq _08107444
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r4, _08107454 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08107458 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0810745C @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
_0810742E:
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08107460 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08107464 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
_08107444:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08107454: .4byte 0x0000046D
_08107458: .4byte 0x0000046B
_0810745C: .4byte 0x00000553
_08107460: .4byte 0x0000046A
_08107464: .4byte 0x00000484
