	push {lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xb0
	ldrb r0, [r2]
	cmp r0, #0
	bne _080ABAF0
	ldr r0, [r3, #0x1c]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080ABB04 @ =0x00000209
	cmp r1, r0
	bne _080ABAEA
	movs r0, #1
	strb r0, [r2]
_080ABAEA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _080ABAFE
_080ABAF0:
	adds r1, r3, #0
	adds r1, #0xb8
	adds r0, r3, #0
	adds r0, #0x20
	ldr r1, [r1]
	bl _call_via_r1
_080ABAFE:
	pop {r0}
	bx r0
	.align 2, 0
_080ABB04: .4byte 0x00000209
