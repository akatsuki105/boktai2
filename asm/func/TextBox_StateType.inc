	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x18
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _0804833A
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _080482F8
	ldrb r1, [r1]
	cmp r1, #0
	bne _080482F8
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _080482F4 @ =TextBox_StateWaitInput
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080483AA
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _080483AA
	adds r1, #0x92
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _080483AA
	.align 2, 0
_080482F4: .4byte TextBox_StateWaitInput
_080482F8:
	ldrb r0, [r4, #8]
	adds r1, r0, #1
	strb r1, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4, #9]
	cmp r0, r2
	blo _0804833A
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #0x16]
	adds r0, r4, #0
	bl TextRenderer_Advance
	cmp r0, #0
	beq _0804833A
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08048330
	ldr r1, _0804832C @ =TextBox_StateIdle
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	b _0804833A
	.align 2, 0
_0804832C: .4byte TextBox_StateIdle
_08048330:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0804833A
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
_0804833A:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08048378 @ =TextBox_StateIdle
	cmp r1, r0
	beq _080483AA
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080483AA
	ldr r0, _0804837C @ =0x00000183
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048388
	ldr r2, _08048380 @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804838E
	ldr r1, _08048384 @ =TextBox_StateFastForward
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	b _080483AA
	.align 2, 0
_08048378: .4byte TextBox_StateIdle
_0804837C: .4byte 0x00000183
_08048380: .4byte 0x030044E0
_08048384: .4byte TextBox_StateFastForward
_08048388:
	subs r0, #1
	strb r0, [r1]
	ldr r2, _080483B0 @ =0x030044E0
_0804838E:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080483AA
	ldr r0, _080483B4 @ =TextBox_StateFastForward
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r0, _080483B8 @ =0x0000017F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080483AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080483B0: .4byte 0x030044E0
_080483B4: .4byte TextBox_StateFastForward
_080483B8: .4byte 0x0000017F
