	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08060406:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _0806041C
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08060338
_0806041C:
	adds r4, #1
	adds r5, #0x38
	cmp r4, #0xf
	ble _08060406
	ldr r1, _08060430 @ =0x03000134
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08060430: .4byte 0x03000134
