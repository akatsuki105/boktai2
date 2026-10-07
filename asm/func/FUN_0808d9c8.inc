	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d268
	adds r0, r4, #0
	bl EntityCC28_ApplyWeapon
	adds r0, r4, #0
	bl FUN_0808d93c
	ldr r0, _0808DA08 @ =0x00000C03
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808d3d4
	bl FUN_082408f4
	ldr r2, _0808DA0C @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808DA10 @ =FUN_0808cf14
	adds r0, r4, #0
	bl FUN_0808a33c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808DA08: .4byte 0x00000C03
_0808DA0C: .4byte 0x030044BC
_0808DA10: .4byte FUN_0808cf14
