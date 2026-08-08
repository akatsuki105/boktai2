	adds r3, r0, #0
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrb r1, [r2]
	adds r0, r3, #0
	adds r0, #0x6c
	strb r1, [r0]
	ldr r1, _0821A304 @ =0x00000171
	adds r1, r1, r3
	mov ip, r1
	ldrb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x6d
	strb r0, [r1]
	ldrb r1, [r2]
	adds r0, r3, #0
	adds r0, #0xcc
	strb r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r1, r3, #0
	adds r1, #0xcd
	strb r0, [r1]
	ldrb r1, [r2]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_0821A304: .4byte 0x00000171
