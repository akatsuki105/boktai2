	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0804B2D8 @ =0x030000D8
	ldr r2, [r0]
	cmp r2, #0
	beq _0804B2D4
	cmp r1, #0
	beq _0804B2D4
	movs r0, #0xf0
	orrs r1, r0
	ldrb r0, [r2, #0x1a]
	orrs r1, r0
	strb r1, [r2, #0x1a]
_0804B2D4:
	pop {r0}
	bx r0
	.align 2, 0
_0804B2D8: .4byte 0x030000D8
