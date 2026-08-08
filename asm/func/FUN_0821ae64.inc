	mov ip, r0
	adds r0, #0xfc
	str r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	str r3, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	add r2, ip
	ldr r0, _0821AEAC @ =0x085AFFA4
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	movs r1, #1
	mov r2, ip
	adds r2, #0xf8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, ip
	str r3, [r0]
	movs r0, #0x84
	lsls r0, r0, #1
	add r0, ip
	str r3, [r0]
	movs r1, #2
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0821AEAC: .4byte 0x085AFFA4
