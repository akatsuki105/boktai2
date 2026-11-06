	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F8302
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3c
	bl AuxShadow_Show
	strb r4, [r6]
_081F8302:
	ldr r4, _081F8378 @ =0x00000109
	adds r6, r5, r4
	ldrb r0, [r6]
	rsbs r0, r0, #0
	strb r0, [r5, #6]
	mov r3, sp
	adds r4, r5, #0
	adds r4, #0x1c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	mov r8, r1
	adds r0, r5, #0
	bl Entity081f8a28_TurnToTarget
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r3, [r0]
	ldr r2, _081F837C @ =gSineTable
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _081F8380
	asrs r0, r0, #0xc
	b _081F8386
	.align 2, 0
_081F8378: .4byte 0x00000109
_081F837C: .4byte gSineTable
_081F8380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F8386:
	adds r3, r5, #0
	adds r3, #0xf8
	strh r0, [r3]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r2, [r0]
	ldr r1, _081F83B0 @ =gSineTable
	subs r4, #3
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _081F83B4
	asrs r2, r0, #0xc
	b _081F83BA
	.align 2, 0
_081F83B0: .4byte gSineTable
_081F83B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F83BA:
	adds r0, r5, #0
	adds r0, #0xfc
	strh r2, [r0]
	mov r2, sp
	ldrh r0, [r6]
	ldrh r3, [r5, #0x1c]
	adds r0, r0, r3
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r6, #2]
	ldrh r4, [r7, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r1, [r6, #4]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081F8400
	cmp r1, #0
	blt _081F8400
	ldr r0, _081F8404 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F8400
	ldr r0, _081F8408 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F840C
_081F8400:
	movs r4, #0
	b _081F841A
	.align 2, 0
_081F8404: .4byte 0x030046A8
_081F8408: .4byte 0x030046AC
_081F840C:
	ldr r0, _081F842C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F841A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F8430
	adds r0, #4
	b _081F843C
	.align 2, 0
_081F842C: .4byte 0x030046A4
_081F8430:
	ldr r0, _081F8464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F843C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _081F8450
	cmp r1, #0
	bne _081F8468
_081F8450:
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	movs r4, #0x91
	lsls r4, r4, #1
	adds r1, r5, r4
	b _081F860E
	.align 2, 0
_081F8464: .4byte 0x030046A4
_081F8468:
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r7, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r7, #4]
	ldrh r6, [r6, #4]
	adds r0, r0, r6
	strh r0, [r7, #4]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081F84BC
	movs r4, #0x86
	lsls r4, r4, #1
	adds r2, r5, r4
	movs r0, #0x87
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _081F84BA
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r4, [r1]
	adds r0, r0, r4
	strh r0, [r2]
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
	b _081F84BC
_081F84BA:
	strh r1, [r2]
_081F84BC:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x3b
	ble _081F84DA
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0x28
	bls _081F84EE
	ldr r0, _081F8544 @ =0x0003FFFF
	cmp r8, r0
	bgt _081F84EE
_081F84DA:
	adds r2, r5, #0
	adds r2, #0xfa
	ldrh r0, [r2]
	subs r0, #3
	movs r1, #0
	strh r0, [r2]
	movs r3, #0x85
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
_081F84EE:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081F8506
	adds r0, r7, #0
	bl Entity081f8a28_SpawnTrail
_081F8506:
	adds r0, r5, #0
	bl Entity081f8a28_UpdateHitbox
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
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
	beq _081F8548
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F8550
	.align 2, 0
_081F8544: .4byte 0x0003FFFF
_081F8548:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F8550:
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
	beq _081F8574
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F857C
_081F8574:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F857C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F85B4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F85EC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F85B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F85AC
	ldrb r0, [r4, #5]
_081F85AC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F85C8
	.align 2, 0
_081F85B4: .4byte 0x0000FFFF
_081F85B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F85C8
	strh r1, [r4, #8]
_081F85C8:
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
	bne _081F85EC
	movs r0, #1
	strb r0, [r4, #7]
_081F85EC:
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	cmp r0, #0
	ble _081F85FE
	subs r0, #1
	str r0, [r1]
	b _081F8612
_081F85FE:
	movs r4, #0x8f
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x91
	lsls r0, r0, #1
	adds r1, r5, r0
_081F860E:
	movs r0, #1
	strb r0, [r1]
_081F8612:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
