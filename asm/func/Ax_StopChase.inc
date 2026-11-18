	mov ip, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	add r2, ip
	ldr r0, _0819E408 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	movs r2, #0xbc
	lsls r2, r2, #1
	add r2, ip
	ldr r1, _0819E40C @ =0xFBFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	ldr r0, _0819E410 @ =0x00000E48
	adds r1, r1, r0
	movs r2, #0x11
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0819E414 @ =0x0000024E
	add r0, ip
	strh r3, [r0]
	bx lr
	.align 2, 0
_0819E408: .4byte 0xFFFFFEFF
_0819E40C: .4byte 0xFBFFFFFF
_0819E410: .4byte 0x00000E48
_0819E414: .4byte 0x0000024E
