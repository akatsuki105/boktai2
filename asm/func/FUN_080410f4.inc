	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0xf7
	lsls r0, r0, #1
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08041112
	adds r0, r1, #0
	adds r0, #0x5c
	bl FUN_08002a58
	movs r0, #0
	strb r0, [r4]
	b _08041116
_08041112:
	movs r0, #1
	rsbs r0, r0, #0
_08041116:
	pop {r4}
	pop {r1}
	bx r1
