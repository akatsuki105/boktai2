	ldr r1, _0807A8FC @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _0807A900 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr
	.align 2, 0
_0807A8FC: .4byte 0x0000038E
_0807A900: .4byte 0x030046A0
