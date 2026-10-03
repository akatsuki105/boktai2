	push {lr}
	movs r2, #0
	ldr r0, _080BBBC8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r0, r3
_080BBBBA:
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _080BBBCC
	adds r0, r2, #0
	b _080BBBD8
	.align 2, 0
_080BBBC8: .4byte 0x030046A0
_080BBBCC:
	adds r1, #2
	adds r2, #1
	cmp r2, #0xf
	ble _080BBBBA
	movs r0, #1
	rsbs r0, r0, #0
_080BBBD8:
	pop {r1}
	bx r1
