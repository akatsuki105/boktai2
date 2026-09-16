	push {r4, r5, lr}
	movs r4, #0
	movs r3, #0x64
	rsbs r3, r3, #0
	movs r2, #0
	ldr r0, _0823D5E8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0823D5EC @ =0x000002FE
	adds r0, r0, r1
_0823D5CA:
	movs r5, #0
	ldrsh r1, [r0, r5]
	cmp r1, r3
	ble _0823D5D6
	adds r3, r1, #0
	adds r4, r2, #0
_0823D5D6:
	adds r0, #2
	adds r2, #1
	cmp r2, #4
	ble _0823D5CA
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D5E8: .4byte 0x030046A0
_0823D5EC: .4byte 0x000002FE
