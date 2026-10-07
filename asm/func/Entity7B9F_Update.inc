	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r5, r0
_081D8788:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D8798
	movs r0, #1
	b _081D879A
_081D8798:
	movs r0, #0
_081D879A:
	cmp r0, #0
	beq _081D87B4
	movs r0, #0xdc
	muls r0, r4, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r1, [r1]
	bl _call_via_r1
_081D87B4:
	adds r4, #1
	cmp r4, #3
	ble _081D8788
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
