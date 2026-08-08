	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r2, _080E64E0 @ =0x0000044D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E64D8
	cmp r1, #0
	ble _080E64D8
	adds r4, r1, #0
_080E64C8:
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_082466ec
	subs r4, #1
	cmp r4, #0
	bne _080E64C8
_080E64D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E64E0: .4byte 0x0000044D
