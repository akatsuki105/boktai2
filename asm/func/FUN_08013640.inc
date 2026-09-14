	push {lr}
	ldrb r2, [r1]
	cmp r2, #0
	beq _0801364E
	movs r0, #1
	rsbs r0, r0, #0
	b _08013662
_0801364E:
	str r2, [r1, #0x38]
	ldr r2, [r0, #0x1c]
	str r2, [r1, #0x3c]
	cmp r2, #0
	beq _0801365A
	str r1, [r2, #0x38]
_0801365A:
	str r1, [r0, #0x1c]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_08013662:
	pop {r1}
	bx r1
	.align 2, 0
