	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	mov r8, r7
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0xa9
	ldrb r0, [r4]
	cmp r0, #0
	beq _081FE36A
	movs r0, #0
	strb r0, [r4]
	ldr r0, _081FE3B0 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r7, #0
	adds r3, #0x50
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
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
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
	mov r0, sl
	bl NestedState_Reset0
_081FE36A:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _081FE380
	b _081FEA6E
_081FE380:
	movs r5, #1
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r5
	str r1, [sp, #0x2c]
	cmp r0, #0
	beq _081FE3B8
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #2
	bhi _081FE3B8
	ldr r1, _081FE3B4 @ =FUN_081fd000
	movs r0, #5
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	strb r5, [r4]
	b _081FEA6E
	.align 2, 0
_081FE3B0: .4byte 0x03002BE0
_081FE3B4: .4byte FUN_081fd000
_081FE3B8:
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #9
	bls _081FE3C2
	b _081FEA6E
_081FE3C2:
	lsls r0, r0, #2
	ldr r1, _081FE3CC @ =_081FE3D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FE3CC: .4byte _081FE3D0
_081FE3D0: @ jump table
	.4byte _081FE3F8 @ case 0
	.4byte _081FE424 @ case 1
	.4byte _081FE452 @ case 2
	.4byte _081FE584 @ case 3
	.4byte _081FE7C4 @ case 4
	.4byte _081FE800 @ case 5
	.4byte _081FE9DC @ case 6
	.4byte _081FEA18 @ case 7
	.4byte _081FEA54 @ case 8
	.4byte _081FEA66 @ case 9
_081FE3F8:
	mov r5, sl
	ldr r3, [r5, #4]
	cmp r3, #0
	beq _081FE402
	b _081FEA42
_081FE402:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	str r4, [r5, #4]
	b _081FEA42
_081FE424:
	mov r0, sl
	ldr r3, [r0, #4]
	cmp r3, #0
	beq _081FE42E
	b _081FEA42
_081FE42E:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	mov r1, sl
	str r4, [r1, #4]
	b _081FEA42
_081FE452:
	mov r2, sl
	ldr r3, [r2, #4]
	cmp r3, #0
	bne _081FE484
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #6
	bl Boss_PlayAnimFacing
	ldr r0, _081FE4CC @ =0x000007CC
	add r0, r8
	ldr r0, [r0]
	movs r1, #3
	bl FUN_08203d0c
_081FE484:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	ldr r1, _081FE4D0 @ =0x000007F4
	add r1, r8
	mov r3, sl
	ldr r0, [r3, #4]
	ldrh r1, [r1]
	cmp r0, r1
	bls _081FE51E
	adds r0, r7, #0
	adds r0, #0x4d
	add r3, sp, #0xc
	ldrb r4, [r0]
	movs r5, #5
	rsbs r5, r5, #0
	ldr r2, _081FE4D4 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FE4D8
	asrs r1, r0, #0xc
	b _081FE4DE
	.align 2, 0
_081FE4CC: .4byte 0x000007CC
_081FE4D0: .4byte 0x000007F4
_081FE4D4: .4byte gSineTable
_081FE4D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE4DE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FE4F6
	asrs r0, r0, #0xc
	b _081FE4FC
_081FE4F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FE4FC:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x50
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
_081FE51E:
	mov r3, sl
	ldr r1, [r3, #4]
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	beq _081FE52E
	cmp r1, #3
	bne _081FE56A
_081FE52E:
	ldr r2, _081FE554 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FE558 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _081FE55C @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FE560
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, #0
	bl FUN_081fad7c
	b _081FE56A
	.align 2, 0
_081FE554: .4byte 0x030046B8
_081FE558: .4byte 0x000003FF
_081FE55C: .4byte 0x0203B400
_081FE560:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r7, #0
	bl FUN_081fabc0
_081FE56A:
	mov r1, sl
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	ldr r1, _081FE580 @ =0x000007F2
	add r1, r8
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081FE57E
	b _081FEA6E
_081FE57E:
	b _081FEA5E
	.align 2, 0
_081FE580: .4byte 0x000007F2
_081FE584:
	mov r2, sl
	ldr r0, [r2, #4]
	movs r3, #0xcc
	adds r3, r3, r7
	mov sb, r3
	cmp r0, #0
	bne _081FE61E
	ldr r1, _081FE5D4 @ =0x00000807
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081FE5D8 @ =0x00000806
	add r0, r8
	ldrb r1, [r0]
	mov r0, sb
	movs r2, #1
	bl Map_GetPathNodePos
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE5CE
	cmp r1, #0
	blt _081FE5CE
	ldr r0, _081FE5DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE5CE
	ldr r0, _081FE5E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE5E4
_081FE5CE:
	movs r4, #0
	b _081FE5F2
	.align 2, 0
_081FE5D4: .4byte 0x00000807
_081FE5D8: .4byte 0x00000806
_081FE5DC: .4byte 0x030046A8
_081FE5E0: .4byte 0x030046AC
_081FE5E4:
	ldr r0, _081FE604 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE5F2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FE608
	adds r0, #4
	b _081FE614
	.align 2, 0
_081FE604: .4byte 0x030046A4
_081FE608:
	ldr r0, _081FE670 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE614:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
_081FE61E:
	add r4, sp, #0x14
	adds r5, r7, #0
	adds r5, #0x50
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r3, sb
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	strh r2, [r4, #2]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #0x24]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081FE674
	movs r1, #1
	rsbs r1, r1, #0
	b _081FE6A6
	.align 2, 0
_081FE670: .4byte 0x030046A4
_081FE674:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0x50
	muls r0, r2, r0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	movs r1, #0x50
	muls r0, r1, r0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r3, #0x50
	muls r0, r3, r0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #0x24]
_081FE6A6:
	movs r0, #0xc8
	lsls r0, r0, #5
	cmp r1, r0
	bgt _081FE6DC
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x50]
	str r1, [r7, #0x54]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r3, [sp, #0x2c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, _081FE6D8 @ =0x0000022B
	bl PlaySound_082406e0
	bl FUN_081fafd4
	mov r0, sl
	bl NestedState_Advance0
	b _081FE6F6
	.align 2, 0
_081FE6D8: .4byte 0x0000022B
_081FE6DC:
	add r0, sp, #0x14
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
_081FE6F6:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE71A
	cmp r1, #0
	blt _081FE71A
	ldr r0, _081FE720 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE71A
	ldr r0, _081FE724 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE728
_081FE71A:
	movs r4, #0
	b _081FE736
	.align 2, 0
_081FE720: .4byte 0x030046A8
_081FE724: .4byte 0x030046AC
_081FE728:
	ldr r0, _081FE748 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE736:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FE74C
	adds r0, #4
	b _081FE758
	.align 2, 0
_081FE748: .4byte 0x030046A4
_081FE74C:
	ldr r0, _081FE790 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE758:
	ldrb r1, [r0]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	mov r5, sl
	ldr r0, [r5, #4]
	ands r0, r2
	cmp r0, #0
	bne _081FE7A8
	ldr r2, _081FE794 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FE798 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FE79C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FE7A0
	adds r0, r7, #0
	movs r1, #0xfa
	bl FUN_081fad7c
	b _081FE7A8
	.align 2, 0
_081FE790: .4byte 0x030046A4
_081FE794: .4byte 0x030046B8
_081FE798: .4byte 0x000003FF
_081FE79C: .4byte 0x0203B400
_081FE7A0:
	adds r0, r7, #0
	movs r1, #0xfa
	bl FUN_081fabc0
_081FE7A8:
	mov r2, sl
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	b _081FEA6E
_081FE7C4:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0x96
	bl FUN_08022c24
	mov r3, sl
	ldr r0, [r3, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _081FE7DE
	bl FUN_081fafd4
_081FE7DE:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	mov r5, sl
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0xa
	bhi _081FE7FE
	b _081FEA6E
_081FE7FE:
	b _081FEA5E
_081FE800:
	mov r0, sl
	ldr r1, [r0, #4]
	movs r2, #0xcc
	adds r2, r2, r7
	mov sb, r2
	cmp r1, #0
	bne _081FE896
	ldr r0, _081FE84C @ =0x00000807
	add r0, r8
	strb r1, [r0]
	ldr r0, _081FE850 @ =0x00000806
	add r0, r8
	ldrb r1, [r0]
	mov r0, sb
	movs r2, #0
	bl Map_GetPathNodePos
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE848
	cmp r1, #0
	blt _081FE848
	ldr r0, _081FE854 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE848
	ldr r0, _081FE858 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE85C
_081FE848:
	movs r4, #0
	b _081FE86A
	.align 2, 0
_081FE84C: .4byte 0x00000807
_081FE850: .4byte 0x00000806
_081FE854: .4byte 0x030046A8
_081FE858: .4byte 0x030046AC
_081FE85C:
	ldr r0, _081FE87C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE86A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FE880
	adds r0, #4
	b _081FE88C
	.align 2, 0
_081FE87C: .4byte 0x030046A4
_081FE880:
	ldr r0, _081FE8F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE88C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
_081FE896:
	mov r3, sl
	ldr r0, [r3, #4]
	adds r0, #1
	str r0, [r3, #4]
	add r4, sp, #0x1c
	adds r5, r7, #0
	adds r5, #0x50
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r3, sb
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	strh r2, [r4, #2]
	movs r0, #0x50
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #0x28]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081FE8F8
	movs r1, #1
	rsbs r1, r1, #0
	b _081FE930
	.align 2, 0
_081FE8F4: .4byte 0x030046A4
_081FE8F8:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #0x28]
_081FE930:
	movs r0, #0xc8
	lsls r0, r0, #5
	cmp r1, r0
	ble _081FE940
	mov r1, sl
	ldr r0, [r1, #4]
	cmp r0, #0xa
	bls _081FE952
_081FE940:
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x50]
	str r1, [r7, #0x54]
	mov r0, sl
	bl NestedState_Advance0
	b _081FE96C
_081FE952:
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
_081FE96C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE990
	cmp r1, #0
	blt _081FE990
	ldr r0, _081FE994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE990
	ldr r0, _081FE998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE99C
_081FE990:
	movs r4, #0
	b _081FE9AA
	.align 2, 0
_081FE994: .4byte 0x030046A8
_081FE998: .4byte 0x030046AC
_081FE99C:
	ldr r0, _081FE9BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE9AA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FE9C0
	adds r0, #4
	b _081FE9CC
	.align 2, 0
_081FE9BC: .4byte 0x030046A4
_081FE9C0:
	ldr r0, _081FE9D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE9CC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	b _081FEA6E
	.align 2, 0
_081FE9D8: .4byte 0x030046A4
_081FE9DC:
	mov r3, sl
	ldr r0, [r3, #4]
	cmp r0, #0
	bne _081FEA42
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	mov r5, sl
	str r4, [r5, #4]
	ldr r0, _081FEA14 @ =0x000007CC
	add r0, r8
	ldr r0, [r0]
	bl FUN_08203d38
	b _081FEA42
	.align 2, 0
_081FEA14: .4byte 0x000007CC
_081FEA18:
	mov r1, sl
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FEA42
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	mov r2, sl
	str r4, [r2, #4]
_081FEA42:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl Boss_AdvanceAnim
_081FEA54:
	adds r0, r7, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FEA6E
_081FEA5E:
	mov r0, sl
	bl NestedState_Advance0
	b _081FEA6E
_081FEA66:
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FEA6E:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
