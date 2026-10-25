	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C5472
	ldr r0, _080C5494 @ =0x0000022D
	bl PlaySound_082406e0
_080C5472:
	movs r0, #0
	str r0, [sp, #4]
	ldrh r2, [r6, #4]
	adds r0, r2, #0
	subs r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x29
	bhi _080C54AA
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _080C5498
	movs r1, #0
	str r1, [sp]
	cmp r2, #0x23
	bls _080C54CC
	b _080C54C6
	.align 2, 0
_080C5494: .4byte 0x0000022D
_080C5498:
	movs r3, #1
	str r3, [sp]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x23
	bls _080C54CC
	ldrb r0, [r6, #3]
	adds r0, #4
	b _080C54CA
_080C54AA:
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _080C54BE
	movs r4, #1
	str r4, [sp]
	cmp r1, #0x31
	bls _080C54CC
	ldrb r0, [r6, #3]
	adds r0, #4
	b _080C54CA
_080C54BE:
	movs r5, #0
	str r5, [sp]
	cmp r1, #0x31
	bls _080C54CC
_080C54C6:
	ldrb r0, [r6, #3]
	adds r0, #0xfc
_080C54CA:
	strb r0, [r6, #3]
_080C54CC:
	movs r0, #0xff
	mov sl, r0
	adds r5, r6, #0
	adds r5, #0x24
	adds r7, r6, #0
	adds r7, #0x50
	movs r1, #8
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0xd
	mov sb, r2
_080C54E2:
	ldr r3, [sp]
	cmp r3, #0
	beq _080C54FA
	movs r4, #0x32
	ldrsh r0, [r5, r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrb r0, [r7, #2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080C550A
	b _080C550E
_080C54FA:
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r1, [r7, #2]
	adds r0, r0, r1
	cmp r0, #0
	blt _080C550E
_080C550A:
	asrs r0, r0, #2
	b _080C5514
_080C550E:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C5514:
	strh r0, [r5, #0x32]
	mov r0, r8
	adds r0, #0x4e
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrb r4, [r6, #3]
	adds r3, r0, r4
	mov r0, sl
	ands r3, r0
	ldrh r2, [r5, #0x2c]
	ldr r1, _080C5550 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	mov r4, sl
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	adds r4, r7, #0
	mov ip, r1
	cmp r0, #0
	blt _080C5554
	asrs r2, r0, #0xc
	b _080C555A
	.align 2, 0
_080C5550: .4byte gSineTable
_080C5554:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C555A:
	movs r1, #0x97
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r5]
	ldrh r1, [r4]
	mov r2, sl
	ands r3, r2
	lsls r0, r3, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C5580
	asrs r1, r0, #0xc
	b _080C5586
_080C5580:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C5586:
	movs r4, #0x97
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _080C55E0
	ldr r0, _080C5640 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r4, #0
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C55AE
	rsbs r1, r1, #0
_080C55AE:
	cmp r1, #0x5f
	bgt _080C55E0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080C55C2
	rsbs r0, r0, #0
_080C55C2:
	cmp r0, #0x5f
	bgt _080C55E0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r6, r3
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	movs r4, #1
	str r4, [sp, #4]
_080C55E0:
	adds r5, #0x50
	adds r7, #0x50
	movs r0, #0x50
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	cmp r2, #0
	blt _080C55F6
	b _080C54E2
_080C55F6:
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x51
	bls _080C5664
	movs r4, #0
	ldrb r0, [r6, #6]
	cmp r0, #0
	bne _080C5652
	ldr r0, _080C5640 @ =0x03002BE0
	ldr r3, [r0]
	movs r5, #0x30
	ldrsh r1, [r3, r5]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r2, [r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	movs r5, #0xc0
	lsls r5, r5, #2
	adds r0, r0, r5
	cmp r1, r0
	bge _080C5652
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _080C5644
	movs r0, #0x2c
	ldrsh r1, [r3, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _080C5652
	b _080C5656
	.align 2, 0
_080C5640: .4byte 0x03002BE0
_080C5644:
	movs r5, #0x2c
	ldrsh r1, [r3, r5]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _080C5652
	movs r4, #1
_080C5652:
	cmp r4, #0
	beq _080C565C
_080C5656:
	movs r0, #0
	strh r0, [r6, #4]
	b _080C5664
_080C565C:
	ldr r1, _080C5674 @ =FUN_080c5678
	adds r0, r6, #0
	bl FUN_080c52e0
_080C5664:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5674: .4byte FUN_080c5678
