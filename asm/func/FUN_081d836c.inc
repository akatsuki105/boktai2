	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D839A
	cmp r1, #0
	blt _081D839A
	ldr r0, _081D83A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D839A
	ldr r0, _081D83A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D83A8
_081D839A:
	movs r0, #0
	b _081D83B6
	.align 2, 0
_081D83A0: .4byte 0x030046A8
_081D83A4: .4byte 0x030046AC
_081D83A8:
	ldr r0, _081D8424 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D83B6:
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0xd4
	ldrb r1, [r0]
	mov sb, r0
	adds r7, r6, #0
	adds r7, #0xd6
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r1, #0
	beq _081D83F6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0x8c
	bl ParticleShadow_Show
	movs r1, #0
	movs r0, #0
	strh r0, [r7]
	mov r2, sb
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0xd5
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x20
	bl AuxAnim_SetAnimSpeed
_081D83F6:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8428
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D8430
	.align 2, 0
_081D8424: .4byte 0x030046A4
_081D8428:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8430:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8454
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D845C
_081D8454:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D845C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8494 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D84CC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8498
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D848C
	ldrb r0, [r4, #5]
_081D848C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D84A8
	.align 2, 0
_081D8494: .4byte 0x0000FFFF
_081D8498:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D84A8
	strh r1, [r4, #8]
_081D84A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081D84CC
	movs r0, #1
	strb r0, [r4, #7]
_081D84CC:
	ldrh r0, [r6, #0x1e]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6, #0x1e]
	adds r4, r6, #0
	adds r4, #0x3c
	adds r5, r6, #0
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	mov r0, r8
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081D84FC
	adds r0, #4
	b _081D850A
_081D84FC:
	ldr r0, _081D8520 @ =0x030046A4
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D850A:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081D8524
	cmp r3, #2
	beq _081D8528
	b _081D852C
	.align 2, 0
_081D8520: .4byte 0x030046A4
_081D8524:
	ldrb r0, [r5, #4]
	b _081D852A
_081D8528:
	ldrb r0, [r5]
_081D852A:
	subs r2, r2, r0
_081D852C:
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bgt _081D854C
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r1, _081D8548 @ =FUN_081d85a8
	str r1, [r0]
	strh r2, [r6, #0x1e]
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
	b _081D8552
	.align 2, 0
_081D8548: .4byte FUN_081d85a8
_081D854C:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_081D8552:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
