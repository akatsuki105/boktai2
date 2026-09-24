	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	cmp r1, #0
	bne _08202514
	ldr r0, _0820253C @ =0x00000692
	add r0, sb
	strb r1, [r0]
	ldr r0, _08202540 @ =0x00000693
	add r0, sb
	strb r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	add r0, sb
	strb r1, [r0]
	ldr r0, _08202544 @ =0x00000691
	add r0, sb
	strb r1, [r0]
_08202514:
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0xd2
	lsls r0, r0, #3
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #1
	beq _082025FC
	cmp r0, #1
	bgt _08202548
	cmp r0, #0
	beq _0820255C
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r1, sp
	adds r1, #8
	str r1, [sp, #0x18]
	b _08202780
	.align 2, 0
_0820253C: .4byte 0x00000692
_08202540: .4byte 0x00000693
_08202544: .4byte 0x00000691
_08202548:
	cmp r0, #3
	bne _0820254E
	b _0820276C
_0820254E:
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r2, sp
	adds r2, #8
	str r2, [sp, #0x18]
	b _08202780
_0820255C:
	ldr r0, _082025F0 @ =0x00000692
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202576
	ldr r0, _082025F4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _082025F8 @ =0x000006E4
	add r2, sb
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_08202576:
	mov r1, sb
	adds r1, #0x46
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	movs r3, #0
	mov sl, r3
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r0, sp
	adds r0, #8
	str r0, [sp, #0x18]
	movs r4, #0xdd
	lsls r4, r4, #3
	add r4, sb
	mov r3, sb
	adds r3, #0x48
	movs r5, #7
_0820259C:
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	movs r2, #1
	rsbs r2, r2, #0
	cmp r1, #0
	ble _082025B0
	movs r2, #1
_082025B0:
	lsls r0, r2, #2
	adds r0, r0, r2
	mov r2, sl
	subs r1, r5, r2
	muls r0, r1, r0
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r3, #0x2c
	movs r2, #1
	add sl, r2
	mov r0, sl
	cmp r0, #3
	ble _0820259C
	ldr r1, _082025F0 @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bhi _082025E0
	b _08202780
_082025E0:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	b _08202780
	.align 2, 0
_082025F0: .4byte 0x00000692
_082025F4: .4byte 0x03002BE0
_082025F8: .4byte 0x000006E4
_082025FC:
	movs r7, #0
	ldr r0, _082026E0 @ =0x000006E4
	add r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r0, _082026E4 @ =0x00000694
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r2, r0
	movs r0, #0xdd
	lsls r0, r0, #3
	add r0, sb
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	mov r4, sp
	mov r0, sp
	strh r2, [r0]
	ldrh r0, [r0, #0x10]
	strh r0, [r4, #2]
	strh r1, [r4, #4]
	movs r6, #0x96
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08202686
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	mov r1, sp
	strh r0, [r1]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08202686:
	movs r3, #0
	mov sl, r3
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r0, sp
	adds r0, #8
	str r0, [sp, #0x18]
_08202696:
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	add r1, sb
	adds r2, r1, #0
	adds r2, #0x44
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #0x48
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _082026DC
	cmp r1, #0
	blt _082026DC
	ldr r0, _082026E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082026DC
	ldr r0, _082026EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082026F0
_082026DC:
	movs r4, #0
	b _082026FE
	.align 2, 0
_082026E0: .4byte 0x000006E4
_082026E4: .4byte 0x00000694
_082026E8: .4byte 0x030046A8
_082026EC: .4byte 0x030046AC
_082026F0:
	ldr r0, _08202710 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_082026FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08202714
	adds r0, #4
	b _08202720
	.align 2, 0
_08202710: .4byte 0x030046A4
_08202714:
	ldr r0, _08202768 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08202720:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	mov r3, sb
	adds r1, r3, r0
	adds r0, r1, #0
	adds r0, #0x46
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r2
	bgt _08202748
	adds r0, r1, #0
	adds r0, #0x28
	strh r2, [r0, #0x1e]
	adds r7, #1
_08202748:
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _08202696
	cmp r7, #6
	ble _08202780
	movs r2, #1
	str r2, [sp, #0x10]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #2
	strb r0, [r1]
	b _08202780
	.align 2, 0
_08202768: .4byte 0x030046A4
_0820276C:
	ldr r1, _08202870 @ =0x000006D9
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r3, sp
	adds r3, #8
	str r3, [sp, #0x18]
_08202780:
	movs r0, #0
	mov sl, r0
	ldr r5, [sp, #0x18]
	mov r1, sp
	adds r1, #8
	str r1, [sp, #0x14]
	adds r6, #0x1c
	mov r8, r6
	movs r7, #0xbc
	lsls r7, r7, #1
	add r7, sb
_08202796:
	mov r2, r8
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r3, [sp, #0x14]
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r1, _08202874 @ =0x085AE7C8
	movs r0, #7
	mov r2, sl
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _08202842
	ldr r0, _08202878 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08202826
	ldr r3, [sp, #0x18]
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r2, [sp, #0x14]
	strh r0, [r2]
	movs r3, #2
	ldrsh r0, [r5, r3]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_08202826:
	ldr r2, [sp, #0x18]
	ldrh r0, [r2]
	ldrh r3, [r7]
	adds r0, r0, r3
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
_08202842:
	subs r7, #0x2c
	movs r0, #0x2c
	rsbs r0, r0, #0
	add r8, r0
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #6
	ble _08202796
	ldr r3, [sp, #0x10]
	cmp r3, #1
	bne _08202860
	mov r0, sb
	bl FUN_08200b5c
_08202860:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202870: .4byte 0x000006D9
_08202874: .4byte 0x085AE7C8
_08202878: .4byte 0x085AE7B8
