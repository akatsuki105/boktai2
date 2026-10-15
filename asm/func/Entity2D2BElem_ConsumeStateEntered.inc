	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _08007F42
	movs r0, #0
	b _08007F48
_08007F42:
	movs r0, #0
	strb r0, [r1, #4]
	movs r0, #1
_08007F48:
	pop {r1}
	bx r1
