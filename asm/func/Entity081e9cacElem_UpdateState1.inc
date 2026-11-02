	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	adds r5, r3, #0
	adds r4, r0, #0
	adds r4, #0xcc
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
	beq _081E8FE2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081E8FEA
_081E8FE2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8FEA:
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
	beq _081E900E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081E9016
_081E900E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9016:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E904C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E9084
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9050
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9046
	ldrb r0, [r4, #5]
_081E9046:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9060
	.align 2, 0
_081E904C: .4byte 0x0000FFFF
_081E9050:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9060
	strh r1, [r4, #8]
_081E9060:
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
	bne _081E9084
	movs r0, #1
	strb r0, [r4, #7]
_081E9084:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
