	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0
	str r0, [sp]
	movs r1, #0x1f
	mov sb, r1
	ldr r2, _082230A0 @ =0x00000F08
	adds r2, r5, r2
	str r2, [sp, #4]
	ldr r4, _082230A4 @ =0x00000F0A
	adds r4, r4, r5
	mov sl, r4
_08222F2E:
	ldr r0, [sp]
	lsls r0, r0, #1
	mov r8, r0
	ldr r1, _082230A8 @ =0x00000EC4
	adds r0, r5, r1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sb
	ands r0, r1
	ldr r2, _082230AC @ =0xFFFFFF00
	ands r6, r2
	orrs r6, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #8
	ldr r2, _082230B0 @ =0xFFFF00FF
	ands r6, r2
	orrs r6, r0
	lsrs r1, r1, #0x1a
	ands r1, r4
	lsls r1, r1, #0x10
	ldr r4, _082230B4 @ =0xFF00FFFF
	ands r6, r4
	orrs r6, r1
	ldr r1, _082230B8 @ =0x00000EA4
	adds r0, r5, r1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sb
	ands r0, r1
	ldr r2, _082230AC @ =0xFFFFFF00
	ands r7, r2
	orrs r7, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #8
	ldr r2, _082230B0 @ =0xFFFF00FF
	ands r7, r2
	orrs r7, r0
	lsrs r1, r1, #0x1a
	ands r1, r4
	lsls r1, r1, #0x10
	ldr r4, _082230B4 @ =0xFF00FFFF
	ands r7, r4
	orrs r7, r1
	lsls r1, r7, #0x18
	asrs r1, r1, #0x18
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	ldr r2, [sp, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	muls r0, r1, r0
	mov r2, sl
	ldrh r1, [r2]
	str r3, [sp, #8]
	bl Div
	adds r0, r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp, #8]
	ldr r4, _082230AC @ =0xFFFFFF00
	ands r3, r4
	orrs r3, r0
	lsls r1, r7, #0x10
	asrs r1, r1, #0x18
	lsls r4, r6, #0x10
	asrs r4, r4, #0x18
	subs r1, r1, r4
	mov ip, r1
	ldr r1, [sp, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sl
	ldrh r1, [r2]
	str r3, [sp, #8]
	bl Div
	adds r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x10
	ldr r3, [sp, #8]
	ldr r0, _082230B0 @ =0xFFFF00FF
	ands r3, r0
	orrs r3, r4
	lsls r1, r7, #8
	asrs r1, r1, #0x18
	lsls r4, r6, #8
	asrs r4, r4, #0x18
	subs r1, r1, r4
	mov ip, r1
	ldr r1, [sp, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sl
	ldrh r1, [r2]
	str r3, [sp, #8]
	bl Div
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #8
	ldr r3, [sp, #8]
	ldr r4, _082230B4 @ =0xFF00FFFF
	ands r3, r4
	orrs r3, r0
	ldr r0, _082230BC @ =0x00000EE4
	adds r2, r5, r0
	add r2, r8
	lsls r1, r3, #8
	asrs r1, r1, #0x18
	lsls r1, r1, #0xa
	lsls r0, r3, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	bgt _08223042
	b _08222F2E
_08223042:
	ldr r2, _082230A0 @ =0x00000F08
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r1, #1
	movs r4, #0
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	ble _08223090
	ldr r1, _082230C0 @ =0x00000F48
	adds r0, r5, r1
	str r4, [r0]
	ldr r2, _082230C4 @ =0x00000DC8
	adds r0, r5, r2
	movs r1, #0x8c
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _082230C8 @ =0x00000DD4
	adds r1, r5, r0
	ldr r2, _082230CC @ =0x00000F04
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08223090
	str r4, [r0]
	adds r0, r1, #0
	movs r1, #0
	bl FUN_082318ac
_08223090:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082230A0: .4byte 0x00000F08
_082230A4: .4byte 0x00000F0A
_082230A8: .4byte 0x00000EC4
_082230AC: .4byte 0xFFFFFF00
_082230B0: .4byte 0xFFFF00FF
_082230B4: .4byte 0xFF00FFFF
_082230B8: .4byte 0x00000EA4
_082230BC: .4byte 0x00000EE4
_082230C0: .4byte 0x00000F48
_082230C4: .4byte 0x00000DC8
_082230C8: .4byte 0x00000DD4
_082230CC: .4byte 0x00000F04
