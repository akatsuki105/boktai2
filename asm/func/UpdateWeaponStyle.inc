	push {r4, r5, r6, lr}
	sub sp, #0x14
	movs r4, #0
	mov r6, sp
_0823D558:
	ldr r5, _0823D58C @ =0x030046A0
	ldr r1, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0823D590 @ =0x0000D2F0
	bl Div
	stm r6!, {r0}
	adds r4, #1
	cmp r4, #4
	ble _0823D558
	movs r0, #0
	movs r1, #5
	movs r4, #0
	mov r3, sp
_0823D57E:
	ldr r2, [r3]
	cmp r2, r0
	ble _0823D594
	adds r0, r2, #0
	adds r1, r4, #0
	b _0823D59A
	.align 2, 0
_0823D58C: .4byte 0x030046A0
_0823D590: .4byte 0x0000D2F0
_0823D594:
	cmp r2, r0
	bne _0823D59A
	movs r1, #5
_0823D59A:
	adds r3, #4
	adds r4, #1
	cmp r4, #4
	ble _0823D57E
	ldr r0, [r5]
	ldr r2, _0823D5B4 @ =0x000002FA
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r1, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823D5B4: .4byte 0x000002FA
