	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r1, #0
	movs r0, #0xbc
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059DCC
	movs r0, #0
	strb r0, [r4, #1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	movs r2, #1
	mov r3, ip
	strb r2, [r3, #9]
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #0x20]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	strb r2, [r4, #4]
_08059DCC:
	ldrh r1, [r4, #8]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08059DDE
	ldrb r0, [r4, #0xd]
	adds r0, #0x20
	strb r0, [r4, #0xd]
_08059DDE:
	ldrh r1, [r4, #8]
	lsls r2, r1, #3
	adds r0, r1, #0
	ands r0, r3
	lsls r0, r0, #7
	adds r3, r2, r0
	movs r0, #0x20
	subs r0, r0, r1
	mov r5, sp
	lsls r6, r0, #3
	ldr r2, _08059E10 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08059E14
	asrs r1, r0, #0xc
	b _08059E1A
	.align 2, 0
_08059E10: .4byte gSineTable
_08059E14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059E1A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08059E36
	asrs r0, r0, #0xc
	b _08059E3C
_08059E36:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059E3C:
	strh r0, [r5, #4]
	mov r3, ip
	adds r3, #0x1c
	mov r2, sp
	mov r1, sp
	ldrh r0, [r4, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, ip
	strh r0, [r1, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0x12]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #0x14]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq _08059E6E
	lsls r0, r0, #1
	mov r2, ip
	strb r0, [r2, #9]
	b _08059E74
_08059E6E:
	movs r0, #1
	mov r3, ip
	strb r0, [r3, #9]
_08059E74:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _08059E8C
	movs r1, #0
	movs r0, #0x40
	mov r2, ip
	strb r0, [r2, #9]
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #1]
	strh r1, [r4, #8]
_08059E8C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
