	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08058262
	movs r0, #0
	strb r0, [r4, #8]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r0, _08058280 @ =0x00000EBC
	add r0, r8
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x28
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x2c
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xd]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r2, r1, #0
	strb r1, [r4, #5]
	adds r5, r4, #0
	adds r5, #0x78
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r3, #0
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08058248
	movs r3, #1
_08058248:
	movs r0, #0
	cmp r2, #1
	bls _08058250
	movs r0, #1
_08058250:
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	movs r1, #0x10
	bl AuxAnim_SetAnimSpeed
_08058262:
	ldr r2, _08058284 @ =gSineTable
	ldr r0, [r4, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r6, r2, #0
	cmp r0, #0
	blt _08058288
	asrs r0, r0, #0xc
	b _0805828E
	.align 2, 0
_08058280: .4byte 0x00000EBC
_08058284: .4byte gSineTable
_08058288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805828E:
	adds r2, r0, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r5, [r4, #0xd]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080582B0
	asrs r1, r0, #0xc
	b _080582B6
_080582B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080582B6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080582CE
	asrs r0, r0, #0xc
	b _080582D4
_080582CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080582D4:
	strh r0, [r3, #4]
	ldr r0, [r4, #0x14]
	subs r0, #8
	cmp r0, #7
	bhi _080582E6
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
_080582E6:
	ldrh r0, [r4, #0x20]
	ldrh r3, [r4, #0x28]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	ldr r2, _0805833C @ =0xFFFF0000
	ldrh r1, [r4, #0x22]
	ldrh r3, [r4, #0x2a]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	ldrh r1, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	add r6, sp, #4
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058338
	cmp r1, #0
	blt _08058338
	ldr r0, _08058340 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058338
	ldr r0, _08058344 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058348
_08058338:
	movs r5, #0
	b _08058356
	.align 2, 0
_0805833C: .4byte 0xFFFF0000
_08058340: .4byte 0x030046A8
_08058344: .4byte 0x030046AC
_08058348:
	ldr r0, _08058368 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08058356:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805836C
	adds r0, #4
	b _08058378
	.align 2, 0
_08058368: .4byte 0x030046A4
_0805836C:
	ldr r0, _080583AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058378:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08058412
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080583A6
	cmp r1, #0
	blt _080583A6
	ldr r0, _080583B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080583A6
	ldr r0, _080583B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080583B8
_080583A6:
	movs r5, #0
	b _080583C6
	.align 2, 0
_080583AC: .4byte 0x030046A4
_080583B0: .4byte 0x030046A8
_080583B4: .4byte 0x030046AC
_080583B8:
	ldr r0, _080583D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080583C6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080583DC
	adds r0, #4
	b _080583E8
	.align 2, 0
_080583D8: .4byte 0x030046A4
_080583DC:
	ldr r0, _080583FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080583E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058400
	cmp r2, #2
	beq _08058404
	b _08058408
	.align 2, 0
_080583FC: .4byte 0x030046A4
_08058400:
	ldrb r0, [r6, #4]
	b _08058406
_08058404:
	ldrb r0, [r6]
_08058406:
	subs r1, r1, r0
_08058408:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08058414
_08058412:
	movs r2, #1
_08058414:
	cmp r2, #0
	beq _08058420
	movs r2, #0
	mov r3, r8
	ldr r1, [r3, #0x30]
	b _0805843A
_08058420:
	add r0, sp, #4
	ldrh r0, [r0]
	strh r0, [r7, #0x1c]
	add r1, sp, #4
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x1e]
	ldrh r0, [r1, #4]
	strh r0, [r7, #0x20]
	ldr r0, [r4, #0x14]
	cmp r0, #0x1f
	bls _0805844E
	mov r0, r8
	ldr r1, [r0, #0x30]
_0805843A:
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	b _08058452
_0805844E:
	adds r0, #1
	str r0, [r4, #0x14]
_08058452:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
