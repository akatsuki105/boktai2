	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	str r1, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _081853FC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185400
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185402
	.align 2, 0
_081853FC: .4byte 0x0000046D
_08185400:
	movs r0, #0
_08185402:
	cmp r0, #0
	beq _08185436
	ldr r0, _08185470 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _08185474 @ =0x0000066C
	add r0, sl
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08185478 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r7, _0818547C @ =0x00000474
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08185436:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	mov r4, sp
	adds r4, #0x15
	adds r0, r6, #0
	add r1, sp, #0x14
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	mov r2, sb
	ldrb r0, [r2, #4]
	cmp r0, #3
	bhi _08185486
	mov r3, r8
	ldrh r0, [r3, #0xe]
	adds r0, #1
	ldrb r7, [r3, #7]
	cmp r0, r7
	blt _08185480
	ldrh r0, [r3, #8]
	adds r0, #1
	ldrb r1, [r3, #5]
	cmp r0, r1
	blt _0818548A
	movs r0, #0
	b _0818548A
	.align 2, 0
_08185470: .4byte 0x03002BE0
_08185474: .4byte 0x0000066C
_08185478: .4byte 0x0000FFF7
_0818547C: .4byte 0x00000474
_08185480:
	mov r2, r8
	ldrh r0, [r2, #8]
	b _0818548A
_08185486:
	mov r3, r8
	ldrh r0, [r3, #8]
_0818548A:
	ldr r4, _08185514 @ =0x085ADBFC
	lsls r3, r0, #3
	mov r7, sp
	adds r7, #0x15
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08185518 @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r5
	orrs r2, r0
	str r2, [sp, #0x18]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0818551C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r3, r3, r4
	ldrh r1, [r3, #4]
	ldrh r2, [r6, #0xc]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r3, sb
	ldrb r0, [r3, #4]
	cmp r0, #4
	bne _08185520
	ldr r1, [r6, #0x44]
	movs r2, #0
	movs r0, #2
	strb r0, [r1, #7]
	ldr r0, [r3, #0x38]
	ldrb r1, [r7]
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_080e6978
	b _081856FC
	.align 2, 0
_08185514: .4byte 0x085ADBFC
_08185518: .4byte 0xFFFF0000
_0818551C: .4byte 0x0000FFFF
_08185520:
	cmp r0, #3
	bls _08185526
	b _081856FC
_08185526:
	ldr r1, [r6, #0x44]
	movs r5, #0
	movs r0, #1
	strb r0, [r1, #7]
	mov r7, sb
	ldr r7, [r7, #0x38]
	mov sb, r7
	ldr r0, _08185558 @ =0x0000066E
	add r0, sl
	ldrb r1, [r0]
	ldr r0, [sp, #0x20]
	bl Mod
	cmp r0, #0
	beq _08185546
	b _081856DC
_08185546:
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	bne _0818555C
	movs r0, #1
	b _0818555E
	.align 2, 0
_08185558: .4byte 0x0000066E
_0818555C:
	movs r0, #0
_0818555E:
	cmp r0, #0
	bne _0818559A
	ldr r0, _08185580 @ =0x0000066C
	add r0, sl
	ldrb r2, [r0]
	ldr r0, _08185584 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, r2
	bge _0818558C
	ldr r3, _08185588 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r1, r1, r0
	b _0818558E
	.align 2, 0
_08185580: .4byte 0x0000066C
_08185584: .4byte 0x03002BE0
_08185588: .4byte 0xFFFFFF00
_0818558C:
	subs r1, r1, r2
_0818558E:
	ldr r0, _081855B0 @ =0x0000066D
	add r0, sl
	ldrb r0, [r0]
	cmp r1, r0
	bgt _0818559A
	b _081856A4
_0818559A:
	add r2, sp, #0x14
	ldrb r0, [r6, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081855B4
	asrs r0, r1, #6
	b _081855BA
	.align 2, 0
_081855B0: .4byte 0x0000066D
_081855B4:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081855BA:
	lsls r0, r0, #6
	strb r0, [r2]
	ldr r7, _08185604 @ =0x00000256
	adds r0, r6, r7
	ldrh r5, [r0]
	add r0, sp, #0x18
	mov sl, r0
	ldr r7, _08185608 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x18
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818560C
	adds r0, #4
	b _08185616
	.align 2, 0
_08185604: .4byte 0x00000256
_08185608: .4byte 0x030046A4
_0818560C:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08185616:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r5, #0
	movs r4, #0
	mov r7, sl
	strh r0, [r7, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r0, sp, #0x14
	ldrb r3, [r0]
	movs r0, #0x3c
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x18
	movs r2, #0x40
	bl Player_ReleaseGrabbed
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08185690 @ =0x00000469
	adds r0, r6, r3
	strb r5, [r0]
	ldr r7, _08185694 @ =0x0000046A
	adds r0, r6, r7
	strb r5, [r0]
	ldr r1, _08185698 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818569C @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081856A0 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	b _0818572C
	.align 2, 0
_08185690: .4byte 0x00000469
_08185694: .4byte 0x0000046A
_08185698: .4byte 0x00000484
_0818569C: .4byte Enemy_ClearStateBegun
_081856A0: .4byte 0x0000046B
_081856A4:
	adds r0, r6, #0
	bl Octopus_GetGrabbedAnimOffset
	adds r3, r0, #0
	mov r7, sp
	ldrb r0, [r7, #0x15]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, _081856D8 @ =0x00000226
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x10]
	mov r0, sb
	add r1, sp, #0x18
	movs r2, #0
	bl Player_HoldGrabbed
	b _081856FC
	.align 2, 0
_081856D8: .4byte 0x00000226
_081856DC:
	adds r0, r6, #0
	bl Octopus_GetGrabbedAnimOffset
	adds r3, r0, #0
	mov r7, sp
	ldrb r0, [r7, #0x15]
	str r0, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl Player_HoldGrabbed
_081856FC:
	adds r0, r6, #0
	movs r1, #0x12
	bl Enemy_PlayAnimFlipOnly
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #0
	bne _0818571A
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _0818571A
	movs r0, #0xef
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0818571A:
	ldr r2, [sp, #0x20]
	cmp r2, #0xb4
	ble _0818572C
	ldr r3, _0818573C @ =0x0000046B
	adds r0, r6, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6, #0x44]
	strb r1, [r0, #7]
_0818572C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818573C: .4byte 0x0000046B
