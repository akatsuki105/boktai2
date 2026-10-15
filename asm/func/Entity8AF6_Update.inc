	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5D94
	adds r4, r6, #0
	adds r4, #0x1c
_080A5D84:
	adds r0, r4, #0
	bl Entity8AF6Entry_Update
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5D84
_080A5D94:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
