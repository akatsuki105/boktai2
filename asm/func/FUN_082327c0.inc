	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _082327E8 @ =0x0000AE1B
	bl FUN_082310cc
	ldr r1, _082327EC @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #4]
	bl FUN_0823273c
	bl FUN_08232760
	bl FUN_0823279c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_082327E8: .4byte 0x0000AE1B
_082327EC: .4byte 0x030046A4
