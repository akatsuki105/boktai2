	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _08090214 @ =0x00002E2C
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	ldr r2, _08090218 @ =0x00002E8C
	adds r6, r5, r2
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, _0809021C @ =0x00002EEC
	adds r3, r5, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r1, _08090220 @ =0x00002F4C
	adds r1, r1, r5
	mov r8, r1
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08090224 @ =0x0000403C
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0xff
	mov r1, sb
	strb r0, [r1]
	ldr r2, _08090228 @ =0x0000403D
	adds r2, r5, r2
	str r2, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, _0809022C @ =0x0000403E
	adds r0, r5, r0
	str r0, [sp, #4]
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, _08090230 @ =0x0000403F
	adds r2, r5, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r0, _08090234 @ =0x0000402C
	adds r0, r5, r0
	str r0, [sp, #0xc]
	ldr r1, _08090238 @ =0x00004038
	adds r1, r1, r5
	mov sl, r1
	ldrb r0, [r1]
	lsls r0, r0, #4
	ldr r1, [sp, #0xc]
	ldr r2, [r1]
	adds r4, r2, r0
	ldr r1, _0809023C @ =0x00004039
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080901D4
	b _08090512
_080901D4:
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080902A4
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _0809024E
	ldrb r0, [r4, #6]
	mov r2, sb
	strb r0, [r2]
	ldr r2, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08090244
	ldr r0, _08090240 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r7]
	b _080902A4
	.align 2, 0
_08090214: .4byte 0x00002E2C
_08090218: .4byte 0x00002E8C
_0809021C: .4byte 0x00002EEC
_08090220: .4byte 0x00002F4C
_08090224: .4byte 0x0000403C
_08090228: .4byte 0x0000403D
_0809022C: .4byte 0x0000403E
_08090230: .4byte 0x0000403F
_08090234: .4byte 0x0000402C
_08090238: .4byte 0x00004038
_0809023C: .4byte 0x00004039
_08090240: .4byte 0xFFFFFDFF
_08090244:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r7]
	b _080902A4
_0809024E:
	ldr r0, _08090294 @ =0x00004050
	adds r3, r5, r0
	mov r1, sl
	ldrb r0, [r1]
	ldrh r2, [r3]
	cmp r0, r2
	beq _080902A4
	movs r1, #6
	ldrsb r1, [r4, r1]
	ldr r0, [sp, #0xc]
	ldr r2, [r0]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r6, [r3]
	lsls r0, r6, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _080902A4
	mov r1, sb
	strb r6, [r1]
	ldr r1, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7]
	movs r0, #6
	ldrsb r0, [r4, r0]
	ldrh r3, [r3]
	cmp r0, r3
	bne _0809029C
	ldr r0, _08090298 @ =0xFFFFFDFF
	ands r1, r0
	b _080902A2
	.align 2, 0
_08090294: .4byte 0x00004050
_08090298: .4byte 0xFFFFFDFF
_0809029C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_080902A2:
	str r1, [r7]
_080902A4:
	movs r1, #7
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090374
	adds r0, r1, #0
	ldr r2, _080902F0 @ =0x0000402C
	adds r7, r5, r2
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _0809030A
	ldrb r1, [r4, #7]
	ldr r2, _080902F4 @ =0x0000403D
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080902F8 @ =0x00002E8C
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08090300
	ldr r0, _080902FC @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090374
	.align 2, 0
_080902F0: .4byte 0x0000402C
_080902F4: .4byte 0x0000403D
_080902F8: .4byte 0x00002E8C
_080902FC: .4byte 0xFFFFFDFF
_08090300:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090374
_0809030A:
	ldr r1, _08090358 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _0809035C @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08090374
	movs r1, #7
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08090374
	ldr r2, _08090360 @ =0x0000403D
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090364 @ =0x00002E8C
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #7
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _0809036C
	ldr r0, _08090368 @ =0xFFFFFDFF
	ands r1, r0
	b _08090372
	.align 2, 0
_08090358: .4byte 0x00004038
_0809035C: .4byte 0x00004050
_08090360: .4byte 0x0000403D
_08090364: .4byte 0x00002E8C
_08090368: .4byte 0xFFFFFDFF
_0809036C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_08090372:
	str r1, [r2]
_08090374:
	movs r1, #8
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090444
	adds r0, r1, #0
	ldr r1, _080903C0 @ =0x0000402C
	adds r7, r5, r1
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _080903DA
	ldrb r1, [r4, #8]
	ldr r2, _080903C4 @ =0x0000403E
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080903C8 @ =0x00002EEC
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080903D0
	ldr r0, _080903CC @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090444
	.align 2, 0
_080903C0: .4byte 0x0000402C
_080903C4: .4byte 0x0000403E
_080903C8: .4byte 0x00002EEC
_080903CC: .4byte 0xFFFFFDFF
_080903D0:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090444
_080903DA:
	ldr r1, _08090428 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _0809042C @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08090444
	movs r1, #8
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08090444
	ldr r2, _08090430 @ =0x0000403E
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090434 @ =0x00002EEC
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #8
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _0809043C
	ldr r0, _08090438 @ =0xFFFFFDFF
	ands r1, r0
	b _08090442
	.align 2, 0
_08090428: .4byte 0x00004038
_0809042C: .4byte 0x00004050
_08090430: .4byte 0x0000403E
_08090434: .4byte 0x00002EEC
_08090438: .4byte 0xFFFFFDFF
_0809043C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_08090442:
	str r1, [r2]
_08090444:
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08090452
	b _08090682
_08090452:
	adds r0, r1, #0
	ldr r1, _08090494 @ =0x0000402C
	adds r7, r5, r1
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _080904A0
	ldrb r1, [r4, #9]
	ldr r2, _08090498 @ =0x0000403F
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0809049C @ =0x00002F4C
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809048A
	b _0809060A
_0809048A:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090682
	.align 2, 0
_08090494: .4byte 0x0000402C
_08090498: .4byte 0x0000403F
_0809049C: .4byte 0x00002F4C
_080904A0:
	ldr r1, _080904F4 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _080904F8 @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	bne _080904B2
	b _08090682
_080904B2:
	movs r1, #9
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080904CC
	b _08090682
_080904CC:
	ldr r2, _080904FC @ =0x0000403F
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090500 @ =0x00002F4C
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #9
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _08090508
	ldr r0, _08090504 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r2]
	b _08090682
	.align 2, 0
_080904F4: .4byte 0x00004038
_080904F8: .4byte 0x00004050
_080904FC: .4byte 0x0000403F
_08090500: .4byte 0x00002F4C
_08090504: .4byte 0xFFFFFDFF
_08090508:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	str r1, [r2]
	b _08090682
_08090512:
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090570
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	bne _08090530
	b _08090682
_08090530:
	ldrb r0, [r4, #0xb]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08090564
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #0xb
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090564
	ldr r0, _08090560 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r7]
	b _08090682
	.align 2, 0
_08090560: .4byte 0xFFFFFDFF
_08090564:
	ldr r2, _0809056C @ =0x00002E2C
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_0809056C: .4byte 0x00002E2C
_08090570:
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	cmp r0, r1
	beq _080905C8
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	bne _08090588
	b _08090682
_08090588:
	ldrb r0, [r4, #0xc]
	ldr r1, [sp]
	strb r0, [r1]
	ldr r2, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6]
	ldrb r1, [r4, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080905BC
	movs r1, #7
	ldrsb r1, [r4, r1]
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _080905BC
	ldr r0, _080905B8 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r6]
	b _08090682
	.align 2, 0
_080905B8: .4byte 0xFFFFFDFF
_080905BC:
	ldr r2, _080905C4 @ =0x00002E8C
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_080905C4: .4byte 0x00002E8C
_080905C8:
	movs r1, #0xd
	ldrsb r1, [r4, r1]
	cmp r1, r0
	beq _08090624
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	str r3, [sp, #0x10]
	bl FUN_0808fd2c
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _08090682
	ldrb r0, [r4, #0xd]
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08090618
	movs r1, #8
	ldrsb r1, [r4, r1]
	movs r0, #0xd
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090618
_0809060A:
	ldr r0, _08090614 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090682
	.align 2, 0
_08090614: .4byte 0xFFFFFDFF
_08090618:
	ldr r2, _08090620 @ =0x00002EEC
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_08090620: .4byte 0x00002EEC
_08090624:
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r0, r1
	beq _08090682
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _08090682
	ldrb r0, [r4, #0xe]
	ldr r1, [sp, #8]
	strb r0, [r1]
	mov r0, r8
	ldr r2, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	mov r1, r8
	str r2, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08090674
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090674
	ldr r0, _08090670 @ =0xFFFFFDFF
	ands r2, r0
	mov r0, r8
	str r2, [r0]
	b _08090682
	.align 2, 0
_08090670: .4byte 0xFFFFFDFF
_08090674:
	ldr r1, _08090694 @ =0x00002F4C
	adds r0, r5, r1
_08090678:
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
_08090682:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090694: .4byte 0x00002F4C
