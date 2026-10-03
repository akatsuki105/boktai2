	strh r1, [r0, #0x3a]
	ldr r1, _0808BA1C @ =0x03003584
	ldrh r2, [r0, #0x3a]
	lsls r2, r2, #5
	ldr r1, [r1]
	adds r1, r1, r2
	str r1, [r0, #0x48]
	bx lr
	.align 2, 0
_0808BA1C: .4byte 0x03003584
