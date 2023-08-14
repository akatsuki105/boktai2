	push {lr}
	movs r0, #0x6d
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0824359A
	bl fetch_082316e4
	bl IsMagicUnlocked
_0824359A:
	pop {r1}
	bx r1
	.align 2, 0
