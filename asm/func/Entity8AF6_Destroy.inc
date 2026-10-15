	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5DBC
	adds r4, r6, #0
	adds r4, #0x54
_080A5DAC:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5DAC
_080A5DBC:
	ldr r1, _080A5DC8 @ =0x03002C4C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5DC8: .4byte 0x03002C4C
