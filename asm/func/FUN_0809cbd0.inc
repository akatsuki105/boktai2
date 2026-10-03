	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809CC00 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0809CBF2
	adds r0, r4, #0
	bl _call_via_r1
_0809CBF2:
	adds r0, r4, #0
	bl FUN_0808c7c4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC00: .4byte 0x03002BE0
