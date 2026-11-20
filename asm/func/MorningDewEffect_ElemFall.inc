	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #0x1e
	ldrsh r1, [r2, r3]
	ldrb r5, [r7, #5]
	adds r1, r1, r5
	subs r1, r0, r1
	movs r0, #0x96
	lsls r0, r0, #3
	cmp r1, r0
	ble _0801A1B8
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	movs r1, #1
	movs r4, #2
_0801A1A8:
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	subs r4, #1
	adds r6, #0x28
	cmp r4, #0
	bge _0801A1A8
	b _0801A3A0
_0801A1B8:
	cmp r1, #0x18
	bgt _0801A1BE
	b _0801A2FA
_0801A1BE:
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	ldr r0, [r7, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	mov sb, r1
	ands r0, r1
	str r0, [r7, #0x18]
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0801A2AC
	movs r0, #0x18
	strb r0, [r7, #2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	mov ip, r2
	orrs r1, r2
	str r1, [r0]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801A204
	mov r3, ip
	strb r3, [r7, #1]
_0801A204:
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	ldr r5, _0801A2A0 @ =0x0203B400
	mov sl, r5
	ldr r4, _0801A2A4 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _0801A2A8 @ =0x000003FF
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r1, [r1]
	mov r5, ip
	ands r1, r5
	subs r1, #4
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r2, [r2]
	ands r2, r5
	subs r2, #4
	bl Particle_SetOffset
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl Particle_SetPose
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	mov r5, sb
	ands r1, r5
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r7, #8]
	ldr r2, [r7, #0xc]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	b _0801A3A0
	.align 2, 0
_0801A2A0: .4byte 0x0203B400
_0801A2A4: .4byte 0x030046B8
_0801A2A8: .4byte 0x000003FF
_0801A2AC:
	subs r0, #1
	strb r0, [r7, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	bne _0801A2E0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl Particle_SetPose
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
_0801A2E0:
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bne _0801A3A0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0801A3A0
_0801A2FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r7]
	strh r1, [r7, #6]
	ldr r2, _0801A3B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0801A3C0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #4
	strb r0, [r7, #3]
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	movs r0, #0x10
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0x13
	adds r1, r1, r7
	mov sb, r1
	adds r5, r2, #0
_0801A332:
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	mov r2, r8
	ldr r1, [r2, #0x28]
	adds r0, r6, #0
	movs r2, #2
	bl Particle_SetPose
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	mov r0, sl
	adds r1, r0, r4
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0801A3C0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	adds r2, r3, r4
	movs r0, #3
	ands r1, r0
	strb r1, [r2]
	adds r4, #1
	adds r6, #0x28
	cmp r4, #2
	ble _0801A332
	ldr r0, _0801A3C4 @ =0x03002BE0
	ldr r0, [r0]
	bl Player_RemoveKaamos
_0801A3A0:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3B8: .4byte 0x030046B8
_0801A3BC: .4byte 0x000003FF
_0801A3C0: .4byte 0x0203B400
_0801A3C4: .4byte 0x03002BE0
