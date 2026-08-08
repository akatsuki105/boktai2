	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	cmp r3, #0
	beq _080F0A00
	ldrh r0, [r3]
	ldr r2, _080F0A08 @ =0x0000060C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r3, #0
	bl _call_via_r2
_080F0A00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F0A08: .4byte 0x0000060C
