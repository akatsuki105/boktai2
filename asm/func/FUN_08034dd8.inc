	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08034E0A
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x58
	bl Boss_PlayAnimFlip
_08034E0A:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034EA4
	cmp r5, #5
	bne _08034E8E
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r5, [r0]
	ldr r2, _08034EAC @ =0x00000173
	adds r6, r4, r2
	cmp r5, #0
	bne _08034E8A
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _08034E8A
	ldr r1, _08034EB0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _08034EB4 @ =0x00000A18
	adds r1, r4, r2
	adds r2, r4, #0
	adds r2, #0x4d
	ldrb r3, [r2]
	movs r2, #0x32
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	bl FUN_0807ac74
_08034E8A:
	movs r0, #0xff
	strb r0, [r6]
_08034E8E:
	ldr r1, _08034EB8 @ =0x00000311
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034EA4
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08034EA4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034EAC: .4byte 0x00000173
_08034EB0: .4byte 0x03002BE0
_08034EB4: .4byte 0x00000A18
_08034EB8: .4byte 0x00000311
