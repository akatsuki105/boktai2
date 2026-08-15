	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08247392
_08247376:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _08247376
_08247392:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
