	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
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
	beq _080064BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080064C4
_080064BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080064C4:
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
	beq _080064E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080064F0
_080064E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080064F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006528 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006560
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800652C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006520
	ldrb r0, [r4, #5]
_08006520:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800653C
	.align 2, 0
_08006528: .4byte 0x0000FFFF
_0800652C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800653C
	strh r1, [r4, #8]
_0800653C:
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
	bne _08006560
	movs r0, #1
	strb r0, [r4, #7]
_08006560:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006570
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006570:
	ldr r0, [r7, #0x18]
	cmp r0, #3
	bhi _0800657E
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _08006596
_0800657E:
	cmp r0, #7
	bls _08006590
	ldr r0, _0800658C @ =MapItem_UpdateIdle
	str r0, [r7, #0x44]
	movs r0, #0
	b _0800659C
	.align 2, 0
_0800658C: .4byte MapItem_UpdateIdle
_08006590:
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_08006596:
	strh r0, [r1, #2]
	ldr r0, [r7, #0x18]
	adds r0, #1
_0800659C:
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
