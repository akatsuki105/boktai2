	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #5
_081F578E:
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _081F578E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
