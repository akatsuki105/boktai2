	push {lr}
	bl item_0809179c
	cmp r0, #1
	beq _08091E42
	movs r0, #0
	b _08091E44
_08091E42:
	movs r0, #1
_08091E44:
	pop {r1}
	bx r1
