	push {r4, lr}
	ldr r4, _0808C640 @ =0x000025A4
	adds r3, r0, r4
	strh r1, [r3]
	adds r4, #2
	adds r3, r0, r4
	strh r2, [r3]
	adds r4, #0x5e
	adds r3, r0, r4
	strh r1, [r3]
	adds r2, #8
	ldr r1, _0808C644 @ =0x00002606
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C640: .4byte 0x000025A4
_0808C644: .4byte 0x00002606
