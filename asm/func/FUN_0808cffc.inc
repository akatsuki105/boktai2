	push {r4, r5, lr}
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #1
_0808D006:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808D006
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
