	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl FUN_080ef840
	ldr r0, _080ED01C @ =0x03002C60
	ldr r2, [r0]
	ldr r1, [r2, #4]
	movs r3, #0
	cmp r1, #0
	beq _080ED012
	movs r6, #0x80
	lsls r6, r6, #0xa
_080ECFD6:
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r1, r7
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	ble _080ED00A
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r1, r7
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	bne _080ED00A
	adds r7, #0x63
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, r5
	bne _080ED00A
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r4
	bne _080ED00A
	adds r3, #1
_080ED00A:
	ldr r2, [r2]
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080ECFD6
_080ED012:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ED01C: .4byte 0x03002C60
