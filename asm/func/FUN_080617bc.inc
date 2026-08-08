	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrb r0, [r1]
	cmp r0, #0
	beq _080617D0
	movs r0, #0
	strb r0, [r1]
	b _080617D8
_080617D0:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080617D8:
	pop {r0}
	bx r0
