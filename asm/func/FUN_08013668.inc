	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x38]
	ldr r2, [r1, #0x3c]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801367C
	movs r0, #1
	rsbs r0, r0, #0
	b _08013690
_0801367C:
	cmp r3, #0
	beq _08013684
	str r2, [r3, #0x3c]
	b _08013686
_08013684:
	str r2, [r4, #0x1c]
_08013686:
	cmp r2, #0
	beq _0801368C
	str r3, [r2, #0x38]
_0801368C:
	movs r0, #0
	strb r0, [r1]
_08013690:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
