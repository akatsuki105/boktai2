	push {r4, r5, lr}
	ldr r0, _0823DD80 @ =0x0300481C
	ldr r0, [r0]
	cmp r0, #0
	bne _0823DD5E
	bl FUN_0823e768
_0823DD5E:
	ldr r5, _0823DD84 @ =gClock
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823DD72
	adds r3, #0x18
_0823DD72:
	cmp r4, #0
	bge _0823DD8C
	cmp r3, #0
	ble _0823DD88
	subs r3, #1
	b _0823DD8A
	.align 2, 0
_0823DD80: .4byte 0x0300481C
_0823DD84: .4byte gClock
_0823DD88:
	movs r3, #0x17
_0823DD8A:
	adds r4, #0x3c
_0823DD8C:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823DD9E
	adds r2, #0x18
_0823DD9E:
	cmp r1, #0
	bge _0823DDAE
	cmp r2, #0
	ble _0823DDAA
	subs r2, #1
	b _0823DDAC
_0823DDAA:
	movs r2, #0x17
_0823DDAC:
	adds r1, #0x3c
_0823DDAE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823DDC8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823DDCC
_0823DDC8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823DDCC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823DE32
	lsls r0, r0, #2
	ldr r1, _0823DDE4 @ =_0823DDE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823DDE4: .4byte _0823DDE8
_0823DDE8: @ jump table
	.4byte _0823DE00 @ case 0
	.4byte _0823DE0C @ case 1
	.4byte _0823DE2E @ case 2
	.4byte _0823DE1A @ case 3
	.4byte _0823DE24 @ case 4
	.4byte _0823DE2E @ case 5
_0823DE00:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823DE30
_0823DE0C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823DE30
_0823DE1A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DE30
_0823DE24:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DE30
_0823DE2E:
	movs r0, #0
_0823DE30:
	strb r0, [r5, #0xf]
_0823DE32:
	pop {r4, r5}
	pop {r0}
	bx r0
