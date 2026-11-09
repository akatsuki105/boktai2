	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _0819291C @ =0x00000553
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _081929B8
	movs r7, #0xa
	ldrsh r1, [r3, r7]
	subs r2, #0xe1
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _08192910
	cmp r0, #0
	bne _08192920
_08192910:
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08192936
	.align 2, 0
_0819291C: .4byte 0x00000553
_08192920:
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _08192938
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08192936:
	str r1, [r0]
_08192938:
	movs r4, #0
	ldr r0, _08192974 @ =0x00000F36
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r4, r0
	bge _081929B8
	movs r7, #1
	mov sl, r7
	ldr r0, _08192978 @ =0x00000472
	adds r0, r0, r3
	mov sb, r0
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r5
	mov r8, r2
	adds r2, r5, #0
	movs r6, #0
	ldr r7, _0819297C @ =0x0000077A
	adds r3, r2, r7
	movs r5, #0x92
	lsls r5, r5, #1
	mov ip, r1
_08192966:
	ldrh r0, [r3]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08192980
	movs r0, #1
	b _08192982
	.align 2, 0
_08192974: .4byte 0x00000F36
_08192978: .4byte 0x00000472
_0819297C: .4byte 0x0000077A
_08192980:
	movs r0, #0
_08192982:
	cmp r0, #0
	bne _081929A6
	ldr r7, _081929C8 @ =0x00000676
	adds r0, r2, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r7, sb
	ldrh r1, [r7]
	cmp r0, r1
	blt _0819299A
	cmp r1, #0
	bne _081929A6
_0819299A:
	mov r0, r8
	adds r1, r0, r6
	ldr r0, [r1]
	mov r7, sl
	orrs r0, r7
	str r0, [r1]
_081929A6:
	adds r2, r2, r5
	adds r6, r6, r5
	adds r3, r3, r5
	adds r4, #1
	mov r1, ip
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	blt _08192966
_081929B8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081929C8: .4byte 0x00000676
