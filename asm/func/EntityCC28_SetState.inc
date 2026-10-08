	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0808A388 @ =0x000009F4
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _0808A38C @ =0x000009EE
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0808A390 @ =0x000009F8
	adds r0, r3, r1
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0808A39C
	ldr r4, _0808A394 @ =0x00000FCC
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0808A398 @ =0x0000102C
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	b _0808A3B2
	.align 2, 0
_0808A388: .4byte 0x000009F4
_0808A38C: .4byte 0x000009EE
_0808A390: .4byte 0x000009F8
_0808A394: .4byte 0x00000FCC
_0808A398: .4byte 0x0000102C
_0808A39C:
	ldr r4, _0808A3BC @ =0x00000FCC
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0808A3C0 @ =0x0000102C
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
_0808A3B2:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A3BC: .4byte 0x00000FCC
_0808A3C0: .4byte 0x0000102C
