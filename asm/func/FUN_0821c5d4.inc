	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821C6BA
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r6, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r5, r4, r2
	movs r1, #8
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0821C616
	adds r1, r4, #0
	adds r1, #0x50
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0821C650 @ =0x0000023E
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r5, #0
	bl FUN_08236400
_0821C616:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821C6BA
	movs r0, #0x93
	lsls r0, r0, #2
	adds r5, r4, r0
	mov r3, sp
	movs r7, #0x64
	ldr r2, _0821C654 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0821C658
	asrs r1, r0, #0xc
	b _0821C65E
	.align 2, 0
_0821C650: .4byte 0x0000023E
_0821C654: .4byte 0x085B0A08
_0821C658:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821C65E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0821C67A
	asrs r0, r0, #0xc
	b _0821C680
_0821C67A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821C680:
	strh r0, [r3, #4]
	adds r3, r4, #0
	adds r3, #0x50
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0x42
	strb r6, [r0]
	adds r0, r5, #0
	bl FUN_08236400
_0821C6BA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
