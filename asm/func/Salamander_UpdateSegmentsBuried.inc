	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
	ldr r2, _081AA490 @ =0x00000CAA
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _081AA470
	b _081AA58A
_081AA470:
	movs r2, #0
	mov sl, r2
	ldr r0, _081AA494 @ =0x00000674
	adds r6, r7, r0
	ldr r1, _081AA498 @ =0x00000705
	adds r1, r1, r7
	mov sb, r1
_081AA47E:
	movs r1, #1
	mov r2, sb
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AA49C
	movs r0, #1
	b _081AA49E
	.align 2, 0
_081AA490: .4byte 0x00000CAA
_081AA494: .4byte 0x00000674
_081AA498: .4byte 0x00000705
_081AA49C:
	movs r0, #0
_081AA49E:
	cmp r0, #0
	bne _081AA56C
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AA4C6
	cmp r1, #0
	blt _081AA4C6
	ldr r0, _081AA4CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AA4C6
	ldr r0, _081AA4D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AA4D4
_081AA4C6:
	movs r4, #0
	b _081AA4E2
	.align 2, 0
_081AA4CC: .4byte 0x030046A8
_081AA4D0: .4byte 0x030046AC
_081AA4D4:
	ldr r0, _081AA4F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AA4E2:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AA4F8
	adds r0, #4
	b _081AA504
	.align 2, 0
_081AA4F4: .4byte 0x030046A4
_081AA4F8:
	ldr r0, _081AA518 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AA504:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AA51C
	cmp r2, #2
	beq _081AA520
	b _081AA524
	.align 2, 0
_081AA518: .4byte 0x030046A4
_081AA51C:
	ldrb r0, [r5, #4]
	b _081AA522
_081AA520:
	ldrb r0, [r5]
_081AA522:
	subs r1, r1, r0
_081AA524:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _081AA54C
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _081AA546
	orrs r1, r3
	str r1, [r2]
_081AA546:
	movs r2, #1
	rsbs r2, r2, #0
	b _081AA56A
_081AA54C:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081AA568
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_081AA568:
	movs r2, #1
_081AA56A:
	add r8, r2
_081AA56C:
	movs r0, #0xd0
	add sl, r0
	adds r6, #0xd0
	add sb, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r2, _081AA59C @ =0x00000CAA
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp]
	cmp r2, r0
	bge _081AA58A
	b _081AA47E
_081AA58A:
	ldr r1, _081AA59C @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _081AA5A0
	movs r0, #1
	b _081AA5AE
	.align 2, 0
_081AA59C: .4byte 0x00000CAA
_081AA5A0:
	mov r1, r8
	cmn r1, r0
	ble _081AA5AA
	movs r0, #0
	b _081AA5AE
_081AA5AA:
	movs r0, #1
	rsbs r0, r0, #0
_081AA5AE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
