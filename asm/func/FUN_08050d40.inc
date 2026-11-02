	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D54
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #0
	bne _08050D58
_08050D54:
	movs r0, #0
	b _08050D5E
_08050D58:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_08050D5E:
	pop {r1}
	bx r1
	.align 2, 0
