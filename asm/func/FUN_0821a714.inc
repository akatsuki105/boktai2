	mov ip, r0
	movs r0, #0xb0
	lsls r0, r0, #1
	add r0, ip
	str r1, [r0]
	movs r0, #0xb2
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	str r3, [r0]
	movs r2, #0xc8
	lsls r2, r2, #1
	add r2, ip
	ldr r0, _0821A760 @ =0x085AFFA0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	movs r1, #1
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #1
	add r0, ip
	str r3, [r0]
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, ip
	str r3, [r0]
	movs r1, #2
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0821A760: .4byte 0x085AFFA0
