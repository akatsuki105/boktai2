	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #0xf
_08204BD4:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _08204BE0
	adds r0, r4, #0
	bl AuxSprite_Remove
_08204BE0:
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204BD4
	ldr r1, _08204BF4 @ =0x03000220
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08204BF4: .4byte 0x03000220
