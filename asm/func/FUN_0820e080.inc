	push {r4, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x24
	movs r2, #0
	strb r1, [r3]
	ldr r1, _0820E0A8 @ =0x0000114D
	adds r0, r4, r1
	strb r2, [r0]
	ldrb r1, [r3]
	adds r0, r4, #0
	bl FUN_0820dae4
	adds r0, r4, #0
	bl FUN_0820db9c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820E0A8: .4byte 0x0000114D
