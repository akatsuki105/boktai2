	push {lr}
	adds r3, r0, #0
	ldr r0, _0808D97C @ =0x00000C02
	adds r1, r3, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0808D984
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D984
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r3, r2
	ldr r0, [r0]
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0x64
	muls r1, r2, r1
	adds r1, r3, r1
	ldr r2, _0808D980 @ =0x00000C09
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl FUN_08064fd8
	b _0808D994
	.align 2, 0
_0808D97C: .4byte 0x00000C02
_0808D980: .4byte 0x00000C09
_0808D984:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_08064fd8
_0808D994:
	pop {r0}
	bx r0
