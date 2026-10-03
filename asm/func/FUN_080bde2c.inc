	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE58 @ =0x00001690
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BDE52
	ldr r2, _080BDE5C @ =0x0000178A
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r2, #3
	adds r1, r4, r2
	ldrb r1, [r1]
	bl SwapWeaponSlot
	adds r0, r4, #0
	bl FUN_080bd964
_080BDE52:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDE58: .4byte 0x00001690
_080BDE5C: .4byte 0x0000178A
