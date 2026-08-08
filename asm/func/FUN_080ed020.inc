	push {r4, r5, lr}
	bl FUN_080ef840
	ldr r0, _080ED054 @ =0x03002C60
	ldr r2, [r0]
	ldr r1, [r2, #4]
	cmp r1, #0
	beq _080ED060
	movs r4, #0xc2
	lsls r4, r4, #1
	movs r3, #0x80
	lsls r3, r3, #0xa
_080ED038:
	adds r0, r1, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	ble _080ED058
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r1, r5
	ldr r0, [r0]
	ands r0, r3
	cmp r0, #0
	bne _080ED058
	adds r0, r1, #0
	b _080ED062
	.align 2, 0
_080ED054: .4byte 0x03002C60
_080ED058:
	ldr r2, [r2]
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080ED038
_080ED060:
	movs r0, #0
_080ED062:
	pop {r4, r5}
	pop {r1}
	bx r1
