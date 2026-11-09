	push {r4, lr}
	adds r4, r1, #0
	adds r2, r4, #0
	adds r2, #0x68
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805F0E8
	ldr r0, [r4, #0x68]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x68]
	adds r0, r2, #0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r4]
_0805F0E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
