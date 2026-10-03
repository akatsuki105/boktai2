	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0804f820
	adds r5, r0, #0
	cmp r5, #0
	beq _0804F8E4
	adds r3, r5, #0
	adds r3, #0x48
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _0804F8E4
	lsls r0, r0, #2
	ldr r1, _0804F850 @ =_0804F854
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F850: .4byte _0804F854
_0804F854: @ jump table
	.4byte _0804F86C @ case 0
	.4byte _0804F878 @ case 1
	.4byte _0804F87C @ case 2
	.4byte _0804F8A2 @ case 3
	.4byte _0804F8A6 @ case 4
	.4byte _0804F8C6 @ case 5
_0804F86C:
	ldr r0, [r4, #4]
	strb r0, [r3, #4]
	ldr r0, [r4, #4]
	lsrs r0, r0, #8
	strb r0, [r3, #5]
	b _0804F8E4
_0804F878:
	movs r1, #2
	b _0804F8DE
_0804F87C:
	movs r6, #0
	ldrh r0, [r4, #6]
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #6]
	ldrh r4, [r4, #4]
	movs r2, #0
	movs r7, #0xf
_0804F88C:
	adds r1, r3, r2
	adds r0, r4, #0
	asrs r0, r6
	ands r0, r7
	strb r0, [r1]
	adds r2, #1
	adds r6, #4
	cmp r2, #3
	ble _0804F88C
	movs r1, #8
	b _0804F8DE
_0804F8A2:
	movs r1, #0x20
	b _0804F8DE
_0804F8A6:
	ldrh r0, [r4, #4]
	str r0, [r3, #8]
	ldrh r0, [r4, #6]
	movs r1, #3
	ands r0, r1
	movs r1, #0
	strb r0, [r3, #7]
	cmp r0, #1
	bne _0804F8BC
	strb r1, [r3, #5]
	b _0804F8C2
_0804F8BC:
	cmp r0, #2
	bne _0804F8C2
	strb r1, [r3, #4]
_0804F8C2:
	movs r1, #0x80
	b _0804F8DE
_0804F8C6:
	bl FUN_0804e458
	cmp r0, #0
	bne _0804F8DA
	ldr r0, [r4, #4]
	movs r1, #3
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x2f
	strb r0, [r1]
_0804F8DA:
	movs r1, #0x80
	lsls r1, r1, #2
_0804F8DE:
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_0804F8E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
