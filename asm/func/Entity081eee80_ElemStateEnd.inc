	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081EEC2C
	adds r0, r4, #0
	bl AuxSprite_Remove
_081EEC2C:
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0x40
	bl ClearMemory
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
