	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0xf
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r7, r1
	ldr r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080F62D6
	movs r0, #0xc0
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	bne _080F62DA
_080F62D6:
	movs r0, #0
	b _080F64B6
_080F62DA:
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r1, r0
	str r1, [r3]
	ldr r2, _080F63B8 @ =0x00000482
	adds r1, r7, r2
	movs r5, #0
	movs r4, #0
	mov r8, r4
	movs r4, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp]
	bl FUN_080ef86c
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080F63BC @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080F63C0 @ =0x0000046A
	adds r0, r7, r2
	strb r5, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r4, [r0]
	ldr r2, _080F63C4 @ =FUN_080e6794
	movs r1, #0xe
	subs r6, #0x17
	adds r0, r7, r6
	strb r4, [r0]
	ldr r4, _080F63C8 @ =0x0000046B
	adds r0, r7, r4
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r4, r8
	strh r4, [r0]
	movs r1, #0x10
	ldr r3, [sp]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r6, #0x51
	adds r0, r7, r6
	ldr r3, [r0]
	movs r4, #9
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r6, #0x50
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080F63CC @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F63B4
	cmp r1, #0
	blt _080F63B4
	ldr r0, _080F63D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F63B4
	ldr r0, _080F63D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F63D8
_080F63B4:
	movs r4, #0
	b _080F63E6
	.align 2, 0
_080F63B8: .4byte 0x00000482
_080F63BC: .4byte 0x00000469
_080F63C0: .4byte 0x0000046A
_080F63C4: .4byte FUN_080e6794
_080F63C8: .4byte 0x0000046B
_080F63CC: .4byte 0x00000551
_080F63D0: .4byte 0x030046A8
_080F63D4: .4byte 0x030046AC
_080F63D8:
	ldr r0, _080F63F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080F63E6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F63FC
	adds r0, #4
	b _080F6408
	.align 2, 0
_080F63F8: .4byte 0x030046A4
_080F63FC:
	ldr r0, _080F641C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F6408:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F6420
	cmp r2, #2
	beq _080F6424
	b _080F6428
	.align 2, 0
_080F641C: .4byte 0x030046A4
_080F6420:
	ldrb r0, [r5, #4]
	b _080F6426
_080F6424:
	ldrb r0, [r5]
_080F6426:
	subs r1, r1, r0
_080F6428:
	movs r4, #0
	strh r1, [r5, #2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #1
	strh r1, [r0, #6]
	ldr r6, _080F64C4 @ =0x00000482
	adds r0, r7, r6
	strh r1, [r0]
	ldr r1, _080F64C8 @ =0x00000222
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080F64CC @ =0x0000024E
	adds r0, r7, r2
	strh r4, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r3, r7, r6
	ldr r0, _080F64D0 @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080F64D4 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080F649C
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _080F64D8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080F64DC @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	adds r6, #0x9e
	adds r0, r7, r6
	strh r4, [r0]
	ldr r1, _080F64E0 @ =0x00000202
	adds r0, r7, r1
	strh r4, [r0]
_080F649C:
	ldr r0, _080F64E4 @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r2, _080F64E8 @ =0x00000542
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _080F64EC @ =0xFFFFEFFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #1
_080F64B6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F64C4: .4byte 0x00000482
_080F64C8: .4byte 0x00000222
_080F64CC: .4byte 0x0000024E
_080F64D0: .4byte 0xFFFFFC7F
_080F64D4: .4byte 0xF3FFFFFF
_080F64D8: .4byte 0xFEFFFFFF
_080F64DC: .4byte 0xFFFFFDFF
_080F64E0: .4byte 0x00000202
_080F64E4: .4byte 0xFFFFFBFF
_080F64E8: .4byte 0x00000542
_080F64EC: .4byte 0xFFFFEFFF
