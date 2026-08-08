	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080DFA44
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_080DFA44:
	adds r0, r5, #0
	bl FUN_080df540
	adds r0, r5, #0
	bl FUN_080df6d4
	ldr r2, _080DFA7C @ =0x0000019D
	adds r1, r5, r2
	adds r2, #3
	adds r0, r5, r2
	subs r2, #0xc
	adds r3, r5, r2
	ldrb r4, [r1]
	ldrh r6, [r0]
	ldr r2, _080DFA80 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _080DFA84
	asrs r1, r0, #0xc
	b _080DFA8A
	.align 2, 0
_080DFA7C: .4byte 0x0000019D
_080DFA80: .4byte 0x085B0A08
_080DFA84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DFA8A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _080DFAA4 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _080DFAA8
	asrs r0, r0, #0xc
	b _080DFAAE
	.align 2, 0
_080DFAA4: .4byte 0x085B0A08
_080DFAA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DFAAE:
	strh r0, [r3, #4]
	mov r4, sp
	adds r3, r5, #0
	adds r3, #0x1c
	movs r0, #0xca
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r3, #0
	cmp r2, #0
	blt _080DFAFC
	cmp r1, #0
	blt _080DFAFC
	ldr r0, _080DFB00 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080DFAFC
	ldr r0, _080DFB04 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DFB08
_080DFAFC:
	movs r4, #0
	b _080DFB16
	.align 2, 0
_080DFB00: .4byte 0x030046A8
_080DFB04: .4byte 0x030046AC
_080DFB08:
	ldr r0, _080DFB28 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080DFB16:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DFB2C
	adds r0, #4
	b _080DFB38
	.align 2, 0
_080DFB28: .4byte 0x030046A4
_080DFB2C:
	ldr r0, _080DFB5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DFB38:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _080DFB60
	movs r0, #0xd7
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	movs r2, #0xd9
	lsls r2, r2, #1
	adds r1, r5, r2
	b _080DFBD6
	.align 2, 0
_080DFB5C: .4byte 0x030046A4
_080DFB60:
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r5, #0x1c]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	ldrh r0, [r6, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r5, #0
	bl FUN_080df900
	adds r0, r5, #0
	bl FUN_080df880
	ldrb r0, [r5, #6]
	adds r0, #8
	strb r0, [r5, #6]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _080DFBB4
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080DFBB4:
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0
	ble _080DFBC6
	subs r0, #1
	str r0, [r1]
	b _080DFBDA
_080DFBC6:
	movs r2, #0xd7
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r1, r5, r0
_080DFBD6:
	movs r0, #1
	strb r0, [r1]
_080DFBDA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
