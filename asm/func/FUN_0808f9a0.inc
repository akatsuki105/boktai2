	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0808F9BC @ =0x030044E0
	ldrh r0, [r4, #2]
	movs r1, #0xf0
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #0
	beq _0808F9C0
	movs r0, #0
	strb r0, [r3, #7]
	ldrh r0, [r4, #2]
	b _0808F9E0
	.align 2, 0
_0808F9BC: .4byte 0x030044E0
_0808F9C0:
	ldrh r0, [r4]
	ands r1, r0
	cmp r1, #0
	beq _0808F9DC
	ldrb r0, [r3, #7]
	adds r0, #1
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0808F9DE
	strb r2, [r3, #7]
	ldrh r0, [r4]
	b _0808F9E0
_0808F9DC:
	strb r1, [r3, #7]
_0808F9DE:
	movs r0, #0
_0808F9E0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
