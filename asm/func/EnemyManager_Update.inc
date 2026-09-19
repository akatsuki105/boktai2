	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ee254
	adds r0, r4, #0
	bl FUN_080ec8a4
	adds r0, r4, #0
	bl FUN_080ec92c
	adds r0, r4, #0
	bl FUN_080ec9b0
	adds r0, r4, #0
	bl FUN_080edebc
	adds r0, r4, #0
	bl FUN_080ee9d4
	ldr r1, _080EEA60 @ =0xFFFE3FFF
	ldr r0, [r4, #0x2c]
	ands r0, r1
	str r0, [r4, #0x2c]
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080EEA60: .4byte 0xFFFE3FFF
