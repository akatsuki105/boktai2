	push {lr}
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080E6764
	movs r1, #0
	bl FUN_082318ac
_080E6764:
	pop {r0}
	bx r0
