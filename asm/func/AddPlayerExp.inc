	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _0807A7EC @ =0x030046A0
	ldr r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r3, r0, #0
	cmp r1, #5
	beq _0807A7E4
	ldr r0, _0807A7F0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807A7D0
	movs r1, #0x80
	lsls r1, r1, #4
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807A7D0
	lsls r0, r2, #1
	adds r0, r0, r2
	asrs r2, r0, #1
_0807A7D0:
	ldr r0, [r3]
	ldr r1, [r0, #0x50]
	adds r1, r1, r2
	str r1, [r0, #0x50]
	ldr r0, _0807A7F4 @ =0x000F423E
	cmp r1, r0
	ble _0807A7E4
	ldr r1, [r3]
	adds r0, #1
	str r0, [r1, #0x50]
_0807A7E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A7EC: .4byte 0x030046A0
_0807A7F0: .4byte 0x03002BE0
_0807A7F4: .4byte 0x000F423E
