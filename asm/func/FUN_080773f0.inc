	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _08077410 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08077406
	b _08077A46
_08077406:
	lsls r0, r0, #2
	ldr r1, _08077414 @ =_08077418
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077410: .4byte 0x0000037D
_08077414: .4byte _08077418
_08077418: @ jump table
	.4byte _08077430 @ case 0
	.4byte _08077548 @ case 1
	.4byte _080775B0 @ case 2
	.4byte _08077608 @ case 3
	.4byte _08077784 @ case 4
	.4byte _08077914 @ case 5
_08077430:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r3, #0xd5
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	adds r2, #0x4b
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077480
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08077488
_08077480:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08077488:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080774AC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080774B4
_080774AC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080774B4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080774EC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077524
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080774F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080774E4
	ldrb r0, [r4, #5]
_080774E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077500
	.align 2, 0
_080774EC: .4byte 0x0000FFFF
_080774F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077500
	strh r1, [r4, #8]
_08077500:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077524
	movs r0, #1
	strb r0, [r4, #7]
_08077524:
	ldr r3, _08077544 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _08077538
	b _08077A46
_08077538:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_08077544: .4byte 0x0000037E
_08077548:
	adds r2, r6, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080775A8 @ =0x0000037E
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xf0
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, #8
	bls _0807758C
	lsls r0, r0, #3
	adds r1, r6, #0
	adds r1, #0xf1
	strb r0, [r1]
	ldrh r0, [r4]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080775AC @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_0807758C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0807759C
	b _08077A46
_0807759C:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_080775A8: .4byte 0x0000037E
_080775AC: .4byte 0x000003F6
_080775B0:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r3, _08077600 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080775DA
	b _08077A46
_080775DA:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08077604 @ =FUN_080726e0
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08077A46
	.align 2, 0
_08077600: .4byte 0x0000037E
_08077604: .4byte FUN_080726e0
_08077608:
	ldr r1, _08077678 @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08077622
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
_08077622:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0807767C @ =0x00000387
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _08077680
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _0807768E
	.align 2, 0
_08077678: .4byte 0x0000037E
_0807767C: .4byte 0x00000387
_08077680:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_0807768E:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080776B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080776B8
_080776B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080776B8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080776F0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077728
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080776F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080776E8
	ldrb r0, [r4, #5]
_080776E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077704
	.align 2, 0
_080776F0: .4byte 0x0000FFFF
_080776F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077704
	strh r1, [r4, #8]
_08077704:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077728
	movs r0, #1
	strb r0, [r4, #7]
_08077728:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	adds r1, r6, #0
	adds r1, #0xf0
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r0, _0807777C @ =0x0000037E
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _08077780 @ =0x000003F6
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0807776E
	b _08077A46
_0807776E:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_0807777C: .4byte 0x0000037E
_08077780: .4byte 0x000003F6
_08077784:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080777DC @ =0x00000387
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _080777E0
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080777EE
	.align 2, 0
_080777DC: .4byte 0x00000387
_080777E0:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_080777EE:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077810
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08077818
_08077810:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08077818:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08077850 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077888
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077854
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08077848
	ldrb r0, [r4, #5]
_08077848:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077864
	.align 2, 0
_08077850: .4byte 0x0000FFFF
_08077854:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077864
	strh r1, [r4, #8]
_08077864:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077888
	movs r0, #1
	strb r0, [r4, #7]
_08077888:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldr r0, _080778CC @ =0x0000037E
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xf0
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _080778D4
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r6, #0
	adds r2, #0xf1
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080778D0 @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	b _080778EC
	.align 2, 0
_080778CC: .4byte 0x0000037E
_080778D0: .4byte 0x000003F6
_080778D4:
	adds r1, r6, #0
	adds r1, #0xf1
	movs r0, #0x40
	strb r0, [r1]
	ldr r3, _0807790C @ =0x000003F6
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_080778EC:
	ldr r0, _08077910 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08077900
	b _08077A46
_08077900:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_0807790C: .4byte 0x000003F6
_08077910: .4byte 0x0000037E
_08077914:
	adds r4, r6, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _08077970 @ =0x00000387
	adds r0, r6, r3
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077974
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _0807797C
	.align 2, 0
_08077970: .4byte 0x00000387
_08077974:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807797C:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080779A0
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _080779A8
_080779A0:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080779A8:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080779E0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _08077A18
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080779E4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080779D8
	ldrb r0, [r5, #5]
_080779D8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080779F4
	.align 2, 0
_080779E0: .4byte 0x0000FFFF
_080779E4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080779F4
	strh r1, [r5, #8]
_080779F4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077A18
	movs r0, #1
	strb r0, [r5, #7]
_08077A18:
	ldr r3, _08077A54 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08077A46
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	bl FUN_08072620
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08077A58 @ =FUN_080772ec
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
_08077A46:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077A54: .4byte 0x0000037E
_08077A58: .4byte FUN_080772ec
