	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _0806923C
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0
	bl FUN_08060b84
_0806923C:
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _08069260
	ldr r6, _08069284 @ =0x000003CE
	adds r0, r5, r6
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	beq _080692CC
_08069260:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x10
	bl FUN_08066ee4
	str r0, [sp, #0x14]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806928C
	ldr r4, _08069288 @ =0x000003A7
	adds r0, r5, r4
	b _08069292
	.align 2, 0
_08069284: .4byte 0x000003CE
_08069288: .4byte 0x000003A7
_0806928C:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
_08069292:
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080692C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r7, [r0, r4]
	mov sl, r7
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r6, [r0, r7]
	mov sb, r6
	movs r0, #0
	str r0, [sp, #0x10]
	movs r1, #0x40
	str r1, [sp, #0xc]
	b _08069448
	.align 2, 0
_080692C8: .4byte 0x085B0A08
_080692CC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x11
	bl FUN_08066ee4
	str r0, [sp, #0x14]
	adds r0, r5, #0
	bl FUN_08068c6c
	adds r4, r0, #0
	movs r6, #1
	str r6, [sp, #0x10]
	adds r0, r5, #0
	bl FUN_08067068
	movs r7, #0xba
	lsls r7, r7, #2
	adds r1, r5, r7
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08069344
	movs r2, #0x20
	str r2, [sp, #0xc]
	ldr r4, _0806933C @ =0x000003A7
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08069340 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r6, [r0, r7]
	mov sl, r6
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	b _08069448
	.align 2, 0
_0806933C: .4byte 0x000003A7
_08069340: .4byte 0x085B0A08
_08069344:
	cmp r4, #8
	bne _0806934E
	movs r6, #0x40
	str r6, [sp, #0xc]
	b _0806936A
_0806934E:
	cmp r4, #7
	bgt _0806935E
	movs r0, #8
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, #0x40
	str r0, [sp, #0xc]
	b _0806936A
_0806935E:
	adds r0, r4, #0
	subs r0, #8
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [sp, #0xc]
_0806936A:
	movs r7, #0xba
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080693B4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r6, [r0, r7]
	mov sl, r6
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08069448
	mov r0, sl
	muls r0, r4, r0
	cmp r0, #0
	blt _080693B8
	asrs r0, r0, #0xc
	b _080693BE
	.align 2, 0
_080693B4: .4byte 0x085B0A08
_080693B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080693BE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	mov r0, sb
	muls r0, r4, r0
	cmp r0, #0
	blt _080693CE
	asrs r0, r0, #0xc
	b _080693D4
_080693CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080693D4:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r4, _080693F8 @ =0x000001C7
	adds r1, r5, r4
	ldrb r1, [r1]
	cmp r1, #1
	bne _08069416
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080693FC
	movs r6, #0x38
	ldrsh r1, [r5, r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08069408
	b _0806940C
	.align 2, 0
_080693F8: .4byte 0x000001C7
_080693FC:
	movs r7, #0x38
	ldrsh r1, [r5, r7]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _0806940C
_08069408:
	asrs r0, r0, #6
	b _08069412
_0806940C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08069412:
	strh r0, [r5, #0x38]
	b _08069448
_08069416:
	cmp r1, #2
	bne _08069448
	movs r1, #0x34
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08069430
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0806943C
	b _08069440
_08069430:
	movs r4, #0x34
	ldrsh r1, [r5, r4]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08069440
_0806943C:
	asrs r0, r0, #6
	b _08069446
_08069440:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08069446:
	strh r0, [r5, #0x34]
_08069448:
	ldr r6, [sp, #0x10]
	cmp r6, #0
	bne _08069450
	b _080695B2
_08069450:
	ldr r7, _080694B8 @ =0x00000292
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0806945E
	b _080695B2
_0806945E:
	adds r2, r5, #0
	adds r2, #0x9c
	ldrh r1, [r2]
	movs r0, #3
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _08069470
	b _080695B2
_08069470:
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806947C
	b _080695B2
_0806947C:
	ldr r2, _080694BC @ =0x00000446
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r6, #0
	mov r8, r0
	cmp r1, #0
	beq _08069496
	ldr r4, _080694C0 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _08069496
	movs r6, #1
_08069496:
	cmp r6, #0
	beq _0806949C
	b _080695B2
_0806949C:
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	cmp r0, #0
	beq _080694D2
	ldrh r0, [r7]
	cmp r0, #0
	bne _080694C8
	str r4, [sp]
	str r6, [sp, #4]
	ldr r0, _080694C4 @ =0x00000163
	b _08069516
	.align 2, 0
_080694B8: .4byte 0x00000292
_080694BC: .4byte 0x00000446
_080694C0: .4byte 0x00000442
_080694C4: .4byte 0x00000163
_080694C8:
	str r4, [sp]
	str r6, [sp, #4]
	movs r0, #0xb1
	lsls r0, r0, #1
	b _08069516
_080694D2:
	movs r6, #0xe5
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	bl FUN_08065a98
	cmp r0, #0
	beq _0806952C
	mov r1, r8
	ldrh r0, [r1]
	movs r1, #0
	cmp r0, #0
	beq _080694F8
	ldr r2, _0806950C @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080694F8
	movs r1, #1
_080694F8:
	cmp r1, #0
	bne _0806952C
	ldrh r0, [r7]
	cmp r0, #0
	bne _08069510
	str r4, [sp]
	str r1, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _08069516
	.align 2, 0
_0806950C: .4byte 0x00000442
_08069510:
	str r4, [sp]
	str r1, [sp, #4]
	ldr r0, _08069528 @ =0x00000193
_08069516:
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _080695B2
	.align 2, 0
_08069528: .4byte 0x00000193
_0806952C:
	movs r6, #0xe4
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08069542
	ldr r1, _08069550 @ =0x000001C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806955C
_08069542:
	ldrh r0, [r7]
	cmp r0, #0
	bne _08069554
	movs r0, #0xca
	bl PlaySound_082406e0
	b _08069576
	.align 2, 0
_08069550: .4byte 0x000001C7
_08069554:
	movs r0, #0xc9
	bl PlaySound_082406e0
	b _08069576
_0806955C:
	ldrh r0, [r7]
	cmp r0, #0
	bne _08069570
	ldr r0, _0806956C @ =0x0000028E
	bl PlaySound_082406e0
	b _08069576
	.align 2, 0
_0806956C: .4byte 0x0000028E
_08069570:
	ldr r0, _0806958C @ =0x0000028D
	bl PlaySound_082406e0
_08069576:
	movs r1, #1
	ldr r0, _08069590 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08069594 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08069598
	movs r0, #1
	b _0806959A
	.align 2, 0
_0806958C: .4byte 0x0000028D
_08069590: .4byte 0x030046A0
_08069594: .4byte 0x00000934
_08069598:
	movs r0, #0
_0806959A:
	cmp r0, #0
	beq _080695B2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_080695B2:
	adds r0, r5, #0
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0xc]
	bl FUN_08060a24
	ldr r4, [sp, #0x10]
	cmp r4, #0
	bne _080695CE
	movs r6, #0xe9
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080695DA
_080695CE:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	movs r3, #0x96
	bl FUN_08068e94
_080695DA:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
