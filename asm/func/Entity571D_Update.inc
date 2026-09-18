	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x87
	lsls r0, r0, #5
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BF958 @ =0x000010E8
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BF958: .4byte 0x000010E8
