	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r2, #0
	ldr r2, _080014C0 @ =0x03000010
	ldrb r0, [r6, #1]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r7, [r0]
	strh r1, [r7, #0x18]
	ldrb r0, [r6]
	strb r0, [r7, #0x1a]
	ldrb r0, [r6, #1]
	strb r0, [r7, #0x1b]
	ldrb r1, [r7, #0x1b]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _080014C4 @ =0x03003ED0
	adds r0, r0, r1
	mov sb, r0
	ldrh r0, [r6, #2]
	strh r0, [r7, #0x1c]
	ldrh r0, [r7, #0x1c]
	bl GetTilemapFile
	adds r5, r0, #0
	ldrb r1, [r7, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001496
	ldr r0, _080014C8 @ =0x000056C2
	bl Registry_Find
	ldr r1, [r0, #4]
	movs r2, #8
	ldrsh r0, [r1, r2]
	str r0, [r6, #0xc]
	movs r3, #0xa
	ldrsh r0, [r1, r3]
	str r0, [r6, #0x10]
_08001496:
	ldrb r1, [r7, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080014D4
	ldr r3, _080014CC @ =0x030047C8
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r2, _080014D0 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r0, r1, r0
	ldr r1, [r6, #0x1c]
	mov r8, r1
	b _080014DC
	.align 2, 0
_080014C0: .4byte 0x03000010
_080014C4: .4byte 0x03003ED0
_080014C8: .4byte 0x000056C2
_080014CC: .4byte 0x030047C8
_080014D0: .4byte 0x03003540
_080014D4:
	ldr r4, [r6, #4]
	ldr r0, [r6, #8]
	ldr r2, [r6, #0x1c]
	mov r8, r2
_080014DC:
	lsls r1, r4, #4
	movs r2, #0
	strh r1, [r7, #0x1e]
	lsls r0, r0, #4
	strh r0, [r7, #0x20]
	strh r1, [r7, #0x22]
	strh r0, [r7, #0x24]
	strh r1, [r7, #0x38]
	strh r0, [r7, #0x3a]
	ldr r0, [r6, #0x14]
	strh r0, [r7, #0x2a]
	ldr r0, [r6, #0x18]
	strh r0, [r7, #0x2c]
	str r2, [r7, #0x30]
	str r2, [r7, #0x34]
	ldr r0, [r6, #0xc]
	strh r0, [r7, #0x3c]
	ldr r0, [r6, #0x10]
	strh r0, [r7, #0x3e]
	ldr r0, [r6, #0x20]
	lsls r0, r0, #3
	adds r1, r7, #0
	adds r1, #0x40
	strh r0, [r1]
	ldr r0, [r6, #0x24]
	lsls r0, r0, #3
	adds r1, #2
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	adds r0, #6
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r7, #0x1b]
	bl GetTilemapBuffer
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0x4d
	bne _0800154A
	ldrb r0, [r5, #1]
	cmp r0, #0x50
	bne _0800154A
	mov r3, sb
	strh r4, [r3]
	ldrb r0, [r7, #0x1b]
	ldr r1, [r6, #0x28]
	bl SetBGPrioDirect
	b _08001568
_0800154A:
	ldrb r0, [r7, #0x1b]
	movs r4, #0xc
	ldrsh r1, [r6, r4]
	str r1, [sp]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	str r1, [sp, #4]
	ldr r1, [r6, #0x28]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBG
_08001568:
	adds r0, r7, #0
	adds r0, #0x4a
	movs r4, #0
	mov sb, r4
	mov r1, r8
	strh r1, [r0]
	ldrh r5, [r7, #0x1e]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x14
	ldrh r4, [r7, #0x20]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x14
	adds r0, r5, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	mov r8, r0
	adds r0, r4, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	movs r2, #2
	rsbs r2, r2, #0
	ands r2, r0
	ldrb r0, [r7, #0x1b]
	str r4, [sp]
	mov r1, r8
	adds r3, r5, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	adds r0, #0x4e
	mov r2, sb
	strh r2, [r0]
	ldr r3, [r6, #0x34]
	mov ip, r3
	lsls r0, r3, #8
	adds r4, r7, #0
	adds r4, #0x52
	strh r0, [r4]
	ldr r0, [r6, #0x38]
	mov r8, r0
	lsls r0, r0, #8
	adds r2, r7, #0
	adds r2, #0x54
	strh r0, [r2]
	adds r5, r7, #0
	adds r5, #0x5e
	mov r1, sb
	strh r1, [r5]
	adds r3, r7, #0
	adds r3, #0x60
	strh r1, [r3]
	ldrh r0, [r4]
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r1, [r2]
	adds r0, r7, #0
	adds r0, #0x5c
	strh r1, [r0]
	ldrh r0, [r4]
	strh r0, [r5]
	ldrh r0, [r2]
	strh r0, [r3]
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _080015FE
	ldrb r0, [r7, #0x1b]
	mov r1, ip
	mov r2, r8
	bl FUN_0822f178
_080015FE:
	movs r0, #0
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
