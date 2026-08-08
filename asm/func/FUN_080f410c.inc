	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	ldr r0, _080F412C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F4130
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F4132
	.align 2, 0
_080F412C: .4byte 0x0000046D
_080F4130:
	movs r0, #0
_080F4132:
	cmp r0, #0
	bne _080F4138
	b _080F44E0
_080F4138:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _080F4190 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F4194 @ =0x0000021E
	adds r0, r7, r2
	movs r2, #0
	strh r2, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r2, [r0]
	ldr r5, _080F4198 @ =0x00000202
	adds r0, r7, r5
	strh r2, [r0]
	adds r3, r7, #0
	adds r3, #0xde
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	movs r2, #1
	adds r5, #0x5b
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _080F419C
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080F41A6
	.align 2, 0
_080F4190: .4byte 0xFFFEBE3F
_080F4194: .4byte 0x0000021E
_080F4198: .4byte 0x00000202
_080F419C:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080F41A6:
	ldrb r0, [r3]
	cmp r0, #0
	bne _080F41BA
	ldr r2, [r7, #0x44]
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F41C8
_080F41BA:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F41C8:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #2
	ldrb r0, [r3]
	cmp r0, #0
	bne _080F41E0
	ldr r0, [r7, #0x44]
	strb r1, [r0, #7]
	b _080F41E6
_080F41E0:
	ldr r0, [r7, #0x44]
	adds r0, #0x3a
	strb r1, [r0]
_080F41E6:
	ldr r2, _080F4404 @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _080F4408 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x30]
	add r5, sp, #0x30
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _080F440C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080F4410 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080F4414 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	mov sb, r2
	str r2, [sp, #4]
	movs r3, #2
	mov r8, r3
	str r3, [sp, #8]
	movs r0, #1
	mov sl, r0
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080F4410 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080F4414 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080F4410 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080F4414 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080F4410 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080F4414 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080F4410 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080F4414 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080F4410 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080F4414 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r1, _080F4418 @ =0x000001DF
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #4
	beq _080F4360
	cmp r1, #1
	beq _080F4360
	cmp r1, #5
	beq _080F4360
	cmp r1, #7
	beq _080F4360
	cmp r1, #6
	beq _080F4360
	cmp r1, #0x18
	bne _080F4366
_080F4360:
	movs r0, #0xe5
	bl PlaySound_082406e0
_080F4366:
	adds r0, r7, #0
	bl FUN_080e8360
	ldr r2, _080F4418 @ =0x000001DF
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _080F437C
	adds r0, r7, #0
	bl FUN_080f8ae0
_080F437C:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080F43DE
	movs r5, #8
	ldrsh r0, [r7, r5]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x14]
	movs r3, #0xc
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x18]
	movs r5, #0xce
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r5, #0x94
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _080F4404 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x38]
	add r1, sp, #0x38
	add r0, sp, #0x10
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl FUN_082318ac
_080F43DE:
	ldrb r0, [r4]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _080F4420
	ldr r0, _080F441C @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r2, r2, r5
	movs r1, #1
	lsls r1, r3
	b _080F4432
	.align 2, 0
_080F4404: .4byte 0xFFFF0000
_080F4408: .4byte 0x0000FFFF
_080F440C: .4byte 0x030046B8
_080F4410: .4byte 0x000003FF
_080F4414: .4byte 0x0203B400
_080F4418: .4byte 0x000001DF
_080F441C: .4byte 0x030046A0
_080F4420:
	ldr r0, _080F4498 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_080F4432:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, _080F449C @ =FUN_080e48d0
	movs r3, #0x10
	ldr r1, _080F44A0 @ =0x0000046D
	adds r0, r7, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r5, _080F44A4 @ =0x0000046B
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r2, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _080F44A8 @ =0x0000046A
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _080F44AC @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _080F44B0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F44B4
	movs r0, #1
	b _080F44B6
	.align 2, 0
_080F4498: .4byte 0x030046A0
_080F449C: .4byte FUN_080e48d0
_080F44A0: .4byte 0x0000046D
_080F44A4: .4byte 0x0000046B
_080F44A8: .4byte 0x0000046A
_080F44AC: .4byte 0x0000046C
_080F44B0: .4byte 0x030047A4
_080F44B4:
	movs r0, #0
_080F44B6:
	cmp r0, #0
	bne _080F44D6
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F44D6
	ldr r0, _080F44F0 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
_080F44D6:
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_080136b4
_080F44E0:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F44F0: .4byte 0x03002B28
