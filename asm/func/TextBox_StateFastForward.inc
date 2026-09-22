	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x18
	ldr r1, _080481C0 @ =0x0000017F
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080481C4
	movs r0, #1
	b _080481CC
	.align 2, 0
_080481C0: .4byte 0x0000017F
_080481C4:
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
_080481CC:
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _0804823E
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0804821C
	ldrb r1, [r1]
	cmp r1, #0
	bne _0804821C
	movs r4, #0xc6
	lsls r4, r4, #1
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08048218 @ =TextBox_StateWaitInput
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r4, #0xa
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804827E
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0804827E
	subs r2, #0xd8
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0804827E
	.align 2, 0
_08048218: .4byte TextBox_StateWaitInput
_0804821C:
	movs r0, #0
	strb r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #0x16]
	adds r0, r4, #0
	bl FUN_08049568
	cmp r0, #0
	beq _0804823E
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804823E
	ldr r1, _08048284 @ =TextBox_StateIdle
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
_0804823E:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08048284 @ =TextBox_StateIdle
	cmp r1, r0
	beq _0804827E
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804827E
	ldr r4, _08048288 @ =0x0000017F
	adds r3, r5, r4
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804827E
	ldr r0, _0804828C @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0804827E
	ldr r1, _08048290 @ =TextBox_StateType
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	strb r2, [r3]
_0804827E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048284: .4byte TextBox_StateIdle
_08048288: .4byte 0x0000017F
_0804828C: .4byte 0x030044E0
_08048290: .4byte TextBox_StateType
