	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	bl FUN_0822d00c
	adds r7, r0, #0
	ldr r0, _0822D65C @ =0x03004040
	ldr r1, _0822D660 @ =0x03004460
	ldr r2, [r0]
	ldr r0, [r1]
	muls r2, r0, r2
	asrs r0, r2, #6
	str r0, [sp]
	cmp r0, #0x40
	bne _0822D66C
	ldr r1, _0822D664 @ =0x03004468
	ldr r0, _0822D668 @ =0x03004250
	b _0822D810
	.align 2, 0
_0822D65C: .4byte 0x03004040
_0822D660: .4byte 0x03004460
_0822D664: .4byte 0x03004468
_0822D668: .4byte 0x03004250
_0822D66C:
	ldr r1, [sp]
	cmp r1, #0
	bne _0822D6D0
	adds r5, r7, #0
	movs r2, #0
	ldr r0, _0822D69C @ =0x03004468
	mov r8, r0
_0822D67A:
	ldr r1, _0822D6A0 @ =0x03004454
	ldrh r0, [r1]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0822D6A8
	adds r6, r2, #1
	ldr r1, _0822D6A4 @ =0x03004494
	movs r3, #0xf
_0822D68E:
	ldrh r0, [r1]
	strh r0, [r5]
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D68E
	b _0822D6C0
	.align 2, 0
_0822D69C: .4byte 0x03004468
_0822D6A0: .4byte 0x03004454
_0822D6A4: .4byte 0x03004494
_0822D6A8:
	lsls r1, r2, #5
	ldr r0, _0822D6CC @ =0x03004250
	adds r4, r1, r0
	adds r6, r2, #1
	movs r3, #0xf
_0822D6B2:
	ldrh r0, [r4]
	strh r0, [r5]
	adds r4, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D6B2
_0822D6C0:
	adds r2, r6, #0
	cmp r2, #0xf
	ble _0822D67A
	mov r2, r8
	str r7, [r2]
	b _0822D812
	.align 2, 0
_0822D6CC: .4byte 0x03004250
_0822D6D0:
	asrs r2, r2, #7
	mov r8, r2
	movs r0, #0x20
	mov r1, r8
	subs r1, r0, r1
	mov sl, r1
	ldr r0, _0822D740 @ =0x03004468
	str r7, [r0]
	ldr r0, _0822D744 @ =0x03004494
	ldrh r0, [r0]
	cmp r0, #0
	bne _0822D772
	ldr r4, _0822D748 @ =0x03004250
	adds r5, r7, #0
	movs r2, #0
_0822D6EE:
	ldr r1, _0822D74C @ =0x03004454
	ldrh r0, [r1]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0822D758
	adds r6, r2, #1
	ldr r2, _0822D750 @ =0x00007C1F
	mov sl, r2
	ldr r0, _0822D754 @ =0x000F83E0
	mov sb, r0
	movs r3, #0xf
	movs r1, #0xf8
	lsls r1, r1, #2
	mov ip, r1
	movs r7, #0xf8
	lsls r7, r7, #7
_0822D712:
	ldrh r2, [r4]
	adds r0, r2, #0
	mov r1, sl
	ands r0, r1
	mov r1, r8
	muls r1, r0, r1
	mov r0, sb
	ands r1, r0
	mov r0, ip
	ands r2, r0
	mov r0, r8
	muls r0, r2, r0
	ands r0, r7
	orrs r1, r0
	lsrs r1, r1, #5
	strh r1, [r5]
	adds r4, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D712
	b _0822D76A
	.align 2, 0
_0822D740: .4byte 0x03004468
_0822D744: .4byte 0x03004494
_0822D748: .4byte 0x03004250
_0822D74C: .4byte 0x03004454
_0822D750: .4byte 0x00007C1F
_0822D754: .4byte 0x000F83E0
_0822D758:
	adds r6, r2, #1
	movs r3, #0xf
_0822D75C:
	ldrh r0, [r4]
	strh r0, [r5]
	adds r4, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D75C
_0822D76A:
	adds r2, r6, #0
	cmp r2, #0xf
	ble _0822D6EE
	b _0822D80C
_0822D772:
	ldr r1, _0822D7E4 @ =0x00007C1F
	ands r1, r0
	str r1, [sp, #4]
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	str r2, [sp, #8]
	ldr r4, _0822D7E8 @ =0x03004250
	adds r5, r7, #0
	movs r2, #0
_0822D786:
	ldr r1, _0822D7EC @ =0x03004454
	ldrh r0, [r1]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0822D7F4
	adds r6, r2, #1
	ldr r0, [sp, #8]
	mov r2, sl
	muls r2, r0, r2
	mov ip, r2
	ldr r1, _0822D7E4 @ =0x00007C1F
	mov sb, r1
	movs r3, #0xf
	ldr r0, [sp, #4]
	mov r2, sl
	muls r2, r0, r2
	adds r7, r2, #0
_0822D7AC:
	ldrh r1, [r4]
	adds r0, r1, #0
	mov r2, sb
	ands r0, r2
	mov r2, r8
	muls r2, r0, r2
	adds r2, r2, r7
	ldr r0, _0822D7F0 @ =0x000F83E0
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r1, r0
	mov r0, r8
	muls r0, r1, r0
	add r0, ip
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r0, r1
	orrs r2, r0
	lsrs r2, r2, #5
	strh r2, [r5]
	adds r4, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D7AC
	b _0822D806
	.align 2, 0
_0822D7E4: .4byte 0x00007C1F
_0822D7E8: .4byte 0x03004250
_0822D7EC: .4byte 0x03004454
_0822D7F0: .4byte 0x000F83E0
_0822D7F4:
	adds r6, r2, #1
	movs r3, #0xf
_0822D7F8:
	ldrh r0, [r4]
	strh r0, [r5]
	adds r4, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D7F8
_0822D806:
	adds r2, r6, #0
	cmp r2, #0xf
	ble _0822D786
_0822D80C:
	ldr r0, [sp]
	ldr r1, _0822D824 @ =0x03004048
_0822D810:
	str r0, [r1]
_0822D812:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822D824: .4byte 0x03004048
