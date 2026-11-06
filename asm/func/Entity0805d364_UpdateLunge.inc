	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	mov sb, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805C524
	movs r0, #0
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0x7c
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r3, r6, #0
	adds r3, #0x14
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r6, #0x24]
	str r1, [r6, #0x28]
	movs r0, #8
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0805C524
	adds r1, r0, #0
	lsls r1, r1, #2
	adds r0, r7, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0x14
	ldrsh r1, [r6, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
_0805C524:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C530
	movs r0, #5
	movs r1, #0
	b _0805C538
_0805C530:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C542
	movs r0, #9
_0805C538:
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _0805C636
_0805C542:
	ldrh r0, [r6, #4]
	cmp r0, #0xf
	bls _0805C54E
	ldrh r1, [r6, #4]
	movs r0, #0x20
	subs r0, r0, r1
_0805C54E:
	lsls r3, r0, #4
	mov r4, sp
	ldrb r5, [r6, #6]
	ldr r2, _0805C570 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C574
	asrs r1, r0, #0xc
	b _0805C57A
	.align 2, 0
_0805C570: .4byte gSineTable
_0805C574:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C57A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C592
	asrs r0, r0, #0xc
	b _0805C598
_0805C592:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C598:
	movs r3, #0
	mov r8, r3
	strh r0, [r4, #4]
	adds r4, r6, #0
	adds r4, #0x14
	adds r2, r6, #0
	adds r2, #0x24
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x24]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x2c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r6, #4]
	cmp r0, #0x1f
	bls _0805C5FE
	movs r0, #2
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805C634
_0805C5FE:
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _0805C630
	subs r0, #1
	strb r0, [r6, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C630
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C622
	mov r4, sb
	cmp r4, #7
	bgt _0805C61E
	movs r0, #1
	b _0805C62E
_0805C61E:
	mov r0, r8
	b _0805C62E
_0805C622:
	cmp r0, #0
	bne _0805C62C
	mov r1, r8
	strb r1, [r6, #8]
	b _0805C630
_0805C62C:
	movs r0, #0xff
_0805C62E:
	strb r0, [r6, #8]
_0805C630:
	ldrh r0, [r6, #4]
	adds r0, #1
_0805C634:
	strh r0, [r6, #4]
_0805C636:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
