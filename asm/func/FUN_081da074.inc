	push {lr}
	adds r2, r0, #0
	ldr r1, _081DA08C @ =0x00000286
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA0A6
	cmp r0, #1
	bgt _081DA090
	cmp r0, #0
	beq _081DA096
	b _081DA0BC
	.align 2, 0
_081DA08C: .4byte 0x00000286
_081DA090:
	cmp r0, #2
	beq _081DA0B4
	b _081DA0BC
_081DA096:
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r1, [r0]
	subs r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	b _081DA0BC
_081DA0A6:
	ldr r0, _081DA0B0 @ =0x0000028B
	adds r1, r2, r0
	movs r0, #2
	b _081DA0BA
	.align 2, 0
_081DA0B0: .4byte 0x0000028B
_081DA0B4:
	ldr r3, _081DA0C0 @ =0x0000028B
	adds r1, r2, r3
	movs r0, #1
_081DA0BA:
	strb r0, [r1]
_081DA0BC:
	pop {r0}
	bx r0
	.align 2, 0
_081DA0C0: .4byte 0x0000028B
