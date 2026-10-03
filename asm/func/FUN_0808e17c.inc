	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x13
	movs r2, #3
	bl FUN_0808a420
	ldr r2, _0808E1B4 @ =0x0000D04D
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	adds r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, #0xd
	adds r1, r2, #0
	strh r1, [r0, #2]
	bl FUN_08050d64
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_0808e0e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E1B4: .4byte 0x0000D04D
