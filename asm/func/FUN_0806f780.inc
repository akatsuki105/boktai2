	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08064d04
	adds r1, r0, #0
	ldr r2, _0806F7A0 @ =0x00000A8D
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0806F7A8
	adds r1, #1
	ldr r2, _0806F7A4 @ =0x00000951
	adds r0, r4, r2
	strb r1, [r0]
	b _0806F7B0
	.align 2, 0
_0806F7A0: .4byte 0x00000A8D
_0806F7A4: .4byte 0x00000951
_0806F7A8:
	ldr r0, _0806F7B8 @ =0x00000951
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0806F7B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806F7B8: .4byte 0x00000951
