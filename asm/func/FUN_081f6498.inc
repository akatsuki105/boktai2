	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r6, #1
	mov r5, sp
	movs r0, #2
	mov sl, r0
	ldr r1, _081F64DC @ =gSineTable
	mov r8, r1
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r7, r0
	mov sb, r8
_081F64BA:
	ldrb r0, [r4]
	adds r0, #2
	strb r0, [r4]
	ldrb r2, [r4]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081F64E0
	asrs r1, r0, #0xc
	b _081F64E6
	.align 2, 0
_081F64DC: .4byte gSineTable
_081F64E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F64E6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r2, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081F6502
	asrs r0, r0, #0xc
	b _081F6508
_081F6502:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6508:
	strh r0, [r5, #4]
	adds r0, r7, #0
	mov r1, sp
	adds r2, r6, #0
	bl Entity081f73ec_SetSegVel
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #5
	ble _081F64BA
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _081F65DE
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r6, r1, #0
	cmp r3, #0
	blt _081F6578
	cmp r2, #0
	blt _081F6578
	ldr r0, _081F657C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081F6578
	ldr r0, _081F6580 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081F6584
_081F6578:
	movs r4, #0
	b _081F6592
	.align 2, 0
_081F657C: .4byte 0x030046A8
_081F6580: .4byte 0x030046AC
_081F6584:
	ldr r0, _081F65A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081F6592:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F65A8
	adds r0, #4
	b _081F65B4
	.align 2, 0
_081F65A4: .4byte 0x030046A4
_081F65A8:
	ldr r0, _081F65C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F65B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F65CC
	cmp r2, #2
	beq _081F65D0
	b _081F65D4
	.align 2, 0
_081F65C8: .4byte 0x030046A4
_081F65CC:
	ldrb r0, [r5, #4]
	b _081F65D2
_081F65D0:
	ldrb r0, [r5]
_081F65D2:
	subs r1, r1, r0
_081F65D4:
	strh r1, [r6, #2]
	adds r0, r6, #0
	movs r1, #2
	bl Entity081f73ec_SpawnDust
_081F65DE:
	adds r0, r7, #0
	bl Entity081f73ec_ApplySegVel
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
