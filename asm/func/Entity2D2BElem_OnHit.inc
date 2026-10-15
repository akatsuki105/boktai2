	push {lr}
	adds r3, r2, #0
	ldrb r1, [r2, #2]
	cmp r1, #1
	bne _08007F6A
	movs r1, #4
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r2, #0
	movs r1, #3
	bl Entity2D2BElem_SetState
	b _08007F80
_08007F6A:
	cmp r1, #2
	bne _08007F80
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r3, #0
	movs r1, #4
	bl Entity2D2BElem_SetState
_08007F80:
	pop {r0}
	bx r0
