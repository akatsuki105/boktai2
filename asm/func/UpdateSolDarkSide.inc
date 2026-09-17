	push {r4, lr}
	ldr r2, _0823D54C @ =0x030046A0
	ldr r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0823D4FE
	movs r0, #1
	str r0, [r1]
_0823D4FE:
	ldr r0, [r2]
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _0823D510
	movs r0, #1
	str r0, [r1]
_0823D510:
	ldr r0, [r2]
	adds r1, r0, r3
	adds r0, r0, r4
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	cmp r1, #0
	bne _0823D522
	movs r1, #1
_0823D522:
	lsls r0, r0, #7
	bl Div
	movs r1, #0
	cmp r0, #0x46
	bgt _0823D536
	movs r1, #1
	cmp r0, #0x3a
	ble _0823D536
	movs r1, #2
_0823D536:
	ldr r0, _0823D54C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823D54C: .4byte 0x030046A0
