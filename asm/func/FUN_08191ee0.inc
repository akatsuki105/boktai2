	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r2, _08192038 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _0819203C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r4, _08192040 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08192044 @ =0x000003FF
	mov sl, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r0, #0x14
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #2
	str r6, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x20
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x40
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x5e
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x80
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xc4
	bl EmitSmoke
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xf0
	bl EmitSmoke
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192038: .4byte 0xFFFF0000
_0819203C: .4byte 0x0000FFFF
_08192040: .4byte 0x030046B8
_08192044: .4byte 0x000003FF
_08192048: .4byte 0x0203B400
