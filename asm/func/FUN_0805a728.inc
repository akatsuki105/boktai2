	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xf8
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	adds r4, r6, #0
	adds r4, #0xe8
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
	beq _0805A76E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0805A776
_0805A76E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805A776:
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
	beq _0805A79A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0805A7A2
_0805A79A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805A7A2:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805A7DC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0805A822
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805A7E6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805A7E0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805A7FC
	.align 2, 0
_0805A7DC: .4byte 0x0000FFFF
_0805A7E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805A7FA
_0805A7E6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805A7FA
	strh r1, [r4, #8]
	movs r2, #1
	b _0805A7FC
_0805A7FA:
	movs r2, #0
_0805A7FC:
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
	bne _0805A824
	movs r0, #1
	strb r0, [r4, #7]
	b _0805A824
_0805A822:
	movs r2, #0
_0805A824:
	strb r2, [r6, #4]
	ldr r0, _0805A83C @ =0x085B0A08
	ldrb r1, [r6, #5]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0805A840
	asrs r1, r0, #0xc
	b _0805A846
	.align 2, 0
_0805A83C: .4byte 0x085B0A08
_0805A840:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805A846:
	ldrh r0, [r5, #0x1e]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	adds r5, #0x2c
	ldrb r0, [r6, #0xc]
	subs r2, r0, #1
	cmp r2, #0
	bge _0805A858
	movs r2, #3
_0805A858:
	movs r3, #2
_0805A85A:
	lsls r0, r2, #3
	adds r0, r0, r6
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	subs r2, #1
	cmp r2, #0
	bge _0805A86E
	movs r2, #3
_0805A86E:
	subs r3, #1
	adds r5, #0x2c
	cmp r3, #0
	bge _0805A85A
	ldrb r0, [r6, #5]
	adds r0, #4
	strb r0, [r6, #5]
	ldrh r0, [r6, #6]
	movs r3, #3
	ands r3, r0
	cmp r3, #0
	bne _0805A8AA
	ldrb r2, [r6, #0xc]
	lsls r2, r2, #3
	adds r2, r2, r6
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r6, #0xc]
	adds r0, #1
	strb r0, [r6, #0xc]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0805A8AA
	strb r3, [r6, #0xc]
_0805A8AA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
