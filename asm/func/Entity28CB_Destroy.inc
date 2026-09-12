	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x74
	movs r5, #4
_0808A0F2:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _0808A0F2
	adds r0, r6, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808A112
	adds r0, r6, #0
	adds r0, #0x18
	bl FUN_08022428
_0808A112:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
