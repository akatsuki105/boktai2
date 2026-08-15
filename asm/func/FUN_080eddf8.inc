	push {lr}
	bl Script_GetValue
	cmp r0, #0
	beq _080EDE0E
	bl FUN_080edda0
	cmp r0, #0
	beq _080EDE0E
	movs r0, #1
	b _080EDE10
_080EDE0E:
	movs r0, #0
_080EDE10:
	pop {r1}
	bx r1
