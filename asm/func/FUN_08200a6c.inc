	push {r4, lr}
	ldr r0, _08200AAC @ =0x03002C80
	ldr r0, [r0]
	mov ip, r0
	movs r4, #3
	adds r0, #0xa2
	movs r1, #0
	strb r4, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	movs r3, #1
	strb r3, [r0]
	ldr r2, _08200AB0 @ =FUN_081fcf54
	subs r0, #5
	strb r4, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08200AAC: .4byte 0x03002C80
_08200AB0: .4byte FUN_081fcf54
