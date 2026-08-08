	push {r4, lr}
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r4, #0x98
	lsls r4, r4, #3
	adds r1, r0, r4
	strb r2, [r1]
	ldr r1, _080EF868 @ =0x000004C1
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080EF868: .4byte 0x000004C1
