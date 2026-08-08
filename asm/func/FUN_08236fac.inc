	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r6, #2
	adds r0, #4
	adds r2, r1, r0
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrb r0, [r2, #1]
	muls r0, r3, r0
	lsls r0, r0, #1
	adds r0, r1, r0
	str r0, [r4]
	movs r0, #0x40
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	cmp r0, r6
	bne _08237002
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08237002
	movs r3, #4
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _08236FF8
	ldrb r1, [r4, #4]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08237002
	b _08237036
_08236FF8:
	ldrb r1, [r4, #4]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08237036
_08237002:
	ldrb r0, [r2, #1]
	strb r0, [r4, #5]
	movs r0, #4
	ands r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08237016
	ldrb r0, [r4, #5]
	subs r0, #1
_08237016:
	strh r0, [r4, #8]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r1, r1, r0
	ldrh r1, [r1]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	strh r1, [r4, #0xe]
	strh r6, [r4, #0xa]
	strb r5, [r4, #4]
	movs r0, #1
	b _0823703A
_08237036:
	strb r5, [r4, #4]
	movs r0, #0
_0823703A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
