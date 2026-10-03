	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C604
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0xa8
_0804C5F0:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x20
	adds r2, r6, #0
	movs r3, #4
	bl rfu_setRecvBuffer
	adds r4, #1
	cmp r4, #3
	ble _0804C5F0
_0804C604:
	movs r2, #0x96
	lsls r2, r2, #2
	ldr r3, _0804C634 @ =0x08251D40
	movs r0, #1
	movs r1, #0
	bl rfu_LMAN_establishConnection
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _0804C638
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	subs r0, #2
	b _0804C648
	.align 2, 0
_0804C634: .4byte 0x08251D40
_0804C638:
	movs r1, #7
	strb r2, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r2, [r5, #0x44]
	adds r2, r5, #0
	adds r2, #0x32
	movs r1, #1
	strb r1, [r2]
_0804C648:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
