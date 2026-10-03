	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r6, _0804B4EC @ =0x085AB5B0
_0804B4C8:
	movs r3, #0
	movs r2, #0
	lsls r0, r4, #1
	adds r1, r0, r6
_0804B4D0:
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r7, [r1]
	cmp r0, r7
	bne _0804B4DC
	adds r3, #1
_0804B4DC:
	adds r1, #1
	adds r2, #1
	cmp r2, #1
	ble _0804B4D0
	cmp r3, #2
	bne _0804B4F0
	adds r0, r4, #0
	b _0804B4FA
	.align 2, 0
_0804B4EC: .4byte 0x085AB5B0
_0804B4F0:
	adds r4, #1
	cmp r4, #3
	ble _0804B4C8
	movs r0, #1
	rsbs r0, r0, #0
_0804B4FA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
