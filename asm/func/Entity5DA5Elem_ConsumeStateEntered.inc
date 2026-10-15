	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08008936
	movs r0, #0
	b _0800893C
_08008936:
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #1
_0800893C:
	pop {r1}
	bx r1
