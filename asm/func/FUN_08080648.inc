	push {lr}
	adds r0, r2, #0
	ldr r1, _08080658 @ =FUN_0808094c
	bl FUN_080801f4
	pop {r0}
	bx r0
	.align 2, 0
_08080658: .4byte FUN_0808094c
