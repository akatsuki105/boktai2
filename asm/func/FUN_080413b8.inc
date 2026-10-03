	push {r4, r5, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r1, r3, #0
	adds r1, #0xd0
	ldr r0, [r1]
	cmp r0, #1
	bne _080413D6
	ldrb r2, [r3, #0x19]
	movs r3, #0
	cmp r2, #1
	bls _080413E2
	b _080413E0
_080413D6:
	movs r2, #0
	ldrb r0, [r3, #0x19]
	movs r3, #0
	cmp r0, #1
	bls _080413E2
_080413E0:
	movs r3, #1
_080413E2:
	str r4, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r1, r5, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
