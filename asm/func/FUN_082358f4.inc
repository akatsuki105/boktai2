	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08235910 @ =0x0000F63B
	bl FUN_082310cc
	adds r1, r0, #0
	ldr r0, _08235914 @ =0x030046A4
	ldr r0, [r0]
	str r1, [r0, #0x14]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08235910: .4byte 0x0000F63B
_08235914: .4byte 0x030046A4
