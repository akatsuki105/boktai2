	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0808E868 @ =0x00004022
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r2, r2, r0
	ldr r0, _0808E86C @ =0x0000036A
	adds r1, r1, r0
	ldrh r3, [r1]
	cmp r2, #0
	bne _0808E870
	movs r3, #0
	b _0808E882
	.align 2, 0
_0808E868: .4byte 0x00004022
_0808E86C: .4byte 0x0000036A
_0808E870:
	subs r1, r2, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r3, #1
	bl Div
	adds r3, r0, #1
_0808E882:
	ldr r1, _0808E8A8 @ =0x000028EC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r3, #0
	subs r1, #0x98
	ldr r2, _0808E8AC @ =0x00002904
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _0808E8B0 @ =0x00002906
	adds r1, r4, r3
	ldr r0, _0808E8B4 @ =0x0000FFD8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E8A8: .4byte 0x000028EC
_0808E8AC: .4byte 0x00002904
_0808E8B0: .4byte 0x00002906
_0808E8B4: .4byte 0x0000FFD8
