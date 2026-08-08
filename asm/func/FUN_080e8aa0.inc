	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0
	subs r1, #1
	cmp r0, r1
	bge _080E8ADC
	adds r5, r1, #0
_080E8AAE:
	adds r6, r0, #1
	cmp r1, #0
	ble _080E8AD4
	adds r2, r7, #0
	adds r4, r5, #0
_080E8AB8:
	ldr r3, [r2]
	ldr r0, [r2, #8]
	cmp r3, r0
	ble _080E8ACC
	ldr r1, [r2, #4]
	str r0, [r2]
	ldr r0, [r2, #0xc]
	str r0, [r2, #4]
	str r3, [r2, #8]
	str r1, [r2, #0xc]
_080E8ACC:
	adds r2, #8
	subs r4, #1
	cmp r4, #0
	bne _080E8AB8
_080E8AD4:
	adds r0, r6, #0
	adds r1, r5, #0
	cmp r0, r1
	blt _080E8AAE
_080E8ADC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
