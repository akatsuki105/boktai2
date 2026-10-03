	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _08047354 @ =0x030000C0
	ldr r0, [r0]
	str r0, [sp, #0x20]
	cmp r0, #0
	beq _0804734E
	ldr r0, [sp, #0x20]
	bl EntityAB4E_FindFreeElem
	adds r7, r0, #0
	cmp r7, #0
	bne _08047358
_0804734E:
	movs r0, #1
	rsbs r0, r0, #0
	b _080476F6
	.align 2, 0
_08047354: .4byte 0x030000C0
_08047358:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r4, #0
	strh r0, [r7]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r7, #2]
	movs r0, #0x6d
	movs r1, #2
	bl VM_GetNamedArgValue
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r4, [r7, #0x10]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r7, #7]
	movs r0, #0x68
	movs r1, #4
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	bl FUN_08045530
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0xb4
	strh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080473F8
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080473F0 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080473F4 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl VM_GetValue
	adds r6, r0, #0
	b _08047420
	.align 2, 0
_080473F0: .4byte 0xFFFF0000
_080473F4: .4byte 0x0000FFFF
_080473F8:
	ldr r0, _0804745C @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08047460 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08047464 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r6, #0
_08047420:
	movs r0, #0x74
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _08047468
	movs r0, #1
	strb r0, [r7, #0x1f]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x25
	strb r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x26
	strb r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x27
	strb r0, [r1]
	b _08047484
	.align 2, 0
_0804745C: .4byte 0x030046A0
_08047460: .4byte 0xFFFF0000
_08047464: .4byte 0x0000FFFF
_08047468:
	strb r2, [r7, #0x1f]
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #9
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0x26
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x27
	strb r2, [r0]
_08047484:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804749A
	bl VM_GetValue
	str r0, [r7, #0x3c]
	bl VM_GetValue
	b _080474A4
_0804749A:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x3c]
	movs r0, #0x80
	lsls r0, r0, #2
_080474A4:
	str r0, [r7, #0x40]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080474D8
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x28
	strb r0, [r4]
	bl VM_GetValue
	strh r0, [r7, #0x30]
	bl VM_GetValue
	strh r0, [r7, #0x32]
	bl VM_GetValue
	strh r0, [r7, #0x34]
	bl VM_GetValue
	str r0, [r7, #0x38]
	mov sb, r4
	b _080474EE
_080474D8:
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #0xff
	strb r0, [r1]
	strh r2, [r7, #0x30]
	strh r2, [r7, #0x32]
	movs r0, #8
	strh r0, [r7, #0x34]
	movs r0, #0xc
	str r0, [r7, #0x38]
	mov sb, r1
_080474EE:
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08047516
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x29
	strb r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x2a
	strb r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x2b
	b _08047528
_08047516:
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #1
_08047528:
	strb r0, [r1]
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08047572
	movs r5, #0
	movs r0, #0x60
	adds r0, r0, r7
	mov sl, r0
	lsls r4, r6, #0x18
	add r6, sp, #0x18
	movs r1, #0x68
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x6a
	str r2, [sp, #0x24]
	adds r0, r7, #0
	adds r0, #0xa4
	str r0, [sp, #0x28]
	b _08047564
_08047554:
	bl VM_GetValue
	lsls r2, r5, #2
	adds r1, r7, #0
	adds r1, #0x48
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #1
_08047564:
	cmp r5, #3
	bgt _080475A4
	bl VM_GetPC
	cmp r0, #0
	bne _08047554
	b _08047590
_08047572:
	movs r5, #0
	movs r1, #0x60
	adds r1, r1, r7
	mov sl, r1
	lsls r4, r6, #0x18
	add r6, sp, #0x18
	movs r2, #0x68
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x6a
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0xa4
	str r1, [sp, #0x28]
_08047590:
	cmp r5, #3
	bgt _080475A4
	movs r1, #0
	lsls r0, r5, #2
	adds r0, #0x48
	adds r0, r0, r7
_0804759C:
	stm r0!, {r1}
	adds r5, #1
	cmp r5, #3
	ble _0804759C
_080475A4:
	ldrh r1, [r7]
	lsrs r3, r4, #0x18
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	mov r0, sl
	add r2, sp, #0x10
	bl Mover_Init
	ldr r1, _08047638 @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x12
	str r0, [sp, #0x18]
	ldr r0, [r6, #4]
	ands r0, r1
	str r0, [r6, #4]
	mov r0, sl
	adds r1, r6, #0
	bl FUN_0823b47c
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08047608
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r2, [r2]
	ldrh r3, [r7, #0x30]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrh r0, [r7, #0x32]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	mov r0, sl
	bl Mover_SetPath
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	mov r0, r8
	movs r2, #0
	bl FUN_08234f80
	adds r0, r7, #0
	bl FUN_080453b0
_08047608:
	movs r0, #0
	strb r0, [r7, #0xc]
	mov r5, r8
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08047632
	cmp r1, #0
	blt _08047632
	ldr r0, _0804763C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08047632
	ldr r0, _08047640 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08047644
_08047632:
	movs r4, #0
	b _08047652
	.align 2, 0
_08047638: .4byte 0xFFFF0000
_0804763C: .4byte 0x030046A8
_08047640: .4byte 0x030046AC
_08047644:
	ldr r0, _08047664 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08047652:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08047668
	adds r0, #4
	b _08047674
	.align 2, 0
_08047664: .4byte 0x030046A4
_08047668:
	ldr r0, _08047688 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08047674:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0804768C
	cmp r2, #2
	beq _08047690
	b _08047694
	.align 2, 0
_08047688: .4byte 0x030046A4
_0804768C:
	ldrb r0, [r5, #4]
	b _08047692
_08047690:
	ldrb r0, [r5]
_08047692:
	subs r1, r1, r0
_08047694:
	movs r6, #0
	movs r5, #0
	ldr r2, [sp, #0x24]
	strh r1, [r2]
	strb r6, [r7, #0x1b]
	ldr r0, [sp, #0x20]
	ldr r1, _08047708 @ =0x0000192C
	adds r4, r0, r1
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r1, _0804770C @ =0x085AB404
	ldrb r0, [r7, #7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	str r5, [sp]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	mov r0, sl
	bl FUN_08002a48
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #1
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Show
	strb r6, [r7, #8]
	movs r1, #1
	strb r1, [r7, #9]
_080476F6:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047708: .4byte 0x0000192C
_0804770C: .4byte 0x085AB404
