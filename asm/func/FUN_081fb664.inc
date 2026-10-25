	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xb4
	mov sb, r0
	mov r4, sb
	movs r5, #0xfe
	lsls r5, r5, #1
	add r5, sb
	mov r1, sb
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FB690
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FB692
_081FB690:
	movs r0, #0
_081FB692:
	cmp r0, #0
	beq _081FB69C
	adds r0, r5, #0
	bl NestedState_Reset0
_081FB69C:
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #5
	bne _081FB6B8
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB6B8
	movs r0, #3
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
_081FB6B8:
	ldrb r0, [r5]
	cmp r0, #6
	bls _081FB6C0
	b _081FBAF8
_081FB6C0:
	lsls r0, r0, #2
	ldr r1, _081FB6CC @ =_081FB6D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FB6CC: .4byte _081FB6D0
_081FB6D0: @ jump table
	.4byte _081FB6EC @ case 0
	.4byte _081FB756 @ case 1
	.4byte _081FB908 @ case 2
	.4byte _081FB91E @ case 3
	.4byte _081FBAD0 @ case 4
	.4byte _081FBAE4 @ case 5
	.4byte _081FBAEE @ case 6
_081FB6EC:
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _081FB74C
	ldr r2, _081FB718 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FB71C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FB720 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FB724
	mov r0, sb
	movs r1, #2
	movs r2, #0
	bl FUN_081fc890
	b _081FB72E
	.align 2, 0
_081FB718: .4byte 0x030046B8
_081FB71C: .4byte 0x000003FF
_081FB720: .4byte 0x0203B400
_081FB724:
	mov r0, sb
	movs r1, #5
	movs r2, #0
	bl FUN_081fc890
_081FB72E:
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0xa2
	strb r1, [r0]
	movs r1, #0
	movs r2, #0
	movs r0, #0x81
	lsls r0, r0, #4
	add r0, sb
_081FB740:
	strb r2, [r0]
	strb r1, [r0, #8]
	adds r0, #1
	adds r1, #1
	cmp r1, #7
	ble _081FB740
_081FB74C:
	adds r0, r5, #0
	movs r1, #1
	bl NestedState_Set0
	b _081FBAF8
_081FB756:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	beq _081FB768
	b _081FB8E2
_081FB768:
	add r4, sp, #0x94
	adds r0, r4, #0
	movs r1, #0
	bl Map_PickRandomPathNode
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _081FB79A
	cmp r1, #0
	blt _081FB79A
	ldr r0, _081FB7A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB79A
	ldr r0, _081FB7A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB7A8
_081FB79A:
	movs r4, #0
	b _081FB7B6
	.align 2, 0
_081FB7A0: .4byte 0x030046A8
_081FB7A4: .4byte 0x030046AC
_081FB7A8:
	ldr r0, _081FB7C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB7B6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FB7CC
	adds r0, #4
	b _081FB7D8
	.align 2, 0
_081FB7C8: .4byte 0x030046A4
_081FB7CC:
	ldr r0, _081FB8F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB7D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	ldr r0, _081FB8F8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	mov r8, r0
	add r0, sp, #0x94
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r0, _081FB8FC @ =0x00000237
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_081e9f78
	ldrh r0, [r7, #2]
	adds r0, #0x20
	strh r0, [r7, #2]
	add r0, sp, #0xc
	mov r2, r8
	ldrh r1, [r2, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _081FB900 @ =0xFFFF0000
	add r7, sp, #0x9c
	ldr r0, [r7]
	ands r0, r6
	orrs r0, r1
	str r0, [r7]
	add r0, sp, #0xc
	ldrh r1, [r2, #0xc]
	ldrh r0, [r0, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r7, #0
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4, #4]
	ldrh r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0x30
	ble _081FB882
	adds r0, r6, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4]
_081FB882:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081FB898
	ldr r0, [r4]
	ands r0, r6
	ldr r1, _081FB904 @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4]
_081FB898:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0x30
	ble _081FB8AA
	ldr r0, [r4, #4]
	ands r0, r6
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4, #4]
_081FB8AA:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bge _081FB8BC
	ldr r0, [r4, #4]
	ands r0, r6
	ldr r1, _081FB904 @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4, #4]
_081FB8BC:
	movs r0, #0xfe
	lsls r0, r0, #3
	add r0, sb
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r7, #0
	bl FUN_081ea524
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_081FB8E2:
	ldr r0, [r5, #8]
	cmp r0, #3
	bhi _081FB8EA
	b _081FBAF8
_081FB8EA:
	adds r0, r5, #0
	movs r1, #2
	bl NestedState_Set0
	b _081FBAF8
	.align 2, 0
_081FB8F4: .4byte 0x030046A4
_081FB8F8: .4byte 0x03002BE0
_081FB8FC: .4byte 0x00000237
_081FB900: .4byte 0xFFFF0000
_081FB904: .4byte 0x0000FFD0
_081FB908:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0x5a
	bhi _081FB914
	b _081FBAF8
_081FB914:
	adds r0, r5, #0
	movs r1, #3
	bl NestedState_Set0
	b _081FBAF8
_081FB91E:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	beq _081FB930
	b _081FBAAC
_081FB930:
	add r4, sp, #0xa4
	adds r0, r4, #0
	movs r1, #0
	bl Map_PickRandomPathNode
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _081FB962
	cmp r1, #0
	blt _081FB962
	ldr r0, _081FB968 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB962
	ldr r0, _081FB96C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB970
_081FB962:
	movs r4, #0
	b _081FB97E
	.align 2, 0
_081FB968: .4byte 0x030046A8
_081FB96C: .4byte 0x030046AC
_081FB970:
	ldr r0, _081FB990 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB97E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FB994
	adds r0, #4
	b _081FB9A0
	.align 2, 0
_081FB990: .4byte 0x030046A4
_081FB994:
	ldr r0, _081FBABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB9A0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	ldr r0, _081FBAC0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	mov sl, r0
	add r0, sp, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x58]
	str r1, [sp, #0x5c]
	ldr r0, _081FBAC4 @ =0x00000237
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_081e9f78
	ldrh r0, [r7, #2]
	adds r0, #0x20
	strh r0, [r7, #2]
	add r0, sp, #0x50
	mov r8, r0
	mov r2, sl
	ldrh r1, [r2, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _081FBAC8 @ =0xFFFF0000
	add r7, sp, #0xac
	ldr r0, [r7]
	ands r0, r6
	orrs r0, r1
	str r0, [r7]
	ldrh r1, [r2, #0xc]
	mov r2, r8
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r7, #0
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4, #4]
	ldrh r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0x30
	ble _081FBA4C
	adds r0, r6, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4]
_081FBA4C:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081FBA62
	ldr r0, [r4]
	ands r0, r6
	ldr r1, _081FBACC @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4]
_081FBA62:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0x30
	ble _081FBA74
	ldr r0, [r4, #4]
	ands r0, r6
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4, #4]
_081FBA74:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bge _081FBA86
	ldr r0, [r4, #4]
	ands r0, r6
	ldr r1, _081FBACC @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4, #4]
_081FBA86:
	movs r0, #0xfe
	lsls r0, r0, #3
	add r0, sb
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	mov r0, r8
	mov r1, sl
	adds r2, r7, #0
	bl FUN_081ea524
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_081FBAAC:
	ldr r0, [r5, #8]
	cmp r0, #3
	bls _081FBAF8
	adds r0, r5, #0
	movs r1, #4
	bl NestedState_Set0
	b _081FBAF8
	.align 2, 0
_081FBABC: .4byte 0x030046A4
_081FBAC0: .4byte 0x03002BE0
_081FBAC4: .4byte 0x00000237
_081FBAC8: .4byte 0xFFFF0000
_081FBACC: .4byte 0x0000FFD0
_081FBAD0:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0x14
	bls _081FBAF8
	adds r0, r5, #0
	movs r1, #5
	bl NestedState_Set0
	b _081FBAF8
_081FBAE4:
	adds r0, r5, #0
	movs r1, #6
	bl NestedState_Set0
	b _081FBAF8
_081FBAEE:
	movs r1, #0xfb
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strh r0, [r1]
_081FBAF8:
	add sp, #0xb4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
