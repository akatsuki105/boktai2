	push {lr}
	ldr r0, _0804B270 @ =0x030000D8
	ldr r0, [r0]
	cmp r0, #0
	bne _0804B274
	movs r0, #0
	b _0804B276
	.align 2, 0
_0804B270: .4byte 0x030000D8
_0804B274:
	movs r0, #1
_0804B276:
	pop {r1}
	bx r1
	.align 2, 0
