	push {lr}
	ldr r2, _080F2294 @ =0x0000046A
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080F2298 @ =0x0000064C
	adds r2, r0, r3
	ldr r2, [r2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080F2294: .4byte 0x0000046A
_080F2298: .4byte 0x0000064C
