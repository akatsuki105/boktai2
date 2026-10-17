	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _080A58BA
_080A5894:
	movs r0, #0xb8
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, r5
	adds r0, #0x44
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0xd0
	adds r4, r0, r4
	ldr r0, [r4]
	cmp r0, #0
	beq _080A58B8
	bl ParticleShadow_Remove
	ldr r0, [r4]
	bl Free
_080A58B8:
	adds r6, #1
_080A58BA:
	ldrb r0, [r5, #0x19]
	cmp r6, r0
	blt _080A5894
	ldr r1, _080A58CC @ =0x03002C48
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A58CC: .4byte 0x03002C48
