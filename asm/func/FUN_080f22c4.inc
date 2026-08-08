	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F22E2
	adds r0, r4, #0
	bl FUN_080f0a0c
_080F22E2:
	pop {r4}
	pop {r0}
	bx r0
