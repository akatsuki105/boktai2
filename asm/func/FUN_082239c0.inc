	push {r4, r5, r6, lr}
	ldr r1, _082239F4 @ =0x00000DA4
	adds r5, r0, r1
	movs r2, #0
	ldrsb r2, [r5, r2]
	ldr r6, _082239F8 @ =0x00000DA5
	adds r4, r0, r6
	movs r3, #0
	ldrsb r3, [r4, r3]
	adds r2, #2
	adds r3, #2
	cmp r2, #0x7f
	ble _082239E8
	movs r3, #0x7f
	movs r2, #0x7f
	movs r6, #0xf5
	lsls r6, r6, #4
	adds r1, r0, r6
	movs r0, #0
	str r0, [r1]
_082239E8:
	strb r2, [r5]
	strb r3, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082239F4: .4byte 0x00000DA4
_082239F8: .4byte 0x00000DA5
