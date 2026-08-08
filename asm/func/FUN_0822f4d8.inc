	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov ip, r1
	mov r8, r3
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r3, [sp, #0x30]
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r4, [r5, #4]
	cmp r4, #0
	beq _0822F508
	movs r0, #1
	rsbs r0, r0, #0
	b _0822F56E
_0822F508:
	movs r1, #0
	strh r4, [r5]
	strh r4, [r5, #0x12]
	strh r4, [r5, #0x14]
	strh r4, [r5, #0x16]
	strh r4, [r5, #0x18]
	strb r1, [r5, #0x1d]
	strh r4, [r5, #0x28]
	strh r4, [r5, #0x2a]
	strh r4, [r5, #0x2c]
	strh r4, [r5, #0x2e]
	strh r4, [r5, #0x30]
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	adds r0, #0x34
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r4, [r5, #0x36]
	str r4, [r5, #0x3c]
	str r4, [r5, #0x54]
	str r4, [r5, #0x48]
	str r4, [r5, #0x4c]
	str r4, [r5, #0x50]
	str r6, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, ip
	adds r2, r7, #0
	mov r3, r8
	bl FUN_0822f364
	ldr r2, _0822F57C @ =0x030044B8
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _0822F580 @ =0xFFFF0000
	cmp r0, r1
	bne _0822F560
	strh r4, [r2]
_0822F560:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x40]
	str r0, [r5, #0x44]
	str r4, [r5, #0x58]
	str r4, [r5, #0x5c]
	movs r0, #0
_0822F56E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0822F57C: .4byte 0x030044B8
_0822F580: .4byte 0xFFFF0000
