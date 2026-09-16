	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r1, [r2, #4]
	cmp r1, #0
	bne _08009292
	adds r1, r3, #0
	adds r1, #0x4c
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
_08009292:
	pop {r4}
	pop {r1}
	bx r1
