	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032A38
	movs r0, #0
	mov r8, r0
	mov r3, r8
	strb r3, [r1]
	movs r0, #0x40
	movs r1, #0x4d
	adds r1, r1, r5
	mov ip, r1
	movs r7, #0
	strb r0, [r1]
	movs r2, #0xff
	movs r4, #1
	movs r3, #2
	movs r1, #2
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x41
	bl Boss_PlayAnimFacing
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r7, [r0]
	movs r2, #0xca
	ldr r3, _08032A18 @ =0x0000087C
	adds r1, r5, r3
	strb r4, [r1]
	subs r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08032A20
	ldr r0, _08032A1C @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _08032A38
	.align 2, 0
_08032A18: .4byte 0x0000087C
_08032A1C: .4byte 0x00000878
_08032A20:
	cmp r0, #0
	bne _08032A30
	ldr r1, _08032A2C @ =0x00000878
	adds r0, r5, r1
	strh r7, [r0]
	b _08032A38
	.align 2, 0
_08032A2C: .4byte 0x00000878
_08032A30:
	ldr r3, _08032AB0 @ =0x00000878
	adds r0, r5, r3
	mov r1, r8
	strh r1, [r0]
_08032A38:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	subs r3, #0x19
	adds r0, r6, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08032AC0
	ldr r3, _08032AB4 @ =0x00000311
	adds r0, r6, r3
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08032AC0
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08032AB8
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x40
	bl Boss_PlayAnimFacing
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08032AC0
	.align 2, 0
_08032AB0: .4byte 0x00000878
_08032AB4: .4byte 0x00000311
_08032AB8:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08032AC0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
