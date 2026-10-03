	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08043CA8
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xa
	strb r0, [r2, #5]
_08043CA8:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08043CBA
	movs r0, #0xc
	movs r1, #0
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #8]
_08043CBA:
	ldr r0, [r2, #0x14]
	adds r0, #1
	str r0, [r2, #0x14]
	pop {r0}
	bx r0
