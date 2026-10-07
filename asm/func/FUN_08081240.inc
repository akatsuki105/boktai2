	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _0808125C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08081260 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08081264
	movs r0, #1
	b _08081266
	.align 2, 0
_0808125C: .4byte 0x030046A0
_08081260: .4byte 0x00000934
_08081264:
	movs r0, #0
_08081266:
	cmp r0, #0
	bne _08081278
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #8
	b _08081284
_08081278:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #4
_08081284:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
