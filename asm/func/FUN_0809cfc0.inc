	push {r4, lr}
	adds r4, r1, #0
	ldrb r1, [r4, #1]
	cmp r1, #0
	blt _0809D004
	cmp r1, #2
	ble _0809CFD4
	cmp r1, #4
	beq _0809CFEC
	b _0809D004
_0809CFD4:
	movs r1, #0xf8
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0x63
	asrs r0, r0, #1
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	b _0809D006
_0809CFEC:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	lsls r0, r0, #1
	b _0809D006
_0809D004:
	movs r0, #0
_0809D006:
	pop {r4}
	pop {r1}
	bx r1
