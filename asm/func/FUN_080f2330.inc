	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080f3718
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F2358
	ldr r1, _080F2360 @ =0x00000469
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080F2358:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F2360: .4byte 0x00000469
