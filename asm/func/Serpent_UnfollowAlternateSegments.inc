	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _08190600 @ =0x00000F36
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _0819062C
	movs r7, #1
	movs r0, #3
	rsbs r0, r0, #0
	mov ip, r0
	adds r5, r2, #0
	ldr r0, _08190604 @ =0x0000077A
	adds r2, r1, r0
	movs r6, #0x92
	lsls r6, r6, #1
_081905F4:
	ldrh r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _08190608
	movs r0, #1
	b _0819060A
	.align 2, 0
_08190600: .4byte 0x00000F36
_08190604: .4byte 0x0000077A
_08190608:
	movs r0, #0
_0819060A:
	cmp r0, #0
	bne _08190620
	cmp r4, #1
	bne _08190616
	movs r4, #0
	b _08190620
_08190616:
	ldrh r1, [r2]
	mov r0, ip
	ands r0, r1
	strh r0, [r2]
	adds r4, #1
_08190620:
	adds r2, r2, r6
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _081905F4
_0819062C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
