	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfaac
	adds r0, r4, #0
	bl FUN_080bffb8
	ldr r0, _080C000C @ =0x0000057A
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _080C0010 @ =FUN_080c0248
	adds r0, r4, #0
	bl EntityB3D1_SetState
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C000C: .4byte 0x0000057A
_080C0010: .4byte FUN_080c0248
