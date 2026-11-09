	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DC548
	bl Marquee_CloseGlobal
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC55C
_081DC548:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DC55A
	adds r0, r4, #0
	bl _call_via_r1
_081DC55A:
	movs r0, #1
_081DC55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
