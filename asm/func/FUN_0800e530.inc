	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _0800E546
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_08013c70
	movs r0, #0
	strb r0, [r4, #0xb]
_0800E546:
	pop {r4}
	pop {r0}
	bx r0
