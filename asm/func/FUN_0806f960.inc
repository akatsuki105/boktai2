	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, _0806F98C @ =0x00000AA8
	adds r4, r5, r0
_0806F96C:
	ldr r1, [r4]
	cmp r1, #0
	beq _0806F97A
	adds r0, r5, #0
	bl _call_via_r1
	orrs r7, r0
_0806F97A:
	adds r4, #4
	adds r6, #1
	cmp r6, #2
	ble _0806F96C
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806F98C: .4byte 0x00000AA8
