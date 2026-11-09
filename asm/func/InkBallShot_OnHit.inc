	push {lr}
	adds r0, r2, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202D48
	adds r0, r2, #0
	movs r1, #1
	bl InkBallShot_SetState
_08202D48:
	pop {r0}
	bx r0
