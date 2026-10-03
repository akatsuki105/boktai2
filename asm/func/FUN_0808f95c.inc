	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808f140
	ldr r2, _0808F980 @ =0x0000401E
	adds r1, r4, r2
	strb r0, [r1]
	ldr r2, _0808F984 @ =0x03003E78
	ldr r0, _0808F988 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_0808f21c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F980: .4byte 0x0000401E
_0808F984: .4byte 0x03003E78
_0808F988: .4byte 0xFFFFFDFF
