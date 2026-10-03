	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _080BFAA0 @ =0x03002BE0
	adds r4, r5, #0
	ldr r3, _080BFAA4 @ =0x0000040C
	movs r2, #0
_080BFA80:
	ldr r0, [r4]
	adds r0, r0, r3
	adds r0, r0, r1
	strb r2, [r0]
	adds r1, #1
	cmp r1, #0x1f
	ble _080BFA80
	ldr r0, [r5]
	ldr r1, _080BFAA8 @ =0x0000042E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFAA0: .4byte 0x03002BE0
_080BFAA4: .4byte 0x0000040C
_080BFAA8: .4byte 0x0000042E
