	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _080DE0B4 @ =0x0000922E
	ldr r1, _080DE0B8 @ =0x0000D1B8
	bl FUN_082310cc
	ldr r2, _080DE0BC @ =0x00000CD8
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _080DE0AE
	ldr r0, _080DE0C0 @ =0x00001C1A
	bl FUN_0822b10c
	ldr r2, _080DE0C4 @ =0x00000CDC
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	bne _080DE0C8
_080DE0AE:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DE10E
	.align 2, 0
_080DE0B4: .4byte 0x0000922E
_080DE0B8: .4byte 0x0000D1B8
_080DE0BC: .4byte 0x00000CD8
_080DE0C0: .4byte 0x00001C1A
_080DE0C4: .4byte 0x00000CDC
_080DE0C8:
	adds r5, r6, #0
	adds r5, #0x58
	adds r4, r6, #0
	adds r4, #0x28
	movs r7, #0x2f
_080DE0D2:
	movs r0, #0
	strb r0, [r5]
	ldr r1, _080DE114 @ =0x00000CDC
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r4, #0
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0xa
	rsbs r2, r2, #0
	bl FUN_0822dad4
	movs r0, #2
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r5, #0x44
	adds r4, #0x44
	subs r7, #1
	cmp r7, #0
	bge _080DE0D2
	ldr r0, _080DE118 @ =0x03000174
	str r6, [r0]
	movs r0, #0
_080DE10E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DE114: .4byte 0x00000CDC
_080DE118: .4byte 0x03000174
