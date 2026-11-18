	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r5, r1, #0
	adds r7, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	adds r0, r3, #0
	movs r1, #2
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	beq _0819F6B8
	b _0819F884
_0819F6B8:
	ldr r2, _0819F708 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _0819F70C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [r4, #4]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	add r5, sp, #0x1c
	str r3, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0819F710 @ =0x05000002
	bl CpuSet
	ldr r2, _0819F714 @ =0x00000ECE
	adds r0, r6, r2
	ldrb r0, [r0]
	mov r8, r4
	adds r4, r5, #0
	cmp r0, #4
	bhi _0819F7A0
	lsls r0, r0, #2
	ldr r1, _0819F718 @ =_0819F71C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0819F708: .4byte 0xFFFF0000
_0819F70C: .4byte 0x0000FFFF
_0819F710: .4byte 0x05000002
_0819F714: .4byte 0x00000ECE
_0819F718: .4byte _0819F71C
_0819F71C: @ jump table
	.4byte _0819F730 @ case 0
	.4byte _0819F748 @ case 1
	.4byte _0819F760 @ case 2
	.4byte _0819F778 @ case 3
	.4byte _0819F790 @ case 4
_0819F730:
	ldr r1, _0819F740 @ =0x0000FF88
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r3, _0819F744 @ =0x00000ECE
	adds r1, r6, r3
	b _0819F784
	.align 2, 0
_0819F740: .4byte 0x0000FF88
_0819F744: .4byte 0x00000ECE
_0819F748:
	ldr r1, _0819F758 @ =0x0000FFB5
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r5, _0819F75C @ =0x00000ECE
	adds r1, r6, r5
	b _0819F784
	.align 2, 0
_0819F758: .4byte 0x0000FFB5
_0819F75C: .4byte 0x00000ECE
_0819F760:
	ldr r1, _0819F770 @ =0x0000FFE2
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r0, _0819F774 @ =0x00000ECE
	adds r1, r6, r0
	b _0819F784
	.align 2, 0
_0819F770: .4byte 0x0000FFE2
_0819F774: .4byte 0x00000ECE
_0819F778:
	movs r1, #0xf
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r2, _0819F78C @ =0x00000ECE
	adds r1, r6, r2
_0819F784:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0819F7A0
	.align 2, 0
_0819F78C: .4byte 0x00000ECE
_0819F790:
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r3, _0819F7C4 @ =0x00000ECE
	adds r0, r6, r3
	strb r2, [r0]
_0819F7A0:
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldr r1, _0819F7C8 @ =gSineTable
	adds r2, r7, #0
	adds r2, #0x40
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r6, r1, #0
	mov ip, r2
	cmp r0, #0
	blt _0819F7CC
	asrs r0, r0, #0xc
	b _0819F7D2
	.align 2, 0
_0819F7C4: .4byte 0x00000ECE
_0819F7C8: .4byte gSineTable
_0819F7CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F7D2:
	adds r2, r0, #0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r6
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819F7EE
	asrs r0, r0, #0xc
	b _0819F7F4
_0819F7EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F7F4:
	add r3, sp, #0x24
	adds r1, r2, r0
	ldrh r5, [r3]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F828 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819F82C
	asrs r0, r0, #0xc
	b _0819F830
	.align 2, 0
_0819F828: .4byte 0xFFFF0000
_0819F82C:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819F830:
	adds r5, r0, #0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xff
	mov r2, ip
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819F84E
	asrs r0, r0, #0xc
	b _0819F854
_0819F84E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F854:
	adds r1, r5, r0
	ldrh r5, [r3, #4]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F890 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	mov r2, r8
	movs r3, #0
	bl EmitSmoke
_0819F884:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F890: .4byte 0xFFFF0000
