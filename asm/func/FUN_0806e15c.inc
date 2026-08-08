	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	movs r7, #1
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806E1A8
	ldr r0, _0806E1D8 @ =0x0000026A
	bl PlaySound_082406e0
	ldr r2, _0806E1DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806E1E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806E1E4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	movs r1, #0xe2
	lsls r1, r1, #2
	add r1, r8
	strh r0, [r1]
	mov r0, r8
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
	movs r7, #0
_0806E1A8:
	movs r4, #0xe2
	lsls r4, r4, #2
	add r4, r8
	ldrh r0, [r4]
	cmp r0, #0
	bne _0806E1E8
	ldr r0, _0806E1D8 @ =0x0000026A
	bl PlaySound_082406e0
	ldr r2, _0806E1DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806E1E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0806E1E4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0806E1EA
	.align 2, 0
_0806E1D8: .4byte 0x0000026A
_0806E1DC: .4byte 0x030046B8
_0806E1E0: .4byte 0x000003FF
_0806E1E4: .4byte 0x0203B400
_0806E1E8:
	subs r0, #1
_0806E1EA:
	strh r0, [r4]
	mov r0, r8
	bl FUN_08067068
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	strb r0, [r1]
	mov r0, r8
	bl FUN_080609dc
	mov r0, r8
	movs r1, #6
	bl FUN_08060aa4
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, r8
	movs r0, #0xd5
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	ldr r0, _0806E25C @ =0x000002E6
	add r0, r8
	ldrb r3, [r0]
	ldr r0, _0806E260 @ =0x000002E7
	add r0, r8
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08236fac
	mov r5, r8
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E264
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E26C
	.align 2, 0
_0806E25C: .4byte 0x000002E6
_0806E260: .4byte 0x000002E7
_0806E264:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E26C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E290
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E298
_0806E290:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E298:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E2D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806E308
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E2D4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E2C8
	ldrb r0, [r4, #5]
_0806E2C8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E2E4
	.align 2, 0
_0806E2D0: .4byte 0x0000FFFF
_0806E2D4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806E2E4
	strh r1, [r4, #8]
_0806E2E4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E308
	movs r0, #1
	strb r0, [r4, #7]
_0806E308:
	cmp r7, #0
	beq _0806E3F6
	movs r7, #0xd1
	lsls r7, r7, #2
	add r7, r8
	ldrh r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806E3F6
	ldr r0, _0806E344 @ =0x0000034A
	add r0, r8
	ldrh r5, [r0]
	cmp r5, #0
	bne _0806E3F6
	mov r4, r8
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	adds r6, r0, #0
	cmp r6, #0
	beq _0806E35C
	ldrh r1, [r7]
	cmp r1, #0
	bne _0806E34C
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0806E348 @ =0x00000163
	b _0806E386
	.align 2, 0
_0806E344: .4byte 0x0000034A
_0806E348: .4byte 0x00000163
_0806E34C:
	cmp r1, #2
	bne _0806E3F6
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0806E358 @ =0x00000163
	b _0806E386
	.align 2, 0
_0806E358: .4byte 0x00000163
_0806E35C:
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	bl FUN_08065a98
	cmp r0, #0
	beq _0806E39C
	ldrh r1, [r7]
	cmp r1, #0
	bne _0806E37C
	str r4, [sp]
	str r6, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _0806E386
_0806E37C:
	cmp r1, #2
	bne _0806E3F6
	str r4, [sp]
	str r6, [sp, #4]
	ldr r0, _0806E398 @ =0x00000193
_0806E386:
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _0806E3F6
	.align 2, 0
_0806E398: .4byte 0x00000193
_0806E39C:
	ldrh r1, [r7]
	cmp r1, #0
	bne _0806E3B0
	ldr r0, _0806E3AC @ =0x00000269
	bl PlaySound_082406e0
	b _0806E3BC
	.align 2, 0
_0806E3AC: .4byte 0x00000269
_0806E3B0:
	cmp r1, #2
	bne _0806E3BC
	movs r0, #0x9a
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806E3BC:
	movs r1, #1
	ldr r0, _0806E3D4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0806E3D8 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806E3DC
	movs r0, #1
	b _0806E3DE
	.align 2, 0
_0806E3D4: .4byte 0x030046A0
_0806E3D8: .4byte 0x00000934
_0806E3DC:
	movs r0, #0
_0806E3DE:
	cmp r0, #0
	beq _0806E3F6
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_0806E3F6:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
