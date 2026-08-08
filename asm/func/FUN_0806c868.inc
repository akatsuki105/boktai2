	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _0806C884
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
_0806C884:
	ldr r0, _0806C894 @ =0x00000382
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0x3b
	bls _0806C898
	subs r0, #0x3c
	b _0806C8A4
	.align 2, 0
_0806C894: .4byte 0x00000382
_0806C898:
	ldr r0, [r7, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x20]
	movs r0, #0
_0806C8A4:
	strb r0, [r2]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x66
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C8FA
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C902
_0806C8FA:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C902:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C926
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C92E
_0806C926:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C92E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C964 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C99C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C968
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C95E
	ldrb r0, [r4, #5]
_0806C95E:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C978
	.align 2, 0
_0806C964: .4byte 0x0000FFFF
_0806C968:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C978
	strh r1, [r4, #8]
_0806C978:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _0806C99C
	movs r0, #1
	strb r0, [r4, #7]
_0806C99C:
	ldr r1, _0806C9B8 @ =0x000004C7
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806C9B0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806C9B0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C9B8: .4byte 0x000004C7
