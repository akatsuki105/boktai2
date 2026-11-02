	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r2, r5, #0
	adds r2, #0x6e
	ldrh r0, [r2]
	cmp r0, #0
	beq _081EE348
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _081EE4C8
_081EE348:
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r5, #0
	adds r0, #0x68
	ldrh r1, [r0]
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	movs r0, #0x5e
	adds r0, r0, r5
	mov ip, r0
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r3, _081EE3B8 @ =gSineTable
	adds r6, r5, #0
	adds r6, #0x5a
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #0xc
	ldrh r2, [r5, #0x1c]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	mov r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	adds r2, r5, #0
	adds r2, #0x64
	ldrh r0, [r2]
	cmp r0, #0
	beq _081EE3BC
	subs r0, #1
	strh r0, [r2]
	b _081EE3DC
	.align 2, 0
_081EE3B8: .4byte gSineTable
_081EE3BC:
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r2, [r5, #0x1e]
	adds r0, r0, r2
	strh r0, [r5, #0x1e]
	adds r2, r5, #0
	adds r2, #0x6d
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EE3D8
	subs r0, #1
	strb r0, [r2]
	b _081EE3DC
_081EE3D8:
	movs r0, #2
	strb r0, [r5, #7]
_081EE3DC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _081EE408
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081EE410
_081EE408:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EE410:
	str r0, [r7]
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
	beq _081EE434
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081EE43C
_081EE434:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EE43C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EE474 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EE4BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EE47E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EE478
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081EE494
	.align 2, 0
_081EE474: .4byte 0x0000FFFF
_081EE478:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EE492
_081EE47E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EE492
	strh r1, [r4, #8]
	movs r2, #1
	b _081EE494
_081EE492:
	movs r2, #0
_081EE494:
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
	bne _081EE4BC
	movs r0, #1
	strb r0, [r4, #7]
	b _081EE4BC
_081EE4BA:
	movs r2, #0
_081EE4BC:
	cmp r2, #0
	beq _081EE4C8
	adds r1, r5, #0
	adds r1, #0x58
	movs r0, #2
	strb r0, [r1]
_081EE4C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
