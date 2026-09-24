	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_081d1260
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
	beq _081D131E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D1326
_081D131E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D1326:
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
	beq _081D134A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D1352
_081D134A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1352:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D138C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D13D2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D1396
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1390
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D13AC
	.align 2, 0
_081D138C: .4byte 0x0000FFFF
_081D1390:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D13AA
_081D1396:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D13AA
	strh r1, [r4, #8]
	movs r2, #1
	b _081D13AC
_081D13AA:
	movs r2, #0
_081D13AC:
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
	bne _081D13D4
	movs r0, #1
	strb r0, [r4, #7]
	b _081D13D4
_081D13D2:
	movs r2, #0
_081D13D4:
	cmp r2, #0
	beq _081D145E
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1406
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x18]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d0e74
	b _081D1424
_081D1406:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x18]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d0e74
_081D1424:
	adds r1, r5, #0
	adds r1, #0xb0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc6
	strb r2, [r0]
	subs r0, #8
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	str r0, [sp, #8]
	add r1, sp, #0xc
	add r0, sp, #4
	str r0, [r1, #4]
	ldr r2, _081D1468 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r2, #2
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	bl Script_ExecById
_081D145E:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D1468: .4byte 0xFFFF0000
