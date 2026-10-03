	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #3
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808eb4c
	ldr r1, _0808EC14 @ =FUN_0808ee50
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EC14: .4byte FUN_0808ee50
