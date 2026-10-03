	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_0808a420
	ldr r2, _0808E1F0 @ =0x0000D00F
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	adds r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, #0x4b
	adds r1, r2, #0
	strh r1, [r0, #2]
	bl FUN_08050d7c
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #4
	bl FUN_0808e0e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E1F0: .4byte 0x0000D00F
