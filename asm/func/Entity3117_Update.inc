	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A587E
	adds r4, r6, #0
	adds r4, #0x1c
_080A5860:
	ldr r0, _080A5888 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080A586E
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080A5874
_080A586E:
	adds r0, r4, #0
	bl Entity3117_UpdateEntry
_080A5874:
	adds r4, #0xb8
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5860
_080A587E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5888: .4byte 0x030044BC
