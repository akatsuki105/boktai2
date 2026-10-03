	push {r4, lr}
	ldr r2, _0808A480 @ =0x03004494
	strh r1, [r2]
	ldr r3, _0808A484 @ =0x03004454
	ldr r4, _0808A488 @ =0x0000FFFF
	adds r2, r4, #0
	strh r2, [r3]
	ldr r2, _0808A48C @ =0x03004040
	str r0, [r2]
	ldr r2, _0808A490 @ =0x03004464
	strh r1, [r2]
	ldr r2, _0808A494 @ =0x03004490
	movs r1, #0
	strh r1, [r2]
	ldr r1, _0808A498 @ =0x0300445C
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A480: .4byte 0x03004494
_0808A484: .4byte 0x03004454
_0808A488: .4byte 0x0000FFFF
_0808A48C: .4byte 0x03004040
_0808A490: .4byte 0x03004464
_0808A494: .4byte 0x03004490
_0808A498: .4byte 0x0300445C
