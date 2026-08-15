	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r1
	mov sb, r2
	adds r4, r3, #0
	ldr r5, [sp, #0x24]
	bl GetBCDDate
	ldr r7, _0823E08C @ =gClock
	str r0, [r7]
	adds r0, r6, #0
	mov r1, r8
	mov r2, sb
	bl FUN_0823daa4
	movs r1, #0
	strb r0, [r7, #8]
	strb r4, [r7, #4]
	strb r5, [r7, #5]
	add r0, sp, #0x28
	ldrb r0, [r0]
	strb r0, [r7, #6]
	strb r1, [r7, #7]
	ldr r2, [sp, #0x2c]
	cmp r2, #1
	bne _0823E090
	ldrb r3, [r7, #4]
	ldrb r0, [r7, #5]
	str r0, [sp]
	ldrb r0, [r7, #6]
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	mov r2, sb
	bl SetGameDateTimeIntoRTC
	adds r6, r0, #0
	b _0823E092
	.align 2, 0
_0823E08C: .4byte gClock
_0823E090:
	movs r6, #1
_0823E092:
	ldr r5, _0823E0B4 @ =gClock
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823E0A6
	adds r3, #0x18
_0823E0A6:
	cmp r4, #0
	bge _0823E0BC
	cmp r3, #0
	ble _0823E0B8
	subs r3, #1
	b _0823E0BA
	.align 2, 0
_0823E0B4: .4byte gClock
_0823E0B8:
	movs r3, #0x17
_0823E0BA:
	adds r4, #0x3c
_0823E0BC:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823E0CE
	adds r2, #0x18
_0823E0CE:
	cmp r1, #0
	bge _0823E0DE
	cmp r2, #0
	ble _0823E0DA
	subs r2, #1
	b _0823E0DC
_0823E0DA:
	movs r2, #0x17
_0823E0DC:
	adds r1, #0x3c
_0823E0DE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823E0F8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823E0FC
_0823E0F8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823E0FC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823E162
	lsls r0, r0, #2
	ldr r1, _0823E114 @ =_0823E118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823E114: .4byte _0823E118
_0823E118: @ jump table
	.4byte _0823E130 @ case 0
	.4byte _0823E13C @ case 1
	.4byte _0823E15E @ case 2
	.4byte _0823E14A @ case 3
	.4byte _0823E154 @ case 4
	.4byte _0823E15E @ case 5
_0823E130:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823E160
_0823E13C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823E160
_0823E14A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823E160
_0823E154:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823E160
_0823E15E:
	movs r0, #0
_0823E160:
	strb r0, [r5, #0xf]
_0823E162:
	adds r0, r6, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
