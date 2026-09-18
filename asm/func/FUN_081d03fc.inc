	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r7, #0
	ldr r0, _081D0480 @ =0x03000188
	ldr r1, [r0]
	adds r0, r7, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0x1e
	bgt _081D0418
	b _081D0552
_081D0418:
	adds r5, r7, #0
	adds r5, #0xba
	ldrb r0, [r5]
	movs r2, #0x70
	adds r2, r2, r7
	mov r8, r2
	cmp r0, #0
	beq _081D0452
	ldr r1, [r1, #0x18]
	adds r4, r7, #0
	adds r4, #0xb0
	ldrb r3, [r4]
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	bl FUN_08237040
	movs r0, #0
	strb r0, [r5]
	ldrh r0, [r4]
	cmp r0, #1
	bgt _081D0452
	cmp r0, #0
	blt _081D0452
	movs r0, #0xd6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D0452:
	mov r4, r8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x70]
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
	beq _081D0484
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D048C
	.align 2, 0
_081D0480: .4byte 0x03000188
_081D0484:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D048C:
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
	beq _081D04B0
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D04B8
_081D04B0:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D04B8:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D04F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D0536
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D04FA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D04F4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D0510
	.align 2, 0
_081D04F0: .4byte 0x0000FFFF
_081D04F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D050E
_081D04FA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D050E
	strh r1, [r4, #8]
	movs r2, #1
	b _081D0510
_081D050E:
	movs r2, #0
_081D0510:
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
	bne _081D0538
	movs r0, #1
	strb r0, [r4, #7]
	b _081D0538
_081D0536:
	movs r2, #0
_081D0538:
	cmp r2, #0
	beq _081D0562
	ldr r0, [r6]
	movs r2, #1
	orrs r0, r2
	str r0, [r6]
	adds r0, r7, #0
	adds r0, #0xb6
	movs r1, #0
	strh r2, [r0]
	adds r0, #6
	str r1, [r0]
	b _081D056C
_081D0552:
	adds r0, r7, #0
	adds r0, #0x78
	ldrh r0, [r0]
	cmp r0, #1
	bne _081D0562
	adds r0, r7, #0
	bl FUN_081cfa24
_081D0562:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081D056C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
