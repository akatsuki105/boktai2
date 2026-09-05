	push {r4, lr}
	adds r4, r1, #0
	ldr r3, [r0, #0x74]
	cmp r3, #0
	beq _080220DE
_080220C6:
	ldr r1, [r3, #0x30]
	ldrh r0, [r3]
	cmp r0, r4
	bne _080220D8
	ldrb r0, [r3, #2]
	cmp r0, r2
	bne _080220D8
	adds r0, r3, #0
	b _080220E0
_080220D8:
	adds r3, r1, #0
	cmp r3, #0
	bne _080220C6
_080220DE:
	movs r0, #0
_080220E0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
