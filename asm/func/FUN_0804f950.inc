	push {lr}
	bl FUN_0804f820
	adds r1, r0, #0
	cmp r1, #0
	beq _0804F96C
	adds r0, #0x55
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804F96C
	adds r0, r1, #0
	adds r0, #0x54
	bl FUN_0804e514
_0804F96C:
	pop {r0}
	bx r0
