	push {lr}
	ldrh r0, [r0, #0x2a]
	movs r1, #0xf
	bl Mod
	cmp r0, #0
	bne _080EEA16
	bl FUN_080a0808
	cmp r0, #0
	bne _080EEA04
	movs r2, #0x20
	ldr r0, _080EE9FC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080EEA00 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	b _080EEA16
	.align 2, 0
_080EE9FC: .4byte 0x030046A0
_080EEA00: .4byte 0x00000934
_080EEA04:
	ldr r0, _080EEA1C @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080EEA20 @ =0x00000934
	adds r1, r1, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_080EEA16:
	pop {r0}
	bx r0
	.align 2, 0
_080EEA1C: .4byte 0x030046A0
_080EEA20: .4byte 0x00000934
