	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0823DE80 @ =gClock
	strb r3, [r2, #0xa]
	strb r1, [r2, #0xb]
	ldr r0, _0823DE84 @ =gUnkPtr_030047a8
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	cmp r0, #0
	beq _0823DE5E
	adds r0, r3, #1
	strb r0, [r2, #0xa]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _0823DE5E
	adds r0, r3, #0
	subs r0, #0x17
	strb r0, [r2, #0xa]
_0823DE5E:
	adds r5, r2, #0
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823DE72
	adds r3, #0x18
_0823DE72:
	cmp r4, #0
	bge _0823DE8C
	cmp r3, #0
	ble _0823DE88
	subs r3, #1
	b _0823DE8A
	.align 2, 0
_0823DE80: .4byte gClock
_0823DE84: .4byte gUnkPtr_030047a8
_0823DE88:
	movs r3, #0x17
_0823DE8A:
	adds r4, #0x3c
_0823DE8C:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823DE9E
	adds r2, #0x18
_0823DE9E:
	cmp r1, #0
	bge _0823DEAE
	cmp r2, #0
	ble _0823DEAA
	subs r2, #1
	b _0823DEAC
_0823DEAA:
	movs r2, #0x17
_0823DEAC:
	adds r1, #0x3c
_0823DEAE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823DEC8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823DECC
_0823DEC8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823DECC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823DF32
	lsls r0, r0, #2
	ldr r1, _0823DEE4 @ =_0823DEE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823DEE4: .4byte _0823DEE8
_0823DEE8: @ jump table
	.4byte _0823DF00 @ case 0
	.4byte _0823DF0C @ case 1
	.4byte _0823DF2E @ case 2
	.4byte _0823DF1A @ case 3
	.4byte _0823DF24 @ case 4
	.4byte _0823DF2E @ case 5
_0823DF00:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823DF30
_0823DF0C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823DF30
_0823DF1A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DF30
_0823DF24:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DF30
_0823DF2E:
	movs r0, #0
_0823DF30:
	strb r0, [r5, #0xf]
_0823DF32:
	pop {r4, r5}
	pop {r0}
	bx r0
