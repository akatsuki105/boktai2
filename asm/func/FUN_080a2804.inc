	push {r4, r5, lr}
	adds r3, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A2816
	b _080A29E8
_080A2816:
	cmp r0, #2
	bhi _080A2864
	adds r2, r3, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r2, #0x4e
	ldrh r1, [r4]
	movs r0, #2
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	ldr r1, _080A2860 @ =0x00000402
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A28C4
	.align 2, 0
_080A2860: .4byte 0x00000402
_080A2864:
	cmp r0, #4
	bhi _080A28D4
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A28D0 @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r5, #0x3a
	adds r2, r3, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080A28C4:
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	b _080A2A0C
	.align 2, 0
_080A28D0: .4byte 0x00000402
_080A28D4:
	cmp r0, #6
	bhi _080A2960
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A295C @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #6
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	adds r1, #0xab
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A295C: .4byte 0x00000402
_080A2960:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r5, #0x9a
	adds r5, r5, r3
	mov ip, r5
	ldr r1, _080A29E4 @ =0x00000402
	adds r0, r1, #0
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	adds r5, #0x2c
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r1, #0
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	adds r0, #8
	strh r0, [r1, #0x10]
	ldr r0, [r3, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #1
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A29E4: .4byte 0x00000402
_080A29E8:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080A2A0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
