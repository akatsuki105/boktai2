	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x39
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _0808C798
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x38
	movs r0, #0
	strb r0, [r1]
	b _0808C7BA
_0808C798:
	ldrh r0, [r2, #0x30]
	ldrh r3, [r2, #0x18]
	adds r0, r0, r3
	strh r0, [r2, #0x18]
	ldrh r3, [r2, #0x32]
	ldrh r4, [r2, #0x1a]
	adds r0, r3, r4
	strh r0, [r2, #0x1a]
	ldrb r1, [r1]
	movs r0, #3
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x38
	cmp r0, #0
	bne _0808C7BA
	adds r0, r3, #1
	strh r0, [r2, #0x32]
_0808C7BA:
	ldrb r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
