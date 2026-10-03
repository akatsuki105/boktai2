	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809A428
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A424 @ =FUN_0809a324
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _0809A43C
	.align 2, 0
_0809A424: .4byte FUN_0809a324
_0809A428:
	cmp r0, #1
	bne _0809A43C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0809A444 @ =FUN_0809a448
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A43C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A444: .4byte FUN_0809a448
