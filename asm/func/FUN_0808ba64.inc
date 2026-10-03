	push {lr}
	adds r2, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r3, _0808BA80 @ =0x0000043E
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808BA84
	movs r1, #2
	b _0808BAA2
	.align 2, 0
_0808BA80: .4byte 0x0000043E
_0808BA84:
	ldr r3, _0808BAB8 @ =0x0000038E
	adds r0, r1, r3
	ldrb r0, [r0]
	ldr r1, _0808BABC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	cmp r0, #0
	ble _0808BAA2
	movs r1, #6
_0808BAA2:
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	lsls r1, r1, #1
	ldr r2, _0808BAC0 @ =0x00000938
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_0808BAB8: .4byte 0x0000038E
_0808BABC: .4byte 0x030046A0
_0808BAC0: .4byte 0x00000938
