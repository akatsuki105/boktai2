	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _080806B4
	movs r0, #8
	b _080806E4
_080806B4:
	ldr r0, _080806CC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080806D0
	ldr r0, [r4, #0x18]
	bl FUN_080d1b04
	b _080806D6
	.align 2, 0
_080806CC: .4byte 0x030047A4
_080806D0:
	ldr r0, [r4, #0x18]
	bl FUN_0806f900
_080806D6:
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #1
	adds r0, r1, r0
_080806E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
