	mov ip, r0
	adds r0, #0xa6
	movs r3, #0
	strb r1, [r0]
	adds r0, #0x16
	str r3, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0821D858 @ =0x00000804
	add r0, ip
	strh r2, [r0]
	movs r0, #0xea
	lsls r0, r0, #2
	add r0, ip
	str r3, [r0]
	movs r2, #4
	movs r1, #0xe3
	lsls r1, r1, #2
	add r1, ip
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0821D858: .4byte 0x00000804
