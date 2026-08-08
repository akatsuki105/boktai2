	push {lr}
	movs r2, #0
	ldr r0, _080EC504 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r1, r0, r3
_080EC4FA:
	ldrh r0, [r1, #2]
	cmp r0, #0
	bne _080EC508
	adds r0, r1, #0
	b _080EC512
	.align 2, 0
_080EC504: .4byte 0x030046A0
_080EC508:
	adds r1, #6
	adds r2, #1
	cmp r2, #0x13
	ble _080EC4FA
	movs r0, #0
_080EC512:
	pop {r1}
	bx r1
	.align 2, 0
