	push {r4, r5, lr}
	movs r3, #1
	ldr r1, _0808D3C8 @ =0x00000C14
	adds r2, r0, r1
	ldr r4, _0808D3CC @ =0x00000DAC
	adds r1, r0, r4
	ldr r5, _0808D3D0 @ =0x00000EE4
	adds r4, r0, r5
_0808D3AC:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r2, #0x64
	adds r1, #0x68
	cmp r1, r4
	ble _0808D3AC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D3C8: .4byte 0x00000C14
_0808D3CC: .4byte 0x00000DAC
_0808D3D0: .4byte 0x00000EE4
