	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	cmp r0, #0
	beq _080ABFE4
	movs r3, #0
	adds r4, r6, #0
	adds r4, #0xcc
	adds r5, r6, #0
	adds r5, #0xa4
	movs r7, #7
_080ABFB6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080ABFD0
	adds r0, r6, #0
	adds r0, #0xa0
	ldr r1, [r0]
	ldr r2, [r4, #0x10]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	adds r3, #1
_080ABFD0:
	adds r4, #0x3c
	adds r5, #0x3c
	subs r7, #1
	cmp r7, #0
	bge _080ABFB6
	cmp r3, #0
	bne _080ABFE4
	adds r0, r6, #0
	adds r0, #0x9e
	strb r3, [r0]
_080ABFE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
