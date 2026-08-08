	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08234618 @ =0x0000DCFB
	bl FUN_082310cc
	ldr r1, _0823461C @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0xc]
	ldr r1, _08234620 @ =0x0300077C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08234618: .4byte 0x0000DCFB
_0823461C: .4byte 0x030046A4
_08234620: .4byte 0x0300077C
