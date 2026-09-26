	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	bne _0804A656
	movs r0, #0
	b _0804A65C
_0804A656:
	movs r0, #0
	strb r0, [r1, #0x19]
	movs r0, #1
_0804A65C:
	pop {r1}
	bx r1
