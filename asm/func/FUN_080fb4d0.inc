	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	mov r1, sb
	ldr r0, [r1, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r1, _080FB504 @ =0x0000046D
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FB508
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FB50A
	.align 2, 0
_080FB504: .4byte 0x0000046D
_080FB508:
	movs r0, #0
_080FB50A:
	cmp r0, #0
	beq _080FB5C2
	movs r0, #0xfe
	lsls r0, r0, #1
	add r0, sb
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sb
	strb r0, [r2, #5]
	mov r0, sb
	movs r1, #5
	bl FUN_080ef86c
	movs r2, #4
	ldr r1, _080FB540 @ =0x0000065C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080FB544
	movs r0, #1
	b _080FB546
	.align 2, 0
_080FB540: .4byte 0x0000065C
_080FB544:
	movs r0, #0
_080FB546:
	cmp r0, #0
	beq _080FB55A
	movs r1, #0
	movs r0, #2
	strh r0, [r4, #8]
	strh r1, [r4, #0xe]
	subs r0, #7
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080FB55A:
	ldr r0, _080FB56C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FB570
	movs r0, #1
	b _080FB572
	.align 2, 0
_080FB56C: .4byte 0x030047A4
_080FB570:
	movs r0, #0
_080FB572:
	cmp r0, #0
	beq _080FB5AC
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	cmp r1, #0
	beq _080FB5C2
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _080FB58E
	adds r3, r0, #0
_080FB58E:
	cmp r3, #0
	blt _080FB5C2
	movs r2, #0xcc
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _080FB5A8 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	b _080FB5BE
	.align 2, 0
_080FB5A8: .4byte 0x03002BE0
_080FB5AC:
	movs r2, #0xcc
	lsls r2, r2, #3
	add r2, sl
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
_080FB5BE:
	str r0, [r2]
	str r1, [r2, #4]
_080FB5C2:
	ldrh r0, [r4, #8]
	cmp r0, #5
	beq _080FB5CA
	b _080FB9E4
_080FB5CA:
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq _080FB5D2
	b _080FB9E4
_080FB5D2:
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	adds r1, #0xfd
	add r1, sb
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _080FB5F8
	ldr r2, _080FB5F4 @ =0xFFFFFF00
	adds r1, r1, r2
	b _080FB606
	.align 2, 0
_080FB5F4: .4byte 0xFFFFFF00
_080FB5F8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080FB606
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_080FB606:
	adds r0, r1, #0
	cmp r1, #0
	bge _080FB60E
	rsbs r0, r1, #0
_080FB60E:
	cmp r0, #0x1f
	bgt _080FB684
	ldr r0, _080FB624 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FB628
	movs r0, #1
	b _080FB62A
	.align 2, 0
_080FB624: .4byte 0x030047A4
_080FB628:
	movs r0, #0
_080FB62A:
	cmp r0, #0
	beq _080FB66C
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	cmp r1, #0
	bne _080FB63C
	b _080FB98A
_080FB63C:
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _080FB648
	adds r3, r0, #0
_080FB648:
	cmp r3, #0
	bge _080FB64E
	b _080FB98A
_080FB64E:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _080FB668 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	b _080FB98A
	.align 2, 0
_080FB668: .4byte 0x03002BE0
_080FB66C:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, sl
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	b _080FB98A
_080FB684:
	ldr r4, _080FB6A0 @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	mov r5, sb
	adds r5, #8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FB6A4
	adds r0, #4
	b _080FB6B0
	.align 2, 0
_080FB6A0: .4byte 0x00000256
_080FB6A4:
	ldr r0, _080FB6C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FB6B0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080FB6C8
	cmp r3, #2
	beq _080FB6CC
	b _080FB6D0
	.align 2, 0
_080FB6C4: .4byte 0x030046A4
_080FB6C8:
	ldrb r0, [r5, #4]
	b _080FB6CE
_080FB6CC:
	ldrb r0, [r5]
_080FB6CE:
	subs r2, r2, r0
_080FB6D0:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FB6E2
	adds r0, #4
	b _080FB6EE
_080FB6E2:
	ldr r0, _080FB700 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FB6EE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _080FB704
	asrs r0, r0, #6
	b _080FB70A
	.align 2, 0
_080FB700: .4byte 0x030046A4
_080FB704:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080FB70A:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _080FB748
	cmp r1, #1
	bgt _080FB71C
	cmp r1, #0
	beq _080FB726
	b _080FB808
_080FB71C:
	cmp r1, #2
	beq _080FB784
	cmp r1, #3
	beq _080FB7A6
	b _080FB808
_080FB726:
	adds r4, r6, #1
	movs r5, #0
_080FB72A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FB744
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _080FB72A
_080FB744:
	subs r5, r4, #1
	b _080FB80A
_080FB748:
	ldr r1, _080FB780 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_080FB756:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FB7E0
	ldr r0, _080FB780 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _080FB756
	subs r5, r4, r0
	b _080FB80A
	.align 2, 0
_080FB780: .4byte 0x030046A4
_080FB784:
	subs r4, r6, #1
	movs r5, #0
_080FB788:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FB7A2
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _080FB788
_080FB7A2:
	adds r5, r4, #1
	b _080FB80A
_080FB7A6:
	ldr r1, _080FB7DC @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
_080FB7B4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FB7F4
	ldr r0, _080FB7DC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _080FB7B4
	adds r5, r4, r0
	b _080FB80A
	.align 2, 0
_080FB7DC: .4byte 0x030046A4
_080FB7E0:
	ldr r1, _080FB7F0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _080FB80A
	.align 2, 0
_080FB7F0: .4byte 0x030046A4
_080FB7F4:
	ldr r1, _080FB804 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _080FB80A
	.align 2, 0
_080FB804: .4byte 0x030046A4
_080FB808:
	ldrh r5, [r4]
_080FB80A:
	movs r6, #0xcd
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _080FB84C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _080FB84C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FB850
	adds r0, #4
	b _080FB85C
	.align 2, 0
_080FB84C: .4byte 0x030046A4
_080FB850:
	ldr r1, _080FB87C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080FB85C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r2, sb
	ldrb r0, [r2, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _080FB880
	asrs r0, r0, #6
	b _080FB886
	.align 2, 0
_080FB87C: .4byte 0x030046A4
_080FB880:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080FB886:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _080FB8AE
	cmp r1, #1
	bgt _080FB898
	cmp r1, #0
	beq _080FB8A2
	b _080FB8FA
_080FB898:
	cmp r1, #2
	beq _080FB8C8
	cmp r1, #3
	beq _080FB8E4
	b _080FB8FA
_080FB8A2:
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0x7f
	b _080FB8D2
_080FB8AE:
	mov r2, sb
	ldrh r1, [r2, #8]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
	ldr r1, _080FB8C4 @ =0x0000066C
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0x7f
	b _080FB8F8
	.align 2, 0
_080FB8C4: .4byte 0x0000066C
_080FB8C8:
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldrh r0, [r1]
	subs r0, #0x7f
_080FB8D2:
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0, #0xc]
	ldr r0, _080FB8E0 @ =0x0000066C
	add r0, sl
	strh r1, [r0]
	b _080FB8FA
	.align 2, 0
_080FB8E0: .4byte 0x0000066C
_080FB8E4:
	mov r2, sb
	ldrh r1, [r2, #8]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
	ldr r1, _080FB928 @ =0x0000066C
	add r1, sl
	ldrh r0, [r1]
	subs r0, #0x7f
_080FB8F8:
	strh r0, [r1]
_080FB8FA:
	movs r5, #0xcd
	lsls r5, r5, #3
	add r5, sl
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FB924
	cmp r1, #0
	blt _080FB924
	ldr r0, _080FB92C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FB924
	ldr r0, _080FB930 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FB934
_080FB924:
	movs r4, #0
	b _080FB942
	.align 2, 0
_080FB928: .4byte 0x0000066C
_080FB92C: .4byte 0x030046A8
_080FB930: .4byte 0x030046AC
_080FB934:
	ldr r0, _080FB954 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FB942:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FB958
	adds r0, #4
	b _080FB964
	.align 2, 0
_080FB954: .4byte 0x030046A4
_080FB958:
	ldr r0, _080FB978 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FB964:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FB97C
	cmp r2, #2
	beq _080FB980
	b _080FB984
	.align 2, 0
_080FB978: .4byte 0x030046A4
_080FB97C:
	ldrb r0, [r5, #4]
	b _080FB982
_080FB980:
	ldrb r0, [r5]
_080FB982:
	subs r1, r1, r0
_080FB984:
	ldr r0, _080FBA08 @ =0x0000066A
	add r0, sl
	strh r1, [r0]
_080FB98A:
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	asrs r1, r2, #0x10
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _080FBA0C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldr r0, _080FBA10 @ =0x00000226
	add r0, sb
	ldrh r2, [r0]
	ldr r0, _080FBA14 @ =0x0000022E
	add r0, sb
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _080FBA18 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r0, _080FBA1C @ =0x00000674
	add r0, sl
	ldrb r0, [r0]
	str r0, [sp, #8]
	movs r0, #0x1e
	str r0, [sp, #0xc]
	subs r0, #0x32
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	bl FUN_081f3110
	movs r0, #0xd6
	bl PlaySound_082406e0
_080FB9E4:
	ldr r0, _080FBA20 @ =0x0000046E
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	beq _080FB9F6
	ldr r1, _080FBA24 @ =0x0000046B
	add r1, sb
	movs r0, #1
	strb r0, [r1]
_080FB9F6:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FBA08: .4byte 0x0000066A
_080FBA0C: .4byte 0x0000FFFF
_080FBA10: .4byte 0x00000226
_080FBA14: .4byte 0x0000022E
_080FBA18: .4byte 0x00000236
_080FBA1C: .4byte 0x00000674
_080FBA20: .4byte 0x0000046E
_080FBA24: .4byte 0x0000046B
