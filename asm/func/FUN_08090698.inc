	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r0, _080906C4 @ =0x0000E002
	adds r7, r0, #0
_080906A0:
	movs r4, #0
	adds r6, r5, #1
_080906A4:
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0808a420
	strh r7, [r0]
	adds r4, #1
	cmp r4, #0x1f
	ble _080906A4
	adds r5, r6, #0
	cmp r5, #0x1f
	ble _080906A0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080906C4: .4byte 0x0000E002
