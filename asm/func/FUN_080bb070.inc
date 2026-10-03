	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BB0D0 @ =0x00001314
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BB0C8
	ldr r1, _080BB0D4 @ =0x0000140E
	adds r0, r4, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	bl FUN_080ba288
	ldr r3, _080BB0D8 @ =0x030046A0
	ldr r2, [r3]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, _080BB0DC @ =0x0000270F
	cmp r1, r2
	ble _080BB0B0
	ldr r0, [r3]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	strh r2, [r0]
_080BB0B0:
	adds r0, r5, #0
	bl RemoveItem
	ldr r1, _080BB0E0 @ =0x0000151C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, _080BB0E4 @ =FUN_080bb0e8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
_080BB0C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BB0D0: .4byte 0x00001314
_080BB0D4: .4byte 0x0000140E
_080BB0D8: .4byte 0x030046A0
_080BB0DC: .4byte 0x0000270F
_080BB0E0: .4byte 0x0000151C
_080BB0E4: .4byte FUN_080bb0e8
