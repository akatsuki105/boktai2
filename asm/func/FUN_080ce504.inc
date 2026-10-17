	push {lr}
	movs r0, #0x80
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080CE53C
_080CE538:
	movs r0, #0xa
	b _080CE53E
_080CE53C:
	movs r0, #0
_080CE53E:
	pop {r1}
	bx r1
	.align 2, 0
