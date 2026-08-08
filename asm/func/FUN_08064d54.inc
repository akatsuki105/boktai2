	push {lr}
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _08064D66
	movs r0, #1
	b _08064D68
_08064D66:
	movs r0, #0
_08064D68:
	pop {r1}
	bx r1
