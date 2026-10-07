	push {r4, lr}
	ldr r0, _0808E530 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0808E528
	bl FUN_0808d268
	ldr r0, _0808E534 @ =0x00000A3C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl EntityCC28_ApplyWeapon
	adds r0, r4, #0
	bl FUN_0808d93c
	adds r0, r4, #0
	bl FUN_0808d3d4
	ldr r1, _0808E538 @ =FUN_0808e400
	adds r0, r4, #0
	bl FUN_0808a33c
_0808E528:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E530: .4byte 0x0300013C
_0808E534: .4byte 0x00000A3C
_0808E538: .4byte FUN_0808e400
