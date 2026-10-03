	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, _0808C1B0 @ =0x000009D8
	adds r3, r4, r0
	strh r1, [r3]
	ldr r1, _0808C1B4 @ =0x000009DA
	adds r0, r4, r1
	strh r2, [r0]
	ldr r1, _0808C1B8 @ =0x03003584
	ldrh r0, [r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r0, _0808C1BC @ =0x000009B8
	adds r2, r4, r0
	movs r3, #0xf
_0808C186:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808C186
	ldr r1, _0808C1C0 @ =0x000009DD
	adds r0, r4, r1
	movs r1, #0
	strb r5, [r0]
	ldr r2, _0808C1C4 @ =0x000009DC
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0808C1C8 @ =0x000009DE
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C1B0: .4byte 0x000009D8
_0808C1B4: .4byte 0x000009DA
_0808C1B8: .4byte 0x03003584
_0808C1BC: .4byte 0x000009B8
_0808C1C0: .4byte 0x000009DD
_0808C1C4: .4byte 0x000009DC
_0808C1C8: .4byte 0x000009DE
