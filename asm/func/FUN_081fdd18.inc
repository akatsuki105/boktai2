	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	adds r6, r7, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FDE02
	movs r3, #0
	strb r3, [r1]
	add r2, sp, #0x14
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r2, #0
	strh r1, [r0]
	strh r3, [r2, #2]
	strh r1, [r2, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r2, #0
	blt _081FDD66
	ldr r0, _081FDD6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FDD66
	ldr r0, _081FDD70 @ =0x030046AC
	ldr r1, [r0]
	movs r0, #7
	cmp r0, r1
	blo _081FDD74
_081FDD66:
	movs r4, #0
	b _081FDD7C
	.align 2, 0
_081FDD6C: .4byte 0x030046A8
_081FDD70: .4byte 0x030046AC
_081FDD74:
	ldr r0, _081FDD8C @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, r2
_081FDD7C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FDD90
	adds r0, #4
	b _081FDD9C
	.align 2, 0
_081FDD8C: .4byte 0x030046A4
_081FDD90:
	ldr r0, _081FDE24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FDD9C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	add r1, sp, #0x14
	strh r0, [r1, #2]
	adds r2, r7, #0
	adds r2, #0x50
	adds r3, r1, #0
	adds r0, r1, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r6, r4
	bl NestedState_Reset0
_081FDE02:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	mov r5, r8
	ldrb r0, [r5]
	cmp r0, #0xc
	bls _081FDE18
	b _081FE2D0
_081FDE18:
	lsls r0, r0, #2
	ldr r1, _081FDE28 @ =_081FDE2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FDE24: .4byte 0x030046A4
_081FDE28: .4byte _081FDE2C
_081FDE2C: @ jump table
	.4byte _081FDE60 @ case 0
	.4byte _081FDF24 @ case 1
	.4byte _081FDF76 @ case 2
	.4byte _081FDFBE @ case 3
	.4byte _081FE144 @ case 4
	.4byte _081FDFBE @ case 5
	.4byte _081FE144 @ case 6
	.4byte _081FDFBE @ case 7
	.4byte _081FE166 @ case 8
	.4byte _081FE1B0 @ case 9
	.4byte _081FE270 @ case 10
	.4byte _081FE2AE @ case 11
	.4byte _081FE2C8 @ case 12
_081FDE60:
	mov r0, r8
	ldr r5, [r0, #4]
	cmp r5, #0
	bne _081FDF08
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r5, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	mov r0, r8
	str r4, [r0, #4]
	movs r1, #0xf9
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _081FDEB0 @ =0x000007CA
	adds r4, r6, r2
	movs r1, #0
	strh r5, [r4]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _081FDED0
	cmp r0, #2
	bgt _081FDEB4
	cmp r0, #1
	beq _081FDEBA
	b _081FDEEC
	.align 2, 0
_081FDEB0: .4byte 0x000007CA
_081FDEB4:
	cmp r0, #3
	beq _081FDEDC
	b _081FDEEC
_081FDEBA:
	ldr r3, _081FDECC @ =0x000007C9
	adds r0, r6, r3
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_081fa620
	strh r0, [r4]
	b _081FDEF4
	.align 2, 0
_081FDECC: .4byte 0x000007C9
_081FDED0:
	ldr r2, _081FDED8 @ =0x000007C9
	adds r0, r6, r2
	b _081FDEE0
	.align 2, 0
_081FDED8: .4byte 0x000007C9
_081FDEDC:
	ldr r3, _081FDEE8 @ =0x000007C9
	adds r0, r6, r3
_081FDEE0:
	strb r1, [r0]
	strh r5, [r4]
	b _081FDEF4
	.align 2, 0
_081FDEE8: .4byte 0x000007C9
_081FDEEC:
	ldr r4, _081FDF1C @ =0x000007C9
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_081FDEF4:
	movs r0, #0xdd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r5, _081FDF20 @ =0x000007CC
	adds r0, r6, r5
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08203d0c
_081FDF08:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	b _081FE2B6
	.align 2, 0
_081FDF1C: .4byte 0x000007C9
_081FDF20: .4byte 0x000007CC
_081FDF24:
	mov r4, r8
	ldr r3, [r4, #4]
	cmp r3, #0
	bne _081FDF4E
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	mov r1, r8
	str r4, [r1, #4]
_081FDF4E:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	adds r0, r7, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FDF6C
	b _081FE2D0
_081FDF6C:
	mov r0, r8
	movs r1, #2
	bl NestedState_Set0
	b _081FE2D0
_081FDF76:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FDF9C
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #8
	bl Boss_PlayAnimFlip
	mov r5, r8
	str r4, [r5, #4]
_081FDF9C:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	mov r4, r8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x3c
	bhi _081FDFBC
	b _081FE2D0
_081FDFBC:
	b _081FE2C0
_081FDFBE:
	mov r5, r8
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _081FDFCC
	ldr r0, _081FE020 @ =0x000001B9
	bl PlaySound_082406e0
_081FDFCC:
	mov r1, r8
	ldr r0, [r1, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FDFDA
	b _081FE118
_081FDFDA:
	ldr r2, _081FE024 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FE028 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FE02C @ =0x0203B400
	adds r0, r0, r2
	movs r2, #0xff
	ldrb r0, [r0]
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x4d
	add r3, sp, #0x1c
	ldrb r5, [r0]
	movs r4, #0x50
	mov ip, r4
	ldr r1, _081FE030 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r4, ip
	muls r4, r0, r4
	adds r0, r4, #0
	adds r4, r3, #0
	adds r2, r1, #0
	cmp r0, #0
	blt _081FE034
	asrs r1, r0, #0xc
	b _081FE03A
	.align 2, 0
_081FE020: .4byte 0x000001B9
_081FE024: .4byte 0x030046B8
_081FE028: .4byte 0x000003FF
_081FE02C: .4byte 0x0203B400
_081FE030: .4byte gSineTable
_081FE034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE03A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FE056
	asrs r0, r0, #0xc
	b _081FE05C
_081FE056:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FE05C:
	strh r0, [r3, #4]
	ldrh r0, [r4]
	subs r0, #0x20
	add r1, sp, #0x1c
	strh r0, [r1]
	ldrh r0, [r1, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	subs r0, #0x20
	strh r0, [r1, #4]
	mov r3, sb
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081FE086
	asrs r1, r0, #0xc
	b _081FE08C
_081FE086:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE08C:
	ldrh r0, [r4]
	adds r0, r0, r1
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r0, sb
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081FE0AE
	asrs r1, r0, #0xc
	b _081FE0B4
_081FE0AE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE0B4:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r3, r7, #0
	adds r3, #0x50
	add r1, sp, #0x1c
	ldrh r0, [r3]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r5, [r4, #4]
	adds r0, r0, r5
	strh r0, [r4, #4]
	ldr r0, _081FE13C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r0, #0
	movs r0, #8
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	ldr r2, _081FE140 @ =0x000007EA
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #1
	movs r2, #0
	movs r3, #0x10
	bl DustManager_Emit
_081FE118:
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r5, #0x87
	lsls r5, r5, #2
	adds r2, r6, r5
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	mov r1, r8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x3c
	bhi _081FE138
	b _081FE2D0
_081FE138:
	b _081FE2C0
	.align 2, 0
_081FE13C: .4byte 0x03002BE0
_081FE140: .4byte 0x000007EA
_081FE144:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	mov r4, r8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x1e
	bhi _081FE164
	b _081FE2D0
_081FE164:
	b _081FE2C0
_081FE166:
	mov r5, r8
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _081FE18E
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #8
	bl Boss_PlayAnimFacing
	str r4, [r5, #4]
_081FE18E:
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r5, #0x87
	lsls r5, r5, #2
	adds r2, r6, r5
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	mov r1, r8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x64
	bhi _081FE1AE
	b _081FE2D0
_081FE1AE:
	b _081FE2C0
_081FE1B0:
	mov r2, r8
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FE258
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r4, #2
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	mov r0, r8
	str r5, [r0, #4]
	ldr r1, _081FE20C @ =0x000007CC
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_08203d38
	ldr r2, _081FE210 @ =0x00000233
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	ldr r5, _081FE214 @ =0x000007CA
	adds r4, r6, r5
	movs r1, #0
	strh r2, [r4]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _081FE234
	cmp r0, #2
	bgt _081FE218
	cmp r0, #1
	beq _081FE21E
	b _081FE250
	.align 2, 0
_081FE20C: .4byte 0x000007CC
_081FE210: .4byte 0x00000233
_081FE214: .4byte 0x000007CA
_081FE218:
	cmp r0, #3
	beq _081FE240
	b _081FE250
_081FE21E:
	ldr r2, _081FE230 @ =0x000007C9
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_081fa620
	strh r0, [r4]
	b _081FE258
	.align 2, 0
_081FE230: .4byte 0x000007C9
_081FE234:
	ldr r3, _081FE23C @ =0x000007C9
	adds r0, r6, r3
	b _081FE244
	.align 2, 0
_081FE23C: .4byte 0x000007C9
_081FE240:
	ldr r5, _081FE24C @ =0x000007C9
	adds r0, r6, r5
_081FE244:
	strb r1, [r0]
	strh r2, [r4]
	b _081FE258
	.align 2, 0
_081FE24C: .4byte 0x000007C9
_081FE250:
	ldr r0, _081FE26C @ =0x000007C9
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_081FE258:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	b _081FE2B6
	.align 2, 0
_081FE26C: .4byte 0x000007C9
_081FE270:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FE29A
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	mov r1, r8
	str r4, [r1, #4]
_081FE29A:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	b _081FE2B6
_081FE2AE:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_081fa628
_081FE2B6:
	adds r0, r7, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FE2D0
_081FE2C0:
	mov r0, r8
	bl NestedState_Advance0
	b _081FE2D0
_081FE2C8:
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FE2D0:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
