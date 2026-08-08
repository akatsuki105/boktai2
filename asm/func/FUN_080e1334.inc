	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _080E1344 @ =0x03000180
	ldr r4, [r0]
	cmp r4, #0
	bne _080E1350
	b _080E1382
	.align 2, 0
_080E1344: .4byte 0x03000180
_080E1348:
	adds r0, r3, #0
	adds r0, #0x18
	adds r0, r4, r0
	b _080E1384
_080E1350:
	movs r2, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r1, r4, #0
	movs r7, #1
_080E135E:
	adds r0, r7, #0
	lsls r0, r2
	ands r0, r5
	cmp r0, #0
	beq _080E136C
	movs r0, #1
	b _080E136E
_080E136C:
	movs r0, #0
_080E136E:
	cmp r0, #0
	beq _080E137A
	lsls r3, r2, #5
	ldrh r0, [r1, #0x2c]
	cmp r0, r6
	beq _080E1348
_080E137A:
	adds r1, #0x20
	adds r2, #1
	cmp r2, #0xb
	ble _080E135E
_080E1382:
	movs r0, #0
_080E1384:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
