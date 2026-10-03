	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0804FEAC @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, #0
	blt _0804FEA6
	movs r3, #0
	movs r6, #1
	adds r2, r4, #0
	adds r2, #0x98
_0804FE8E:
	ldrh r0, [r2]
	cmp r0, r5
	bne _0804FE9E
	adds r1, r6, #0
	lsls r1, r3
	ldr r0, [r4, #0x74]
	bics r0, r1
	str r0, [r4, #0x74]
_0804FE9E:
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _0804FE8E
_0804FEA6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804FEAC: .4byte 0x030046A0
