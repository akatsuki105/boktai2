	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	ldr r0, _0808B864 @ =0x00000F6C
	adds r1, r3, r0
	movs r2, #0x73
_0808B838:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B838
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r1, r3, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0808B868 @ =0x00000BB8
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B864: .4byte 0x00000F6C
_0808B868: .4byte 0x00000BB8
