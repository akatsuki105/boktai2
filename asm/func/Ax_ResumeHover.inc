	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #0xd
	movs r2, #0xbe
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, _0819E2EC @ =0x00000E48
	adds r1, r1, r0
	movs r2, #0x12
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	mov r2, ip
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _0819E2F0 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0819E2EC: .4byte 0x00000E48
_0819E2F0: .4byte 0x0000FFFB
