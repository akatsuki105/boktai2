	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808EED8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	adds r0, r4, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0808EEE0
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0808EEDC @ =FUN_0808eef8
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808EEF0
	.align 2, 0
_0808EED8: .4byte 0x000034E4
_0808EEDC: .4byte FUN_0808eef8
_0808EEE0:
	cmp r0, #1
	bne _0808EEF0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808ec18
_0808EEF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
