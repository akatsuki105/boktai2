	mov ip, r0
	movs r1, #0xb4
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0
	movs r0, #0x98
	strh r0, [r1]
	adds r0, #0xd2
	add r0, ip
	movs r2, #0x68
	strh r2, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xa0
	strh r0, [r1]
	adds r0, #0x6a
	add r0, ip
	strh r2, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #0xa8
	strh r0, [r1]
	mov r0, ip
	adds r0, #0xaa
	strh r2, [r0]
	subs r1, #0x60
	movs r0, #0xb0
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	strh r2, [r0]
	mov r1, ip
	ldr r0, [r1, #0x30]
	subs r2, #0x6a
	ands r0, r2
	str r0, [r1, #0x30]
	adds r1, #0x90
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #1
	add r1, ip
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _081E4834 @ =0x000015E4
	add r0, ip
	strh r3, [r0]
	bx lr
	.align 2, 0
_081E4834: .4byte 0x000015E4
