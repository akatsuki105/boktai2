	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _082372DC
	movs r0, #0
	b _082373DC
_082372DC:
	movs r6, #0
	movs r7, #0
	strb r6, [r4, #0x1d]
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _082372FC
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #2
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	ldrh r2, [r1]
	ldrb r3, [r4, #0x1b]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822f3cc
_082372FC:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0xe]
	cmp r0, r1
	blo _082373AC
	ldrh r1, [r4, #0x18]
	movs r0, #2
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq _08237326
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _08237322
	movs r6, #1
	b _08237340
_08237322:
	subs r0, #1
	b _0823733A
_08237326:
	ldrh r0, [r4, #0x14]
	adds r0, #1
	strh r0, [r4, #0x14]
	ldrh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0823733C
	movs r6, #1
	subs r0, r1, #1
_0823733A:
	strh r0, [r4, #0x14]
_0823733C:
	cmp r6, #0
	beq _08237376
_08237340:
	ldrb r1, [r4, #0x1d]
	movs r0, #2
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0x1b]
	cmp r0, #2
	bne _08237354
	strb r2, [r4, #0x1b]
	b _0823737E
_08237354:
	cmp r0, #3
	bne _08237364
	strb r2, [r4, #0x1b]
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _0823737E
_08237364:
	movs r0, #2
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08237374
	ldrh r0, [r4, #0x16]
	subs r0, #1
_08237374:
	strh r0, [r4, #0x14]
_08237376:
	ldrb r1, [r4, #0x1d]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0x1d]
_0823737E:
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #2
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r1, [r1, #2]
	ldrh r0, [r4, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _08237398
	asrs r0, r0, #6
	b _0823739E
_08237398:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0823739E:
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082373DA
	movs r0, #1
	strh r0, [r4, #0xe]
	b _082373DA
_082373AC:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	ldrh r1, [r4, #0xe]
	cmp r0, r1
	blt _082373DA
	ldrh r1, [r4, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _082373C8
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _082373DA
	b _082373D2
_082373C8:
	ldrh r0, [r4, #0x14]
	adds r0, #1
	ldrh r1, [r4, #0x16]
	cmp r0, r1
	blt _082373DA
_082373D2:
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
_082373DA:
	adds r0, r6, #0
_082373DC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
