	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E0C
	ldrh r0, [r0, #0x1e]
	cmp r0, #0xa
	bhi _08050E10
_08050E0C:
	movs r0, #0
	b _08050E12
_08050E10:
	movs r0, #1
_08050E12:
	pop {r1}
	bx r1
	.align 2, 0
