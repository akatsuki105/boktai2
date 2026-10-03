	movs r3, #0x9f
	lsls r3, r3, #4
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0808A350 @ =0x000009EC
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0808A350: .4byte 0x000009EC
