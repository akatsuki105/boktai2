	push {lr}
	adds r1, r0, #0
	ldr r2, _0808D1F8 @ =0x00000F3C
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _0808D1D2
	movs r2, #0x1b
	cmp r0, #0x11
	bls _0808D1D2
	movs r2, #0x12
	cmp r0, #0x19
	bls _0808D1D2
	movs r2, #0xa
	cmp r0, #0x21
	bls _0808D1D2
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _0808D1D2
	movs r2, #0x12
_0808D1D2:
	ldr r0, _0808D1F8 @ =0x00000F3C
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x31
	bls _0808D1E8
	movs r0, #0
	strb r0, [r1]
_0808D1E8:
	ldr r0, _0808D1FC @ =0x03004250
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0808D1F8: .4byte 0x00000F3C
_0808D1FC: .4byte 0x03004250
