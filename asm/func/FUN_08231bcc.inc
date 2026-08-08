	push {lr}
	bl fetch_082316e4
	cmp r0, #0
	bne _08231BDA
	bl FUN_0823171c
_08231BDA:
	movs r0, #0
	pop {r1}
	bx r1
