	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r7, #0
	movs r2, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	ands r2, r0
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	cmp r2, #0
	beq _08220E50
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #8
	movs r1, #0xa
	bl Div
	cmp r0, #0
	blt _08220E22
	asrs r2, r0, #8
	b _08220E28
_08220E22:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_08220E28:
	movs r3, #0xfc
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	str r1, [sp]
	str r1, [sp, #4]
	adds r0, r7, #0
	movs r1, #5
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0
	bl FUN_082318ac
_08220E50:
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #1
	ble _08220E6A
	b _08220F76
_08220E6A:
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r4, r7, r3
	ldr r0, [r4]
	movs r1, #6
	bl Div
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, [r4]
	cmp r0, r1
	bne _08220F34
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r7, r4
	add r4, sp, #0x10
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r6, _08220F90 @ =0x0203B400
	ldr r0, _08220F94 @ =0x030046B8
	mov r8, r0
	ldr r3, [r0]
	adds r3, #1
	ldr r5, _08220F98 @ =0x000003FF
	ands r3, r5
	lsls r0, r3, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	adds r0, r4, #0
	ldrh r0, [r0]
	subs r0, #0x40
	movs r2, #0x80
	ands r1, r2
	adds r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	adds r3, #1
	ands r3, r5
	lsls r0, r3, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ands r1, r2
	adds r0, r0, r1
	strh r0, [r4, #2]
	adds r3, #1
	ands r3, r5
	lsls r0, r3, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	ldrh r0, [r4, #4]
	subs r0, #0x40
	ands r1, r2
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldr r4, _08220F9C @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _08220FA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r4
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r2, #4]
	adds r3, #1
	ands r3, r5
	mov r1, r8
	str r3, [r1]
	lsls r3, r3, #1
	adds r3, r3, r6
	ldrh r1, [r3]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldr r0, _08220FA4 @ =0x00000339
	bl PlaySound_082406e0
_08220F34:
	ldr r2, _08220F90 @ =0x0203B400
	mov r8, r2
	ldr r6, _08220F94 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r4, _08220F98 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r3, r7, r0
	ldrh r0, [r3]
	subs r0, #0x18
	movs r5, #0x30
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #0x18
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08220F76:
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r5, [r0]
	cmp r5, #2
	beq _08221024
	cmp r5, #2
	bgt _08220FA8
	cmp r5, #0
	beq _08220FB4
	cmp r5, #1
	beq _08220FF4
	b _082210E4
	.align 2, 0
_08220F90: .4byte 0x0203B400
_08220F94: .4byte 0x030046B8
_08220F98: .4byte 0x000003FF
_08220F9C: .4byte 0xFFFF0000
_08220FA0: .4byte 0x0000FFFF
_08220FA4: .4byte 0x00000339
_08220FA8:
	cmp r5, #3
	beq _082210A0
	cmp r5, #0x63
	bne _08220FB2
	b _082210D0
_08220FB2:
	b _082210E4
_08220FB4:
	movs r3, #2
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08220FF0 @ =0x000002D9
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08220FD6
	b _082210E4
_08220FD6:
	movs r1, #1
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	str r1, [r0]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	str r5, [r0]
	ldr r0, [r2]
	orrs r0, r3
	b _082210E2
	.align 2, 0
_08220FF0: .4byte 0x000002D9
_08220FF4:
	movs r3, #2
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0x5a
	ble _082210E4
	adds r4, #0x14
	adds r0, r7, r4
	str r3, [r0]
	adds r1, r7, r1
	movs r0, #0
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r3
	b _082210E2
_08221024:
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r6, r7, r0
	ldr r0, [r6]
	adds r2, r0, #0
	ands r2, r5
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	cmp r2, #0
	beq _08221046
	movs r2, #0xfd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x3c
	str r0, [r1]
_08221046:
	movs r3, #0xfd
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r2, [r0]
	cmp r2, #0
	ble _08221062
	subs r2, #1
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #2
	movs r3, #0x3c
	bl FUN_0821c2a0
	b _082210E4
_08221062:
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0822109C @ =0x00000809
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0
	bl FUN_082318ac
	movs r1, #3
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	ldr r0, [r6]
	orrs r0, r5
	str r0, [r6]
	b _082210E4
	.align 2, 0
_0822109C: .4byte 0x00000809
_082210A0:
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0x3c
	ble _082210E4
	movs r1, #0x63
	adds r3, #0x14
	adds r0, r7, r3
	str r1, [r0]
	adds r1, r7, r4
	movs r0, #0
	str r0, [r1]
	ldr r0, [r2]
	movs r1, #2
	b _082210E0
_082210D0:
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x10
_082210E0:
	orrs r0, r1
_082210E2:
	str r0, [r2]
_082210E4:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
