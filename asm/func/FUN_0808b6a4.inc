	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0808B6C4 @ =0x030044E0
	ldrh r0, [r5, #2]
	movs r3, #0xf0
	adds r2, r3, #0
	ands r2, r0
	cmp r2, #0
	beq _0808B6CC
	ldr r1, _0808B6C8 @ =0x00003B24
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldrh r0, [r5, #2]
	b _0808B6F6
	.align 2, 0
_0808B6C4: .4byte 0x030044E0
_0808B6C8: .4byte 0x00003B24
_0808B6CC:
	ldrh r1, [r5]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0808B6F4
	ldr r0, _0808B6F0 @ =0x00003B24
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0808B6F4
	strb r2, [r1]
	ldrh r0, [r5]
	b _0808B6F6
	.align 2, 0
_0808B6F0: .4byte 0x00003B24
_0808B6F4:
	movs r0, #0
_0808B6F6:
	pop {r4, r5}
	pop {r1}
	bx r1
