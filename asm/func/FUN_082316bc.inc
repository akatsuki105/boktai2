	push {lr}
	ldr r0, _082316D8 @ =gVM
	ldr r1, [r0]
	cmp r1, #0
	beq _082316D4
	ldrb r2, [r1]
	cmp r2, #0
	beq _082316D4
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0x50
	bne _082316DC
_082316D4:
	movs r0, #0
	b _082316DE
	.align 2, 0
_082316D8: .4byte gVM
_082316DC:
	adds r0, r1, #0
_082316DE:
	pop {r1}
	bx r1
	.align 2, 0
