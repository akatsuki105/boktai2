	push {r4, lr}
	ldr r0, _0804B2B4 @ =0x030000D8
	ldr r4, [r0]
	cmp r4, #0
	beq _0804B2AC
	adds r1, r4, #0
	adds r1, #0x39
	adds r2, r4, #0
	adds r2, #0x3a
	adds r3, r4, #0
	adds r3, #0x3b
	movs r0, #0
	bl rfu_REQBN_watchLink
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0804B2A8
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0x1a]
_0804B2A8:
	bl rfu_REQ_recvData
_0804B2AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B2B4: .4byte 0x030000D8
