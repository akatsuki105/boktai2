	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xac
	lsls r1, r1, #1
	adds r1, r1, r6
	mov r8, r1
	ldr r2, [r1]
	ands r0, r2
	movs r1, #2
	rsbs r1, r1, #0
	ands r1, r2
	mov r2, r8
	str r1, [r2]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r7, [r0]
	cmp r7, #1
	bne _0821A336
	b _0821A4F2
_0821A336:
	cmp r7, #1
	bgt _0821A340
	cmp r7, #0
	beq _0821A34E
	b _0821A5C8
_0821A340:
	cmp r7, #2
	bne _0821A346
	b _0821A532
_0821A346:
	cmp r7, #3
	bne _0821A34C
	b _0821A59C
_0821A34C:
	b _0821A5C8
_0821A34E:
	movs r2, #2
	ands r2, r1
	cmp r2, #0
	beq _0821A358
	movs r2, #1
_0821A358:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	mov r0, r8
	str r1, [r0]
	cmp r2, #0
	beq _0821A3AA
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	str r7, [r0]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0xe0
	lsls r0, r0, #7
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r6, r1
	str r7, [r0]
	adds r2, #0x14
	adds r1, r6, r2
	movs r0, #0xf
	str r0, [r1]
	movs r0, #0x8d
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x80
	strh r0, [r1]
	ldr r0, _0821A3C8 @ =0x03004040
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _0821A3CC @ =0x0300445C
	str r1, [r0]
	ldr r0, _0821A3D0 @ =0x03004494
	ldr r2, _0821A3D4 @ =0x00007FFF
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, _0821A3D8 @ =0x03004464
	strh r1, [r0]
_0821A3AA:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0x28
	ble _0821A3DC
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, [r1]
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r0, r0, r2
	b _0821A3FA
	.align 2, 0
_0821A3C8: .4byte 0x03004040
_0821A3CC: .4byte 0x0300445C
_0821A3D0: .4byte 0x03004494
_0821A3D4: .4byte 0x00007FFF
_0821A3D8: .4byte 0x03004464
_0821A3DC:
	cmp r0, #0x1e
	ble _0821A3F0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	b _0821A3FA
_0821A3F0:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #0x40
_0821A3FA:
	str r0, [r1]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	adds r1, #4
	adds r0, r6, r1
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #0xba
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #0xb4
	lsls r1, r1, #0xf
	cmp r0, r1
	ble _0821A424
	str r1, [r2]
_0821A424:
	movs r1, #2
	ldrsh r4, [r2, r1]
	lsls r0, r4, #6
	subs r0, r0, r4
	movs r1, #0x5a
	bl Div
	adds r0, #0x40
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r5, r6, r2
	strb r0, [r5]
	lsls r0, r4, #2
	adds r0, r0, r4
	movs r1, #0x5a
	bl Div
	adds r0, #0x40
	ldr r2, _0821A4C8 @ =0x00000171
	adds r1, r6, r2
	strb r0, [r1]
	lsls r4, r4, #1
	adds r0, r4, #0
	movs r1, #0x5a
	bl Div
	adds r0, #0x80
	movs r2, #0x8d
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	ldrb r0, [r5]
	cmp r0, #0x5f
	bls _0821A49E
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r3, _0821A4CC @ =0x0000FFFF
	movs r1, #1
	movs r2, #0xf
	bl FUN_0821b21c
	cmp r0, #0
	beq _0821A49E
	movs r1, #1
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	str r0, [r1]
	movs r2, #2
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0821A49E:
	ldr r1, [r6, #0x40]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0821A4D0
	subs r2, #3
	ands r1, r2
	str r1, [r6, #0x40]
	adds r1, r6, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	b _0821A4E8
	.align 2, 0
_0821A4C8: .4byte 0x00000171
_0821A4CC: .4byte 0x0000FFFF
_0821A4D0:
	orrs r1, r2
	str r1, [r6, #0x40]
	adds r1, r6, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
_0821A4E8:
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_0821a2bc
	b _0821A5C8
_0821A4F2:
	movs r3, #2
	adds r0, r1, #0
	ands r0, r3
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	mov r2, r8
	str r1, [r2]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blt _0821A5C8
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	b _0821A5C8
_0821A532:
	adds r0, r1, #0
	ands r0, r7
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	mov r2, r8
	str r1, [r2]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r4, r6, r1
	ldr r1, [r5]
	ldr r2, [r4]
	subs r2, r1, r2
	lsls r0, r2, #5
	subs r0, r0, r2
	bl Div
	movs r1, #0x1f
	ands r0, r1
	ldr r3, _0821A594 @ =0x03004494
	lsls r1, r0, #0xa
	lsls r2, r0, #5
	orrs r1, r2
	orrs r1, r0
	strh r1, [r3]
	ldr r0, _0821A598 @ =0x03004464
	strh r1, [r0]
	ldr r1, [r4]
	ldr r0, [r5]
	cmp r1, r0
	blt _0821A5C8
	movs r1, #3
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	b _0821A5C8
	.align 2, 0
_0821A594: .4byte 0x03004494
_0821A598: .4byte 0x03004464
_0821A59C:
	movs r2, #2
	ands r2, r1
	cmp r2, #0
	beq _0821A5A6
	movs r2, #1
_0821A5A6:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	mov r0, r8
	str r1, [r0]
	cmp r2, #0
	beq _0821A5C2
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0
	bl FUN_082318ac
_0821A5C2:
	adds r0, r6, #0
	bl KillEntity
_0821A5C8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
