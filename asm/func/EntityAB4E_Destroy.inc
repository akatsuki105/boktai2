	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #0
_08046FCC:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08046FDC
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080452f4
_08046FDC:
	adds r5, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _08046FCC
	ldr r1, _08046FF4 @ =0x030000C0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08046FF4: .4byte 0x030000C0
