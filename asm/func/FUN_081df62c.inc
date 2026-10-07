	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DF646
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #1
	strb r1, [r4, #0x1e]
_081DF646:
	pop {r4}
	pop {r1}
	bx r1
